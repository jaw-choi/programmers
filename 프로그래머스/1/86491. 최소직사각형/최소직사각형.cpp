#include <string>
#include <vector>

using namespace std;

void swap(vector<vector<int>>& s, int index)
{
    int tmp = s[index][0];
    s[index][0] = s[index][1];
    s[index][1] = tmp;
}

int findMax(vector<vector<int>> s, int index,int curr)
{
    int ans = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i][index]<curr)
        {
            ans = max(ans,s[i][index]);
        }
    }
    return ans;
}


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_1 = 0;
    int max_2 = 0;

    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i][0] > sizes[i][1])
            swap(sizes,i);
    }
    for(int i=0;i<sizes.size();i++)
    {
        max_1 = max(max_1,sizes[i][0]);
        max_2 = max(max_2,sizes[i][1]);
    }
    
    return max_1 * max_2;
}


//80 70
//60 50 -> 50 60
//60 70 -> 70 60
//60 30 -> 30 60
//80 40 -> 40 80

//80 70
//   50
