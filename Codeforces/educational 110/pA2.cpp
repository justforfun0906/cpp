#include <iostream>
using namespace std;

int main(){
	int R=0,C=0,i,j,a=0,k;
	cin>>R>>C;
	//歸零並擴大方形
	int Team[R+2][C+2]={ };
	
	//臨時替代役 
	int S[R+2][C+2]={ };   
	
	//輸入陣列 
	for(i=1;i<(R+1);i++)
	  for(j=1;j<(C+1);j++)
	  cin>>Team[i][j];
	
	//內格驗證，逐一比對，再度較正
	for(i=1;i<(R+1);i++)     
	  for(j=1;j<(C+1);j++){
	  if (Team[i][j]==0){
	     k=4;
	     
	     if(Team[i][j-1]==0)  //上下左右驗證 
	     k=k-1;
	     else
	     a=a+Team[i][j-1];
	     
	     if(Team[i][j+1]==0)
	     k=k-1;
	     else
	     a=a+Team[i][j+1];
	     
	     if(Team[i-1][j]==0)
	     k=k-1;
	     else
	     a=a+Team[i-1][j];
	     
	     if(Team[i+1][j]==0)
	     k=k-1;
	     else
	     a=a+Team[i+1][j];
	     
	     if(k)
	     S[i][j]=(a/k);
      }
    }  
    
	//把替代役叫回去 
    for(i=1;i<(R+1);i++)
	  for(j=1;j<(C+1);j++){
      if (S[i][j])
      Team[i][j]=S[i][j];
}

	//輸出陣列 
	for(i=1;i<(R+1);i++){
	  for(j=1;j<(C+1);j++)
	  cout<<Team[i][j]<<" ";
	cout<<endl;
    } 
	
	
	return 0;
}
