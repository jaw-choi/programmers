#include <string>
#include <vector>
#define INF 20000000
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> minTaxiCost(n+1,vector<int>(n+1,INF));

    for(int i=0;i<fares.size();i++)
    {
        minTaxiCost[fares[i][0]][fares[i][1]] = fares[i][2];
        minTaxiCost[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i = 1; i <= n; ++i)
        minTaxiCost[i][i] = 0;
    
    for(int k = 1; k <= n; ++k) // ⭐k 를 거쳐갈 때⭐
        for(int i = 1; i <= n; ++i) // (i, j) : i->j 최단 경로
            for(int j = 1; j <= n; ++j) 
                if (minTaxiCost[i][j] > minTaxiCost[i][k] + minTaxiCost[k][j]) // i 에서 j 로 갈 때 k 를 거쳐가는게 더 좋은 최단 경로가 된다면 업데이트
                    minTaxiCost[i][j] = minTaxiCost[i][k] + minTaxiCost[k][j];
    
      for(int i = 1; i <= n; ++i)
        if (answer > minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b])
            answer = minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b];
    return answer;
}
//dp
//  1  2   3   4   5   6
//s 10 66  51  0   34  35
//A 25 48  26  35  2   0
//B 63 0   22  66  46  48
//  98 114 99  101 82  83 ---> 82 o
