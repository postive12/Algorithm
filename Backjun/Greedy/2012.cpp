#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int cycle;
    cin >> cycle;
    priority_queue<int,vector<int>,greater<int>> numbers;
    for (int i = 0;i < cycle;i++) {
        int num;
        cin >> num;
        numbers.push(num);
    }
    long long point = 0;
    long long currentPos = 1;
    while (!numbers.empty()) {
        int currentNum = numbers.top();
        numbers.pop();
        point += abs(currentNum-currentPos);
        currentPos++;
        //cout << point << endl;
    }
    cout << point << endl;
    return 0;
}