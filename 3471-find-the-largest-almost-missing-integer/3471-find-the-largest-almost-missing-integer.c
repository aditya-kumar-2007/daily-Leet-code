int largestInteger(int* a, int n, int k) {
    int ans = -1, i ,j ,c;
    for( i=0; i<n; i++){
        c=0;
        for(j = 0; j <= n-k; j++)
            for(int x = j; x < j+k; x++)
                if(a[x] == a[i]) {
                    c++;
                    break;
                }
      if(c == 1 && a[i] > ans)
        ans = a[i];
    }
    return ans;
}