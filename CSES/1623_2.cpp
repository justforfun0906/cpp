#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	sum+=a[i];
	}
    sort(a.begin(),a.end());
    vector<int>find;
    find.push_back(a[0]);
    for(int i=1;i<n;i++){
        int x=a[i];
        int end=find.size();
        for(int j=0;j<end;j++){
            find.push_back(x+find[j]);
        }
    }
    sort(find.begin(),find.end());
    int half=*lower_bound(find.begin(),find.end(),sum/2);
    int first=sum-half;
    cout<<abs(first-half);
}