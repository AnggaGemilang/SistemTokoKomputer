#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <time.h>
#include "boolean.h"
#include "tools.h"

void Breadcrumb(char *kalimat[5]){
	int i, counter = 0;
	char simbol = '>';
	for(i=0; i<6; i++){
		if(kalimat[i]!=NULL){
			counter++;
		}
	}
	for(i=0; i<counter; i++){
		printf("%s %c ", kalimat[i], ((i==counter-1)) ? '\0' : simbol);
	}
}

void Persyaratan(char *persyaratan[10]){
	int i, counter = 0;
	printf("*) Perhatikan Persyaratan Dibawah Ini\n\n");
	for(i=0; i<10; i++){
		if(persyaratan[i]!=NULL){
			counter++;
		}
	}
	for(i=0; i<counter; i++){
		printf("   %d. %s\n",(i+1), persyaratan[i]);
	}
}

//Fungsi untuk konversi angka ke string (char*)
char *ToString(int angka){
	char* converted = (char*) malloc (sizeof(char)*(100+1));
	sprintf(converted, "%d", angka);
	return converted;
}

// Procedure untuk mengatur posisi
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Procedure untuk menampilkan teks berdasarkan koordinat gotoxy()
void printg(int xCoordinat, int yCoordinat,char *teks){
 	gotoxy(yCoordinat,xCoordinat);
 	printf("%s",teks);
}

// Fungsi untuk melakukan random angka
int RandomNumber(int min_num, int max_num){
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num<max_num){
        low_num=min_num;
        hi_num=max_num+1;
    } else {
        low_num=max_num+1;
        hi_num=min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

// Fungsi untuk memotong string dan menampilkannya sesuai dengan index awal dan akhir
char* substr(const char *src, int m, int n){
	int i;
    int len = n-m;
    char *dest=(char*)malloc(sizeof(char)*(len + 1));
    for (i = m; i < n && (*(src + i) != '\0'); i++){
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}

// Mendapatkan waktu sekarang
Timestamp GetNow(){
	Timestamp timestamp;
    char buff[100];
    time_t now = time(0);
    struct tm now_t = *localtime(&now);
    strftime(buff, 100, " %d-%m-%Y %H:%M:%S", &now_t);    
    timestamp.jam = now_t.tm_hour;
    timestamp.menit = now_t.tm_min;
    timestamp.detik = now_t.tm_sec;
    timestamp.tanggal.hari = now_t.tm_mday;
    timestamp.tanggal.bulan = now_t.tm_mon + 1;
    timestamp.tanggal.tahun = now_t.tm_year + 1900;
	return timestamp;
}

// Fungsi untuk membandingkan 2 buah tanggal apakah lebih kecil
int DateInRange(Timestamp a, Timestamp b){
	if(a.tanggal.tahun < b.tanggal.tahun) return true;
	if(a.tanggal.tahun == b.tanggal.tahun && a.tanggal.bulan < b.tanggal.bulan) return true;
	if(a.tanggal.tahun == b.tanggal.tahun && a.tanggal.bulan == b.tanggal.bulan && a.tanggal.hari < b.tanggal.hari) return true;
 	if(a.tanggal.tahun == b.tanggal.tahun && a.tanggal.bulan == b.tanggal.bulan && a.tanggal.hari == b.tanggal.hari && a.jam <= b.jam) return true;
  	if(a.tanggal.tahun == b.tanggal.tahun && a.tanggal.bulan == b.tanggal.bulan && a.tanggal.hari == b.tanggal.hari && a.jam == b.jam && a.jam == b.jam && a.menit < b.menit) return true;
  	if(a.tanggal.tahun == b.tanggal.tahun && a.tanggal.bulan == b.tanggal.bulan && a.tanggal.hari == b.tanggal.hari && a.jam == b.jam && a.jam == b.jam && a.menit == b.menit && a.detik <= b.detik) return true;
	return false;
}

// Procedure untuk teks berjalan
void MarqueeText(char *kalimat, int speed){
	int x; double y;
   	for(x=0; kalimat[x]!='\0'; x++){
	    printf("%c",kalimat[x]);
	    for(y=0; y<=speed; y++){
		}
   }
}

// Fungsi untuk menghitung hari
int CountDay(Timestamp FirstDate, Timestamp SecondDate){
    int day1, mon1, year1,
        day2, mon2, year2;
    int day_diff, mon_diff, year_diff;
	day1 = FirstDate.tanggal.hari;
	mon1 = FirstDate.tanggal.bulan;
	year1 = FirstDate.tanggal.tahun;
	day2 = SecondDate.tanggal.hari;
	mon2 = SecondDate.tanggal.bulan;
	year2 = SecondDate.tanggal.tahun;
    if(day2 < day1){
        if (mon2 == 3){
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)){
                day2 += 29;
            } else{
                day2 += 28;
            }                        
        } else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12){
           day2 += 30; 
        } else{
           day2 += 31;
        }
        mon2 = mon2 - 1;
    }
    if (mon2 < mon1){
        mon2 += 12;
        year2 -= 1;
    }       
    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;
    return (year_diff*365)+(mon_diff*30)+day_diff;
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void panduan(char *namaFile){
    char buff[255];
    FILE *fptr;
    if ((fptr = fopen(namaFile,"r")) == NULL){
        printf("Error: File tidak ada!");
        exit(1);
    }
    while(fgets(buff, sizeof(buff), fptr)){
        printf("%s", buff);
    }
    fclose(fptr);
}
