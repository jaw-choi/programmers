#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
    int n;
    int ans = 0;
    string str;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        unordered_map<char,int> mp;
        for(int j=0;j<str.length();j++)
        {
            if(mp.find(str[j])!=mp.end()){
                if(str[j]!=str[j-1])
                    break;
            }                
            mp[str[j]]++;
            if(j==str.length()-1)
                ans++;
        }
    }
    cout << ans;
    return 0;
}