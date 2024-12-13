#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> mp;
    for(int i=0;i<9;i++)
        mp[discount[i]]++;
    for(int i=9;i<discount.size();i++)
    {
        mp[discount[i]]++;
        bool flag = true;
        for(int j=0;j<want.size();j++){
            if(mp[want[j]]!=number[j]){
                flag=false;
                break;
            }
        }
        if(flag==true)
            answer++;
        mp[discount[i-9]]--;
    }
    return answer;
}