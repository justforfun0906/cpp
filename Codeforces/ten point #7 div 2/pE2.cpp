#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	
	int q;
	
	cin >> q;
	
	int wa = 0;
	
	while(q--)
	{
		string input;
		
		cin >> input;
		
		if( input == "WA" )
		{
			wa++;
		}
		else if( wa > 0 )
		{
			wa--;
		}
	}
	
	cout << wa << "\n";
	
	return 0;
} 
