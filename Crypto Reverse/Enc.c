#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char Key_0x433134572d39[50] = {
    0x43, 0x31, 0x34, 0x57, 0x2d, 0x39, 0xde, 0xf0,
    0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
    0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
    0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01,
    0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe,
    0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10, 0x00
};

void xorEncrypt(const char *input, const char *output) {
    FILE *inputFile, *outputFile;
    char ch;
    int i = 0;

    inputFile = fopen(input, "r");
    outputFile = fopen(output, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("File opening error!\n");
        exit(1);
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ Key_0x433134572d39[i], outputFile);
        i = (i + 1) % 50;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption completed. Result file: %s\n", output);
}

int main(int argc, char *argv[]) {
    if (argc != 5 || strcmp(argv[1], "-e") != 0 || strcmp(argv[3], "-o") != 0) {
        printf("Usage: ./Encrypt.exe -e <input_file> -o <output_file>\n");
        return 1;
    }

    char *inputFile = argv[2];
    char *outputFile = argv[4];

    xorEncrypt(inputFile, outputFile);

    return 0;
}
