//Solved
// 1 1 1 1 2를 방문했다면 반대 숫자인 2 1 1 1 1도 당연히 가능해짐
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
short map[5][5] = {0};
priority_queue<string> results;
vector<string> dfs(int x,int y,int remains){
    vector<string> result;
    if (remains <= 0) {
        result.push_back("");
        return result;
    }
    priority_queue<string> result_cache;
    remains--;
    string myNum = to_string(map[x][y]);
    //Add my num and add to result;
    if (x - 1 >= 0) {
        vector<string> r = dfs(x - 1, y, remains);
        for (int i = 0; i < r.size(); i++) {
            result_cache.push(myNum + r[i]);
        }
    }
    if (x + 1 < 5) {
        vector<string> r = dfs(x + 1, y, remains);
        for (int i = 0; i < r.size(); i++) {
            result_cache.push(myNum + r[i]);
        }
    }
    if (y - 1 >= 0) {
        vector<string> r = dfs(x, y - 1, remains);
        for (int i = 0; i < r.size(); i++) {
            result_cache.push(myNum + r[i]);
        }
    }
    if (y + 1 < 5) {
        vector<string> r = dfs(x, y + 1, remains);
        for (int i = 0; i < r.size(); i++) {
            result_cache.push(myNum + r[i]);
        }
    }
    string lastString = "";
    while (!result_cache.empty()) {
        string cur = result_cache.top();
        result_cache.pop();
        if (lastString.compare(cur) != 0) {
            lastString = cur;
            result.push_back(cur);
        }
    }
    return result;
}
int main(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            short num;
            cin >> num;
            map[i][j] = num;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vector<string> result = dfs(i,j,6);
            for (int k = 0; k < result.size(); k++) {
                results.push(result[k]);
            }
        }
    }
    string lastString = "";
    int count = 0;
    while (!results.empty()) {
        string cur = results.top();
        results.pop();
        if (lastString.compare(cur) != 0) {
            lastString = cur;
            count++;
        }
    }
    cout << count << endl;
    // while (!results.empty()) {
    //     string r = results.top();
    //     results.pop();
    //     cout << r << endl;
    // }
    
    return 0;
}