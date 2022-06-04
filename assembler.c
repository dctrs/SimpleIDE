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

char dest[DEST_SIZE];
char dest3[DEST_SIZE];
char dest2[DEST_SIZE];
bool isOp(char * ch) {
    if (strcmp(ch, ">") == 0 || strcmp(ch, "<") == 0 || strcmp(ch, "<=") == 0 ||
        strcmp(ch, ">=") == 0 || strcmp(ch, "==") == 0) {
        return (true);
    }
    return (false);
}
bool isArOp(char * ch) {
    if (strcmp(ch, "+") == 0 || strcmp(ch, "-") == 0 ||
        strcmp(ch, "*") == 0 || strcmp(ch, "/") == 0) {
        return (true);
    }
    return (false);
}
bool isNumber(char * ch) {
    int i;
    bool b;
    for (i = 0; i < strlen(ch); i++) {
        if (ch[i] == '0' || ch[i] == '1' || ch[i] == '2' ||
            ch[i] == '3' || ch[i] == '4' || ch[i] == '5' ||
            ch[i] == '6' || ch[i] == '7' || ch[i] == '8' ||
            ch[i] == '9') {
            b = true;
        } else {
            b = false;
            break;
        }
    }
    return b;
}
bool isId(char * ch) {

    if (strcmp(ch, "a") == 0 || strcmp(ch, "b") == 0 ||
        strcmp(ch, "c") == 0 || strcmp(ch, "d") == 0 || strcmp(ch, "e") == 0 || strcmp(ch, "f") == 0 ||
        strcmp(ch, "0") == 0 || strcmp(ch, "1") == 0 || strcmp(ch, "2") == 0 || strcmp(ch, "3") == 0 ||
        strcmp(ch, "4") == 0 || strcmp(ch, "5") == 0 || strcmp(ch, "6") == 0 || strcmp(ch, "7") == 0 ||
        strcmp(ch, "8") == 0 || strcmp(ch, "9") == 0

    ) {
        return (true);
    }
    return false;
}
bool isSentence(int j, char c[j][1000]) {
    if (((isId(c[j]) || (isNumber(c[j]))) && (strcmp(c[j + 1], "=") == 0) &&
            (isId(c[j + 2]) || (isNumber(c[j + 2]))) && isArOp(c[j + 3]) && (isId(c[j + 4]) || (isNumber(c[j + 4])))) || ((isId(c[j]) || (isNumber(c[j]))) && (strcmp(c[j + 1], "=") == 0) && (isId(c[j + 2]) || (isNumber(c[j + 2]))) && (strcmp(c[j + 3], "}") == 0))) {
        return true;

    }
    return false;
}
bool isSart(int j, char c[j][1000]) {
    if (((isId(c[j]) || (isNumber(c[j]))) && isOp(c[j + 1]) && (isId(c[j + 2]) || (isNumber(c[j + 2]))))) {
        return true;
    }
    return false;
}
bool isDegisken(char * ch) {
    if (strcmp(ch, "AX") == 0 || strcmp(ch, "BX") == 0 ||
        strcmp(ch, "CX") == 0 || strcmp(ch, "DX") == 0) {
        return (true);
    }
    return (false);

}
int TOP(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j]);
        int sayi2 = atoi(dizi[j + 2]);
        return sayi1 + sayi2;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return degisken2 + degisken;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j + 2]);
        return sayi1 + degisken;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return degisken + memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        int memory = atoi(dataMem[mem]);
        return degisken + memory;
    }
    

}
int CIK(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j]);
        int sayi2 = atoi(dizi[j + 2]);
        return sayi1 - sayi2;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return degisken - degisken2;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j + 2]);
        return degisken - sayi1;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return degisken - memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        int memory = atoi(dataMem[mem]);
        return memory - degisken;
    }

}
int CRP(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j]);
        int sayi2 = atoi(dizi[j + 2]);
        return sayi1 * sayi2;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return degisken * degisken2;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j + 2]);
        return degisken * sayi1;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return degisken * memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        int memory = atoi(dataMem[mem]);
        return memory * degisken;
    }

}
float BOL(int j, char dizi[j][1000], float degisken, float degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        float sayi1 = atoi(dizi[j]);
        float sayi2 = atoi(dizi[j + 2]);
        float sonuc = (float)(sayi1 / sayi2);
        return sonuc;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return (float) degisken / degisken2;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        float sayi1 = atoi(dizi[j + 2]);
        return (float) degisken / sayi1;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        float memory = atoi(dataMem[mem]);

        return (float) degisken / memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        float memory = atoi(dataMem[mem]);
        return (float) memory / degisken;
    }

}
int VE(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j]);
        int sayi2 = atoi(dizi[j + 2]);
        return sayi1 & sayi2;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return degisken & degisken2;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j + 2]);
        return degisken & sayi1;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return degisken & memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        int memory = atoi(dataMem[mem]);
        return memory & degisken;
    }

}
int VEYA(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j]);
        int sayi2 = atoi(dizi[j + 2]);
        return sayi1 | sayi2;
    } else if (isDegisken(dizi[j]) && isDegisken(dizi[j + 2])) {
        return degisken | degisken2;
    } else if (isDegisken(dizi[j]) && isNumber(dizi[j + 2])) {
        int sayi1 = atoi(dizi[j + 2]);
        return degisken | sayi1;
    } else if (isDegisken(dizi[j]) && (strcmp(dizi[j + 2], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return degisken | memory;
    } else if ((strcmp(dizi[j], "[") == 0) && isDegisken(dizi[j + 4])) {
        int memory = atoi(dataMem[mem]);
        return memory | degisken;
    }

}
int DEG(int j, char dizi[j][1000], int degisken, int degisken2, int mem, char dataMem[mem][2048]) {
    if (isNumber(dizi[j])) {
        int sayi1 = atoi(dizi[j]);
        return ~sayi1;
    } else if (isDegisken(dizi[j])) {
        return ~degisken;
    } else if ((strcmp(dizi[j], "[") == 0)) {
        int memory = atoi(dataMem[mem]);

        return ~memory;
    }

}

int main() {
    FILE * fp;
    int i = 0, k = 0, j;
    int jct, ct, je;
    char data2[][1000] = {""};
    char data[1000][1000] = {"" };
    char data3[][1000] = {""};
    char c[1000][1000] = {""};
    char dataMem[][2048] = {""};
    * dataMem[0] = 0;
    char veriYolu[100];
    char arr[100] = {0};
    char arr2[100] = {0};
    char arr3[100] = {0};
    char arr4[100] ={0};
    bool t1 = false, t2 = false, t3 = false;
    int sonuc;
 	printf("Dosyanin veri yolunu giriniz : ");    
	scanf("%s",veriYolu);
	fp=fopen(veriYolu,"r");
    while ((c[i][1000] = fgetc(fp)) != EOF) {
        i++;
    }
    for (j = 0; j < i; j++) {
        strcpy(c[j], c[j + 1]);

    }
    int i2 = i;
    * c[i] = 0;

    for (j = 0; j < i2; j++) {
        strcpy(data[j], data[j + 1]);

    }* data[i2] = 0;

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
        } else if ( * c[j] == 101 && * c[j + 1] == 108 && * c[j + 2] == 115 && * c[j + 3] == 101) {
            strcpy(data[k], "else");
            j = j + 4;
            k++;
        } else if ( * c[j] == 105 && * c[j + 1] == 102) {
            strcpy(data[k], "if");
            j = j + 2;
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
    int k2 = k;
    for (j = 0; j < k2; j++) {
        if ( * data[j] == 32 || * data[j] == 10 || * data[j] == 9 || * data[j] == 13 || * data[j] == 11) {
            int x = j;
            while (x < i) {
                strcpy(data[x], data[x + 1]);
                x++;
            }

            j--;
            k--;
        }
    }
    j = 0;
    int memIndex;
    int AX, BX, CX, DX;
    AX = 0, BX = 0,CX=0,DX=0;
    while (j < k) {
        while (strcmp(data[j], "HRK") == 0) {
            //1. KAYITCI 2. SAYÝ
            if ((strcmp(data[j + 1], "[") == 0) && isNumber(data[j + 2]) && isNumber(data[j + 5])) {
                int memIndex = atoi(data[j + 2]);
                int number = atoi(data[j + 5]);
                strcpy(dataMem[memIndex], data[j + 5]);

                j += 6;
            } else if ((strcmp(data[j + 1], "AX") == 0) && isNumber(data[j + 3])) {
                AX = atoi(data[j + 3]);
                j += 4;
            } else if ((strcmp(data[j + 1], "BX") == 0) && isNumber(data[j + 3])) {
                BX = atoi(data[j + 3]);
                j += 4;
            } else if ((strcmp(data[j + 1], "CX") == 0) && isNumber(data[j + 3])) {
                CX = atoi(data[j + 3]);
                j += 4;
            } else if ((strcmp(data[j + 1], "DX") == 0) && isNumber(data[j + 3])) {
                DX = atoi(data[j + 3]);
                j += 4;
            }
            //1. ADRES 2. SAYÝ
            else if ((strcmp(data[j + 1], "[") == 0) && isNumber(data[j + 2]) && (strcmp(data[j + 5], "AX") == 0)) {
                int memIndex = atoi(data[j + 2]);
                * dataMem[memIndex] = AX;
                j += 6;
            } else if ((strcmp(data[j + 1], "[") == 0) && isNumber(data[j + 2]) && (strcmp(data[j + 5], "BX") == 0)) {
                int memIndex = atoi(data[j + 2]);
                * dataMem[memIndex] = BX;
                j += 6;
            } else if ((strcmp(data[j + 1], "[") == 0) && isNumber(data[j + 2]) && (strcmp(data[j + 5], "CX") == 0)) {
                int memIndex = atoi(data[j + 2]);
                * dataMem[memIndex] = CX;
                j += 6;
            } else if ((strcmp(data[j + 1], "[") == 0) && isNumber(data[j + 2]) && (strcmp(data[j + 5], "DX") == 0)) {
                int memIndex = atoi(data[j + 2]);
                * dataMem[memIndex] = DX;
                j += 6;
            }
            //1.KAYÝTCÝ 2.SAYI				
            else if ((strcmp(data[j + 1], "AX") == 0) && (strcmp(data[j + 3], "[") == 0) && isNumber(data[j + 4])) {
                int memIndex = atoi(data[j + 4]);
                * dataMem[memIndex] = AX;
                j += 5;
            } else if ((strcmp(data[j + 1], "BX") == 0) && (strcmp(data[j + 3], "[") == 0) && isNumber(data[j + 4])) {
                int memIndex = atoi(data[j + 4]);
                * dataMem[memIndex] = BX;
                j += 5;
            } else if ((strcmp(data[j + 1], "CX") == 0) && (strcmp(data[j + 3], "[") == 0) && isNumber(data[j + 4])) {
                int memIndex = atoi(data[j + 4]);
                * dataMem[memIndex] = CX;
                j += 5;
            } else if ((strcmp(data[j + 1], "DX") == 0) && (strcmp(data[j + 3], "[") == 0) && isNumber(data[j + 4])) {
                int memIndex = atoi(data[j + 4]);
                * dataMem[memIndex] = DX;
                j += 5;
            }
            //1.DE KAYITCI 2.DE
            else if ((strcmp(data[j + 1], "AX") == 0) && (strcmp(data[j + 3], "BX"))) {
                AX = BX;
                j += 4;
            } else if ((strcmp(data[j + 1], "AX") == 0) && (strcmp(data[j + 3], "CX"))) {
                AX = CX;
                j += 4;
            } else if ((strcmp(data[j + 1], "AX") == 0) && (strcmp(data[j + 3], "DX"))) {
                AX = DX;
                j += 4;
            }
            //B
            else if ((strcmp(data[j + 1], "BX") == 0) && (strcmp(data[j + 3], "AX"))) {
                BX = AX;
                j += 4;
            } else if ((strcmp(data[j + 1], "BX") == 0) && (strcmp(data[j + 3], "CX"))) {
                BX = CX;
                j += 4;
            } else if ((strcmp(data[j + 1], "BX") == 0) && (strcmp(data[j + 3], "DX"))) {
                BX = DX;
                j += 4;
            }
            //C
            else if ((strcmp(data[j + 1], "CX") == 0) && (strcmp(data[j + 3], "AX"))) {
                CX = AX;
                j += 4;
            } else if ((strcmp(data[j + 1], "CX") == 0) && (strcmp(data[j + 3], "BX"))) {
                CX = BX;
                j += 4;
            } else if ((strcmp(data[j + 1], "CX") == 0) && (strcmp(data[j + 3], "DX"))) {
                CX = DX;
                j += 4;
            }
            //D
            else if ((strcmp(data[j + 1], "DX") == 0) && (strcmp(data[j + 3], "AX"))) {
                DX = AX;
                j += 4;
            } else if ((strcmp(data[j + 1], "DX") == 0) && (strcmp(data[j + 3], "BX"))) {
                DX = BX;
                j += 4;
            } else if ((strcmp(data[j + 1], "DX") == 0) && (strcmp(data[j + 3], "CX"))) {
                DX = CX;
                j += 4;
            }
        }

        //TOP
        if (strcmp(data[j], "TOP") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                sonuc = TOP(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%d", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                sonuc = TOP(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX+%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                sonuc = TOP(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX+%s=%d\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                sonuc = TOP(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX+%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                sonuc = TOP(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX+%s=%d\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = TOP(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX+BX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = TOP(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX+CX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = TOP(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX+DX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = TOP(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX+AX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = TOP(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX+CX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = TOP(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX+DX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = TOP(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX+AX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = TOP(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX+BX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = TOP(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX+DX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = TOP(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX+AX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = TOP(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX+BX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = TOP(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX+CX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = TOP(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX+[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = TOP(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX+[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = TOP(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX+[%s]=%d\n", data[j + 4], sonuc);
                
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = TOP(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX+[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = TOP(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]+AX=%d\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = TOP(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]+BX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = TOP(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]+CX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = TOP(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]+DX=%d\n", data[j + 2], sonuc);
                j += 6;
            }

        }
        //CIK
        if (strcmp(data[j], "CIK") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                sonuc = CIK(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%d", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                sonuc = CIK(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX-%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                sonuc = CIK(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX-%s=%d\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                sonuc = CIK(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX-%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                sonuc = CIK(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX-%s=%d\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CIK(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX-BX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CIK(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX-CX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CIK(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX-DX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CIK(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX-AX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CIK(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX-CX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CIK(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX-DX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CIK(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX-AX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CIK(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX-BX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CIK(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX-DX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CIK(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX-AX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CIK(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX-BX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CIK(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX-CX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CIK(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX-[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CIK(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX-[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CIK(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX-[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CIK(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX-[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CIK(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]-AX=%d\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CIK(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]-BX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CIK(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]-CX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CIK(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]-DX=%d\n", data[j + 2], sonuc);
                j += 6;
            }

        }
        //CRP
        if (strcmp(data[j], "CRP") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                sonuc = CRP(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%d", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                sonuc = CRP(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX*%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                sonuc = CRP(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX*%s=%d\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                sonuc = CRP(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX*%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                sonuc = CRP(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX*%s=%d\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CRP(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX*BX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CRP(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX*CX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CRP(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX*DX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CRP(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX*AX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CRP(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX*CX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CRP(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX*DX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CRP(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX*AX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CRP(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX*BX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = CRP(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX*DX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = CRP(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX*AX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = CRP(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX*BX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = CRP(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX*CX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CRP(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX*[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CRP(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX*[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CRP(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX*[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = CRP(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX*[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CRP(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]*AX=%d\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CRP(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]*BX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CRP(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]*CX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = CRP(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]*DX=%d\n", data[j + 2], sonuc);
                j += 6;
            }

        }
        //BOL	
        if (strcmp(data[j], "BOL") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                float sonuc = BOL(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%.2f", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                float sonuc = BOL(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX/%s=%.2f\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                float sonuc = BOL(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX/%s=%.2f\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                float sonuc = BOL(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX/%s=%.2f\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                float sonuc = BOL(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX/%s=%.2f\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                float sonuc = BOL(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX/BX=%.2f\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                float sonuc = BOL(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX/CX=%.2f\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                float sonuc = BOL(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX/DX=%.2f\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                float sonuc = BOL(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX/AX=%.2f\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                float sonuc = BOL(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX/CX=%.2f\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                float sonuc = BOL(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX/DX=%.2f\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                float sonuc = BOL(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX/AX=%.2f\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                float sonuc = BOL(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX/BX=%.2f\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                float sonuc = BOL(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX/DX=%.2f\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                float sonuc = BOL(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX/AX=%.2f\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                float sonuc = BOL(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX/BX=%.2f\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                float sonuc = BOL(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX/CX=%.2f\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                float sonuc = BOL(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX/[%s]=%.2f\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                float sonuc = BOL(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX/[%s]=%.2f\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                float sonuc = BOL(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX/[%s]=%.2f\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                float sonuc = BOL(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX/[%s]=%.2f\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                float sonuc = BOL(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%.2f", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]/AX=%.2f\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                float sonuc = BOL(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%.2f", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]/BX=%.2f\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                float sonuc = BOL(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%.2f", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]/CX=%.2f\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                float sonuc = BOL(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%.2f", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]/DX=%.2f\n", data[j + 2], sonuc);
                j += 6;
            }

        }
        //ve
        if (strcmp(data[j], "VE") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                sonuc = VE(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%d", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                sonuc = VE(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX&%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                sonuc = VE(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX&%s=%d\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                sonuc = VE(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX&%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                sonuc = VE(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX&%s=%d\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VE(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX&BX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VE(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX&CX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VE(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX&DX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VE(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX&AX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VE(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX&CX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VE(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX&DX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VE(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX&AX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VE(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX&BX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VE(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX&DX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VE(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX&AX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VE(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX&BX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VE(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX&CX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VE(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX&[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VE(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX&[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VE(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX&[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VE(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX&[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VE(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]&AX=%d\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VE(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]&BX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VE(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]&CX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VE(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]&DX=%d\n", data[j + 2], sonuc);
                j += 6;
            }
        }
        //veYA
        if (strcmp(data[j], "VEYA") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1]) && isNumber(data[j + 3])) {
                sonuc = VEYA(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%d", sonuc);
                j += 4;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0 && isNumber(data[j + 3])) {
                sonuc = VEYA(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX|%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && isNumber(data[j + 3])) {
                sonuc = VEYA(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX|%s=%d\n", data[j + 3], sonuc, dataMem);
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && isNumber(data[j + 3])) {
                sonuc = VEYA(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX|%s=%d\n", data[j + 3], sonuc);
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && isNumber(data[j + 3])) {
                sonuc = VEYA(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX|%s=%d\n", data[j + 3], sonuc);
                j += 4;
            }
            //-------------------degisken+degisken
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VEYA(j + 1, data, AX, BX, memIndex, dataMem);
                printf("\nAX|BX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VEYA(j + 1, data, AX, CX, memIndex, dataMem);
                printf("\nAX|CX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VEYA(j + 1, data, AX, DX, memIndex, dataMem);
                printf("\nAX|DX=%d\n", sonuc);
                AX = sonuc;
                j += 4;
            }
            //B
            else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VEYA(j + 1, data, BX, AX, memIndex, dataMem);
                printf("\nBX|AX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VEYA(j + 1, data, BX, CX, memIndex, dataMem);
                printf("\nBX|CX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VEYA(j + 1, data, BX, DX, memIndex, dataMem);
                printf("\nBX|DX=%d\n", sonuc);
                BX = sonuc;
                j += 4;
            }
            //C
            else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VEYA(j + 1, data, CX, AX, memIndex, dataMem);
                printf("\nCX|AX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VEYA(j + 1, data, CX, BX, memIndex, dataMem);
                printf("\nCX|BX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "DX") == 0) {
                sonuc = VEYA(j + 1, data, CX, DX, memIndex, dataMem);
                printf("\nCX|DX=%d\n", sonuc);
                CX = sonuc;
                j += 4;
            }
            //D
            else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "AX") == 0) {
                sonuc = VEYA(j + 1, data, DX, AX, memIndex, dataMem);
                printf("\nDX|AX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "BX") == 0) {
                sonuc = VEYA(j + 1, data, DX, BX, memIndex, dataMem);
                printf("\nDX|BX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "CX") == 0) {
                sonuc = VEYA(j + 1, data, DX, CX, memIndex, dataMem);
                printf("\nDX|CX=%d\n", sonuc);
                DX = sonuc;
                j += 4;
            }
            //DEGISKEN+ADRES
            else if (strcmp(data[j + 1], "AX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VEYA(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\nAX|[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "BX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VEYA(j + 1, data, BX, DX, memIndex, dataMem);
                BX = sonuc;
                printf("\nBX|[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "CX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VEYA(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\nCX|[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "DX") == 0 && strcmp(data[j + 3], "[") == 0) {
                int memIndex = atoi(data[j + 4]);

                sonuc = VEYA(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\nDX|[%s]=%d\n", data[j + 4], sonuc);
                j += 6;
            }
            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "AX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VEYA(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n[%s]|AX=%d\n", data[j + 2], sonuc);

                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "BX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VEYA(j + 1, data, BX, CX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]|BX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "CX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VEYA(j + 1, data, CX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]|CX=%d\n", data[j + 2], sonuc);
                j += 6;
            } else if (strcmp(data[j + 1], "[") == 0 && strcmp(data[j + 5], "DX") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = VEYA(j + 1, data, DX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);
                printf("\n[%s]|DX=%d\n", data[j + 2], sonuc);
                j += 6;
            }
        }
        //DEG
        if (strcmp(data[j], "DEG") == 0) {
            //----------------sayi+sayi
            if (isNumber(data[j + 1])) {
                sonuc = DEG(j + 1, data, AX, BX, memIndex, dataMem);
                printf("%s'nin degili : %d", data[j + 1], sonuc);
                j += 2;
            }
            //---------------degisken+sayi
            else if (strcmp(data[j + 1], "AX") == 0) {
                sonuc = DEG(j + 1, data, AX, BX, memIndex, dataMem);
                AX = sonuc;
                printf("\n~AX=%d\n", sonuc);
                j += 2;
            } else if (strcmp(data[j + 1], "BX") == 0) {
                sonuc = DEG(j + 1, data, BX, AX, memIndex, dataMem);
                BX = sonuc;
                printf("\n~BX=%d\n", sonuc);
                j += 2;
            } else if (strcmp(data[j + 1], "CX") == 0) {
                sonuc = DEG(j + 1, data, CX, BX, memIndex, dataMem);
                CX = sonuc;
                printf("\n~CX=%d\n", sonuc);
                j += 2;
            } else if (strcmp(data[j + 1], "DX") == 0) {
                sonuc = DEG(j + 1, data, DX, BX, memIndex, dataMem);
                DX = sonuc;
                printf("\n~DX=%d\n", sonuc);
                j += 2;
            }

            //ADRES+DEGÝSKEN
            else if (strcmp(data[j + 1], "[") == 0) {
                int memIndex = atoi(data[j + 2]);
                char result[50];
                sonuc = DEG(j + 1, data, AX, BX, memIndex, dataMem);
                sprintf(result, "%d", sonuc);
                strcpy(dataMem[memIndex], result);

                printf("\n~[%d]=%d\n", memIndex, sonuc);

                j += 4;
            }

        }
       
    } //END
    
    printf("\nDegiskenlerin degerleri:");
	printf("\nAX=%d\n",AX);
	printf("BX=%d\n",BX);
	printf("CX=%d\n",CX);
	printf("DX=%d\n",DX);
	fclose(fp);
}
