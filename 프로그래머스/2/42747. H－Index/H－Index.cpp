#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// bool h_index(int h, const vector<int>& citations)
// {
//     int cnt = 0;
//     for(int i=0;i<citations.size();i++)
//     {
//         if(citations[i] < h) continue;
//         if(citations[i] >= h)
//         {
//             if(citations.size()-i >=h)
//                 return true;
//             else
//                 break;
//         }
//     }
//     return false;
// }
int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    sort(citations.begin(),citations.end());
    int h = 0;
    for(int i=0;i<n;i++)
    {
        h = min(citations[i],n-i);
        answer = max(answer,h);
    }
    
    return answer;
}