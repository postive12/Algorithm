#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int currentN = n;
    int count = 1;
    currentN = 10 * (currentN % 10) + (n / 10 + n % 10) % 10;
    while (currentN != n) {
        currentN = 10 * (currentN % 10) + (currentN / 10 + currentN % 10) % 10;
        count++;
    }
    cout << count << endl;
}