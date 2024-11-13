#include <string>
#include <vector>

using namespace std;


long long helper(long long num)
{
    long long bit = 1;
    if(num%2==0)
        return num+1;
    else {
            while (true) {
                if ((num & bit) == 0)
                    break;
                bit = bit << 1;
            }
         bit = bit >>1;
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