char* smallestSubsequence(char* s) {
    int l[26], v[26]={0}, t=-1;
    char st[1001];

    for(int i=0;s[i];i++) l[s[i]-'a']=i;

    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(v[c]) continue;
        while(t>=0 && st[t]>s[i] && l[st[t]-'a']>i)
            v[st[t--]-'a']=0;
        st[++t]=s[i];
        v[c]=1;
    }

    st[++t]=0;
    return strdup(st);
}