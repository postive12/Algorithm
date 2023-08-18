#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> inputted_num;
    vector<int> find_num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        inputted_num.push_back(a);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        find_num.push_back(a);
    }
    sort(inputted_num.begin(),inputted_num.end());
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = 0;
        int target = find_num[i];
        if (binary_search(inputted_num.begin(),inputted_num.end(),target)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}
