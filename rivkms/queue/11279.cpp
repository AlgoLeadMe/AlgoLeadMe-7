#include <iostream>
#include <queue>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, tmp; 
    cin >> n;
    
    priority_queue<int> q;
    vector<int> printq;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp == 0){
            if(q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else{
            q.push(tmp);
        }
    }
    return 0;
}