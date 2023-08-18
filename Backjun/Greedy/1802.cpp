#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool solution()
{
    string input;
    cin >> input;
    int oneCount = 0;
    int zeroCount = 0;
    for (int i = 0;i < input.size();i++) {
        char character = input.at(i);
        if (character == '0') {
            zeroCount++;
        }
        else if (character == '1') {
            oneCount++;
        }
        if (zeroCount==1&&oneCount==2) {
            oneCount-=2;
        }
        if (zeroCount==2&&oneCount==1) {
            zeroCount-=2;
        }
    }
    cout << zeroCount << "/"<< oneCount << endl;
    return (zeroCount+oneCount==1);
}
int main()
{
    ios::sync_with_stdio(false);
    int cycle;
    cin >> cycle;
    vector<bool> result;
    for (int i = 0;i < cycle;i++) {
        result.push_back(solution());
    }
    for (int i = 0; i < result.size();i++) {
        if (result.at(i)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}