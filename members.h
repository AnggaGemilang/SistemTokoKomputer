#ifndef members_H
#define members_H
#include "tools.h"

typedef struct {
	int id_member;
	char namaLengkap[100], kotaAsal[50], JK[3], pekerjaan[50];
	Tanggal tanggal;
} Members;

// Fungsi (constructor) untuk menambahkan user baru
FILE TambahMember(char mode);

// Fungsi untuk membaca data users dari file
// Procedure untuk melakukan pengurutan data users
// Diurutkan berdasarkan id_karyawan
void TampilkanMember(char mode, int *counterRow);

// Procedure untuk melakukan pencarian
void CariMember();

// Procedure untuk melakukan validasi dalam penambahan member
int IsValidMember(int id_member, char nama[50], char jk[3], int tanggal, int bulan, int tahun, char pekerjaan[50], char kotaAsal[16], char mode);

// Procedure untuk mengubah user
FILE UbahMember();

// Procedure untuk menghapus user
FILE HapusMember();

// Fungsi dalam melakukan pengurutan ASC
int ASCMember(const void* p, const void* q);

// Fungsi dalam melakukan pengurutan DESC
int DSCMember(const void* p, const void* q);

// Procedure untuk menampilkan header table
void TableHeaderMembers(int coordAwal, int *barisTerakhir);

// Fungsi untuk mengecek apakah member
int IsMember(char id_member[10]);

#endif

