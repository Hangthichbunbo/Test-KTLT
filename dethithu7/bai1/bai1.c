#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} diem;

void doc(int *n, FILE **f, char *tentep, diem **a) {
    printf("Nhap ten tep input: ");
    fgets(tentep, 30, stdin);
    tentep[strcspn(tentep, "\n")] = '\0';

    *f = fopen(tentep, "r");

    if(*f == NULL) {
        printf("Loi mo tep");
        return;
    }

    fscanf(*f, "%d\n", n);
    *a = (diem *)malloc(*n * sizeof(diem));

    for(int i = 0; i < *n; i++) {
        fscanf(*f, "%d %d", &(*a)[i].x, &(*a)[i].y);
    }

    fclose(*f);
}

void xagoc(int n, diem *a) {
    float max = 0, dodai;
    
    for(int i = 0; i < n; i++) {
        dodai = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));

        if(dodai > max) {
            max = dodai;
        }
    }

    printf("Diem xa goc toa do nhat la: ");
    for(int i = 0; i < n; i++) {
        dodai = sqrt(pow(a[i].x, 2) + pow(a[i].y, 2));

        if(dodai == max) {
            printf("A[%d] = (%d, %d)\n", i + 1, a[i].x, a[i].y);
        }
    }
}

float gapkhuc(int n, diem *a) {
    float gk = 0;

    for(int i = 1; i < n - 1; i++) {
        gk += sqrt(pow((float)(a[i].x - a[i + 1].x), 2) + pow((float)(a[i].y - a[i + 1].y), 2));
    }

    gk += sqrt(pow((float)(a[0].x - a[n - 1].x), 2) + pow((float)(a[0].y - a[n - 1].y), 2));

    return gk;
}

int main () {
    FILE *f;
    char tentep[30];
    int n;
    diem *a;

    doc(&n, &f, tentep, &a);

    xagoc(n, a);

    printf("Do dai duong gap khuc la: %.1f", gapkhuc(n, a));
}