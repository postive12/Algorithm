#include <iostream>
#include <iterator>
using namespace std;
double input[1001] = {0};
int main(){
    int cycle = 0;
    cin >> cycle;
    double sum = 0;
    double max = 0;
    for (int i = 0; i < cycle; i++) {
        cin >> input[i];
        if (max < input[i]) {
            max = input[i];
        }
    }
    for (int i = 0; i < cycle; i++) {
        input[i] = input[i] / max * 100;
        if(input[i] > 100) input[i] = 100;
        sum += input[i];
    }
    cout << sum / cycle << endl;
}