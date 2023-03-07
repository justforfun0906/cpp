#include<iostream>  
#include<string.h>  
using namespace std;  
struct video{  
    int L,S;  
};   
int main(){  
    int N,M;  
    cin>>N>>M;  
    M+=1;  
    video v[N];  
    int bag[M];  
    for(int k=0;k<M;k++){  
        bag[k]=0;  
    }  
    for(int i=0;i<N;i++){  
        cin>>v[i].S>>v[i].L;  
    }  
    for(int i=0;i<N;i++){  
        for(int j=M;j>=v[i].L;j--){  
            if((bag[j-v[i].L]+v[i].S)>=bag[j]){  
                bag[j]=bag[j-v[i].L]+v[i].S;  
            }  
        }  
    }  
    cout<<bag[M-1];  
}
