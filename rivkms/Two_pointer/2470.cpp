#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vector<int> answer(2);
    int p1 = 0, p2 = n-1;
    int min = INT32_MAX;
    while(true){
        if(p1 >= p2){
            break;
        }
        int sum = vec[p1]+vec[p2];
        if(abs(sum) < min){
            min = abs(sum);
            answer[0] = vec[p1];
            answer[1] = vec[p2];
            if(sum == 0){
                break;
            }
        }
        if(sum < 0){
            p1++;
        }
        else{
            p2--;
        }
    }
    cout << answer[0] << " " << answer[1];
    return 0;
}