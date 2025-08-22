#include <iostream>

using namespace std;
int m[3][3];

int check(){
    for(int i = 0;i<3;i++){
        if( m[i][0] == m[i][1] && m[i][1] == m[i][2]){
            if(m[i][0] == 1 ||m[i][0] == 2)
                return m[i][0];
        }
        
    }

    for(int i = 0;i<3;i++){
        if( m[0][i] == m[1][i] && m[1][i] == m[2][i]){
            if(m[0][i] == 1 || m[0][i] == 2)
                return m[0][i];
        }
    }

    if( m[0][0] == m[1][1] && m[1][1] == m[2][2]){
            if(m[0][0] == 1 || m[0][0] == 2)
                return m[0][0];
        }

    if( m[0][2] == m[1][1] && m[1][1] == m[2][0]){
            if(m[0][2] == 1 || m[0][2] == 2)
                return m[0][2];
        }

    return 0;
}

// -1 x , 1 o
int game(int turn){
    int result = check();
    // cout<<result;
    if(result != 0){
        if(turn == -1){
            if(result == 1)
                return -1;
            else return 1;
        }else{
            if(result == 2)
                return 1;
            else return -1;
        }
    }

    int ret = turn == -1 ? 2 : -2;

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(m[i][j] == 0){
                if(turn == -1){
                    m[i][j] = 1;
                    ret = min(ret , game(turn * -1));
                    m[i][j] = 0;
                }else if(turn == 1){
                    m[i][j] = 2;
                    ret = max(ret , game(turn * -1));
                    m[i][j] = 0;
                }
            }
        }
    }

    if(ret == 2 || ret == -2)
        return 0;
    return ret;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x = 0;
    int y = 0;
    for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++){
            cin>>m[i][j];
            if(m[i][j] == 1){
                x++;
            }else if(m[i][j] == 2){
                y++;
            }
        }
    int ret = 0;
    
    if(x > y){
        // o 차례
        ret = game(1);
        
        if(ret == -1){
            cout<<"L";
        }else if(ret == 1){
            cout<<"W";
        }else{
            cout<<"D";
        }
    }else{
        // x 차례
        ret = game(-1);

        if(ret == 1){
            cout<<"L";
        }else if(ret == -1){
            cout<<"W";
        }else{
            cout<<"D";
        }
    }

}