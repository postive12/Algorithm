#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long cycle,length;
    cin >> cycle >> length;
    long lastEnd = 0;
    long remainPanel = 0;
    long count = 0;
    priority_queue<pair<long, long>,vector<pair<long, long>>,greater<pair<long, long>>> pools;
    for (long i = 0;i < cycle;i++) {
        long start,end;
        cin >> start >> end;
        pair<long, long> pool;
        pool.first = start;
        pool.second = end;
        pools.push(pool);
    }
    while (!pools.empty()) {
        pair<long, long> pool = pools.top();
        pools.pop();
        long start = pool.first,end=pool.second;
        long gap = end - start;
        long panel = 0;
        //패널이 남아 있을 경우 처리
        if (remainPanel > 0) {
            if (start - lastEnd < remainPanel) {
                panel += (remainPanel + lastEnd - start);
            }
        }
        //cout << gap << endl;
        //패널이 남아있지 않을 경우 처리
        
        while (panel < gap) {
            //cout << "put panel" <<endl;
            panel += length;
            count++;
        }
        //cout << panel << "/" << gap << endl;
        panel -= gap;
        //자투리 패널과 남은 패널 계산
        remainPanel = panel;
        lastEnd = end;
        //cout << remainPanel << endl;
    }
    cout << count << endl;
    return 0;
}