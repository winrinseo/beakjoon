#include <iostream>
#include <stack>
#define INF 987654321;

using namespace std;

int N;

int arr[100005];

int l[100005] , r[100005] , m[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>N;

    for(int i = 0;i<N;i++){
        cin>>arr[i];
        m[i] = INF;
    }

    stack<pair<int,int>> s;

    for(int i = 0;i<N;i++){
        if(s.empty()){
            s.push({arr[i] , i + 1});
        }else{


            while(!s.empty() && s.top().first <= arr[i])
                s.pop();
            
            l[i] = s.size();
            if(!s.empty())
                m[i] = abs(m[i] - (i + 1)) <= abs(s.top().second - (i + 1)) ? m[i] : s.top().second;

            s.push({arr[i] , i + 1});
        }
    }

    s = stack<pair<int,int>>();

    for(int i = N-1;i>=0;i--){
        if(s.empty()){
            s.push({arr[i] , i + 1});
        }else{


            while(!s.empty() && s.top().first <= arr[i])
                s.pop();
            
            r[i] = s.size();
            if(!s.empty())
                m[i] = abs(m[i] - (i + 1)) <= abs(s.top().second - (i + 1)) ? m[i] : s.top().second;

            s.push({arr[i] , i + 1});
        }
    }
    


    for(int i = 0;i<N;i++){
        cout<<l[i] + r[i]<<" ";
        if(l[i] + r[i] != 0)
            cout<<m[i];
        cout<<"\n";
    }

}