#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int calculate(vector<string> a)
{
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i+=2)
    {
        string sh{};
        string sm{};
        sh += a[i][0];
        sh += a[i][1];
        sm += a[i][3];
        sm += a[i][4];

        string eh{};
        string em{};
        eh += a[i+1][0];
        eh += a[i+1][1];
        em += a[i+1][3];
        em += a[i+1][4];
        int startTime = 60 * stoi(sh) + stoi(sm);
        int endTime = 60 * stoi(eh) + stoi(em);
        ans += endTime - startTime;
    }
    
    return ans;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<string, vector<string>> mp;
    string time, car, state;
    int f;
    int tmp;
    for (auto c : records)
    {
        stringstream ss(c);
        ss >> time >> car >> state;
        mp[car].push_back(time);
    }
        vector<pair<string, vector<string>>> vec(mp.begin(), mp.end()); // map을 vector로 변경
    sort(vec.begin(), vec.end());
    for (auto m : mp)
    {
        if (m.second.size() % 2 != 0)
            m.second.push_back("23:59");
        int total = calculate(m.second);
        int price = fees[1];
        if (total > fees[0]) {
            price += ceil((total - fees[0]) / (double)fees[2]) * fees[3];
        }
        answer.push_back(price);
    }
    
    return answer;
}