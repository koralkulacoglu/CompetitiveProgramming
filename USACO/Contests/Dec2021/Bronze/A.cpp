#include <iostream>
using namespace std;

int main() {
	int n, g=0, h=0;
	long long ans=0;
	cin>>n;
	string c;
	cin>>c;
	for (int s=0; s<n-2; s++) {
		g=0;h=0;
		g += (c[s]=='G');
		g += (c[s+1]=='G');
		g += (c[s+2]=='G');
		h += (c[s]=='H');
		h += (c[s+1]=='H');
		h += (c[s+2]=='H');
		ans += (g==1 || h==1);
		for (int e=s+3; e<n; e++) {
			g += (c[e]=='G');
			h += (c[e]=='H');
			ans += (g==1 || h==1);
			if (g>1 && h>1) break;
		}
	}
	cout<<ans;
}


