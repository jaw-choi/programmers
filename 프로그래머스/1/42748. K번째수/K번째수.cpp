#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //1234567
    //sort(array.begin(),array.end());
    for(int i=0;i<commands.size();i++)
    {
        vector<int> tmp;
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        for(int j=start-1;j<end;j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[target-1]);
    }
    return answer;
}