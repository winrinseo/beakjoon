#include <iostream>
#define pii pair<int,int>
using namespace std;

int X,Y;
int x,y;
int dx,dy;
int dist(pii a, pii b){
    return (b.first - a.first)*(b.first - a.first) + 
                (b.second - a.second) * (b.second - a.second);
}

int gcd(int a , int b){
    while(b!=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>X>>Y;
    cin>>x>>y>>dx>>dy;
    int g = gcd(dx,dy);
    dx /= g;
    dy /= g;
    int m = (1<<30);
    pii answer = {X,Y};
    while(1){

        int d = dist({X,Y}, {x,y});

        if(d < m){
            m = d;
            answer = {x,y};
        }

        x += dx;
        y += dy;

        if(abs(x) > 100 || abs(y) > 100)
            break;
    }

    cout<<answer.first<<" "<<answer.second;
}