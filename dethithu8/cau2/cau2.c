#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ts[30], tg[30];
    int nxb;
} sach;

void timsach(int n, sach *a) {
    char tentim[30];
    printf("Nhap ten sach muon tim: ");
    fgets(tentim, 30, stdin);
    tentim[strcspn(tentim, "\n")] = '\0';

    FILE *f = fopen("output.txt", "w");
    
    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fprintf(f,"Thong tin cua sach can tim\n");
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].ts, tentim) == 0) {
            fprintf(f, "Ten sach: %s\tTac gia: %s\tNXB: %d\n",a[i].ts, a[i].tg, a[i].nxb);
        }
    }

    fclose(f);
}

void sapxep(int n, sach *a) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j].nxb < a[i].nxb) {
                sach tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}

void trc2000(int n, sach *a) {
    FILE *f = fopen("output.txt", "a");
    
    if(f == NULL) {
        printf("Loi mo file!");
        return;
    }

    fprintf(f, "---Danh sach sach xuat ban truoc nam 2000---\n");
    fprintf(f, "%-20s%-20s%-10s\n", "Ten sach", "Tac gia", "NXB");
    for(int i = 0; i < n; i++) {
        if(a[i].nxb < 2000) {
            fprintf(f, "%-20s%-20s%-10d\n", a[i].ts, a[i].tg, a[i].nxb);
        }
    }
}

int main() {
    int n;
    sach *a;
    FILE *f = fopen("input.txt", "r");

    if(f == NULL) {
        printf("Loi mo file!");
        return 1;
    }

    fscanf(f, "%d\n", &n);
    a = (sach*)malloc(n * sizeof(sach));

    for(int i = 0; i < n; i++) {
        fgets(a[i].ts, 30, f);
        a[i].ts[strcspn(a[i].ts, "\n")] = '\0';
        fgets(a[i].tg, 30, f);
        a[i].tg[strcspn(a[i].tg, "\n")] = '\0';
        fscanf(f, "%d\n", &a[i].nxb);
    }

    fclose(f);

    timsach(n, a);
    sapxep(n, a);
    trc2000(n, a);

    printf("Da luu vao tep output");

    return 0;
}