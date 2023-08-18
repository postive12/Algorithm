//Solved
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1e8
using namespace std;
//입력 변수
int v,e;
int must_a,must_b;
//정점 벡터
vector<vector<pair<int,int>>> vertexes;
//거리 벡터
vector<int> vertex_distances;
//특정 정점 거리 연산 함수
int distance_a2b(int a,int b){
    vertex_distances = vector<int>(v+1,MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  queue;
    vertex_distances[a] = 0;
    queue.push(pair<int,int>(0,a));
    while (!queue.empty()) {
        int cur_vertex = queue.top().second;
        int cur_cost = queue.top().first;
        queue.pop();
        if (vertex_distances[cur_vertex] < cur_cost) {
            continue;
        }
        for (int i = 0; i < vertexes[cur_vertex].size();i++) {
            int v_vertex = vertexes[cur_vertex][i].second;
            int v_distance = vertexes[cur_vertex][i].first + cur_cost;
            if (vertex_distances[v_vertex] > v_distance) {
                vertex_distances[v_vertex] = v_distance;
                queue.push({v_distance,v_vertex});
            }
        }
    }
    return vertex_distances[b];
}
int main()
{
    cin >> v >> e;
    vertexes = vector<vector<pair<int,int>>>(v + 1);
    for (int i = 0;i < e;i++) {
        int a,b,cost;
        cin >> a >> b >> cost ;
        vertexes[a].push_back({cost,b});
        vertexes[b].push_back({cost,a});
    }
    cin >> must_a >> must_b;
    //반드시 지나야 하는 정점 거리 연산
    int must_a2b = distance_a2b(must_a,must_b);
    //반드시 지나야하는 정점과 시작 끝 정점 계산
    int o2a = distance_a2b(1,must_a);
    int o2b = distance_a2b(1,must_b);
    int b2n = distance_a2b(must_b,v);
    int a2n = distance_a2b(must_a,v);
    //각각의 결과 합
    int result_case_1 =  o2a + must_a2b + b2n;
    int result_case_2 =  o2b + must_a2b + a2n;
    //합 중 최솟값 선별
    int result = min(result_case_1,result_case_2);
    if (result >= MAX) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }
    return 0;
}