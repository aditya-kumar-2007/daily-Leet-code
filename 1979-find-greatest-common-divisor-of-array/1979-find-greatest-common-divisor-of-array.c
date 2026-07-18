int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int findGCD(int* nums, int numsSize)
{
    int mn = nums[0], mx = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] < mn)
            mn = nums[i];
        if (nums[i] > mx)
            mx = nums[i];
    }

    return gcd(mn, mx);
}