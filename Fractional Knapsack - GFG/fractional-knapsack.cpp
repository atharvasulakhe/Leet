//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<Item,double>p,pair<Item,double>q){
        return p.second>q.second;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<Item,double>>v;
        for(int i=0;i<n;i++){
            
            v.push_back(make_pair(arr[i],1.0*arr[i].value/arr[i].weight));
        }
        sort(v.begin(),v.end(),cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(v[i].first.weight<=W){
                ans+=(double)v[i].first.value;
                W-=v[i].first.weight;
            }
            else{
                ans+=(double)W*v[i].second;
                W=0;
            }
        }
        return ans;

    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends