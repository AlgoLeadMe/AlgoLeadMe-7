#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::vector <int> &vec1, std::vector <int> &vec2);

int main(void)
{
    int n, result, end_time;
    std::cin >> n;

    std::vector <std::vector <int>> vec(n);
    for (int i = 0; i < n; i++) {
        int t, s;
        std::cin >> t >> s;
        vec[i].push_back(t);
        vec[i].push_back(s);
    }

    std::sort(vec.begin(), vec.end(), compare);

    result = vec[0][1] - vec[0][0], end_time = vec[0][1];
    for (int i = 1; i < n; i++) {
        if (end_time + vec[i][0] > vec[i][1]) {
            result -= end_time + vec[i][0] - vec[i][1];
            end_time = vec[i][1];
        }
        else end_time += vec[i][0];
    }

    if (result < 0) std::cout << "-1";
    else std::cout << result;
    
    return 0;
}

bool compare(std::vector <int> &vec1, std::vector <int> &vec2)
{
    if (vec1[1] == vec2[1]) return vec1[0] < vec2[0];   
    else return vec1[1] < vec2[1];
}