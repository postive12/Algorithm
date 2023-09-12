#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX 1e9
using namespace std;
/*
    풀이과정
    제약 x에서 y로 이동할 때 +,* 등 늘어나는 연산만 사용하기에 중간에 가지치기 가능
    bfs를 활용한 백트래킹으로 풀이
    우선순위 큐를 사용하여 가장 횟수가 적은 대상먼저 탐색
    만약 새롭게 찾은 루트가 이미 방문 되어 있으면서 비용이 현재보다 더 작으면 큐에 넣지 않음
*/
int cost_cache[10000001] = {0};
int bfs_backtracking(int x,int y,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//우선순위 큐 사용
    q.push({0,x});
    cost_cache[x] = 0;
    while(!q.empty()){
        int cur_cost = q.top().first;
        int cur_pos = q.top().second;
        q.pop();
        if(cur_pos == y) return cur_cost;
        int next_cost = cur_cost + 1;
        int next_pos = cur_pos + n;
        if(next_pos <= y&&next_cost < cost_cache[next_pos]){
            cost_cache[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
        next_pos = cur_pos * 2;
        if(next_pos <= y &&next_cost < cost_cache[next_pos]){
            cost_cache[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
        next_pos = cur_pos * 3;
        if(next_pos <= y &&next_cost < cost_cache[next_pos]){
            cost_cache[next_pos] = next_cost;
            q.push({next_cost,next_pos});
        }
    }
    //못 찾으면 -1 
    return -1;
}
int solution(int x, int y, int n) {
    //초기화 필요
    for(int i = 0;i < 1000001;i++) cost_cache[i] = MAX;
    return bfs_backtracking(x,y,n);
}
