//Solved
//b aa b aa 문제 문제 이름 찾아야함
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> cache;
int solution(string s)
{
    int answer = -1;
    cout << s.size() << endl;
    for(int i = 0;i < s.size();i++){
        int same_count = 0;
        char current_char = -1;
        cache.push(s[i]);
        cout << cache.size() << endl;
        while(!cache.empty()){
            if (current_char == -1) {
                current_char = cache.top();
                cache.pop();
            }
            cout << current_char << endl;
            if (current_char == cache.top()) {
                cache.pop();
                if (!cache.empty()) {
                    current_char = cache.top();
                    cache.pop();
                }
            }
            else {
                cache.push(current_char);
                break;
            }
        }
    }
    answer = cache.size() == 0 ? 1 : 0;
    return answer;
}