#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> ans;
    for(int i=0;i<elements.size();i++)
    {
        int sum = 0;
        for(int j=i;j<i + elements.size();j++)
        {
            sum+= elements[j%elements.size()];
            ans.insert(sum);
            //cout << sum << " ";
        }
    }

    return ans.size();
}