int stoneGameII(int* p, int n) {
    int dp[101][101] = {0}, s[101] = {0};

    for(int i=n-1;i>=0;i--)
     s[i]=s[i+1]+p[i];
     for(int i=n-1;i>=0;i--)
     for(int m=n;m>=1;m--) {
        for(int x=1;x<=2*m && i+x<=n;x++) {
            int v=s[i]-dp[i+x][m>x?m:x];
            if(v>dp[i][m]) dp[i][m]=v;
            }
        }

    return dp[0][1];
}