//Solved
#include <algorithm>
#include <iostream>
using namespace std;
char map[50][50] = {'0'};
char cached_chess_map_w[8][8] = {'0'};
char cached_chess_map_b[8][8] = {'0'};
int min_result = 64;//max is 64
void create_chess_map(char map[8][8],char start_char){
    char current_start = start_char;
    for (int i = 0 ; i <  8;i++) {
        map[i][0] = current_start;
        for (int j = 1; j < 8; j++) {
            map[i][j] = map[i][j-1] == 'W' ? 'B' : 'W';
        }
        current_start = current_start == 'W' ? 'B' : 'W';
    }
}
void check_chess_map(int x,int y){
    int count_b = 0;
    int count_w = 0;
    //check w b
    for (int i = x; i < x + 8;i++) {
        for (int j = y; j < y + 8; j++) {
            if (map[i][j] != cached_chess_map_b[i-x][j-y]) {
                count_b++;
            }
            if (map[i][j] != cached_chess_map_w[i-x][j-y]) {
                count_w++;
            }
        }
    }
    //cout << " x : " << x << " y : " << y << " b : " << count_b << " w : " << count_w << endl;
    min_result = min(min_result,count_b);
    min_result = min(min_result,count_w);
}
int main()
{
    int w,h;
    cin >> w >> h;
    for (int i = 0; i < w;i++) {
        for (int j = 0; j < h; j++) {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    create_chess_map(cached_chess_map_b,'B');
    create_chess_map(cached_chess_map_w,'W');
    for (int i = 0; i < w - 8 + 1;i++) {
        for (int j = 0; j < h - 8 + 1; j++) {
            check_chess_map(i,j);
        }
    }
    cout << min_result << endl;
}