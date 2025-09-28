#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>


using namespace std;
unordered_map<long long,long long> room;
long long GetEmptyRoom(long long n)
{
    if (room[n] == 0) return n; // 빈 방을 찾았다면 n 을 리턴한다. 
    return room[n] = GetEmptyRoom(room[n]); // 재귀호출을 끝내고 돌아오는 과정에서 타고 올라오기 전의 방들에게도 n 으로 업데이트 해준다.
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(auto num : room_number)
    {
        long long emptyRoom  = GetEmptyRoom(num); // 손님은 num 방 가고 싶어할 때 손님이 갈 수 있는 빈 방
        answer.push_back(emptyRoom);
        room[emptyRoom] = emptyRoom + 1; // 해당 방은 배정 되었으므로 다음 방으로 일단 지정해놓는다. (틀린 정보라도 나중에 GetEmptyRoom 함수 재귀호출에서 돌아오는 과정에서 정정 된다.)
    }

    return answer;
}
