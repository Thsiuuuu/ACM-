#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e5+10;

struct Point{
    double x,y;
}a[N],b[N];

/*

    这个题就是从前往后依次遍历，如果一个木棍跟他后面的木棍不相交的话，就是顶层木棍
    这里用叉积判断是不是相交

*/

int n,ans[N],cnt;

double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool intersect(int i,int j){
    if(cross(a[i],b[i],a[j])*cross(a[i],b[i],b[j])>0) return 0;
    if(cross(a[j],b[j],a[i])*cross(a[j],b[j],b[i])>0) return 0;
    return 1;
}

void solve(){
    printf("Top sticks: "); cnt=0;
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=i+1;j<=n;j++){
            if(intersect(i,j)){
                flag=1;
                break;
            }
        }
        if(!flag) ans[++cnt]=i;
    }
    for(int i=1;i<cnt;i++){
        printf("%d, ",ans[i]);
    }
    printf("%d",ans[cnt]);
    puts(".");
}

int main(){
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
        }
        solve();
    }
    return 0;
}