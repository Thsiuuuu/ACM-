#include <iostream>
#include <algorithm>

using namespace std;

/*

    求出每个障碍物投到视线上的左右端点，然后用叉积求交点
    跑一遍区间合并，最后维护右端点即可
*/

const int N=1e5+4;
int cnt,n;
struct Point{
    double x,y;

    Point(double x_=0,double y_=0): x(x_),y(y_){}//传参，然后直接初始化成员变量，用括号内的东西初始化括号左边变量 
    
    bool operator<(const Point&w) const{
        if(x!=w.x){
            return x<w.x;
        }
        return y<w.y;
    }
}L1,L2,H1,H2,B1,B2,a[N];

Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,double t){
    return Point(a.x*t,a.y*t);
}

double operator*(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}//叉积，两个向量形式的


double getNode(Point a,Point u,Point b,Point v){
    double t=(a-b)*v/(v*u);
    Point p=a+u*t;
    if(p.x>L2.x) p.x=L2.x;
    if(p.x<L1.x) p.x=L1.x;
    return p.x;
}



int main(){
    while(scanf("%lf%lf%lf",&H1.x,&H2.x,&H1.y),H1.x&&H2.x&&H1.y){
        H2.y=H1.y;
        scanf("%lf%lf%lf",&L1.x,&L2.x,&L1.y); L2.y=L1.y;
        scanf("%d",&n); cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf",&B1.x,&B2.x,&B1.y); B2.y=B1.y;
            if(B1.y<L1.y||B1.y>H1.y) continue;//障碍物在房子上边或者观察线下边
            a[cnt].x=getNode(H2,B1-H2,L1,L2-L1);
            a[cnt++].y=getNode(H1,B2-H1,L1,L2-L1);//x和y分别代表左右端点，这里传参一三位置是点，二四位置是每个点所在直线的方向向量
        }
        sort(a,a+cnt);
        double ans=max(a[0].x-L1.x,L2.x-a[cnt-1].y);
        double r=a[0].y;
        for(int i=1;i<cnt;i++){
            if(a[i].x>r){
                ans=max(ans,a[i].x-r);
            }
            r=max(r,a[i].y);
        }
        if(!cnt){
            ans=L2.x-L1.x;
        }
        if(!ans){
            printf("No View\n");
        }else{
            printf("%.2f\n",ans);
        }
    }
    return 0;
}