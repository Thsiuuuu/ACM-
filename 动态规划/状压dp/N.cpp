#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>


using namespace std;


#define int long long

string s;


//这个题不是状压dp
// 但是可以采用位运算的方法进行优化


/*
这个题直接用爆搜会超时，尽管剪枝了（）

然后仔细一想，这个二维是互不干扰的，
所以可以分别处理x y轴，看看能不能到这个点
然后讨论奇偶数的关系，可以得出什么时候走x，y轴
因为一次走方向就确定了，所以相当于把相邻的T之间的F打包
变成一段长度，直接移动代替模拟
因为有两个方向，所以每种情况下有两种子情况

这里可以用bitset进行优化，


*/


/*

int x,y;

int dx=1,dy=1;
bool tri=false;

bool dp[8001][8001];


    // dx,dy表示方向，1为正向，-1反向

    // st表示走到了第几位
    // fnum,tnum分别表示f t的数量




bool check1(int a,int b,int fnum){

    if(fnum<(abs(x-a)+abs(y-b))) return true;
    return false;

}//时刻检查距离进行剪枝

bool check2(int a,int b,int fnum,int tnum){

    if((a!=x||y!=b)&&(!fnum)) return true;
    return false;
}//检查位置


void dfs(int st,int a,int b,int dx,int dy,int fnum,int tnum){


    //cout<<a<<" "<<b<<" "<<dx<<" "<<dy<<"\n";



    if(check2(a,b,fnum,tnum)){
        
        //cout<<"wrong1\n";
        
        return ;//到不了了
    }
    if(!tnum){

        //cout<<"wrong2\n";

         if(!dx&&a!=x) return ;
         if(!dy&&b!=y) return ;
         //检验垂直情况

        if(!dy&&y*dy<0) return;
        if(!dx&&x*dx<0) return ;
    } //转不了了
    if(check1(a,b,fnum)){
        //cout<<"wrong3\n";
        return ;//到不了了
    }
    if(a==x&&b==y){


        //cout<<"tri\n";

        if(st==s.size()){

           // cout<<"true1\n";

            tri=true;
            return ;
        }
        //return ;
    }




    if(tri) return;

    if(s[st]=='F'){
        dfs(st+1,a+dx,b+dy,dx,dy,fnum-1,tnum);
    }else if(s[st]=='T'){
        if(dx){
            dfs(st+1,a,b,0,1,fnum,tnum-1);
            dfs(st+1,a,b,0,-1,fnum,tnum-1);
        }else{
            dfs(st+1,a,b,1,0,fnum,tnum-1);
            dfs(st+1,a,b,-1,0,fnum,tnum-1);
        }
    }

}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>s;
    cin>>x>>y;

    memset(dp,false,sizeof(dp));

    int  fnum=0,tnum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='F'){
            fnum++;
        }else tnum++;
    }

    
    
    
    dfs(0,0,0,1,0,fnum,tnum);
    if(tri) cout<<"Yes";
    else cout<<"No";

    return 0;
}

*/
/*
爆搜超时啦

*/



const int maxn=1e5;

bitset<maxn*2> dpx,dpy;

int x,y,l;

signed main(){

    dpx[maxn]=dpy[maxn]=1;
    cin>>s>>x>>y;
    s+="T";


    int cnt=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='T'){
            if(!cnt) x-=i;
            else if(l){
                if(cnt%2) dpy=dpy<<l|dpy>>l;
                else dpx=dpx<<l|dpx>>l;
            }
            l=0;cnt++;
        }else l++;
    }

    if(dpx[maxn+x]&&dpy[maxn+y]) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}