//2023-08-17 하노이 탑
//Solved
#include <iostream>
#include <vector>
using namespace std;
//이동 처리
void move_a2b(short a,short b){
    cout << a << " " << b << "\n";
}
//하노이 타워 이동 처리
void hanoi_tower(short from,short to,short count){
    if(count == 0) return;
    hanoi_tower(from, 3 - (from + to ) % 3,count-1);
    move_a2b(from,to);
    hanoi_tower(3 - (from + to ) % 3,to,count - 1);

}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    //이동 횟수 계산
    //크기가 매우 커서 long 형에 담을 수 없음
    vector<long> results;
    results.push_back(0);
    for (int i = 0; i < n; i++) {
        //값 연산
        for (int j = 0; j < results.size();j++) {
            results[j] *= 2;
            if (j == 0) {
                results[j] +=1;
            }
        }
        //10의 자리수가 넘어가면 10의 자리를 다음 자리로 더해줌
        for (int j = 0; j < results.size();j++) {
            int next = results[j] / 10;
            results[j] %= 10;
            if (next <= 0) continue;
            if (results.size() <= j + 1) {
                results.push_back(next);
            }
            else {
                results[j+1] += next;
            }
        }
    }
    //비용 출력
    for (int i = results.size() - 1; i >= 0 ;i--) {
        cout << results[i];
    }
    cout << "\n";
    if(n > 20){
        return 0;
    }
    //하노이 타워 출력
    hanoi_tower(1, 3,n);
    return 0;
}