#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void printDFS(const vector<vector<int>>& nums,int curr)
{
    vector<int> visited(nums.size(),0);
    stack<int> s;
    
    s.push(curr);
    
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        
        if(visited[curr]==1)
            continue;
        
        visited[curr]=1;
        cout << curr << " ";
        
        for(int i=nums[curr].size()-1;i>=0;i--)
        {
            int next = nums[curr][i];
            if(!visited[next])
            {
                s.push(next);
            }
        }
    }
    cout <<endl;
}
void printBFS(const vector<vector<int>>& nums,int curr)
{
    vector<int> visited(nums.size(),0);
    queue<int> q;
    
    q.push(curr);
    visited[curr] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        
        for(auto next : nums[curr])
        {
            if(!visited[next])
            {
                visited[next]=1;
                q.push(next);
            }
        }
    }
    cout << endl;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,v;
    cin >> n >> m >> v;
    vector<vector<int>> nums(n+1);
    int begin, end;
    for(int i=0;i<m;i++)
    {
        cin >> begin >> end;
        nums[begin].push_back(end);
        nums[end].push_back(begin);
    }
     for (int i = 1; i <= n; ++i)
        sort(nums[i].begin(), nums[i].end());
    
    printDFS(nums,v);
    printBFS(nums,v);
    return 0;
}