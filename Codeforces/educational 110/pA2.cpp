#include <iostream>
using namespace std;

int main(){
	int R=0,C=0,i,j,a=0,k;
	cin>>R>>C;
	//�k�s���X�j���
	int Team[R+2][C+2]={ };
	
	//�{�ɴ��N�� 
	int S[R+2][C+2]={ };   
	
	//��J�}�C 
	for(i=1;i<(R+1);i++)
	  for(j=1;j<(C+1);j++)
	  cin>>Team[i][j];
	
	//�������ҡA�v�@���A�A�׸���
	for(i=1;i<(R+1);i++)     
	  for(j=1;j<(C+1);j++){
	  if (Team[i][j]==0){
	     k=4;
	     
	     if(Team[i][j-1]==0)  //�W�U���k���� 
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
    
	//����N�Хs�^�h 
    for(i=1;i<(R+1);i++)
	  for(j=1;j<(C+1);j++){
      if (S[i][j])
      Team[i][j]=S[i][j];
}

	//��X�}�C 
	for(i=1;i<(R+1);i++){
	  for(j=1;j<(C+1);j++)
	  cout<<Team[i][j]<<" ";
	cout<<endl;
    } 
	
	
	return 0;
}
