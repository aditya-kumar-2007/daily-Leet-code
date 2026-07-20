int myAtoi(char *s){
    long x=0;
    int f=1;
    while(*s==' ') s++;
    if(*s=='-'||*s=='+') f=*s++=='-'?-1:1;
    while(*s>='0'&&*s<='9'){
        x=x*10+*s++-'0';
        if(f*x>INT_MAX) return INT_MAX;
        if(f*x<INT_MIN) return INT_MIN;
    }
    return f*x;
}