#include<iostream>
using namespace std;
int main(){
    /*
    [(0,0)][(0,1)][(0,2)][(0,3)][(0,4)]
    [(1,0)][(1,1)][(1,2)][(1,3)][(1,4)]
    [(2,0)][(2,1)][(2,2)][(2,3)][(2,4)]

    n = 3, m = 5
    b[0][0] = a[2][4]
    b[0][1] = a[2][3]
    b[1][1] = a[1][3]
    b[i][j] = a[n-1-i][m-1-j]
    */
    int t;
    cin>>t;
    for(int T=0;T<t;T++){
        int n,m; cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int b[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j] = a[n-1-i][m-1-j];
            }
        }
        bool same = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] != b[i][j]){
                    same = false;
                    break;
                }
            }
            if(same == false){
                break;
            }
        }
        if(same){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}