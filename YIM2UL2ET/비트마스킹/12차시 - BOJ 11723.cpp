#include <iostream>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k, bits = 0;
    std::string command;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> k;
            bits |= (1<<k);
        }
        else if (command == "remove") {
            std::cin >> k;
            bits &= ~(1<<k);
        }
        else if (command == "check") {
            std::cin >> k;
            if (bits & (1<<k)) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if (command == "toggle") {
            std::cin >> k;
            bits ^= (1<<k);
        }
        else if (command == "all") bits = (1<<21)-1;
        else bits = 0;
    }
    return 0;
}