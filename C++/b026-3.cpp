#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int days;
	while(cin>>days){
		int stonks[days],max=0,sum=0;
		for(int i=0; i<days; i++){
			cin>>stonks[i];
		}
		for(int i=0; i<days; i++){
			for(int j=i; j<days; j++){
				sum+=stonks[j];
				if(sum>max) max=sum;
			}
			sum=0;
		}
		cout<<max<<'\n';
	}
	return 0;
}
