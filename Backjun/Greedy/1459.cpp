#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    long x,y,w,s;
    cin >> x >> y >> w >> s;
    long cost = 0;
    bool isAcrossCheap = (w*2) > s;
    if (isAcrossCheap) {
        if(x==y){
            cout << x * s << endl;
            return 0;
        }
        long gap = abs(x-y);
        cost = min(x,y) * s;
        if (w <= s) {
            cost += gap * w;
        }
        else {
            if (gap % 2 == 0) {
                cost += gap * s;
            }
            else{
                cost += (gap - 1) * s + w;
            }
        }
    }
    else{
        cost = (x + y) * w;
    }
    cout << cost << endl;
    return 0;
}