bool checkDivisibility(int n) {
    int t = n, sum = 0, product = 1;

    while (t) {
        int d = t % 10;
        sum += d;
        product *= d;
        t /= 10;
    }

    return n % (sum + product) == 0;
}