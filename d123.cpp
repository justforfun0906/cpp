#include<iostream>
#include<set>
using namespace std;
int main(){
    int n, Case = 1;
    while(cin>>n){
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        set<int> sums;
        bool isB2 = 1;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                int temp = a[i] + a[j];
                if(sums.count(temp)){
                    isB2 = 0;
                    break;
                }else{
                    sums.insert(temp);
                }
            }
        }
        cout << "Case #" << Case++;
        if (isB2) cout << ": It is a B2-Sequence.\n\n";
        else cout << ": It is not a B2-Sequence.\n\n";
    }
}