#include <iostream>
#include <algorithm>
using namespace std;
int N;
string a;
int solve(int len){
    int cnt[26] = {0};
    int lo = 0,hi = 0;
    int cur = 0;
    for(hi = 0; hi < len; hi++){
        if(++cnt[a[hi]-'a']==1){
            cur++;
        }
    }
    if(cur<=N) return true;
    while(hi < a.size()){
        if(++cnt[a[hi]-'a']==1){
            cur++;
        }
        if(--cnt[a[lo]-'a']==0){
            cur--;
        }
        if(cur<=N) return true;
        hi++,lo++;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>a;
    //투포인터 풀이
    /*int lo = 0,hi = 0;
    int answer = 0;
    int cur = 0;
    while(hi<a.size()){
        if(++cnt[a[hi]-'a']==1){
            cur++;
        }
        while(cur > N){
            if(--cnt[a[lo]-'a']==0){
                cur--;
            }
            lo++;
        }
        answer = max(answer,hi-lo+1);
        hi++;
    }
    cout<<answer;
    */

   //파라메트릭 서치 풀이
   int lo = 0,hi = a.size();
   int answer = 0;
   while(lo<=hi){
       int mid = (lo+hi)/2;
       //부분 문자열의 길이를 mid로 제한했을 때 문자열의 종류가 n이하가 되는가
       if(solve(mid)){
           lo = mid+1;
           answer = mid;
       }else{
           hi = mid-1;
       }
   }
   cout<<answer;
}