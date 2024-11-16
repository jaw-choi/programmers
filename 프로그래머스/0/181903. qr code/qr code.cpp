#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    int idx = 0;
    for(auto c : code)
    {
        if(idx % q == r)
            answer += code[idx];
        idx++;
    }
    return answer;
}