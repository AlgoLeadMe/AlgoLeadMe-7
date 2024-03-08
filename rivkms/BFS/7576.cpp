#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int SIZE;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int w, h, s = 0;
    cin >> w >> h;
    SIZE = w*h;
    
    vector<int> box(SIZE);
    queue<int> q;

    for(int i = 0; i<SIZE; i++){
        cin >> box[i];
        if(box[i]==1){
            q.push(i);
        }
    }
    q.push(-1);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(tmp == -1){
            if(q.empty()){
                break;
            }
            s++;
            q.push(-1);
            continue;
        }
        int x = tmp%w;
        int y = tmp/w;
        for(int i = 0; i<4; i++){
            if(x+1<w && box[y*w+x+1]==0){
                box[y*w+x+1] = 1;
                q.push(y*w+x+1);
            }
            else if(y+1<h&&box[(y+1)*w+x]==0){
                box[(y+1)*w+x] = 1;
                q.push((y+1)*w+x);
            }
            else if(x>0 && box[y*w+x-1]==0){
                box[y*w+x-1] = 1;
                q.push(y*w+x-1);
            }
            else if(y>0 && box[(y-1)*w+x]==0){
                box[(y-1)*w+x] = 1;
                q.push((y-1)*w+x);
            }
        }
    }
    for(int y = 0; y<h; y++){
        for(int x = 0; x<w; x++){
            if(box[y*w+x]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << s;

    return 0;
}