#include <stdio.h>
#include <stdlib.h>
#define DOSYA_YOLU "text.txt"

void satir_satir_oku() {
    FILE *dosya;
    char buf[100];
    if ((dosya = fopen(DOSYA_YOLU, "r")) == NULL) {
        printf("dosya acilamadi!\n");
        exit(1);
    	}
    int satir_sayisi = 0;

    // satir satir okuma islemi
    while ( fgets(buf, 100, dosya) != NULL ) {

        printf("%d. satir: \"%s\"\n", satir_sayisi, buf+satir_sayisi);
            satir_sayisi++;
        }
        fclose(dosya);
}





int main()
{
    satir_satir_oku();








       /* FILE * dosya;
        // dosyayi bastan yazmak icin ac (dosyanin icindekileri siler)
        if ((dosya = fopen(DOSYA_YOLU, "w")) == NULL) {
            printf("dosya acilamadi!\n");
            exit(1);
            }
            fputc('a', dosya);
            fputc('1', dosya);
            fputc('2', dosya);
            		// dosyayi kapat
            fclose(dosya);
            // dosyayi eklemek icin ac
            if ((dosya = fopen(DOSYA_YOLU, "a")) == NULL) {
                printf("dosya acilamadi!\n");
                exit(1);
                }
            long int gosterge = ftell(dosya); // bulundugu byte numarasini oku
            printf("%ld. indexteki karakter yazilacak\n", gosterge);
            // satir satir yaz
            fputs("satir 1\n", dosya);
            fputs("...\n", dosya);
            // formatli yaz
            fprintf(dosya, "%06d %.3f\n", 15, 1.3);
            fprintf(dosya, "test\n");
        fclose(dosya);*/








    return 0;
}
