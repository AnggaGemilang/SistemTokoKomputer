#ifndef barang_H
#define barang_H
#include "tools.h"
typedef struct{
	int barang_id,jml_barang,hrg;
	char kategori_barang[20],nama_barang[20],merk_barang[20],kondisi_barang[15],barang_sewa[15],status[10];
	Timestamp tanggal;
}Barang;

void menubarang(void);

// PROSEDUR TAMBAH BARANG
FILE TambahBarang(char mode);

// PROSEDUR CARI BARANG
void CariBarang();

// PROSEDUR LIST BARANG
FILE TampilkanBarang(char mode, char isSewa, char isBaru, int *counterRow, char isAktif, char isNonaktif);

// PROSEDUR HAPUS BARANG
FILE HapusBarang();

// PROSEDUR EDIT BARANG
FILE UbahBarang();

// PROSEDUR AKTIFKAN BARANG
FILE AktifkanBarang();

// PROSEDUR NONAKTIFKAN BARANG
FILE NonaktifkanBarang();

// Fungsi dalam melakukan pengurutan ASC
int ASCBarang(const void* p, const void* q);

// Fungsi dalam melakukan pengurutan DESC
int DSCBarang(const void* p, const void* q);

// Procedure untuk menampilkan header table
void TableHeaderBarang(int coordAwal, int *barisTerakhir);

// Procedure untuk melakukan validasi dalam penambahan member
int IsValidBarang(int barang_id, char kategori_barang[10], char nama_barang[20], char merk_barang[50], char kondisi_barang[50], int jml_barang, int hrg, char barang_sewa[10], char status[10], char mode);

#endif
