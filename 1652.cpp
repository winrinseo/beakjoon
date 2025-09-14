#include <iostream>

using namespace std;

int N;
string m[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>m[i];
    }

    int r = 0, c = 0;
    
    for(int i = 0;i<N;i++){
        int sequence = 0;

        for(int j = 0;j<N;j++){
            if(m[i][j] == '.') sequence++;
            if(m[i][j] == 'X'){
                if(sequence >= 2) r++;
                sequence = 0;
            }
        }
        if(sequence >= 2) r++;
    }

    for(int i = 0;i<N;i++){
        int sequence = 0;

        for(int j = 0;j<N;j++){
            if(m[j][i] == '.') sequence++;
            if(m[j][i] == 'X'){
                if(sequence >= 2) c++;
                sequence = 0;
            }
        }
        if(sequence >= 2) c++;
    }
    cout<<r<<" "<<c;
}