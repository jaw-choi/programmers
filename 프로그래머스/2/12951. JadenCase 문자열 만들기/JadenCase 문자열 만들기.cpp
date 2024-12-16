#include <string>
#include <vector>
#include <sstream>

using namespace std;
void JadenCase(string& str)
{
    if(str[0]>='0' && str[0] <='9'){
        for(int i=1;i<str.length();i++){
            if(str[i]>='A'&&str[i]<='Z')
                str[i] = str[i] + abs('A'-'a');
        }
    }
    else{
        for(int i=0;i<str.length();i++){
            if(i==0){
                if(str[i]>='a'&&str[i]<='z')
                    str[i] = str[i] - abs('A'-'a');
            }
            else{
                if(str[i]>='A'&&str[i]<='Z')
                    str[i] = str[i] + abs('A'-'a');
            }
            
        }
    }
}
string solution(string s) {
    int change = abs('A' - 'a');
    bool isSpace = false;
    if(s[0]==' ')
        isSpace = true;
    
    for(auto& c : s)
    {
        if(c==' '){
            isSpace = true;
            continue;
        }
        if(c >= 'A' && c<='Z')
            c = c + change;      
        if(isSpace){
            if(c >= 'a' && c<='z')
                c = c - change;
        }
        isSpace = false;
        
    }
    if(s[0] >= 'a' && s[0]<='z')
        s[0] = s[0] - change;
    return s;
}