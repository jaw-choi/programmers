#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    if(a.size()<=2)
        return a.size();
    int answer = 2;
    vector<int> left(a.size(),0);
    vector<int> right(a.size(),0);
    int min = a[0];
    for(int i=0;i<a.size();i++)
    {
        if(a[i] > min){
            left[i] = min;
        }
        else{
            min = a[i];
            left[i] = min;
        }
    }
    min = a[a.size()-1];
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i] > min){
            right[i] = min;
        }
        else{
            min = a[i];
            right[i] = min;
        }
    }

    for(int i=1;i<a.size()-1;i++)
    {
        if(left[i-1] < a[i] && right[i+1] < a[i])
            continue;
        else
            answer++;
    }
    return answer;
}

