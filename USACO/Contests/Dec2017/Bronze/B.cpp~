#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream cin ("shuffle.in");
	ofstream cout ("shuffle.out");

	int n;
	cin>>n;
	vector<int> cows(n), order(n), ordered(n);
	for (int i=0; i<n; i++) {
		cin>>order[i];
		order[i]--;
	}
	for (int i=0; i<n; i++) {
		cin>>cows[i];
	}
	int cow;
	for (int i=0; i<n; i++) {
		cout<<cows[order[order[order[i]]]]<<'\n';
	}
		
}
