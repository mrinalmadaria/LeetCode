//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if (n == 1) return "1";
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string current;
            int count = 1;
            for (int j = 1; j < prev.size(); ++j) {
                if (prev[j] == prev[j-1]) {
                    ++count;
                } else {
                    current += to_string(count) + prev[j-1];
                    count = 1;
                }
            }
            current += to_string(count) + prev.back();
            prev = current;
        }
        return prev;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends