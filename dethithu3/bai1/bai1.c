#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void doc(int *n, int *m, int ***a, char *filename, FILE **fin) {
	printf("Nhap ten tep: ");
	fgets(filename, 30, stdin);
	filename[strlen(filename) - 1] = '\0';
	
	*fin = fopen(filename, "r");
	fscanf(*fin, "%d %d", m, n);
	
	*a = (int **)malloc(*m *sizeof(int*));
	for(int i = 0; i < *m; i++) {
		(*a)[i] = (int *)malloc(*n*sizeof(int));
	}
	
	for(int i = 0; i < *m; i++) {
		for(int j = 0; j < *n; j++) {
			fscanf(*fin, "%d", &(*a)[i][j]);
		}
	}
	
	fclose(*fin);
}

void in(int n, int m, int **a) {
	printf("Ma tran vua doc la: \n");
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void TBC(int n, int m, int **a) {
	float tbc;
	int tong = 0, dem = 0;
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] % 2 == 0 || a[i][j] % 3 == 1) {
				tong += a[i][j];
				dem++;
			}
		}
	}
	
	if(dem == 0) {
		printf("Khong tinh duoc TBC\n");
	}
	else {
		tbc = (float) tong / (float) dem;
        printf("TBC cua so chan va chia 3 du 1 la: %.1f\n", tbc);
	}
	
}



void tonghang(int n, int m, int **a) {	
    int tong = 0;

	for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
		    tong += a[i][j];
	    }
		printf("Tong hang %d la: %d \n", i + 1, tong);
        tong = 0;
	}
}

void invaotep(int n, int m, int **a, FILE **fout) {
	*fout = fopen("output.txt", "w");
	
	fprintf(*fout, "%s", "Ma tran vua doc la: \n");
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			fprintf(*fout, "%5d", a[i][j]);
		}
		fprintf(*fout, "\n");
	}

    fclose(*fout);
}


int main() {
	int **a, m, n;
	FILE *fin, *fout;
	char filename[30];
	
	doc(&n, &m, &a, filename, &fin);
	
	in(n, m, a);
	
	TBC(n, m, a);
	
	tonghang(n, m, a);
	
	invaotep(n, m, a, &fout);
	
	return 0;
}