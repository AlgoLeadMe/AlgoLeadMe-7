#include <iostream>
#include <vector>

int main(void)
{
    int size, k, idx = 0;
    std::vector <int> v;

    std::cin >> size >> k;
    for (int i = 0; i < size;) v.push_back(++i);

    std::cout << "<";
    while(true) {
        idx = (idx + k - 1) % size--;
        std::cout << v[idx];
        v.erase(v.begin() + idx);

        if (size > 0) std::cout << ", ";
        else break;
    }
    std::cout << ">";
    
    return 0;
}