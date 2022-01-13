#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n%2 != 0) return false;
        
        map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]%k] ++;
        }
        
        for(auto x : mp){
            int num = x.first;
            int cnt = x.second;
            int req = (k-num)%k ;
            // cout << num << " " << cnt << " " << req << " " << mp[req] << endl;
            if(req == num){
                if(cnt%2 != 0) return false;
            }
            else{
                if(cnt != mp[req]) return false; 
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends