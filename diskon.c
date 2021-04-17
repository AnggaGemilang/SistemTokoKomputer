#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "boolean.h"
#include "diskon.h"
#include "tools.h"

// Procedure untuk menampilkan header table
void TableHeaderDiskon(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR DISKON");
	printg(yCoordAwal=yCoordAwal+1,44,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,4,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,4,"\xb3");
 	printg(yCoordAwal,7,"NO");
	printg(yCoordAwal,11,"\xb3");
 	printg(yCoordAwal,14,"ID DISKON");
 	printg(yCoordAwal,26,"\xb3");
 	printg(yCoordAwal,31,"NAMA DISKON");
 	printg(yCoordAwal,46,"\xb3");
 	printg(yCoordAwal,49,"DISKON");
 	printg(yCoordAwal,57,"\xb3");
 	printg(yCoordAwal,64,"WAKTU AWAL");
 	printg(yCoordAwal,79,"\xb3");
 	printg(yCoordAwal,85,"WAKTU AKHIR");
 	printg(yCoordAwal,101,"\xb3");
 	printg(yCoordAwal,105,"STATUS");
 	printg(yCoordAwal,114,"\xb3");
	printg(yCoordAwal=yCoordAwal+1,4,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

FILE TambahDiskon(){
	Diskon diskon;
	FILE *fptr;
	int jml, counter = 1, jml_diskon, awalHari, awalBulan, awalTahun, awalJam, awalMenit, awalDetik, akhirHari, akhirBulan, akhirTahun, akhirJam, akhirMenit, akhirDetik;
	char *tambahDiskon[6] = {"\n\n   Beranda","Kelola Diskon","Tambah Diskon\n\n\n",NULL,NULL,NULL};				
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Jumlah Diskon Dituliskan Dalam Persen",
		"Masukkan Awal Penerapan Diskon Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Masukkan Akhir Penerapan Diskon Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Masukkan Status Dengan Nilai aktif atau nonaktif",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Breadcrumb(tambahDiskon);
	Persyaratan(syarat);		
	ulangiJumlah:
	printf("\n   Berapa Data Yang Ditambahkan : "); fflush(stdin);
	if(scanf("%d", &jml) != 1) {
		printf("\n   Masukkan Angka!\n");
		goto ulangiJumlah;
	}
	while(counter<=jml){
		ulangi:
		if((fptr = fopen("bin/diskon.dat","ab")) == NULL){
	       printf("   Error! File Tidak Dapat Dibuka...");
	       exit(1);
	   	}else{
   			printf("\n   Masukkan Data Ke-%d\n", counter);
			diskon.id_diskon = RandomNumber(10000,99999); 				
			printf("   %-33s :  ","Nama Diskon"); fflush(stdin); gets(diskon.nama_diskon);
			printf("   %-33s :  ","Jumlah Diskon [%]"); fflush(stdin); scanf("%d",&jml_diskon);
			printf("   %-20s :  ","Waktu Awal  [HH/BB/TTTT JJ:MM:DD]"); fflush(stdin); scanf("%d/%d/%d %d:%d:%d", &awalHari, &awalBulan, &awalTahun, &awalJam, &awalMenit, &awalDetik);
			printf("   %-20s :  ","Waktu Akhir [HH/BB/TTTT JJ:MM:DD]"); fflush(stdin); scanf("%d/%d/%d %d:%d:%d", &akhirHari, &akhirBulan, &akhirTahun, &akhirJam, &akhirMenit, &akhirDetik);
			printf("   %-33s :  ","Status [aktif/nonaktif]"); fflush(stdin); gets(diskon.status);
			if(IsValidDiskon(diskon.id_diskon, diskon.nama_diskon, jml_diskon, awalHari, awalBulan, awalTahun, awalJam, awalMenit, awalDetik, akhirHari, akhirBulan, akhirTahun, akhirJam, akhirMenit, akhirDetik, diskon.status, 'n')){
				diskon.jml_diskon = jml_diskon;
				diskon.tanggal_awal.detik = awalDetik;
				diskon.tanggal_awal.jam = awalJam;
				diskon.tanggal_awal.menit = awalMenit;
				diskon.tanggal_awal.tanggal.bulan = awalBulan;
				diskon.tanggal_awal.tanggal.hari = awalHari;
				diskon.tanggal_awal.tanggal.tahun = awalTahun;															
				diskon.tanggal_akhir.detik = akhirDetik;
				diskon.tanggal_akhir.jam = akhirJam;
				diskon.tanggal_akhir.menit = akhirMenit;
				diskon.tanggal_akhir.tanggal.bulan = akhirBulan;
				diskon.tanggal_akhir.tanggal.hari = akhirHari;
				diskon.tanggal_akhir.tanggal.tahun = akhirTahun;															
				fwrite(&diskon, sizeof(Diskon), 1, fptr);
				printf("\n   %d Data Berhasil Ditambahkan!\n\n", jml);
				fclose(fptr);
			} else {
				printf("\n   Masukkan Data Dengan Benar\n");
				jml_diskon = 0; awalHari = 0; awalBulan = 0; awalTahun = 0; awalJam = 0; awalMenit = 0; awalDetik = 0; akhirHari = 0; akhirBulan = 0; akhirTahun = 0; akhirJam = 0; akhirMenit = 0; akhirDetik = 0;			
				fclose(fptr); 
				goto ulangi;
			}
		}	
		counter++;
		if(counter<=jml){
			system("cls");
			Breadcrumb(tambahDiskon);
			Persyaratan(syarat);		   				
		}
	}
}

void HapusDiskon(){
	Diskon diskon;
	FILE *fptr, *temp;
	char query[20];
	char yakin;
	int status = false, isFound = false, counterRow = 12;
	char *syarat[10] = {
		"Masukkan ID Diskon Untuk Menghapus Diskon",
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
	TampilkanDiskon('c', &counterRow, 't', 't');
	ulangiDiskon:
	printf("\n   Masukkan ID Diskon : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/diskon.dat","rb+")) == '\0'){
      	printf("\n   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
			if(strcmp(query, ToString(diskon.id_diskon))!=0){
				fwrite(&diskon, sizeof(Diskon), 1, temp);
			}
			if(strcmp(query, ToString(diskon.id_diskon))==0){
				isFound = true;
				printf("   %-34s :  %d\n","ID Diskon", diskon.id_diskon);
				printf("   %-34s :  %s\n","Nama Diskon", diskon.nama_diskon);
				printf("   %-34s :  %d\n","Jumlah Diskon", diskon.jml_diskon);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Awal Diskon  [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_awal.tanggal.hari, diskon.tanggal_awal.tanggal.bulan, diskon.tanggal_awal.tanggal.tahun, diskon.tanggal_awal.jam, diskon.tanggal_awal.menit, diskon.tanggal_awal.detik);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Akhir Diskon [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_akhir.tanggal.hari, diskon.tanggal_akhir.tanggal.bulan, diskon.tanggal_akhir.tanggal.tahun, diskon.tanggal_akhir.jam, diskon.tanggal_akhir.menit, diskon.tanggal_akhir.detik);
				printf("   %-34s :  %s\n\n","Status", diskon.status);
				printf("   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
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
			goto ulangiDiskon;
		}			
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			if(fwrite != 0){
				printf("\n   Data Berhasil Dihapus!\n");
			}
			fclose(fptr);
			fclose(temp);
			remove("bin/diskon.dat");
			rename("bin/temp.dat","bin/diskon.dat");
		}
	}
}

void EditDiskon(){
	Diskon diskon;
	FILE *fptr;
	char query[20];
	int counterRow = 13, isFound = false, jmlDiskon, awalHari, awalBulan, awalTahun, awalJam, awalMenit, awalDetik, akhirHari, akhirBulan, akhirTahun, akhirJam, akhirMenit, akhirDetik;
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Jumlah Diskon Dituliskan Dalam Persen",
		"Masukkan Awal Penerapan Diskon Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Masukkan Akhir Penerapan Diskon Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Masukkan Status Dengan Nilai aktif atau nonaktif",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);	
	TampilkanDiskon('c', &counterRow, 't', 't');
	ulangiDiskon:
	printf("\n   Masukkan ID Diskon : "); scanf("%s", &query);
   	if((fptr = fopen("bin/diskon.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
			if(strcmp(query, ToString(diskon.id_diskon))==0){
				isFound = true;
				fflush(stdin);		
				printf("\n   *) Data Terkini\n");				
				printf("   %-34s :  %d\n","ID Diskon", diskon.id_diskon);
				printf("   %-34s :  %s\n","Nama Diskon", diskon.nama_diskon);
				printf("   %-34s :  %d %s\n","Jumlah Diskon [%]", diskon.jml_diskon, "%");
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Awal Diskon  [HH/BB/TTTT JJ:MM:DD]", diskon.tanggal_awal.tanggal.hari, diskon.tanggal_awal.tanggal.bulan, diskon.tanggal_awal.tanggal.tahun, diskon.tanggal_awal.jam, diskon.tanggal_awal.menit, diskon.tanggal_awal.detik);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Akhir Diskon [HH/BB/TTTT JJ:MM:DD]", diskon.tanggal_akhir.tanggal.hari, diskon.tanggal_akhir.tanggal.bulan, diskon.tanggal_akhir.tanggal.tahun, diskon.tanggal_akhir.jam, diskon.tanggal_akhir.menit, diskon.tanggal_akhir.detik);
				printf("   %-34s :  %s\n\n","Status", diskon.status);

				printf("   *) Perbaharui Data!\n");					
				ulangi:
				diskon.id_diskon = diskon.id_diskon;
				printf("   %-34s :  ","Nama Diskon"); fflush(stdin); gets(diskon.nama_diskon);
				printf("   %-34s :  ","Jumlah Diskon [%]"); fflush(stdin); scanf("%d", &jmlDiskon);
				printf("   %-20s :  ","Awal Diskon  [HH/BB/TTTT JJ:MM:DD]"); fflush(stdin); scanf("%d/%d/%d %d:%d:%d", &awalHari, &awalBulan, &awalTahun, &awalJam, &awalMenit, &awalDetik);
				printf("   %-20s :  ","Akhir Diskon [HH/BB/TTTT JJ:MM:DD]"); fflush(stdin); scanf("%d/%d/%d %d:%d:%d", &akhirHari, &akhirBulan, &akhirTahun, &akhirJam, &akhirMenit, &akhirDetik);
				strcpy(diskon.status,diskon.status);
				if(IsValidDiskon(diskon.id_diskon, diskon.nama_diskon, jmlDiskon, awalHari, awalBulan, awalTahun, awalJam, awalMenit, awalDetik, akhirHari, akhirBulan, akhirTahun, akhirJam, akhirMenit, akhirDetik, diskon.status, 'c')){
					diskon.jml_diskon = jmlDiskon;
					diskon.tanggal_awal.detik = awalDetik;
					diskon.tanggal_awal.jam = awalJam;
					diskon.tanggal_awal.menit = awalMenit;
					diskon.tanggal_awal.tanggal.bulan = awalBulan;
					diskon.tanggal_awal.tanggal.hari = awalHari;
					diskon.tanggal_awal.tanggal.tahun = awalTahun;															
					diskon.tanggal_akhir.detik = akhirDetik;
					diskon.tanggal_akhir.jam = akhirJam;
					diskon.tanggal_akhir.menit = akhirMenit;
					diskon.tanggal_akhir.tanggal.bulan = akhirBulan;
					diskon.tanggal_akhir.tanggal.hari = akhirHari;
					diskon.tanggal_akhir.tanggal.tahun = akhirTahun;															
					printf("\n   Data Berhasil Diperbaharui!\n\n");
					fseek(fptr, (long) -sizeof(Diskon), SEEK_CUR);
					fwrite(&diskon, sizeof(Diskon), 1, fptr);
				   	fclose(fptr);
					break;																						
				} else {
					printf("\n   Masukkan Data Yang Benar!\n");
					jmlDiskon = 0; awalHari = 0; awalBulan = 0; awalTahun = 0; awalJam = 0; awalMenit = 0; awalDetik = 0; akhirHari = 0; akhirBulan = 0; akhirTahun = 0; akhirJam = 0; akhirMenit = 0; akhirDetik = 0;			
					goto ulangi;
				}
			}
		}
		if(isFound==false){
			printf("   Diskon Tidak Ditemukan\n");
			goto ulangiDiskon;
		}	
	}
}

FILE AktifkanDiskon(){
	Diskon diskon;
	FILE *fptr;
	int status = false, counterRow = 12;
	char query[20], yakin, isFound;
	char *syarat[10] = {
		"Masukkan ID Diskon Untuk Mengaktifkan Diskon", 
		"Tersedia Alert Untuk Memastikan Pengaktifan",
		"Masukkan Y/y Untuk Melanjutkan Pengaktifan", 
		"Masukkan T/t Untuk Menggagalkan Pengaktifan",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);	
	TampilkanDiskon('c', &counterRow, 't', 'y');
	ulangiLagi:
	printf("\n   Masukkan ID Diskon : "); scanf("%s", &query);
   	if((fptr = fopen("bin/diskon.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
			if(strcmp(query, ToString(diskon.id_diskon))==0){
				isFound = true;
				printf("   %-34s :  %d\n","ID Diskon", diskon.id_diskon);
				printf("   %-34s :  %s\n","Nama Diskon", diskon.nama_diskon);
				printf("   %-34s :  %d\n","Jumlah Diskon", diskon.jml_diskon);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Awal Diskon  [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_awal.tanggal.hari, diskon.tanggal_awal.tanggal.bulan, diskon.tanggal_awal.tanggal.tahun, diskon.tanggal_awal.jam, diskon.tanggal_awal.menit, diskon.tanggal_awal.detik);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Akhir Diskon [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_akhir.tanggal.hari, diskon.tanggal_akhir.tanggal.bulan, diskon.tanggal_akhir.tanggal.tahun, diskon.tanggal_akhir.jam, diskon.tanggal_akhir.menit, diskon.tanggal_akhir.detik);
				printf("   %-34s :  %s\n\n","Status", diskon.status);
				printf("   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){
					fflush(stdin);
				 	status = true;
					diskon.id_diskon = diskon.id_diskon;
					strcpy(diskon.nama_diskon, diskon.nama_diskon);
					diskon.jml_diskon = diskon.jml_diskon;
					diskon.tanggal_awal = diskon.tanggal_awal;
					diskon.tanggal_akhir = diskon.tanggal_akhir;
					strcpy(diskon.status, "aktif");
					break;
					goto berhasil;
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			goto ulangiLagi;
		}				
		if(status==false){
			gagal:
			printf("   Data Gagal Diaktifkan!\n");
		} else if(status==true){
			berhasil:
			fseek(fptr, (long) -sizeof(Diskon), SEEK_CUR);
			fwrite(&diskon, sizeof(Diskon), 1, fptr);
	   		fclose(fptr);
			if(fwrite != 0){
				printf("\n   Data Berhasil Diaktifkan!\n");
			}
		}
	}
}

FILE NonaktifkanDiskon(){
	Diskon diskon;
	FILE *fptr;
	int status = false, counterRow = 12;
	char query[20], yakin, isFound = false;
	char *syarat[10] = {
		"Masukkan ID Diskon Untuk Mengaktifkan Diskon", 
		"Tersedia Alert Untuk Memastikan Penonaktifkan",
		"Masukkan Y/y Untuk Melanjutkan Penonaktifkan", 
		"Masukkan T/t Untuk Menggagalkan Penonaktifkan",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);		
	TampilkanDiskon('c', &counterRow, 'y', 't');
	ulangiLagi:
	printf("\n   Masukkan ID Diskon : "); scanf("%s", &query);
   	if((fptr = fopen("bin/diskon.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
			if(strcmp(query, ToString(diskon.id_diskon))==0){
				isFound = true;
				printf("   %-34s :  %d\n","ID Diskon", diskon.id_diskon);
				printf("   %-34s :  %s\n","Nama Diskon", diskon.nama_diskon);
				printf("   %-34s :  %d\n","Jumlah Diskon", diskon.jml_diskon);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Awal Diskon  [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_awal.tanggal.hari, diskon.tanggal_awal.tanggal.bulan, diskon.tanggal_awal.tanggal.tahun, diskon.tanggal_awal.jam, diskon.tanggal_awal.menit, diskon.tanggal_awal.detik);
				printf("   %-20s :  %d/%d/%d %d:%d:%d\n","Akhir Diskon [dd/mm/yyyy hh:mm:ss]", diskon.tanggal_akhir.tanggal.hari, diskon.tanggal_akhir.tanggal.bulan, diskon.tanggal_akhir.tanggal.tahun, diskon.tanggal_akhir.jam, diskon.tanggal_akhir.menit, diskon.tanggal_akhir.detik);
				printf("   %-34s :  %s\n\n","Status", diskon.status);
				printf("   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){
					fflush(stdin);
				 	status = true;
					diskon.id_diskon = diskon.id_diskon;
					strcpy(diskon.nama_diskon, diskon.nama_diskon);
					diskon.jml_diskon = diskon.jml_diskon;
					diskon.tanggal_awal = diskon.tanggal_awal;
					diskon.tanggal_akhir = diskon.tanggal_akhir;
					strcpy(diskon.status, "nonaktif");
					break;
					goto berhasil;
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			goto ulangiLagi;
		}						
		if(status==false){
			gagal:
			printf("   Data Gagal Dinonaktifkan!\n");
		} else if(status==true) {
			berhasil:
			fseek(fptr, (long) -sizeof(Diskon), SEEK_CUR);
			fwrite(&diskon, sizeof(Diskon), 1, fptr);
	   		fclose(fptr);
			if(fwrite != 0){
				printf("\n   Data Berhasil Dinonaktifkan!\n");
			}
		}
	}
}

int ASCDiskon(const void* p, const void* q){ 
	return (((Diskon*)p)->id_diskon - ((Diskon*)q)->id_diskon); 
} 

int DSCDiskon(const void* p, const void* q){ 
	return (((Diskon*)q)->id_diskon - ((Diskon*)p)->id_diskon); 
}

void TampilkanDiskon(char mode, int *counterRow, char isAktif, char isNonaktif){
	int type;
	Diskon diskon;
	Diskon arrDiskon[20];
	FILE *fptr;
	char *tampilkanDiskon[6] = {"\n\n   Beranda","Kelola Diskon","Tampilkan Diskon\n\n",NULL,NULL,NULL};
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris = 12;
	if((fptr = fopen("bin/diskon.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
			if(((isAktif=='y') ? strcmp(diskon.status,"aktif")==0 : true) && ((isNonaktif=='y') ? strcmp(diskon.status,"nonaktif")==0 : true)){
				arrDiskon[counter_jumlah] = diskon;
				counter_jumlah++;	
			}
		}
		if(mode=='c'){
			TableHeaderDiskon(*counterRow, &CounterBaris);
			qsort(arrDiskon, counter_jumlah, sizeof(Diskon), ASCDiskon);
		} else if(mode=='n'){
			ulangi:
			Breadcrumb(tampilkanDiskon);
			printf("\n   ");
			printf("*) Mode Urutan\n\n   1. Ascending\n\n   2. Descending\n\n   Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderDiskon(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrDiskon, counter_jumlah, sizeof(Diskon), ASCDiskon); 
					break;
				case 2:
					qsort(arrDiskon, counter_jumlah, sizeof(Diskon), DSCDiskon); 
					break;
				default:
					printf("   Tidak Dikenali\n");
					goto ulangi;
					break;
			}
		}
	    for (i=0; i < counter_jumlah; i++){
		 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
		 	printg(CounterBaris,7,ToString(i+1));
		 	printg(CounterBaris,11,"\xb3");
		 	printg(CounterBaris,17,ToString(arrDiskon[i].id_diskon));
		 	printg(CounterBaris,26,"\xb3");
		 	printg(CounterBaris,29,((strlen(arrDiskon[i].nama_diskon) <= 15) ? arrDiskon[i].nama_diskon : strcat(substr(arrDiskon[i].nama_diskon,0,12),"...")));
		 	printg(CounterBaris,46,"\xb3");
		 	printg(CounterBaris,50,strcat(ToString(arrDiskon[i].jml_diskon)," %"));
		 	printg(CounterBaris,57,"\xb3");
		 	printg(CounterBaris,59, strcat(ToString(arrDiskon[i].tanggal_awal.tanggal.hari),"/"));
		 	printg(CounterBaris,62, strcat(ToString(arrDiskon[i].tanggal_awal.tanggal.bulan),"/"));
		 	printg(CounterBaris,65, strcat(ToString(arrDiskon[i].tanggal_awal.tanggal.tahun)," "));
		 	printg(CounterBaris,70, strcat(ToString(arrDiskon[i].tanggal_awal.jam),":"));
		 	printg(CounterBaris,73, strcat(ToString(arrDiskon[i].tanggal_awal.menit),":"));
		 	printg(CounterBaris,76, ToString(arrDiskon[i].tanggal_awal.detik));
		 	printg(CounterBaris,79,"\xb3");
		 	printg(CounterBaris,81, strcat(ToString(arrDiskon[i].tanggal_akhir.tanggal.hari),"/"));
		 	printg(CounterBaris,84, strcat(ToString(arrDiskon[i].tanggal_akhir.tanggal.bulan),"/"));
		 	printg(CounterBaris,87, strcat(ToString(arrDiskon[i].tanggal_akhir.tanggal.tahun)," "));
		 	printg(CounterBaris,92, strcat(ToString(arrDiskon[i].tanggal_akhir.jam),":"));
		 	printg(CounterBaris,95, strcat(ToString(arrDiskon[i].tanggal_akhir.menit),":"));
		 	printg(CounterBaris,98, ToString(arrDiskon[i].tanggal_akhir.detik));	
		 	printg(CounterBaris,101,"\xb3");
		 	printg(CounterBaris,104,arrDiskon[i].status);
		 	printg(CounterBaris,114,"\xb3");
			printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
		printg(CounterBaris,18,ToString(counter_jumlah));
	 	fclose(fptr);
		*counterRow = CounterBaris;	
		printf("\n");
	}
}

// Procedure untuk melakukan pencarian
void CariDiskon(){
	Diskon diskon;
	FILE *fptr;
	char query[20], ulangi='y';
	int isFound = false, counter_jumlah=0, CounterBaris = 13;
	char *syarat[10] = {
		"Masukkan ID Diskon/Nama Diskon/Jumlah/Awal Diskon/Akhir Diskon/Status",
		"Untuk Mencari Status, Masukkan aktif/nonaktif",
		"Untuk Mencari Awal Diskon, Masukkan Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Untuk Mencari Akhir Diskon, Masukkan Dengan Format HH/BB/TTTT JJ:MM:DD",
		"Untuk Mencari Jumlah Diskon, Masukkan Angka Tanpa Persen (%)", 
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	while(ulangi=='y'){
		system("cls");
		char *cariDiskon[6] = {"\n\n   Beranda","Kelola Diskon","Cari Diskon\n\n\n",NULL,NULL,NULL};
		Breadcrumb(cariDiskon);
		Persyaratan(syarat);
		TampilkanDiskon('c', &CounterBaris, 't', 't');
		printf("\n   Masukkan Kata Kunci : "); fflush(stdin); gets(query);
	   	if((fptr = fopen("bin/diskon.dat","ab+")) == '\0'){
	       	printf("   Error! File Tidak Dapat Dibuka...");
	       	MessageBeep(0);
		    exit(1);
		} else {
			TableHeaderDiskon(CounterBaris+4, &CounterBaris);
			while(fread(&diskon, sizeof(Diskon), 1, fptr)==1){
				if((strcmp(query,ToString(diskon.id_diskon))==0) || (strcmp(query,ToString(diskon.jml_diskon))==0) || (strcmp(query, diskon.nama_diskon)==0) || (strcmp(query, diskon.status)==0)){
					isFound = true;
				 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
				 	printg(CounterBaris,7,ToString(counter_jumlah=counter_jumlah+1));
				 	printg(CounterBaris,11,"\xb3");
				 	printg(CounterBaris,17,ToString(diskon.id_diskon));
				 	printg(CounterBaris,26,"\xb3");
				 	printg(CounterBaris,29,((strlen(diskon.nama_diskon) <= 15) ? diskon.nama_diskon : strcat(substr(diskon.nama_diskon,0,12),"...")));
				 	printg(CounterBaris,46,"\xb3");
				 	printg(CounterBaris,50,strcat(ToString(diskon.jml_diskon)," %"));
				 	printg(CounterBaris,57,"\xb3");
				 	printg(CounterBaris,59, strcat(ToString(diskon.tanggal_awal.tanggal.hari),"/"));
				 	printg(CounterBaris,62, strcat(ToString(diskon.tanggal_awal.tanggal.bulan),"/"));
				 	printg(CounterBaris,65, strcat(ToString(diskon.tanggal_awal.tanggal.tahun)," "));
				 	printg(CounterBaris,70, strcat(ToString(diskon.tanggal_awal.jam),":"));
				 	printg(CounterBaris,73, strcat(ToString(diskon.tanggal_awal.menit),":"));
				 	printg(CounterBaris,76, ToString(diskon.tanggal_awal.detik));
				 	printg(CounterBaris,79,"\xb3");
				 	printg(CounterBaris,81, strcat(ToString(diskon.tanggal_akhir.tanggal.hari),"/"));
				 	printg(CounterBaris,84, strcat(ToString(diskon.tanggal_akhir.tanggal.bulan),"/"));
				 	printg(CounterBaris,87, strcat(ToString(diskon.tanggal_akhir.tanggal.tahun)," "));
				 	printg(CounterBaris,92, strcat(ToString(diskon.tanggal_akhir.jam),":"));
				 	printg(CounterBaris,95, strcat(ToString(diskon.tanggal_akhir.menit),":"));
				 	printg(CounterBaris,98, ToString(diskon.tanggal_akhir.detik));	
				 	printg(CounterBaris,101,"\xb3");
				 	printg(CounterBaris,104,diskon.status);
				 	printg(CounterBaris,114,"\xb3");
					printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
				}
			}
			if(isFound==false){
				printf("\n   Data Tidak Ditemukan!\n");
			} else {
				printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
				printg(CounterBaris,18,ToString(counter_jumlah));
				printf("\n");
			}
		}
	   	fclose(fptr);
		ulangiUlangi:
		printf("\n   Cari Lagi [Y/T] : "); fflush(stdin); scanf("%c", &ulangi);
		if(ulangi=='t' || ulangi=='T' || ulangi=='y' || ulangi=='Y'){
		} else {
			goto ulangiUlangi;			
		}
		counter_jumlah = 0;
		CounterBaris = 13;	
		isFound=false;
	}
}

int IsValidDiskon(int id_diskon, char nama_diskon[50], int jml_diskon, int hariAwal, int bulanAwal, int tahunAwal, int jamAwal, int menitAwal, int detikAwal, int hariAkhir, int bulanAkhir, int tahunAkhir, int jamAkhir, int menitAkhir, int detikAkhir, char status[5], char mode){
	FILE *fptr;
	Diskon diskon;
	char idStr[5];
	if(jml_diskon > 0 && strlen(nama_diskon) > 0 && strlen(ToString(jml_diskon)) > 0 && strlen(status) > 0 && strlen(ToString(hariAwal)) > 0 && strlen(ToString(bulanAwal)) > 0 && strlen(ToString(tahunAwal)) > 0 && strlen(ToString(jamAwal)) > 0 && strlen(ToString(menitAwal)) > 0 && strlen(ToString(detikAwal)) > 0 && strlen(ToString(hariAkhir)) > 0 && strlen(ToString(bulanAkhir)) > 0 && strlen(ToString(tahunAkhir)) > 0 && strlen(ToString(jamAkhir)) > 0 && strlen(ToString(menitAkhir)) > 0 && strlen(ToString(detikAkhir)) > 0){
		if(jml_diskon != 0 && hariAwal != 0 && bulanAwal != 0 && tahunAwal != 0 && hariAkhir != 0 && bulanAkhir != 0 && tahunAkhir != 0 && strlen(nama_diskon) < 50 && strlen(ToString(jml_diskon)) < 4 && strlen(status) < 10 && strlen(ToString(hariAwal)) <= 2 && strlen(ToString(bulanAwal)) <= 2 && strlen(ToString(tahunAwal)) <= 4 && strlen(ToString(jamAwal)) <= 2 && strlen(ToString(menitAwal)) <= 2 && strlen(ToString(detikAwal)) <= 2 && strlen(ToString(hariAkhir)) <= 2 && strlen(ToString(bulanAkhir)) <= 2 && strlen(ToString(tahunAkhir)) <= 4 && strlen(ToString(jamAkhir)) <= 2 && strlen(ToString(menitAkhir)) <= 2 && strlen(ToString(detikAkhir)) <= 2){
			if((strcmp(status,"aktif")==0) || (strcmp(status,"nonaktif")==0)){
				if(mode=='n'){
					if((fptr = fopen("bin/diskon.dat","rb")) == NULL){
				       	printf("   Error! File Tidak Dapat Dibuka...");
				       	MessageBeep(0);
					    exit(1);				
					} else {
						while(fread(&diskon,sizeof(Diskon),1,fptr)==1){
							sprintf(idStr, "%d", diskon.id_diskon);
							if(strcmp(ToString(id_diskon), idStr)==0){
								fclose(fptr);
								return false;
							}
						}
						fclose(fptr);
						return true;
					}				
				}
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}	
	} else {
		return false;
	}	
}
