//2021-08-23 주사위 굴리기
//Solved
#include <bits/stdc++.h>
using namespace std;
pair<int,int> directions[4] = {
    {1,0},
    {-1,0},
    {0,-1},
    {0,1}
};
int dice[4][3] = {
    {-1,0,-1},
    {0,0,0},
    {-1,0,-1},
    {-1,0,-1},
    
};
int table[20][20] = {};
int n,m = 0;
int x,y = 0;
int k = 0;
vector<int> commands;
void roll_dice(int direction){
    if (direction == 1) {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = tmp;
    }
    if (direction == 2) {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = tmp;
    }
    if (direction == 3) {
        int tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
    }
    if (direction == 4) {
        int tmp = dice[0][1];
        dice[0][1] = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = tmp;
    }
}
int main()
{
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < k;i++) {
        int num;
        cin >> num;
        commands.push_back(num);
    }
    for (int i = 0;i < commands.size();i++) {
        int command = commands[i];
        int next_x = x + directions[command-1].first;
        int next_y = y + directions[command-1].second;
        if (next_x >= m || next_x < 0 || next_y >= n || next_y < 0) continue;
        roll_dice(command);
        x = next_x;
        y = next_y;
        int table_num = table[y][x];
        if (table_num == 0) {
            table[y][x] = dice[3][1];
        }
        else {
            dice[3][1] = table_num;
            table[y][x] = 0;
        }
        cout << dice[1][1] << endl;
    }
}