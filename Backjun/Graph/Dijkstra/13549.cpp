//13549 숨박꼭질 3
/*
    풀이 과정
    다익스트라로 장소에 도달할 수 있을 때까지 탐색
    탐색위치가 100000보다 크다면 탐색 큐에 추가하지 않음
    pair을 통해 현재 비용을 같이 넘겨줌
    장소에 도달하면 탐색 중단
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e9;
using namespace std;
//거리 저장 배열
int distances[100001] = {0};
//다익스트라
int djikstra(int start,int end){
    //다익스트라용 우선순위 큐
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    //시작 점 기입
    q.push({0,start});
    while (!q.empty()) {
        int cur_pos = q.top().second;
        int cur_cost = q.top().first;
        q.pop();
        //현재 정점이 비용이 더 크다면 넘김
        if (distances[cur_pos] < cur_cost) continue;
        //이후 방문한 정점은 반드시 비용이 최소 때문에 가장 목표 지점에 도달한 경로가 최소
        if (cur_pos == end) return cur_cost;
        //x+1
        int next_pos = cur_pos + 1;
        int next_cost = cur_cost + 1;
        if (next_pos <= 100000 && distances[next_pos] > cur_cost + 1) {
            distances[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
        //x-1
        next_pos = cur_pos - 1;
        if (cur_pos - 1 >= 0 && distances[next_pos] > cur_cost + 1){
            distances[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
        //x*2
        next_pos = cur_pos * 2;
        next_cost = cur_cost;
        if (cur_pos != 0 && end > cur_pos && next_pos <= 100000 && distances[next_pos] > next_cost){
            distances[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
    }
    //failed
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0;i < 100001; i++) distances[i] = MAX;
    int n,k;
    cin >> n >> k;
    cout << djikstra(n,k) << endl;
    return 0;
}