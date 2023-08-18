#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1e9
using namespace std;
int main()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<vector<int>> link_vector(n+1);
    vector<int> min_distance(n+1,MAX);
    for (int i = 0;i < m; i++) {
        int s,e;
        cin >> s >> e;
        link_vector[s].push_back(e); 
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visit_queue;
    min_distance[x] = 0;
    visit_queue.push({0,x});
    while (!visit_queue.empty()) {
        pair<int,int> cur_ver = visit_queue.top();
        visit_queue.pop();
        for (int i = 0; i < link_vector[cur_ver.second].size(); i++) {
            int v = link_vector[cur_ver.second][i];
            int cur_dis = cur_ver.first + 1;
            if (cur_dis < min_distance[v]) {
                min_distance[v] = cur_dis;
                visit_queue.push({cur_dis,v}) ;
            }
        }
    }
    bool is_printed = false;
    for (int i = 1; i < min_distance.size();i++) {
        if (min_distance[i]==k) {
            cout << i<< endl;
            is_printed = true;
        }
    }
    if (!is_printed) {
        cout << -1 << endl;
    }

}