#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union JenisKelamin {
    char laki_laki[10];
    char perempuan[10];
};

struct Pelajar {
    char nama[50];
    char nis[20];
    union JenisKelamin jenis_kelamin;
    char jurusan[20];
    int kelas;
    int semester;
    float nilai_uts;
    float nilai_uas;
};

void inputData(struct Pelajar *pelajar) {

    printf("\n*** Silahkan Masukan Data ***\n");
    printf("Masukkan nama pelajar       : ");
    scanf(" %[^\n]", pelajar->nama); 
    printf("Masukkan NIS                : ");
    scanf(" %[^\n]", pelajar->nis);
    
    printf("Masukkan jenis kelamin (L/P): ");
    char jenis_kelamin;

    scanf(" %c", &jenis_kelamin);
    if (jenis_kelamin == 'L' || jenis_kelamin == 'l') {
        strcpy(pelajar->jenis_kelamin.laki_laki, "Laki-laki");

    } else {
        strcpy(pelajar->jenis_kelamin.perempuan, "Perempuan");
    }

    printf("Masukkan jurusan            : ");
    scanf(" %[^\n]", pelajar->jurusan);
    printf("Masukkan kelas              : ");
    scanf("%d", &pelajar->kelas);
    printf("Masukkan semester           : ");
    scanf("%d", &pelajar->semester);
    printf("Masukkan nilai UTS          : ");
    scanf("%f", &pelajar->nilai_uts);
    printf("Masukkan nilai UAS          : ");
    scanf("%f", &pelajar->nilai_uas);
}


void outputData(struct Pelajar *pelajar) {
    printf("\n==== Data Pelajar ====\n");
    printf("Nama          : %s\n", pelajar->nama);
    printf("NIS           : %s\n", pelajar->nis);

    if (strcmp(pelajar->jenis_kelamin.laki_laki, "Laki-laki") == 0) {  
        printf("Jenis Kelamin : %s\n", pelajar->jenis_kelamin.laki_laki);

    } else {
        printf("Jenis Kelamin : %s\n", pelajar->jenis_kelamin.perempuan);
    }

    printf("Jurusan       : %s\n", pelajar->jurusan);
    printf("Kelas         : %d\n", pelajar->kelas);
    printf("Semester      : %d\n", pelajar->semester);
    printf("Nilai UTS     : %.2f\n", pelajar->nilai_uts);
    printf("Nilai UAS     : %.2f\n", pelajar->nilai_uas);
}

void cariData(struct Pelajar *pelajarArray, int jumlahPelajar, const char *nis) {
    for (int i = 0; i < jumlahPelajar; i++) {
        if (strcmp(pelajarArray[i].nis, nis) == 0) { 
            outputData(&pelajarArray[i]);
            return;
        }
    }
    printf("\nData pelajar dengan NIS : %s tidak ditemukan.\n", nis);
}

int main() {
    int jumlahPelajar = 0;
    struct Pelajar *pelajarArray = NULL;

    int pilihan;
    do {
        printf("\n============================================\n");
        printf("==== Pemantauan Hasil Ujian Pelajar SMA ====");
        printf("\n============================================\n");
        printf("1. Tambah Data Pelajar\n");
        printf("2. Tampilkan Semua Data Pelajar\n");
        printf("3. Cari Data Pelajar Berdasarkan NIS\n");
        printf("4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            pelajarArray = (struct Pelajar *)realloc(pelajarArray, (jumlahPelajar + 1) * sizeof(struct Pelajar));
            if (pelajarArray == NULL) {
                printf("Alokasi memori gagal!\n");
                return 1;
            }
            inputData(&pelajarArray[jumlahPelajar]);
            jumlahPelajar++;

        } else if (pilihan == 2) {
            for (int i = 0; i < jumlahPelajar; i++) {
                outputData(&pelajarArray[i]);
            }

        } else if (pilihan == 3) {
            if (jumlahPelajar == 0) {
                printf("\nBelum ada data pelajar yang dimasukkan.\n");
            } else {
                char nis[20];
                printf("\nMasukkan NIS yang ingin dicari: ");
                scanf(" %[^\n]", nis);
                cariData(pelajarArray, jumlahPelajar, nis);
            }

        } else if (pilihan == 4) {
            free(pelajarArray);
            pelajarArray = NULL; 
            return 0;

        } else {
            printf("Pilihan salah!\n");
        }

    } while (pilihan != 4);

    return 0;
}
