#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool _is_prime(const int &val)
{
    if(val < 2) return false;
    for(int i = 2; i*i <= val; ++i)
    {
        if(val % i == 0) return false;
    }
    return true;
}

map<int, int> DFS(string numbers, vector<int> was_through, map<int, int> result, string input)
{
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(find(was_through.begin(), was_through.end(), i) != was_through.end())
        {
            continue;
        }
        vector<int> _was_thr = was_through;
        string str = input;
        _was_thr.push_back(i);
        str += numbers[i];
        if(_is_prime(stoi(str)))
        {
            result[stoi(str)] = 0;
        }
        result = DFS(numbers, _was_thr, result, str);
    }
    return result;
}

int solution(string numbers) {
    map<int, int> result;
    vector<int> was_through;
    result = DFS(numbers, was_through, result, "");
    return result.size();
}
