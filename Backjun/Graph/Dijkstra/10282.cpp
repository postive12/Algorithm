#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1e9
using namespace std;
void solve(){
    int v,e,s_vertex;
    cin >> v >> e >> s_vertex;
    vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> link_vector(v+1);
    vector<int> min_distance(v+1,MAX);
    for (int i = 0; i < e; i++) {
        int start,end,duration = 0;
        cin >> end >> start >> duration;
        pair<int,int> edge = {duration,end};
        link_vector[start].push(edge);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visit_queue;
    min_distance[s_vertex] = 0;
    visit_queue.push({0,s_vertex});
    while (!visit_queue.empty()) {
        pair<int,int> cur_ver = visit_queue.top();
        visit_queue.pop();
        while (!link_vector[cur_ver.second].empty()) {
            pair<int,int> cur_edge = link_vector[cur_ver.second].top();
            link_vector[cur_ver.second].pop();
            int cur_dur = cur_ver.first + cur_edge.first;
            if (min_distance[cur_edge.second] > cur_dur) {
                min_distance[cur_edge.second] = cur_dur;
                visit_queue.push({cur_dur,cur_edge.second});
            }
        }
    }
    int count = 0;
    int duration = 0;
    for (int i = 1; i < min_distance.size(); i++) {
        if (min_distance[i] < MAX) {
            count++;
            if (min_distance[i] > duration) {
                duration = min_distance[i];
            }
        }
    }
    cout << count << " " << duration << endl;
}
int main()
{
    int tc = 0;
    cin >> tc;
    for (int i = 0;i < tc;i++) {
        solve();
    }
}