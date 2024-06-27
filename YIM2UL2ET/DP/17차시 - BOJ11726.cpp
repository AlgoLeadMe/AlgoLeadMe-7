#include <iostream>
#include <vector>

std::vector <int> dp(1000);

int func(int n) {
    if (dp[n-1] == 0) {
        dp[n-1] = (func(n-1) + func(n-2)) % 10007;
    }
    return dp[n-1];
}

int main(void) {
    dp[0] = 1, dp[1] = 2;

    int n;
    std::cin >> n;
    std::cout << func(n);
    return 0;
}