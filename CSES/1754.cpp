/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/.                   *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.                                   %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@/           (@@@@@@@@@@@@@@@@@@@@@           .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@       &@@@(   (@@@@@@@@@@@@@@@@@@@@@    @@@@,      %@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@,     %@@@@@,       ,@@@@@@@@@@@@@@@@#        @@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@     (@@@@@,     ,@.       &@@@@@@@,       #*      @@@@@@     @@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@#    %@@@@@     (@@@@@@@@/               @@@@@@@@%     @@@@@@     @@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@.    @@@@@     @@@@@@@@@@@@@@@%      *@@@@@@@@@@@@@@@     @@@@@%    @@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@/   ,@@@@(    @@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@&    @@@@@@    @@@@@@@@@@@@@@@@@@
@@@@@@@@@.      @@@@.    @@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@    @@@@@/   (@@@@@@@@@@@@@@@@@
@@@@@@@/    *@@@@@@,   ,@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@    @@@@@              (@@@@@@
@@@@@@@.       /%&%    @@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@   ,@@@@
@@@@@@@@&,                                                                      /@@@@@@@    @(  %@@@
@@@@@@@@@@,  ,@@@@@@,                                          .,*#    &@@@@@@%   @@@@@@@@@@@#  %@@@
@@@@@@@@@@@@         /@@@@.  *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .@@@@@@@@@@(  %@@@@@@@@@   .@@@@
@@@@@@@@@@@@#    (@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   *@@@@@@@@@@@@*             *@@@@@@
@@@@@@@@@/    @@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   ,@@@@@@@@@@@@@   *@@@@@@@@@@@@@@@@@@
@@@@@@&    @@@@@@@@@@@@@#                                      @@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
@@@@*   (@@@@@@@@&*       @@@@@@@@@@@@@&%#((/////((#%&@@@&   @@@@@@@@@@@(    (@@@@@@@@@@@@@@@@@@@@@@
@@@@@&,            .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.  ,@@@@@@@*      @@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pii pair<int, int>
#define vi vector<int>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
int main(){
    faster;
    int c;
    cin>>c;
    while(c--){
        long long a,b;
        cin>>a>>b;
        if(a==0||b==0){
        	if(a==0&&b==0) cout<<"YES"<<'\n';
        	else cout<<"NO"<<'\n';
        	continue;
		}
        if((a+b)%3!=0){
        	cout<<"NO"<<'\n';
        	continue;
		}
	    long long y=b-(a+b)/3 , x=a-(a+b)/3;
	    if(x<0||y<0) cout<<"NO"<<'\n';
	    else if(2*x+y!=a||x+2*y!=b) cout<<"NO"<<'\n';
	    else cout<<"YES"<<'\n';
    } 
}
