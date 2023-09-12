/*https://school.programmers.co.kr/learn/courses/30/lessons/178870*/
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;


vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,0};
    if (sequence[0] == k) {
        return answer;
    }
    //필요 변수
    vector<pair<int,pair<int,int>>> results;
    queue<int> selected_element;
    int result_sum = sequence[0];
    selected_element.push(sequence[0]);

    
    int left = 0;
    int right = 0;
    for (int i = 1; i < sequence.size(); i++) {
        result_sum += sequence[i];
        selected_element.push(sequence[i]);
        right++;
        while (result_sum > k) {
            int cur_first = selected_element.front();
            selected_element.pop();
            result_sum -= cur_first;
            left++;
        }
        while (!selected_element.empty()&&selected_element.front() == 0) {
            selected_element.pop();
            left++;
        }
        if (result_sum == k) {
            results.push_back({(right - left),{left,right}});
        }
    }
    int min = 0;
    for (int i = 0;i < results.size();i++) {
        if (results[min].first > results[i].first) {
            min = i;
            continue;
        }
        if (results[min].first == results[i].first){
            if (results[min].second.first > results[i].second.first) {
                min = i;
                continue;
            }
        }

    }
    answer[0] = results[min].second.first;
    answer[1] = results[min].second.second;
    return answer;
}