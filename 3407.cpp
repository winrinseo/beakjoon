#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int T;
unordered_set<string> s;
string str;


string c[] = {
    "h", "b", "c", "n", "o", "f", "p", "s", "k", "v", "y", "i", "w", "u",
	"ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
	"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
	"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
	"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
	"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
	"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
	"pu", "ru", "lv", "dy"
	};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0;i<114;i++){
        s.insert(c[i]);
    }


    cin>>T;

    while(T--){
        cin>>str;


        vector<int> dp(str.size() + 1);
        string a;
        a.push_back(str[0]);
        if(s.find(a) != s.end()) dp[0] = 1;

        
        a.push_back(str[1]);
        if(s.find(a) != s.end()) dp[1] = 1;
        

        a.clear();

        a.push_back(str[1]);
        if(s.find(a) != s.end()) dp[1] = max(dp[1] , dp[0]);

        a.clear();


        for(int i = 2;i<str.size();i++){

            // 1글자
            a.push_back(str[i]);

            if(s.find(a) != s.end()){
                dp[i] = max(dp[i] , dp[i-1]);
            }

            // 2글자
            a.push_back(str[i-1]);
            swap(a[0],a[1]);

            if(s.find(a) != s.end()){
                dp[i] = max(dp[i] , dp[i-2]);
            }
            a.clear();
        }
        

        if(dp[str.size() - 1]) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}