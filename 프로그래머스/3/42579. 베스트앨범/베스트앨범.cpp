#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        less<vector<int>>>> mp;
    
    map<string,int> ump;
    for(int i=0;i<genres.size();i++)
    {
        mp[genres[i]].push({plays[i],i});
        ump[genres[i]] += plays[i];
    }
    vector<pair<int,string>> v;
    for(auto m : ump)
    {
        v.push_back(make_pair(m.second,m.first));
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
    {
        auto curr = v[i].second;
        int cnt = 2;
        if(mp[curr].size()>=2)
        {
            int first = mp[curr].top()[0];
            int firstIndex = mp[curr].top()[1];
            mp[curr].pop();
            int second = mp[curr].top()[0];
            int secondIndex = mp[curr].top()[1];
            if(first==second){
                if(secondIndex < firstIndex)
                {
                    answer.push_back(secondIndex);
                    answer.push_back(firstIndex);
                }
            }
            else
            {
                    answer.push_back(firstIndex);
                    answer.push_back(secondIndex);
            }
        }
        else{
            answer.push_back(mp[curr].top()[1]);
        }
        // while(!mp[curr].empty())
        // {
        //     answer.push_back(mp[curr].top()[1]);
        //     mp[curr].pop();
        //     cnt--;
        //     if(cnt==0)
        //         break;
        // }
    }
    return answer;
}