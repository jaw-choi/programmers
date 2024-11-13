#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> answer(n+1,vector<int>(n+1,0));
    vector<int> ans;
    int limit = (n*n+1)/2;
    int cnt = 0;
    int num = 1;
    int i=-1;
    int j=0;
    int flag = 0;
    while(n > 0)
    {
        if(flag==0){
            i++;
        }
        else if(flag==1){
            j++;
        }
        else{
            i--;
            j--;
        }
        
        answer[i][j] = num++;
        cnt++;
        
        
        if(flag==0&&cnt==n){
            n = n-1;
            flag = 1;
            cnt=0;
        }
        else if(flag == 1 && cnt == n){
            n = n-1;
            flag = 2;
            cnt=0;
        }
        else if(flag == 2 && cnt == n){
            n = n-1;
            flag = 0;
            cnt=0;
        }
    }
    for(auto a : answer)
    {
        for(auto b : a){
            if(b==0)
                break;
            ans.push_back(b);            
        }
    }
    return ans;
}