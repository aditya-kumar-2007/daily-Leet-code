#include <stdlib.h>
#include <string.h>

int* validSequence(char*a,char*b,int*n){
 int x=strlen(a),y=strlen(b),p=x-1,q=0,z=0,*s=malloc((y+1)*4),*r=malloc(y*4);
 for(int i=0;i<=y;i++)
 s[i]=-1;
 for(int i=y-1;i>=0;i--){
    while(p>=0&&a[p]!=b[i])p--;
    if(p>=0)s[i]=p--;}
    for(int i=0;i<y;i++){
        if(q<x&&a[q]==b[i])r[i]=q++;
        else if(!z&&q<x&&(i==y-1||s[i+1]>q))z=1,r[i]=q++;
        else{
            while(q<x&&a[q]!=b[i])q++;
            if(q==x){free(s);
            free(r);
            *n=0;
             return 0;}
              r[i]=q++;}
              }
              free(s);*n=y;return r;
}