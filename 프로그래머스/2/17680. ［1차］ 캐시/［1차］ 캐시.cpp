#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void Erase(unordered_map<string,int>& map)
{
    int min = 100001;
    string city{};
    for(auto m : map)
    {
        if(m.second < min){
            min = m.second;
            city = m.first;
        }            
    }
    map.erase(city);
}
string small(string city)
{
    string ans{};
    for(auto c : city)
    {
        if(c>='A' && c <= 'Z')
            c = (c-'A') + 'a';
        ans+=c;
    }
    return ans;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0){
        answer = cities.size()*5;
        return answer;
    }
    unordered_map<string,int> mp;
    int LRU = 0;
    for(auto city : cities)
    {
        string smallCity = small(city);
        if(mp.find(smallCity)!=mp.end()) //hash에 존재
        {
            mp[smallCity] = LRU;
            answer++;
        }            
        else                        //hash에 없음
        {
            if(mp.size()==cacheSize) //full
            {
                //가장 작은 것을 찾아서 없앤 후 추가
                Erase(mp);
                mp[smallCity] = LRU;
            }
            else //공간 있음
            {
                mp[smallCity] = LRU;                
            }
            
            answer+=5;
        }
        LRU++;
    }
    return answer;
}
//