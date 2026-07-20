int** shiftGrid(int** g,int m,int* c,int k,int* rs,int** rcs){
    int n=c[0],t=m*n;
    k%=t;
    int **a=malloc(m*sizeof(int*));
    *rcs=malloc(m*sizeof(int));
    *rs=m;
    for(int i=0;i<m;i++) a[i]=malloc(((*rcs)[i]=n)*sizeof(int));
    for(int i=0;i<t;i++)
        a[((i+k)%t)/n][((i+k)%t)%n]=g[i/n][i%n];
    return a;
}