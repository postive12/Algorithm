//Solved bfs djikstra
/*
    풀이 순서
    1. 맵을 입력 받는다
    2. bfs로 탐색
        2.1 이때 다음 탐색을 수행하기 위한 총 비용을 pair로 넘겨줌
        2.2 이와 동시에 distance 배열에 다음 탐색 위치 비용을 기입한다
        ex) 최대 비용은 (125 + 125)*9를 넘지 않음 int로 수행
*/
#include <iostream>
#include <queue>
#define MAX 1e9
using namespace std;
//direction
pair<int,int> directions[4] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
};
int n = 0;
int map[126][126] = {0};
int distance_map[126][126] = {0};
void bfs(int sx,int sy){
    queue<pair<int,pair<int,int>>> q;
    distance_map[sx][sy] = map[sx][sy];
    q.push({0,{sx,sy}});
    while (!q.empty()) {
        int cost = q.front().first;
        pair<int,int> pos = q.front().second;
        q.pop();
        for(int i = 0;i < 4;i++){
            int next_x = pos.first + directions[i].first;
            int next_y = pos.second + directions[i].second;
            if(next_x < 0||next_x >=n || next_y < 0||next_y >=n) continue;
            int next_cost = distance_map[pos.first][pos.second] + map[next_x][next_y];
            if (next_cost < distance_map[next_x][next_y]) {
                distance_map[next_x][next_y] = next_cost;
                q.push({next_cost,{next_x,next_y}});
            }
        }
    }
}
int main()
{
    int case_num = 0;
    while (true) {
        case_num++;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0;j < n;j++) {
                cin >> map[i][j];
                distance_map[i][j] = MAX;
            }
        }
        bfs(0,0);
        cout << "Problem " << case_num << ": " << distance_map[n-1][n-1] << "\n";
    }
    return 0;
}