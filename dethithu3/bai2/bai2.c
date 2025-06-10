#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct {
    char ten[50];
    int ns, nkn;
} dangvien;

void doc(int *n, FILE **f, dangvien **a) {
    *f = fopen("input.txt", "r");

    fscanf(*f, "%d", n);
    *a = (dangvien*)malloc(*n *sizeof(dangvien));

    for(int i = 0; i < *n; i++) {
        fgets((*a)[i].ten, 50, *f);
        (*a)[i].ten[strlen((*a)[i].ten) - 1] = '\0';
        fscanf(*f, "%d\n%d", &(*a)[i].ns, &(*a)[i].nkn);
    }

    fclose(*f);
}

void in1() {
    printf("%s %20s %20s\n", "Ho ten", "Nam sinh", "Nam ket nap");
}

void sapxep(int n, dangvien *a) {
    dangvien tam;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j].nkn < a[i].nkn) {
                a[i] = tam;
                tam = a[j];
                a[j] = a[i];
            }
        }
    }

    printf("Danh sach sau khi sap xep la\n");
    in1();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            printf("%s %20d %20d\n", a[i].ten, a[i].ns, a[i].nkn);
        }
    }
}

void tuoidang(int n, dangvien *a) {
    int ktra = 0;
    printf("Danh sach dang vien co tu 20 nam tuoi dang tro len la\n");
    in1();
    for(int i = 0; i < n; i++) {
        if(2025 - a[i].nkn >= 20) {
            ktra = 1;
            printf("%s %20d %20d\n", a[i].ten, a[i].ns, a[i].nkn);
        }
    }

    if(ktra == 0) {
        printf("Khong co dang vien nao\n");
    }
}

int main() {
	int n;
	FILE *f;
    dangvien *a;

    doc(&n, &f, &a);

    sapxep(n, a);

    tuoidang(n, a);
	
	return 0;
}