#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = 0;
        int curr_sum = 0;
        int minLen = INT_MAX;
        while(end < n){
            // cout << end << " " << nums[end] << endl;
            curr_sum += nums[end];
            if(curr_sum < target){
                end++;
            }
            else{
                while(st <= end && curr_sum >= target){
                    minLen = min(minLen, end-st+1);
                    curr_sum -= nums[st];
                    st++;
                }
                
                if(st > end){
                    end = st;
                }
                else{
                    end++;
                }
            }
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};