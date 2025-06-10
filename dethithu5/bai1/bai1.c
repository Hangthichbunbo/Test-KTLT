#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} diem;

void doc(int *n, FILE **f, diem **a, char *filename) {
    printf("Nhap ten tep: ");
    fgets(filename, 30, stdin);
    filename[strlen(filename) - 1] = '\0';

    *f = fopen(filename, "r");
    if(*f == NULL) {
        printf("Loi mo file");
        return;
    }

    fscanf(*f, "%d", n);
    *a = (diem*)malloc(*n * sizeof(diem));

    for(int i= 0; i < *n; i++) {
        fscanf(*f, "%d %d", &(*a)[i].x, &(*a)[i].y);
    }

    fclose(*f);
}

void in(int n, diem *a) {
    printf("Day diem vua doc la\n");
    for(int i= 0; i < n; i++) {
        printf("A[%d] = (%d, %d)\n", i + 1, a[i].x, a[i].y);
    }
}

void xa_goc_toa_do(int n, diem *a) {
    float max = 0, dodai;
    for(int i = 0; i < n; i++) {
        dodai = abs(pow(a[i].x, 2) + pow(a[i].y, 2));
        if(dodai > max) {
            max = dodai;
        }
    }

    printf("Diem xa goc toa do nhat la\n");

    for(int i = 0; i < n; i++) {
        if(max == (abs(pow(a[i].x, 2) + pow(a[i].y, 2)))) {
            printf("A[%d] = (%d, %d)\n", i + 1, a[i].x, a[i].y);
        }
    }
}

int giaithua(int m) {
    int gt = 1;
    for(int i = 1; i < m; i++) {
        gt *= i;
    }
    return gt;
}

void sodoanthang(int n, diem *a) {
    int dem = 0;
    int sodoan;
    for(int i = 0; i < n; i++) {
        if(a[i].x < 0 && a[i].y < 0) {
            dem++;
        }
    }

    if(dem < 2) {
        printf("Khong co doan thang nao nam trong goc phan tu thu 3");
    }
    else {
        sodoan = giaithua(dem)/(giaithua(2)*giaithua(dem - 2));
        printf("So doan thang nam trong goc phan tu thu 3 la: %d", sodoan);
    }
}

int main() {
    FILE *f;
    char filename[30];
    diem *a;
    int n;

    doc(&n, &f, &a, filename);
    in(n, a);
    xa_goc_toa_do(n, a);
    sodoanthang(n, a);

    return 0;
}