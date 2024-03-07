#include <iostream>

std::string FindValue(int n)
{
    std::string result = "1";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < result.size(); j++) {
            result[j] = (result[j] - '0') * 2 + '0';
            if (result[j] > '9') {
                result[j] -= 10;
                if (j == 0) result.insert(result.begin(), '1'), j++;
                else result[j-1]++;
            }
        }
    }
    result[result.size()-1]--;
    return result;
}

void Hanoi(int level, int start, int between, int end)
{
    std::ios_base::sync_with_stdio(false);  
    std::cout.tie(NULL);

    if (level == 1) std::cout << start << " " << end << "\n";
    else {
        Hanoi(level-1, start, end, between);
        std::cout << start << " " << end << "\n";
        Hanoi(level-1, between, start, end);
    }
    return;
}

int main(void) {
    int n;
    std::cin >> n;
    std::cout << FindValue(n) << "\n";
    if (!(n > 20)) Hanoi(n, 1, 2, 3);
    return 0;
}