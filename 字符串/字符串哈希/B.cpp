#include <iostream>
#include <string>

using namespace std;

/*

    根据生日悖论，n个数随机取数，取到相同次数为O(根号n)，所以对mod开根次就大概率造成哈希冲突


*/

int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    srand(time(0));
    cout<<"100000 20\n";
    for(int i=1;i<=1e5;i++){
        cout<<char('a'+rand()%26);
    }
    
    return 0;
}