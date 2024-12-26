#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    /*8<brown<5000
    1<yellow<2000000
    가로>=세로
    
    ab = yellow+brown;
    (brown - 4) / 2 = a-2,b-2;*/
    
    for(int i=3;i<=2500;i++)
    {
        if(sum%i==0)
        {
            int a = i;
            int b = sum/i;
            if((a-2)*(b-2)==yellow){
                if(b<=a)
                    return {i,sum/i};
            }
        }
    }
    return answer;
}