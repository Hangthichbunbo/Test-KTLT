#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void doc(int *n, FILE **f, char *filename, int ***a) {
    printf("Nhap ten tep input: ");
    fgets(filename, 30, stdin);
    filename[strlen(filename) - 1] = '\0';

    *f = fopen(filename, "r");
    fscanf(*f, "%d", n);
    *a = (int **)malloc(*n * sizeof(int));
    for(int i = 0; i < *n; i++) {
        (*a)[i] = (int *)malloc(*n * sizeof(int));
    }

    for(int i = 0; i < *n; i++) {
        for(int j = 0; j < *n; j++) {
            fscanf(*f, "%d", &(*a)[i][j]);
        }
    }

    fclose(*f);
}

void tbc(int n, int **a) {
    float Tbc, tongmatran = 0, tongtam = 0;
    int demgiatri = 0, m = n, demptu;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tongmatran += a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            tongtam += a[i][j];
            demgiatri++;
        }
        m -= 1;
    }
    
    demptu = n * n - (demgiatri);
    Tbc = (tongmatran - tongtam)/(float)(demptu);
    printf("TBC cac phan tu duoi duong cheo phu la: %.1f", Tbc);

}

void tgtren(int n, int **a) {
    int dem = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i][j] != 0) {
                dem = 1;
                break;
            }
        }
    }

    if(dem == 1) {
        printf("\nMa tran A khong la ma tran tam giac tren");
    }
    else {
        printf("\nMa tran A la ma tran tam giac tren");
    }
}

int main () {
    int n, **a;
    FILE *f;
    char filename[30];

    doc(&n, &f, filename, &a);

    tbc(n, a);

    tgtren(n, a);

    return 0;
}