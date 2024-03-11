#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> & a, const pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    pair<int, int> tmp = v.front();
    int s = 1;
    for(int i = 1; i < n; i++){
        if(tmp.second <= v[i].first){
            tmp = v[i];
            s++;
        }
    }
    cout << s;

    return 0;
}