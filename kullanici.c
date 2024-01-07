#include "kullanici.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kullanici k1;

void giris(){
	int secim = menu();	
	while(secim!=0){
		switch(secim){
			case 1: 
				yeniKayit(); 
				break;
			case 2: 
				kayitAra(); 
				break;
			case 3: 
				kayitSil(); 
				break;
			case 4: 
				listele(); 
				break;
			case 5: 
				tumKayitlariSil(); 
				break;
		}
		secim = menu();
	}
}
int menu(){	
	
	printf("\n KULLANICI KAYIT UYGULAMASI\n\n");
	printf("[1] Yeni Kayýt \n");
	printf("[2] Kayýt Ara \n");
	printf("[3] Kayýt Sil \n");
	printf("[4] Listele \n");
	printf("[5] Tüm Kayýtlari Sil \n");
	printf("[0] Çýkýþ \n");
	int secim;

	do{
		printf("Seciminiz [0-5] : ");
		secim = getche() - '0';
		printf("\n");
		
	}while ( secim<0 || secim>5);
	
	return secim;
}
void yeniKayit(){
	system("cls");
	printf("Yeni kayýt için...\n");
	printf("Telefon  : ") ; girisAl(k1.tel);
	printf("Ad       : ") ; girisAl(k1.ad);
	printf("Soyad    : ") ; girisAl(k1.soyad);
	printf("Adres    : ") ; girisAl(k1.adres);
	
	veriTabaniKayit(k1);
	
	
}
void kayitAra(){
	system("cls");
	int sonuc=0;
	char arama[20];
	printf("Ad : ");
	girisAl(arama);
	FILE *fp;
	if( (fp = fopen("kullanicilar.txt","rb") )== NULL){
		printf("Veritabaný hatasý ! \n");
		exit(1);
	}
	
	while(fread(&k1, sizeof(kullanici),1,fp) != NULL) {
		if(strcmp(arama,k1.ad) ==0){ // eþitlerse 0 döndürür
			if(sonuc==0)
				printf("%-20s%-20s%-20s%-20s\n","NUMARA","AD","SOYAD","ADRES");
			printf("%-20s%-20s%-20s%-20s\n",k1.tel,k1.ad,k1.soyad,k1.adres);
		 	
		 	sonuc++;
		
		
		}
	}
	
	fclose(fp);
	if(sonuc==0)
	printf("\n%s isimli kayit bulunamadi \n",arama);
	else
	printf("\n%s isimli kisiden %d adet bulundu \n",arama,sonuc);
	
}
void kayitSil(){
	
	system("cls");
	int sonuc=0;
	char arama[20];
	printf("Telefon Numarasi : ");
	girisAl(arama);
	FILE *fp, *yFp;
	if( (fp = fopen("kullanicilar.txt","rb") )== NULL){
		printf("Veritabaný hatasý ! \n");
		exit(1);
	}
	
	if( (yFp = fopen("yedek.txt","wb") )== NULL){ //wb yeni dosya olusturur
		printf("Veritabaný hatasý ! \n");
		exit(1);
	}
	
	
	
	while(fread(&k1, sizeof(kullanici),1,fp) != NULL) {
		if(strcmp(arama,k1.tel) ==0){ // eþitlerse 0 döndürür
			sonuc++;		
		
		}else{
			fwrite(&k1, sizeof(kullanici),1,yFp);
			
		}
	}
	fclose(fp);
	fclose(yFp);
	
	remove("kullanicilar.txt");
	rename("yedek.txt","kullanicilar.txt");
	

	if(sonuc==0)
	printf("\n%s numarali kayit bulunamadi \n",arama);
	else
	printf("\n%s numarali kisi silindi \n",arama);
	
	
	
}
void listele(){
	
	system("cls");
	int sonuc=0;
	FILE *fp;
	if( (fp = fopen("kullanicilar.txt","rb") )== NULL){
		printf("Veritabaný hatasý ! \n");
		exit(1);
	}
	
	while(fread(&k1, sizeof(kullanici),1,fp) != NULL) {
		
			if(sonuc==0)
			printf("%-20s%-20s%-20s%-20s\n","NUMARA","AD","SOYAD","ADRES");
			printf("%-20s%-20s%-20s%-20s\n",k1.tel,k1.ad,k1.soyad,k1.adres);
		 	
		 	sonuc++;
		
	}
	
	fclose(fp);
	if(sonuc==0)
	printf("\nListe boþ \n");
	else
	printf("\n%d adet kullanici kaydi bulundu \n",sonuc);
	
	
}
void tumKayitlariSil(){
	system("cls");
	char tercih;
	printf("Tum kayitlari silmek istediginize emin misiniz [E/H] :");
	scanf("%c",&tercih);
	
	if(tercih=='E' || tercih=='e'){
		int sonuc = remove("kullanicilar.txt"); // eðer silinirse 0 döndürür
		if(sonuc==0)
			printf("kayitlar basariyla silindi\n");
		else
			printf("silme islemi basarisiz\n");
		
	}
	else{
		printf("Silme islemi iptal edildi\n");
	}
	
	
}
void veriTabaniKayit(kullanici k1){
	FILE *fp;
	if( (fp = fopen("kullanicilar.txt","ab"))== NULL){
		printf("Veritabaný hatasý ! \n");
		exit(1);
	}
	fwrite(&k1, sizeof(kullanici),1,fp); //1 sadece 1 tane kullanýcý yapýsýný dosyaya yazacaðýný söyler
	fclose(fp);
	printf("Kayýt tamamlandý \n");
}
void girisAl(char *fp){
	fgets(fp,20,stdin) ;
	int n=strlen(fp);
	fp[n-1]='\0'; //n-1 çünkü fgets sonuna bir \n ekler onu nulla degistirdik
	
}
