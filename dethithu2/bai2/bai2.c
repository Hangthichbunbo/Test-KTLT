#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ten[50];
    float diem;
    char truong;
}thisinh;

void doc(int *n, FILE **f, thisinh **a ) {
    *f = fopen("input.txt", "r");

    fscanf(*f, "%d\n", n);
    *a = (thisinh *)malloc(*n * sizeof(thisinh));

    for(int i = 0; i < *n; i++) {
        fgets((*a)[i].ten, 50, *f);
        (*a)[i].ten[strcspn((*a)[i].ten, "\n")] = '\0';
        fscanf(*f, "%f\n", &(*a)[i].diem);
        fscanf(*f, "%c\n", &(*a)[i].truong);
    }

    fclose(*f);
}

void diemmax(int n, thisinh *a) {
    float tongdiem[4] = {0}; 
    for(int i = 0; i < n; i++) {
        if(a[i].truong == 'A') {
            tongdiem[0] += a[i].diem;
        }
        else if(a[i].truong == 'B') {
            tongdiem[1] += a[i].diem;
        }
        else if(a[i].truong == 'C') {
            tongdiem[2] += a[i].diem;
        }
        else {
            tongdiem[3] += a[i].diem;
        }
    }
    printf("Tong diem truong A la: %.1f\n", tongdiem[0]);
    printf("Tong diem truong B la: %.1f\n", tongdiem[1]);
    printf("Tong diem truong C la: %.1f\n", tongdiem[2]);
    printf("Tong diem truong D la: %.1f\n", tongdiem[3]);

    float max = tongdiem[0];

    for(int i = 1; i < 4; i++) {
        if(tongdiem[i] > max) {
            max = tongdiem[i];
        }
    }

    for(int i = 0; i < 4; i++) {
        if(tongdiem[i] == max) {
            if(i == 0) {
                printf("Truong A co tong diem lon nhat\n");
            }
            else if(i == 1) {
                printf("Truong B co tong diem lon nhat\n");
            }
            else if(i == 2) {
                printf("Truong C co tong diem lon nhat\n");
            }
            else {
                printf("Truong D co tong diem lon nhat\n");
            }
        }
    }
}

void tim(int n, thisinh *a, FILE **fout) {
    char tentim[50];
    printf("Nhap ten thi sinh can tim: ");
    fgets(tentim, 50, stdin);
    tentim[strcspn(tentim, "\n")] = '\0';
    
    *fout = fopen("output.txt", "w");
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].ten, tentim) == 0){
            fprintf(*fout, "Ho ten: %s\t Diem: %.1f\t Truong: %c\n", a[i].ten, a[i].diem, a[i].truong);
        }
    }

    fclose(*fout);
}

int main() {
    int n;
    FILE *f, *fout;
    thisinh *a;
    
    doc(&n, &f, &a);
    diemmax(n, a);
    tim(n, a, &fout);

    return 0;
}