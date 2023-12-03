/*
You are given two integers, a and b. Find the minimum value of the expression a&x + b&x, for 1≤x≤ max(a, b).

Note: &represents the bitwise AND operator.

Input:
a = 4, b = 5
Output:
0
Explanation:
Take x = 2
the value of the expression
4&2+5&2=0+0=0

Example 2:
Input:
a = 1, b = 1
Output:2
Explanation: Take x = 1

Your Task:
You don't need to read, input, or print anything. Your task is to complete the function solve(), 
which takes integer a and b as input parameters and returns the minimum possible answer to the problem.

Constraints:
0<=a,b<=10^18
*/ 



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long solve(long long a, long long b) {
        // code here
        long long mx = max(a, b);
        long long x = 1;
        long long mn = LLONG_MAX; // Include <climits> for LLONG_MAX
        while (x <= mx) {
            long long cur = (a & x) + (b & x);
            mn = min(mn, cur);
            x <<= 1;
        }
        return mn;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.solve(a, b) << "\n";
    }
    return 0;
}

// } Driver Code Ends




