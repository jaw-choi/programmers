#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    //1234567
    //sort(array.begin(),array.end());
    for(int i=0;i<commands.size();i++)
    {
        tmp = array;
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        for(int j=start-1;j<end;j++)
        sort(tmp.begin() + start -1,tmp.begin()+end);
        answer.push_back(tmp[start + target-2]);
    }
    return answer;
}