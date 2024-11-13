#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> window = queue1;
    int n = queue1.size();
    long long sum = 0;
    long long target = 0;
    int cnt = 0;
    for(auto q : queue1){
        sum+=q;
        target +=q;
    }
    for(auto q : queue2){
        target += q;
    }
    target/=2;
    window.insert(window.end(), queue2.begin(), queue2.end());
    window.insert(window.end(), queue1.begin(), queue1.end());
    int left = 0;
    int right = n;
    while(left<=right && right < window.size())
    {
        if(sum > target){
            sum = sum - window[left];
            left++;
        }
        else if(sum < target){
            sum = sum + window[right];
            right++;
        }
        else{
            return cnt;
        }
        cnt++;
    }
    return -1;
}
//