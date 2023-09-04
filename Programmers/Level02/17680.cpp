#include <bits/stdc++.h>
using namespace std;

vector<string> cache;
vector<int> reference_count;
int program_time = 0;
int cache_size = 0;
string to_upper(string s){
    for(int i = 0;i < s.size();i++){
        s[i] = toupper(s[i]);
    }
    return s;
}
int is_exist(string city){
    city = to_upper(city);
    for(int i = 0;i < cache_size;i++){
        if(city.compare(cache[i]) == 0){
            reference_count[i] = program_time;
            return i;
        }
    }
    return -1;
}
int insert_cache(string city){
    city = to_upper(city);
    if(cache_size == 0){
        return -1;
    }
    int oldest = 0;
    for(int i = 0;i < cache_size;i++){
        if(program_time - reference_count[oldest] < program_time - reference_count[i]){
            oldest = i;
        }
    }
    reference_count.erase(reference_count.begin() + oldest);
    reference_count.push_back(program_time);
    cache.erase(cache.begin() + oldest);
    cache.push_back(city);
    return cache_size -1;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    cache_size = cacheSize;
    cache = vector<string>(cacheSize,"");
    reference_count = vector<int>(cacheSize,0);
    for(int i = 0;i < cities.size();i++){
        program_time++;
        int query_result = is_exist(cities[i]);
        if(query_result != -1){
            answer++;
            reference_count[query_result]++;
        }
        else{
            answer += 5;
            int cached_pos = insert_cache(cities[i]);
            if(cached_pos != -1) reference_count[cached_pos]++;
        }
    }
    return answer;
}