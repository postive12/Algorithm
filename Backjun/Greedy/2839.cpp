#include <ios>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    int result = 0;
    while (n >= 3) {
        if (n%5==0) {
            result+= n/5;
            n %= 5;
        }
        else{
            result++;
            n -= 3;
        }
    }
    if (n == 0) {
        cout << result << endl;
    }
    else{
        cout << -1 << endl;
    }
}