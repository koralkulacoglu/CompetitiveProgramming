#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream cout ("moobuzz.out");
	ifstream cin ("moobuzz.in");
	
	int n;
	cin>>n;
	int cn=n%8, moos=n/8*6+(n+1)/9;

	if (cn==7) {
		moos += 6;
	}
	else if (cn==6) {
		moos += 5;
	}
	else if (cn==5 || cn==4) {
		moos += 3;
	}
	else if (cn==3) {
		moos += 1;
	}
	cout<<n+moos;
}
