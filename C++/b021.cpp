#include<iostream>
#include<algorithm>
using namespace std;
struct point{
	int index;
	int chinese;
	int english;
	int math;
	int physics;
	int chemistry;
	int sum;
};
bool cpr(point s1,point s2){
	if(s1.sum!=s2.sum){
		return s1.sum>s2.sum;
	}
	else{
		return s1.math>s2.math;
	}
}
int main(){
	int n;
	cin>>n;
	point pt[n];
	for(int i=0;i<n;i++){
		cin>>pt[i].index>>pt[i].chinese>>pt[i].english>>pt[i].math>>pt[i].physics>>pt[i].chemistry;
	}
	for(int i=0;i<n;i++){
		pt[i].sum=pt[i].chinese+pt[i].english+pt[i].math+pt[i].physics+pt[i].chemistry;
	}
	sort(pt,pt+n,cpr);
	for(int i=0;i<n;i++){
		cout<<pt[i].index<<endl;
	}
}
