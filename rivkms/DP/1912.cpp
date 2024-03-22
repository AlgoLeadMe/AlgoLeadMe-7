#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int m = -2147483647;
    int n, tmp;

    cin >> n;
    vector<int> dp(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0];
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        if (m < dp[i]) m = dp[i];
    }
    cout << m;
    return 0;
}