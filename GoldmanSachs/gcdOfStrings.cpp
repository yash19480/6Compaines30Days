#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        if(n < m){
            return gcdOfStrings(str2, str1);
        }
        
        string a = str1+str2;
        string b = str2+str1;
        
        if(a != b) return "";
        
        int len = __gcd(n, m);
        return str2.substr(0, len);
    }
};