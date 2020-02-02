#include <cmath>
#include <cstdio>
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

typedef struct Segment{
    Point s, e;
    Segment(Point s, Point e):s(s.x,s.y), e(e.x,e.y){}
    //作为直线，直线的交点
    //第一个返回值表示直线位置关系，0表示重合，1表示平行，2表示相交，当且仅当为2时，第二个返回值是交点
    pair<int, Point> cross(const Segment &a)const{
        if(sgn((s-e)^(a.s-a.e)) == 0){
            if(sgn((s-a.e)^(a.s-e)) == 0)
                return make_pair(0, Point());//重合
            return make_pair(1, Point());//平行
        }
        Point res;
        double t = ((s-a.s) ^ (a.s-a.e)) / ((s-e) ^ (a.s-a.e));
        res.x = s.x + t*(e.x-s.x);//t*e.x + (1-t)*s.x
        res.y = s.y + t*(e.y-s.y);//t*e.y + (1-t)*s.y
        return make_pair(2, res);
    }
    //作为线段，判断两条线段是否相交
    bool inter(const Segment &a)const{
        return
        max(s.x, e.x) >= min(a.s.x, a.e.x) &&
        max(s.y, e.y) >= min(a.s.y, a.e.y) &&
        max(a.s.x, a.e.x) >= min(s.x, e.x) && 
        max(a.s.y, a.e.y) >= min(s.y, e.y) && 
        sgn((s-a.e)^(a.s-a.e))*sgn((e-a.e)^(a.s-a.e)) <= 0 &&
        sgn((a.s-e)^(s-e))*sgn((a.e-e)^(s-e)) <= 0;
    }
    //点到直线距离，返回垂线段的垂足
    Point dis(const Point &p)const{
        Point res;
        double t = ((p-s)*(e-s))/((e-s)*(e-s));
        res.x = s.x + t*(e.x-s.x);//t*e.x + (1-t)*s.x
        res.y = s.y + t*(e.y-s.y);//t*e.y + (1-t)*s.y
        return res;
    }
}Segment;

//多边形面积
double area(vector<Point> ps){
    double res = 0;
    for(int i=0;i<ps.size();i++)
        res += ps[i]^ps[(i+1)%ps.size()];
    return res / 2;
}
//判断一个点是否在线段上
bool OnSegment(Point p, Segment L){
    return sgn((L.s-p) ^ (L.e-p)) == 0 &&
    sgn((p.x-L.s.x) * (p.x-L.e.x)) <= 0 &&
    sgn((p.y-L.s.y) * (p.y-L.e.y)) <= 0;
}
//判断一个点是否在凸多边形内
//0表示在边界上，-1表示在外部，1表示在内部
int checkInConvexPolygon(Point a, vector<Point> ps){
    for(int i=0;i<ps.size();i++){
        int j = (i+1)%ps.size(); // j = i + 1
        if(sgn((ps[i]-a)^(ps[j]-a)) < 0) return -1;
        else if(OnSegment(a, Segment(ps[i], ps[j]))) return 0;
    }
    return 1;
}
//判断多边形是否是凸多边形
//ps可能是顺时针可能是逆时针
bool isConvex(vector<Point> ps){
    bool res[3];
    res[0] = res[1] = res[2] = false;
    for(int i=0;i<ps.size();i++){
        int j = (i+1)%ps.size(); // j = i + 1
        int k = (j+1)%ps.size(); // k = i + 2
        res[sgn((ps[j]-ps[i])^(ps[k]-ps[i])) + 1]=true;
        if(res[0] && res[2]) return false;
    }
    return true;
}




