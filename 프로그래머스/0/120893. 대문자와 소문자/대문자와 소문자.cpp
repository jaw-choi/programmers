#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string) {
    string answer = "";
    int num = 'a' - 'A';
    for(auto c : my_string)
    {
        if(c >= 'a' && c<='z')
            answer += c - num;
        else
            answer += c + num;
    }
    return answer;
}