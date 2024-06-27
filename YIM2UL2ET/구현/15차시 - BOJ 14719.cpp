#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    int height, width, res = 0;

    std::cin >> height >> width;
    std::vector <int> vec(width);
    for (int i = 0; i < width; i++) std::cin >> vec[i];
    
    for (int i = height; i >= 0; i--) {
        int cnt = std::count_if(vec.begin(), vec.end(), [&i](int v) -> bool {return v>=i;});
        if (cnt > 1) {
            int front = std::find_if(vec.begin(), vec.end(), [&i](int v) -> bool {return v>=i;}) - vec.begin();
            int back = std::find_if(vec.rbegin(), vec.rend(), [&i](int v) -> bool {return v>=i;}) - vec.rbegin();
            res += width - back - front - cnt;
        }
    }
    
    std::cout << res;
    return 0;
}