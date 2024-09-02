#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int sizeP = p.length();
    for(int i=0;i<=t.length()-sizeP;i++)
    {
        if(t.substr(i,sizeP) <= p)
            answer++;
    }
    return answer;
}