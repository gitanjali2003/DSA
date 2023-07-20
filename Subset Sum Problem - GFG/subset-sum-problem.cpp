//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>arr,vector<vector<int>>&dp,int index,int sum,int tempSum)
    {
        if(tempSum == sum)
        {
            return true;
        }
        
        if(index >= arr.size() || tempSum > sum)
        {
            return false;
        }
        
        if(dp[index][tempSum] != -1)
        {
            return dp[index][tempSum];
        }
        
        int inc = solve(arr,dp,index+1,sum,tempSum+arr[index]);
        int exc = solve(arr,dp,index+1,sum,tempSum);
        
        return dp[index][tempSum] = inc || exc;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        
        return solve(arr,dp,0,sum,0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends