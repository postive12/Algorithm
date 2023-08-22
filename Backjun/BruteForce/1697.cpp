//2023-08-22 숨박꼭질
//Solved
#include "bits/stdc++.h"
#define MAX 1e9 
//2배 절반일 때
using namespace std;
int distances[100001] = {0};
void bfs(int from,int to){
    queue<int> q;
    distances[from] = 0;
    q.push(from);
    while (!q.empty()) {
        int cur_pos = q.front();
        q.pop();        
        if (cur_pos == to) continue;
        int dist = distances[cur_pos] + 1;
        if(cur_pos + 1 <= 100000 && distances[cur_pos + 1] > dist){
            distances[cur_pos + 1] = dist;
            q.push(cur_pos + 1);
        }
        if(cur_pos - 1 >= 0 && distances[cur_pos - 1] > dist){
            distances[cur_pos - 1] = dist;
            q.push(cur_pos - 1);
        }
        if(cur_pos * 2 <= 100000 && distances[cur_pos * 2] > dist){
            distances[cur_pos * 2] = dist;
            q.push(cur_pos * 2);
        }
    }
};
int main()
{
    ios::sync_with_stdio(false);
    fill_n(distances,100001,MAX);
    int n,k;
    cin >> n >> k;
    bfs(n, k);
    cout << distances[k] << endl;
    return 0;
}