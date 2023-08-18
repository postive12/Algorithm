#include <iostream>
#include <vector>
using namespace std;
vector<int> numbers;
//출력
void print_numbers(){
    for (int i = 0;i < numbers.size();i++) {
        cout << numbers[i] << "\n";
    }
}
//선택 정렬
void selection_sort()
{
    for (int i = 0;i < numbers.size();i++) {
        int swapPos = i;
        for (int j = i;j < numbers.size();j++) {
            if (numbers[swapPos] > numbers[j]) {
                swapPos = j;
            }
        }
        if (swapPos == i) {
            continue;
        }
        int tmp = numbers[i];
        numbers[i] = numbers[swapPos];
        numbers[swapPos] = tmp;
    }
}
//퀵 정렬
void quick_sort(int start,int end)
{
    if (start >= end) {
        return;
    }
    //cout << start << " " << end << endl;
    int pivot = numbers[start];
    int left = start;
    int right = end+1;
    do{
        do{
            left++;
        }while (numbers[left] < pivot && left <= end);
        do{
            right--;
        }while (numbers[right] > pivot && right >= start);
        if (left < right) {
            int tmp = numbers[left];
            numbers[left] = numbers[right];
            numbers[right] = tmp;
        }
    } while (left < right);

    int tmp = numbers[start];
    numbers[start] = numbers[right];
    numbers[right] = tmp;
    quick_sort(start,right-1);
    quick_sort(right+1, end);
}
int main()
{
    ios::sync_with_stdio(false);
    int cycle;
    cin >> cycle;

    for (int i = 0;i < cycle;i++) {
        int n = 0;
        cin >> n;
        numbers.push_back(n);
    }
    quick_sort(0,cycle-1);
    print_numbers();
    return 0;
}