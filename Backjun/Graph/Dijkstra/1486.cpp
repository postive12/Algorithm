//1486 등산 2023-08-11
//Solved
#include <iostream>
#include <queue>
#include <cmath>
#define MAX 1e9
using namespace std;
//방향 선언
pair<int,int> direction[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
//사용 변수 선언
int n,m,t,d;
//배열 공간 선언
int map[25][25] = {0};
//배열 거리 선언
int map_distance[25][25] ={};
int map_return[25][25] = {};
//다익스트라 알고리즘
void dijkstra(int target_map[25][25],int x,int y,bool is_back = false){
    target_map[x][y] = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> queue;
    queue.push({0,{x,y}});
    while (!queue.empty()) {
        int cur_distance = queue.top().first;
        int cur_x = queue.top().second.first;
        int cur_y = queue.top().second.second;
        queue.pop();
        if (cur_distance > d) continue;
        if (target_map[cur_x][cur_y] < cur_distance) continue;
        for (int i = 0;i < 4; i++) {
            int next_x = cur_x + direction[i].first;
            int next_y = cur_y + direction[i].second;
            if (next_x >= n || next_x < 0||next_y >= m || next_y < 0) continue;
            int sub = map[next_x][next_y] - map[cur_x][cur_y];

            if (abs(sub) > t ) continue;

            int distance = target_map[cur_x][cur_y];
            if (!is_back) {
                if (sub <= 0) {distance += 1;}
                else {distance += pow(abs(sub),2);}
            }
            else{
                if (sub >= 0) {distance += 1;}
                else {distance += pow(abs(sub),2);}
            }
            
            if (distance < target_map[next_x][next_y]) {
                target_map[next_x][next_y] = distance;
                queue.push({distance,{next_x,next_y}});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    //배열 초기화
    for (int i = 0; i < 25; i++) 
        for (int j = 0; j < 25; j++) 
            map_distance[i][j] = MAX;
    for (int i = 0; i < 25; i++) 
        for (int j = 0; j < 25; j++) 
            map_return[i][j] = MAX;
    //변수 입력
    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c >= 'A' && 'Z' >= c) {
                map[i][j] = (int)c - 65 + 0;
            }
            else {
                map[i][j] = (int)c - 97 + 26;
            }
        }
    }
    //등산로 탐색
    dijkstra(map_distance,0,0);
    dijkstra(map_return,0,0,true);
    //탐색 등산로의 합을 구한 후 갈 수 있는 최대 높이를 구함
    int max_height = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total_dist = map_distance[i][j] + map_return[i][j];
            if (total_dist <= d) {
                max_height = max(max_height,map[i][j]);
            }
        }
    }
    //최대 높이 출력
    cout << max_height << endl;
    return 0;
}