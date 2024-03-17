// <미완>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, A, D;
vector<int> vec;
pair<int, int> compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    if(p1.first < M){
        if(p2.first < M){
            return p1.second < p2.second ? p1 : p2;
        }
        else{
            return p2;
        }
    }
    else{
        if(p2.first < M){
            return p1;
        }
        else{
            return p1.second < p2.second ? p1 : p2;
        }
    }
}

pair<int, int> dfs(int point, int num, int n, int canblood) {
    if (n == N) {
        return pair<int, int>(point, num);
    }
    if(!canblood){
        pair<int, int> p1 = dfs(point+vec[n], num, n + 1, canblood);
        pair<int, int> p2 = dfs(point+A, num+1, n + 1, D-1);
        return compare(p1, p2);
    }
    else{
        return dfs(point, num, n + 1, canblood-1);
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

    pair<int, int> p = dfs(0, 0, 0, 0);
    cout<< p.first << " " << p.second;

    return 0;
}