#include <iostream>
#include <string>
using namespace std;
string p;
int vow,con;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vow |= 1<<('a'-'a');
    vow |= 1<<('e'-'a');
    vow |= 1<<('i'-'a');
    vow |= 1<<('o'-'a');
    vow |= 1<<('u'-'a');
    con = ~vow;
    while(1){
        cin>>p;

        if(p == "end") break;

        int acVow = 0;
        int vowCnt = 0;
        int conCnt = 0;

        bool accept = true;

        for(int i = 0;i<p.size();i++){
            //모음인경우
            if((vow & 1 << (p[i] - 'a'))){
                acVow |= 1 << (p[i] - 'a');
                vowCnt++;
                conCnt = 0;
            }else{
                conCnt++;
                vowCnt = 0;
            }

            //같은 글자 체크
            if(i > 0 && p[i-1] == p[i]){
                accept = false;
                if(p[i] == 'e' || p[i] == 'o')
                    accept = true;
            }

            if(vowCnt >= 3 || conCnt >= 3)
                accept = false;
            
            if(!accept) break;
        }
        if(acVow && accept){
            cout<<"<"<<p<<">"<<" is acceptable."<<"\n";
        }else{
            cout<<"<"<<p<<">"<<" is not acceptable."<<"\n";
        }
    }
}