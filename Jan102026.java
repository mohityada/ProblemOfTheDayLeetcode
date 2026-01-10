class Jan102026 {

    int solve(String s1, String s2,  int n, int m, int[][] dp){
        
        if(dp[n][m] != 0) return dp[n][m];

        if(n == 0){
            int rem = 0;
            for(int x = 0; x < m; x++) rem += (int)s2.charAt(x);
            return rem;
        }
        if(m == 0){
            int rem = 0;
            for(int x = 0; x < n; x++) rem += (int)s1.charAt(x);
            
            return rem;
        }   

        if(s1.charAt(n-1) == s2.charAt(m-1)){
            return dp[n][m] = solve(s1, s2, n-1, m-1, dp);
        } else{
            int op1 = solve(s1, s2, n-1, m, dp) + (int)s1.charAt(n-1);

            int op2 = solve(s1, s2, n, m-1, dp) + (int)s2.charAt(m-1);
            return dp[n][m] = Math.min(op1, op2);
        }
    }
    public int minimumDeleteSum(String s1, String s2) {
        int dp[][] = new int[s1.length() + 1][s2.length() + 1];

        // for(int i = n-1; i >= 0; i--){
        //     for(int j = m-1; j >= 0; j--){

        //     }
        // }    

        return solve(s1, s2, s1.length(), s2.length(), dp);
    }
}
