/*
osman tosun
02200201031
ikinci sinif
normal ogr.
*/
#include <stdbool.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define DEST_SIZE 40000
#define DEST_SIZE2 40000

int j;
char dest[DEST_SIZE];

char dest2[DEST_SIZE];
int main() {
    FILE * fp;
    int i = 0, k = 0, j;
    char data2[][1000] = {""};
    char data[][1000] = {""};
    char data3[][1000] = {""};
    char c[1000][1000] = {""};
    char veriYolu[100];
	printf("Not: ilk seferde acilmazsa birkac defa deneyin kendim kontrol ettim calisiyor\nama bazen ekrana bastirilmasi gerekenlerin yarisini bastirabiliyor\n.c uzantisi ile calistiramadim ama .cpp ile calisiyor");    
	printf("Dosyanin veri yolunu giriniz : ");    
	scanf("%s",veriYolu);
	fp=fopen("deneme.txt","r");
    while ((c[i][1000] = fgetc(fp)) != EOF) {
        i++;
    }
    for (j = 0; j < i; j++) {
        strcpy(c[j], c[j + 1]);
    }

    j = 0;
    k = 0;
    int l = 1;
    int len;
    int x = 0;
    int y = 0;
    char s[1] = "";
    char a[3] = "++";
    bool t;
    bool p;
    while (j < i) {
        if ( * c[j] == 101 && * c[j + 1] == 108 && * c[j + 2] == 115 && * c[j + 3] == 101 && * c[j + 4] == 32 && * c[j + 5] == 105 && * c[j + 6] == 102) {
            strcpy(data[k], "else if");
            j = j + 7;
            k++;
        }
        t = false;
        while ((( * c[j] >= 97 && * c[j] <= 122) || ( * c[j] >= 65 && * c[j] <= 90) || ( * c[j] >= 48 && * c[j] <= 57) || ( * c[j] == 37 && (( * c[j + 1] >= 97 && * c[j + 1] <= 122) || ( * c[j + 1] >= 65 && * c[j + 1] <= 90))))) {
            strcat(dest, c[j]);
            j++;
            t = true;
        }
        if (t == true) {
            strcpy(data[k], dest);
            strcpy(dest, s);
            k++;
        } else if ( * c[j] == 43 && * c[j + 1] == 43) {
            strcpy(data[k], "++");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 45 && * c[j + 1] == 45) {
            strcpy(data[k], "--");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 38 && * c[j + 1] == 38) {
            strcpy(data[k], "&&");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 61 && * c[j + 1] == 61) {
            strcpy(data[k], "==");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 33 && * c[j + 1] == 61) {
            strcpy(data[k], "!=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 124 && * c[j + 1] == 124) {
            strcpy(data[k], "||");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 60 && * c[j + 1] == 61) {
            strcpy(data[k], "<=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 62 && * c[j + 1] == 61) {

            strcpy(data[k], ">=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 43 && * c[j + 1] == 61) {
            strcpy(data[k], "+=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 45 && * c[j + 1] == 61) {
            strcpy(data[k], "-=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 42 && * c[j + 1] == 61) {
            strcpy(data[k], "*=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 47 && * c[j + 1] == 61) {
            strcpy(data[k], "/=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 37 && * c[j + 1] == 61) {
            strcpy(data[k], "%=");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 47 && * c[j + 1] == 47) {
            strcpy(data[k], "//");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 62 && * c[j + 1] == 62) {
            strcpy(data[k], ">>");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else if ( * c[j] == 60 && * c[j + 1] == 60) {
            strcpy(data[k], "<<");
            k++;
            j++;
            x = j;
            while (x < i) {
                strcpy(c[x], c[x + 1]);
                x++;
            }
            i--;
        } else {
            strcpy(data[k], c[j]);
            k++;
            j++;
        }
    }
    int j5 = 0;
    int l2 = k;
    l = k;
    while (j5 < l) {
        strcpy(data2[j5], data[j5]);
        j5++;
    }

    int count = 0;
    int h = 0;
    for (j = 0; j < k; j++) {
        if ( * data[j] == 125 && * data[j - 1] != 34) {
            h++;
        }
    }
    for (j = 0; j < k; j++) {
        if ( * data[j] == 123 && * data[j + 1] != 34) {
            count++;
        }
    }
    int z;
    int k2 = k;
    for (j = 0; j < k2; j++) {
        if (( * data[j] == 10)) {
            z = j + 1;
            while (!(( * data[z] >= 97 && * data[z] <= 122) ||
                    ( * data[z] >= 65 && * data[z] <= 90) ||
                    ( * data[z] >= 48 && * data[z] <= 57) ||
                    ( * data[z] == 123) || ( * data[z] == 125) || ( * data[z] == 35))) {
                * data[z] = 0;
                z++;
            }
        }
    }
    int q;
    j = 0;
    int e = 0;
    int k3 = k;
    int w;
    int j2 = 0;
    while (j < k3) {
        if (( * data[j] == 10)) { 
            w = 0;
            j2 = j;
            while (w < e) {
                for (q = k3; j2 < q; q--) {
                    strcpy(data[q], data[q - 1]);
                }
                * data[j2 + 1] = 9;
                k3++;
                w++;
                j2++;
            }
        }
        if ( * data[j] == 123) {
            e++; 
            count--; 
        }
        if ( * data[j] == 125) { 
            e--; 
            h--; 
        }
        j++;
    }
    printf("Kodun Indentation kurallarina uygun tam hali\n");
    j = 0;
    while (j < k3) {
        printf("%s", data[j]);
        j++;
    }
    for (j5 = 0; j5 < l; j5++) {
        if ( * data2[j5] == 32 || * data2[j5] == 10 || * data2[j5] == 9 || * data2[j5] == 13 || * data2[j5] == 11) {
            int x2 = j5;
            while (x2 < i) {
                strcpy(data2[x2], data2[x2 + 1]);
                x2++;
            }
            j5--;
            l2--;
        }
    }
    printf("\nKelimelestirilmis hali = { ");
    j5 = 0;
    while (j5 < l2) {
        printf("%s,", data2[j5]);
        j5++;
    }
    printf(" }\n");

    fclose(fp);

}

