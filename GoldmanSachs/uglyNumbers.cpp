#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
	    
	    dp[1] = 1;
	    
	    ull p1=1, p2=1, p3=1;
	    
	    for(int i=2; i<=n; i++){
	        ull f1 = 2*dp[p1];
	        ull f2 = 3*dp[p2];
	        ull f3 = 5*dp[p3];
	        
	        dp[i] = min({f1, f2, f3});
	        
	        if(dp[i] == f1) p1++;
	        if(dp[i] == f2) p2++;
	        if(dp[i] == f3) p3++;
	    }
	    
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends