#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    if(n<num)
        return 0;
    if(n==num)
        return 1;
    int i = num;
    while(i<=n)
    {
        if(i+w*2 <=n)
        {
            answer+=2;
            i = i+w*2;
        }
        else
        {
            int remain = w-(i%w);
            if(remain==w)
                remain=0;
            if(i+remain*2+1 <=n)
                answer++;
            break;
        }
    }
    return answer;
}