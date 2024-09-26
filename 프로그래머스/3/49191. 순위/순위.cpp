#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> rank(n+1,vector<bool>(n+1,false));

    for(int i=0;i<results.size();i++)
    {
        rank[results[i][0]][results[i][1]] = true;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(rank[j][i] == true && rank[i][k] == true)
                    rank[j][k] = true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int tmp = 0;
        for(int j=1;j<=n;j++)
        {
            if(rank[i][j])
                tmp++;
            if(rank[j][i])
                tmp++;
        }
        if(tmp == n-1)
            answer++;
    }
    return answer;
    
}
//승,패 n-1만큼 받은놈 확정
//2등을 이기면 1등 확정
//꼴등앞에한테 지면 꼴등 확정
//4 1
//3 2
//2 3
//1 4
//0 5

/*
int solution(int n, vector<vector<int>> results) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    int answer = 0;
    unordered_map<int,pair<int,int>> mp;//이름,횟수,승점
    unordered_map<int,int> rank;
    int second = -1;
    int beyondLast = -1;
    for(auto r :results)
    {
        if(mp.find(r[0])==mp.end())
        {
            mp[r[0]] = make_pair(1,1);
        }
        else if(mp.find(r[0])!=mp.end())
        {
            mp[r[0]].first++;
            mp[r[0]].second++;
        }
        
        if(mp.find(r[1])==mp.end())
        {
            mp[r[1]] = make_pair(1,0);
        }
        else if(mp.find(r[1])!=mp.end())
        {
            mp[r[1]].first++;
        }
    }
    for(auto m : mp)
    {
        if(m.second.first == n - 1)
        {
            rank[m.first] = n - m.second.second;
            if(n - m.second.second == 2)//2등
                second = m.first;
            else if(n - m.second.second == n-1)//꼴등 앞
                beyondLast = m.first;
        }
        cout << m.first << " [" << m.second.first << "," << m.second.second << "]" <<endl;
    }
    
    for(auto r : results)
    {
        if(r[1] == second)
            rank[r[0]] = 1;
        else if(r[0] == beyondLast)
            rank[r[1]] = n;
    }
    for(auto r : rank)
        cout << r.first <<" " << r.second<<endl;
    return rank.size();
}
*/