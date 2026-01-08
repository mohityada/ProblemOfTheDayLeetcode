class Jan082026 {
public:
    // int mdp(vector<int>& num1, vector<int>& num2, int i, int j, int n, int m){
    //     if(i == n - 1 || j == m - 1) return num1[i]*num2[j];

    //     int op1 = num1[i]*num2[j] + mdp(num1, num2, i+1, j+1, n, m);
    //     int op2 = mdp(num1, num2, i, j+1, n, m);
    //     int op3 = mdp(num1, num2, i+1, j, n, m);

    //     return max(op1, max(op2, op3));
    // }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int dp[n][m];
        dp[n-1][m-1] = a[n-1]*b[m-1];

        for(int i = n-2; i >= 0; i--){
            dp[i][m-1] = max(dp[i+1][m-1], a[i]*b[m-1]);
        }
        for(int i = m-2; i >= 0; i--){
            dp[n-1][i] = max(dp[n-1][i+1], a[n-1]*b[i]);
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                dp[i][j] = max(a[i]*b[j] + (dp[i+1][j+1] > 0 ? dp[i+1][j+1] : 0), max(dp[i][j+1], dp[i+1][j]));
            }
        }
        return dp[0][0];        
    }
};
