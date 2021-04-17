#ifndef tools_H
#define tools_H

typedef struct {
	int hari;
	int bulan;
	int tahun;
} Tanggal;

typedef struct {
	Tanggal tanggal;
	int jam;
	int menit;
	int detik;
}Timestamp;

//Fungsi untuk konversi angka ke string (char*)
char *ToString(int angka);

// Procedure untuk mengatur posisi
void gotoxy(int x, int y);

// Fungsi untuk melakukan random angka
int RandomNumber(int min_num, int max_num);

// Procedure untuk menampilkan teks berdasarkan koordinat gotoxy()
void printg(int a, int b, char *teks);

// Fungsi untuk memotong string dan menampilkannya sesuai dengan index awal dan akhir
char* substr(const char *src, int m, int n);

// Fungsi untuk membandingkan 2 buah tanggal apakah lebih kecil
int DateInRange(Timestamp a, Timestamp b);

// Fungsi untuk menghitung hari
int CountDay(Timestamp FirstDate, Timestamp SecondDate);

// Procedure untuk teks berjalan
void MarqueeText(char *kalimat, int speed);

// Mendapatkan waktu sekarang
Timestamp GetNow();

void Breadcrumb(char *kalimat[10]);

void Persyaratan(char *persyaratan[10]);

void panduan(char *namaFile);

#endif
