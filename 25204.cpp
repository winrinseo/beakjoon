#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T,N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--){
        cin>>N;

        vector<string> v;

        for(int i = 0;i<N;i++){
            string a;cin>>a;
            v.push_back(a);
        }

        sort(v.begin(),v.end(),[](string & a,string & b){
            int size = min(a.size() , b.size());

            for(int i = 0;i<size;i++){

                if(a[i] != b[i]){
                    if(a[i] == '-')
                        return false;
                    
                    if(b[i] == '-')
                        return true;

                    if(tolower(a[i]) == tolower(b[i])){
                        return a[i] < b[i];
                    }

                    if(a[i] != b[i]){
                        return tolower(a[i]) < tolower(b[i]);
                    }

                    
                }
            }


            return a.size() < b.size();
        });


        for(int i = 0;i<N;i++){
            cout<<v[i]<<"\n";
        }
    }
}