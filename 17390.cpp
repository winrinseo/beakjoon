#include <iostream>
#include <algorithm>

using namespace std;

int N , M;
int arr[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;

    for(int i = 1;i<=N;i++)
        cin>>arr[i];

    sort(arr + 1 , arr + N + 1);

    for(int i = 1;i<=N;i++)
        arr[i] += arr[i-1];

    
    for(int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;

        cout<<arr[b] - arr[a-1]<<"\n";
    }
}