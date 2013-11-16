#include <iostream>

int main(int argc, char** argv) {

    int cases;
    long long int n, k, result, j;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        scanf("%lld %lld", &n, &k);
        n = n - 1;
        k = k - 1;
        if (k > n / 2)
            k = n - k;
        result = 1;
        for (j = 1; j <= k; j++) {
            result = (result * (n - j + 1)) / (j);
        }
        printf("%lld\n", result);
    }
    return 0;
}
