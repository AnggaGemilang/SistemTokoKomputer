#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "barang.h"
#include "tools.h"

// Procedure untuk menampilkan header table
void TableHeaderBarang(int yCoordAwal, int *barisTerakhir){
	printg(yCoordAwal,51,"DAFTAR BARANG");
	printg(yCoordAwal=yCoordAwal+1,45,"TOKO KOMPUTER JAYA HARTONO");	
	printg(yCoordAwal=yCoordAwal+2,4,"\xda\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc2\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
 	printg(yCoordAwal=yCoordAwal+1,4,"\xb3");
 	printg(yCoordAwal,7,"NO");
	printg(yCoordAwal,11,"\xb3");
 	printg(yCoordAwal,15,"ID");
 	printg(yCoordAwal,20,"\xb3");
 	printg(yCoordAwal,22,"KATEGORI");
 	printg(yCoordAwal,31,"\xb3");
 	printg(yCoordAwal,37,"NAMA");
 	printg(yCoordAwal,46,"\xb3");
 	printg(yCoordAwal,50,"MEREK");
 	printg(yCoordAwal,57,"\xb3");
 	printg(yCoordAwal,59,"KONDISI");
 	printg(yCoordAwal,67,"\xb3"); 
 	printg(yCoordAwal,70,"SEWA");
 	printg(yCoordAwal,76,"\xb3"); 
 	printg(yCoordAwal,78,"JUMLAH");
 	printg(yCoordAwal,85,"\xb3");
	printg(yCoordAwal,91,"HARGA");
	printg(yCoordAwal,100,"\xb3");
	printg(yCoordAwal,103,"TANGGAL MASUK");
	printg(yCoordAwal,118,"\xb3"); 	 	
	printg(yCoordAwal=yCoordAwal+1,4,"\xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc1\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
	*barisTerakhir = yCoordAwal;
}

// Fungsi (constructor) untuk menambahkan user baru
FILE TambahBarang(char mode){
	Barang stok;
	FILE *fptr;
	int jml, counter = 1, jml_stok, harga;
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Kondisi Barang Hanya Boleh Diisi Oleh baru/bekas/rusak", 
		"Barang Sewa Hanya Boleh Diisi Oleh y (Barang Sewa) atau t (Bukan Barang Sewa)",
		"Jumlah Barang Hanya Boleh Diisi Dari 1 sampai 500",
		"Harga Barang Hanya Boleh Diisi Dari Rp. 1 sampai Rp. 1.000.000.000",
		"Status Barang Hanya Boleh Diisi Oleh aktif/nonaktif",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	char *tambahBarang[6] = {"\n\n   Beranda","Kelola Barang","Tambah Barang\n\n\n",NULL,NULL,NULL};				
	if(mode=='y'){
		Breadcrumb(tambahBarang);	
	}
	Persyaratan(syarat);	
	ulangiJumlah:
	printf("\n   Berapa Data Yang Ditambahkan : "); fflush(stdin);
	if(scanf("%d", &jml) != 1) {
		printf("   Masukkan Angka!\n");
		goto ulangiJumlah;
	}
	while(counter<=jml){
		ulangi:
		if((fptr = fopen("bin/stock.dat","ab")) == NULL){
	       printf("   Error! File Tidak Dapat Dibuka...");
	       exit(1);
	   	}else{
   			printf("\n   Masukkan Data Ke-%d\n", counter);
			stok.barang_id = RandomNumber(10000,99999); 				
			printf("   %-34s :  ","Kategori [pc/laptop]"); fflush(stdin); gets(stok.kategori_barang);
			printf("   %-34s :  ","Nama barang"); fflush(stdin); gets(stok.nama_barang);
			printf("   %-34s :  ","Merk barang"); fflush(stdin); gets(stok.merk_barang);
			printf("   %-20s :  ","Kondisi barang [baru/bekas/rusak] "); fflush(stdin); gets(stok.kondisi_barang);
			printf("   %-34s :  ","Barang Sewa [y/t]"); fflush(stdin); gets(stok.barang_sewa);
			printf("   %-34s :  ","Jumlah barang [1-500]"); fflush(stdin); scanf("%d",&jml_stok);
			printf("   %-34s :  Rp. ","Harga barang [1-1000000000]"); fflush(stdin); scanf("%d",&harga);
			strcpy(stok.status,"aktif");
			stok.tanggal = GetNow();
			if(IsValidBarang(stok.barang_id, stok.kategori_barang, stok.nama_barang, stok.merk_barang, stok.kondisi_barang, jml_stok, harga, stok.barang_sewa, stok.status,'n')){
				stok.jml_barang = jml_stok;
				stok.hrg = harga;
				fwrite(&stok, sizeof(Barang), 1, fptr);
				fclose(fptr);				
			} else {
				printf("\n   Masukkan Data Dengan Benar\n");
				jml_stok = 0;
				harga = 0;
				fclose(fptr);
				goto ulangi;
			}
		}
		counter++;
		if(counter<=jml){
			system("cls");
			if(mode=='y'){
				Breadcrumb(tambahBarang);
				printf("\n   ");	
				Persyaratan(syarat);
			}
		}
	}
	if(fwrite != 0){
		printf("\n   %d Data Berhasil Ditambahkan!\n\n", jml);
	} else {
		printf("\n   Data Gagal Ditambahkan!\n\n");
	}
}

// Procedure untuk melakukan pengurutan data users
FILE TampilkanBarang(char mode, char isSewa, char isBaru, int *counterRow, char isAktif, char isNonaktif){
	int type;
	char query[20];
	Barang stok;
	Barang arrBarang[20];
	FILE *fptr;
	int counter_jumlah = 0, counter_no = 1, i, CounterBaris;
	if((fptr = fopen("bin/stock.dat","rb")) == NULL){
    	printf("   Error! File Tidak Dapat Dibuka...");
       	MessageBeep(0);
	    exit(1);
	} else {
		while(fread(&stok, sizeof(Barang), 1, fptr)==1){
			if(((isSewa=='y') ? strcmp(stok.barang_sewa,"y")==0 : true) && ((isSewa=='d') ? strcmp(stok.barang_sewa,"t")==0 : true) && ((isBaru=='e') ? strcmp(stok.kondisi_barang,"baru")==0 : true) && ((isAktif=='y') ? strcmp(stok.status,"aktif")==0 : true) && ((isNonaktif=='y') ? strcmp(stok.status,"nonaktif")==0 : true)){
				arrBarang[counter_jumlah]=stok;
				counter_jumlah++;
			}
	    }
		if(mode=='c'){
			TableHeaderBarang(*counterRow, &CounterBaris);
			qsort(arrBarang, counter_jumlah, sizeof(Barang), ASCBarang);
		} else if(mode=='n'){
			ulangi:
			printf("*) Mode Urutan\n\n   1. Ascending\n\n   2. Descending\n\n   Masukkan Mode : ");
			scanf("%d", &type);
			TableHeaderBarang(*counterRow, &CounterBaris);
			switch(type){
				case 1:
				    qsort(arrBarang, counter_jumlah, sizeof(Barang), ASCBarang); 
					break;
				case 2:
					qsort(arrBarang, counter_jumlah, sizeof(Barang), ASCBarang); 
					break;
				default:
					printf("   Masukkan Angka Yang Benar!\n");
					goto ulangi;
					break;
			}
		}
	    for (i=0; i < counter_jumlah; i++){
		 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
		 	printg(CounterBaris,7,ToString(i+1));
		 	printg(CounterBaris,11,"\xb3");
		 	printg(CounterBaris,13,ToString(arrBarang[i].barang_id));
		 	printg(CounterBaris,20,"\xb3");
		 	printg(CounterBaris,22,arrBarang[i].kategori_barang);
		 	printg(CounterBaris,31,"\xb3");
		 	printg(CounterBaris,33,((strlen(arrBarang[i].nama_barang) <= 18) ? arrBarang[i].nama_barang : strcat(substr(arrBarang[i].nama_barang,0,14),"...")));
		 	printg(CounterBaris,46,"\xb3");
		 	printg(CounterBaris,48,arrBarang[i].merk_barang);
		 	printg(CounterBaris,57,"\xb3");
		 	printg(CounterBaris,59,arrBarang[i].kondisi_barang);
		 	printg(CounterBaris,67,"\xb3");
		 	printg(CounterBaris,69,(strcmp(arrBarang[i].barang_sewa,"Y")==0 || strcmp(arrBarang[i].barang_sewa,"y")==0) ? "IYA" : "TIDAK");
		 	printg(CounterBaris,76,"\xb3");
		 	printg(CounterBaris,79,ToString(arrBarang[i].jml_barang));
			printg(CounterBaris,85,"\xb3");
			printg(CounterBaris,87,ToString(arrBarang[i].hrg));
			printg(CounterBaris,100,"\xb3");
		 	printg(CounterBaris,104,strcat(ToString(arrBarang[i].tanggal.tanggal.hari),"/"));
		 	printg(CounterBaris,107,strcat(ToString(arrBarang[i].tanggal.tanggal.bulan),"/"));
		 	printg(CounterBaris,110,ToString(arrBarang[i].tanggal.tanggal.tahun));
			printg(CounterBaris,118,"\xb3");	 	
			printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
	    }
		printg(CounterBaris=CounterBaris+1,4,"Jumlah Data : ");
		printg(CounterBaris,18,ToString(counter_jumlah));
	 	fclose(fptr);
	 	*counterRow = CounterBaris;
	 	printf("\n");
	}
}

// Procedure untuk menghapus member
FILE HapusBarang(){
	Barang stok;
	FILE *fptr, *temp;
	char query[20];
	char yakin, ulangi = 'y', isFound = false;
	int status = false, counterRow = 12;
	char *syarat[10] = {
		"Masukkan ID Barang Untuk Menghapus Barang",
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
	TampilkanBarang('c','t','t',&counterRow,'t','t');
	ulangiBarang:	
	printf("\n   Masukkan ID barang : "); fflush(stdin); scanf("%s", &query);
	temp = fopen("bin/temp.dat", "wb");
	if((fptr = fopen("bin/stock.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&stok, sizeof(Barang), 1, fptr)==1){
			if(strcmp(query, ToString(stok.barang_id))!=0){
				fwrite(&stok, sizeof(Barang), 1, temp);
			}
			if(strcmp(query, ToString(stok.barang_id))==0){
				isFound = true;
				printf("   %-34s :  %d\n","ID Barang", stok.barang_id);
				printf("   %-34s :  %s\n","Kategori [pc/laptop]", stok.kategori_barang);
				printf("   %-34s :  %s\n","Nama barang", stok.nama_barang);
				printf("   %-34s :  %s\n","Merk barang", stok.merk_barang);
				printf("   %-34s :  %s\n","Kondisi barang [Baru/Bekas/Rusak]", stok.kondisi_barang);
				printf("   %-34s :  %s\n","Barang Sewa [y/t]", (strcmp(stok.barang_sewa,"Y")==0 || strcmp(stok.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
				printf("   %-34s :  %d\n","Jumlah barang [1-500]", stok.jml_barang);
				printf("   %-34s :  Rp. %d\n","Harga barang [1-1000000000]", stok.hrg);
				printf("   %-28s  :  %d/%d/%d\n","Tanggal Masuk Barang [HH/BB/TTTT]", stok.tanggal.tanggal.hari, stok.tanggal.tanggal.bulan, stok.tanggal.tanggal.tahun);
				printf("   %-34s :  %s\n","Status barang", stok.status);	
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
			goto ulangiBarang;
		}					
		if(status==false){
			gagal:
			printf("   Data Gagal Dihapus!\n\n");
			fclose(fptr);
			fclose(temp);
			remove("bin/temp.dat");
		} else if(status==true) {
			if(fwrite != 0){
				printf("\n   Data Berhasil Dihapus!\n\n");
			}
			fclose(fptr);
			fclose(temp);
			remove("bin/stock.dat");
			rename("bin/temp.dat","bin/stock.dat");
		}
	}
}

// Procedure untuk mengubah member
FILE UbahBarang(){
	Barang stok;
	FILE *fptr;
	int counterRow = 14, isFound = false, jml_stok, harga;
	char query[20];
	char *syarat[10] = {
		"Pastikan Semua Kolom Sudah Terisi", 
		"Kondisi Barang Hanya Boleh Diisi Oleh baru, bekas, atau rusak", 
		"Barang Sewa Hanya Boleh Diisi Oleh y (Barang Sewa) atau t (Bukan Barang Sewa)",
		"Jumlah Barang Hanya Boleh Diisi Dari 1 sampai 500",
		"Harga Barang Hanya Boleh Diisi Dari Rp. 1 sampai Rp. 1.000.000.000",
		"Status Barang Hanya Boleh Diisi Oleh aktif/nonaktif",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);		
	TampilkanBarang('c','t','t',&counterRow,'t','t');
	ulangiBarang:
	printf("\n   Masukkan ID Barang : "); scanf("%s", &query);
   	if((fptr = fopen("bin/stock.dat","rb+")) == '\0'){
       	printf("\n   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&stok, sizeof(Barang), 1, fptr)==1){
			if(strcmp(query, ToString(stok.barang_id))==0){
				fflush(stdin);
				isFound = true;
				printf("\n    *) Data Terkini\n");									
				printf("   %-34s :  %d\n","ID Barang", stok.barang_id);
				printf("   %-34s :  %s\n","Kategori [pc/laptop]", stok.kategori_barang);
				printf("   %-34s :  %s\n","Nama barang", stok.nama_barang);
				printf("   %-34s :  %s\n","Merk barang", stok.merk_barang);
				printf("   %-34s :  %s\n","Kondisi barang [Baru/Bekas/Rusak]", stok.kondisi_barang);
				printf("   %-34s :  %s\n","Barang Sewa [y/t]", (strcmp(stok.barang_sewa,"Y")==0 || strcmp(stok.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
				printf("   %-34s :  %d\n","Jumlah barang [1-500]", stok.jml_barang);
				printf("   %-34s :  Rp. %d\n","Harga barang [1-1000000000]", stok.hrg);
				printf("   %-28s  :  %d/%d/%d\n","Tanggal Masuk Barang [HH/BB/TTTT]", stok.tanggal.tanggal.hari, stok.tanggal.tanggal.bulan, stok.tanggal.tanggal.tahun);
				printf("   %-34s :  %s\n","Status barang", stok.status);	
										
				printf("\n   *) Perbaharui Data!\n");					
				ulangi:
				stok.barang_id = stok.barang_id;
				printf("   %-34s :  ","Kategori [pc/laptop]"); fflush(stdin); gets(stok.kategori_barang);
				printf("   %-34s :  ","Nama barang"); fflush(stdin); gets(stok.nama_barang);
				printf("   %-34s :  ","Merk barang"); fflush(stdin); gets(stok.merk_barang);
				printf("   %-34s :  ","Kondisi barang [Baru/Bekas/Rusak]"); fflush(stdin); gets(stok.kondisi_barang);
				printf("   %-34s :  ","Barang Sewa [y/t]"); fflush(stdin); gets(stok.barang_sewa);
				printf("   %-34s :  ","Jumlah barang [1-500]"); fflush(stdin); scanf("%d", &jml_stok);
				printf("   %-34s :  Rp. ","Harga barang [1-10000000000]"); fflush(stdin); scanf("%d", &harga);
				printf("   %-34s :  ","Status [aktif/nonaktif]"); fflush(stdin); gets(stok.status);
				stok.tanggal = GetNow();				
				if(IsValidBarang(stok.barang_id, stok.kategori_barang, stok.nama_barang, stok.merk_barang, stok.kondisi_barang, jml_stok, harga, stok.barang_sewa, stok.status, 'c')){
					stok.jml_barang = jml_stok;
					stok.hrg = harga;
					fseek(fptr, (long) -sizeof(Barang), SEEK_CUR);
					fwrite(&stok, sizeof(Barang), 1, fptr);
					if(fwrite != 0){
						printf("\n   Data Berhasil Diperbaharui!\n");
					} else {
						MessageBeep(0);
						printf("   Data Gagal Diperbaharui!\n");
					}
					break;	
				} else {
					printf("\n   Masukkan data dengan benar!\n");
					jml_stok = 0;
					harga = 0;		
					goto ulangi;
				}																
			}
		}
		if(isFound==false){
			printf("   Barang Tidak Ditemukan\n");
			goto ulangiBarang;
		}				
	   	fclose(fptr);
	}
}

// Procedure untuk melakukan pencarian
void CariBarang(){
	Barang stok;
	FILE *fptr;
	char query[20], ulangi='y';
	int isFound = false, counter_jumlah=0, CounterBaris = 17;
	char *syarat[10] = {
		"Masukkan ID Barang/Kategori/Nama/Merek/Kondisi/IsSewa/Qty/Harga/Status/Tgl Masuk",
		"Untuk Mencari Kategori, Masukkan laptop/pc",
		"Untuk Mencari Kondisi, Masukkan baru/bekas/rusak",
		"Untuk Mencari IsSewa, Masukkan y (Barang Sewa) atau t (Bukan Barang Sewa)",
		"Untuk Mencari Status, Masukkan aktif/nonaktif",		
		"Untuk Mencari TTL, Masukkan Dengan Format HH/BB/TTTT",
		"Anda Bisa Mengulangi Pencarian",
		"Masukkan Y/Y Untuk Mengulangi Pencarian",
		"Masukman T/t Untuk Kembali Ke Menu Sebelumnya", 
		NULL,
	};	
	while(ulangi=='y'){
		system("cls");
		char *cariBarang[6] = {"\n\n   Beranda","Kelola Barang","Cari Barang\n\n\n",NULL,NULL,NULL};
		Breadcrumb(cariBarang);
		Persyaratan(syarat);		
		TampilkanBarang('c','t','t', &CounterBaris,'t','t');
		printf("\n   Masukkan Kata Kunci : "); fflush(stdin); gets(query);
	   	if((fptr = fopen("bin/stock.dat","ab+")) == '\0'){
	       	printf("   Error! File Tidak Dapat Dibuka...");
	       	MessageBeep(0);
		    exit(1);
		} else {
			TableHeaderBarang(CounterBaris+4, &CounterBaris);
			while(fread(&stok, sizeof(Barang), 1, fptr)==1){
				if((strcmp(query,ToString(stok.barang_id))==0) || (strcmp(query, stok.kategori_barang)==0) || (strcmp(query, stok.nama_barang)==0) || (strcmp(query, stok.merk_barang)==0) || (strcmp(query, stok.kondisi_barang)==0) || (strcmp(query, stok.barang_sewa)==0) || (strcmp(query, stok.status)==0)){
					isFound = true;
				 	printg(CounterBaris=CounterBaris+1,4,"\xb3");
				 	printg(CounterBaris,7,ToString(counter_jumlah=counter_jumlah+1));
					printg(CounterBaris,11,"\xb3");
				 	printg(CounterBaris,13,ToString(stok.barang_id));
				 	printg(CounterBaris,20,"\xb3");
				 	printg(CounterBaris,22,stok.kategori_barang);
				 	printg(CounterBaris,31,"\xb3");
				 	printg(CounterBaris,33,stok.nama_barang);
				 	printg(CounterBaris,46,"\xb3");
				 	printg(CounterBaris,48,stok.merk_barang);
				 	printg(CounterBaris,57,"\xb3");
				 	printg(CounterBaris,59,stok.kondisi_barang);
				 	printg(CounterBaris,67,"\xb3");
					printg(CounterBaris,69,(strcmp(stok.barang_sewa,"Y")==0 || strcmp(stok.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
					printg(CounterBaris,76,"\xb3");
					printg(CounterBaris,79,ToString(stok.jml_barang));
					printg(CounterBaris,85,"\xb3");
				    printg(CounterBaris,87,ToString(stok.hrg));
				    printg(CounterBaris,100,"\xb3");
				 	printg(CounterBaris,104,strcat(ToString(stok.tanggal.tanggal.hari),"/"));
				 	printg(CounterBaris,107,strcat(ToString(stok.tanggal.tanggal.bulan),"/"));
				 	printg(CounterBaris,110,ToString(stok.tanggal.tanggal.tahun));
					printg(CounterBaris,118,"\xb3");
					printg(CounterBaris=CounterBaris+1,4,"\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4");
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
		counter_jumlah = 0;
		CounterBaris = 17;
		isFound=false;
	   	fclose(fptr);
	   	ulangiUlangi:
		printf("\n   Cari Lagi? [Y/T] : "); fflush(stdin); scanf("%c", &ulangi);	
		if(ulangi=='t' || ulangi=='T' || ulangi=='y' || ulangi=='Y'){
		} else {
			goto ulangiUlangi;			
		}
   	}
}

FILE AktifkanBarang(){
	Barang stok;
	FILE *fptr;
	int status = false, counterRow = 14;
	char query[20], yakin, isFound;
	char *syarat[10] = {
		"Masukkan ID Barang Untuk Mengaktifkan Barang", 
		"Barang Yang Aktif Akan Muncul Pada Halaman Tampilkan Barang", 
		"Barang Yang nonaktif Tidak Akan Muncul Pada Halaman Tampilkan Barang",
		"Tersedia Alert Untuk Memastikan Pengaktifan",
		"Masukkan Y/y Untuk Melanjutkan Pengaktifan", 
		"Masukkan T/t Untuk Menggagalkan Pengaktifan",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);
	TampilkanBarang('c','t','t', &counterRow,'t','y');
	ulangiLagi:
	printf("\n   Masukkan ID Barang : "); scanf("%s", &query);
   	if((fptr = fopen("bin/stock.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&stok, sizeof(Barang), 1, fptr)==1){
			if(strcmp(query, ToString(stok.barang_id))==0){
				isFound = true;						
				printf("\n   %-34s :  %d\n","ID Barang", stok.barang_id);
				printf("   %-34s :  %s\n","Kategori [pc/laptop]", stok.kategori_barang);
				printf("   %-34s :  %s\n","Nama barang", stok.nama_barang);
				printf("   %-34s :  %s\n","Merk barang", stok.merk_barang);
				printf("   %-34s :  %s\n","Kondisi barang [Baru/Bekas/Rusak]", stok.kondisi_barang);
				printf("   %-34s :  %s\n","Barang Sewa [y/t]", (strcmp(stok.barang_sewa,"Y")==0 || strcmp(stok.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
				printf("   %-34s :  %d\n","Jumlah barang [1-500]", stok.jml_barang);
				printf("   %-34s :  Rp. %d\n","Harga barang [1-1000000000]", stok.hrg);
				printf("   %-28s  :  %d/%d/%d\n","Tanggal Masuk Barang [HH/BB/TTTT]", stok.tanggal.tanggal.hari, stok.tanggal.tanggal.bulan, stok.tanggal.tanggal.tahun);
				printf("   %-34s :  %s\n","Status barang", stok.status);
				printf("\n   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){
					fflush(stdin);
				 	status = true;
					stok.barang_id = stok.barang_id;
					strcpy(stok.kategori_barang, stok.kategori_barang);
					strcpy(stok.nama_barang, stok.nama_barang);
					strcpy(stok.merk_barang, stok.merk_barang);
					strcpy(stok.kondisi_barang, stok.kondisi_barang);
					strcpy(stok.barang_sewa, stok.barang_sewa);
					stok.jml_barang = stok.jml_barang;
					stok.hrg = stok.hrg;
					stok.tanggal = stok.tanggal;
					strcpy(stok.status, "aktif");
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
			printf("   Data Gagal Diaktifkan!\n\n");
		} else if(status==true){
			berhasil:
			if(fwrite != 0){
				printf("\n   Data Berhasil Diaktifkan!\n\n");
			}
			fseek(fptr, (long) -sizeof(Barang), SEEK_CUR);
			fwrite(&stok, sizeof(Barang), 1, fptr);
	   		fclose(fptr);
		}
	}
}

FILE NonaktifkanBarang(){
	Barang stok;
	FILE *fptr;
	int status = false, counterRow = 14;
	char query[20], yakin, isFound;
	char *syarat[10] = {
		"Masukkan ID Barang Untuk Menonaktifkan Barang", 
		"Barang Yang Aktif Akan Muncul Pada Halaman Tampilkan Barang", 
		"Barang Yang nonaktif Tidak Akan Muncul Pada Halaman Tampilkan Barang",
		"Tersedia Alert Untuk Memastikan Penonaktifan",
		"Masukkan Y/y Untuk Melanjutkan Penonaktifan", 
		"Masukkan T/t Untuk Menggagalkan Penonaktifan",
		NULL,
		NULL,
		NULL,
		NULL,
	};
	Persyaratan(syarat);
	TampilkanBarang('c','t','t', &counterRow,'y','t');
	ulangiLagi:
	printf("\n   Masukkan ID Barang : "); scanf("%s", &query);
   	if((fptr = fopen("bin/stock.dat","rb+")) == '\0'){
       	printf("   Error! File Tidak Dapat Dibuka...");
		MessageBeep(0);       	
	    exit(1);
	} else {
		while(fread(&stok, sizeof(Barang), 1, fptr)==1){
			if(strcmp(query, ToString(stok.barang_id))==0){
				isFound = true;
				printf("\n   %-34s :  %d\n","ID Barang", stok.barang_id);
				printf("   %-34s :  %s\n","Kategori [pc/laptop]", stok.kategori_barang);
				printf("   %-34s :  %s\n","Nama barang", stok.nama_barang);
				printf("   %-34s :  %s\n","Merk barang", stok.merk_barang);
				printf("   %-34s :  %s\n","Kondisi barang [Baru/Bekas/Rusak]", stok.kondisi_barang);
				printf("   %-34s :  %s\n","Barang Sewa [y/t]", (strcmp(stok.barang_sewa,"Y")==0 || strcmp(stok.barang_sewa,"y")==0) ? "IYA" : "TIDAK");
				printf("   %-34s :  %d\n","Jumlah barang [1-500]", stok.jml_barang);
				printf("   %-34s :  Rp. %d\n","Harga barang [1-1000000000]", stok.hrg);
				printf("   %-28s  :  %d/%d/%d\n","Tanggal Masuk Barang [HH/BB/TTTT]", stok.tanggal.tanggal.hari, stok.tanggal.tanggal.bulan, stok.tanggal.tanggal.tahun);
				printf("   %-34s :  %s\n","Status barang", stok.status);
				printf("\n   Apakah Anda Yakin [Y/T] ? "); fflush(stdin); scanf("%c",&yakin);
				if(yakin=='y' || yakin=='Y'){
					fflush(stdin);
				 	status = true;
					stok.barang_id = stok.barang_id;
					strcpy(stok.kategori_barang, stok.kategori_barang);
					strcpy(stok.nama_barang, stok.nama_barang);
					strcpy(stok.merk_barang, stok.merk_barang);
					strcpy(stok.kondisi_barang, stok.kondisi_barang);
					strcpy(stok.barang_sewa, stok.barang_sewa);
					stok.jml_barang = stok.jml_barang;
					stok.hrg = stok.hrg;
					stok.tanggal = stok.tanggal;
					strcpy(stok.status, "nonaktif");
					break;
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
			printf("   Data Gagal Dinonaktifkan!\n\n");
		} else if(status==true) {
			berhasil:
			fseek(fptr, (long) -sizeof(Barang), SEEK_CUR);
			fwrite(&stok, sizeof(Barang), 1, fptr);
	   		fclose(fptr);
			if(fwrite != 0){
				printf("\n   Data Berhasil Dinonaktifkan!\n\n");
			}
		}
	}
}

int ASCBarang(const void* p, const void* q) 
{ 
	return (((Barang*)p)->barang_id - ((Barang*)q)->barang_id); 
} 

int DSCBarang(const void* p, const void* q) 
{ 
	return (((Barang*)q)->barang_id - ((Barang*)p)->barang_id); 
} 

// Procedure untuk melakukan validasi dalam penambahan member
int IsValidBarang(int barang_id, char kategori_barang[10], char nama_barang[20], char merk_barang[50], char kondisi_barang[50], int jml_barang, int hrg, char barang_sewa[10], char status[10], char mode){
	FILE *fptr;
	Barang stok;
	char idStr[2];
	if(strlen(kategori_barang) > 0 && strlen(nama_barang) > 0 && strlen(merk_barang) > 0 && strlen(kondisi_barang) > 0 && strlen(barang_sewa) > 0 && strlen(ToString(jml_barang)) > 0 && strlen(ToString(hrg)) > 0){
		if(jml_barang >= 0 && hrg != 0 && strlen(ToString(barang_id)) < 7 && strlen(kategori_barang) <= 7 && strlen(nama_barang) <= 20 && strlen(merk_barang) <= 10 && strlen(kondisi_barang) < 7 && jml_barang <= 500 && strlen(ToString(hrg)) <= 10){
			if((strcmp(kategori_barang,"pc")==0) || (strcmp(kategori_barang,"laptop")==0)){
				if((strcmp(kondisi_barang,"baru")==0) || (strcmp(kondisi_barang,"rusak")==0) || (strcmp(kondisi_barang,"bekas")==0)){
					if((strcmp(barang_sewa,"y")==0) || (strcmp(barang_sewa,"t")==0)){
						if((strcmp(status,"aktif")==0) || (strcmp(status,"nonaktif")==0)){
							if(mode=='n'){
								if((fptr = fopen("bin/stock.dat","rb")) == NULL){
							       	printf("   Error! File Tidak Dapat Dibuka...");
							       	MessageBeep(0);
								    exit(1);				
								} else {
									while(fread(&stok,sizeof(Barang),1,fptr)==1){
										sprintf(idStr, "%d", stok.barang_id);
										if(strcmp(ToString(barang_id), idStr)==0){
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
