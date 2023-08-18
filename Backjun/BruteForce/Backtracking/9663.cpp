//2023-08-14 N-Queen
//Solved Slower
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int n;
int result_count = 0;
vector<pair<int,int>> queens;
int chess_map[16][16] = {0};
bool is_attackable(pair<int,int> a,pair<int,int> b)
{
    if (a.first == b.first) {
        return true;
    }
    if (a.second == b.second) {
        return true;
    }
    if (abs(a.first - b.first) == abs(a.second - b.second)) {
        return true;
    }
    return false;
}
bool is_all_not_attakable(pair<int,int> pos)
{
    for (int i = 0; i < queens.size();i++) {
        if (is_attackable(queens[i],pos)) {
            return false;
        }
    }
    return true;
}
void backtracking(int layer)
{
    if (layer == n) {
        result_count++;
    }
    else {
        for (int i = 0;i < n;i++) {
            pair<int,int> pos(i,layer);
            if (is_all_not_attakable(pos)) {
                queens.push_back(pos);
                backtracking(layer+1);
                queens.pop_back();
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    backtracking(0);
    cout << result_count << endl;
    return 0;
}
//Solved Faster
// #include <iostream>
// #include <vector>
// using namespace std;
// int n;
// int result_count = 0;
// pair<int,int> direction[8] ={
//     {0,1},
//     {1,1},
//     {1,0},
//     {1,-1},
//     {0,-1},
//     {-1,-1},
//     {-1,0},
//     {-1,1},
// };
// int chess_map[16][16] = {0};
// void fill_queen(pair<int,int> pos,int num){
//     chess_map[pos.first][pos.second] += num;
//     for (int i = 0; i < 8; i++) {
//         int curX = pos.first + direction[i].first;
//         int curY = pos.second + direction[i].second;
//         while (curX >= 0&&curX<n&&curY >= 0&&curY <n) {
//             chess_map[curX][curY] += num;
//             curX += direction[i].first;
//             curY += direction[i].second;
//         }
//     }
// }
// void backtracking(int layer)
// {
//     if (layer == n) {
//         result_count++;
//     }
//     else {
//         for (int i = 0;i < n;i++) {
//             pair<int,int> pos(i,layer);
//             if (chess_map[pos.first][pos.second] > 0) continue;
//             fill_queen(pos, 1);
//             backtracking(layer+1);
//             fill_queen(pos, -1);
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin >> n;
//     backtracking(0);
//     cout << result_count << endl;
//     return 0;
// }