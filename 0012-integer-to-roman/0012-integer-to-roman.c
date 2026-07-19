char* intToRoman(int num) {
    int v[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char *ans=malloc(20),*p=ans;
    ans[0]=0;

    for(int i=0;i<13;i++)
        while(num>=v[i]){
            strcpy(p,r[i]);
            p+=strlen(r[i]);
            num-=v[i];
        }

    *p=0;
    return ans;
}