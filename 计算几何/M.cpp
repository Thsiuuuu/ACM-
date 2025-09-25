#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

/*

    其实不用凸包，因为凸包会改变它的形状

*/

const int N=1e5+10;
struct Point{
    double x,y;
    Point(double a=0,double b=0):x(a),y(b){}
    bool operator<(const Point&w) const{
        return x!=w.x?x<w.x:y<w.y;
    }
}p[N],stk[N];

int n,top;
double b;
Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,double t){
    return Point (a.x*t,a.y*t);
}

double operator*(Point a,Point b){
    return (a.x*b.x+a.y*b.y);
}

double operator%(Point a,Point b){
    return (a.x*b.y-a.y*b.x);
}

double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

void Andrew(){
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        while(top>1&&cross(stk[top-1],stk[top],p[i])<=0) top--;
        stk[++top]=p[i];
    }

    int t=top;
    for(int i=n-1;i>=1;i--){
        while(top>t&&cross(stk[top-1],stk[top],p[i])<=0) top--;
        stk[++top]=p[i];
    }
}

int main(){
    scanf("%d%lf",&n,&b);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }

    // Andrew();
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=(p[i]%p[(i+1)%n]);
    }
    printf("%.4lf",fabs(sum*b)/2);
    return 0;
}