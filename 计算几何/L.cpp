#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=1e5+10;
struct Point{
    double x,y;
    Point(double a=0,double b=0):x(a),y(b){}
    bool operator<(const Point& w)const{
        return x!=w.x?x<w.x:y<w.y;
    }
}p[N],stk[N];

int n,top;
Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,double t){
    return Point(a.x*t,a.y*t);
}
double operator%(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

double operator*(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}

double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Andrew(){
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
        while(top>1&&cross(stk[top-1],stk[top],p[i])<=0) top--;//在栈顶构成有向直线右侧或共线就出栈
        stk[++top]=p[i];
    }//求下凸包

    int t=top;
    for(int i=n-1;i>=1;i--){
        while(top>t&&cross(stk[top-1],stk[top],p[i])<=0) top--;
        stk[++top]=p[i];
    }//求上凸包

    double res=0;
    for(int i=1;i<top;i++){
        res+=dis(stk[i],stk[(i+1)]);
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    printf("%.2lf",Andrew());
    return 0;
}