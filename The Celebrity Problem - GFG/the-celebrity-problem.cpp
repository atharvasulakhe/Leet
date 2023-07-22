//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        int i=0,j=n-1;
        while(i<j){
            if(M[j][i]==1){//j knows i
                j--;
            } 
            else i++; //j dosnt know i so i cant be celebrity
        }
        
        int celeb=i;
        for(int i=0;i<n;i++){
            if(i!=celeb){
                if(M[celeb][i]==1 || M[i][celeb]==0) return -1;
            } 
        }
        return celeb;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends