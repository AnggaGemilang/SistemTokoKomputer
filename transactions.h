#ifndef transactions_H
#define transactions_H
#include "tools.h"
#include "barang.h"

typedef struct {
	Barang barang;
	int qty;
} Belanjaan;

typedef struct{
	char nama_penyewa[100];
	int id_penyewaan, total_harga;
	Belanjaan belanjaan[5];
	int harga_dibayarkan;
	Timestamp awal_pernyewaan;
	Timestamp akhir_penyewaan;
	char status_sewa[10], no_telp[12], status_lunas[12];
} Sewa;

typedef struct{
	int id_penjualan, total_harga;
	Belanjaan belanjaan[10];
	Timestamp tanggal_pembelian;
	char nama_pembeli[100], keterangan[100], no_telp[12];
} Jual;

typedef struct {
	int id_pembelian, total_harga;
	Belanjaan belanjaan[10];
	Timestamp tanggal_pembelian;
	char nama_pembeli[100], keterangan[100], no_telp[12];
} Beli;

void HapusJual();

void HapusSewa();

void HapusBeli();

// Fungsi untuk mnegecek konidisi barang sewaan
int IsRusak(int kondisi);

FILE TampilkanPenjualan(char mode, char isJual, int *counterRow);

FILE TampilkanPenyewaan(char mode, char isMasih, int *counterRow);

FILE TampilkanPembelian(char mode, int *counterRow);

void TableHeaderPenjualan(int yCoordAwal, int *barisTerakhir);

void TableHeaderPenyewaan(int yCoordAwal, int *barisTerakhir);

void TableHeaderPembelian(int yCoordAwal, int *barisTerakhir);

void Penjualan();

void ReturBarang();

void Pengembalian();

void Pembelian();

void Penyewaan();

void Laporan();

void Struk(char mode, Jual penjualan, Beli pembelian, Sewa penyewaan, int counter, int diskon, int dibayarkan);

int IsGaransi(Jual jual);

#endif
