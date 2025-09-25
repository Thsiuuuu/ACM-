#include <algorithm>
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;


const double eps=1e-8;
const int N=1e5+10;
struct Point{
    double x,y;

    Point(double x_=0,double y_=0) :x(x_),y(y_){}
}o,e,p[3];

double R;

/*

    注意外积方向一定不要写反!!!

*/

Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

double operator&(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}

Point operator*(Point a,double t){
    return Point(a.x*t,a.y*t);
}

double operator*(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

Point operator/(Point a,double t){
    return Point(a.x/t,a.y/t);
}

Point rotate(Point a,double b){
    return Point(a.x*cos(b)-a.y*sin(b),a.y*cos(b)+a.x*sin(b));
}

double len(Point a){
    return sqrt(a.x*a.x+a.y*a.y);
}

Point norm(Point a){
    return a/len(a);
}

bool onSegment(Point p,Point a,Point b){
    return fabs((a-p)*(b-p))<eps&&((a-p)&(b-p))<=0;
}

Point getNode(Point a,Point u,Point b,Point v){
    double t=(a-b)*v/(v*u);
    return a+u*t;
}

double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}



double getDP2(Point a,Point b,Point& pa,Point&pb){
    Point e=getNode(a,b-a,o,rotate(b-a,(acos(-1.0))/2));//求垂足
    double d=dis(o,e);
    if(!onSegment(e,a,b)) d=min(dis(o,a),dis(o,b));
    if(R<=d) return d;
    double len=sqrt(R*R-dis(o,e)*dis(o,e));
    pa=e+norm(a-b)*len;
    pb=e+norm(b-a)*len;
    return d;
}//返回点到线段最短距离，同时更新线段与圆的交点（如果存在的话）

double sector(Point a,Point b){
    double angle=acos((a&b)/len(a)/len(b));
    if(a*b<0) angle=-angle;//这个如果是顺时针，就把它变成负的角度，因为都是逆时针方向扫为正
    return R*R*angle/2;
}//求两个向量范围内 的扇形的面积

double getArea(Point a,Point b){
    if(fabs(a*b)<eps) return 0;
    double da=dis(o,a),db=dis(o,b);
    if(R>=da&&R>=db) return a*b/2;//ab在圆内
    Point pa,pb;
    double d=getDP2(a,b,pa,pb);
    if(R<=d) return sector(a,b);//ab都在圆外
    if(R>=da) return a*pb/2+sector(pb,b);//a在圆内
    if(R>=db) return pa*b/2+sector(a,pa);//b在圆内
    return sector(a,pa)+pa*pb/2+sector(pb,b);//ab是割线
}//求面积

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&o.x,&o.y,&R)!=-1){
        for(int i=0;i<3;i++){
            p[i].x-=o.x,p[i].y-=o.y;//平移
        }
        o=Point(0,0);
        double res=0;
        for(int i=0;i<3;i++){
            res+=getArea(p[i],p[(i+1)%3]);
        }
        printf("%.2lf\n",fabs(res));
    }
    return 0;
}

