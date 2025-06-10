#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ten[100];
    char tacgia[100];
    int nam;
} Sach;

int main() {
    FILE *f = fopen("sach.txt", "r");

    int n;
    fscanf(f, "%d\n", &n);

    Sach ds[100];

    for (int i = 0; i < n; i++) {
        fgets(ds[i].ten, 100, f);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = 0;
        fgets(ds[i].tacgia, 100, f);
        ds[i].tacgia[strcspn(ds[i].tacgia, "\n")] = 0;
        fscanf(f, "%d\n", &ds[i].nam);
    }
    fclose(f);

    char ten_tim[100];
    printf("Nhap ten sach can tim: ");
    fgets(ten_tim, 100, stdin);
    ten_tim[strcspn(ten_tim, "\n")] = 0;

    printf("Cac sach co ten '%s':\n", ten_tim);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ten, ten_tim) == 0) {
            printf("Tac gia: %s, Nam: %d\n", ds[i].tacgia, ds[i].nam);
        }
    }

    FILE *out = fopen("sach_out.txt", "w");

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].nam > ds[j].nam) {
                Sach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ds[i].nam < 2000) {
            fprintf(out, "%s\n%s\n%d\n", ds[i].ten, ds[i].tacgia, ds[i].nam);
        }
    }

    fclose(out);
    return 0;
}