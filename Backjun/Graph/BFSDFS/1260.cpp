//Solved
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Vertex{
    public:
        bool is_visited = false;
        priority_queue<short,vector<short>,greater<short>> edges;
};
Vertex vertexes_dfs[1001];
Vertex vertexes_bfs[1001];
void dfs(int start){
    if (vertexes_dfs[start].is_visited) {
        return;
    }
    cout  << start << " ";
    vertexes_dfs[start].is_visited = true;
    while (!vertexes_dfs[start].edges.empty()) {
        short nextPos = vertexes_dfs[start].edges.top();
        vertexes_dfs[start].edges.pop();
        vertexes_bfs[start].edges.push(nextPos);
        dfs(nextPos);
    }
}
void bfs(int start){
    queue<short> visit_queue;
    visit_queue.push(start);
    while (!visit_queue.empty()) {
        int curPos = visit_queue.front();
        visit_queue.pop();
        if (vertexes_bfs[curPos].is_visited) {
            continue;
        }
        cout << curPos << " ";
        vertexes_bfs[curPos].is_visited = true;
        while (!vertexes_bfs[curPos].edges.empty()) {
            visit_queue.push(vertexes_bfs[curPos].edges.top());
            vertexes_bfs[curPos].edges.pop();
        }
    }
    
}
int main(){
    int n,m,v = 0;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        short s,e;
        cin >> s >> e;
        vertexes_dfs[s].edges.push(e);
        vertexes_dfs[e].edges.push(s);
    }
    dfs(v);
    cout << endl;
    bfs(v);
    cout << endl;
    return 0;
}