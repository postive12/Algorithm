#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int cost = 1000;
    int n = 0;
    int result = 0;
    int coin[6] = {500,100,50,10,5,1}; 
    cin >> n;
    cost-=n;
    for (int i = 0; i < 6;i++) {
        result += cost / coin[i];
        cost %= coin[i];
    }
    cout << result;
    return 0;
}