#include <string>
#include <vector>
#include <iostream>

using namespace std;

string str(int num,int n)
{
    string ans = "";
    while(num!=0)
    {
        if(num%2==1)
            ans="1"+ans;
        else
            ans="0"+ans;
        num/=2;
    }
    while(ans.length()!=n)
        ans = "0" + ans;
    return ans;
}

string print(string a, string b,int n)
{
    string ans = "";
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0' && b[i]=='0')
            ans += " ";
        else if(a[i]=='1' || b[i]=='1')
            ans+= "#";
    }
    return ans;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++)
    {
        answer.push_back(print(str(arr1[i],n),str(arr2[i],n),n));  
    }
    return answer;
}