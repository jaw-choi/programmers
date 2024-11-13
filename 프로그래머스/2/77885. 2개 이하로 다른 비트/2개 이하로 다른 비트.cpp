#include <string>
#include <vector>

using namespace std;

long long diff(long long num, long long other)
{
    
}
//1011 ->11
//1100 ->12
//1111 ->15
//1101 ->13
long long helper(long long num)
{
    long long bit = 1;
    if(num%2==0)
        return num+1;
    else {
            while (true) {
                if ((num & bit) == 0)
                    break;
                bit *= 2;
            }
         bit = bit / 2;
    }
    return num + bit;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto num : numbers)
    {
        answer.push_back(helper(num));
    }
    return answer;
}