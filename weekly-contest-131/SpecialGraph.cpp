/*
You are given an array A[ ] of N integers. Consider a complete graph of N nodes numbered from 1 to N, where the weight of edge connecting nodes x and y (x!=y) is |x * y-A[x] % A[y] - A[y] % A[x] |. Your task is to find the cost of the minimum spanning tree of this graph.
The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees.

Example 1:
Input:
N = 5
A[] = {1, 3, 5, 5, 1}
Output:
10
Explanation:
One of the minimum spanning tree will be
1
/|\
2 5 3
/
3
Cost will be weight of edge 1 - 2 +
weight of edge 1-4+
weight of edge 1 - 5 +
weight of edge 2 - 3
=1+ 3 + 5 + 1 = 10

Example 2:
Input:
N = 3
A[] = {1, 1, 1}
Output: 5
Explanation:
One of the minimum spanning tree will be
1
/\
3 2
Cost will beweight of edge 1 - 3 +
weight of edge 1 - 2
= 2 + 3 = 5

Your Task:
You don't need to read, input, or print anything. Your task is to complete the function solve(), which takes N and A[] as input parameters and returns the answer to the problem.

Constraints:
1≤ N ≤5*10^4
1 ≤ A[i] ≤N
*/ 


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct UnionFind{
    vector<int> data;
    UnionFind(int size) : data(size,-1){}
    bool unionSet(int x,int y){
        x = root(x); y = root(y);
        if(x!=y){
            if(data[y] < data[x]){swap(x,y);}
            data[x]+=data[y];data[y]=x;
        }
        return (x!=y);
    }
    bool findSet(int x,int y){
        return root(x)==root(y);
    }
    int root(int x){
        return data[x] < 0 ? x : data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};

class Solution {
  public:
  
    long long solve(int N, vector<int> A){
        vector<long long> eg;
        // long long en=0;
        for(long long i=0;i<N;i++){
            for(long long j=i+1;j<N;j++){
                long long c=(i+1)*(j+1);
                if(c > 2ll*N){break;}
                c-=A[i]%A[j];
                c-=A[j]%A[i];
                if(c<0){c*=-1;}
                
                if(c > N){continue;}
                eg.push_back((c<<40) ^ (i<<20) ^ j);
            }
        }
        sort(eg.begin(),eg.end());
        UnionFind uf(N);
        long long res=0,rem=N-1;
        for(auto &nx : eg){
            long long c=(nx>>40);
            nx^=(c<<40);
            long long i=(nx>>20);
            nx^=(i<<20);
            long long j=nx;
            if(!uf.findSet(i,j)){
                uf.unionSet(i,j);
                res+=c;
                rem--;
                if(rem<=0){break;}
            }
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}

// } Driver Code Ends







