#include <string>
#include <vector>

using namespace std;
long long helper(int i, int j, vector<int>& v)
{
    int num1=0,num2=0;
    int sign  = 1;
    for(int k=i;k<=j;k++)
    {
        num1+= (v[k] * sign);
        sign*=-1;
        num2+= (v[k] * sign);
    }
    return max(num1,num2);
}
long long solution(vector<int> sequence) {
    long long answer = -100001;
    int n = sequence.size();
    long long currA = 0, currB = 0;
    long long bestA = 0, bestB = 0;
    for(int i=0;i<n;i++)
    {
        long long a = (i%2==0) ? sequence[i] : -sequence[i];
        long long b = -a;
        
        currA = max(a,currA+a);
        currB = max(b,currB+b);
        
        bestA = max(currA,bestA);
        bestB = max(currB,bestB);
        
    }
    return max(bestA,bestB);
}