
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<char> s1;
        stack<int> s2;
        
        int i = 0;
        int n = s.size(); 
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                int cnt = 0;
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    cnt = 10*cnt + (s[i]-'0');
                
                    i++;
                }
                s2.push(cnt);
            }
            else if(s[i] == ']'){
                string x = "";
                while(!s1.empty() && s1.top() != '['){
                    x = s1.top() + x; s1.pop();
                }
                if(!s1.empty() && s1.top() == '[') s1.pop();
                string fin_x = "";
                
                int cnt =1;
                if(!s2.empty()){
                    cnt = s2.top(); s2.pop();
                }
                for(int j=0; j<cnt; j++){
                    fin_x += x;
                }
                // cout << "fin_x : " << fin_x << endl;
                for(int j=0; j<fin_x.size(); j++){
                    s1.push(fin_x[j]);
                }
                i++;
            }
            else{
                s1.push(s[i++]);
            }
        }
        
        string res = "";
        while(!s1.empty()){
            res = s1.top()+res; s1.pop();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends