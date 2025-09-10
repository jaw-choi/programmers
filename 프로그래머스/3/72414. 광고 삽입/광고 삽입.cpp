#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define time first
#define deltaView second

int ToInt(string log) {
    int hours = stoi(log.substr(0, 2));
    int minutes = stoi(log.substr(3, 2));
    int seconds = stoi(log.substr(6, 2));
    return 3600 * hours + 60 * minutes + seconds;
}

string ToStr(int log) {
    string hours = to_string(log / 3600);
    if (hours.length() == 1) hours = "0" + hours;
    string minutes = to_string((log % 3600) / 60);
    if (minutes.length() == 1) minutes = "0" + minutes;
    string seconds = to_string((log % 3600) % 60);
    if (seconds.length() == 1) seconds = "0" + seconds;
    return hours + ":" + minutes + ":" + seconds;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTotalTime = ToInt(play_time);
    int advTotalTime = ToInt(adv_time);
    vector<pair<int, int>> event; // 이벤트들을 저장할 배열
    
    event.push_back({ 0, 0 }); // 0 초도 이벤트로서 추가해주기
    for (auto& log : logs) {
        int startTime = ToInt(log.substr(0, 8));
        event.push_back({ startTime, 1 }); // 시작 시간은 변화량 1 로 함께 저장
        int endTime = ToInt(log.substr(9, 8));
        event.push_back({ endTime, -1 }); // 종료 시간은 변화량 -1 로 함께 저장
    }
    // 시간 순서별로 정렬해주기
    sort(event.begin(), event.end());
    
    int startIndex = 0, endIndex = 0; // ⭐투포인터⭐ 파란색 별(이벤트 포인터 1), 초록색 별(이벤트 포인터 2)
    long long startViews = 0, endViews = 0; // 새로운 구간에서 빠지는 시청자수(파란색), 새로운 구간에 포함되는 시청자수(노란색) 
    long long sumViews = 0, maxViews = 0; // 현재 광고 구간의 누적 시청자수, 현재까지 구한 광고 구간의 누적 시청자수 최대값
    int advStartTime = 0, answerTime = 0; // 광고 시작 시간(매번 이벤트 시간이 대입될 것이다. 1초씩++ 되던 첫번째 풀이와 달리!), 현재까지 구한 광고 구간의 누적 시청자수 최대값이 나온 그 광고 시작 시간(답)
    
    /* 1. {0초 이벤트} 즉, 0초에서 광고가 시작될 때의 광고 시간 동안의 누적 시청자 수 구하기 */
    // 먼저 광고 시간 전에 등장하는 이벤트들마다 시청자 수를 합산
    while(endIndex + 1 < event.size() && event[endIndex + 1].time <= advTotalTime) {
        int deltaTime = event[endIndex + 1].time - event[endIndex].time;
        sumViews += deltaTime * endViews;
        endViews += event[endIndex + 1].deltaView;
        endIndex++;
    }
    // 아직 이벤트가 걸리진 않았지만 0 초부터 시작한 광고에 진행 중인 이벤트가 있을 수 있으므로 광고시간과 마지막 이벤트 사이에서 발생한 시청자 수도 합산해준다.(갈색)
    // 이부분은 사실 영상에서 등장한 코드로는 sumViews += (advTotalTime - event[endIndex + 1].time) * endViews; 이었는데 event[endIndex]이 아닌 event[endIndex + 1] 인게 이해가 잘 안됐다. 내가 생각한대로 event[endIndex] 를 사용해서 제출했는데도 다 정답 처리 되길래 이걸 사용했다. 아무튼 영상의 코드와 다른점은 여기 뿐이다.
    sumViews += (advTotalTime - event[endIndex].time) * endViews;
    maxViews = sumViews;
    
    /* 2. 가까운 이벤트에 걸릴 때 마다 광고 시간 동안의 누적 시청자 수 구하기 👉 Sum = Sum - A + B */
    while (advStartTime <= playTotalTime - advTotalTime && endIndex + 1 < event.size()){
        //현재 광고 구간에서 가장 가까운 이벤트로 이동한다.
        int startDeltaTime = event[startIndex + 1].time - advStartTime; // 파란색 별(이벤트 포인터 1)과 현재의 광고 시작 시간(advStartTime)간의 차이
        int endDeltaTime = event[endIndex + 1].time - (advStartTime + advTotalTime); // 초록색 별(이벤트 포인터 2)과 현재의 광고 종료 시간(advStartTime + advTotalTime)간의 차이
        if (startDeltaTime <= endDeltaTime) { // startIndex 가 가리키는 이벤트와 더 가깝다면 광고 구간을 startDeltaTime 만큼 이동한다. 그리고 Prefix Sum 으로 새로운 구간 합을 구한다.
            sumViews += (endViews - startViews) * startDeltaTime; // Prefix SUm
            startViews += event[startIndex + 1].deltaView; // 다음에 빠질 시청자수 (변화량 반영하여 업데이트)
            startIndex++;
            advStartTime += startDeltaTime; // 광고 구간 이동
        }
        else {
            sumViews += (endViews - startViews) * endDeltaTime; // Prefix SUm
            endViews += event[endIndex + 1].deltaView; // 다음에 포함될 시청자수 (변화량 반영하여 업데이트)
            endIndex++;
            advStartTime += endDeltaTime; // 광고 구간 이동
        }
        
        if (maxViews < sumViews){
            maxViews = sumViews;
            answerTime = advStartTime;
        }
    }
    

    answer = ToStr(answerTime);
    return answer;
}