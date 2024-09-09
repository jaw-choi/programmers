#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    unordered_map<int,int> mp;
    vector<int> v;
    
    for(auto s : operations)
    {
        string order;
        int num;
        stringstream ss(s);
        ss >> order >> num;
        if(order =="I")
        {
            v.push_back(num);
            mp[num]++;
        }
        else if(order=="D")
        {
            if(v.size()!=0)
            {
                if(num==-1)
                {
                    sort(v.begin(),v.end());
                    v.erase(v.begin());
                }
                else
                {
                    sort(v.rbegin(),v.rend());
                    v.erase(v.begin());
                }
            }
            
        }
        
    }
    if(v.size()==0)
        return answer;
    else
    {
        sort(v.begin(),v.end());
        return {v[v.size()-1],v[0]};
    }
}