//16234 인구이동
//BFS
/*
    풀이 과정
    bfs를 이용해서 그룹 탐색
    방문 여부 판별 배열 필요
    방문하지 않은 나라를 모두 탐색한다
        for i = start to end do
            if is_selected then continue
            bfs(x,y)
        endfor

    //만약 만들어진 그룹 크기가 0이면 그룹이 더이상 만들어 질 수 없다는 것 반복문 종료
    if country_group.size() == 0 break;
    이렇게 탐색된 나라들의 그룹 좌표를 vector<vector<pair<int,int>>>로 저장한다
    저장한 좌표들의 평균을 구한뒤 기입힌다. 이 과정을 반복한다
*/
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//directions
pair<int,int> directions[4] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
//맵 변수들
int map[51][51] = {0};
bool is_visited[51][51] = {false};
vector<vector<pair<int,int>>> map_group;
vector<int> group_sum;
//입력 변수들
int n,l,r = 0;
void bfs_group(int x,int y){
    //방문 그룹
    queue<pair<int,int>> q;
    //그룹 변수들에 기입
    map_group.push_back(vector<pair<int,int>>());
    group_sum.push_back(0);
    //현재 위치 저장
    int cur_group = map_group.size() - 1;
    //초기 위치 기입
    q.push({x,y});
    is_visited[x][y] = true;

    while (!q.empty()) {
        pair<int,int> pos = q.front();
        map_group[cur_group].push_back(pos);
        //방문한 위치의 인구 합산
        group_sum[cur_group] += map[pos.first][pos.second];
        int population = map[pos.first][pos.second];
        q.pop();
        //반복문으로 4개 방향 방문
        for(int i = 0;i < 4;i++){
            int next_x = pos.first + directions[i].first;
            int next_y = pos.second + directions[i].second;
            //범위에 벗어나 있으면 넘김
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >=n) continue;
            //이미 방문했으면 넘김
            if (is_visited[next_x][next_y]) continue;
            int gap = abs(population - map[next_x][next_y]);
            //차이가 조건에 부합하지 않으면 넘김
            if (gap < l || gap > r) continue;
            //방문 처리 후 방문 큐에 삽입
            is_visited[next_x][next_y] = true;
            q.push({next_x,next_y});
        }
    }
    //그룹 구성원이 하나면 그룹 삭제
    if (map_group[cur_group].size() <= 1) {
        map_group.pop_back();
        group_sum.pop_back();
    }
}
int main()
{
    cin >> n >> l >> r;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> map[i][j];
            is_visited[i][j] = false;
        }
    }
    int loop_count = 0;
    while (true) {
        //그룹 변수 초기화
        map_group.clear();
        group_sum.clear();
        //방문 여부 초기화
        for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) is_visited[i][j] = false;
        
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (is_visited[i][j]) continue;
                bfs_group(i,j);
            }
        }
        //만들어진 그룹 사이즈가 0이면 루프 탈출
        if (group_sum.size() == 0) break;
        //그룹이 있을 시 루프 카운트 증가
        loop_count++;
        //그룹 사이즈로 값 나누기
        for (int i = 0;i <group_sum.size();i++) {
            group_sum[i] /= map_group[i].size();
        }
        //생성된 그룹에 값 기입
        for (int i = 0;i < map_group.size();i++) {
            for (int j = 0;j < map_group[i].size();j++) {
                pair<int,int> pos = map_group[i][j];
                map[pos.first][pos.second] = group_sum[i];
            }
        }
    }
    cout << loop_count << endl;
    return 0;
}