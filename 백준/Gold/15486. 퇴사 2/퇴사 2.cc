#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> day(n);
    vector<int> pay(n);
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin >> day[i] >> pay[i];
    }
    
    for(int i=0;i<n;i++)
    {
        ans[i+1] = max(ans[i+1],ans[i]);
        int endDay = i + day[i];
        if(endDay<=n){
            ans[endDay] = max(ans[endDay],ans[i] + pay[i]);
        }
    }

    cout << ans[n];
    return 0;
}