#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void doc(int *n, int *m, float **a, float **b) {
    FILE *f = fopen("P.txt", "r");

    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fscanf(f, "%d", n);
    *a = (float *)malloc(*n * sizeof(float));

    for(int i = 0; i < *n; i++) {
        fscanf(f, "%f", &(*a)[i]);
    }

    fclose(f);

    FILE *f1 = fopen("Q.txt", "r");
    
    if(f1 == NULL) {
        printf("Loi mo file!");
        return;
    }

    fscanf(f1, "%d", m);
    *b = (float *)malloc(*m *sizeof(float));

    for(int i = 0; i < *m; i++) {
        fscanf(f1, "%f", &(*b)[i]);
    }

    fclose(f1);

}

void p_q(int n, int m, float *a, float *b) {
    float d1, d2, P1, Q1, gtri;

    printf("Nhap 2 so thuc d1 va d2: ");
    scanf("%f %f", &d1, &d2);

    for(int i = 0; i < n; i++) {
        P1 += a[i]*pow(d1, i);
    }

    for(int i = 0; i < m; i++) {
        Q1 += b[i]*pow(d2, i);
    }

    gtri =  Q1 - Q1;

    printf("Gia tri cua P(d1) - Q(d2) = %.1f", gtri);

}

void hsop_q (int n, int m, float *a, float *b) {
    float c[100];

    if(n  >= m) {
        for(int i = 0; i < m; i++) {
            c[i] = a[i] - b[i];
        }
        for(int i = m; i < n; i++) {
            c[i] = a[i];
        }
    }
    //m >= n;
    else {
        for(int i = 0; i < n; i++) {
            c[i] = a[i] - b[i];
        }
        for(int i = n; i < m; i++) {
            c[i] = - b[i];
        }
    }

    printf("He so cua da thuc P(x) - Q(x) la: \n");
    if(n >= m) {
        for(int i = 0; i < n; i++) {
            printf("%5.1f", c[i]);
        }
    }
    else {
        for(int i = 0; i < m; i++) {
            printf("%5.1f", c[i]);
        }
    }
    
}

int main() {
    int n, m;
    float *a, *b;

    doc(&n, &m, &a, &b);
    p_q(n, m, a, b);
    hsop_q(n, m, a, b);

    return 0;
}