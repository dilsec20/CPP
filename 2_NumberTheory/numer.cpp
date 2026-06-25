#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> v = {"a==b","b!=a"};

    for(int i = 0; i<v.size(); i++){
        string s = v[i];
        sort(s.begin(), s.end());
        v[i] = s;
    }

    for(auto x : v){
        cout<<x<<" ";
    }
    return 0;
}