#include <iostream>
#include <vector>
using namespace std;

int L , M , K , C;
int atk[3000006];
vector<int> z;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>L>>M>>K>>C;
    for(int i = 0;i<L;i++){
        int a; cin>>a;
        z.push_back(a);
    }

    for(int i = 0;i<L;i++){
        int gun = (atk[i] + 1 - atk[max(0 , i + 1 - M)] ) * K;
        if(z[i] - gun > 0){
            if(C == 0){
                cout<<"NO";
                return 0;
            }
            C--;
            atk[i + 1] = atk[i];
        }else{
            atk[i + 1] = atk[i] + 1;
        }
    }

    cout<<"YES";
    return 0;
}