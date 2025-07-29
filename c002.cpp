#include<iostream>
using namespace std;
struct rectangle{
    int x1, y1, x2, y2;
    bool isInside(int x, int y){
        if(x>x1 && x<x2 && y<y1 && y < y2){
            return true;
        }else{
            return false;
        }
    }
};
int f91(int n){
    if(n<=100){
        return f91(f91(n+11));
    }else{
        return n-10;
    }
}
int main(){
    pair<int, string> p1;
    rectangle recs[10];
    for(int i=0;i<3;i++){
        cin>>recs[i].x1>>recs[i].y1>>;
    }
    for(int i=0;i<6;i++){
        int x,y;
        cin>>x>>y;
        for(int j = 0;j<3;j++){
            if(recs[j].isInside(x,y)){
                cout<<"Inside"<<j<<"th rectangle";
            }
        }
    }
    char a;
    int v = a-'0';
}