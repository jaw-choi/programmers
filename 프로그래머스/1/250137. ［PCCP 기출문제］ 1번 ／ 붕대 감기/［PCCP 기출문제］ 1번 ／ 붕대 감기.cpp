#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int size_ = attacks[attacks.size()-1][0];
    int curr = health;
    int attackIdx = 0;
    int bandageTime = 0;
    for(int i=1;i<=size_;i++)
    {
        if(attacks[attackIdx][0] == i)
        {
            bandageTime = 0;
            curr -= attacks[attackIdx][1];
            if(curr <= 0)//die
                return -1;
            attackIdx++;
        }
        else
        {
            bandageTime++;
            curr += bandage[1];
            if(bandageTime == bandage[0]){
                curr += bandage[2];
                bandageTime = 0;
            }
            if(curr > health)
                curr = health;
            
        }
    }
    return curr;
}