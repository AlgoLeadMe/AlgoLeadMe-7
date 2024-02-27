#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int> map, int n, int k){
    int cnt = 0;
    bool check = true;
    if(n == k){
        return 1;
    }

    for(int i = 0; i<n; i++){
        map[k] = i;
        for(int j = 0; j<k; j++){
            if(map[k]==map[j] || k-j == abs(map[k]-map[j]) ){
                check = false;
                break;
            }
        }
        if(check){
            cnt+=dfs(map, n, k+1);
        }
        check = true;
    }
    return cnt;

}

int main(){
    int n, cnt = 0;
    cin >> n;

    cnt = dfs(vector<int> (n,0), n, 0);
    cout << cnt;
    return 0;
}