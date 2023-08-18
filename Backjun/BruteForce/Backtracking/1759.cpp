//2023-08-16 조합론 암호만들기
//Solved
#include <iostream>
#include <queue>
using namespace std;
//모음 모음
char vowel[5]={
    'a',
    'e',
    'i',
    'u',
    'o'
};
//입력 값
int l,c;
//입력받은 문자들
vector<char> characters;
//결과
vector<char> result_characters;
//방문여부 표시
vector<bool> is_selected;
//결과값 저장용 우선순위 큐
priority_queue<string,vector<string>,greater<string>> result_queue;
bool is_vowel(char input){
    for (int i = 0;i < 5; i++) {
        if (vowel[i] == input) {
            return true;
        }
    }
    return false;
}
//백트래킹
void create_password(int start,int length,int vowel,int consonant){
    //조건 합치 판별
    if (l - consonant < 1|| l - vowel < 2) {
        return;
    }
    //길이에 도달하면 문자열 생성 후 큐에 기입
    if(length == l) {
        char charset[l];
        for (int i = 0;i < l; i++) {
            charset[i] = result_characters[i];
        }
        result_queue.push(charset);
        return;
    }
    for (int i = 0;i < c;i++) {
        if(is_selected[i]) continue;
        if(length - 1 >= 0) if(result_characters[length - 1] > characters[i]) continue;
        bool is_v = is_vowel(characters[i]);
        is_selected[i] = true;
        result_characters[length] = characters[i];
        create_password(i,length + 1,is_v ? vowel + 1 : vowel,is_v ? consonant : consonant + 1);
        is_selected[i] = false;
    }
}
int main()
{
    cin >> l >> c;
    is_selected = vector<bool>(l,false);
    result_characters = vector<char>(l,0);
    for (int i = 0;i < c;i++) {
        char ch;
        cin >> ch;
        characters.push_back(ch);
    }
    //비밀번호 생성
    create_password(0, 0, 0, 0);
    //우선순위 큐에서 값 출력 
    while (!result_queue.empty()) {
        cout << result_queue.top() << "\n";
        result_queue.pop();
    }
    return 0;
}