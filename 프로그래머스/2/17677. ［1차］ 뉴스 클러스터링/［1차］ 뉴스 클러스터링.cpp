#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(string str1, string str2) {
    if(str1.size()==0||str2.size()==0)
        return 65536;
    int answer = 0;

    int left=-1;
    int right=0;
    vector<string> leftStr{};
    vector<string> rightStr{};
    unordered_map<string,int> A;
    unordered_map<string,int> B;
    unordered_map<string,int> allStr;
    while(right < str1.size())
    {
        string tmp1{};
        left++;
        right++;  
        for(int i=left;i<=right;i++)
        {
            if(str1[i]>='A' && str1[i]<='Z')
            {
                str1[i] = 'a' + (str1[i]-'A');
            }
            if(str1[i]<'a' || str1[i]>'z')
                continue;
            tmp1+=str1[i];       
        }
        if(tmp1.size()==2)
            leftStr.push_back(tmp1);  
          
    }
    left=-1;
    right=0;
    while(right < str2.size())
    {
        string tmp2{};
        left++;
        right++;  
        for(int i=left;i<=right;i++)
        {
            if(str2[i]>='A' && str2[i]<='Z')
            {
                str2[i] = 'a' + (str2[i]-'A');
            }
            if(str2[i]<'a' || str2[i]>'z')
                continue;
            tmp2+=str2[i];       
        }
        if(tmp2.size()==2)
            rightStr.push_back(tmp2);           
    }
    for(auto l : leftStr)
    {
        A[l]++;
        if(allStr[l]==0)
            allStr[l]++;
    }
    for(auto r : rightStr)
    {
        B[r]++;
        if(allStr[r]==0)
            allStr[r]++;
    }
    int inter = 0;
    int Union = 0;
    if(allStr.size()==0)
        return 65536;
    for(auto a : allStr)
    {
        inter+= min(A[a.first],B[a.first]);
        Union+= max(A[a.first],B[a.first]);
    }
    if(Union==0)
        return 65536;
    answer = ((double)inter / (double)Union) * 65536;
    return answer;
}