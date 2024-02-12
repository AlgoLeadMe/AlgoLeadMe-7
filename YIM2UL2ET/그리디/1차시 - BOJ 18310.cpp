#include <iostream>

int main(void)
{
    bool IndexSet = false;
    int n, temp, index, result, up, down;
    long long value, tvalue;
    int location[100000] = {0};

    value = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        location[temp-1]++;
        value += temp-1;
    }

    index = 0, up = n, down = 0, tvalue = value;
    for (int i = 0; i < 100000; i++) {
        if (location[i] == 0) continue;

        tvalue += down * (i - index);
        tvalue -= up * (i - index);
        down += location[i];
        up -= location[i];

        if (tvalue < value || IndexSet == false) {
            value = tvalue;
            result = i+1;
            IndexSet = true;
        }
        index = i;
    }
    
    std::cout << result;
    return 0;
}