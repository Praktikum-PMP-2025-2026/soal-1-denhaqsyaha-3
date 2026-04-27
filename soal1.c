/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - Structures and Dynamic Array
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Nahidl Denhaq Syaha
 *   Nama File           : Soal 1.c
 *   Deskripsi           : Menginput bilangan integer hingga -1, menghitung banyaknya, mengurutkannya, sekaligus memberikan median data
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int* arr;
    int idx;
    int max;
} Array;

// Indeks awal adalah 0
// Maksimal awal adalah 0

void tambahArray (Array* temp, int n);

void sortinArray (Array* temp);

float cariMedian (Array* temp);

int main (void) {
    Array dinamis;
    dinamis.arr = NULL;
    dinamis.idx = 0;
    dinamis.max = 0;

    int n;
    scanf ("%d", &n);
    while (n != -1) {
        tambahArray(&dinamis, n);
        scanf ("%d", &n);
    }
    
    sortinArray(&dinamis);

    float md = cariMedian(&dinamis);

    printf("COUNT %d SORTED ", dinamis.max);
    for(int i = 0; i < dinamis.max; i++) {
        printf("%d ", (dinamis.arr)[i]);
    }
    if (dinamis.max % 2 == 0) {
        printf("MEDIAN %.2f", md);
    } else {
        printf("MEDIAN %d", (int)md);
    }

    return 0;
}

void tambahArray (Array* temp, int n) {
    if ((*temp).max == 0) {
        (*temp).arr = (int*)malloc(sizeof(int));
        (*temp).arr[0] = n;
        (*temp).idx = 0;
        (*temp).max = 1;
    } else {
        (*temp).arr = (int*)realloc((*temp).arr, ((*temp).max + 1)*sizeof(int));
        ((*temp).arr[(*temp).max]) = n;
        (*temp).idx++;
        (*temp).max++;
    }
}

void sortinArray (Array* temp) {
    int a[(*temp).max];
    for (int i = 0; i < (*temp).max; i++) {
        a[i] = ((*temp).arr)[i];
    }

    for (int i = 0; i < ((*temp).max) - 1; i++) {
        for (int j = i + 1; j < (*temp).max; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < (*temp).max; i++) {
        ((*temp).arr)[i] = a[i];
    }
}

float cariMedian (Array* temp) {
    int a[(*temp).max];
    for (int i = 0; i < (*temp).max; i++) {
        a[i] = ((*temp).arr)[i];
    }
    float med;
    if ((*temp).max % 2 != 0) {
        med = a[((*temp).max + 1) / 2 - 1];
    } else {
        med = ((float)a[(*temp).max/2] + (float)a[(*temp).max/2 - 1])/2;
    }

    return med;
}
