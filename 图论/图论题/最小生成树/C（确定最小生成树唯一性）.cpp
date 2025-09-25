#include <iostream>
#include <algorithm>

using namespace std;


#define int long long 


/*
    这里判断最小生成树唯一性
    什么时候不唯一，就是在合并两个联通块的时候有权值相同的边
    因此我们检验权值相同的边会不会合并相同的联通块
    或者换句话说，
    如果所有权值相同的所有边都可以被放进去，那么他们端点一定分属于不同的联通块
    如果真正放进去的边，小于所有的边，那么一定有至少两条边是负责合并相同联通块的，这时候一定不唯一
*/

struct edge{
    int u,v;
    int val;
};

int f[110];
edge e[10010];

bool cmp(const edge&a,const edge&b){
    return a.val<b.val;
}

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=m;i++){
            cin>>e[i].u>>e[i].v>>e[i].val;
        }
        sort(e+1,e+1+m,cmp);
        int num=0,ans=0,tail=0,sum1=0,sum2=0;
        bool flag=true;
        for(int i=1;i<=m+1;i++){
            if(i>tail){
                if(sum1!=sum2){
                    flag=false;
                    break;
                }
                sum1=0;
                for(int j=i;j<=m+1;j++){
                    if(j>m||e[j].val!=e[i].val){
                        tail=j-1;
                        break;
                    }
                    if(find(e[j].u)!=find(e[j].v)) sum1++;

                }
                sum2=0;
            }
            if(i>m){
                break;
            }
                int x=find(e[i].u);
                int y=find(e[i].v);
                if(x!=y&&num!=n-1){
                    sum2++;
                    num++;
                    f[x]=f[y];
                    ans+=e[i].val;
                }

        }
        if(flag) cout<<ans<<"\n";
        else cout<<"Not Unique!\n";
    }
    return 0;
}