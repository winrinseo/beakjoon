#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int d[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N == 0){
        cout<<0;
        return 0;
    }
    for(int i = 0;i<N;i++){
        cin>>d[i];
    }
    
    sort(d , d + N);

    int cut = round((double)N * 3 / 20);
    double answer = 0;
    for(int i = cut;i<N - cut;i++){
        answer += (double)d[i];
    }
    
    cout<<round(answer / (N - cut * 2));;
}