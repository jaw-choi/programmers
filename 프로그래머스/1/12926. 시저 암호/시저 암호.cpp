#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int tmp = 0;
    for(auto& c : s)
    {
        if(c != ' ')
        {
            if(c >='a' && c<='z'){
                tmp = ((c - 'a') + n)%26;
                c = 'a' + tmp;
            }
            else if(c >='A' && c<='Z'){
                tmp = ((c - 'A') + n)%26;
                c = 'A' + tmp;                
            }
        }
    }
    return s;
}