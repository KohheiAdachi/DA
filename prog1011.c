/* prog1011.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ZIP {
    int code;       /* 郵便番号 */
    char *name;     /* 住所（漢字） */
    char *roman;    /* 住所（ローマ字） */
};

#define NUM_OF_ZIP 124117
struct ZIP *zip_data;

void read_zip_file(void)
{
    int i;
    char s[256];
    FILE *fp = fopen("ken2.txt", "r");
    if( fp == NULL ){
        printf( "ken2.txt が開けません¥n");
        exit(-1);
    }
    zip_data = (struct ZIP *)malloc(sizeof(struct ZIP) * NUM_OF_ZIP);
    for(i=0 ; i<NUM_OF_ZIP ; i++ ) {
        fscanf(fp, "%d",&zip_data[i].code);
        fscanf(fp, "%s", s);
        zip_data[i].name  = (char *)malloc(strlen(s)+1);
        strcpy(zip_data[i].name, s);
        fscanf(fp, "%s", s);
        zip_data[i].roman  = (char *)malloc(strlen(s)+1);
        strcpy(zip_data[i].roman, s);
    }
    fclose( fp );
}

void find_zip_by_key(char *key)
{
    int i;
    for (i=0; i<NUM_OF_ZIP; ++i) {
        if (strstr(zip_data[i].name,key)){
            printf("%d %s\n",zip_data[i].code,zip_data[i].name);
        }
        if (strstr(zip_data[i].roman,key)){
            printf("%d %s\n",zip_data[i].code,zip_data[i].name);
        }
    }
}

int main(void)
{
    char key[256];
    read_zip_file();
    while (1) {
        printf("Input key word:");
        scanf("%s",key);
        find_zip_by_key(key);
        printf("--------------------\n");
    }
    
    return 0;
}



