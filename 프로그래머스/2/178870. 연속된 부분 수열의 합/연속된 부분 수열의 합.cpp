#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left = 0;
    int right = 0;
    int curr = sequence[left];
    int min = 1000001;
    while(left <=right && right < sequence.size())
    {
        if(curr < k){
            right++;
            curr+=sequence[right];
        }
        else if(curr > k){
            curr-=sequence[left];
            left++;
        }
        else{            

                if(right - left < min){
                    answer = {left,right};
                    min = right - left;
                }                
                curr -= sequence[left];
                left++;
            
        }
    }

    return answer;
}