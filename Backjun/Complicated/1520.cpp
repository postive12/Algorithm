//Solved
//1520 내리막 길
//dp backtracking
/*
    풀이 과정
    dfs와 백트래킹을 이용한 방식으로
    백트래킹을 통해 자신보다 작은 곳으로만 내려간다
    내려가다가 도착 지점에 도달하면 갑승ㄹ 증가시킨 후 리턴
*/
#include <iostream>
using namespace std;
//directions
pair<int,int> directions[4] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}  
};
int m,n;
int map[501][501] = {0};
int is_reach[501][501] = {0};
bool is_visited[501][501] = {false};
int backtracking(int x,int y){
    if (x == m-1&&y == n-1) {
        return 1;
    }
    if (is_visited[y][x]) {
        return is_reach[y][x];
    }
    int cur_height = map[y][x];
    //cout << x << " / " << y<< " / " << cur_height << endl;
    for (int i = 0;i < 4;i++) {
        int next_y = y + directions[i].first;
        int next_x = x + directions[i].second;
        if(next_y < 0 || next_y >= m || next_x < 0||next_x >= n) continue;
        if(cur_height <= map[next_y][next_x]) continue;
        is_reach[y][x] += backtracking(next_x,next_y);
        is_visited[y][x] = true;
    }
    return is_reach[y][x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            cin >> map[i][j];
        }
    }
    cout << backtracking(0,0) << endl;
    return 0;
}