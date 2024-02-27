#include <iostream>
#include <stack>
#include <vector>

int main(void)
{
    bool is_Cstr = true;
    std::string str;
    std::stack <char> stk;
    std::vector <int> vec;

    std::cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            stk.push(str[i]);
            if (stk.size() > vec.size()) vec.push_back(0);
        }
        else if (!stk.empty() && ((str[i] == ')' && stk.top() == '(') || (str[i] == ']' && stk.top() == '['))){
            int value;
            if (stk.top() == '(') value = 2;
            else value = 3;

            if (stk.size() < vec.size()) {
                vec[vec.size()-2] += vec.back() * value;
                vec.pop_back();
            }
            else vec[vec.size()-1] += value;

            stk.pop();
        }
        else {
            is_Cstr = false;
            break;
        }
    }

    if (!is_Cstr || !stk.empty()) std::cout << 0;
    else std::cout << vec[0];
    return 0;
}