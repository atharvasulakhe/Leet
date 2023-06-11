//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
static bool cmp(pair<int,int>a, pair<int,int>b){
    return a.second < b.second;
}
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,int>>v;
        for(int i=0;i<N;i++){
            pair<int,int> p=make_pair(i,F[i]);
            v.push_back(p);
        }
        vector<int>ans;
        sort(v.begin(),v.end(),cmp);
        int ansend=v[0].second;
        ans.push_back(v[0].first +1);
        for(int i=1;i<N;i++){
            if(S[v[i].first] > ansend){
                ans.push_back(v[i].first+1);
                ansend=v[i].second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends