//2023-08-20
//푸는 중
#include "bits/stdc++.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    string input;
    cin >> input;
    stack<short> numbers;
    vector<short> result;
    int request_size = n - k;
    for (int i = 0; i < input.size();i++) {
        numbers.push(input[i] - 48);
    }
    while (!numbers.empty()) {
        if (result.size() < request_size) {
            result.push_back(numbers.top());
            numbers.pop();
        }
        else{
            short current = numbers.top();
            numbers.pop();
            int min_num = 0;
            for (int i = 0 - 1;i < result.size() ;i++) {
                if (result[min_num] > result[i]) {
                    min_num = i;
                    break;
                }
            }
            result[min_num] = current;
        }
    }
    for (int i = result.size() - 1;i >= 0;i--) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}