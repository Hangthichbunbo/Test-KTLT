#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} diem;

void doc (int *n, char *filename, diem **a) {
    printf("Nhap ten file input: ");
    fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *f = fopen(filename, "r");

    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fscanf(f, "%d\n", n);
    *a = (diem*)malloc(*n * sizeof(diem));

    for(int i = 0; i < *n; i++) {
        fscanf(f, "%d %d\n", &(*a)[i].x, &(*a)[i].y);
    }

    fclose(f);
}

void trongngoai (int *dem_trong, int n, diem *a) {
    float r = 5;
    int dem_ngoai = 0;

    for(int i = 0; i < n; i++) {
        if(sqrt(pow(a[i].x, 2) + pow(a[i].y, 2)) > 5) {
            dem_ngoai++;
        }
        else if(sqrt(pow(a[i].x, 2) + pow(a[i].y, 2)) < 5) {
            (*dem_trong)++;
        }
        else continue;
    }

    printf("So diem nam ngoai la: %d\n", dem_ngoai);
    printf("So diem nam trong la: %d\n", *dem_trong);
}

int gt(int b) {
    int gthua = 1;

    for(int i = 2; i <= b; i++) {
        gthua *= i;
    }

    return gthua;
}

void dtron (int dem_trong, int n, diem *a) {
    int so_doan;

    if(dem_trong < 2) {
        printf("Khong co doan thang nao trong duong tron!");
    }
    else {
        so_doan = gt(dem_trong)/(gt(2)*gt(dem_trong - 2));
        printf("So doan thang nam trong duong tron la: %d\n", so_doan);
    }
}

int main() {
    int n, b;
    char filename[30];
    diem *a;
    int dem_trong = 0;
    
    doc(&n, filename, &a);
    trongngoai(&dem_trong, n, a);
    dtron(dem_trong, n, a);

    return 0;
}