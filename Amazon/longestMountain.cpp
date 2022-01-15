#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        int i =0;
        int maxLen = 0;
        
        while(i < n-1){
            //found the starting of a mountain
            if(i < n-1 && arr[i] < arr[i+1]){
                int slope1 = 0;
                int slope2 = 0;
                while(i < n-1 && arr[i] < arr[i+1]){
                    i++;
                    slope1++;
                }
                
                while(i < n-1 && arr[i] > arr[i+1]){
                    i++;
                    slope2++;
                }
                
                if(slope2 == 0){
                    continue;
                }
                
                maxLen = max(maxLen, slope1+slope2+1);
            }
            else{
                i++;    
            }
        }
        
        return maxLen;
    }
};