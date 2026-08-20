int* resultArray(int* n, int s, int* r) {
    int *a=malloc(s*4),*b=malloc(s*4),*c=malloc(s*4),x=0,y=0,k=0;
    a[x++]=n[0]; b[y++]=n[1];

    for(int i=2;i<s;i++)
        if(a[x-1]>b[y-1]) a[x++]=n[i];
        else b[y++]=n[i];

    for(int i=0;i<x;i++) c[k++]=a[i];
    for(int i=0;i<y;i++) c[k++]=b[i];

    *r=s;
    free(a); free(b);
    return c;
}