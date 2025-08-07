#include <iostream>
#include <vector>
using namespace std;

int N,A,B;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>A>>B;

    if(A + B - 1 > N){
        cout<<-1;
        return 0;
    }
    int h = 0;


    if(A < B){
        if(A == 1){
            for(int i = B;i >= 1; i--){
                v.push_back(i);
            }
        }else{
            for(int i = 1;i<A;i++){
                v.push_back(i);
            }
            for(int i = B;i >= 1; i--){
                v.push_back(i);
            }
        }
    }else if(A >= B){
        if(B == 1){
            for(int i = 1;i <= A; i++){
                v.push_back(i);
            }
        }else{
            for(int i = 1;i<=A;i++){
                v.push_back(i);
            }
            for(int i = B - 1;i >= 1; i--){
                v.push_back(i);
            }
        }
    }
    
    //모자라면 1 삽입
    if(A + B - 1 < N){
        int diff = N - (A + B - 1);
        cout<<v[0]<<" ";

        for(int i = 0;i<diff;i++){
            cout<<1<<" ";
        }
        for(int i = 1; i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }else{
        for(int i = 0; i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    
    
}