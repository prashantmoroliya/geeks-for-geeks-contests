/*
There are N people standing in a row, you are given a string s of length N where s[i] = '1' if ith person is infected with a virus and s[i]= '0' if not infected. Given K, ith person can infect up to K people on his left side and up to K people on his right side.
Find the total number of people who are infected with the virus.

Example 1:
Input:
s = "00100100"
K = 1
Output:
6
Explanation: Both third and sixth person
can infect one person on their left side
and one on their right side.

Example 2:
Input:
s = "0010100"
K = 1
Output:
5
Explanation: Third person can infect one person on his left side and one on his right side. Fifth person can infect one person on his right side, the person on the left side of fifth person already got infected by the third person.

Your Task: You don't need to read input or print anything. Your task is to complete the function virusinfection() which takes the string s and integer K as input parameters and returns the total number of people who are infected with the virus.

Constraints:
1 <= |s| <=2*10^5
1 <= K <= 2*10^5
*/ 



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(string s, int K){
        // code here
        int n = s.length();
        vector<int> potential_infections(n, 0);

        // Count potential infections for each person
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                int left = max(0, i - K);
                int right = min(n - 1, i + K);
                potential_infections[left]++;
                if (right + 1 < n)  // Avoid out-of-range access
                    potential_infections[right + 1]--;
            }
        }

        // Calculate actual infections
        int infected = 0, total_infected = 0;
        for (int i = 0; i < n; ++i) {
            infected += potential_infections[i];
            if (infected > 0)
                total_infected++;
        }

        return total_infected;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.solve(s, K) << "\n";
    }
}
// } Driver Code Ends





