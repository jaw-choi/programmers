#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    for(auto& n : numbers)
        n*=2;
    return numbers;
}