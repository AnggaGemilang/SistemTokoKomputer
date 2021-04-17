#define ENTER 13
#define TAB 9
#define BKSP 8
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "boolean.h"
#include "users.h"
#include "tools.h"

// Procedure untuk menampilkan header table
void TableHeaderUsers(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,50,"DAFTAR USERS");
	printg(yCoordAwal=yCoordAwal+1,43,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,4,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,4,"\xb3");
 	printg(yCoordAwal,8,"NO");
	printg(yCoordAwal,13,"\xb3");
 	printg(yCoordAwal,19,"ID KARYAWAN");
 	printg(yCoordAwal,36,"\xb3");
 	printg(yCoordAwal,44,"NAMA LENGKAP");
 	printg(yCoordAwal,63,"\xb3");
 	printg(yCoordAwal,71,"USERNAME");
 	printg(yCoordAwal,86,"\xb3");
 	printg(yCoordAwal,96,"ROLE");
 	printg(yCoordAwal,109,"\xb3");
	printg(yCoordAwal=yCoordAwal+1,4,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

// Fungsi (constructor) untuk menambahkan user baru
FILE TambahUser(){
	Users user;
	FILE *fptr;
	int jml, counter = 1;
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Username Tidak Boleh Sama", 
		"Kolom Role Hanya Bisa Diisi Oleh Administrator, Kasir, atau Gudang",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	char *tambahUser[6] = {"\n\n   Beranda","Kelola User","Tambah User\n\n\n",NULL,NULL,NULL};						
	Breadcrumb(tambahUser);
	Persyaratan(syarat);		   		
	ulangiJumlah:
	printf("\n   Berapa Data Yang Ditambahkan : "); fflush(stdin);
	if(scanf("%d", &jml) != 1) {
		printf("   Masukkan Angka!\n");
		goto ulangiJumlah;
		system("cls");
	}
	while(counter<=jml){
		if((fptr = fopen("bin/users.dat","ab")) == NULL){
	       printf("   Error! File Tidak Dapat Dibuka...");
	       exit(1);
	   	}else{
   			printf("\n   Masukkan Data Ke-%d\n", counter);
			ulangi:
			user.id_karyawan = RandomNumber(10000,99999);				
			printf("   %-33s :  ","Nama Lengkap"); fflush(stdin); gets(user.nama);
			printf("   %-33s :  ","Username"); fflush(stdin); scanf("%s", &user.username);
			printf("   %-33s :  ","Password"); fflush(stdin); gets(user.password);
			printf("   %-20s :  ","Role [Administrator/Kasir/Gudang]"); fflush(stdin); gets(user.role);
			if(IsValidUser(user.id_karyawan, user.nama, user.username, user.password, user.role, 'n')){
				fwrite(&user, sizeof(Users), 1, fptr);
				fclose(fptr);
			} else {
				printf("\n   Masukkan Data Dengan Benar\n");
				goto ulangi;
				system("cls");
			}
		}	
		counter++;
		if(counter<=jml){
			system("cls");
			Breadcrumb(tambahUser);
			Persyaratan(syarat);		   				
		}
	}
	if(fwrite != 0){
		printf("\n   %d Data Berhasil Ditambahkan!\n\n", jml);
	}
}

// Procedure untuk melakukan pengurutan data users
FILE TampilkanUser(char mode, int *counterRow){
	int type;
	Users user;
	Users arrUser[20];
	char *tampilkanUser[6] = {"\n\n   Beranda","Kelola User","Tampilkan User\n\n\n",NULL,NULL,NULL};
	FILE *fptr;
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/users.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&user, sizeof(Users), 1, fptr)==1){
			arrUser[counter_jumlah] = user;
			counter_jumlah++;
		}
		if(mode=='c'){
			TableHeaderUsers(*counterRow, &CounterBaris);
			qsort(arrUser, counter_jumlah, sizeof(Users), ASCUser);
		} else if(mode=='n'){
			ulangi:
			Breadcrumb(tampilkanUser);
			printf("*) Mode Urutan\n\n   1. Ascending\n\n   2. Descending\n\n   Masukkan Mode : "); fflush(stdin); scanf("%d", &type);
			TableHeaderUsers(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrUser, counter_jumlah, sizeof(Users), ASCUser); 
					break;
				case 2:
					qsort(arrUser, counter_jumlah, sizeof(Users), DSCUser); 
					break;
				default:
					system("cls");
					goto ulangi;
					break;
			}
		}
	    for (i=0; i < counter_jumlah; i++) {
		 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
		 	printg(CounterBaris,8,ToString(i+1));
		 	printg(CounterBaris,13,"\xb3");
		 	printg(CounterBaris,22,ToString(arrUser[i].id_karyawan));
		 	printg(CounterBaris,36,"\xb3");
		 	printg(CounterBaris,40,(strlen(arrUser[i].nama) <= 18) ? arrUser[i].nama : strcat(substr(arrUser[i].nama,0,14),"..."));
		 	printg(CounterBaris,63,"\xb3");
		 	printg(CounterBaris,67,((strlen(arrUser[i].username) <= 18) ? arrUser[i].username : strcat(substr(arrUser[i].username,0,14),"...")));
		 	printg(CounterBaris,86,"\xb3");
		 	printg(CounterBaris,90,arrUser[i].role);
		 	printg(CounterBaris,109,"\xb3");
			printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
		printg(CounterBaris,18,ToString(counter_jumlah));
		printf("\n");
	 	fclose(fptr);
	 	*counterRow = CounterBaris;
	}
}

//Procedure untuk Melakukan Logout
void Logout(Users *UserNow, int *status){
	system("cls");
	printf("\n   *) Logout Berhasil!\n");
	*status = true;
}

// Procedure untuk menghapus user
FILE HapusUser(){
	Users user;
	FILE *fptr, *temp;
	char query[20];
	char yakin;
	int status = false, isFound = false, counterRow = 12;
	char *syarat[10] = {
		"Masukkan ID Karyawan Untuk Menghapus User",
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
	TampilkanUser('c', &counterRow);
	ulangiUser:
	printf("\n   Masukkan ID Karyawan : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/users.dat","rb+")) == '\0'){
      	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&user, sizeof(Users), 1, fptr)==1){
			if(strcmp(query, ToString(user.id_karyawan))!=0){
				fwrite(&user, sizeof(Users), 1, temp);
			}
			if(strcmp(query, ToString(user.id_karyawan))==0){
				isFound = true;
				printf("\n   %-33s :  %d\n","ID Karyawan", user.id_karyawan);
				printf("   %-33s :  %s\n","Nama Lengkap", user.nama);
				printf("   %-33s :  %s\n","Username", user.username);
				printf("   %-20s :  %s\n\n","Role [Administrator/Kasir/Gudang]", user.role);
				ulangiUlangi:
				printf("   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){ 
				 	status = true;
					continue;	 
				} else if(yakin=='t' || yakin=='T'){
					status = false;
					break;
					goto gagal;
				} else {
					goto ulangiUlangi;
				}
			}
		}
		if(isFound==false){
			printf("   Data Tidak Ditemukan\n");
			fclose(fptr);
			fclose(temp);
			goto ulangiUser;
		}			
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			printf("\n   Data Berhasil Dihapus!\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/users.dat");
			rename("bin/temp.dat","bin/users.dat");
		}
	}
}

// Procedure untuk mengubah user
FILE UbahUser(){
	Users user;
	FILE *fptr;
	int isFound = false, counterRow = 13;
	char query[20];
	char *syarat[10] = {
		"Masukkan ID Karyawan Untuk Mengubah User",
		"Pastikan Semua Kolom Sudah Terisi",
		"ID Karyawan Tidak Dapat Diubah",
		"Username Tidak Boleh Sama", 
		"Kolom Role Hanya Bisa Diisi Oleh Administrator, Kasir, atau Gudang",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);	
	TampilkanUser('c', &counterRow);
	ulangiUser:
	printf("\n   Masukkan ID Karyawan : "); scanf("%s", &query);				
   	if((fptr = fopen("bin/users.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&user, sizeof(user), 1, fptr)==1){
			if(strcmp(query, ToString(user.id_karyawan))==0){
				isFound = true;
				fflush(stdin);
				printf("\n   *) Data Terkini\n");
				printf("   %-33s :  %d\n","ID Karyawan", user.id_karyawan);
				printf("   %-33s :  %s\n","Nama Lengkap", user.nama);
				printf("   %-33s :  %s\n","Username", user.username);
				printf("   %-20s :  %s\n\n","Role [Administrator/Kasir/Gudang]", user.role);
					
				printf("   *) Perbaharui Data!\n");
				ulangi:
				user.id_karyawan = user.id_karyawan;
				printf("   %-33s :  ","Nama Lengkap"); fflush(stdin); gets(user.nama);
				printf("   %-33s :  ","Username"); fflush(stdin); gets(user.username);
				printf("   %-33s :  ","Password"); fflush(stdin); gets(user.password);
				printf("   %-20s :  ","Role [Administrator/Kasir/Gudang]"); fflush(stdin); gets(user.role);
				if(IsValidUser(user.id_karyawan, user.nama, user.username, user.password, user.role, 'c')){
					fseek(fptr, (long) -sizeof(user), SEEK_CUR);
					fwrite(&user, sizeof(user), 1, fptr);
					if(fwrite != 0){
						printf("\n   Data Berhasil Diperbaharui!\n\n");
						fclose(fptr);	
					}
					break;																									
				} else {
					printf("\n   Masukkan data dengan benar!\n");
					goto ulangi;
				}
			}
		}
		if(isFound==false){
			printf("   Pengguna Tidak Ditemukan\n");
		   	fclose(fptr);	
			goto ulangiUser;
		}		
	}
}

// Procedure untuk melakukan pencarian
void CariUser(){
	Users user;
	FILE *fptr;
	char query[20], ulangi='y';	
	int isFound = false, counter_jumlah=0, CounterBaris = 13;
	char *syarat[10] = {
		"Masukkan ID Karyawan/Nama Lengkap/Username/Role",
		"Untuk Mencari Role, Masukkan Administrator/Kasir/Gudang",
		"Anda Bisa Mengulangi Pencarian",
		"Masukkan Y/Y Untuk Mengulangi Pencarian",
		"Masukman T/t Untuk Kembali Ke Menu Sebelumnya", 
		NULL,
		NULL,
		NULL,
		NULL,
	};
	while(ulangi=='y'){
		system("cls");
		char *cariUser[6] = {"\n\n   Beranda","Kelola User","Cari User\n\n\n",NULL,NULL,NULL};													
		Breadcrumb(cariUser);		
		Persyaratan(syarat);
		TampilkanUser('c', &CounterBaris);
		printf("\n   Masukkan Kata Kunci : "); fflush(stdin); gets(query);
	   	if((fptr = fopen("bin/users.dat","ab+")) == '\0'){
	       	printf("   Error! File Tidak Dapat Dibuka...");
	       	MessageBeep(0);
		    exit(1);
		} else {
			TableHeaderUsers(CounterBaris+4, &CounterBaris);
			while(fread(&user, sizeof(user), 1, fptr)==1){
				if((strcmp(query,ToString(user.id_karyawan))==0) || (strcmp(query, user.nama)==0) || (strcmp(query, user.username)==0) || (strcmp(query, user.role)==0)){
					isFound = true;
				 	printg(CounterBaris=CounterBaris+1,4,"|");
				 	printg(CounterBaris,8,ToString(counter_jumlah=counter_jumlah+1));
				 	printg(CounterBaris,13,"\xb3");
				 	printg(CounterBaris,22,ToString(user.id_karyawan));
				 	printg(CounterBaris,36,"\xb3");
				 	printg(CounterBaris,40,((strlen(user.nama) <= 18) ? user.nama : strcat(substr(user.nama,0,14),"...")));
				 	printg(CounterBaris,63,"\xb3");
				 	printg(CounterBaris,67,((strlen(user.username) <= 18) ? user.username : strcat(substr(user.username,0,14),"...")));
				 	printg(CounterBaris,86,"\xb3");
				 	printg(CounterBaris,90,user.role);
				 	printg(CounterBaris,109,"\xb3");
					printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
				}
			}
			if(isFound==false){
				printf("\n   Data Tidak Ditemukan!\n\n");
			} else {
				printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
				printg(CounterBaris,18,ToString(counter_jumlah));
				printf("\n\n");
			}
		}
	   	fclose(fptr);
	   	ulangiUlangi:
		printf("   Cari Lagi? (Y/T) : "); fflush(stdin); scanf("%c", &ulangi);
		if(ulangi=='t' || ulangi=='T' || ulangi=='y' || ulangi=='Y'){
		} else {
			goto ulangiUlangi;			
		}
		counter_jumlah = 0;
		isFound=false;
		CounterBaris = 13;
	}
}

// Fungsi untuk melakukan login
int Login(Users *UserNow){
	FILE *fptr;
	Users user;
	char username[50];
	char password[50];
	char ch;

	printf("\n   \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda         \xda\xda\xda       \xda\xda\xda      \xda\xda\xda     \xda\xda\xda\n");
	printf("   \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda        \xda\xda\xda\xda\xda       \xda\xda\xda    \xda\xda\xda     \xda\xda\xda\xda\xda\n");
   	printf("           \xda\xda\xda       \xda\xda\xda \xda\xda\xda       \xda\xda\xda  \xda\xda\xda     \xda\xda\xda \xda\xda\xda\n");
	printf("           \xda\xda\xda      \xda\xda\xda   \xda\xda\xda        \xda\xda\xda\xda      \xda\xda\xda   \xda\xda\xda\n");
	printf("   \xda\xda\xda     \xda\xda\xda     \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda        \xda\xda      \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\n");
	printf("    \xda\xda\xda   \xda\xda\xda     \xda\xda\xda       \xda\xda\xda       \xda\xda     \xda\xda\xda       \xda\xda\xda\n");
	printf("      \xda\xda\xda\xda\xda      \xda\xda\xda         \xda\xda\xda      \xda\xda    \xda\xda\xda         \xda\xda\xda\n");
	printf("\n");
	 	 
	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda          \xda\xda\xda\xda          \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda     \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda     \xda\xda\xda\xda\xda\xda       \xda\xda\xda     \xda\xda\xda       \xda\xda\xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda         \xda\xda\xda\xda\xda\xda         \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda   \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda   \xda\xda\xda\xda \xda\xda\xda\xda\xda     \xda\xda\xda\xda    \xda\xda\xda     \xda\xda\xda\xda  \xda\xda\xda\xda\n");
   	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda        \xda\xda\xda  \xda\xda\xda        \xda\xda\xda       \xda\xda\xda        \xda\xda\xda\xda       \xda\xda\xda\xda    \xda\xda\xda\xda    \xda\xda\xda\xda\xda\xda  \xda\xda\xda    \xda\xda\xda\xda    \xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda       \xda\xda\xda    \xda\xda\xda       \xda\xda\xda      \xda\xda\xda         \xda\xda\xda\xda      \xda\xda\xda\xda      \xda\xda\xda\xda   \xda\xda\xda\xda\xda\xda\xda \xda\xda\xda   \xda\xda\xda\xda      \xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda      \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda      \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda          \xda\xda\xda\xda      \xda\xda\xda\xda      \xda\xda\xda\xda   \xda\xda\xda  \xda\xda\xda\xda\xda\xda   \xda\xda\xda\xda      \xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda     \xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda\xda     \xda\xda\xda     \xda\xda\xda          \xda\xda\xda\xda       \xda\xda\xda\xda    \xda\xda\xda\xda    \xda\xda\xda   \xda\xda\xda\xda\xda    \xda\xda\xda\xda    \xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda    \xda\xda\xda\xda        \xda\xda\xda\xda    \xda\xda\xda      \xda\xda\xda         \xda\xda\xda\xda        \xda\xda\xda\xda  \xda\xda\xda\xda     \xda\xda\xda    \xda\xda\xda\xda     \xda\xda\xda\xda  \xda\xda\xda\xda\n");
	printf("   \xda\xda\xda\xda      \xda\xda\xda\xda   \xda\xda\xda\xda          \xda\xda\xda\xda   \xda\xda\xda       \xda\xda\xda        \xda\xda\xda\xda          \xda\xda\xda\xda\xda\xda       \xda\xda\xda     \xda\xda\xda       \xda\xda\xda\xda\xda\xda\n");	

	printf("\n\n  Selamat Datang Di Sistem Toko Komputer Jaya Hartono\n");
	printf("\n  Masukkan Username : "); fflush(stdin); gets(username);
    printf("  Masukkan Password : ");

    int i=0;
    while(true){
    	ch = getch();
    	if(ch == ENTER || ch == TAB){
    		password[i] = '\0';
    		break;
		} else if (ch == BKSP){
			if(i > 0){
				i--;
				printf("\b \b");
			} 
		} else {
			password[i++] = ch;
			printf("* \b");
		}
	}
	
	printf("\n\n\t      CHECKING USER\n");
	MarqueeText("\n  \xb3\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb3",1999900);			

	if((fptr = fopen("bin/users.dat","rb")) == NULL){
       	printf("   Error! File Tidak Dapat Dibuka...");
	    exit(1);
	} else {
		while(fread(&user, sizeof(user), 1, fptr)==1){
			if(strcmp(username,user.username)==0 && strcmp(password,user.password)==0){
				*UserNow = user;
			   	fclose(fptr);
				return true;							
			}
		}
	}		
}

int ASCUser(const void* p, const void* q){ 
	return (((Users*)p)->id_karyawan - ((Users*)q)->id_karyawan); 
} 

int DSCUser(const void* p, const void* q){ 
	return (((Users*)q)->id_karyawan - ((Users*)p)->id_karyawan); 
} 

// Fungsi untuk melakukan validasi dalam penambahan user
int IsValidUser(int id_karyawan, char nama[50], char username[50], char password[50], char role[16], char mode){
	FILE *fptr;
	Users user;
	char idStr[2];
	if(strlen(nama) > 0 && strlen(username) > 0 && strlen(password) > 0 && strlen(role) > 0){
		if(strlen(ToString(id_karyawan)) < 7 && strlen(nama) <= 50 && strlen(username) <= 50 && strlen(password) <= 50 && strlen(role) <= 16){
			if(strcmp(role,"Kasir")==0 || strcmp(role, "Gudang")==0 || strcmp(role, "Administrator")==0){
				if(mode=='n'){
					if((fptr = fopen("bin/users.dat","rb")) == NULL){
				       	printf("\t\t\t\tError! File Tidak Dapat Dibuka...");
				       	MessageBeep(0);
					    exit(1);				
					} else {
						while(fread(&user,sizeof(Users),1,fptr)==1){
							sprintf(idStr, "%d", user.id_karyawan);
							if(strcmp(ToString(id_karyawan), idStr)==0 || strcmp(username, user.username)==0){
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
