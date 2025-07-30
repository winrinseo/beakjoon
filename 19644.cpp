// #include <iostream>

// using namespace std;
// int L , M , D , B;
// int seg[12000005];
// int z[3000005];
// //배열의 크기 재배정, L보다 큰 2^n
// int H = 1;
// void update(int k){//k번째 수를 1로 변경
//     k += H;
//     seg[k] = 1;
//     k>>=1;
//     for(;k != 0;k>>=1){
//         seg[k] = seg[k<<1] + seg[k<<1 | 1];
//     }
// }
// //구간합 반환
// int sum(int idx , int st , int ed , int l , int r){
//     if(l <= st && ed <= r)
//         return seg[idx];
//     if(r < st || ed < l)
//         return 0;

//     int mid = (st + ed)/2;

//     return sum(idx * 2 , st , mid , l , r) + sum(idx * 2 + 1 , mid+1 , ed , l , r);
// }

// int sum(int l,int r){
//     return sum(1,0,H - 1, l , r);
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>L>>M>>D>>B;

//     for(int i = 1; i<=L;i++)
//         cin>>z[i];

//     //
//     while(H < L) H<<=1;

//     for(int t = 1;t<=L;t++){
//         int turn = t-1;
//         //바로 앞의 좀비에게 기관총이 누적된 횟수 + 1
//         int d = (sum(max( 0 , t - M ), turn ) + 1) * D;
//         if(z[t] - d <= 0){
//             update(turn);
//         }else if(B){
//             B--;
//         }else{
//             cout<<"NO";
//             return 0;
//         }
//     }

//     cout<<"YES";
// }



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