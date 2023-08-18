/*
https://school.programmers.co.kr/learn/courses/30/lessons/12981

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool vector_contains(vector<string> array,string target){
    for (int i = 0; i < array.size();i++ ) {
        if (array[i].compare(target) == 0) {
            return true;
        }
    }
    return false;
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    //필요 변수
    vector<string> result_array;
    //끝말잇기 첫 단어 마지막 값 가져오기
    char last_char = words[0][words[0].length() - 1];
    result_array.push_back(words[0]);
    int cur_position = 1;
    int cycle = 1;
    for (int i = 1;i < words.size(); i++) {
        //자릿수 판별
        cur_position++;
        if (cur_position % (n + 1) == 0) {
            cur_position = 1;
            cycle++;
        }
        string cur_string = words[i];
        if (cur_string[0] != last_char) {
            answer[0] = cur_position;
            answer[1] = cycle;
            return answer;
        }
        if (vector_contains(result_array, cur_string)) {
            answer[0] = cur_position;
            answer[1] = cycle;
            return answer;
        }
        result_array.push_back(cur_string);
        last_char = words[i][words[i].length()-1];
    }
    return answer;
}