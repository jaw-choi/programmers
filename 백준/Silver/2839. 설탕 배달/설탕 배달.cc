#include <iostream>
using namespace std;
int main(void)
{
    
    int a;
    cin >> a;
    int answer = 0;
    while(a >=0){
        if(a%5==0){
            answer+= a/5;
            cout << answer;
            return 0;
        }
        a-=3;
        answer++;
    }
        cout << -1;
	return 0;
}