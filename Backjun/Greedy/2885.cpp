#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    int choco = 2;
    int chocoResult = 0;

    while (choco < k) {
        choco*=2;
    }
    chocoResult = choco;
    if (choco==k) {
        cout << chocoResult << " " << 0 << endl;
        return 0;
    }
    int count = 0;
    while (k != 0) {
        choco/=2;
        if (choco==0) {
            break;
        }
        if (k >= choco) {
            k-=choco;
        }
        //cout << k << endl;
        count++;
    }
    cout << chocoResult << " " << count << endl;
    return 0;
}