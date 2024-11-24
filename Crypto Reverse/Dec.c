#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Anahtar (key) dizisi
unsigned char Key_0x433134572d39[50] = {
    0x43, 0x31, 0x34, 0x57, 0x2d, 0x39, 0xde, 0xf0,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
    0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
    0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01,
    0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe,
    0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x00
};

void xorDecrypt(const char *input, const char *output) {
    FILE *inputFile, *outputFile;
    char ch;
    int i = 0;

    // Açılacak dosyaları aç
    inputFile = fopen(input, "r");
    outputFile = fopen(output, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Dosya açma hatası!\n");
        exit(1);
    }

    // Her karakteri anahtar ile XOR işlemine tabi tut
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ Key_0x433134572d39[i], outputFile);
        i = (i + 1) % 50; // Anahtarın baştan tekrar kullanılması için döngü
    }

    // Dosyaları kapat
    fclose(inputFile);
    fclose(outputFile);

    printf("Şifre çözme tamamlandı. Sonuç dosyası: %s\n", output);
}

int main(int argc, char *argv[]) {
    // Argüman sayısını kontrol et
    if (argc != 4 || strcmp(argv[2], "-o") != 0) {
        printf("Kullanım: %s <input_file> -o <output_file>\n", argv[0]);
        return 1;
    }

    // Girdi ve çıktı dosya isimlerini al
    char *inputFile = argv[1];
    char *outputFile = argv[3];

    // Şifre çözme işlemini gerçekleştir
    xorDecrypt(inputFile, outputFile);

    return 0;
}
