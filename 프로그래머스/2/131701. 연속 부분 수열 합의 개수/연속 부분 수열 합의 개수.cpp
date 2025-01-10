#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int sum(int start,int end, const vector<int>& elements)
{
    int ans = 0;
    if(start<=end){
        for(int i=start;i<=end;i++){
            ans+=elements[i];
        }
    }
    else
    {
        for(int i=start;i<elements.size();i++){
            ans+=elements[i];
        }
        for(int i=0;i<=end;i++){
            ans+=elements[i];
        }
    }
    return ans;
}
void helper(int num,const vector<int>& elements, set<int>& per)
{
    int start = 0;
    int end = num;
    while(start<elements.size())
    {
        per.insert(sum(start,end,elements));
        start++;
        end++;
        if(end==elements.size())
            end=0;
    }
}
int solution(vector<int> elements) {
    int answer = 0;
    set<int> ans;
    for(int i=0;i<elements.size();i++)
    {
        set<int> per;
        helper(i,elements,per);
        for(auto s : per)
            ans.insert(s);
    }

    return ans.size();
}