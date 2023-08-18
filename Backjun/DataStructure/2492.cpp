#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <stack>
#define MAX 1e9
using namespace std;
int main()
{
    int cycle = 0;
    cin >> cycle;
    stack<pair<int,int>> tower;
    stack<pair<int,int>> height_stack; 
    vector<int> recieve(cycle+1,0);
    for(int i = 1; i <= cycle; i++){
        int n = 0;
        cin >> n;
        tower.push({i,n});
    }
    pair<int,int> n = tower.top();
    tower.pop();
    height_stack.push(n);

    while (!tower.empty()) {
        pair<int,int> cur_pos = tower.top();
        tower.pop();
        //cout << curHeight.second <<"/" << height_stack.top().second << endl;
        while (!height_stack.empty()&&height_stack.top().second <= cur_pos.second) {
            pair<int, int> cur_pair = height_stack.top();
            //cout << cur_pos.second <<"/" << cur_pair.second << "/" << height_stack.size() << endl;
            height_stack.pop();
            recieve[cur_pair.first] = cur_pos.first;
        }
        height_stack.push(cur_pos);
    }
    for (int i = 1;i < recieve.size();i++) {
        cout << recieve[i] << " ";
    }
    cout << endl;
}