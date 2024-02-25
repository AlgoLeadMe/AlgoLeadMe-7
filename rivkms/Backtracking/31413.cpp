// <미완>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, A, D;
vector<int> vec;
pair<int, int> compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second > p2.second) {
        if (p2.first >= M) {
            return p2;
        }
        return p1;
    }
    if (p1.second < p2.second) {
        if (p1.first >= M) {
            return p1;
        }
        return p2;
    }
    return p1.first > p2.first ? p1 : p2;
}

pair<int, int> dfs(bool blood, int point, int num, int n) {
    if (n == N) {
        return pair<int, int>(point, num);
    }
    if (!blood) {
        point += vec[n];
        pair<int, int> p1 = dfs(false, point, num, n + 1);
        pair<int, int> p2 = dfs(true, point, num, n + 1);
        return compare(p1, p2);
    }
    else {
        point += A;
        num += D;
        return dfs(false, point, num, n + 1);
    }
}

int main() {
    int tmp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    cin >> A >> D;

    pair<int, int> p = dfs(false, 0, 0, 0);
    if (p.first >= M) {
        cout << -1;
    }
    else {
        cout << p.second;
    }
    return 0;
}