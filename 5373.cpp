#include <iostream>
#define U 0
#define D 1
#define F 2
#define B 3
#define L 4
#define R 5
using namespace std;
int T,N;
int refe[6][3][3] = {
    {{0,0,0},{0,0,0},{0,0,0}}, //u w
    {{1,1,1},{1,1,1},{1,1,1}}, //d y
    {{2,2,2},{2,2,2},{2,2,2}}, //f r
    {{3,3,3},{3,3,3},{3,3,3}}, //b o
    {{4,4,4},{4,4,4},{4,4,4}}, //l g
    {{5,5,5},{5,5,5},{5,5,5}}, //r b
};
char color[6] = {'w','y','r','o','g','b'};
int cube[6][3][3];
int temp[6][3][3];

void side_rotate(int face){

    switch (face)
    {
        case U:
        temp[B][0][0] = cube[L][0][0];
        temp[B][0][1] = cube[L][0][1];
        temp[B][0][2] = cube[L][0][2];

        temp[R][0][0] = cube[B][0][0];
        temp[R][0][1] = cube[B][0][1];
        temp[R][0][2] = cube[B][0][2];

        temp[F][0][0] = cube[R][0][0];
        temp[F][0][1] = cube[R][0][1];
        temp[F][0][2] = cube[R][0][2];

        temp[L][0][0] = cube[F][0][0];
        temp[L][0][1] = cube[F][0][1];
        temp[L][0][2] = cube[F][0][2];

        break;

        case D:
        temp[F][2][0] = cube[L][2][0];
        temp[F][2][1] = cube[L][2][1];
        temp[F][2][2] = cube[L][2][2];

        temp[R][2][0] = cube[F][2][0];
        temp[R][2][1] = cube[F][2][1];
        temp[R][2][2] = cube[F][2][2];

        temp[B][2][0] = cube[R][2][0];
        temp[B][2][1] = cube[R][2][1];
        temp[B][2][2] = cube[R][2][2];

        temp[L][2][0] = cube[B][2][0];
        temp[L][2][1] = cube[B][2][1];
        temp[L][2][2] = cube[B][2][2];

        break;

        case F:
        temp[U][2][0] = cube[L][2][2];
        temp[U][2][1] = cube[L][1][2];
        temp[U][2][2] = cube[L][0][2]; 

        temp[R][0][0] = cube[U][2][0];
        temp[R][1][0] = cube[U][2][1];
        temp[R][2][0] = cube[U][2][2];

        temp[D][0][0] = cube[R][2][0];
        temp[D][0][1] = cube[R][1][0];
        temp[D][0][2] = cube[R][0][0];

        temp[L][0][2] = cube[D][0][0];
        temp[L][1][2] = cube[D][0][1];
        temp[L][2][2] = cube[D][0][2];
        break;

        case B:
        temp[D][2][0] = cube[L][0][0];
        temp[D][2][1] = cube[L][1][0];
        temp[D][2][2] = cube[L][2][0]; 

        temp[R][0][2] = cube[D][2][2];
        temp[R][1][2] = cube[D][2][1];
        temp[R][2][2] = cube[D][2][0];
        
        temp[U][0][0] = cube[R][0][2];
        temp[U][0][1] = cube[R][1][2];
        temp[U][0][2] = cube[R][2][2];

        temp[L][2][0] = cube[U][0][0];
        temp[L][1][0] = cube[U][0][1];
        temp[L][0][0] = cube[U][0][2];
        break;

        case L:
        temp[U][0][0] = cube[B][2][2];
        temp[U][1][0] = cube[B][1][2];
        temp[U][2][0] = cube[B][0][2]; 

        temp[F][0][0] = cube[U][0][0];
        temp[F][1][0] = cube[U][1][0];
        temp[F][2][0] = cube[U][2][0];

        temp[D][2][0] = cube[F][2][0];
        temp[D][1][0] = cube[F][1][0];
        temp[D][0][0] = cube[F][0][0];

        temp[B][0][2] = cube[D][2][0];
        temp[B][1][2] = cube[D][1][0];
        temp[B][2][2] = cube[D][0][0];
        break;

        case R:
        temp[U][2][2] = cube[F][2][2];
        temp[U][1][2] = cube[F][1][2];
        temp[U][0][2] = cube[F][0][2];

        temp[B][0][0] = cube[U][2][2];
        temp[B][1][0] = cube[U][1][2];
        temp[B][2][0] = cube[U][0][2];

        temp[D][0][2] = cube[B][2][0];
        temp[D][1][2] = cube[B][1][0];
        temp[D][2][2] = cube[B][0][0];

        temp[F][0][2] = cube[D][0][2];
        temp[F][1][2] = cube[D][1][2];
        temp[F][2][2] = cube[D][2][2];
        break;
    }

    for(int i = 0;i<6;i++){
        for(int j = 0;j<3;j++){
            for(int z = 0;z<3;z++){
                cube[i][j][z] = temp[i][j][z];
            }
        }
    }
}
void rotate(int face,int dir){

    for(int k = 0;k<dir;k++){
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                temp[face][i][j] = cube[face][3-1-j][i];
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                cube[face][i][j] = temp[face][i][j];
            }
        }
    }
    for(int k = 0;k<dir;k++){
        side_rotate(face);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>N;

        for(int i = 0;i<6;i++){
            for(int j = 0;j<3;j++){
                for(int z = 0;z<3;z++){
                    cube[i][j][z] = refe[i][j][z];
                    temp[i][j][z] = refe[i][j][z];
                }
            }
        }

        for(int i = 0;i<N;i++){
            char pos,dir;
            cin>>pos>>dir;
            int rot = dir == '+' ? 1:3;
            if(pos == 'U'){
                rotate(U,rot);
            }else if(pos == 'D'){
                rotate(D,rot);
            }else if(pos == 'F'){
                rotate(F,rot);
            }else if(pos == 'B'){
                rotate(B,rot);
            }else if(pos == 'L'){
                rotate(L,rot);
            }else if(pos == 'R'){
                rotate(R,rot);
            }
        }

        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                cout<<color[cube[U][i][j]];
            }
            cout<<"\n";
        }
    }
}