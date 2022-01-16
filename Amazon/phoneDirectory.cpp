// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int len = s.size();
        vector<vector<string>> res;
        string prefix = "";
        for(int i=0; i<s.size(); i++){
            prefix += s[i];
            
            //now, we will search the contact array for prefix values;
            set<string> st;
            vector<string> sol;
            for(int j=0; j<n; j++){
                string substr = contact[j].substr(0,prefix.size());
                // cout << prefix << "  " << substr << endl;
                if(substr == prefix){
                    st.insert(contact[j]);
                }
            }
            
            if(st.empty()){
                sol.push_back("0");
            }
            else{
                for(auto str : st) {
                    sol.push_back(str);
                }
            }
            res.push_back(sol);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends