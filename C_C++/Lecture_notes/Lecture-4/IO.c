#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char cn;
    fp = fopen("example.txt", "w");
    printf("Enter data...\n");
    while ((cn = getchar()) != EOF)
    {
        putc(cn, fp);
    }
    fclose(fp);
    fp = fopen("example.txt", "r");

    while ((cn = getc(fp)) != EOF)
    {
        printf("%c", cn);
    }
    printf("\n");
    fclose(fp);

    fp = fopen("example.txt", "a"); // append to the end of the file
    int *age;
    int x = 10;
    age = &x;
    scanf("%s %d", "David", age);
    fprintf(fp, "%s %d", "David", *age);
    fclose(fp);

    fp = fopen("example.txt", "ab"); // append bytes
    const char *myText = "How are you";
    fwrite(myText, sizeof(char), strlen(myText), fp);
    fclose(fp);

    fp = fopen("example.txt", "rb");
    char buffer[BUFSIZ]; // BUFSIZ = 1024
    while (!feof(fp))
    {
        int r = fread(buffer, sizeof(char), BUFSIZ, fp); // r = how many bytes read
        fwrite(buffer, sizeof(char), r, stdout);
    }
    fclose(fp);

    return 0;
}