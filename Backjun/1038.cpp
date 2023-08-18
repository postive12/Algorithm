#include <iostream>
#include <queue>
#define MAX_COUNT 100001
using namespace std;
long long cache[MAX_COUNT] = {0};
int main() {
    int num = 0;
    cin >> num;
    if (num <= 10) {
        cout << num;
        return 0;
    }
    int count = 10;
    queue<long long> numbers;  
    for (int i = 1; i <= 9; i++) {
        numbers.push(i);
        cache[i] = i;
    }
    while (count <= num && numbers.empty() == false) {
        long long number = numbers.front();
        numbers.pop();
        long lastNumber = number % 10;
        for (int i = 0; i < lastNumber; i++) {
            numbers.push(number * 10 + i);
            cache[count++] = number * 10 + i;
        }
    }
    if (count >= num && cache[num] != 0) cout << cache[num];
    else cout << -1 << endl;
    return 0;
}