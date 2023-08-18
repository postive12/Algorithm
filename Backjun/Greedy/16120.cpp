#include <iostream>
#include <string>
using namespace std;
int main(){
    string input;
    cin >> input;
    int p_count = 0;
    bool is_front_a = false;
    for (int i = 0; i < input.size(); i++) {
        char current_char = input.at(i);
        if (current_char == 'P') {
            if (p_count >= 2 && is_front_a) {
                p_count -= 2;
            }
            //p 갯수 증가
            p_count++;

            //a 확인 변수를 false로 설정
            is_front_a = false;
        }
        if (current_char == 'A') {
            //만약 앞에 P가 두개 보다 작으면 NP
            if (p_count < 2) {
                cout << "NP" << endl;
                return 0;
            }
            //만약 앞에 A가 하나 더 있었다면 NP
            if(is_front_a){
                cout << "NP" << endl;
                return 0;
            }
            //만약 자기 자신이 맨 마지막 이라면 NP
            if (i+1 == input.size()) {
                cout << "NP" << endl;
                return 0;
            }
            is_front_a = true;
        }
    }
    cout << (p_count == 1 ?  "PPAP": "NP") <<endl;
}