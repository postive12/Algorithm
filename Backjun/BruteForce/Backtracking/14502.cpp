//2023-08-21
//Solved
#include "bits/stdc++.h"
using namespace std;
pair<short, short> directions[4] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
short table[8][8] = {0};
short table_copy[8][8] = {0};
short max_result = 0;
int n,m;
vector<pair<short, short>> virus;
void copy_table(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            table_copy[i][j] = table[i][j];
        }

    }
}
void spread_virus(pair<short, short> pos){
    queue<pair<short, short>> q;
    q.push(pos);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nxt_x = x + directions[i].first;
            int nxt_y = y + directions[i].second;
            if(nxt_x >= n || nxt_x < 0 || nxt_y >=m || nxt_y < 0) continue;
            if (table_copy[nxt_x][nxt_y] > 0) continue;
            table_copy[nxt_x][nxt_y] = 2;
            q.push({nxt_x,nxt_y});
        }
    }
}
void check_virus(){
    copy_table();
    for (int i = 0;i < virus.size();i++) {
        spread_virus(virus[i]);
    }
    //count empty
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (table_copy[i][j] == 0) {
                result++;
            }
        }
    }
    max_result = result > max_result ? result : max_result;
}
void we_will_build_the_wall(int num,int wall_count){
    if (wall_count == 3) {
        //check
        check_virus();
        return;
    }
    for (int i = num;i < n * m;i++) {
        int x = i / m;
        int y = i % m;
        if (table[x][y] > 0) continue;
        table[x][y] = 1;
        we_will_build_the_wall(i, wall_count+1);
        table[x][y] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short num;
            cin >> num;
            table[i][j] = num;
            if (table[i][j] == 2) virus.push_back({i,j});
        }
    }
    we_will_build_the_wall(0,0);
    cout << max_result << endl;
    return 0;
}