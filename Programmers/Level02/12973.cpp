//Solved
#include <bits/stdc++.h>
using namespace std;

stack<char> cache;
int solution(string s)
{
    int answer = -1;
    for(int i = 0;i < s.size();i++){
        char current_char = -1;
        cache.push(s[i]);
        while(!cache.empty() || current_char != -1){
            if (current_char == -1) {
                current_char = cache.top();
                cache.pop();
                continue;
            }
            if (!cache.empty()&&current_char == cache.top()) {
                cache.pop();
                current_char = -1;
                continue;
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