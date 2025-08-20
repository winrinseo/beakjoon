#include <iostream>
#include <algorithm>
using namespace std;

int bit[10][3];

bool hop[10][10][10];
bool check[10][10][10];

int N;

int getbit(int num){
    int ret = 0;

    while(num){
        ret += num & 1;
        num >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<9;i++){
        string a,b,c;cin>>a>>b>>c;

        if(a == "CIRCLE"){
            bit[i][0] |= (1<<0);
        }else if(a == "TRIANGLE"){
            bit[i][0] |= (1<<1);
        }else if(a == "SQUARE"){
            bit[i][0] |= (1<<2);
        }

        if(b == "YELLOW"){
            bit[i][1] |= (1<<0);
        }else if(b == "RED"){
            bit[i][1] |= (1<<1);
        }else if(b == "BLUE"){
            bit[i][1] |= (1<<2);
        }

        if(c == "GRAY"){
            bit[i][2] |= (1<<0);
        }else if(c == "WHITE"){
            bit[i][2] |= (1<<1);
        }else if(c == "BLACK"){
            bit[i][2] |= (1<<2);
        }
    }

    int hopcount = 0;

    for(int i = 0;i<9;i++){
        for(int j = i+1;j<9;j++){     
            for(int k = j+1;k<9;k++){
                int flag = true;
                for(int a = 0; a<3;a++){
                    int comb = bit[i][a] | bit[j][a] | bit[k][a];
                    int count = getbit(comb);
                    if(!(count == 3 || count == 1)){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    hop[i][j][k] = 1;
                    hopcount++;
                    
                }

            }
        }
    }

    cin>>N;
    bool g = false;
    int answer = 0;
    for(int i = 0;i<N;i++){
        char c;cin>>c;

        if(c == 'H'){
            int p[3];
            cin>>p[0]>>p[1]>>p[2];
            sort(p , p + 3);
            p[0]--;p[1]--;p[2]--;
            if((!check[p[0]][p[1]][p[2]]) && hop[p[0]][p[1]][p[2]]){
                check[p[0]][p[1]][p[2]] = 1;
                answer += 1;
                hopcount--;
            }else{
                answer -= 1;
            }
        }else{
            if(!g && hopcount <= 0) {
                g = true;
                answer += 3;
            }else answer -= 1;
        }
    }
    cout<<answer;
}