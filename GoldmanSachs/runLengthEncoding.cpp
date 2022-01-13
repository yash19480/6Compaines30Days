#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  int n = src.size();
  int i =0;
  string x = "";
  while(i < n){
      char c = src[i];
      int cnt = 1;
      int j = i+1;
      while(j < n && src[j] == c){
          cnt++;
          j++;
      }
      x += c;
      x += to_string(cnt);
      i = j;
  }
  
  return x;
}     
 
