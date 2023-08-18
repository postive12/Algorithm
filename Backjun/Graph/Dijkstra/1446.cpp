//아직 못품
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int e,l;
    cin >> e >> l;
    map<int,vector<pair<int,int>>> vertexes;
    for (int i = 0;i < e;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if (vertexes.find(a) != vertexes.end()) {
            vertexes[a].push_back({b,c});
        }
        else{
            vertexes[a];
        }
    } 
}
