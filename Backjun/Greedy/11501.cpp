#include <iostream>
#include <stack>
#include <vector>
using namespace std;
long solution()
{
    long result = 0;
    long n;
    cin >> n;
    stack<long> stocks;
    for (long i = 0;i < n;i++) {
        long num;
        cin >> num;
        stocks.push(num);
    }
    long curMax = stocks.top();
    stocks.pop();
    while (!stocks.empty()) {
        long curPrice = stocks.top();
        stocks.pop();
        if (curPrice < curMax) {
            result += (curMax - curPrice);
            //cout << "add price : " << (curMax - curPrice) << endl;
        }
        else {
            curMax = curPrice;
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    long cycle = 0;
    cin >> cycle;
    vector<long> results;
    for (long i = 0;i < cycle;i++) {
        results.push_back(solution());
    }
    for (long result : results) {
        cout << result << "\n";
    }
    return 0;
}