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
int main() {
    FILE * fp;
    int i = 0, k = 0, j;
    int jct, ct, je;
    char data2[][1000] = {""};
    char data[1000][1000] = {""};
    char data3[][1000] = {""};
    char c[1000][1000] = {"" };
    char veriYolu[100];
    bool t1 = false, t2 = false, t3 = false;
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
    //PARSER-----------------------------------------------------------
    j = 0;
    //if
    if ((strcmp(data[j], "if") == 0) && (strcmp(data[j + 1], "(") == 0)) {
        j = j + 2;
        t1 = true;
        if (isSart(j, data)) {
            t1 = true;
            j += 3;
        } else {
            t1 = false;
        }
        if (strcmp(data[j], ")") == 0) {
            t1 = true;
            j++;
        } else {
            t1 = false;
        }
        if (strcmp(data[j], "{") == 0) {
            t1 = true;
            j++;
        } else {
            t1 = false;
        }
        ct = 0;
        jct = j;
        bool x = true;

        if (strcmp(data[12], "}") == 0 || strcmp(data[10], "}") == 0) {
            while (strcmp(data[jct], "}") != 0 && j < k) {
                ct++;
                jct++;
            }
        } else {
            t1 = false;
        }

        if (isSentence(j, data)) {
            t1 = true;
            j += ct;
        }
        if (strcmp(data[j], "}") == 0) {
            j++;
            t1 = true;
        } else {
            t1 = false;
        }
    } else {
        t1 = false;
    }
    int flag1 = j;
    //else if
    for (je = j; je < k && (strcmp(data[je], "else") != 0) && t1 == true; je++) {
        if ((strcmp(data[je], "else if") == 0) && (strcmp(data[je + 1], "(") == 0)) {
            je += 2;
            if (isSart(je, data) == true && (strcmp(data[je + 3], ")") == 0)) {
                je += 4;
                t2 = true;
            } else {
                t2 = false;
                break;
            }
            ct = 0;
            jct = je;
            if (strcmp(data[flag1 + 12], "}") == 0 || strcmp(data[flag1 + 10], "}") == 0) {
                while (strcmp(data[jct], "}") != 0 && je < k) {
                    ct++;
                    jct++;
                }
            } else {
                t2 = false;
                break;
            }
            if (strcmp(data[je], "{") == 0 && isSentence(je + 1, data) == true) {
                je += ct;
                t2 = true;
                if (strcmp(data[je], "}") == 0) {
                    je++;
                    t2 = true;
                } else {
                    t2 = false;
                    break;
                }
            } else {
                t2 = false;
                break;
            }
            je--;
        } else {
            t2 = false;
            break;
        }
    }
    j = je;
    int flag2 = j;
    //else
    if ((strcmp(data[j], "else") == 0) && (strcmp(data[j + 1], "{") == 0)) {
        t3 = true;
        j += 2;
        int ct = 0;
        int jct = j;
        if (strcmp(data[flag2 + 5], "}") == 0 || strcmp(data[flag2 + 7], "}") == 0) {
            while (strcmp(data[jct], "}") != 0 && j < k) {
                ct++;
                jct++;
            }
        } else {
            t3 = false;
        }
        if (isSentence(j, data)) {
            t3 = true;
            j += ct;
        } else {
            t3 = false;

        }
        if (strcmp(data[j], "}") == 0) {
            t3 = true;
            j++;
        } else {
            t3 = false;

        }
    }
    //PARSER-----------------------------------------------------------	
    int flag3 = j;
    if ((t1 == true && * data[flag1] == 0) || (t1 == true && (t3 == true && * data[flag3] == 0)) || (t1 == true && (t2 == true && * data[flag2] == 0)) || (t1 == true && t2 == true && (t3 == true && * data[flag3] == 0))) {
        printf("\ndosya dogrudur \n");
    } else {
        printf("\ndosya hatalidir\n");
    }
    fclose(fp);
}
