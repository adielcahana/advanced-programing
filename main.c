#include <stdio.h>

char readChar(FILE *f){
    char c;
    fread(&c,8,1,f);
    return c;
}

void writeChar(char c, FILE *f){
    fwrite(&c,8,1,f);
}

int main(int argc, char** argv) {
    FILE* src = fopen(argv[1], "rb");
    FILE* target = fopen(argv[2], "wb");
    char c = readChar(src);
    while (c != EOF){
        writeChar(c, target);
        c = readChar(src);
    }
    fclose(src);
    fclose(target);
    return 0;
}



