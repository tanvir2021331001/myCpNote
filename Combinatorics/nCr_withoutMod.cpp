unsigned long long nCr(int n, int r) {
    // nCr is the same as nC(n-r)
    if (r > n - r) {
        r = n - r;
    }
    unsigned long long result = 1;
    // Calculate the result using the formula:
    // nCr = n! / (r! * (n-r)!)
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
