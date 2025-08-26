
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T, N, X;
unordered_map<int,long long> num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N>>X;
        num.clear();
        
        for(int i = 0;i<N;i++){
            int a;cin>>a;
            num[a]++;
        }

        long long answer = 0;
        for(auto it = num.begin();it!=num.end();it++){
            if(X != 0){
                int target = it->first ^ X;
                if(num.find(target) != num.end()){
                    answer += (it->second * num[target]);
                    it->second = 0;
                }
            }else{
                long long n = it->second - 1;
                long long cnt = n * (1 + n);
                cnt /= 2;
                answer += cnt;
            }
        }

        cout<<answer<<"\n";  
    }
}

/*
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T, N, X;
unordered_map<int,int> endIndex;
int p[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    while(T--){
        cin>>N>>X;
        endIndex.clear();
        for(int i = 0;i < N + 1;i++)
            p[i] = -1;
        
        for(int i = 0;i<N;i++)
            cin>>p[i];
        
        sort(p , p+N);
        int numend = -1;
        for(int i = 0;i<N + 1;i++){
            if(numend != p[i]){
                endIndex[numend] = i;
                numend = p[i];
            }
        }
        long long answer = 0;
        for(int i = 0;i<N-1;i++){
            int target = X ^ p[i];

            int * add = lower_bound(p + i + 1 , p + N , target);
            if(*add == target){
                int idx = add - p;
                answer += (endIndex[p[idx]] - idx);
            }
        }

        cout<<answer<<"\n";
        
    }
}
*/