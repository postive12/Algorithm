//N진수 게임 17687
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    구현 순서
    1. 숫자를 진법 문자열로 변환하는 함수 구현
    2. 구해진 진법 문자열이 고갈될 때까지 반복문을 돌린다
        2.1. 반복문을 돌리면서 턴을 판별하고 자신의 턴일 때 문자를 이어붙인다
        2.2. 요청 길이에 도달하면 return한다

    진법 변환 하는 방법
    예를 들어 5를 2진법으로 변환하기 아래의 과정을 따른다
    1. 5 => "5/2" + "5%2" => 21
    위 과정을 따라 만들어진 숫자 중 앞의 숫자를 다시 1번 설명과 같이 진법의 숫자로 나누고 나머지를 구해 붙여준다
    2. 2 => "2/2" + "2%2" => 10
    즉 1번에서 만들어진 "21"에서 2는 10으로 치환된다 => 101
    이를 재귀함수로 구현하면 아래 create_num 함수와 같다
*/
//16진법 숫자들
char nums[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//진법으로 숫자를 바꿔주는 재귀 함수
string create_num(int n,int num){
    //만약 내가 이번에 받은 값이 n보다 작다면 배열에서 문자를 찾아 문자열로 변환한 수 리턴한다.
    if(num < n) return string(1,nums[num]);
    //아니라면 앞숫자와 뒷숫자를 구해 붙여주고 이를 리턴한다
    return create_num(n,num/n) + string(1,nums[num%n]);
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int current_num = 0;
    int current_turn = 1;
    while(answer.size() < t){
        string numstr = create_num(n,current_num);
        for(int i = 0;i < numstr.size();i++){
            if(current_turn == p) answer.append(1,numstr[i]);
            if(answer.size() == t) return answer;
            current_turn%=m;
            current_turn++;
        }
        current_num++;
    }
    return answer;
}