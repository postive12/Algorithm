#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    string input;
    getline(cin,input);
    string keyword;
    getline(cin,keyword);
    //cout << input << endl << keyword << endl;
    int curCursor = 0;
    int count = 0;
    for (int i = 0;i < input.size();i++) {
        //cout << "===================" << endl;
        //cout << "Pos : " << i << endl << "input : " << input.at(i) << endl << "keyword : " << keyword.at(curCursor) << endl;
        if (input.at(i)==keyword.at(curCursor)) {
            curCursor++;
            if (curCursor==keyword.size()) {
                curCursor = 0;
                count++;
            }

        }
        else{
            i-=curCursor;
            curCursor = 0;
        }
    }
    cout << count << endl;
    return 0;
}