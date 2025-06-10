#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char hten[30], quequan[30], hocluc;
} sinhvien;

void doc(int *n, FILE **f, sinhvien **a) {
    *f = fopen("sv.txt", "r");
    fscanf(*f, "%d\n", n);

    *a = (sinhvien*)malloc(*n * sizeof(sinhvien));

    for(int i = 0; i < *n; i++){
        fgets((*a)[i].hten, 30, *f);
        (*a)[i].hten[strcspn((*a)[i].hten, "\n")] = '\0';
        fgets((*a)[i].quequan, 30, *f);
        (*a)[i].quequan[strcspn((*a)[i].quequan, "\n")] = '\0';
        fscanf(*f, "%c\n", &(*a)[i].hocluc);
    }

    fclose(*f);
}

void inds(int n, sinhvien *a) {
    printf("%-30s%-20s%10s\n", "Ho ten", "Que quan", "Hoc luc");
    for(int i = 0;  i < n; i++) {
        printf("%-30s%-30s%10c\n",a[i].hten, a[i].quequan, a[i].hocluc);
    }
}

void thongke(int n, sinhvien *a) {
    int dema = 0, demb = 0, demc = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].hocluc == 'A') {
            dema++;
        }
        else if(a[i].hocluc == 'B') {
            demb++;
        }
        else {
            demc++;
        }
    }

    printf("So sinh vien co hoc luc A, B, C la: %d %d %d", dema, demb, demc);
}

void timkiem(int n, sinhvien *a) {
    char tentim[30];
    printf("\nNhap ten can tim: ");
    fgets(tentim, 30, stdin);
    tentim[strlen(tentim) - 1] = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].hten, tentim) == 0) {
            printf("Que quan: %s\t Hoc luc: %c", a[i].quequan, a[i].hocluc);
        }
    }
}


int main () {
    FILE *f;
    int n;
    sinhvien *a;

    doc(&n, &f, &a);

    inds(n, a);

    thongke(n, a);

    timkiem(n, a);

    return 0;
}