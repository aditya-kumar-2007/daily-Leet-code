int maxSubarrayLength(int* a, int n, int k) {
    int key[200003], val[200003] = {0};
    int l = 0, ans = 0;

    for (int i = 0; i < 200003; i++) key[i] = -1;

    for (int r = 0; r < n; r++) {
        int x = a[r], h = (x % 200003 + 200003) % 200003;

        while (key[h] != -1 && key[h] != x)
            h = (h + 1) % 200003;

        if (key[h] == -1) key[h] = x;
        val[h]++;

        while (val[h] > k) {
            int y = a[l++], p = (y % 200003 + 200003) % 200003;

            while (key[p] != y)
                p = (p + 1) % 200003;

            val[p]--;
        }

        if (r - l + 1 > ans)
            ans = r - l + 1;
    }

    return ans;
}