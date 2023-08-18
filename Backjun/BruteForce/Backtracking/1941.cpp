//2023-08-15 소문난 칠공주
//Solved
#include <iostream>
#include <queue>
using namespace std;
//방향
pair<int, int> direction[4] = {
    {0 , 1},
    {1,0},
    {0,-1},
    {-1,0},
};
//교실
//TRUE = 이다솜 FALSE = 임도연
bool map[5][5] = {};
//교실에서 선택되었는지 중복 체크
bool is_selected[25] = {};
//그룹원 위치
pair<int,int> group[7];
//그룹원 방문 판별 
bool is_group_visited[7];
//결과값
int result = 0;
//생성된 그룹이 적절한지 판별하는 함수
bool check_group(){
    //그룹 방문 배열 초기화
    fill_n(is_group_visited,7,false);
    //큐 생성
    queue<int> queue;
    //첫 노드 방문 처리
    is_group_visited[0] = true;
    //그룹 위치 중 첫노드 를 큐에 기입
    queue.push(0);
    while (!queue.empty()) {
        //현재 그룹원 가져오기
        int cur_mem = queue.front();
        queue.pop();
        //가져온 그룹원 위치 저장
        int cur_x = group[cur_mem].first;
        int cur_y = group[cur_mem].second;
        for (int i = 0; i < 4; i++) {
            //4 방향으로 탐색
            int next_x = cur_x + direction[i].first;
            int next_y = cur_y + direction[i].second;
            //값을 벗어났는지 확인
            if (next_x >=5 || next_x < 0 || next_y < 0 || next_y >= 5) continue;
            //방문 가능한 노드 확인
            for(int j = 0;j < 7;j++){
                if (!is_group_visited[j]&&group[j].first == next_x && group[j].second == next_y) {
                    is_group_visited[j] = true;
                    queue.push(j);
                }
            }   
        }
    }
    //방문하지 않은 노드가 있다면 false
    for (int i = 0; i < 7; i++) {
        if (!is_group_visited[i]) {
            return false;
        }
    }
    return true;
}
//그룹 생성
void backtracking(int num,int group_count,int doyeon){
    //임도연 파가 그룹의 과반을 넘으면 당연히 이다솜 파는 최솟값을 맞출 수 없음
    if (doyeon >= 4) {
        return;
    }
    //그룹이 구성되었는지 확인
    if (group_count == 7) {
        //그룹 검증 후 결과값 증가
        if (check_group()) result++;
        return;
    }
    //그룹을 중복없는 순서 상관 없는 조합으로 생성
    //중복이 제거되어야 하기 때문에 현제 학번 이후부터 탐색해야함
    for (int i = num; i < 25; i++) {
        int x = i%5;
        int y = i/5;
        if (is_selected[i]) continue;
        //방문처리
        is_selected[i] = true;
        group[group_count] = pair<int,int>(x,y);
        //그룹원 기입 후 백트래킹
        backtracking(i,group_count+1,map[x][y]?doyeon:doyeon+1);
        //방문 안함 처리
        is_selected[i] = false;
    }
}

int main()
{
    for (int i = 0;i<5;i++) {
        for (int j = 0; j < 5;j++) {
            char c;
            cin >> c;
            map[i][j] = c == 'S';
        }
    }
    backtracking(0,0,0);
    cout << result << endl;
    return 0;
}