int minimumPushes(char* word) {
    int ans = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++) {
        ans += (i / 8) + 1;
    }

    return ans;
}