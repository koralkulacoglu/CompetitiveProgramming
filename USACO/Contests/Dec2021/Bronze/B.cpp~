#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> target(n), arr(n);
	for (int i=0; i<n; i++) cin>>target[i];
	for (int i=0; i<n; i++) cin>>arr[i];
	for (int i=0; i<n; i++) {
		target[i] = target[i] - arr[i];
	}
	
	int ans=0, prev=0;
	for (int h:target) {
		ans += max(0, h-prev);
		prev = h;
	}
	cout<<ans;
} 
