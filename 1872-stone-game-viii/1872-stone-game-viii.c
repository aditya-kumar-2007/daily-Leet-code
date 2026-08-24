int stoneGameVIII(int* a, int n){
    long long p[n], ans;
    p[0] = a[0]; 
    for(int i = 1 ; i < n; i++)
    p[i] = p[i-1] + a[i];
    ans = p[n-1];
    for(int i = n-2; i > 0; i--)
    ans = ans > p[i]-ans ? ans : p[i]-ans;
    return ans;   
}