#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int t;
	cin>> t ;
	
	while(t--){
		queue<int> q; 
		vector<int> v = {1};
		int n , fuck = 1;
		cin >> n;
		int a[n];
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i=2;i<=n;i++){
			q.push(i);
		}
		for(int i=0 ; i<n ; i++){
			int shit = 1 ;
			if(!v.empty() and a[i] == v.back() ){
				v.pop_back() ;
			}
			else{
				while(q.size()){
					if(a[i] == q.front()){
						q.pop() ;
						shit = 0 ;
						break ;
					}
					else{
						v.push_back(q.front()) ;
						q.pop() ;
					}
				}
				if(shit){
					cout << "No" << endl ;
					fuck = 0 ;
					break ; 
				}
				
			}
			//for(int i=0;i<v.size();i++){
			//	cout << v[i];
			//}
			//	cout << endl ; 
		}
		if(fuck){
			cout << "Yes" << endl ;
		}
	}
} 
