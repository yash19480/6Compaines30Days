#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.size();
        stack<string> st;
        int curr = 1;
        string res = "";
        for(int i=0; i<n; i++){
            if(S[i] == 'I'){
                st.push(to_string(curr));
                while(!st.empty()){
                    res = res + st.top() ;
                    st.pop();
                }
            }
            else{
                st.push(to_string(curr));
            }
            curr++;
        }
        st.push(to_string(curr));
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends