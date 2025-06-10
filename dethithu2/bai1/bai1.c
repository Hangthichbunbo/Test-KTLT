#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void doc(int *m, int *n, FILE **f, char *filename, int ***a) {
    printf("Nhap ten file input: ");
    fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    *f = fopen(filename, "r");

    fscanf(*f, "%d%d", m, n);
    *a = (int **)malloc(*m * sizeof(int*));

    for(int i = 0; i < *m; i++) {
        (*a)[i] = (int *)malloc(*n*sizeof(int));
    }

    for(int i = 0; i < *m; i++) {
        for(int j = 0; j < *n; j++) {
            fscanf(*f, "%d", &(*a)[i][j]);
        }
    }

    fclose(*f);
}

void am_max(int m, int n, int **a) {
    int max = -999, ktra = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] < 0 && a[i][j] > max) {
                max = a[i][j];
                ktra = 1;
            }
        }
    }

    if(ktra == 1) {
        printf("Gia tri am lon nhat cua ma tran la: %d\n", max);
    }
    else printf("Khong co gia tri am lon nhat\n");
}

void max_cot(int m, int n, int **a) {
    int maxcot[n];
    for(int j = 0; j < n; j++) {
        maxcot[j] = -99;
        for(int i = 0; i < n; i++) {
            if(a[i][j] > maxcot[j]) {
                maxcot[j] = a[i][j];
            }
        }
        printf("Gia tri lon nhat cua cot %d la: %d\n", j + 1, maxcot[j]);
    }
}

void tong_hang(int m, int n, int **a) {
    int tonghang[m];
    for(int i = 0; i < m; i++) {
        tonghang[i] = 0;
        for(int j = 0; j < n; j++) {
            tonghang[i] += a[i][j];
        }
        printf("Tong hang %d la: %d\n", i + 1, tonghang[i]);
    }
}

int main() {
    int m, n;
    FILE *f;
    char filename[30];
    int **a;

    doc(&m, &n, &f, filename, &a);
    am_max(m, n, a);
    max_cot(m, n, a);
    tong_hang(m, n, a);

    return 0;
}