#include <iostream>
#include <map>
using namespace std;
map<string,int> com;
int kr,kc,sr,sc;
int N;
int d[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string kk,ss; cin>>kk>>ss;
    cin>>N;
    kr = kk[1] - '0';
    kc = kk[0] - 'A' + 1;

    sr = ss[1] - '0';
    sc = ss[0] - 'A' + 1;
    
    com["R"] = 0, com["L"] = 1,com["B"] = 2,com["T"] = 3,
    com["RT"] = 4,com["LT"] = 5,com["RB"] = 6,com["LB"] = 7;


    for(int i = 0;i<N;i++){
        string c;cin>>c;
        int dir = com[c];
        //킹 먼저 움직임
        int nkr = kr + d[dir][0];
        int nkc = kc + d[dir][1];

        if(nkr < 1 || nkr > 8 || nkc < 1 || nkc > 8)
            continue;
        
        //겹친경우 돌움직임
        if(nkr == sr && nkc == sc){
            int nsr = sr + d[dir][0];
            int nsc = sc + d[dir][1];

            if(nsr < 1 || nsr > 8 || nsc < 1 || nsc > 8)
                continue;
            sr = nsr; 
            sc = nsc;
        }
        kr = nkr;
        kc = nkc;
    }
    cout<<char(kc-1+'A')<<kr<<"\n"<<char(sc-1+'A')<<sr;
}