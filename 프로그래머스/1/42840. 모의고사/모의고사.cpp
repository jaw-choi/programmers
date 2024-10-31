#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    int n = answers.size();
    vector<int> answer;
    vector<int> ans;
    int cnt1=0,cnt2=0,cnt3 = 0;
    vector<int> stu1 = {1,2,3,4,5};
    vector<int> stu2 = {2,1,2,3,2,4,2,5};
    vector<int> stu3 = {3,3,1,1,2,2,4,4,5,5};
    for(int i=0;i<n;i++)
    {
        if(answers[i] == stu1[i%stu1.size()])
            cnt1++;
        if(answers[i] == stu2[i%stu2.size()])
            cnt2++;
        if(answers[i] == stu3[i%stu3.size()])
            cnt3++;
    }
    int maxN = max(cnt1,max(cnt2,cnt3));
    if(maxN == cnt1)
        answer.push_back(1);
    if(maxN == cnt2)
        answer.push_back(2);
    if(maxN == cnt3)
        answer.push_back(3);
    cout << cnt1 << " "<<cnt2 << " "<<cnt3 << " ";
    return answer;
}