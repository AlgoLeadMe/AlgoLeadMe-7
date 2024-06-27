#include <iostream>
#include <vector>

void cre_heap(std::vector <int> &heap, int key) {
    int k = heap.size();
    heap.push_back(key);
    while (k > 1) {
        if (abs(heap[k/2]) > abs(heap[k]) || (abs(heap[k/2]) == abs(heap[k]) && heap[k/2] > heap[k])) {
            std::swap(heap[k], heap[k/2]);
            k /= 2;
        }
        else break;
    }
    return;
}

void del_heap(std::vector <int> &heap) {
    int k = 1;
    heap[1] = heap.back(), heap.pop_back();
    while (k * 2 <= heap.size()) {
        if (k * 2 + 1 < heap.size() && (abs(heap[k*2+1]) < abs(heap[k*2]) || (abs(heap[k*2+1]) == abs(heap[k*2]) && heap[k*2+1] < heap[k*2])))
            k = k*2+1;
        else k = k*2;

        if (abs(heap[k/2]) > abs(heap[k]) || (abs(heap[k/2]) == abs(heap[k]) && heap[k/2] > heap[k])) 
            std::swap(heap[k/2], heap[k]);
        else break;
    }
    return;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k, x;
    std::vector <int> abs_heap = {0};

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (abs(x) > 0) cre_heap(abs_heap, x);
        else if (abs_heap.size() > 1) {
            std::cout << abs_heap[1] << '\n';
            del_heap(abs_heap);
        }
        else std::cout << 0 << '\n';
    }
    
}