#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    if(N==2) cout<<arr[0];
    else cout<<arr[(N-1)/2];
}