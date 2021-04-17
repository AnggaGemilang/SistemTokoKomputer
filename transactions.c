#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "boolean.h"
#include "transactions.h"
#include "tools.h"
#include "diskon.h"

int ASCPenjualan(const void* p, const void* q){ 
	return (((Jual*)p)->id_penjualan - ((Jual*)q)->id_penjualan); 
} 

int DSCPenjualan(const void* p, const void* q){
	return (((Jual*)q)->id_penjualan - ((Jual*)p)->id_penjualan); 
}

int ASCPembelian(const void* p, const void* q){ 
	return (((Beli*)p)->id_pembelian - ((Beli*)q)->id_pembelian); 
} 

int DSCPembelian(const void* p, const void* q){ 
	return (((Beli*)q)->id_pembelian - ((Beli*)p)->id_pembelian); 
}

int ASCPenyewaan(const void* p, const void* q){ 
	return (((Sewa*)p)->id_penyewaan - ((Sewa*)q)->id_penyewaan); 
} 

int DSCPenyewaan(const void* p, const void* q){ 
	return (((Sewa*)q)->id_penyewaan - ((Sewa*)p)->id_penyewaan); 
}

void TableHeaderPenjualan(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR TRANSAKSI");
	printg(yCoordAwal=yCoordAwal+1,45,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,1,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,1,"\xb3");
 	printg(yCoordAwal,3,"NO");
	printg(yCoordAwal,7,"\xb3");
 	printg(yCoordAwal,10,"ID");
 	printg(yCoordAwal,15,"\xb3");
 	printg(yCoordAwal,18,"NAMA PEMBELI");
 	printg(yCoordAwal,32,"\xb3");
 	printg(yCoordAwal,37,"NO TELP");
 	printg(yCoordAwal,47,"\xb3");
 	printg(yCoordAwal,51,"BELANJAAN");
 	printg(yCoordAwal,63,"\xb3");
  	printg(yCoordAwal,65,"QTY");
 	printg(yCoordAwal,69,"\xb3"); 	
  	printg(yCoordAwal,75,"TANGGAL");
 	printg(yCoordAwal,88,"\xb3");
  	printg(yCoordAwal,91,"TOT_HARGA");
 	printg(yCoordAwal,103,"\xb3");
  	printg(yCoordAwal,106,"KETERANGAN");
 	printg(yCoordAwal,118,"\xb3");
	printg(yCoordAwal=yCoordAwal+1,1,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

void TableHeaderPembelian(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR TRANSAKSI");
	printg(yCoordAwal=yCoordAwal+1,45,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,1,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,1,"\xb3");
 	printg(yCoordAwal,3,"NO");
	printg(yCoordAwal,7,"\xb3");
 	printg(yCoordAwal,10,"ID");
 	printg(yCoordAwal,15,"\xb3");
 	printg(yCoordAwal,18,"NAMA PENJUAL");
 	printg(yCoordAwal,32,"\xb3");
 	printg(yCoordAwal,37,"NO TELP");
 	printg(yCoordAwal,47,"\xb3");
 	printg(yCoordAwal,51,"BELANJAAN");
 	printg(yCoordAwal,63,"\xb3");
  	printg(yCoordAwal,65,"QTY");
 	printg(yCoordAwal,69,"\xb3"); 	
  	printg(yCoordAwal,75,"TANGGAL");
 	printg(yCoordAwal,88,"\xb3");
  	printg(yCoordAwal,91,"TOT_HARGA");
 	printg(yCoordAwal,103,"\xb3");
  	printg(yCoordAwal,106,"KEKURANGAN");
 	printg(yCoordAwal,118,"\xb3");
	printg(yCoordAwal=yCoordAwal+1,1,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

void TableHeaderPenyewaan(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR TRANSAKSI");
	printg(yCoordAwal=yCoordAwal+1,45,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,0,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,0,"\xb3");
 	printg(yCoordAwal,2,"NO");
	printg(yCoordAwal,5,"\xb3");
 	printg(yCoordAwal,8,"ID");
 	printg(yCoordAwal,12,"\xb3");
 	printg(yCoordAwal,15,"NAMA PEMBELI");
 	printg(yCoordAwal,29,"\xb3");
 	printg(yCoordAwal,32,"BELANJAAN");
 	printg(yCoordAwal,43,"\xb3");
 	printg(yCoordAwal,45,"QTY");
 	printg(yCoordAwal,49,"\xb3");
  	printg(yCoordAwal,54,"AWAL SEWA");
 	printg(yCoordAwal,67,"\xb3"); 	
  	printg(yCoordAwal,69,"AKHIR SEWA");
 	printg(yCoordAwal,80,"\xb3");
  	printg(yCoordAwal,82,"STATUS");
 	printg(yCoordAwal,89,"\xb3");
  	printg(yCoordAwal,93,"DIBAYAR");
 	printg(yCoordAwal,103,"\xb3");
  	printg(yCoordAwal,106,"TOT HARGA");
 	printg(yCoordAwal,118,"\xb3");
	printg(yCoordAwal=yCoordAwal+1,0,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

FILE TampilkanPenjualan(char mode, char isJual, int *counterRow){
	int type;
	Jual penjualan;
	Jual arrPenjualan[100];
	Sewa penyewaan;
	Beli pembelian;
	char *tampilkanJual[6] = {"\n\n   Beranda","Kelola Transaksi","Kelola Penjualan","Tampilkan Penjualan\n\n",NULL,NULL};																
	FILE *fptr;
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/jual.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&penjualan, sizeof(Jual), 1, fptr)==1){
			if(((isJual=='y') ? strcmp(penjualan.keterangan,"Jual")==0 : true)){
				arrPenjualan[counter_jumlah]=penjualan;
				counter_jumlah++;
			}
		}
		if(mode=='c'){
			TableHeaderPenjualan(*counterRow, &CounterBaris);
			qsort(arrPenjualan, counter_jumlah, sizeof(Jual), ASCPenjualan);
		} else if(mode=='n'){
			ulangi:
           	Breadcrumb(tampilkanJual);			   							
			printf("\n   *) Mode Urutan\n\n   1. Ascending\n\n   2. Descending\n\n   Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderPenjualan(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrPenjualan, counter_jumlah, sizeof(Jual), ASCPenjualan); 
					break;
				case 2:
					qsort(arrPenjualan, counter_jumlah, sizeof(Jual), DSCPenjualan); 
					break;
				default:
					printf("   Tidak Dikenali\n");
					goto ulangi;
					break;
			}
		}
	    for (i=0; i < counter_jumlah; i++){
		 	printg(CounterBaris=CounterBaris+1,1,"\xb3");
		 	printg(CounterBaris,4,ToString(i+1));
			printg(CounterBaris,7,"\xb3");
		 	printg(CounterBaris,9,ToString(arrPenjualan[i].id_penjualan));
		 	printg(CounterBaris,15,"\xb3");
		 	printg(CounterBaris,17,(strlen(arrPenjualan[i].nama_pembeli) <= 14) ? arrPenjualan[i].nama_pembeli : strcat(substr(arrPenjualan[i].nama_pembeli,0,11),"..."));
		 	printg(CounterBaris,32,"\xb3");
		 	printg(CounterBaris,34,arrPenjualan[i].no_telp);
		 	printg(CounterBaris,71,strcat(ToString(arrPenjualan[i].tanggal_pembelian.tanggal.hari),"/"));
		 	printg(CounterBaris,74,strcat(ToString(arrPenjualan[i].tanggal_pembelian.tanggal.bulan),"/"));
		 	printg(CounterBaris,77,strcat(ToString(arrPenjualan[i].tanggal_pembelian.tanggal.tahun)," "));
		 	printg(CounterBaris,82,strcat(ToString(arrPenjualan[i].tanggal_pembelian.jam),":"));
		 	printg(CounterBaris,85,ToString(arrPenjualan[i].tanggal_pembelian.menit));
		 	printg(CounterBaris,88,"\xb3");
		  	printg(CounterBaris,90,"Rp.");
		  	printg(CounterBaris,94,ToString(arrPenjualan[i].total_harga));
		 	printg(CounterBaris,103,"\xb3");
		  	printg(CounterBaris,108,arrPenjualan[i].keterangan);
		 	printg(CounterBaris,118,"\xb3");
		 	int j;
		 	for(j = 0; j < 10; j++){
		 		if(arrPenjualan[i].belanjaan[j].barang.barang_id != -1){
					printg(CounterBaris,50,arrPenjualan[i].belanjaan[j].barang.nama_barang);
				  	printg(CounterBaris,65.5,ToString(arrPenjualan[i].belanjaan[j].qty));
	 				printg(CounterBaris,1,"\xb3");
					printg(CounterBaris,7,"\xb3");
	  				printg(CounterBaris,15,"\xb3");
	  				printg(CounterBaris,32,"\xb3");
	 				printg(CounterBaris,46," \xb3  ");
	 				printg(CounterBaris,63,"\xb3");									    				
	 				printg(CounterBaris,69,"\xb3");
	  				printg(CounterBaris,88,"\xb3");
	  				printg(CounterBaris,103,"\xb3");
	  				printg(CounterBaris,118,"\xb3");
					CounterBaris=CounterBaris+1;		 					 			
				}
			}
			printg(CounterBaris,1,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,1,"Jumlah Data : ");
		printg(CounterBaris,15,ToString(counter_jumlah));
	 	fclose(fptr);	
	 	printf("\n");
	}	
}

void HapusBeli(){
	Beli beli;
	FILE *fptr, *temp;
	char query[20], yakin, ulangi = 'y', isFound = false;
	int status = false, counterRow = 11;
	char *syarat[10] = {
		"Masukkan ID Member Untuk Menghapus Transaksi Jual",
		"Tersedia Alert Untuk Memastikan Penghapusan",
		"Masukkan Y/y Untuk Melanjutkan Penghapusan", 
		"Masukkan T/t Untuk Menggagalkan Penghapusan", 
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);
	TampilkanPembelian('c', &counterRow);
	ulangiBeli:
	printf("\n   Masukkan ID Transaksi : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/beli.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&beli, sizeof(Beli), 1, fptr)==1){
			if(strcmp(query, ToString(beli.id_pembelian))!=0){
				fwrite(&beli, sizeof(Beli), 1, temp);
			}
			if(strcmp(query, ToString(beli.id_pembelian))==0){
				isFound = true;
				printf("   %-20s :  %d\n","ID Pembelian", beli.id_pembelian);
				printf("   %-20s :  %d\n","Nama Penjual", beli.nama_pembeli);
				printf("   %-20s :  %d\n","No Telp", beli.no_telp);
				int i;
				for(i=0; i < 10; i++){
					if(beli.belanjaan[i].barang.barang_id!=-1){
						printf("   %s ke-%-5s : %s\n","Nama Barang",ToString(i+1), beli.belanjaan[i].barang.nama_barang);						
					}
				}
				printf("   %-20s :  %d/%d/%d\n","Tanggal Masuk Barang", beli.tanggal_pembelian.tanggal.hari, beli.tanggal_pembelian.tanggal.bulan, beli.tanggal_pembelian.tanggal.tahun);
				printf("   %-20s :  %s\n","Harga", ToString(beli.total_harga));	
				printf("   %-20s :  %s\n","Keterangan", beli.keterangan);	
				printf("\n   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){ 
				 	status = true;
					continue;	 
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			fclose(fptr);
			fclose(temp);
			goto ulangiBeli;
		}							
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			printf("\n   Data Berhasil Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/beli.dat");
			rename("bin/temp.dat","bin/beli.dat");
		}
	}
}

void Laporan(){
	Jual penjualan;
	Sewa penyewaan;
	Beli pembelian;
	Timestamp DateNow, timestamp, awal, akhir;
	Diskon diskon;
	Barang barang;
	FILE *fptrPenjualan, *fptrPenyewaan, *fptrBarang;	
	char tambah_item, member, idmember[10], query[5];
	int jumlah = 0, counter = 0, i, isFound = false, pemasukan = 0, pengeluaran = 0, mode;
	printf(" *) Mode Laporan\n\n    1. Keseluruhan\n\n    2. Atur Bulan\n\n    3. Atur Range\n\n    Pilih Mode Laporan : ");
	scanf("%d", &mode);
	if(mode==2){
		printf("    %-20s : ", "Masukkan Periode [MM/YYYY]"); fflush(stdin); scanf("%d/%d", &timestamp.tanggal.bulan, &timestamp.tanggal.tahun);
	} else if(mode==3){
		printf("    %-20s : ", "Masukkan Awal Periode [MM/YYYY]"); fflush(stdin); scanf("%d/%d", &awal.tanggal.bulan, &awal.tanggal.tahun);
		awal.tanggal.hari = 01;
		awal.jam = 01;
		awal.menit = 00;
		awal.detik = 00;
		printf("    %-20s : ", "Masukkan Akhir Periode [MM/YYYY]"); fflush(stdin); scanf("%d/%d", &akhir.tanggal.bulan, &akhir.tanggal.tahun);
		akhir.tanggal.hari = 30;
		akhir.jam = 01;
		akhir.menit = 00;
		akhir.detik = 00;
	}
	if((fptrBarang = fopen("bin/stock.dat","rb")) == NULL){
	    printf("    Error! File Tidak Dapat Dibuka...");
	    MessageBeep(0);
		exit(1);
	} else {
		while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
			pengeluaran = pengeluaran + barang.hrg*barang.jml_barang;
		}
		if((fptrPenjualan = fopen("bin/jual.dat","rb")) == NULL){
		    printf("    Error! File Tidak Dapat Dibuka...");
		    MessageBeep(0);
			exit(1);
		} else {
			int tempPemasukan = 0, tempPengeluaran = 0;
			while(fread(&penjualan, sizeof(Jual), 1, fptrPenjualan)==1){
				if((strcmp(penjualan.keterangan,"Jual")==0) && ((mode==2) ? timestamp.tanggal.bulan == penjualan.tanggal_pembelian.tanggal.bulan && timestamp.tanggal.tahun == penjualan.tanggal_pembelian.tanggal.tahun : true) && ((mode==3) ? DateInRange(awal, penjualan.tanggal_pembelian) && DateInRange(penjualan.tanggal_pembelian, akhir) : true)){
					tempPemasukan = tempPemasukan + penjualan.total_harga;
					pengeluaran = pengeluaran + penjualan.total_harga;
					pemasukan = pemasukan + penjualan.total_harga;
				}
				if((strcmp(penjualan.keterangan,"Retur")==0) && ((mode==2) ? timestamp.tanggal.bulan == penjualan.tanggal_pembelian.tanggal.bulan && timestamp.tanggal.tahun == penjualan.tanggal_pembelian.tanggal.tahun : true) && ((mode==3) ? DateInRange(awal, penjualan.tanggal_pembelian) && DateInRange(penjualan.tanggal_pembelian, akhir) : true)){
					tempPengeluaran = tempPengeluaran + penjualan.total_harga;
					pengeluaran = pengeluaran + penjualan.total_harga;
				}
			}
			printf("\n    Pengeluaran Dari Stok Barang Rp. %d\n", pengeluaran);
			printf("\n    Pemasukan Dari Penjualan Rp. %d\n", tempPemasukan);
			printf("    Pengeluaran Dari Penjualan Rp. %d\n", tempPengeluaran);
			if((fptrPenyewaan = fopen("bin/sewa.dat","rb")) == NULL){
			    printf("    Error! File Tidak Dapat Dibuka...");
			    MessageBeep(0);
				exit(1);
			} else {
				int tempPemasukan = 0;
				while(fread(&penyewaan, sizeof(Sewa), 1, fptrPenyewaan)==1){
					if(((mode==2) ? timestamp.tanggal.bulan == penyewaan.awal_pernyewaan.tanggal.bulan && timestamp.tanggal.tahun == penyewaan.awal_pernyewaan.tanggal.tahun : true) && ((mode==3) ? DateInRange(awal, penyewaan.awal_pernyewaan) && DateInRange(penyewaan.awal_pernyewaan, akhir) : true)){
						tempPemasukan = tempPemasukan + penyewaan.total_harga;
						pemasukan = pemasukan + penyewaan.total_harga;
					}
				}
				printf("\n    Keuntungan Dari Penyewaan Rp. %d\n", tempPemasukan);
			}
		}
	}
	printf("\n    Total pemasukan : Rp. %d", pemasukan);
	printf("\n    Total pengeluaran : Rp. %d", pengeluaran);
	((pemasukan > pengeluaran) ? printf("\n    Toko Untung") : printf("\n    Toko Rugi"));
}

FILE TampilkanPenyewaan(char mode, char isMasih, int *counterRow){
	int type;
	Jual penjualan;
	Sewa penyewaan;
	Sewa arrPenyewaan[100];
	Beli pembelian;
	FILE *fptr;
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/sewa.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&penyewaan, sizeof(Sewa), 1, fptr)==1){
			if(((isMasih=='y') ? strcmp(penyewaan.status_sewa,"masih")==0 : true)){
				arrPenyewaan[counter_jumlah]=penyewaan;
				counter_jumlah++;	
			}
		}
		if(mode=='c'){
			TableHeaderPenyewaan(*counterRow, &CounterBaris);
			qsort(arrPenyewaan, counter_jumlah, sizeof(Sewa), ASCPenyewaan);
		} else if(mode=='n'){
			ulangi:
			printf(" *) Mode Urutan\n\n    1. Ascending\n\n    2. Descending\n\n    Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderPenyewaan(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrPenyewaan, counter_jumlah, sizeof(Sewa), ASCPenyewaan); 
					break;
				case 2:
					qsort(arrPenyewaan, counter_jumlah, sizeof(Sewa), DSCPenyewaan); 
					break;
				default:
					printf("   Tidak Dikenali\n");
					goto ulangi;
					break;
			}
		}
	    for(i=0; i < counter_jumlah; i++){
		 	printg(CounterBaris=CounterBaris+1,0,"\xb3");
		 	printg(CounterBaris,2,ToString(i+1));
		 	printg(CounterBaris,7,ToString(arrPenyewaan[i].id_penyewaan));
		 	printg(CounterBaris,14,(strlen(arrPenyewaan[i].nama_penyewa) <= 14) ? arrPenyewaan[i].nama_penyewa : strcat(substr(arrPenyewaan[i].nama_penyewa,0,11),"..."));
		 	printg(CounterBaris,51,strcat(ToString(arrPenyewaan[i].awal_pernyewaan.tanggal.hari),"/"));
		 	printg(CounterBaris,54,strcat(ToString(arrPenyewaan[i].awal_pernyewaan.tanggal.bulan),"/"));
		 	printg(CounterBaris,56,strcat(ToString(arrPenyewaan[i].awal_pernyewaan.tanggal.tahun)," "));
		 	printg(CounterBaris,61,strcat(ToString(arrPenyewaan[i].awal_pernyewaan.jam),":"));
		 	printg(CounterBaris,64,ToString(arrPenyewaan[i].awal_pernyewaan.menit));
		 	printg(CounterBaris,69,strcat(ToString(arrPenyewaan[i].akhir_penyewaan.tanggal.hari),"/"));
		 	printg(CounterBaris,72,strcat(ToString(arrPenyewaan[i].akhir_penyewaan.tanggal.bulan),"/"));
		 	printg(CounterBaris,75,strcat(ToString(arrPenyewaan[i].akhir_penyewaan.tanggal.tahun)," "));
		 	printg(CounterBaris,82,arrPenyewaan[i].status_sewa);
			printg(CounterBaris,91,"Rp."); 	
		 	printg(CounterBaris,94,ToString(arrPenyewaan[i].harga_dibayarkan));	
			printg(CounterBaris,105,"Rp.");  	
		  	printg(CounterBaris,109,ToString(arrPenyewaan[i].total_harga));
		 	int j;
		 	for(j = 0; j < 5; j++){
		 		if(arrPenyewaan[i].belanjaan[j].barang.barang_id != -1){
					printg(CounterBaris,31,arrPenyewaan[i].belanjaan[j].barang.nama_barang);
				  	printg(CounterBaris,45,ToString(arrPenyewaan[i].belanjaan[j].qty));
	 				printg(CounterBaris,0,"\xb3");
					printg(CounterBaris,5,"\xb3");
	  				printg(CounterBaris,12,"\xb3");
	  				printg(CounterBaris,29,"\xb3");
	 				printg(CounterBaris,43,"\xb3");
	 				printg(CounterBaris,49,"\xb3");									    				
	 				printg(CounterBaris,67,"\xb3");
	  				printg(CounterBaris,80,"\xb3");
	  				printg(CounterBaris,89,"\xb3");
	  				printg(CounterBaris,103,"\xb3");	  				
	  				printg(CounterBaris,118,"\xb3");
					CounterBaris=CounterBaris+1;
				}
			}
			printg(CounterBaris,0,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,1,"Jumlah Data : ");
		printg(CounterBaris,15,ToString(counter_jumlah));
	 	fclose(fptr);
	 	printf("\n");
	}	
}

void Pembelian(){
	Jual penjualan;
	Sewa penyewaan;
	Beli pembelian;
	Timestamp DateNow;
	Diskon diskon;
	Barang barang;
	FILE *fptrBarang, *fptrPembelian;	
	char tambah_item, query[5];
	int jumlah = 0, counter = 0, i, isFound = false, yang_dibayarkan, total_diskon, progress_harga = 0, counterRow = 4;
	DateNow = GetNow();
	UlangiPembelian:
	if((fptrPembelian = fopen("bin/beli.dat","ab")) == NULL){
	    printf("   Error! File Tidak Dapat Dibuka...");
	    MessageBeep(0);
		exit(1);
	} else {
		int z;
		for(z=0; z<10; z++){
			pembelian.belanjaan[z].barang.barang_id = -1;
		}
		do{			
			system("cls");
			char *beli[6] = {"   Beranda","Kelola Transaksi","Kelola Pembelian","Pembelian\n\n",NULL,NULL};									
			printf("\n\n");
			Breadcrumb(beli);
			TampilkanBarang('c','t','t',&counterRow,'y','t');
			if((fptrBarang = fopen("bin/stock.dat","rb+")) == NULL){
		       printf("   Error! File Tidak Dapat Dibuka...");
		       MessageBeep(0);
			   exit(1);
		   	} else{
				printf("\n   %-20s : ", "Masukkan Kode Barang"); fflush(stdin); scanf("%s",&query);
				while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
					if(strcmp(query, ToString(barang.barang_id))==0){
						isFound = true;
						ulangiJumlah:
						printf("   %-20s : ", "Jumlah"); fflush(stdin); scanf("%d", &jumlah);
						if(jumlah > barang.jml_barang){
							printf("   Jumlah Barang Tidak Cukup\n\n");
							goto ulangiJumlah;
						} else {
							barang.jml_barang = barang.jml_barang - jumlah;
							if(barang.jml_barang==0){
								strcpy(barang.status, "nonaktif");
							}								
						}
						pembelian.belanjaan[counter].barang = barang;		
						barang.barang_id = barang.barang_id;
						barang.hrg = barang.hrg;
						strcpy(barang.kategori_barang,barang.kategori_barang);
						strcpy(barang.barang_sewa,barang.barang_sewa);
						strcpy(barang.kondisi_barang,barang.kondisi_barang);
						strcpy(barang.merk_barang,barang.merk_barang);
						strcpy(barang.nama_barang,barang.nama_barang);
						barang.tanggal = barang.tanggal;
						barang.jml_barang = barang.jml_barang + jumlah;
					}
				}
				pembelian.belanjaan[counter].qty = jumlah;				
				if(isFound==false){
					printf("   Kode Barang Tidak Tersedia, Masukkan Barang Baru\n\n   ");
					TambahBarang('t');
					system("cls");
					counterRow = 4;
					goto UlangiPembelian;
				}
				fseek(fptrBarang, (long) -sizeof(Barang), SEEK_CUR);
				fwrite(&barang, sizeof(Barang), 1, fptrBarang);
				fclose(fptrBarang);
			}
			counter++;
			printf("   %-20s : ","Tambah Item [Y/T]"); fflush(stdin); scanf("%c", &tambah_item);
		} while(tambah_item=='y'||tambah_item=='Y');
		pembelian.id_pembelian = RandomNumber(1,9999);
		printf("   %-20s : ", "Nama Penjual"); fflush(stdin); gets(pembelian.nama_pembeli);
		printf("   %-20s : ", "No Telepon"); fflush(stdin); gets(pembelian.no_telp);
		printf("   %-20s : ", "Kekurangan"); fflush(stdin); gets(pembelian.keterangan);
		pembelian.tanggal_pembelian = GetNow();
		for(i=0; i<counter; i++){
			pembelian.total_harga = pembelian.total_harga + pembelian.belanjaan[i].barang.hrg*pembelian.belanjaan[i].qty;
		}
		fwrite(&pembelian, sizeof(Beli), 1, fptrPembelian);	
		fclose(fptrPembelian);
		printf("\n   Pembelian Berhasil!\n\n");		
	}
}

FILE TampilkanPembelian(char mode, int *counterRow){
	int type;
	Jual penjualan;
	Beli arrPembelian[100];
	Sewa penyewaan;
	Beli pembelian;
	FILE *fptr;
	char *tampilkanBeli[6] = {"\n\n   Beranda","Kelola Transaksi","Kelola Pembelian","Tampilkan Pembelian\n\n",NULL,NULL};										
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/beli.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&pembelian, sizeof(Beli), 1, fptr)==1){
			arrPembelian[counter_jumlah]=pembelian;
			counter_jumlah++;
		}
		if(mode=='c'){
			TableHeaderPembelian(*counterRow, &CounterBaris);
			qsort(arrPembelian, counter_jumlah, sizeof(Beli), ASCPembelian);
		} else if(mode=='n'){
			ulangi:
           	Breadcrumb(tampilkanBeli);
			printf("\n   *) Mode Urutan\n\n   1. Ascending\n\n   2. Descending\n\n   Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderPembelian(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrPembelian, counter_jumlah, sizeof(Beli), ASCPembelian); 
					break;
				case 2:
					qsort(arrPembelian, counter_jumlah, sizeof(Beli), DSCPembelian); 
					break;
				default:
					printf("   Masukkan Angka Dengan Benar!\n");
					goto ulangi;
					break;
			}
		}
	    for (i=0; i < counter_jumlah; i++){
		 	printg(CounterBaris=CounterBaris+1,1,"\xb3");
		 	printg(CounterBaris,4,ToString(i+1));
			printg(CounterBaris,7,"\xb3");
		 	printg(CounterBaris,9,ToString(arrPembelian[i].id_pembelian));
		 	printg(CounterBaris,15,"\xb3");
		 	printg(CounterBaris,17,(strlen(arrPembelian[i].nama_pembeli) <= 14) ? arrPembelian[i].nama_pembeli : strcat(substr(arrPembelian[i].nama_pembeli,0,11),"..."));
		 	printg(CounterBaris,32,"\xb3");
		 	printg(CounterBaris,34,arrPembelian[i].no_telp);
		 	printg(CounterBaris,47,"\xb3");
		 	printg(CounterBaris,63,"\xb3");
		 	printg(CounterBaris,69,"\xb3");
		 	printg(CounterBaris,71,strcat(ToString(arrPembelian[i].tanggal_pembelian.tanggal.hari),"/"));
		 	printg(CounterBaris,74,strcat(ToString(arrPembelian[i].tanggal_pembelian.tanggal.bulan),"/"));
		 	printg(CounterBaris,77,strcat(ToString(arrPembelian[i].tanggal_pembelian.tanggal.tahun)," "));
		 	printg(CounterBaris,82,strcat(ToString(arrPembelian[i].tanggal_pembelian.jam),":"));
		 	printg(CounterBaris,85,ToString(arrPembelian[i].tanggal_pembelian.menit));
		 	printg(CounterBaris,88,"\xb3");
		  	printg(CounterBaris,90,"Rp.");
		  	printg(CounterBaris,94,ToString(arrPembelian[i].total_harga));
		 	printg(CounterBaris,103,"\xb3");
		  	printg(CounterBaris,108,arrPembelian[i].keterangan);
		 	printg(CounterBaris,118,"\xb3");
		 	int j;
		 	for(j = 0; j < 10; j++){
		 		if(arrPembelian[i].belanjaan[j].barang.barang_id != -1){
					printg(CounterBaris,50,arrPembelian[i].belanjaan[j].barang.nama_barang);
				  	printg(CounterBaris,65.5,ToString(arrPembelian[i].belanjaan[j].qty));
	 				printg(CounterBaris,0," \xb3");
					printg(CounterBaris,7,"\xb3");
	  				printg(CounterBaris,15,"\xb3");
	  				printg(CounterBaris,32,"\xb3");
	 				printg(CounterBaris,46," \xb3 ");
	 				printg(CounterBaris,63,"\xb3");									    				
	 				printg(CounterBaris,69,"\xb3");
	  				printg(CounterBaris,88,"\xb3");
	  				printg(CounterBaris,103,"\xb3");
	  				printg(CounterBaris,118,"\xb3");
					CounterBaris=CounterBaris+1;		 					 			
				}
			}
			printg(CounterBaris,1,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,1,"Jumlah Data : ");
		printg(CounterBaris,15,ToString(counter_jumlah));
	 	fclose(fptr);
	 	printf("\n");
	}	
}

void Pengembalian(){
	char kode_transaksi[5], kode_barang[5], isRusak;
	FILE *fptrPenyewaan, *fptrBarang;
	Jual jual;
	Sewa penyewaan;
	Beli pembelian;	
	Barang barang;
	Timestamp DateNow;
	char *pengembalian[6] = {"\n\n    Beranda","Kelola Transaksi","Kelola Penyewaan","Pengembalian\n\n",NULL,NULL};										
	int statusBarang = false, IsFound = false, mode, i, yang_dibayarkan, progress_harga = 0, kondisiPersen, counterRow = 5;
	DateNow = GetNow();
   	Breadcrumb(pengembalian);
	TampilkanPenyewaan('c','y', &counterRow);
	UlangiTransaksi:
	if((fptrPenyewaan = fopen("bin/sewa.dat","rb+")) == NULL){
		printf("    Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);
		exit(1);
	} else {
		printf("\n   Masukkan kode transaksi : "); fflush(stdin); scanf("%s", &kode_transaksi);
		while(fread(&penyewaan, sizeof(Sewa), 1, fptrPenyewaan)==1){
			if(strcmp(kode_transaksi, ToString(penyewaan.id_penyewaan))==0 && strcmp(penyewaan.status_sewa,"masih")==0){
				IsFound = true;
				printf("   %-20s : %d\n","ID Penjualan", penyewaan.id_penyewaan);
				printf("   %-20s : %s\n","Nama Pembeli", penyewaan.nama_penyewa);
				printf("   %-20s : %.12s\n","No Telp", penyewaan.no_telp);
				int i;
				for(i=0; i < 5; i++){
					if(penyewaan.belanjaan[i].barang.barang_id!=-1){
						printf("   %s ke-%-5s : %s\n","Nama Barang",ToString(i+1), penyewaan.belanjaan[i].barang.nama_barang);						
					}
				}
				printf("   %-20s : %d/%d/%d\n","Awal Penyewaan", penyewaan.awal_pernyewaan.tanggal.hari, penyewaan.awal_pernyewaan.tanggal.bulan, penyewaan.awal_pernyewaan.tanggal.tahun);
				printf("   %-20s : %d/%d/%d\n","Akhir Penyewaan", penyewaan.akhir_penyewaan.tanggal.hari, penyewaan.akhir_penyewaan.tanggal.bulan, penyewaan.akhir_penyewaan.tanggal.tahun);
				printf("   %-20s : Rp. %d\n","Telah Dibayar",penyewaan.harga_dibayarkan);
				printf("   %-20s : Rp. %d\n","Total Harga",penyewaan.total_harga);				
				if(!DateInRange(DateNow,penyewaan.akhir_penyewaan)){
					int hari = CountDay(penyewaan.akhir_penyewaan,DateNow);
					printf("   Pengembalian Barang Telat %d hari\n", hari);
					printf("   %-20s : Rp. %d\n","Denda",100000*hari);
					penyewaan.total_harga = penyewaan.total_harga + (100000*hari);
					printf("   %-20s : Rp. %d\n","Total Harga",penyewaan.total_harga);
				}
				printf("\n   %-20s [y/t] ? ","Apakah barang rusak"); fflush(stdin); scanf("%c", &isRusak);
				if(isRusak=='y' || isRusak=='Y'){
					printf("   Berapa penurunan kondisi barang [1/100] : "); fflush(stdin); scanf("%d", &kondisiPersen);
					printf("   %-20s : Rp. %d\n","Denda",((int)((double)penyewaan.total_harga*((double)kondisiPersen/(double)100))));
					penyewaan.total_harga = penyewaan.total_harga + ((int)((double)penyewaan.total_harga*((double)kondisiPersen/(double)100)));
					printf("   %-20s : Rp. %d\n","Total Harga",penyewaan.total_harga);
				}
				if(penyewaan.harga_dibayarkan<penyewaan.total_harga){
					progress_harga = penyewaan.harga_dibayarkan;
					while(progress_harga<penyewaan.total_harga){
						printf("   Bayar [Rp. %d] %2s Rp. ",(penyewaan.total_harga-progress_harga),":"); fflush(stdin); scanf("%d", &yang_dibayarkan);
						progress_harga = progress_harga + yang_dibayarkan;
						printf("   %-20s : Rp. %d\n","Telah Dibayarkan", progress_harga);
						if(progress_harga > penyewaan.total_harga){
							penyewaan.harga_dibayarkan = penyewaan.total_harga;								
							printf("   %-20s : Rp. %d\n","Kembalian", progress_harga-penyewaan.total_harga);
							strcpy(penyewaan.status_lunas,"end");
							printf("   Pembayaran sudah selesai\n");						
						} else if(progress_harga == penyewaan.total_harga){
							penyewaan.harga_dibayarkan = progress_harga;
							strcpy(penyewaan.status_lunas,"end");
							printf("   Pembayaran sudah selesai\n");
						}
					}						
				}
				printf("\n   Terimakasih telah menyewa di jaya hartono\n");
				strcpy(penyewaan.status_sewa,"end");				
				fseek(fptrPenyewaan, (long) -sizeof(Sewa), SEEK_CUR);
				fwrite(&penyewaan, sizeof(Sewa), 1, fptrPenyewaan);
				fclose(fptrPenyewaan);
			}
		}
		if(IsFound==false){
			printf("   Transaksi Tidak Ditemukan\n");
			fclose(fptrPenyewaan);		
			goto UlangiTransaksi;
		}
	}
}

void Penyewaan(){
	Jual penjualan;
	Sewa penyewaan;
	Beli pembelian;
	Barang barang;
	Timestamp DateNow;
	Diskon diskon;
	char *sewaan[6] = {"\n\n   Beranda","Kelola Transaksi","Kelola Penyewaan","Penyewaan\n\n",NULL,NULL};									
	Breadcrumb(sewaan);	
	char tambah_item, member, query[5], idmember[10], buatAkun;
	int jumlah = 0, counter = 0, i, isFound = false, yang_dibayarkan, progress_harga = 0, total_diskon = 0, counterRow = 4;
	FILE *fptrBarang, *fptrPenyewaan, *fptrDiskon;
	DateNow = GetNow();
	if((fptrPenyewaan = fopen("bin/sewa.dat","ab")) == NULL){
	    printf("   Error! File Tidak Dapat Dibuka...");
	    MessageBeep(0);
		exit(1);
	} else {
		int z;
		for(z=0; z<5; z++){
			penyewaan.belanjaan[z].barang.barang_id = -1;
		}
		do{
			counterRow = 4;
			system("cls");
			Breadcrumb(sewaan);			
			ulangi:
			TampilkanBarang('c','y','e', &counterRow,'y','t');
			if((fptrBarang = fopen("bin/stock.dat","rb+")) == NULL){
		       printf("   Error! File Tidak Dapat Dibuka...");
		       MessageBeep(0);
			   exit(1);
		   	} else{
				printf("\n   %-25s : ", "Masukkan Kode Barang"); scanf("%s",&query);
				while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
					if(strcmp(query, ToString(barang.barang_id))==0){
						isFound = true;	
						penyewaan.belanjaan[counter].barang = barang;		
						barang.barang_id = barang.barang_id;
						barang.hrg = barang.hrg;
						strcpy(barang.kategori_barang,barang.kategori_barang);
						strcpy(barang.barang_sewa,barang.barang_sewa);
						strcpy(barang.kondisi_barang,barang.kondisi_barang);
						strcpy(barang.merk_barang,barang.merk_barang);
						strcpy(barang.nama_barang,barang.nama_barang);
						barang.tanggal = barang.tanggal;
						ulangiJumlah:
						printf("   %-25s : ", "Jumlah"); fflush(stdin); scanf("%d", &jumlah);
						if(jumlah > barang.jml_barang){
							printf("   Jumlah Barang Tidak Cukup\n\n");
							goto ulangiJumlah;
						} else {
							barang.jml_barang = barang.jml_barang - jumlah;
							if(barang.jml_barang==0){
								strcpy(barang.status, "nonaktif");
							}						
						}
						fseek(fptrBarang, (long) -sizeof(Barang), SEEK_CUR);
						fwrite(&barang, sizeof(Barang), 1, fptrBarang);
						fclose(fptrBarang);
					}
				}
				penyewaan.belanjaan[counter].qty = jumlah;
				if(isFound==false){
					printf("   Barang Tidak Ditemukan\n");
					goto ulangi;
				}
			}
			counter++;
			printf("   %-25s : ","Tambah Item [Y/T]"); fflush(stdin); scanf("%c", &tambah_item);
		} while(tambah_item=='y'||tambah_item=='Y');
		penyewaan.id_penyewaan = RandomNumber(1000,9999);
		penyewaan.awal_pernyewaan = GetNow();
		printf("   %-25s : ", "Nama Penyewa"); fflush(stdin); gets(penyewaan.nama_penyewa);
		printf("   %-25s : ", "No Telepon"); fflush(stdin); gets(penyewaan.no_telp);
		ulangiTanggal:
		printf("   %-25s : ", "Akhir Penyewaan"); fflush(stdin); scanf("%d/%d/%d", &penyewaan.akhir_penyewaan.tanggal.hari, &penyewaan.akhir_penyewaan.tanggal.bulan, &penyewaan.akhir_penyewaan.tanggal.tahun);
		if(!DateInRange(DateNow, penyewaan.akhir_penyewaan)){
			printf("   Masukkan Tanggal Yang Benar!\n\n");
			counterRow = counterRow + 2;
			goto ulangiTanggal;	
		}
		penyewaan.akhir_penyewaan.jam = penyewaan.awal_pernyewaan.jam;
		penyewaan.akhir_penyewaan.menit = penyewaan.awal_pernyewaan.menit;
		penyewaan.akhir_penyewaan.detik = penyewaan.awal_pernyewaan.detik;	
		strcpy(penyewaan.status_sewa,"masih");
		penyewaan.total_harga = 0;		
		for(i=0; i<counter; i++){
			penyewaan.total_harga = penyewaan.total_harga + ((int)((double)penyewaan.belanjaan[i].barang.hrg*0.05)*(CountDay(DateNow,penyewaan.akhir_penyewaan)));
		}
		printf("   %-25s : Rp. %d\n", "PPN [10%]",((int)((double)penyewaan.total_harga*0.1)));
		penyewaan.total_harga = penyewaan.total_harga + ((int)((double)penyewaan.total_harga*0.1));
		printf("   %-25s : Rp. %d\n", "Total Harga",penyewaan.total_harga);
		ulangiMember:
		printf("   Anda Member [Y/T] %-9s ","?"); fflush(stdin); scanf("%c", &member);
		if(member=='y'){
			counterRow = counterRow + 12;
			TampilkanMember('c', &counterRow);
			printf("\n   %-25s : ","Masukkan ID Member"); fflush(stdin); scanf("%s", &idmember);
			if(IsMember(idmember)){
				penyewaan.total_harga = penyewaan.total_harga - ((int)((double)penyewaan.total_harga*0.1));
				total_diskon = total_diskon + ((int)((double)penyewaan.total_harga*0.1));
				printf("   %-25s : Rp. %d\n","Diskon Member [10%]",((int)((double)penyewaan.total_harga*0.1)));
				printf("   %-25s : Rp. %d\n", "Total Harga", penyewaan.total_harga);				
			} else {
				printf("   Member Tidak Dikenali!\n\n");
				goto ulangiMember;
			}
		} else if(member=='t'){
			printf("   Buat Akun [Y/T] %-11s ","?"); fflush(stdin); scanf("%c", &buatAkun);
			if(buatAkun=='y'){
				TambahMember('t');
				penyewaan.total_harga = penyewaan.total_harga - ((int)((double)penyewaan.total_harga*0.1));
				total_diskon = total_diskon + ((int)((double)penyewaan.total_harga*0.1));
				printf("   %-25s : Rp. %d\n","Diskon Member [10%]",((int)((double)penyewaan.total_harga*0.1)));
				printf("   %-25s : Rp. %d\n", "Total Harga", penyewaan.total_harga);
			}
		}
		if((fptrDiskon = fopen("bin/diskon.dat","rb")) == NULL){
		    printf("   Error! File Tidak Dapat Dibuka...");
		    MessageBeep(0);
			exit(1);		
		} else {
			while(fread(&diskon, sizeof(Diskon), 1, fptrDiskon)==1){
				if(strcmp(diskon.status,"aktif")==0){
					if(DateInRange(diskon.tanggal_awal, DateNow) && DateInRange(DateNow, diskon.tanggal_akhir)){
						penyewaan.total_harga = penyewaan.total_harga - ((int)((double)penyewaan.total_harga*((double)diskon.jml_diskon/(double)100)));
						total_diskon = total_diskon + ((int)((double)penyewaan.total_harga*((double)diskon.jml_diskon/(double)100)));
						printf("   Diskon %s [%d%s] : Rp. %d\n",diskon.nama_diskon,diskon.jml_diskon,"%",((int)((double)penyewaan.total_harga*((double)diskon.jml_diskon/(double)100))));			
						printf("   %-25s : Rp. %d\n","Total Harga",penyewaan.total_harga);			
					}					
				}
			}
			fclose(fptrDiskon);
		}
		ulangiBayar:
		printf("   Bayar [Rp. %d] : Rp. ", penyewaan.total_harga); fflush(stdin); scanf("%d", &yang_dibayarkan);
		progress_harga = progress_harga + yang_dibayarkan;
		if(progress_harga < penyewaan.total_harga && progress_harga >= ((int)((double)penyewaan.total_harga*0.5))){
			strcpy(penyewaan.status_lunas,"masih");
			penyewaan.harga_dibayarkan = progress_harga;
			printf("\n   Pembayaran Uang Muka Telah Berhasil\n");
		} else if(progress_harga < penyewaan.total_harga && progress_harga < ((int)((double)penyewaan.total_harga*0.5))){
			printf("   Pembayaran Uang Muka Minimal Rp. %d \n", ((int)((double)penyewaan.total_harga*0.5)));
			printf("   Telah Dibayar : %d\n", progress_harga);
			printf("   Sisa Jika Ingin DP : %d\n", ((int)((double)penyewaan.total_harga*0.5))-progress_harga);
			goto ulangiBayar;
		} else if(progress_harga == penyewaan.total_harga){
			strcpy(penyewaan.status_lunas,"masih");
			penyewaan.harga_dibayarkan = progress_harga;			
			printf("\n   Pembayaran telah berhasil\n");
		} else if(progress_harga > penyewaan.total_harga){
			penyewaan.harga_dibayarkan = penyewaan.total_harga;
			strcpy(penyewaan.status_lunas,"end"); 
			printf("   %-25s : Rp. %d\n","Kembalian",(progress_harga-penyewaan.total_harga));
			printf("\n   Pembayaran telah berhasil\n");
		}
		fwrite(&penyewaan, sizeof(Sewa), 1, fptrPenyewaan);
		Struk('s', penjualan, pembelian, penyewaan, counter-1, total_diskon, progress_harga);
		fclose(fptrPenyewaan);		
	}
}

void Penjualan(){
	Jual penjualan;
	Sewa penyewaan;
	Beli pembelian;
	Timestamp DateNow;
	Diskon diskon;
	Barang barang;
	FILE *fptrBarang, *fptrPenjualan, *fptrDiskon;	
	char tambah_item, member, idmember[10], query[5], buatAkun;
	int jumlah = 0, counter = 0, i, isFound = false, yang_dibayarkan, progress_harga = 0, total_diskon = 0, counterRow = 4;
	DateNow = GetNow();
	if((fptrPenjualan = fopen("bin/jual.dat","ab")) == NULL){
	    printf("   Error! File Tidak Dapat Dibuka...");
	    MessageBeep(0);
		exit(1);
	} else {
		int z;
		for(z=0; z<10; z++){
			penjualan.belanjaan[z].barang.barang_id = -1;
		}
		do{
			counterRow = 4;	
			system("cls");
			char *jualan[6] = {"\n\n   Beranda","Kelola Transaksi","Kelola Penjualan","Penjualan\n\n",NULL,NULL};									
			Breadcrumb(jualan);
			TampilkanBarang('c','d','e',&counterRow,'y','t');
	   		ulangiBarang:
			if((fptrBarang = fopen("bin/stock.dat","rb+")) == NULL){
		       printf("   Error! File Tidak Dapat Dibuka...");
		       MessageBeep(0);
			   exit(1);
		   	} else{
				printf("\n   %-25s : ", "Masukkan Kode Barang"); fflush(stdin); scanf("%s",&query);
				while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
					if(strcmp(query, ToString(barang.barang_id))==0){
						isFound = true;	
						penjualan.belanjaan[counter].barang = barang;		
						barang.barang_id = barang.barang_id;
						barang.hrg = barang.hrg;
						strcpy(barang.kategori_barang,barang.kategori_barang);
						strcpy(barang.barang_sewa,barang.barang_sewa);
						strcpy(barang.kondisi_barang,barang.kondisi_barang);
						strcpy(barang.merk_barang,barang.merk_barang);
						strcpy(barang.nama_barang,barang.nama_barang);
						barang.tanggal = barang.tanggal;
						ulangiJumlah:
						printf("   %-25s : ", "Jumlah"); fflush(stdin); scanf("%d", &jumlah);
						if(jumlah > barang.jml_barang){
							printf("   Jumlah Barang Tidak Cukup\n\n");
							goto ulangiJumlah;
						} else {
							barang.jml_barang = barang.jml_barang - jumlah;
							if(barang.jml_barang==0){
								strcpy(barang.status, "nonaktif");
							}								
						}
						fseek(fptrBarang, (long) -sizeof(Barang), SEEK_CUR);
						fwrite(&barang, sizeof(Barang), 1, fptrBarang);
						fclose(fptrBarang);	
					}
				}
				penjualan.belanjaan[counter].qty = jumlah;				
				if(isFound==false){
					printf("   Barang Tidak Ditemukan\n");
					fclose(fptrBarang);
					goto ulangiBarang;
				}
			}
			counter++;
			printf("   %-25s : ","Tambah Item [Y/T]"); fflush(stdin); scanf("%c", &tambah_item);
		} while(tambah_item=='y'||tambah_item=='Y');
		penjualan.id_penjualan = RandomNumber(10000,999999);
		printf("   %-25s : ", "Nama Pembeli"); fflush(stdin); gets(penjualan.nama_pembeli);
		printf("   %-25s : ", "No Telepon"); fflush(stdin); gets(penjualan.no_telp);
		strcpy(penjualan.keterangan, "Jual");
		penjualan.tanggal_pembelian = GetNow();
		for(i=0; i<counter; i++){
			penjualan.total_harga = penjualan.total_harga + penjualan.belanjaan[i].barang.hrg*penjualan.belanjaan[i].qty;
		}
		printf("   %-25s : Rp. %d\n", "PPN [10%]",((int)((double)penjualan.total_harga*0.1)));
		penjualan.total_harga = penjualan.total_harga + ((int)((double)penjualan.total_harga*0.1));
		printf("   %-25s : Rp. %d\n", "Total Harga",penjualan.total_harga);
		ulangiMember:
		printf("   Anda Member [Y/T] %-9s ","?"); fflush(stdin); scanf("%c", &member);
		if(member=='y'){
			counterRow = counterRow + 12;
			TampilkanMember('c', &counterRow);
			printf("\n   %-25s : ","Masukkan ID Member"); fflush(stdin); scanf("%s", &idmember);
			if(IsMember(idmember)){
				penjualan.total_harga = penjualan.total_harga - ((int)((double)penjualan.total_harga*0.1));
				total_diskon = total_diskon + ((int)((double)penjualan.total_harga*0.1));
				printf("   %-25s : Rp. %d\n","Diskon Member [10%]",((int)((double)penjualan.total_harga*0.1)));
				printf("   %-25s : Rp. %d\n", "Total Harga", penjualan.total_harga);				
			} else {
				printf("   Member Tidak Dikenali!\n");
				counterRow = counterRow - 12;
				goto ulangiMember;
			}
		} else if(member=='t'){
			printf("   Buat Akun [Y/T] %11s ","?"); fflush(stdin); scanf("%c", &buatAkun);
			if(buatAkun=='y'){
				TambahMember('t');
				penjualan.total_harga = penjualan.total_harga - ((int)((double)penjualan.total_harga*0.1));
				total_diskon = total_diskon + ((int)((double)penjualan.total_harga*0.1));
				printf("   %-25s : Rp. %d\n","Diskon Member [10%]",((int)((double)penjualan.total_harga*0.1)));
				printf("   %-25s : Rp. %d\n", "Total Harga", penjualan.total_harga);
			}
		}
		if((fptrDiskon = fopen("bin/diskon.dat","rb")) == NULL){
		    printf("   Error! File Tidak Dapat Dibuka...");
		    MessageBeep(0);
			exit(1);		
		} else {
			while(fread(&diskon, sizeof(Diskon), 1, fptrDiskon)==1){
				if(strcmp(diskon.status,"aktif")==0){
					if(DateInRange(diskon.tanggal_awal, DateNow) && DateInRange(DateNow, diskon.tanggal_akhir)){
						penjualan.total_harga = penjualan.total_harga - ((int)((double)penjualan.total_harga*((double)diskon.jml_diskon/(double)100)));
						total_diskon = total_diskon + ((int)((double)penjualan.total_harga*((double)diskon.jml_diskon/(double)100)));
						printf("   Diskon %-4s [%d%s] : Rp. %d\n",diskon.nama_diskon,diskon.jml_diskon,"%",((int)((double)penjualan.total_harga*((double)diskon.jml_diskon/(double)100))));			
						printf("   %-25s : Rp. %d\n","Total Harga",penjualan.total_harga);			
					}					
				}
			}
			fclose(fptrDiskon);
		}
		while(progress_harga<penjualan.total_harga){
			printf("   Bayar [Rp. %d] : Rp. ",(penjualan.total_harga-progress_harga)); fflush(stdin); scanf("%d", &yang_dibayarkan);
			progress_harga = progress_harga + yang_dibayarkan;
			printf("   Telah Dibayarkan : Rp. %d\n", progress_harga);
			if(progress_harga > penjualan.total_harga){
				printf("   Kembalian : Rp. %d", progress_harga-penjualan.total_harga);
			} else if(progress_harga == penjualan.total_harga){
				printf("   Pembayaran sudah selesai");
			}
		}
		fwrite(&penjualan, sizeof(Jual), 1, fptrPenjualan);	
		Struk('j', penjualan, pembelian, penyewaan, counter-1, total_diskon, progress_harga);
		fclose(fptrPenjualan);		
	}
}

int IsGaransi(Jual penjualan){
	Timestamp NextDay;
	if(penjualan.tanggal_pembelian.tanggal.bulan==1 || penjualan.tanggal_pembelian.tanggal.bulan==3 || penjualan.tanggal_pembelian.tanggal.bulan==5 || penjualan.tanggal_pembelian.tanggal.bulan==7 || penjualan.tanggal_pembelian.tanggal.bulan==8 || penjualan.tanggal_pembelian.tanggal.bulan==10 || penjualan.tanggal_pembelian.tanggal.bulan==12){
		NextDay = penjualan.tanggal_pembelian;
		if(penjualan.tanggal_pembelian.tanggal.hari > 0 && penjualan.tanggal_pembelian.tanggal.hari <= 28){
			penjualan.tanggal_pembelian.tanggal.hari = penjualan.tanggal_pembelian.tanggal.hari + 3;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==29){
			penjualan.tanggal_pembelian.tanggal.hari = 1;
			penjualan.tanggal_pembelian.tanggal.tahun = penjualan.tanggal_pembelian.tanggal.tahun + 1;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==30){
			penjualan.tanggal_pembelian.tanggal.hari = 2;	
			penjualan.tanggal_pembelian.tanggal.tahun = penjualan.tanggal_pembelian.tanggal.tahun + 1;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==31){
			penjualan.tanggal_pembelian.tanggal.hari = 3;			
			penjualan.tanggal_pembelian.tanggal.tahun = penjualan.tanggal_pembelian.tanggal.tahun + 1;
		}
	}
	else if(penjualan.tanggal_pembelian.tanggal.bulan==4 || penjualan.tanggal_pembelian.tanggal.bulan==6 || penjualan.tanggal_pembelian.tanggal.bulan==9 || penjualan.tanggal_pembelian.tanggal.bulan==11){
		if(penjualan.tanggal_pembelian.tanggal.hari > 0 && penjualan.tanggal_pembelian.tanggal.hari <= 27){
			penjualan.tanggal_pembelian.tanggal.hari = penjualan.tanggal_pembelian.tanggal.hari + 3;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==28){
			penjualan.tanggal_pembelian.tanggal.hari = 1;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==29){
			penjualan.tanggal_pembelian.tanggal.hari = 2;	
		} else if(penjualan.tanggal_pembelian.tanggal.hari==30){
			penjualan.tanggal_pembelian.tanggal.hari = 3;
		}
	} else if(penjualan.tanggal_pembelian.tanggal.bulan==2){
		if(penjualan.tanggal_pembelian.tanggal.hari > 0 && penjualan.tanggal_pembelian.tanggal.hari <= 25){
			penjualan.tanggal_pembelian.tanggal.hari = penjualan.tanggal_pembelian.tanggal.hari + 3;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==26){
			penjualan.tanggal_pembelian.tanggal.hari = 1;
		} else if(penjualan.tanggal_pembelian.tanggal.hari==27){
			penjualan.tanggal_pembelian.tanggal.hari = 2;	
		} else if(penjualan.tanggal_pembelian.tanggal.hari==28){
			penjualan.tanggal_pembelian.tanggal.hari = 3;
		}	
	}
	NextDay.tanggal.hari = penjualan.tanggal_pembelian.tanggal.hari;
	NextDay.tanggal.tahun = penjualan.tanggal_pembelian.tanggal.tahun;		
	if(DateInRange(NextDay,penjualan.tanggal_pembelian)){
		return true;
	} else {
		return false;
	}
}

void HapusJual(){
	Jual jual;
	FILE *fptr, *temp;
	char query[20], yakin, ulangi = 'y', isFound = false;
	int status = false, counterRow = 11;
	char *syarat[10] = {
		"Masukkan ID Member Untuk Menghapus Transaksi Jual",
		"Tersedia Alert Untuk Memastikan Penghapusan",
		"Masukkan Y/y Untuk Melanjutkan Penghapusan", 
		"Masukkan T/t Untuk Menggagalkan Penghapusan", 
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);	
	TampilkanPenjualan('c','t', &counterRow);
	ulangiTransaksi:
	printf("\n   Masukkan ID Transaksi : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/jual.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&jual, sizeof(Jual), 1, fptr)==1){
			if(strcmp(query, ToString(jual.id_penjualan))!=0){
				fwrite(&jual, sizeof(Jual), 1, temp);
			}
			if(strcmp(query, ToString(jual.id_penjualan))==0){
				isFound = true;
				printf("   %-20s : %d\n","ID Penjualan",ToString(jual.id_penjualan));
				printf("   %-20s : %s\n","Nama Pembeli",jual.nama_pembeli);
				printf("   %-20s : %s\n","No Telp",jual.no_telp);
				int i;
				for(i=0; i < 10; i++){
					if(jual.belanjaan[i].barang.barang_id!=-1){
						printf("   %s ke-%-5s : %s\n","Nama Barang",ToString(i+1), jual.belanjaan[i].barang.nama_barang);						
					}
				}
				printf("   %-20s : %d/%d/%d\n","Tanggal Pembelian", jual.tanggal_pembelian.tanggal.hari, jual.tanggal_pembelian.tanggal.bulan, jual.tanggal_pembelian.tanggal.tahun);
				printf("   %-20s : %d\n","Total Harga",jual.total_harga);
				printf("   %-20s : %s\n","Keterangan",jual.keterangan);								
				printf("\n   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c", &yakin);
				if(yakin=='y' || yakin=='Y'){ 
				 	status = true;
					continue;	 
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			fclose(fptr);
			fclose(temp);
			goto ulangiTransaksi;
		}
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			fclose(fptr);
			fclose(temp);
			remove("bin/jual.dat");
			rename("bin/temp.dat","bin/jual.dat");
			if(fwrite != 0){
				printf("\n   Data Berhasil Dihapus!\n\n");
			}
		}
	}
}

void HapusSewa(){
	Sewa sewa;
	FILE *fptr, *temp;
	char query[20], yakin, ulangi = 'y', isFound = false;
	int status = false, counterRow = 12;
	char *syarat[10] = {
		"Masukkan ID Member Untuk Menghapus Transaksi Sewa",
		"Tersedia Alert Untuk Memastikan Penghapusan",
		"Masukkan Y/y Untuk Melanjutkan Penghapusan", 
		"Masukkan T/t Untuk Menggagalkan Penghapusan", 
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);	
	TampilkanPenyewaan('c','t', &counterRow);
	ulangiSewa:	
	printf("\n   Masukkan ID Transaksi : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/sewa.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&sewa, sizeof(Sewa), 1, fptr)==1){
			if(strcmp(query, ToString(sewa.id_penyewaan))!=0){
				fwrite(&sewa, sizeof(Sewa), 1, temp);
			}
			if(strcmp(query, ToString(sewa.id_penyewaan))==0){
				isFound = true;
				printf("   %-20s : %d\n","ID Penjualan", sewa.id_penyewaan);
				printf("   %-20s : %s\n","Nama Pembeli", sewa.nama_penyewa);
				printf("   %-20s : %s\n","No Telp", sewa.no_telp);
				int i;
				for(i=0; i < 5; i++){
					if(sewa.belanjaan[i].barang.barang_id!=-1){
						printf("   %s ke-%-5s : %s\n","Nama Barang",ToString(i+1), sewa.belanjaan[i].barang.nama_barang);						
					}
				}
				printf("   %-20s : %d/%d/%d\n","Awal Penyewaan", sewa.awal_pernyewaan.tanggal.hari, sewa.awal_pernyewaan.tanggal.bulan, sewa.awal_pernyewaan.tanggal.tahun);
				printf("   %-20s : %d/%d/%d\n","Akhir Penyewaan", sewa.akhir_penyewaan.tanggal.hari, sewa.akhir_penyewaan.tanggal.bulan, sewa.akhir_penyewaan.tanggal.tahun);
				printf("   %-20s : Rp. %d\n","Telah Dibayar",sewa.harga_dibayarkan);
				printf("   %-20s : Rp. %d\n","Total Harga",sewa.total_harga);
				printf("\n   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){ 
				 	status = true;
					continue;
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			fclose(fptr);
			fclose(temp);
			goto ulangiSewa;
		}									
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			fclose(fptr);
			fclose(temp);
			remove("bin/sewa.dat");
			rename("bin/temp.dat","bin/sewa.dat");
			if(fwrite != 0){
				printf("\n   Data Berhasil Dihapus!\n\n");
			}
		}
	}
}

void ReturBarang(){
	char kode_transaksi[5], kode_barang[5], idRetur[5], isFound = false, isFoundBarang = false;
	FILE *fptrPenjualan, *fptrBarang;
	Jual jual;
	Sewa penyewaan;
	Beli pembelian;	
	Barang barang;
	char *returJual[6] = {"\n\n   Beranda","Kelola Transaksi","Kelola Penjualan","Retur Penjualan\n\n",NULL,NULL};
	Breadcrumb(returJual);
	int statusBarang = false, statusRetur = false, CounterBaris = 4, jumlahBarang, counter_jumlah = 0;
	TampilkanPenjualan('c','y', &CounterBaris);
	ulangi:
	printf("\n   %-20s : ", "Masukkan Kode Transaksi"); scanf("%s", &kode_transaksi);
	if((fptrPenjualan = fopen("bin/jual.dat","ab+")) == NULL){
		printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);
		exit(1);
   	} else {
		while(fread(&jual, sizeof(Jual), 1, fptrPenjualan)==1){
			if(strcmp(kode_transaksi, ToString(jual.id_penjualan))==0){
				isFound = true;	
				if(IsGaransi(jual)){
					system("cls");
					Breadcrumb(returJual);
					CounterBaris = 4;
					TableHeaderBarang(CounterBaris, &CounterBaris);
					int j;
					for(j = 0; j < 10; j++){
						if(jual.belanjaan[j].barang.barang_id != -1){
							counter_jumlah = counter_jumlah + 1;
						 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
						 	printg(CounterBaris,7,ToString(counter_jumlah=counter_jumlah+1));
							printg(CounterBaris,11,"\xb3");
						 	printg(CounterBaris,13,ToString(jual.belanjaan[j].barang.barang_id));
						 	printg(CounterBaris,20,"\xb3");
						 	printg(CounterBaris,22,jual.belanjaan[j].barang.kategori_barang);
						 	printg(CounterBaris,31,"\xb3");
						 	printg(CounterBaris,33,jual.belanjaan[j].barang.nama_barang);
						 	printg(CounterBaris,46,"\xb3");
						 	printg(CounterBaris,48,jual.belanjaan[j].barang.merk_barang);
						 	printg(CounterBaris,57,"\xb3");
						 	printg(CounterBaris,59,jual.belanjaan[j].barang.kondisi_barang);
						 	printg(CounterBaris,67,"\xb3");
							printg(CounterBaris,69,(strcmp(jual.belanjaan[j].barang.barang_sewa,"Y")==0 || strcmp(jual.belanjaan[j].barang.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
							printg(CounterBaris,76,"\xb3");
							printg(CounterBaris,79,ToString(jual.belanjaan[j].qty));
							printg(CounterBaris,85,"\xb3");
						    printg(CounterBaris,87,ToString(jual.belanjaan[j].barang.hrg));
						    printg(CounterBaris,100,"\xb3");
						 	printg(CounterBaris,104,strcat(ToString(jual.belanjaan[j].barang.tanggal.tanggal.hari),"/"));
						 	printg(CounterBaris,107,strcat(ToString(jual.belanjaan[j].barang.tanggal.tanggal.bulan),"/"));
						 	printg(CounterBaris,110,ToString(jual.belanjaan[j].barang.tanggal.tanggal.tahun));
							printg(CounterBaris,118,"\xb3");
							printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
						}
					}
					printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
					printg(CounterBaris,18,ToString(counter_jumlah));
					printf("\n");
					ulangiBarang:
					printf("\n   %-20s : ", "Masukkan Kode Barang"); scanf("%s",&kode_barang);
					int i;
					for(i=0; i<10; i++){
						if(strcmp(kode_barang, ToString(jual.belanjaan[i].barang.barang_id))==0){
							isFoundBarang = true;
							strcpy(idRetur,strcat(substr(kode_barang,0,1),"9999"));
							strcpy(jual.no_telp, jual.no_telp);
							jual.id_penjualan = RandomNumber(10000,99999);
							strcpy(jual.nama_pembeli, jual.nama_pembeli);
							strcpy(jual.keterangan, "Retur");
							jual.tanggal_pembelian = GetNow();
							jual.belanjaan[0].barang = jual.belanjaan[i].barang;
							ulangiJumlah:
							printf("   Masukkan Jumlah Barang : "); fflush(stdin); scanf("%d", &jumlahBarang);
							if(jumlahBarang > jual.belanjaan[i].qty){
								printf("   Masukkan Jumlah Barang Yang Benar!\n\n");
								goto ulangiJumlah;
							}
							jual.belanjaan[0].qty = jumlahBarang;
							int y;
							for(y=1; y<10; y++){
								jual.belanjaan[y].barang.barang_id = -1;	
							}
							jual.total_harga = jual.belanjaan[i].barang.hrg/1;
							if((fptrBarang = fopen("bin/stock.dat","rb+")) == NULL){
								printf("   Error! File Tidak Dapat Dibuka...");
								MessageBeep(0);
								exit(1);
						   	} else {
						   		while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
									if(strcmp(idRetur, ToString(barang.barang_id))==0){
										statusRetur = true;
										barang.jml_barang = barang.jml_barang + jumlahBarang;
								   		fseek(fptrBarang, (long) -sizeof(Barang), SEEK_CUR);
										fwrite(&barang, sizeof(Barang), 1, fptrBarang);	
										fclose(fptrBarang);																				
									}
						   		}
						   		fptrBarang = fopen("bin/stock.dat","rb+");
						   		while(fread(&barang, sizeof(Barang), 1, fptrBarang)==1){
									if(strcmp(ToString(jual.belanjaan[i].barang.barang_id), ToString(barang.barang_id))==0){
										barang.jml_barang = barang.jml_barang - 1;
								   		fseek(fptrBarang, (long) -sizeof(Barang), SEEK_CUR);
										fwrite(&barang, sizeof(Barang), 1, fptrBarang);
										fclose(fptrBarang);											
									}									
						   		}
						   		if(statusRetur==false){
						   			fptrBarang = fopen("bin/stock.dat","ab+");
						  			barang.barang_id = atoi(idRetur);
									strcpy(barang.nama_barang,barang.nama_barang);
									strcpy(barang.barang_sewa,barang.barang_sewa);
									strcpy(barang.merk_barang,barang.merk_barang);									
									strcpy(barang.kategori_barang,barang.kategori_barang);
									strcpy(barang.kondisi_barang,"rusak");					
									barang.hrg = barang.hrg;
									barang.jml_barang = 1;
									barang.tanggal = barang.tanggal;
									fwrite(&barang, sizeof(Barang), 1, fptrBarang);
									fclose(fptrBarang);	
								}
						   	}
						}
					}
					if(isFoundBarang==false){
						printf("   Data Tidak Ditemukan!\n");
						goto ulangiBarang;
					}
				} else {
					printf("   Garansi Barang Sudah Habis\n\n");
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan!\n");
			fclose(fptrPenjualan);
			goto ulangi;
		}
		fwrite(&jual, sizeof(Jual), 1, fptrPenjualan);								
		fclose(fptrPenjualan);		
		printf("\n   Retur Berhasil\n");
	}
}

void Struk(char mode, Jual penjualan, Beli pembelian, Sewa penyewaan, int counter, int diskon, int dibayarkan){
	int i;
	printf("\n\n\t\t      TOKO KOMPUTER JAYA HARTONO\n");
	printf("\t   Jl. Gegerkalong Hilir, Ciwaruga, Kec. Parongpong\n");
	printf("\t       Kabupaten Bandung Barat, Jawa Barat 40559\n");
	printf("       ===================================================\n\n");
	switch(mode){
		case 'j':
			printf("   %-15s : %d\n", "No Transaksi", penjualan.id_penjualan);
			printf("   %-15s : %d/%d/%d %d:%d:%d\n\n", "Tanggal", penjualan.tanggal_pembelian.tanggal.hari, penjualan.tanggal_pembelian.tanggal.bulan, penjualan.tanggal_pembelian.tanggal.tahun, penjualan.tanggal_pembelian.jam, penjualan.tanggal_pembelian.menit, penjualan.tanggal_pembelian.detik);						
			printf("   No\tNama Barang\tqty\tharga\n");
			for(i = 0; i <= counter; i++){
				printf("   %d\t%s\t%d\tRp. %d\n", (i+1), penjualan.belanjaan[i].barang.nama_barang, penjualan.belanjaan[i].qty, penjualan.belanjaan[i].qty*penjualan.belanjaan[i].barang.hrg);
			}
			printf("\n   %-15s : %s\n", "Nama Pembeli", penjualan.nama_pembeli);
			printf("   %-15s : %.12s\n", "No Telepon", penjualan.no_telp);
			printf("   %-15s : Rp. %d\n", "PPN [10%]", ((int)((double)penjualan.total_harga*0.1)));
			printf("   %-15s : Rp. %d\n", "Diskon", diskon);
			printf("   %-15s : Rp. %d\n", "Uang Dibayarkan", dibayarkan);
			printf("   %-15s : Rp. %d\n", "Kembalian", dibayarkan-penjualan.total_harga);
			printf("   %-15s : Rp. %d\n", "Total Harga", penjualan.total_harga);
		break;
		case 's':
			printf("    %-15s : %d\n", "No Transaksi", penyewaan.id_penyewaan);
			printf("    %-15s : %d/%d/%d %d:%d:%d\n", "Awal Penyewaan", penyewaan.awal_pernyewaan.tanggal.hari, penyewaan.awal_pernyewaan.tanggal.bulan, penyewaan.awal_pernyewaan.tanggal.tahun, penyewaan.awal_pernyewaan.jam, penyewaan.awal_pernyewaan.menit, penyewaan.awal_pernyewaan.detik);
			printf("    %-15s : %d/%d/%d %d:%d:%d\n\n", "Akhir Penyewaan", penyewaan.akhir_penyewaan.tanggal.hari, penyewaan.akhir_penyewaan.tanggal.bulan, penyewaan.akhir_penyewaan.tanggal.tahun, penyewaan.akhir_penyewaan.jam, penyewaan.akhir_penyewaan.menit, penyewaan.akhir_penyewaan.detik);
			printf("    No\tNama Barang\tqty\tharga\n");
			for(i = 0; i <= counter; i++){
				printf("    %d\t%s\t%d\tRp. %d\n", (i+1), penyewaan.belanjaan[i].barang.nama_barang, penyewaan.belanjaan[i].qty, penyewaan.belanjaan[i].barang.hrg*penyewaan.belanjaan[i].qty);
			}
			printf("\n    %-15s : %s\n", "Nama Pembeli", penyewaan.nama_penyewa);
			printf("    %-15s : %.12s\n", "No Telepon", penyewaan.no_telp);
			printf("    %-15s : Rp. %d\n", "PPN [10%]", ((int)((double)penyewaan.total_harga*0.1)));
			printf("    %-15s : Rp. %d\n", "Diskon", diskon);
			printf("    %-15s : Rp. %d\n", "Uang Dibayarkan", dibayarkan);
			printf("    %-15s : Rp. %d\n", "Kembalian", ((dibayarkan>penyewaan.total_harga) ? dibayarkan-penyewaan.total_harga : 0));			
			printf("    %-15s : Rp. %d\n", "Total Harga", penyewaan.total_harga);
		break;
	}
}
