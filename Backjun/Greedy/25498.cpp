#include <iostream>
#include "vector"
using namespace std;
class Vertex{
public:
    char data;
    bool isVisited;
    vector<int> child;
};
vector<vector<char>> handles;

void dfs(vector<char> characters, vector<Vertex> graph,Vertex startVertex)
{
    if (startVertex.isVisited){
        return;
    }
    characters.push_back(startVertex.data);
    startVertex.isVisited = true;
    for (int i = 0; i < startVertex.child.size(); ++i) {
        dfs(characters,graph,graph[startVertex.child[i]]);
    }
    if (startVertex.child.size() == 0){
        handles.push_back(characters);
    }
}
int main() {
    int cycle = 0;
    cin >> cycle;
    string characterSet;
    cin >> characterSet;
    vector<Vertex> vertexes;
    for (int i = 0; i < cycle; ++i) {
        Vertex s;
        s.data = characterSet[i];
        s.isVisited = false;
        vertexes.push_back(s);
    }
    for (int i = 1; i < cycle; ++i) {
        int x,y;
        int temp;
        cin >> x >> y;
        if (x > y){
            temp = x;
            x = y;
            y = temp;
        }
        vertexes[x-1].child.push_back(y-1);
    }
    vector<char> characters;

    dfs(characters,vertexes,vertexes[0]);
    int max_size = 0;
    vector<vector<char>> targetHandles;

    for (int i = 0; i < handles.size(); ++i) {
        if (max_size < handles[i].size()) max_size = handles[i].size();
    }
    for (int i = 0; i < handles.size(); ++i) {
        if (handles[i].size() >= max_size) targetHandles.push_back(handles[i]);
    }
    int currentSize = 0;
    int selectedHandle = 0;
    vector<int> targetHandles2;
    for (int i = 0; i < targetHandles.size(); ++i) {
        targetHandles2.push_back(i);
    }
    vector<int> targetHandles4;
    while (currentSize < max_size){
        vector<int> targetHandles3;
        targetHandles3 = targetHandles2;
        targetHandles2.clear();
        char max_dic = 0;
        for (int i = 0; i < targetHandles3.size(); ++i) {
            if (max_dic < targetHandles[targetHandles3[i]][currentSize]) max_dic = targetHandles[targetHandles3[i]][currentSize];
        }

        for (int i = 0; i < targetHandles3.size(); ++i) {
            if (max_dic <= targetHandles[targetHandles3[i]][currentSize]) targetHandles2.push_back(targetHandles3[i]);
        }
        currentSize++;
        targetHandles4 = targetHandles2;
    }
    for (int j = 0; j < targetHandles[targetHandles4[0]].size(); ++j) {
        cout << targetHandles[targetHandles4[0]][j];
    }
    return 0;
}