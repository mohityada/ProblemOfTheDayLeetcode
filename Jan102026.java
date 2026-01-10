class Jan102026 {

    // int solve(String s1, String s2,  int n, int m, int[][] dp){
        
    //     if(dp[n][m] != 0) return dp[n][m];

    //     if(n == 0){
    //         int rem = 0;
    //         for(int x = 0; x < m; x++) rem += (int)s2.charAt(x);
    //         return rem;
    //     }
    //     if(m == 0){
    //         int rem = 0;
    //         for(int x = 0; x < n; x++) rem += (int)s1.charAt(x);
            
    //         return rem;
    //     }   

    //     if(s1.charAt(n-1) == s2.charAt(m-1)){
    //         return dp[n][m] = solve(s1, s2, n-1, m-1, dp);
    //     } else{
    //         int op1 = solve(s1, s2, n-1, m, dp) + (int)s1.charAt(n-1);

    //         int op2 = solve(s1, s2, n, m-1, dp) + (int)s2.charAt(m-1);
    //         return dp[n][m] = Math.min(op1, op2);
    //     }
    // }
    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int dp[][] = new int[n][m];
        
        int rem1 = 0;
        boolean lastS2 = false, lastS1 = false;
        for(int x = n-1; x >= 0; x--) {
            if(s1.charAt(x) == s2.charAt(m-1)) lastS2 = true;
            rem1 += (int)s1.charAt(x);
            if(lastS2) dp[x][m-1] = rem1 - (int)s2.charAt(m-1);
            else dp[x][m-1] = rem1 + (int)s2.charAt(m-1);
        }
        int rem2 = 0;
        for(int x = m-1; x >= 0; x--){
            if(s2.charAt(x) == s1.charAt(n-1)) lastS1 = true;
            rem2 += (int)s2.charAt(x);          
            if(lastS1) dp[n-1][x] = rem2 - (int)s1.charAt(n-1);
            else dp[n-1][x] = rem2 + (int)s1.charAt(n-1);
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                char c1 = s1.charAt(i);
                char c2 = s2.charAt(j);
                if(c1 == c2){
                    dp[i][j] = dp[i+1][j+1];
                } else{
                    int op1 = dp[i][j+1] + (int)c2;
                    int op2 = dp[i+1][j] + (int)c1;
                    dp[i][j] = Math.min(op1, op2);
                }
            }
        }    
        return dp[0][0];
    }
}
