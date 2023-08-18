//Solved
#include <iostream>
#include <vector>
using namespace std;
//1..4까지 시계방향으로 방향이 결정 1은 위
pair<int,int> direction_pair[5] = {
    pair<int,int>(0,1),
    pair<int,int>(1,0),
    pair<int,int>(0,-1),
    pair<int,int>(-1,0),

};
vector<int> cctv_direction[6] ={
{},
    {1},
    {1,3},
    {0,1},
    {0,1,3},
    {0,1,2,3},
};
struct CCTV{
    public:
        short type;
        short x;
        short y;
        CCTV(short type,short x,short y){
            this->type = type;
            this->x = x;
            this->y = y;
        }
};
int n,m;
short map[8][8] = {0};
vector<CCTV> cctv_cache;
int min_empty = 100;
int count_empty(){
    int result = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (map[i][j] == 0) result++;
        }
    }
    return result;
}
//약산 긴가 민가
void fill_direction_from_pos(int dir,int x,int y,int num){
    int curX = x + direction_pair[dir].first;
    int curY = y + direction_pair[dir].second;
    while (curX < n&&curY < m&&curX >=0 && curY >=0) {
        if (map[curX][curY] == 6) break;
        if (map[curX][curY] > 0){
            curX += direction_pair[dir].first;
            curY += direction_pair[dir].second;
            continue;
        }
        map[curX][curY] += num;
        curX += direction_pair[dir].first;
        curY += direction_pair[dir].second;
    }
}
void fill_cctv(int type,int dir,int x,int y,int num){
    vector<int> cctv_dir = cctv_direction[type];
    for (int i = 0; i < cctv_dir.size();i++) {
        int cur_dir = (cctv_dir[i] + dir) % 4;
        fill_direction_from_pos(cur_dir,x,y,num);
    }
}
void backtracking(int len){
    if (len == cctv_cache.size()) {
        min_empty = min(min_empty,count_empty());
    }
    else {
        CCTV cctv = cctv_cache[len];
        int dir_it = cctv.type == 5 ? 1 : (cctv.type == 2 ? 2 : 4);
        for (int i = 0; i < dir_it;i++) {
            fill_cctv(cctv.type,i, cctv.x, cctv.y,-1);
            backtracking(len+1);
            fill_cctv(cctv.type,i, cctv.x, cctv.y,1);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int num;
            cin >> num;
            map[i][j] = num;
            if (map[i][j] > 0 && map[i][j] < 6) {
                cctv_cache.push_back(CCTV(map[i][j],i,j));
            }
        }
    }
    backtracking(0);
    cout << min_empty << endl;
    return 0;
}