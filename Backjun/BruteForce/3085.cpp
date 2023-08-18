//먼저 자기 자신이 스왑이 가능한지 확인
//스왑이 불가능 하면 일단 먼저 모든 행과 영을 체크
//각 열이나 행에 대한 값을 기록해놓음
//기록한 값들 중 최댓값을 출력하도록 한다
//Solved
#include <algorithm>
#include <iostream>
using namespace std;
int n;
char map[50][50];
int eat_max = 0;
int routeX[4] = {1, -1,0,0};
int routeY[4] = {0, 0,1,-1};
void check_map(){
    //check row
    for (int i = 0;i < n;i++) {
        int result = 0;
        int lastChar = map[i][0];
        for (int j = 0; j < n;j++) {
            if (map[i][j] != lastChar) {
                lastChar = map[i][j];
                eat_max = max(result,eat_max);
                result = 0;
            }
            result++;
        }
        eat_max = max(result,eat_max);
    }
    //check row reverse
    for (int i = n - 1;i >=0 ;i--) {
        int result = 0;
        int lastChar = map[i][n-1];
        for (int j = n - 1; j >= 0;j--) {
            if (map[i][j] != lastChar) {
                lastChar = map[i][j];
                eat_max = max(result,eat_max);
                result = 0;
            }
            result++;
        }
        eat_max = max(result,eat_max);
    }
    //check column
    for (int i = 0;i < n;i++) {
        int result = 0;
        int lastChar = map[0][i];
        for (int j = 0; j < n;j++) {
            if (map[j][i] != lastChar) {
                lastChar = map[j][i];
                eat_max = max(result,eat_max);
                result = 0;
            }
            result++;
        }
        eat_max = max(result,eat_max);
    }
    //check column reverse
    for (int i = n - 1;i >=0 ;i--) {
        int result = 0;
        int lastChar = map[n-1][i];
        for (int j = n - 1; j >= 0;j--) {
            if (map[j][i] != lastChar) {
                lastChar = map[j][i];
                eat_max = max(result,eat_max);
                result = 0;
            }
            result++;
        }
        eat_max = max(result,eat_max);
    }
}
void check_swap(int x,int y){
    //cout << "============= x : " << x << " / y : " << y << endl; 
    for (int i = 0; i < 4; i++) {
        int targetX = x + routeX[i];
        int targetY = y + routeY[i];
        if (targetX < 0) continue;
        if (targetX >= n) continue;
        if (targetY < 0) continue;
        if (targetY >= n) continue;
        char tmpA = map[x][y];
        char tmpB = map[targetX][targetY];
        if (tmpA == tmpB) continue;
        //cout << " x : " << targetX << " / y : " << targetY << " || char : "  << tmpB <<endl; 
        map[x][y] = tmpB;
        map[targetX][targetY] = tmpA;
        check_map();
        map[targetX][targetY] = tmpB;
        map[x][y] = tmpA;
        if (eat_max == n) {
            return;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n;i++){
        for (int j = 0;j < n;j++) {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    for(int i = 0; i < n;i++){
        for (int j = 0;j < n;j++) {
            check_swap(i,j);
            if (eat_max == n) {
                break;
            }
        }
    }
    cout << eat_max << endl;
    return 0;
}