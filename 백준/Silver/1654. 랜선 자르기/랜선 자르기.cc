#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
    long long answer = 0;
    long long k,n,num;
    vector<long long> v;
    v.reserve(k);
    cin >>k >>n;
    for(int i=0;i<k;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    long long left,right,mid;
    left = 1;
    right = v[v.size()-1];
    
    while(left<=right)
    {
        mid = (left+right)/2;
        long long tmp = 0;
        for(auto vec : v)
        {
            tmp += (vec/mid);
        }
        if(tmp>=n){
            answer = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout <<answer;
    return 0;
}