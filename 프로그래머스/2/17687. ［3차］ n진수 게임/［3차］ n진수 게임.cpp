#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toNDigit(int i, int n)
{
        int x = i;
        string tmp = "";

        while (x > 0) {          // 4번
            int bit = x % n;
            x /= n;

            if (bit > 9) tmp += char('A' + (bit - 10));
            else tmp += char(bit + '0');
        }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string answerTmp = "";
    int size_ = m * t;
    for(int i=0;i< size_;i++)
    {
        if(i==0){
            answerTmp+="0";
        continue;
        }
        string tmp = toNDigit(i,n);
        int j=0;
        while(j<tmp.length())
        {
            answerTmp += tmp[j];
            j++;
        }
        size_-=j-1;
    }
    for(int i=p-1;i< m * t;i+=m)
    {
            answer+=answerTmp[i];
    }
    return answer;
}