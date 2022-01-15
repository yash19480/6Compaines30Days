// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here
        vector<vector<int>> dp(k+1, vector<int>(n,0));
        
        for(int i=1; i<=k; i++){
            int x = INT_MIN;
            for(int j=1; j<n; j++){
                x = max(x, dp[i-1][j-1] - A[j-1]);
                dp[i][j] = max(dp[i][j-1], x + A[j]);
            }
        }
        
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends