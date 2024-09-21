#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for(int i=food.size()-1;i>0;i--)
    {
        int tmp = food[i];
        if(tmp%2!=0)
            tmp-=1;
        tmp/=2;
        for(int j=0;j<tmp;j++)
        {
            answer = to_string(i) + answer;
        }
        for(int j=0;j<tmp;j++)
        {
            answer = answer + to_string(i);
        }
    }
    return answer;
}