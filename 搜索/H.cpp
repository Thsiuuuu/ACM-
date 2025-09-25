#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;


/*


    传统的bfs就可以做，然后首尾是目标字符的时候可以进行剪枝
    还是要注意多组输入的初始化问题


*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    
    int t;
    cin>>t;


    while(t--){

        string ori,obj;
        cin>>ori>>obj;

        

        int level=0,siz;

        if(ori==obj){
            cout<<"0\n";
            continue;
        }//注意特判!!!

        queue<string> que;
        set<string> has;


        has.insert(ori);
        que.push(ori);


        while(!que.empty()){

            bool st=false;
            string mod;//每次都是取栈首

            
            level++;
            siz=que.size();

            while(siz--&&(!st)){

                mod=que.front();
                que.pop();//又忘了多组输入一定要清空了!!!

                for(int i=0;i<4;i++){

                    if(mod[i]==obj[i]&&(i==0||i==3)){
                        continue;
                    }//对应字符相同，并且只在首尾的位置上

                    char c=mod[i];
                    if(mod[i]=='9'){
                        mod[i]='1';
                    }else{
                        mod[i]+=1;
                    }//进行加法

                    if(mod==obj){
                        st=true;
                        break;
                    }//加法相等退出

                    if(has.find(mod)==has.end()){
                        has.insert(mod);   
                        que.push(mod);
                    }//统计出没出现过，没出现过再入队列

                    mod[i]=c;//复原
                    if(mod[i]=='1'){
                        mod[i]='9';
                    }else{
                        mod[i]-=1;
                    }//进行减法

                    if(mod==obj){
                        st=true;
                        break;
                    }//减法相等就退出

                    if(has.find(mod)==has.end()){
                        has.insert(mod);
                        que.push(mod);
                    }//没出现过再入队列
                    mod[i]=c;//复原

                    
                    if(st){
                        break;
                    }
                
                }


                string num;
                for(int i=0;i<3;i++){
                    num=mod;
                    char d=num[i];
                    num[i]=num[i+1];
                    num[i+1]=d;
                    if(num==obj){
                      st=true;
                        break;
                    }
                    if(has.find(num)==has.end()){
                        has.insert(num);
                        que.push(num);
                    }
                }//交换和加减法应该是单独进行



                if(st) break;
            }


            if(st){
                cout<<level<<'\n';
                break;
            }


        }
    }

    return 0;

}