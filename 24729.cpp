#include <iostream>

using namespace std;
int N;
int arr[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    
    int _min = 100005;
    int _max = -1;
    for(int i = 0;i<N;i++){
        int a;cin>>a;
        _min = min(_min,a);
        _max = max(_max,a);
        arr[a]++;
    }
    if(_min == _max){
        cout<<-1;
        return 0;
    }
    for(int i = _min; i < _max;i++){
        arr[i+1] -= arr[i];
        if(i+1 != _max && arr[i+1] <= 0){
            cout<<-1;
            return 0;
        }
        if(i+1 == _max && arr[i+1] != 0){
            cout<<-1;
            return 0;
        }
    }
    cout<<1;

}