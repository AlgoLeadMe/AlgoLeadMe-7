#include <iostream>
#include <stack>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    char ch;
    std::string str;
    std::stack <char> stk1, stk2;

    std::cin >> str >> n;
    for (int i = 0; i < str.size(); i++) stk1.push(str[i]);
    
    for (int i = 0; i < n; i++) {
        std::cin >> ch;
        if (ch == 'L' && !stk1.empty()) stk2.push(stk1.top()), stk1.pop();
        else if (ch == 'D' && !stk2.empty()) stk1.push(stk2.top()), stk2.pop();
        else if (ch == 'B' && !stk1.empty()) stk1.pop();
        else if (ch == 'P') std::cin >> ch, stk1.push(ch);
    }

    while(stk1.size() > 0) stk2.push(stk1.top()), stk1.pop();
    while(stk2.size() > 0) std::cout << stk2.top(), stk2.pop();
    return 0;
}