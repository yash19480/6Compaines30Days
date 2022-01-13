#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int st = 0;
        int end = 0;
        long long prod = 1;
        int cnt = 0;
        while(end < n){
            prod *= a[end];
            
            if(prod < k){
                cnt += (end-st+1);
                end++;
            }
            else{
                while(st <= end && prod >= k ){
                    prod /= a[st];
                    st++;
                }
                
                if(st > end){
                    end = st;
                }
                else{
                    cnt += (end-st+1);
                    end++;
                }
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends