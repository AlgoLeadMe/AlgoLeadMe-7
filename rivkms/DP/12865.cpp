#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> wv(n+1, pair<int, int>(0,0));
    vector<vector<int>> value (n+1, vector<int>(k+1, 0));
    for(int i = 1; i<=n; i++){
        cin >> wv[i].first >> wv[i].second;        
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k;j++){
            if(wv[i].first > j ){
                value[i][j] = value[i-1][j];
            }
            else{
                value[i][j] = max(value[i-1][j], value[i-1][j-wv[i].first]+wv[i].second);
            }
            
        }
    }
    cout << value[n][k];

    return 0;
}