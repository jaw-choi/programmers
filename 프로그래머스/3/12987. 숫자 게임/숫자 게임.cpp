#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int idx = 0;
    for(int i=0;i<A.size();i++)
    {
        if(idx>B.size()-1)
            return answer;
        while(A[i] >= B[idx])
        {
            idx++;
            if(idx>B.size()-1)
                return answer;
        }
        answer++;
        idx++;
    }
    //1,3,5,7
    //2,2,6,8
    //3,5,7
    //3,5,7,1
    return answer;
}