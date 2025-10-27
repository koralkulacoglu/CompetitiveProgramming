#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ofstream cout ("mixmilk.out");
	ifstream cin ("mixmilk.in");
	vector<int> c(3), m(3);
	for (int i=0; i<3; i++) {
		cin>>c[i]>>m[i];
	}
	int space;
	for (int i=1; i<=100; i++) {
		space = c[i%3]-m[i%3];
		if (space > m[(i-1)%3]) {
			m[i%3] += m[(i-1)%3];
			m[(i-1)%3] = 0;
		} else {
			m[i%3] = c[i%3];
			m[(i-1)%3] -= space;
		}
	}
	cout<<m[0]<<'\n';
	cout<<m[1]<<'\n';
	cout<<m[2]<<'\n';
}	

