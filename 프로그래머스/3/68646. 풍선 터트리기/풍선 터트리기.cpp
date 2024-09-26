#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> left(a.size(),0);
    vector<int> right(a.size(),0);
    int lmin = a[0];
    for(int i=0;i<a.size();i++)
    {
        if(lmin > a[i])
            lmin = a[i];
        left[i] = lmin;
    }
    int rmin = a[a.size()-1];
    for(int i=a.size()-1;i>=0;i--)
    {
        if(rmin > a[i])
            rmin = a[i];
        right[i] = rmin;
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i] <= left[i] || a[i] <= right[i])
            answer++;
    }
    return answer;
}
//-16,-16,-16,-16,-16,-92,-92,-92,-92,-92
//-92,-92-,92-,92,-92,-92,-71,-68,-61,-33