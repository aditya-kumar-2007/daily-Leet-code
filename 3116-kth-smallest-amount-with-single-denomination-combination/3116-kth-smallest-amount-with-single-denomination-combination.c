long long gcd(long long a,long long b){
    while(b){
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

long long findKthSmallest(int* c,int n,long long k){
    long long l=1,r=(long long)c[0]*k;

    while(l<r){
        long long x=(l+r)/2,cnt=0;

        for(int mask=1;mask<(1<<n);mask++){
            long long L=1;
            int bits=0;

            for(int i=0;i<n;i++)
                if(mask&(1<<i)){
                    bits++;
                    L=L/gcd(L,c[i])*c[i];

                    if(L>x) break;
                }

            if(L<=x){
                if(bits&1) cnt+=x/L;
                else cnt-=x/L;
            }
        }

        if(cnt>=k) r=x;
        else l=x+1;
    }

    return l;
}