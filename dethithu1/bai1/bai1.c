#include <stdio.h>
#include <math.h>

int main() {
    char ten_tep[100];
    scanf("%s", ten_tep);

    FILE *f = fopen(ten_tep, "r");

    int n, x, y;
    fscanf(f, "%d", &n);

    int nam_trong = 0, nam_ngoai = 0;
    int diem[100][2];  // Lưu tọa độ các điểm
    int doi_xung[100][2];  // Lưu các cặp đối xứng

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d%d", &x, &y);
        diem[i][0] = x;
        diem[i][1] = y;

        double khoang_cach = sqrt(x*x + y*y);
        if (khoang_cach <= 5)
            nam_trong++;
        else
            nam_ngoai++;
    }

    printf("So diem nam trong la: %d\n", nam_trong);
    printf("So diem nam ngoai la: %d\n", nam_ngoai);

    int dem_doi_xung = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diem[i][0] == -diem[j][0] && diem[i][1] == -diem[j][1]) {
                doi_xung[dem_doi_xung][0] = i;
                doi_xung[dem_doi_xung][1] = j;
                dem_doi_xung++;
            }
        }
    }

    if (dem_doi_xung > 0) {
        printf("Cac cap diem doi xung qua goc toa do:\n");
        for (int i = 0; i < dem_doi_xung; i++) {
            printf("Diem %d va diem %d\n", doi_xung[i][0], doi_xung[i][1]);
        }
    } else {
        printf("Khong tim thay cap diem doi xung.\n");
    }

    fclose(f);
    return 0;
}