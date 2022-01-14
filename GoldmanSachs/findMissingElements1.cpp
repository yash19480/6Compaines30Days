#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* x = new int[2];
        
        int missing = 0;
        int repeating = 0;
        
        int XOR = 0;
        
        for(int i=0; i<n; i++){
            XOR ^= (arr[i]^(i+1));
        }
        
        int set_bit = XOR & ~(XOR-1);
        
        int a = 0;
        int b = 0;
        for(int i=0; i<n; i++){
            if((arr[i] & set_bit)!= 0){
                a ^= arr[i];
            }
            else{
                b ^= arr[i];
            }
            
            if(((i+1) & set_bit) != 0){
                a ^= (i+1);
            }
            else{
                b ^= (i+1);
            }
        }
        int tmp_cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == a) tmp_cnt++;
        }
        
        if(tmp_cnt == 0){
            x[0] = b;
            x[1] = a;
        }
        else{
            x[0] = a;
            x[1] = b;
        }
        return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends