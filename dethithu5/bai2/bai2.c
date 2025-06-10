#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char hoten[30];
    int luong, mcv;
} nvien;

void nhap(int n, nvien **a) {
    *a = (nvien*)malloc(n * sizeof(nvien));

    for(int i = 0; i < n; i++) {
        printf("Nhan vien %d\n", i + 1);
        printf("Nhap ten: ");
        getchar();
        fgets((*a)[i].hoten, 30, stdin);
        (*a)[i].hoten[strlen((*a)[i].hoten) - 1] = '\0';
        printf("Nhap luong: ");
        scanf("%d", &(*a)[i].luong);
        printf("Nhap ma cong viec: ");
        scanf("%d", &(*a)[i].mcv);
    }
}

void tbluong(int n, nvien *a) {
    float dem[3] = {0}, tongluong[3] = {0}, luongTB[3];
    for(int i = 0; i < n; i++) {
        if(a[i].mcv == 1) {
            dem[0]++;
            tongluong[0] += a[i].luong;
        }
        if(a[i].mcv == 2) {
            dem[1]++;
            tongluong[1] += a[i].luong;
        }
        if(a[i].mcv == 3) {
            dem[2]++;
            tongluong[2] += a[i].luong;
        }
    }
    for(int i = 0; i < 3; i++) {
        luongTB[i] = tongluong[i]/dem[i];
        printf("Luong trung binh mcv %d la: %.1f\n", i + 1, luongTB[i]);
    }
}

void xuat(int n, FILE **f, nvien *a) {
    *f = fopen("Nhanvien.txt", "w");

    if(*f == NULL) {
        printf("Loi mo file");
        return;
    }

    fprintf(*f, "%d\n", n);

    for(int i = 0; i < n; i++) {
        fprintf(*f, "%s\n%d\n%d\n", a[i].hoten, a[i].luong, a[i].mcv);
    }

    fclose(*f);
}

int main() {
    int n;
    FILE *f;
    nvien *a;

    printf("So nhan vien can nhap thong tin: ");
    scanf("%d", &n);

    nhap(n, &a);
    tbluong(n, a);
    xuat(n, &f, a);

    return 0;
}