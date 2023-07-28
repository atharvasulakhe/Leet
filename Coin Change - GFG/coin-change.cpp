//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   long long recur(int coins[], int N, int sum, int ind,vector<vector<long long>>&dp){
      
//       if(ind==0){
//           if(sum%coins[0]==0) return 1;
//           else return 0;
//       }
//       //if(ind<0) return 0;
//       if(dp[ind][sum]!=-1) return dp[ind][sum];
//       int nottake= recur(coins,N,sum,ind-1,dp);
//       int take=0;
//       if(coins[ind]<=sum) take= recur(coins,N,sum-coins[ind],ind,dp);
      
//       return dp[ind][sum]= take+nottake;
//   }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>>dp(N,vector<long long>(sum+1,0));
        // long long int ans= recur(coins,N,sum, N-1,dp);
        
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=sum;j++){
                long long nottake= dp[i-1][j];
                long long take=0;
                if(coins[i]<=j) take= dp[i][j-coins[i]];
                
                dp[i][j]=take+nottake;
            }
        }
        return dp[N-1][sum];
        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends