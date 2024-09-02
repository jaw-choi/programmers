#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = word.size();
    string aeiou = "AEIOU";
    int seq = 1+5+25+125+625;//781
    for(int i=0,b=1;i<word.size();i++,b*=5)
    {
        answer+= aeiou.find(word[i]) * seq / b;
    }
    
    return answer;
}