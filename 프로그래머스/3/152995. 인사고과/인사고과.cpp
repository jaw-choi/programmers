#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = scores.size() + 1;
    int wanho = scores[0][0] + scores[0][1];    
    
    sort(scores.begin()+1, scores.end());
    
    for (int i=1;i<scores.size();i++)
    {  
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) 
            return -1;
        
        if(wanho >= scores[i][0] + scores[i][1])
            continue;
        
        for(int j=i+1;j<scores.size();j++)
        {
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
            {
                answer--;
                break;
            }
        } 
    }
    
    for(auto c : scores)
        if (wanho >= c[0] + c[1])
            answer--;
    
    return answer;
}