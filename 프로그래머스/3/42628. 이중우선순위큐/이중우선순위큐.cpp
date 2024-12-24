#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    string order;
    string num;
    for(auto op : operations)
    {
        stringstream ss(op);
        ss>>order>>num;
        if(order=="I")
        {
            ms.insert(stoi(num));
        }
        else//D
        {
            if(!ms.empty())
            {
                if(num=="-1")
                {
                    ms.erase(ms.begin());
                }
                else
                {
                    ms.erase(prev(ms.end()));
                }
            }
        }
    }
    if(ms.empty())
        return {0,0};
    return {*ms.rbegin(),*ms.begin()};
}