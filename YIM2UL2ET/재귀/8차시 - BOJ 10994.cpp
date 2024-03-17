#include <iostream>

void cover1(int n, int level)
{
    for (int i = 0; i < level; i++) std::cout << "* ";
    for (int i = 0; i < 4*(n-level)-3; i++) std::cout << "*";
    for (int i = 0; i < level; i++) std::cout << " *";
    std::cout << "\n";
}

void cover2(int n, int level)
{
    for (int i = 0; i < level; i++) std::cout << "* ";
    std::cout << "*";
    for (int i = 0; i < 4*(n-level)-5; i++) std::cout << " ";
    std::cout << "*";
    for (int i = 0; i < level; i++) std::cout << " *";
    std::cout << "\n";
}

void star(int n, int level)
{
    if (n == level+1) {
        for (int i = 0; i < n*2-2; i++) std::cout << "* ";
        std::cout << "*\n";
    }
    else {
        cover1(n, level);
        cover2(n, level);
        star(n, level+1);
        cover2(n, level);
        cover1(n, level);
    }
}

int main(void)
{
    int n;
    std::cin >> n;
    star(n, 0);
    return 0;
}