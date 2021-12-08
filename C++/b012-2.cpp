#include <iostream>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;

  
int main(){  
    char a[100];  
    cin>>a;
	int n=strlen(a); 
    int b[n];  
    for(int i=0;i<n;i++)  
    {  
        switch(a[i])  
        {  
            case 'I':  b[i]=1;  break;
            case 'V':  b[i]=5;  break;
            case 'X':  b[i]=10; break;
            case 'L':  b[i]=50;  break;
            case 'C':  b[i]=100;  break;
            case 'D':  b[i]=500;  break;
            case 'M':  b[i]=1000; break; 
        }  
    }
    int total=0;
    for(int i=0;i<n;i++)
    {
    	if(b[i+1]>b[i]){
			total-=b[i];
		}
		else{
			total+=b[i];
		}
    }
     
	cout<<total;
    return 0;  
}  
  
