#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, goal;
    int a, b, cnt = 0;;
    cin >> n;
    a = 0;
    b = n-1;
    vector<int> vec(n,0);
    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cin >> goal;
    while(true){
        if(b<=a){
            cout << cnt;
            break;
        }
        if(vec[a]+vec[b] == goal){
            cnt++;
            a+=1;
            b-=1;
        }
        else if(vec[a]+vec[b] > goal){
            b-=1;
        }
        else{
            a+=1;
        }
    }
    return 0;
}