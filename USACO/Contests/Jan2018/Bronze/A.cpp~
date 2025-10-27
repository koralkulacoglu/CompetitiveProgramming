#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ofstream cout ("billboard.out");
	ifstream cin ("billboard.in");
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	int base=x2-x1, height=y2-y1;
	if (x1>=x3 && x2<=x4 && y2>=y3 && y1<=y4 && !(y1>y3 && y2<y4)) {
		height -= min(y2, y4) - max(y1, y3);
	}
	if (y1>=y3 && y2<=y4 && x2>=x3 && x1<=x4 && !(x1>x3 && x2<x4)) {
		base -= min(x2, x4) - max(x1, x3);
	}
	cout<<base*height;
}
