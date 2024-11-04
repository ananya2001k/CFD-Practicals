#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    float h, k, A, B, Ua, Ub, L, q, Q;
    float a[10], b[10], c[10], d[10], al[10], be[10], x[10];

    printf("Enter the initial and final temperature:\n");
    scanf("%f %f", &Ua, &Ub);
    printf("Enter the length of the rod: \n");
    scanf("%f", &L);
    printf("Enter the thermal conductivity of the rod: \n");
    scanf("%f", &k);
    printf("Enter the cross section area: \n");
    scanf("%f", &A);
    printf("Enter the number of nodal points: \n");
    scanf("%d", &n);
    printf("Enter the value of q: \n");
    scanf("%f", &q);

    h = L / n;
    B = (k * A) / h;
    Q = q * A * h;

    for (i = 2; i <= n; i++) {
        a[i] = -B;
    }
    for (i = 1; i < n; i++) {
        c[i] = -B;
    }
    for (i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            b[i] = 3 * B;
        } else {
            b[i] = 2 * B;
        }
    }
    for (i = 2; i < n; i++) {
        d[i] = Q;
    }
    d[1] = 2 * B * Ua + Q;
    d[n] = 2 * B * Ub + Q;

    // Solution by tridiagonal
    al[1] = b[1];
    be[1] = d[1] / b[1];
    for (i = 2; i <= n; i++) {
        al[i] = b[i] - (a[i] * c[i - 1] / al[i - 1]);
        be[i] = (d[i] - a[i] * be[i - 1]) / al[i];
    }
    x[n] = be[n];
    for (i = n - 1; i >= 1; i--) {
        x[i] = be[i] - (c[i] * x[i + 1]) / al[i];
    }

    printf("The solution of the system is: \n");
    for (i = 1; i <= n; i++) {
        printf("%.2f", x[i]);
        if (i < n) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}