#include <iostream>
#include <ostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1e9
using namespace std;

struct Link{
public:
    short end;
    short distance;
};

struct compare{
    bool operator()(Link &a, Link &b){
        return a.distance > b.distance;
    }
};

vector<priority_queue<Link,vector<Link>,compare>> link_vector;
int main()
{
    int num = 0;
    int line_num = 0;
    int s_vertex = 0;
    cin >> num >> line_num;
    cin >> s_vertex;
    vector<int> min_distance(num+1,MAX);
    for (int i = 0; i <= num; ++i) {
        priority_queue<Link,vector<Link>,compare> v;
        link_vector.push_back(v);
    }
    
    for (int i = 0; i < line_num; ++i) {
        short a,b,c;
        cin >> a >> b >> c;
        Link l;
        l.end = b;
        l.distance = c;
        link_vector[a].push(l);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visit_queue;
    visit_queue.push({0,s_vertex});
    min_distance[s_vertex] = 0;
    //int count = 0;
    while (!visit_queue.empty())
    {
        int start_v = visit_queue.top().second;
        visit_queue.pop();
        priority_queue<Link,vector<Link>,compare> current_v = link_vector[start_v];
        while (!current_v.empty()) {
            Link l = current_v.top();
            current_v.pop();
            //count++;
            int cur_dis = l.distance + min_distance[start_v];
            if (cur_dis < min_distance[l.end]) {
                min_distance[l.end] = cur_dis;
                visit_queue.push({cur_dis,l.end});
            }   
        }
    }

    for (int i = 1; i <= num; ++i) {
        if (min_distance[i]==MAX){
            cout << "INF\n";
            continue;
        }
        cout << min_distance[i] << "\n";
    }
    //cout << "Count Result : " << count << endl;
}