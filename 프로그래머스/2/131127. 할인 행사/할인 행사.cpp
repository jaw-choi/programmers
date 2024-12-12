#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    map <string,int> items;
    for(int i=0;i<want.size();i++) items[want[i]] = number[i];// 원하는 상품과 그 개수 등록
    for(int i=0;i<discount.size()-9;i++)
    {//10일 기간을 전체다 체크해준다.
        bool able = true;// 회원가입해도 되는지
        map <string,int> tmp(items);// 원하는 상품과 그 개수 복제본
        for(int j=i;j<i+10;j++) tmp[discount[j]]--;//10일동안 상품--
        for(auto c : tmp)
        {
            if (c.second)
            {//구매못한 상품이 있다면
                able = false;
                break;
            }
        }
        if (able) answer++;// 다 구매할 수 있다면
    }
    return answer;
}