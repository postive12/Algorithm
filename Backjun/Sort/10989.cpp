#include <vector>
#include <iostream>
using namespace std;
long numbers[10001] = {0};
int main(){
    ios::sync_with_stdio(false);
    int cycle;
    cin >> cycle;
    for (int i = 0;i < cycle;i++) {
        int num;
        cin >> num;
        numbers[num]++;
    }
    for (int i = 0;i <= 10000;i++) {
        int count = numbers[i];
        if (count == 0) continue;
        for (int j = 0;j < count;j++) {
            cout << i << "\n";
        }
    }
    return 0;
}