#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int is_ok = EXIT_FAILURE;
    const char* fname ="text.txt";
    FILE* fp = fopen(fname, "r");
    if(!fp) {
        perror("File opening failed");
        return is_ok;
    }
    fputs("Hello, world!\n", fp);
    rewind(fp);
 
    int c;
    while ((c = fgetc(fp)) != EOF) {
       putchar(c);
    }
 
    if (ferror(fp)) {
        puts("I/O error when reading");
    } else if (feof(fp)) {
        puts("End of file reached successfully");
        is_ok = EXIT_SUCCESS;
    }
 
    fclose(fp);
    remove(fname);
    return is_ok;
}
