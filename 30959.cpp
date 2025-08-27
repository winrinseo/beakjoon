#include <iostream>
#include <vector>
using namespace std;

int N,M;
int correct[105];
int predict[20][105];
int _max;
vector<int> comb;
int solve(int cur){
    if(comb.size() == _max){
        vector<int> an;
        for(int i = 0;i<M;i++){
            int p[2] = {0};

            for(int j = 0;j<comb.size();j++)
                p[predict[comb[j]][i]]++;
            
            if(p[0] > p[1]) an.push_back(0);
            else an.push_back(1);
        }

        int ret = 0;
        
        for(int i = 0;i<M;i++){
            if(correct[i] == an[i])
                ret++;
        }
        return ret;
    }

    if(cur == N){
        return 0;
    }


    int ret = solve(cur+1);


    comb.push_back(cur);
    ret = max(ret , solve(cur + 1));
    comb.pop_back();

    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;

    for(int i = 0;i<M;i++)
        cin>>correct[i];

    for(int i = 0; i<N;i++)
        for(int j = 0;j<M;j++)
            cin>>predict[i][j];

    
    _max = 1;

    int m = solve(0);

    
    for(int i = 3;i<=N;i+=2){
        _max = i;
        if(solve(0) > m){
            cout<<1;
            return 0;
        }
    }
    cout<<0;   
}