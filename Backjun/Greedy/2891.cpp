//Finish
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, s, r;
    cin >> n >> s >> r;
    vector<int> teams(n + 2, 1);
    for (int i = 0; i < s; i++) {
        int num;
        cin >> num;
        teams[num] = 0;
    }
    for (int i = 0; i < r; i++) {
        int num;
        cin >> num;
        teams[num] = teams[num] == 0 ? 1 : 2;
    }
    for (int i = 1; i < n + 1 ; i++) {
       
        if (teams[i] >= 1) {
            continue;
        }
        if (teams[i - 1] == 2) {
            teams[i - 1] = 1;
            teams[i] = 1;
            continue;
        }
        if (teams[i + 1] == 2) {
            teams[i + 1] = 1;
            teams[i] = 1;
            continue;
        }
    }
    int count = 0;
    for (int i = 0; i < teams.size(); i++) {
        if (teams[i] == 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}