#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "members.h"
#include "tools.h"

// Procedure untuk menampilkan header table
void TableHeaderMembers(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR MEMBER");
	printg(yCoordAwal=yCoordAwal+1,45,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,4,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,4,"\xb3");
 	printg(yCoordAwal,7,"NO");
	printg(yCoordAwal,11,"\xb3");
 	printg(yCoordAwal,14,"ID MEMBER");
 	printg(yCoordAwal,25,"\xb3");
 	printg(yCoordAwal,30,"NAMA LENGKAP");
 	printg(yCoordAwal,46,"\xb3");
 	printg(yCoordAwal,49,"JENIS KELAMIN");
 	printg(yCoordAwal,64,"\xb3");
 	printg(yCoordAwal,69,"PEKERJAAN");
 	printg(yCoordAwal,82,"\xb3");
 	printg(yCoordAwal,88.5,"TTL");
 	printg(yCoordAwal,97,"\xb3"); 
 	printg(yCoordAwal,102,"Kota Asal");
 	printg(yCoordAwal,115,"\xb3"); 	 	
	printg(yCoordAwal=yCoordAwal+1,4,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

// Fungsi (constructor) untuk menambahkan user baru
FILE TambahMember(char mode){
	Members member;
	FILE *fptr;
	int jml, counter = 1, hari, bulan, tahun;
	char *tambahMember[6] = {"\n\n   Beranda","Kelola Member","Tambah Member\n\n\n",NULL,NULL,NULL};				
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Jenis Kelamin Hanya Bisa Diisi Dengan l atau p",
		"Masukkan Tanggal Lahir Dengan Format HH/BB/TTTT",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	if(mode=='y'){
		Breadcrumb(tambahMember);
		Persyaratan(syarat);				
	}
	ulangiJumlah:
	printf("\n   Berapa Data Yang Ditambahkan : "); fflush(stdin);
	if(scanf("%d", &jml) != 1) {
		printf("   Masukkan Angka!\n");
		goto ulangiJumlah;
	}
	while(counter<=jml){
		ulangi:
		if((fptr = fopen("bin/members.dat","ab")) == NULL){
	       printf("   Error! File Tidak Dapat Dibuka...");
	       exit(1);
	   	}else{
   			printf("\n   Masukkan Data Ke-%d\n", counter);
			member.id_member = RandomNumber(10000,99999);	
			printf("   %-26s :  ","Nama Lengkap"); fflush(stdin); gets(member.namaLengkap);
			printf("   %-26s :  ","Jenis Kelamin [l/p]"); fflush(stdin); gets(member.JK);
			printf("   %-26s :  ","Tanggal Lahir [HH/BB/TTTT]"); fflush(stdin); scanf("%d/%d/%d",&hari, &bulan, &tahun);
			printf("   %-26s :  ","Pekerjaan"); fflush(stdin); gets(member.pekerjaan);
			printf("   %-26s :  ","Kota Asal"); fflush(stdin); gets(member.kotaAsal);
			if(IsValidMember(member.id_member, member.namaLengkap, member.JK, hari, bulan, tahun, member.pekerjaan, member.kotaAsal,'n')){
				member.tanggal.hari = hari;
				member.tanggal.bulan = bulan;
				member.tanggal.tahun = tahun;
				fwrite(&member, sizeof(Members), 1, fptr);
				fclose(fptr);
				printf("\n   %d Data Berhasil Ditambahkan!\n\n", jml);
			} else {
				printf("\n   Masukkan Data Dengan Benar\n");
				hari = 0; bulan = 0; tahun = 0;
				fclose(fptr);	
				goto ulangi;
			}
		}
		counter++;
		if(counter<=jml){
			system("cls");
			if(mode=='y'){
			   	Breadcrumb(tambahMember);		
	   			Persyaratan(syarat);					
			}
		}
	}
}

// Procedure untuk melakukan pengurutan data users
void TampilkanMember(char mode, int *counterRow){
	int type;
	Members member;
	Members arrMembers[20];
	FILE *fptr;
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/members.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&member, sizeof(Members), 1, fptr)==1){
			arrMembers[counter_jumlah]=member;
			counter_jumlah++;
		}
		if(mode=='c'){
			TableHeaderMembers(*counterRow, &CounterBaris);
			qsort(arrMembers, counter_jumlah, sizeof(Members), ASCMember);
		} else if(mode=='n'){
			ulangi:
			printf("\n   ");
			printf(" *) Mode Urutan\n\n    1. Ascending\n\n    2. Descending\n\n    Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderMembers(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrMembers, counter_jumlah, sizeof(Members), ASCMember); 
					break;
				case 2:
					qsort(arrMembers, counter_jumlah, sizeof(Members), DSCMember); 
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
		 	printg(CounterBaris,16,ToString(arrMembers[i].id_member));
		 	printg(CounterBaris,25,"\xb3");
		 	printg(CounterBaris,28.5,((strlen(arrMembers[i].namaLengkap) <= 18) ? arrMembers[i].namaLengkap : strcat(substr(arrMembers[i].namaLengkap,0,14),"...")));
		 	printg(CounterBaris,46,"\xb3");
		 	printg(CounterBaris,51,(strcmp(arrMembers[i].JK,"L")==0 || strcmp(arrMembers[i].JK,"l")==0) ? "Laki-Laki" : "Perempuan");
		 	printg(CounterBaris,64,"\xb3");
		 	printg(CounterBaris,67,arrMembers[i].pekerjaan);
		 	printg(CounterBaris,82,"\xb3");
		 	printg(CounterBaris,85,strcat(ToString(arrMembers[i].tanggal.hari),"/"));
		 	printg(CounterBaris,88,strcat(ToString(arrMembers[i].tanggal.bulan),"/"));
		 	printg(CounterBaris,91,ToString(arrMembers[i].tanggal.tahun));
			printg(CounterBaris,97,"\xb3");
			printg(CounterBaris,100,((strlen(arrMembers[i].kotaAsal) <= 11) ? arrMembers[i].kotaAsal : strcat(substr(arrMembers[i].kotaAsal,0,11),"...")));
			printg(CounterBaris,115,"\xb3");		 	
			printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
		printg(CounterBaris,18,ToString(counter_jumlah));
	 	fclose(fptr);	
	 	*counterRow = CounterBaris;
	 	printf("\n");
	}
}

// Procedure untuk menghapus member
FILE HapusMember(){
	Members member;
	FILE *fptr, *temp;
	char query[20];
	char yakin;
	int status = false, isFound = false, counterRow = 12;
	char *syarat[10] = {
		"Masukkan ID Member Untuk Menghapus Member",
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
	TampilkanMember('c', &counterRow);
	ulangiMember:
	printf("\n   Masukkan ID Member : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/members.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&member, sizeof(Members), 1, fptr)==1){
			if(strcmp(query, ToString(member.id_member))!=0){
				fwrite(&member, sizeof(Members), 1, temp);
			}
			if(strcmp(query, ToString(member.id_member))==0){
				isFound = true;
				printf("   %-26s :  %d\n","ID Member", member.id_member);
				printf("   %-26s :  %s\n","Nama Lengkap", member.namaLengkap);
				printf("   %-26s :  %s\n","Jenis Kelamin [l/p]", (strcmp(member.JK,"L")==0 || strcmp(member.JK,"l")==0) ? "Laki-Laki" : "Perempuan");
				printf("   %-26s :  %d/%d/%d\n","Tanggal Lahir [HH/BB/TTTT]", member.tanggal.hari, member.tanggal.bulan, member.tanggal.tahun);
				printf("   %-26s :  %s\n","Pekerjaan", member.pekerjaan);
				printf("   %-26s :  %s\n\n","Kota Asal", member.kotaAsal);
				
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
			goto ulangiMember;
		}				
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			printf("   Data Berhasil Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			unlink("bin/members.dat");
			rename("bin/temp.dat","bin/members.dat");
		}
	}
}

// Procedure untuk mengubah member
FILE UbahMember(){
	Members member;
	FILE *fptr;
	int counterRow = 12, hari, bulan, tahun;
	char query[20], isFound;
	char *syarat[10] = {
		"Masukkan ID Member Untuk Mengubah Member",
		"Pastikan Semua Kolom Sudah Terisi", 
		"Jenis Kelamin Hanya Bisa Diisi Dengan l atau p",
		"Masukkan Tanggal Lahir Dengan Format HH/BB/TTTT",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);		
	TampilkanMember('c', &counterRow);
	ulangiMember:
	printf("\n   Masukkan ID Member : "); scanf("%s", &query);
   	if((fptr = fopen("bin/members.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&member, sizeof(Members), 1, fptr)==1){
			if(strcmp(query, ToString(member.id_member))==0){
				isFound = true;				
				fflush(stdin);
				printf("\n   *) Data Terkini\n");				
				printf("   %-26s :  %d\n","ID Member", member.id_member);
				printf("   %-26s :  %s\n","Nama Lengkap", member.namaLengkap);
				printf("   %-26s :  %s\n","Jenis Kelamin [l/p]", (strcmp(member.JK,"L")==0 || strcmp(member.JK,"l")==0) ? "Laki-Laki" : "Perempuan");
				printf("   %-26s :  %d/%d/%d\n","Tanggal Lahir [HH/BB/TTTT]", member.tanggal.hari, member.tanggal.bulan, member.tanggal.tahun);
				printf("   %-26s :  %s\n","Pekerjaan", member.pekerjaan);
				printf("   %-26s :  %s\n\n","Kota Asal", member.kotaAsal);
					
				printf("   *) Perbaharui Data!\n");					
				ulangi:
				member.id_member = member.id_member;
				printf("   %-26s :  ","Nama Lengkap"); fflush(stdin); gets(member.namaLengkap);
				printf("   %-26s :  ","Jenis Kelamin [l/p]"); fflush(stdin); scanf("%c", &member.JK);
				printf("   %-26s :  ","Tanggal Lahir [HH/BB/TTTT]"); fflush(stdin); scanf("%d/%d/%d", &hari, &bulan, &tahun);
				printf("   %-26s :  ","Pekerjaan"); fflush(stdin); gets(member.pekerjaan);
				printf("   %-26s :  ","Kota Asal"); fflush(stdin); gets(member.kotaAsal);				
				if(IsValidMember(member.id_member, member.namaLengkap, member.JK, hari, bulan, tahun, member.pekerjaan, member.kotaAsal,'c')){
					member.tanggal.hari = hari;
					member.tanggal.bulan = bulan;
					member.tanggal.tahun = tahun;
					fseek(fptr, (long) -sizeof(Members), SEEK_CUR);
					fwrite(&member, sizeof(Members), 1, fptr);
				   	fclose(fptr);	
					printf("\n   Data Berhasil Diperbaharui!\n\n");
					break;	
				} else {
					printf("\n   Masukkan data dengan benar!\n");
					hari = 0; bulan = 0; tahun = 0;
					goto ulangi;
				}														
			}
		}
		if(isFound==false){
			printf("   Member Tidak Ditemukan\n");
			fclose(fptr);
			goto ulangiMember;
		}		
	}
}

// Procedure untuk melakukan pencarian
void CariMember(){
	Members member;
	FILE *fptr;
	char query[20], ulangi='y';
	char *syarat[10] = {
		"Masukkan ID Member/Nama Lengkap/Jenis Kelamin/TTL/Kota Asal",
		"Untuk Mencari Jenis Kelamin, Masukkan l/p",
		"Untuk Mencari TTL, Masukkan Dengan Format HH/BB/TTTT",
		"Anda Bisa Mengulangi Pencarian",
		"Masukkan Y/Y Untuk Mengulangi Pencarian",
		"Masukman T/t Untuk Kembali Ke Menu Sebelumnya", 
		NULL,
		NULL,
		NULL,
		NULL,
	};	
	int isFound = false, counter_jumlah=0, CounterBaris = 14;
	while(ulangi=='y'){
		system("cls");
		char *cariMember[6] = {"\n\n   Beranda","Kelola Member","Cari Member\n\n\n",NULL,NULL,NULL};													
		Breadcrumb(cariMember);
		Persyaratan(syarat);				
		TampilkanMember('c', &CounterBaris);
		printf("\n   Masukkan Kata Kunci : "); fflush(stdin); gets(query);
	   	if((fptr = fopen("bin/members.dat","ab+")) == '\0'){
	       	printf("   Error! File Tidak Dapat Dibuka...");
	       	MessageBeep(0);
		    exit(1);
		} else {
			TableHeaderMembers(CounterBaris+4, &CounterBaris);
			while(fread(&member, sizeof(Members), 1, fptr)==1){
				if((strcmp(query,ToString(member.id_member))==0) || (strcmp(query, member.namaLengkap)==0) || (strcmp(query, member.JK)==0) || (strcmp(query, member.pekerjaan)==0 || (strcmp(query, member.kotaAsal)==0))){
					isFound = true;
				 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
				 	printg(CounterBaris,7,ToString(counter_jumlah=counter_jumlah+1));
				 	printg(CounterBaris,11,"\xb3");
				 	printg(CounterBaris,16,ToString(member.id_member));
				 	printg(CounterBaris,25,"\xb3");
				 	printg(CounterBaris,28.5,((strlen(member.namaLengkap) <= 18) ? member.namaLengkap : strcat(substr(member.namaLengkap,0,14),"...")));
				 	printg(CounterBaris,46,"\xb3");
				 	printg(CounterBaris,51,(strcmp(member.JK,"L")==0 || strcmp(member.JK,"l")==0) ? "Laki-Laki" : "Perempuan");
				 	printg(CounterBaris,64,"\xb3");
				 	printg(CounterBaris,67,member.pekerjaan);
				 	printg(CounterBaris,82,"\xb3");
				 	printg(CounterBaris,85,strcat(ToString(member.tanggal.hari),"/"));
				 	printg(CounterBaris,88,strcat(ToString(member.tanggal.bulan),"/"));
				 	printg(CounterBaris,91,ToString(member.tanggal.tahun));
					printg(CounterBaris,97,"\xb3");
					printg(CounterBaris,100,((strlen(member.kotaAsal) <= 11) ? member.kotaAsal : strcat(substr(member.kotaAsal,0,11),"...")));
					printg(CounterBaris,115,"\xb3");
					printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
				}
			}
			if(isFound==false){
				printf("\n   Data Tidak Ditemukan!\n\n\n");
			} else {
				printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
				printg(CounterBaris,18,ToString(counter_jumlah));
			}
			printf("\n\n");
		}
	   	fclose(fptr);
	   	ulangiUlangi:
		printf("   Cari Lagi? [Y/T] : "); fflush(stdin); scanf("%c", &ulangi);
		if(ulangi=='t' || ulangi=='T' || ulangi=='y' || ulangi=='Y'){
		} else {
			goto ulangiUlangi;			
		}
		counter_jumlah = 0;
		isFound=false;
		CounterBaris = 14;
	}
}

int ASCMember(const void* p, const void* q){ 
	return (((Members*)p)->id_member - ((Members*)q)->id_member); 
} 

int DSCMember(const void* p, const void* q){ 
	return (((Members*)q)->id_member - ((Members*)p)->id_member); 
} 

int IsMember(char id_member[10]){
	Members member;
	FILE *fptr;
	if((fptr = fopen("bin/members.dat","ab+")) == '\0'){
	   	printf("\t\t\t\tError! File Tidak Dapat Dibuka...");
	   	MessageBeep(0);
	    exit(1);
	} else {	
		while(fread(&member, sizeof(Members), 1, fptr)==1){
			if(strcmp(id_member,ToString(member.id_member))==0){
				return true;
			}
		}
	}
	return false;
}

// Procedure untuk melakukan validasi dalam penambahan member
int IsValidMember(int id_member, char nama[50], char jk[3], int tanggal, int bulan, int tahun, char pekerjaan[50], char kotaAsal[50], char mode){
	FILE *fptr;
	Members member;
	char idStr[2];
	if(strlen(nama) > 0 && strlen(jk) > 0 && strlen(pekerjaan) > 0 && strlen(kotaAsal) > 0 && strlen(ToString(tanggal)) > 0 && strlen(ToString(bulan)) > 0 && strlen(ToString(tahun)) > 0){
		if(tanggal != 0 && bulan != 0 && tahun != 0 && strlen(ToString(id_member)) < 7 && strlen(nama) <= 50 && strlen(jk) <= 1 && tanggal <= 31 && bulan <= 12 && strlen(ToString(tanggal)) <= 2 && strlen(ToString(bulan)) <= 2 && strlen(ToString(tahun)) <= 4 && strlen(pekerjaan) < 50 && strlen(kotaAsal) < 50){		
			if(strcmp(jk,"L")==0 || strcmp(jk,"P")==0 || strcmp(jk,"p")==0 || strcmp(jk,"l")==0){
				if(mode=='n'){
					if((fptr = fopen("bin/members.dat","rb")) == NULL){
				       	printf("   Error! File Tidak Dapat Dibuka...");
				       	MessageBeep(0);
					    exit(1);				
					} else {
						while(fread(&member,sizeof(Members),1,fptr)==1){
							sprintf(idStr, "%d", member.id_member);
							if(strcmp(ToString(id_member), idStr)==0){
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
