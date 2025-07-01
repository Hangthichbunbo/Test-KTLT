#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ht[30], dh;
    float diem;
} ts;

void tongdiem (int n, ts a[]) {
    float diemtong[3] = {0};
    char dh[3] = {'A', 'B', 'C'};

    for(int i = 0; i < n; i++) {
        if(a[i].dh == 'A') {
            diemtong[0] += a[i].diem;
        }

        if(a[i].dh == 'B') {
            diemtong[1] += a[i].diem;
        }

        else {
            diemtong[2] += a[i].diem;
        }
    }

    FILE *f = fopen("output.txt", "a");

    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    for(int i = 0; i < 3; i++) {
        fprintf(f, "\nTong diem cua truong %c la: %.1f\n", dh[i], diemtong[i]);
    }

    float min = 999;

    for(int i = 0; i < 3; i++) {
        if(diemtong[i] < min) {
            min = diemtong[i];
        }
    }

    for(int i = 0; i < 3; i++) {
        if(diemtong[i] == min) {
            fprintf(f, "\nTruong co so diem nho nhat la truong %c\n", dh[i]);
        }
    }

    fclose(f);
}

void diemmax (int n, ts a[]) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j].diem > a[i].diem) {
                ts tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    FILE *f = fopen("output.txt", "a");

    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fprintf(f, "\n---Danh sach 3 thi sinh co diem cao nhat la---\n");
    fprintf(f, "%-30s%-15s%-15s\n", "Ho ten", "So diem", "Dai hoc");

    for(int i = 0; i < 3; i++) {
        fprintf(f, "%-30s%-15.1f%-10c\n", a[i].ht, a[i].diem, a[i].dh);
    }

    fclose(f);
}

void luu (int n, ts a[]) {
    FILE *f = fopen("output.txt", "w");

    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fprintf(f, "---Danh sach thi sinh---\n");
    fprintf(f, "%-30s%-15s%-15s\n", "Ho ten", "So diem", "Dai hoc");

    for(int i = 0; i < n; i++) {
        fprintf(f, "%-30s%-15.1f%-10c\n", a[i].ht, a[i].diem, a[i].dh);
    }

    fclose(f);
}

int main () {
    int n;
    FILE *f;
    ts *a;

    f = fopen("input.txt", "r");

    if(f == NULL) {
        printf("Loi mo file!");
        return 1;
    }

    fscanf(f, "%d\n", &n);
    a = (ts *) malloc (n * sizeof(ts));

    for(int i = 0; i < n; i++) {
        fgets(a[i].ht, 30, f);
        a[i].ht[strcspn(a[i].ht, "\n")] = '\0';
        fscanf(f, "%f\n", &a[i].diem);
        fscanf(f, "%c\n", &a[i].dh);
    }

    fclose(f);

    luu(n, a);
    tongdiem(n, a);
    diemmax(n, a);

    return 0;
}