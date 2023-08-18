#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#define MAX 1e9
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> schedule;
    for (int i = 0; i < n;i++) {
        pair<long long, long long> sc;//앞 수가 끝나는 시간 뒷 수가 시작 시간
        cin >> sc.first >> sc.second;
        schedule.push(sc);
    }

    stack<pair<long long,long long>> result;
    while (!schedule.empty()) {
        pair<long long, long long> sc = schedule.top();
        schedule.pop();
        if (result.empty()) {
            result.push(sc);
            continue;
        }
        pair<long long, long long> lst = result.top();
        if (lst.second > sc.first) {
            //두 시간대가 겹친다
            if (sc.second < lst.second) {
                //그런데 끝나는 시간대가 더 이르다면 교체
                result.pop();
                result.push(sc);
            }//아니라면 그냥 지나감
            continue;
        }
        else {
            //만약 시작 시간이 끝나는 시간보다 뒤라면 그냥 스택에 추가
            result.push(sc);
        }
    }
    int count = 0;
    while (!result.empty()) {
        count++;
        result.pop();
    }
    cout << count << endl;
}