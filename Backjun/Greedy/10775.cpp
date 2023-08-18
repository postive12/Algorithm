//Solved
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int g,p = 0;
    cin >> g >> p;
    vector<bool> gate(g + 1,false);
    vector<int> gatePos;
    vector<int> planes;
    gate[0] = true;
    for (int i = 0;i < g + 1;i++) {
        gatePos.push_back(i);
    }
    for (int i = 0;i < p; i++) {
        int num = 0;
        cin >> num;
        planes.push_back(num);
    }
    int count = 0;
    for (int i = 0;planes.size();i++) {
        int cur = planes[i];
        if (gatePos[cur] <= 0) {
            break;
        }
        bool isSuccess = false;
        for (int i = gatePos[cur];i > 0;i--) {
            if (gate[i]) {
                gatePos[i] = gatePos[i] - 1;
                continue;
            }
            gate[i] = true;
            gatePos[cur] = i - 1;
            isSuccess = true;
            break;
        }
        if (!isSuccess) {
            break;
        }
        count++;
    }
    cout << count << endl;
}