#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> box;

void func(const int & start, const int & center, const int & end, const int & n){
    if(n==1){
        box.push_back(pair<int, int> (start, end));
        return;
    }
    func(start, end, center, n-1);
    box.push_back(pair<int, int> (start, end));
    func(center, start, end, n-1);

    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a = 0; 
    cin >> n;
    func(1,2,3,n);
    cout << box.size() << "\n";
    for(pair<int, int> i : box){
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}