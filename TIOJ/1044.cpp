#include<bits/stdc++.h>
#include"lib1044.h"
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n=Initialize();
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r)/2;
        if(Guess(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    Report(r);
    return 0;
}