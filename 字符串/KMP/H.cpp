#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*

    有两种情况
    |s|<|t|这个时候没有办法复现，直接输出原字符串即可
    |s|>=|t|,这个时候有多少次复现，取决于有多少组1和0



    漏掉了重复的情况
    比如
    s:101010101010101
    t:101
    这样按照我的构造会出现问题
    那么重新考虑一下
    对于出现重复的位置而言，我们肯定希望接着它再往下走
    那么肯定重复的越长越好
    也就是t的后面一段当做t的前一段，然后再往下延伸
    那么最长的是多少呢，就是最长前后缀长度
    可以用next数组的形成方式进行匹配
*/
int nxt[500010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s,t;
    cin>>s>>t;

    int slen=s.size(),tlen=t.size();
    if(slen<tlen){
        cout<<s;
    }else{

        int s0=0,s1=0;
        for(int i=0;i<slen;i++){
            if(s[i]=='0') s0++;
            else s1++;
        }

        t=" "+t;
        s=" "+s;
        int j=0;
        for(int i=1;i<tlen;i++){
            while(t[j+1]!=t[i+1]&&j) j=nxt[j];
            if(t[j+1]==t[i+1]){
                nxt[i+1]=++j;
            }
        }
        
        int num=1;
        while(s0&&s1){
            if(t[num]=='0'&&s0){
                cout<<0;
                s0--;
                num++;
            }else if(t[num]=='1'&&s1){
                cout<<1;
                s1--;
                num++;
            }

            if(num==tlen+1){
                num=nxt[tlen];
                num++;
            }
        }

        for(int i=0;i<s0;i++){
            cout<<0;
        }
        for(int i=0;i<s1;i++){
            cout<<1;
        }
    }
    return 0;
}