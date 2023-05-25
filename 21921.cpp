#include <iostream>

using namespace std;
int N,X;
int p[250005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X;

    for(int i = 0;i<N;i++){
        cin>>p[i];
    }

    int i;
    int sum = 0;
    int max = 0;
    int c = 1;
    for(i = 0;i<X;i++)
        sum += p[i];
    
    max = sum;
    for(; i<N; i++){
        sum += p[i];
        sum -= p[i-X];

        if(sum > max){
            max = sum;
            c = 1;
        }else if(sum == max){
            c++;
        }
    }
    if(max == 0){
        cout<<"SAD";
    }else{
        cout<<max<<"\n"<<c;
    }
}