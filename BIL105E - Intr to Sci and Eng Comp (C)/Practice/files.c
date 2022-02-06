
 #include <stdio.h>

 main()
 {
 FILE *yaz;
 int x,y,z;
 
 
 char string[]="Bu dosya iki sayinin toplamini gosterir!";
 char add[]=" + ";
 char eq[]=" = ";
 
 yaz = fopen("deneme.txt","w");
 if( yaz== NULL)
{
 puts("Dosya acilamiyor...\a\n");
 exit(0);
 }

 printf("Toplanacak iki sayi girin : ");
 scanf("%d %d",&x,&y);
 z = x+y;

 fprintf(yaz,"%s\n%d%s%d%s%d", string, x, add, y, eq, z);
 fclose(yaz);

 puts("Bilgiler kaydedildi. Devam etmek icin ENTER tusuna basin.");
 getchar();
 
int i;
FILE *oku;
 oku= fopen("deneme.txt", "r");
 for(i=0;i<6;i++){
 		fscanf(oku, "%s", string);
 		printf("%s", string);
 		printf (" ");
 	}
 	printf("\n");
	fscanf(oku,"%d%s%d%s%d", &x, add, &y, eq, &z);
	printf("%d%s%d%s%d", x, add, y, eq, z);
}

