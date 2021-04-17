#ifndef diskon_H
#define diskon_H
#include "tools.h"

typedef struct {
	int id_diskon, jml_diskon;
	Timestamp tanggal_awal;
	Timestamp tanggal_akhir;
	char nama_diskon[50], status[50];
} Diskon;

// Fungsi (constructor) untuk menambahkan diskon baru
FILE TambahDiskon();

// Procedure untuk menghapus user
void HapusDiskon();

// Procedure untuk mengubah user
void EditDiskon();

// Procedure untuk mengaktifkan diskon
FILE AktifkanDiskon();

// Procedure untuk menonaktifkan diskon
FILE NonaktifkanDiskon();

// Fungsi untuk membaca data users dari file
// Procedure untuk melakukan pengurutan data users
// Diurutkan berdasarkan id_karyawan
void TampilkanDiskon(char mode, int *counterRow, char isAktif, char isNonaktif);

// Procedure untuk menampilkan header table
void TableHeaderDiskon(int yCoordAwal, int *barisTerakhir);

// Procedure untuk melakukan validasi dalam penambahan member
int IsValidDiskon(int id_diskon, char nama_diskon[50], int diskon, int hariAwal, int bulanAwal, int tahunAwal, int jamAwal, int menitAwal, int detikAwal, int hariAkhir, int bulanAkhir, int tahunAkhir, int jamAkhir, int menitAkhir, int detikAkhir, char status[5], char mode);

// Fungsi dalam melakukan pengurutan ASC
int ASCDiskon(const void* p, const void* q);

// Fungsi dalam melakukan pengurutan DSC
int DSCDiskon(const void* p, const void* q);

// Procedure dalam melakukan pencarian diskon
void CariDiskon();

#endif
