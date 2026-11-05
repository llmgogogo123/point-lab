#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Point {
public:
	double x, y;

	Point(double x0,double y0) {
		x = x0;
		y = y0;
	}
	
};
class Line{
    public:
    Point a;
    Point b;
    Line(Point p1,Point p2): a(p1), b(p2){}
    double length(){
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
};
int main() {
	vector<Point> q;
	q.push_back(Point(2.5, 4.2));
	q.push_back(Point(3.2, 4.5));
	q.push_back(Point(0, 0));
	q.push_back(Point(2, 0));
	q.push_back(Point(2, 3));
	double xh = 0, yh = 0;
	for (const auto& pt : q) {
		xh += pt.x;
		yh += pt.y;
	}
	double t = q.size();
	cout << xh / t << ',' << yh / t << endl;
    Line l(Point(1,1),Point(0,0));
    double res=l.length();
    cout<<res<<endl;
	return 0;
}