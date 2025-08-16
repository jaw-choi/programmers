#include <string>
#include <vector>

using namespace std;

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