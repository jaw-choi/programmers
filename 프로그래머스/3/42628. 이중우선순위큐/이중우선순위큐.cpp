#include <string>
#include <vector>
#include <sstream>
#include <set>



using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(auto op : operations)
    {
        stringstream ss(op);
        char order;
        string num;
        ss >> order >> num;
        if(order=='I'){
            ms.insert(stoi(num));
        }
        else if(!ms.empty()){//oreder=='D'
            if(stoi(num)==1){//erase max
                ms.erase(--ms.end()); //////////////////
            }
            else//erase min
                ms.erase(ms.begin());
        }
    }
    if(ms.empty())
        return {0,0};
    return {*ms.rbegin(),*ms.begin()};
}