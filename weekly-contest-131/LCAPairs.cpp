/*
LCA Pairs
You are given a connected tree of N nodes numbered from 0 to N-1 rooted at the 0th node, where p[i] is the parent of the ith node and p[0] = -1 as the 0th node is the root.
Calculate the numbers of pairs of nodes (a,b) 0 <= a< N, a <= b < N such that LCA(a,b) = x, for each x where 0 < x < N.
The LCA or lowest common ancestor between two nodes a and b is defined as the lowest node in tree that has both a and b as descendants (where we allow a node to be a descendant of itself). 

Example 1:
Input:
N = 3
P[] = [-1, 0, 0]
Output: [4, 1, 1]
Explanation: The structure of tree is:
0 
/\
1 2
For LCA = 0, we have 4 pairs (0,0), (0,1), (0,2), (1,2)
For LCA = 1, we have only 1 pair (1,1)
For LCA = 2, we have only 1 pair (2,2)

Example 2:
Input:
N = 5
P[] = [-1, 0, 0, 1, 1]
Output: [8, 4, 1, 1, 1]
Explanation: The structure of tree is
0
/\
1 2
/\
3 4
For LCA = 0, we have 8 pairs (0,0), (0,1), (0,2),(0,3),(0,4),(1,2),(2,3),(2,4)
For LCA = 1, we have 4 pairs (1,1), (1,3), (1,4),(3,4)
FOR LCA = 2, we have only 1 pair (2,2).
FOR LCA = 3, we have only 1 pair (3,3) 
For LCA = 4, we have only 1 pair (4,4)

Your Task:
Your task is to complete the function calcPairs() which takes the integer N and a list pl] of size N as input parameters and returns a list of N elements a0, a1... aN-1 where ai is the the number of unordered pairs for which Ica(a,b) = i, where 0<=a<N, a<=b<N

Constraints: 
1<=N<=10^5
0≤ p[i] < N where 0 < i < N
p[0]=-1
*/



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution 
{
    public:
    void dfs(vector<int> adj[], vector<long long> &ans, vector<long long> &size, int node){
        long long sub = 1;
        for(auto it: adj[node]){
            dfs(adj,ans,size,it);
            ans[node]+=size[it]*sub;
            sub+=size[it];
        }
        size[node] = sub;
    }
	
	vector<long long>calcPairs(int N, vector<int> p) {
	    // Code here
	    vector<int> adj[N];
        for(int i=1; i<N; i++){
            adj[p[i]].push_back(i);
        }
        vector<long long> ans(N,1);
        vector<long long> size(N,0);
        dfs(adj,ans,size,0);
        return ans;
	}
};


//{ Driver Code Starts.

int main()
{

    int t;
	cin >>t ;
    while(t--)
    {
        int V;
    	cin >> V ;

    	vector<int> par(V) ;
        for(int  i = 0 ; i < V ; ++i) {
            cin >> par[i] ;
        }
        Solution obj;
        vector<long long>ans=obj.calcPairs(V, par);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends



