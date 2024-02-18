#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec(101,vector<int> (10,0));

int func(const int & n, const int & a){
    if(vec[n][a]){
        return vec[n][a];
    }
    else if(a==0){
        return vec[n][a] = func(n-1, 1)%1000000000;
    }
    else if(a==9){
        return vec[n][a] = func(n-1, 8)%1000000000;
    }
    return vec[n][a] = ((func(n-1, a-1)) + (func(n-1, a+1)))%1000000000;
}

int main(){
    int n, sum = 0;
    cin >> n;
    
    
    for(int i = 0 ;i<=9; i++){
        vec[1][i] = 1;
    }
    
    for(int i = 1; i<=9; i++){
        sum+=func(n ,i);
        sum%=1000000000;
    }
    cout << sum;
    return 0;
}
