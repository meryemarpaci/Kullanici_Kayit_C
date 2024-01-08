#ifndef _KULLANICI_H
#define _KULLANICI_H

typedef struct Kullanici{
	char tel[10];
	char ad[20];
	char soyad[20];
	char adres[20];
	
} kullanici;

void giris();
int menu();
void yeniKayit();
void kayitAra();
void kayitSil();
void listele();
void tumKayitlariSil();
void veriTabaniKayit(kullanici k1);
void girisAl(char *);
#endif _KULLANICI_H
