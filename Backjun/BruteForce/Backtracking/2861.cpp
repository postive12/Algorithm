//Solved
#include <iostream>
using namespace std;
int length = 0;
int result_cashes[80] = {0};
bool is_same_arr(int a[],int b[],int len)
{
    for (int i = 0;i < len; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
bool is_available(int a[80],int pos,int len)
{
    if ((pos + 1) - (len * 2) < 0) {
        return true;
    }
    int second[len];
    int first[len];
    for (int i = 0; i < len; i++) {
        second[len - 1 - i] = a[pos - i];
        first[len - 1 - i] = a[pos - i - len];
    }
    return !is_same_arr(first,second,len);
}
bool is_all_available(int a[80],int pos)
{
    int max_length = (pos + 1) / 2;
    for (int i = 2; i <=  max_length; i++) {
        if (!is_available(result_cashes,pos,i)) {
            return false;
        }
    }
    return true;
}
//수가 들어왔을 때 해당 수 앞의 2,3자리 까지의 숫자를 판단한다 이후 해당 자리 부터 2,3,만큼의 숫자를 확인한다
void backtracking(int cur,int cur_len){
    if (cur_len == length) {
        for (int i = 0;i < length;i++) {
            cout << result_cashes[i];
        }
        cout << endl;
        exit(0);
        return;
    }
    else{
        for (int i = 1; i <= 3;i++) {
            if (cur == i) continue;
            result_cashes[cur_len] = i;
            if (is_all_available(result_cashes,cur_len)) {
                backtracking(i, cur_len + 1);
            }
            result_cashes[cur_len] = 0;
        }
    }

}
int main()
{
    cin >> length;
    result_cashes[0] = 1;
    backtracking(1,1);
    return 0;
}