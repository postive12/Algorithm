#include <iostream>
#include <vector>
using namespace std;
vector<int> numbers;
void quick_sort(int start,int end){
    if (start >= end) {
        return;
    }
    int pivot = numbers[start];
    int left = start;
    int right = end + 1;
    do{
        do{
            left++;
        }while (numbers[left] < pivot && left <= end);
        do{
            right--;
        }while(numbers[right] > pivot && right >= start);
        if (left < right) {
            int tmp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = tmp;
        }
    }while(left < right);
    int tmp = numbers[start];
    numbers[start] = numbers[right];
    numbers[right] = tmp;
    quick_sort(start,right-1);
    quick_sort(right+1, end);
}
int main()
{
    ios::sync_with_stdio(false);
    int cycle = 0;
    cin >> cycle;
    cycle *= 2;
    for (int i = 0;i < cycle;i++) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    quick_sort(0,cycle-1);
    int min = 1e9;
    for (int i = 0;i < cycle/2;i++) {
        int sum = numbers[i] + numbers[cycle-i-1];
        if (min > sum) {
            min = sum;
        } 
    }
    cout << min << endl;
    return 0;
}