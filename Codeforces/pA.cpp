 #include<iostream>
 using namespace std;
 int main(){
 	int a;
 	cin>>a;
 	for(int i=0;i<a;i++){
 		int n;
 		cin>>n;
  		int t=2;
 		while(n>t){
 			t=t*2;
		}
		if(n==t){
			cout<<n-1<<endl;
		}
		else{
			t=t/2;
			cout<<t-1<<endl;
		}		
	 }
 }
