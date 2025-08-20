#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int N;

list<char> word[25];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i = 0; i<N;i++){
        string a;
        cin>>a;
        for(int j = 0;j<a.size();j++){
            word[i].push_back(a[j]);
        }
    }

    
    string answer;
    while(true){
        

        sort(word , word + N , [](list<char> & a , list<char> & b){

            for(auto i = a.begin(), j = b.begin();
                i != a.end() && j != b.end();
                i++,j++
                ){
                    if(*i != *j)
                        return *i < *j;
                }
            return a.size() > b.size();
        });
        if(word[0].begin() == word[0].end()) break;
        answer.push_back(word[0].front());
        word[0].erase(word[0].begin());
    }

    cout<<answer;
}