//finish
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int r,c;
void print_vector(vector<string> target){
    cout << "============================" << endl;
    for (int i = 0; i < target.size();i++) {
        cout << target[i] << endl;
    }
    cout << "============================" << endl;
}
bool find_path(vector<string> &target,int x,int y){
    if (y < 0) {
        return false;
    }
    if (y > r - 1) {
        return false;
    }
    if (target[y][x] == 'x') {
        return false;
    }
    target[y][x] = 'x';
    if (x == c - 1) {
        return true;
    }
    if (find_path(target, x + 1, y - 1)) {
        //make path true
        return true;
    }
    if (find_path(target, x + 1, y)) {
        return true;
    }
    if (find_path(target, x + 1, y + 1)) {
        return true;
    }
    return false;
}
int main(){
    cin >> r >> c;
    vector<string> map;
    for (int i = 0; i < r;i++) {
        string str;
        cin >> str;
        map.push_back(str);
    }
    //print_vector(map);
    int count = 0;
    for (int i = 0;i < r; i++) {
        if (find_path(map, 0,i)) {
            count++;
        }
        //print_vector(map);
    }
    cout << count << endl;
    return 0;
}
