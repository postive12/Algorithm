#include <iostream>
using namespace std;
int field[301][301] = {0};
int cache[301][301] = {0};
int main()
{
    int m,n;
    cin >> m >> n;
    // y, x
    int count = 0;
    for (int i = 1; i <= m; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            int num = 0;
            cin >> num;
            sum += num;
            field[i][j] = num;
            cache[i][j] = sum + cache[i-1][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (field[i][j] == 10){
                count++;
                continue;
            }
            //cout << cache[i][j] << "\t";
            for (int k = i; k <= m; k++) {
                for (int g = j; g <= n; g++) {
                    int sum = 0;
                    sum += cache[k][g];
                    sum -= cache[i-1][g];
                    sum -= cache[k][j-1];
                    sum += cache[i-1][j-1];
                    if (sum >= 10){
                        if (sum == 10) count++;
                        break;
                    }
                }
            }
        }
        //cout << endl;
    }
    cout << count << endl;
}