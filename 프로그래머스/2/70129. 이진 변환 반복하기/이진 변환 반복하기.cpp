#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = s;
    int cnt = 0;
    int numToChange = 0;
    while(tmp!="1")
    {
        int num=0;
        s = tmp;
        for(auto c : s){
            if(c=='1')
                num++;
            else
                cnt++;
        }
        
        tmp = "";
        while(num!=0){
            if(num%2==0)
                tmp = '0' + tmp;
            else
                tmp = '1' + tmp;
            num/=2;
        }
        numToChange++;
    }
    answer.push_back(numToChange);
    answer.push_back(cnt);
    return answer;
}