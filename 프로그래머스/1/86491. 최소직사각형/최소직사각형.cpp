#include <string>
#include <vector>

using namespace std;

void swap(vector<vector<int>>& s, int index)
{
    int tmp = s[index][0];
    s[index][0] = s[index][1];
    s[index][1] = tmp;
}


int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_1 = 0;
    int max_2 = 0;

    for(int i=0;i<sizes.size();i++)
    {
        max_1 = max(max_1, min(sizes[i][0],sizes[i][1]));
        max_2 = max(max_2, max(sizes[i][0],sizes[i][1]));
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
