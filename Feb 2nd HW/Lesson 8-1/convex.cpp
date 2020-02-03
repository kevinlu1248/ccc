#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

double eps = 1e-8;
int sgn(double x){
    if(x > eps) return 1;
    if(x < -eps) return -1;
    return 0;
}
bool equal(double a, double b){
    // return a == b;//error
    // return fabs(a-b) < eps;
    return sgn(a - b) == 0;
}
bool lt(double a, double b){//less than
    // return a < b;//error
    return a < b - eps;
}
bool le(double a, double b){//less or equal
    // return a <= b;//error
    return a < b + eps;
}
typedef struct Point{
    double x, y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator+(const Point &a)const{
        return Point(x+a.x, y+a.y);
    }
    Point operator-(const Point &a)const{
        return Point(x-a.x, y-a.y);
    }
    double operator*(const Point &a)const{//点积
        return x*a.x + y*a.y;
    }
    double operator^(const Point &a)const{//叉积
        return x*a.y - y*a.x;
    }
    Point transferXY(double a)const{//将当前点绕原点旋转a度（弧度制）
        return Point(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a));
    }
    double dis(const Point &a)const{
        return sqrt((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y));
    }
}Point;

const int N = 1010;
Point list[N];
//极角排序（极点为list[0]）
bool cmp(const Point &a, const Point &b){
    double t = (a - list[0]) ^ (b - list[0]);
    if(sgn(t) > 0) return true;
    else if(sgn(t) == 0)
        if(sgn(list[0].dis(a) - list[0].dis(b))<=0)
            return true;
    return false;
}

vector<Point> convex(int n){
    int k = 0;
    for(int i=1;i<n;i++){
        if(list[k].y > list[i].y || (list[k].y == list[i].y && list[k].x > list[i].x))
            k = i;
    }
    swap(list[k], list[0]);
    sort(list+1, list+n, cmp);
    vector<Point> res;
    res.push_back(list[0]);
    if(n == 1) return res;
    res.push_back(list[1]);
    if(n == 2) return res;
    for(int i=2;i<n;i++){
        while(sgn((res[res.size()-1]-res[res.size()-2])^(list[i]-res[res.size()-2])) <= 0)
            res.pop_back();//pop the last one in res
        res.push_back(list[i]);
    }
    return res;
}

//calculate a pair of points with longest distance
double rotating_calipers(vector<Point> convex){
    //旋转卡壳
    double ans = 0;
    int n = convex.size();
    for(int i=0, j=1;i<n;i++){
        Point t = convex[i] - convex[(i+1)%n];
        while(sgn(t ^ (convex[(j+1)%n]-convex[j])) < 0)
            j = (j+1)%n;
        double dis = max(convex[i].dis(convex[j]), convex[(i+1)%n].dis(convex[(j+1)%n]));
        ans = max(ans, dis);
    }
    return ans;
}

Point outerCenter(Point a, Point b, Point c){
    Point db = b - a;
    double tb = db*db/2;
    Point dc = c - a;
    double tc = dc*dc/2;
    double d = db ^ dc;
    double x = a.x + (tb*dc.y - tc*db.x)/d;
    double y = a.y + (tc*db.y - tb*dc.x)/d;
    return Point(x, y);
}
double overlapOfCircle(Point c1, double r1, Point c2, double r2){
    const double PI = 3.14159265;
    double d = c1.dis(c2);
    if(le(r1 + r2, d)) return 0;
    if(le(d, fabs(r1 - r2))){
        double r = min(r1, r2);
        return r * r * PI;
    }
    double x = (d*d + r1*r1 - r2*r2) / (2*d);
    double t1 = acos(x/r1);
    double t2 = acos(x/r2);
    return r1*r1*t1 + r2*r2*t2 - d*r1*sin(t1);
}