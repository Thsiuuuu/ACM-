#include <iostream>
#include <algorithm>


using namespace std;

struct Point{
    int x,y;
    
    Point(int x_=0,int y_=0):x(x_),y(y_){}

    bool operator<(const Point&w) const{
        if(x!=w.x){
            return x<w.x;
        }
        return y<w.y;
    }

}p[110];
int n;

/*

    求一个多边形面积，从原点想每个多边形的临近两点连线即可
    逆时针或者顺时针选定方向都可以，最后取绝对值并/2即可，注意一个方向最后一个点到出发点的面积也要计算

*/
Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);

}
Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,int t){
    return Point(a.x*t,a.y*t);
}

int operator*(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}

int operator%(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

int len(Point a){
    return sqrt(a.x*a.x+a.y*a.y);
}

int dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }

    int sum=0;

    for(int i=0;i<=n-1;i++){
        sum+=(p[i]%p[(i+1)%n]);
    }

    sum=abs(sum);
    cout<<0.5*sum;

    return 0;
}
