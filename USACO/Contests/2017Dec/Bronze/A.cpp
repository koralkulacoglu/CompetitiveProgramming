#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream cout ("billboard.out");
	ifstream cin ("billboard.in");
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	int x5,y5,x6,y6;
	cin>>x1>>y1>>x2>>y2;
	cin>>x3>>y3>>x4>>y4;
	cin>>x5>>y5>>x6>>y6;
	int a1 = (x2-x1)*(y2-y1);
	int a2 = (x4-x3)*(y4-y3);

	int i1,i2;
	if (x5>x2 || x6<x1 || y5>y2 || y6<y1) {
		i1 = 0;
	} else {
		int l1;
		int w1;
		if (x5>=x1) {
			l1 = (x2<x6?x2:x6)-x5;
		} else {
			l1 = (x6<x2?x6:x2)-x1;
		}
		if (y5>=y1) {
			w1 = (y2<y6?y2:y6)-y5;
		} else {
			w1 = (y6<y2?y6:y2)-y1;
		}
		i1 = l1*w1;
	}
	if (x5>x4 || x6<x3 || y5>y4 || y6<y3) {
		i2 = 0;
	} else {
		int l2;
		int w2;
		if (x5>=x3) {
			l2 = (x4<x6?x4:x6)-x5;
		} else {
			l2 = (x6<x4?x6:x4)-x3;
		}
		if (y5>=y3) {
			w2 = (y4<y6?y4:y6)-y5;
		} else {
			w2 = (y6<y4?y6:y4)-y3;
		}
		i2 = l2*w2;
	}
	cout<<a1+a2-i1-i2<<endl;
}

