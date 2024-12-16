#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string tmp;
    vector<int> v;
    while(ss>>tmp){
        v.push_back(stoi(tmp));
    }
    sort(v.begin(),v.end());
    answer +=to_string(v[0]);
    answer +=" ";
    answer +=to_string(v[v.size()-1]);
    return answer;
}