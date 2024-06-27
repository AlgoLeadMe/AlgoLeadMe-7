#include <iostream>
#include <algorithm>

bool isOneChar(std::string str) {
    int size = str.size();
    for (int i = 1; i < size; i++) {
        if (str[i-1] != str[i]) return false;
    }
    return true;
}

int main(void) {
    std::string str, rstr;
    std::cin >> str, rstr = str;
    std::reverse(rstr.begin(), rstr.end());

    if (isOneChar(str)) std::cout << -1;
    else if (str == rstr) std::cout << str.size()-1;
    else std::cout << str.size();

    return 0;
}