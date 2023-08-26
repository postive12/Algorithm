//Solved
#include <bits/stdc++.h>
using namespace std;
long long pacto(int n){
    if(n == 0) return 1;
    return n * pacto(n - 1);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    for(int i = 1; i <= n;i++){
        nums.push_back(i);
    };
    for(int i = 0; i < n - 1 ;i++){
        long long current_solution_size = pacto(n - 1 - answer.size());
        long long current_pos = k / current_solution_size + (k % current_solution_size > 0 ? 1 : 0);
        k %= current_solution_size;
        k = k <= 0 ? current_solution_size:k;
        answer.push_back(nums[current_pos - 1]);
        nums.erase(nums.begin()+ current_pos - 1);
    }
    answer.push_back(nums[0]);
    return answer;
}