#include <iostream>

using namespace std;

int N,M;
int arr[200005];
int correct;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>arr[i];
        if(arr[i] == i) {
            correct++;
        }
    }

    cin>>M;


    while(M--){
        
        
        int a,b;cin>>a>>b;
        //이미 올바른 위치
        if(arr[a] == a){
            correct--;
        }

        if(arr[b] == b){
            correct--;
        }

        if(arr[a] == b){
            correct++;
        }

        if(arr[b] == a){
            correct++;
        }

        int temp = arr[b];
        arr[b] = arr[a];
        arr[a] = temp;
        
        if(N == correct){// 교체하고도 정렬이 유지되는지 확인
            cout<<0<<" ";
        }else if(N == 1){
            cout<<0<<" ";
        }else if(N == 2){
            cout<<1<<" ";
        }else{
            cout<<-1<<" ";
        }
    }

}