#include <iostream>
#include <stack>

int main(void)
{
    char ch;
    std::stack <char> stk;
    std::string res;

    ch = getchar();
    while (ch != '\n') {
        if (ch == '+' || ch == '-') {
            while(!stk.empty() && stk.top() != '(') {
                res.push_back(stk.top());
                stk.pop();
            }
            stk.push(ch);
        }
        else if (ch == '*' || ch == '/') {
            if (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                res.push_back(stk.top());
                stk.pop();
            }
            stk.push(ch);
        }
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                res.push_back(stk.top());
                stk.pop();
            }
            if (!stk.empty()) stk.pop();
        }
        else if (ch == '(') stk.push(ch);
        else res.push_back(ch);
        ch = getchar();
    }
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    std::cout << res;
    return 0;
}