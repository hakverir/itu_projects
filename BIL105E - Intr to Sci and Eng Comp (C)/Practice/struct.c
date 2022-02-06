#include <stdio.h>

struct student{
		int numara;
		char ad[15];
		char soyad[15];
		int odev;
		int vize;
		int final;
	};

int main(void)
{
	struct student donemsonu={1, "A", "B", 96, 90, 100,
					2, "C", "D", 74, 100, 98,
					3, "E", "F", 83, 99, 82,
					4, "G H", "I", 80, 71, 89,
					5, "J", "K", 57, 13, 8};

	float ort=0.0;
	FILE *ogr;
	FILE *ogr2;

	if((ogr= fopen("student.txt", "w"))==NULL) {
		printf ("NO\n");
	}
	else{
		fprintf(ogr, "%2s\t%15s\t%15s\t%4s\t%4s\t%5s\n", "NO", "AD", "SOYAD", "ODEV", "VIZE", "FINAL");
		donemsonu.numara=1;
		while(donemsonu.numara<=5){
			fprintf(ogr, "%d\t%s\t%s\t%d\t%d\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, donemsonu.odev, donemsonu.vize, donemsonu.final);
			donemsonu.numara++;
		}
	}

	printf("kontrol:\n\n%2s\t%15s\t%15s\t%4s\t%4s\t%5s\n", "NO", "AD", "SOYAD", "ODEV", "VIZE", "FINAL");
	donemsonu.numara=1;
	while(donemsonu.numara<=5){
		fscanf(ogr, "%d\t%s\t%s\t%d\t%d\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, donemsonu.odev, donemsonu.vize, donemsonu.final);
		printf("%d\t%s\t%s\t%d\t%d\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, donemsonu.odev, donemsonu.vize, donemsonu.final);
		donemsonu.numara++;
		}

	if((ogr2= fopen("success.txt", "w"))==NULL) {
		printf ("zaa 2 xdd\n");
	}
	else{
		float x, y, z;
		int a,b,c;
		donemsonu.numara=1;
		fprintf(ogr2, "%2s\t%15s\t%15s\t%4s\n", "NO", "AD", "SOYAD", "ORT.");
		while(donemsonu.numara<=1){
			x=(donemsonu.odev*20)/100;
			y=(donemsonu.vize*30)/100;
			z=(donemsonu.final*50)/100;
			ort=(x+y)+z;
			if(ort>=59.5) {
				fprintf(ogr, "%d\t%s\t%s\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, ort);
			}
			donemsonu.numara++;
		}
	}
	donemsonu.numara=1;
	printf("kontrol:\n%2s\t%15s\t%15s\t%4s\n", "NO", "AD", "SOYAD", "ORT.");
	while(donemsonu.numara<=5){
		fscanf(ogr2, "%d\t%s\t%s\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, ort);
		printf("%d\t%s\t%s\t%d\n", donemsonu.numara, donemsonu.ad, donemsonu.soyad, ort);
		donemsonu.numara++;
		}
}
