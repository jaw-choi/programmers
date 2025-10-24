#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



bool cmp(const string& a,const string& b)
{
    if(a.size()==b.size())
    {
        return a<b;
    }
    return a.size()<b.size();
}
bool operator<=(const string& a,const string& b)
{
    if(a==b)
        return true;
    if(a.size()==b.size())
    {
        return a<b;
    }
    return a.size()<b.size();
}

void addOneStr(string& ans)
{
    for(auto it = ans.rbegin();it!=ans.rend();it++)
    {
        if(*it=='z')
        {
            *it='a';
            if(it==ans.rend()-1)
            {
                ans = 'a'+ans;
            }
        }
        else{
            *it = *it+1;
            break;
        }
    }
}
void helper(string& ans,const vector<string>& bans)
{
    for(auto& b : bans)
    {
        if(b <= ans)
        {
            //cout << b<< " :"<<ans << endl;
            addOneStr(ans);
        }
    }
}
string solution(long long n, vector<string> bans) {
    string answer = "";
    int num = 0;
    vector<int> nums;
    sort(bans.begin(),bans.end(),cmp);
    //for(auto b : bans)
        //cout << b << endl;
    while(n!=0)
    {
        num = n%26;
        if(num==0){
            nums.push_back(26);
            n-=26;
        }
        else
            nums.push_back(num);
        n = n/26;
    }
    reverse(nums.begin(),nums.end());
    
    for(auto n : nums)
    {
        answer+= n+'a'-1;
    }

    helper(answer,bans);
    return answer;
}