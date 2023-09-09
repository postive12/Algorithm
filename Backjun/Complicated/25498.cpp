//Solved
//25498 핸들 뭘로 하지
//bfs,backtracking, greedy
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n = 0;
vector<vector<int>> vertexes;
vector<bool> is_visited;
string input;
string bfs()
{
    string result_str = "";
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({1,1});
    result_str.append(1,input[0]);
    is_visited[1] = true;
    while (!q.empty()) {
        int cur_pos = q.top().second;
        int cur_depth = q.top().first;
        char cur_char = input[cur_pos-1];
        q.pop();

        if (result_str[cur_depth-1] > cur_char) continue;

        int next_depth = cur_depth + 1;
        for (int i = 0;i < vertexes[cur_pos].size(); i++) {
            if (is_visited[vertexes[cur_pos][i]]) continue;
            is_visited[vertexes[cur_pos][i]] = true;
            char next_char = input[vertexes[cur_pos][i] - 1];
            if (result_str.size() < next_depth){
                result_str.append(1,next_char);
                q.push({next_depth,vertexes[cur_pos][i]});
            }
            else if(result_str[next_depth-1] > next_char){
                continue;
            }
            result_str[next_depth-1] = next_char;
            q.push({next_depth,vertexes[cur_pos][i]});
        }
    }
    return result_str;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> input;
    vertexes = vector<vector<int>>(n+1,vector<int>());
    is_visited = vector<bool>(n+1,false);
    for (int i = 0;i < n - 1;i++) {
        int a,b;
        cin >> a >> b;
        vertexes[a].push_back(b);
        vertexes[b].push_back(a);
    }
    cout << bfs() << endl;
    return 0;
}