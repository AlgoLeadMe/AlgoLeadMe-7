#include <iostream>
#include <algorithm>

std::string change_string(std::string str)
{
    int delay = 0;
    std::string new_str = str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'k') new_str[i-delay] = 'c';
        else if (str[i] > 'n') new_str[i-delay]++;
        else if (str[i] == 'n' && i+1 < str.size() && str[i+1] == 'g') {
            new_str.erase(new_str.begin() + (i++) - delay);
            new_str[i - (++delay)] = 'o';
        }
    }
    return new_str;
}

bool compare(std::string str1, std::string str2)
{
    return change_string(str1) < change_string(str2);
}

int main(void)
{
    int n;
    std::cin >> n;

    std::string str[n];
    for (int i = 0; i < n; i++) std::cin >> str[i];
    
    std::sort(str, str+n, compare);

    for (int i = 0; i < n; i++) std::cout << str[i] << std::endl;
    return 0;
}