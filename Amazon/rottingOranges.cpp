#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        queue<pair<int, int>> q;
        int n = grid.size(); 
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int,int>> pr = {{0,1},{0,-1},{1,0},{-1,0}};
    
        while(!q.empty()){
            int sz = q.size();
            int i = 0;
            int l = 0;        
            while(i < sz){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                // cout << "x : " << x << " y : " << y << endl;
                for(int i=0; i<4; i++){
                    int nx = x + pr[i].first;
                    int ny = y + pr[i].second;
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        l++;
                    }
                }
                i++;
            }
            if(l != 0) time++;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return time;
    }
};