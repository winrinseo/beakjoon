#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N;
int arr[100005];
bool check[250005];
vector<pii> sel;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>arr[i];
        if(check[arr[i]]){
            cout<<0;
            return 0;
        }
        check[arr[i]] = 1;
    }
    sel.reserve(N);
    for(int i = 0;i<N;i++){
        if(arr[i] > N) continue;

        if(sel.empty()){
            sel.push_back({arr[i] , i});
        }else if(sel.back().first < arr[i]){
            if((arr[i] - sel.back().first) != (i - sel.back().second)){
                cout<<0;
                return 0;
            }
        }else if(sel.back().first > arr[i]){
            if((N - sel.back().first + arr[i]) != (i - sel.back().second)){
                cout<<0;
                return 0;
            }
        }
    }
    cout<<1;
}