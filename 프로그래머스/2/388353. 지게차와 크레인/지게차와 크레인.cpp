#include <string>
#include <vector>
#include <iostream>

using namespace std;
void DeleteAll(char c, vector<string>& storage)
{
    int n = storage.size();
    int m = storage[0].size();
    for(int i=0;i<storage.size();i++){        
        for(int j=0;j<storage[0].size();j++){            
            if(storage[i][j]==c){
                if(i==0 || j==0 || i==n-1 || j==m-1)
                    storage[i][j]='.';
                else
                    storage[i][j]=',';
            }
        }
    }
}
void checkDelete(char c, vector<string>& storage)
{
    int n = storage.size();
    int m = storage[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(storage[i][j]==c){
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    storage[i][j]=',';
                }
                else
                {
                    if(storage[i-1][j]=='.' ||
                      storage[i+1][j]=='.' ||
                      storage[i][j-1]=='.' ||
                      storage[i][j+1]=='.' )
                        storage[i][j]=',';
                }
                
            }
            
        }
}
void commaToDot(vector<string>& storage)
{
        int n = storage.size();
    int m = storage[0].size();
    for(int i=0;i<storage.size();i++){        
        for(int j=0;j<storage[0].size();j++){
            
                if(storage[i][j]==','){
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    storage[i][j]='.';
                }
                else
                {
                    if(storage[i-1][j]=='.' ||
                      storage[i+1][j]=='.' ||
                      storage[i][j-1]=='.' ||
                      storage[i][j+1]=='.' )
                        storage[i][j]='.';
                }
                
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    for(auto& r : requests)
    {
        string str = r;
        if(str.size()==2)
        {
            DeleteAll(str[0],storage);
        }
        else if(str.size()==1)
        {
            checkDelete(str[0],storage);
        }
            //commaToDot(storage);
        bool changed = true;
while (changed) {
    changed = false;
    int n = storage.size();
    int m = storage[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] == ',') {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1 ||
                    storage[i - 1][j] == '.' || storage[i + 1][j] == '.' ||
                    storage[i][j - 1] == '.' || storage[i][j + 1] == '.') {
                    storage[i][j] = '.';
                    changed = true;
                }
            }
        }
    }
}

//         for(int i=0;i<storage.size();i++){
//         for(int j=0;j<storage[0].size();j++){
//             cout << storage[i][j] << " ";
//         }
//     cout << endl;
// }
//     cout << endl;
        
    }
    for(int i=0;i<storage.size();i++)
        for(int j=0;j<storage[0].size();j++)
            if(storage[i][j]!='.' && storage[i][j]!=',')
                answer++;

            
    return answer;
}