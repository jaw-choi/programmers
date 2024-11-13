#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string getHead(const string& str)
{
    string ans;
    for(auto c : str){
        if(c>='0' && c<='9')
            break;
        else
            ans+=tolower(c);
    }
    return ans;
}
int findNumIdx(const string &str)
{
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            break;
    }
    return i;
}
int getNum(string str)
{
    return std::stoi(str.substr( findNumIdx(str) ));
}
bool cmpNum(const string& str1, const string& str2)
{
    return getNum(str1) < getNum(str2);
}

bool cmpHead(const string& str1, const string& str2)
{
    //string head1 = getHead(str1);
    //string head2 = getHead(str2);
    //return head1 < head2;
    return getHead(str1).compare(getHead(str2)) < 0;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),cmpNum);
    stable_sort(files.begin(),files.end(),cmpHead);
    
    return files;
}

