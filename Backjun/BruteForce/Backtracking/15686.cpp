//solved - backtraking brute force
#include <iostream>
#include <vector>
#define MAX 50000
using namespace std;
vector<pair<short, short>> house_pair;
vector<pair<short, short>> chicken_pair;
bool is_chicken_house_alive[13];
//모든 치킨집에 대해 각각의 집의 치킨 도로 길이를 구함
//해당 거리에서 가장 가까운 순서대로 큐에 정리
//가장 가까운 집이 많은 순서대로 
int min_road = MAX;
int n,m;
int check_road(){
    int chicken_city_road = 0;
    for (int i = 0; i < house_pair.size() ; i++) {
        int current_road_min = MAX;
        for (int j = 0; j < chicken_pair.size(); j++) {
            if (!is_chicken_house_alive[j]) continue;
            int road = abs(house_pair[i].first - chicken_pair[j].first) + abs(house_pair[i].second - chicken_pair[j].second);
            current_road_min = min(current_road_min,road);
        }
        chicken_city_road+=current_road_min;
    }
    return chicken_city_road;
}
void backtracking(int pos,int count){
    if (count == m) {
        min_road = min(check_road(),min_road);
    }
    else {
        for (int i = pos; i < chicken_pair.size(); i++) {
            if (is_chicken_house_alive[i]) continue;
            is_chicken_house_alive[i] = true;
            backtracking(i, count + 1);
            is_chicken_house_alive[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pair<short,short> pos(i,j);
            int num;
            cin >> num;
            if (num == 1) house_pair.push_back(pos);
            if (num == 2) chicken_pair.push_back(pos);
        }
    }
    //init array
    fill_n(is_chicken_house_alive,13,false);
    backtracking(0,0);
    cout << min_road << endl;
    return 0;
}