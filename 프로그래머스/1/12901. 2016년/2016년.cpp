#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int date = 0;
    for(int i =0;i<a-1;i++)
        date+=month[i];
    date+=b;
    if(date%7==1)
        return "FRI";
    else if(date%7==2)
        return "SAT";
    else if(date%7==3)
        return "SUN";
    else if(date%7==4)
        return "MON";
    else if(date%7==5)
        return "TUE";
    else if(date%7==6)
        return "WED";
    else if(date%7==0)
        return "THU";
    return answer;
}