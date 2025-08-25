#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), prev(nullptr),next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : val(x), prev(prev), next(next) {}
};
string solution(int n, int k, vector<string> cmd) {
    string answer(n,'X');
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    stack<ListNode*> deleted;
    
    for(int i=1;i<n;i++){
        ListNode* tmp = new ListNode(i);
        curr->next = tmp;
        tmp->prev = curr;
        curr = tmp;
    }
    curr = head;
    for(int i=0;i<k;i++)
        curr = curr->next;

    for(int i=0;i<cmd.size();i++)
    {
        char command = cmd[i][0];
        if(command == 'D'){
            int cnt = stoi(cmd[i].substr(2));
            for(int i=0;i<cnt;i++)
                curr = curr->next;
        }
        else if(command == 'U'){
            int cnt = stoi(cmd[i].substr(2));
            for(int i=0;i<cnt;i++)
                curr = curr->prev;
        }
        else if(command == 'C'){
            deleted.push(curr);
            if(curr->prev)
                curr->prev->next = curr ->next;
            else
                head = curr->next;
            if(curr->next)
                curr->next->prev = curr->prev;
            
            if(curr->next)
                curr = curr->next;
            else
                curr = curr->prev;
        }
        else if(command == 'Z')
        {
            ListNode* recov = deleted.top();
            deleted.pop();
            if(recov->prev){
                recov->prev->next = recov;
            }
            else{
                head = recov;
                recov->next->prev = recov;
            }
            if(recov->next){
                recov->next->prev = recov;
            }
        }
    }
    
       while(head){
           answer[head->val] = 'O';
           head = head->next;
    }
    return answer;
}