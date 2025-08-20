#include <iostream>


using namespace std;

int N;

string a,b,c;
bool compair(string & a, string & b , int & h , int & j , int & s){

    for(int i = 0;i<N;i++){
        int a0 , b0;
        if(a[i] == 'H')
            a0 = h;
        else if(a[i] == 'J')
            a0 = j;
        else if(a[i] == 'S')
            a0 = s;

        if(b[i] == 'H')
            b0 = h;
        else if(b[i] == 'J')
            b0 = j;
        else if(b[i] == 'S')
            b0 = s;
       
        if(a0 < b0) return true;
        else if(a0 > b0)return false;
    }
    return false;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>a>>b>>c;

    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            if(i == j) continue;
            for(int k = 1;k<=3;k++){
                if(i == k || j == k) continue;
                if(compair(a , b , i, j,k) && compair(b , c , i, j, k)){
                    
                    cout<<"HJS! HJS! HJS!";
                    return 0;
                }

            }   
        }   
    }

    cout<<"Hmm...";
}