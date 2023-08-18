#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<>> list_mileage;
int subject,mileage;
vector<int> numbers;
void quick_sort(int start,int end)
{
    if (start >= end) {
        return;
    }
    int pivot = numbers[start];
    int left = start;
    int right = end + 1;
    do{
        do{
            left++;
        }while(numbers[left] > pivot && left <= end);
        do{
            right--;
        }while(numbers[right] < pivot && right >= start);
        if (left < right) {
            int tmp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = tmp;
        }
    }while(left<right);
    int tmp = numbers[start];
    numbers[start] = numbers[right];
    numbers[right] = tmp;

    quick_sort(start,right-1);
    quick_sort(right+1, end);
}
void solution()
{
    int n,m;
    cin >> n >> m;
    numbers.clear();
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    quick_sort(0,n-1);
    list_mileage.push(n < m ? 0 :numbers[m-1]);
}
int main()
{
    cin >> subject >> mileage;
    for (int i = 0;i < subject;i++) {
        solution();
    }
    int count = 0;
    while (!list_mileage.empty()) {
        int num = list_mileage.top();
        list_mileage.pop();
        mileage -= num <= 36 ? num : 36;
        mileage -= num == 0 ? 1 : 0;
        if (mileage >= 0) {
            //cout << mileage << "/";
            count++;
        }
        else{
            break;
        }
    }
    cout << count << endl;
    return 0;
}