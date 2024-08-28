#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);
    unordered_map<string,int> mp1;
    for(auto g:gems)
        mp1[g]++;
    unordered_map<string,int> mp;
    
    int size_ = mp1.size();
    int left = 0;
    int right = 0;
    int len = 100001;
    int i = 0;
    while(right < gems.size())
    {
        for(i=right;i<gems.size();i++)
        {
            mp[gems[i]]++;
            if(mp.size()==size_)
            {
                right = i;
                break;
            }
        }
        if(i==gems.size())
            break;
        
        for(i=left;i<gems.size();i++)
        {
                if(mp[gems[i]]==1){
                    left=i;
                    break;
                }
            else
                mp[gems[i]]--;
        }
        if( len > right - left){
            len = right - left;
            answer[0]=left+1;
            answer[1]=right+1;
        }
        mp.erase(gems[left]);
        left++;
        right++;
    }
    return answer;
}