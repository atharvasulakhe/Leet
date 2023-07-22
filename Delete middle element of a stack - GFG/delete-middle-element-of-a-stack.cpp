//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void recur(stack<int>&s, int size, int curr){
        if(curr==size/2){
            s.pop();
            return;
        }
        
        int n=s.top();
        s.pop();
        
        recur(s,size,curr+1);
        
        s.push(n);
        
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        recur(s,sizeOfStack, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends