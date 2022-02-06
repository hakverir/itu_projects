#include <iostream>
#include <stdlib.h>
//#include <cstdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include "diziislemleri.h"

using namespace std;

void Dizi::dosyaOku(){
	FILE *kopyaDosya;
	if((kopyaDosya = fopen("records.txt","r+"))==NULL){
		if((kopyaDosya=fopen("records.txt", "w+"))==NULL){
			printf("File could not be opened\n");
		}
	}
		
	else{
			while(!feof(kopyaDosya)){
				for(int i=0;i<100;i++)
				fscanf(kopyaDosya, "%s%s", k[i].ad, k[i].telno);
			}
		}
	fclose(kopyaDosya);
}

void Dizi::dosyaYaz(){
	FILE *sonucDosya;
	if((sonucDosya = fopen("records.txt","r+"))==NULL)
		printf("File could not be opened\n");
	else{
			for(int i=0;i<100;i++){
				fprintf(sonucDosya, "%s%s", k[i].ad, k[i].telno);
			}
		}
	fclose(sonucDosya);
}

void Dizi::ekle(Tel_Kayit *ykptr){
	strcpy(k[kayitsayisi].ad,ykptr->ad);
 	strcpy(k[kayitsayisi].telno,ykptr->telno);
	kayitsayisi++;
}

void Dizi::olustur(){
	kayitsayisi=0;
}

int Dizi::ara(char aranacak[]){
	int sayac=0;
	bool tumu=false;
	int bulunan,flag=0;
	if(strcmp(aranacak,"*")==0){
		tumu=true;
		for(int i=0;i<kayitsayisi;i++){
			cout<<i+1<<". "<<k[i].ad<<endl;
			bulunan=i;
			flag=1;
		}
	}
	else{
		for(int i=0;i<kayitsayisi;i++)
		{
 			if(strcmp(k[i].ad,aranacak)==0)
				{
				 cout<<i+1<<". "<<k[i].ad<<endl;
 				 bulunan=i;
				 flag=1;
				}
		}
	}
return flag;
}

void Dizi::guncelle(int kayitno, Tel_Kayit *ykptr){
	strcpy(k[kayitno-1].ad,ykptr->ad);
	strcpy(k[kayitno-1].telno,ykptr->telno);
}

void Dizi::sil(int kayitno){
	Tel_Kayit temp;
	strcpy(temp.ad, "");
	strcpy(temp.telno, "");
	int indisno;
	indisno=kayitno-1;
	k[indisno] = temp;
}

void Dizi::listele(){
	for(int i=0;i<kayitsayisi;i++)
		cout<<i+1<<". "<<k[i].ad<<" \t"<<k[i].telno<<endl;
}

