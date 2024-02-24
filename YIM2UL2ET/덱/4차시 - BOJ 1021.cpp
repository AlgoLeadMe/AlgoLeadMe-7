#include <iostream>
#include <algorithm>
#include <deque>

int main(void)
{
    int n, m, k, idx, result;
    std::deque <int> dq;

    std::cin >> n >> m;
    for (int i = 0; i < n;) {
        dq.push_back(++i);
    }

    result = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> k;

        std::deque <int> :: iterator iter;
        iter = std::find(dq.begin(), dq.end(), k);
        idx = std::distance(dq.begin(), iter);

        if (idx < dq.size() - idx) {
            result += idx;
            for (int j = 0; j < idx; j++) {
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
        }
        else {
            result += dq.size() - idx;
            for (int j = 0; j < dq.size() - idx; j++) {
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
        }

        dq.pop_front();
    }
    
    std::cout << result;
    return 0;   
}