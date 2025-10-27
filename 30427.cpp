#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;

int N,M;
unordered_map<string,int> id;
unordered_map<int,string> id_to_name;
set<int> house;
int num = 1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    // cin.ignore();

    id_to_name[num] = "bumin";
    id["bumin"] = num++;
    id_to_name[num] = "cake";
    id["cake"] = num++;
    id_to_name[num] = "lawyer";
    id["lawyer"] = num++;

    id_to_name[1005] = "swi";
    id["swi"] = 1005;
    house.insert(1005);
    cin>>N;
    bool flag = false;
    vector<string> sv;
    for(int i = 0;i<N;i++){
        string str;cin>>str;
        if(str == "dongho") flag = true;
        else sv.push_back(str);
    }

    sort(sv.begin(),sv.end());
    for(string & a : sv){
        if(id.find(a) == id.end()){
            id_to_name[num] = a;
            id[a] = num++;
        }
        house.insert(id[a]);
    }

    cin>>M;

    for(int i = 0; i<M;i++){
        string str;
        cin>>str;

        if(id.find(str) != id.end()) 
            house.erase(id[str]);
    }

    if(flag) cout<<"dongho";
    else{
        auto it = house.begin();
        cout<<id_to_name[*it];
    }
    
}