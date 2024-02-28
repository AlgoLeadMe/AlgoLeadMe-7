#include <iostream>
#include <algorithm>

std::string translation(std::string min_str)
{
    int s_diff = 0;
    std::string alpha_str = min_str;
    for (int i = 0; i < min_str.size(); i++) {
        if (min_str[i] == 'k') alpha_str[i-s_diff] = 'c';
        else if (min_str[i] > 'n') alpha_str[i-s_diff]++;
        else if (min_str[i] == 'n' && i+1 < min_str.size() && min_str[i+1] == 'g') {
            alpha_str.erase(alpha_str.begin() + (i++) - s_diff);
            alpha_str[i - (++s_diff)] = 'o';
        }
    }
    return alpha_str;
}

bool compare(std::string str1, std::string str2)
{
    return translation(str1) < translation(str2);
}

int main(void)
{
    int n;
    std::cin >> n;

    std::string min_str[n];
    for (int i = 0; i < n; i++) std::cin >> min_str[i];
    
    std::sort(min_str, min_str+n, compare);

    for (int i = 0; i < n; i++) std::cout << min_str[i] << std::endl;
    return 0;
}