#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct fileName{
    int index;
    int num;
    string head;
};

vector<fileName> v;

bool cmp(const fileName& str1,const fileName& str2)
{
    if(str1.head == str2.head){
        if(str1.num==str2.num){
            return str1.index < str2.index;
        }
        else{
            return str1.num < str2.num;
        }
    }
    
    return str1.head < str2.head;
}

vector<string> solution(vector<string> files) {
    //Head, Number, Tail
    vector<string> answer;
    for(int i = 0; i < files.size(); i++){
        vector<int> idx;
        for(int j = 0; j < files[i].size(); j++){
            if('0' <= files[i][j] && files[i][j] <= '9'){
                idx.push_back(j);
            }
        }
        string head = "";
        for(int j = 0; j < idx[0]; j++){
            head += tolower(files[i][j]);
        }
        string number = files[i].substr(idx[0], idx.size());

        fileName f;
        f.index = i;
        f.head = head;
        f.num = stoi(number);

        v.push_back(f);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<files.size();i++)
    {
        answer.push_back(files[v[i].index]);
    }
    return answer;
}