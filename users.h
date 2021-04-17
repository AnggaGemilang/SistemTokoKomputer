#ifndef users_H
#define users_H

typedef struct {
	int id_karyawan;
    char nama[50], username[50], password[50], role[16];
} Users;

// Procedure untuk menampilkan header table
void TableHeaderUsers(int coordAwal, int *barisTerakhir);

// Fungsi (constructor) untuk menambahkan user baru
FILE TambahUser();

// Fungsi untuk membaca data users dari file
// Procedure untuk melakukan pengurutan data users
// Diurutkan berdasarkan id_karyawan
FILE TampilkanUser(char mode, int *counterRow);

// Fungsi untuk melakukan login
int Login();

// Procedure untuk melakukan pencarian
void CariUser();

// Procedure untuk melakukan validasi dalam penambahan user
int IsValidUser(int id_karyawan, char nama[50], char username[50], char password[50], char role[16], char mode);

// Procedure untuk mengubah user
FILE UbahUser();

// Procedure untuk menghapus user
FILE HapusUser();

// Procedure untuk menampilkan error
void ShowError();

// Fungsi dalam melakukan pengurutan ASC
int ASCUser(const void* p, const void* q);

// Fungsi dalam melakukan pengurutan DESC
int DSCUser(const void* p, const void* q);

//Procedure untuk Melakukan Logout
void Logout(Users *UserNow, int *status);

#endif
