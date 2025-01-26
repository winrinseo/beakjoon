#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> p;
unordered_map<int , string> id;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<N;i++){
        string a;
        int sc;
        cin>>a>>sc;
        p.push_back(sc);
        id[i] = a;
    }

    //이분탐색
    
    for(int i = 0;i<M;i++){

        int power; cin>>power;

        int lo = 0 , hi = N-1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            //해당 칭호를 사용할 수 있다면
            if(power <= p[mid]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        cout<<id[lo]<<"\n";

    }
    
}