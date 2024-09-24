#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int>mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]]++;
    }
    if(nums.size()/2 >= mp.size())
        return mp.size();
    else
    {
        return nums.size()/2;
    }
    return answer;
}