#include <iostream>
#include <vector>
#include <queue>

struct idx {int z, y, x;};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n, h, res = 0, non = 0;
    std::vector <idx> offset = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    std::queue <idx> que[2];
    bool curQueue = false;

    std::cin >> n >> m >> h;
    int box[h][m][n];

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                std::cin >> box[z][y][x];
                if (box[z][y][x] == 1) que[curQueue].push({z, y, x});
                else if (box[z][y][x] == 0) non++;
            }
        }
    }

    while (!que[curQueue].empty() && non > 0) {
        while (!que[curQueue].empty()) {
            int z = que[curQueue].front().z, y = que[curQueue].front().y, x = que[curQueue].front().x;
            for (idx set : offset) {
                int zz = z + set.z, yy = y + set.y, xx = x + set.x;
                if (zz >= 0 && zz < h && yy >= 0 && yy < m && xx >= 0 && xx < n && box[zz][yy][xx] == 0) {
                    box[zz][yy][xx] = 1, non--;
                    que[!curQueue].push({zz, yy, xx});
                }
            }
            que[curQueue].pop();
        }
        curQueue = !curQueue;
        res++;
    }

    if (non > 0) std::cout << -1;
    else std::cout << res;
    
    return 0;
}