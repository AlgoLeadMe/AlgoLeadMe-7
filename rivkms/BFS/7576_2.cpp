#include <iostream>
#include <vector>

using namespace std;
int SIZE;
bool filled(const vector<int>& box){
    for(int i = 0; i<SIZE; i++){
        if(box[i]==0){
            return false;
        }
    }
    return true;
}

bool changed(const vector<int>& box1, const vector<int>& box2){
    for(int i = 0; i<SIZE; i++){
        if(box1[i]!=box2[i]){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int w, h, s = 0;
    cin >> w >> h;
    SIZE = w*h;
    vector<int> box(SIZE);
    vector<int> box2(SIZE, 0);
    for(int i = 0; i<SIZE; i++){
        cin >> box[i];
    }
    while(true){
        if(filled(box)){
            cout << s << endl;
            break;
        }

        s++;
        for(int y = 0; y<h; y++){
            for(int x = 0 ; x<w; x++){
                if(box[y*w+x]<0) box2[y*w+x] = -1;
                else if(box[y*w+x]>0) box2[y*w+x] = 1;
                else if(x>0 && box[y*w+x-1]>0) box2[y*w+x] = 1;
                else if(y>0 && box[(y-1)*w+x]>0) box2[y*w+x] = 1;
                else if(x<w-1 && box[y*w+x+1]>0) box2[y*w+x] = 1;
                else if(y<h-1 && box[(y+1)*w+x]>0) box2[y*w+x] = 1;
            }
        }

        if(!changed(box, box2)){
            cout << -1 << endl;
            break;
        }
        box = box2;
    }
}