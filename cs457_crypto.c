#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "cs457_crypto.h"
#define DOWN 1
#define UP 0

/*--------------ASKHSH 1-----------------*/

/*vohthikh sunarthsh gia thn dhmiourgia kleidiou*/
char* random_key_generator(int length){
    int i, fd;
    char *key=malloc(sizeof(char)*length);
    if(!key)perror("Malloc Failed.\n");
    fd = open("/dev/urandom", O_RDONLY);
    if (fd==-1) {
        perror("/dev/urandom Failed");
    }
    else {
        if (read(fd, key, length)!=length) {
            perror("/dev/urandom Failed");
        }
    }
    close(fd);
    for (i=0; i<length; i++) {
        key[i]=abs(key[i]);     /*to kleidi einai panta thetiko*/
    }
    return key;
}

/*Encryption*/
char* one_time_pad_encr(char* plainText, int length, char* randomKey){
    int i;
    char*ciphertext=malloc(sizeof(char)*(length+1));
    if(!ciphertext)perror("Malloc Failed.\n");   
    for (i=0; i<length; i++) {  
        ciphertext[i]=randomKey[i]^plainText[i];    
    }
    ciphertext[length] = '\0';
    return ciphertext;
}

/*Decryption*/
char* one_time_pad_decr(char* cipherText, int length, char* randomKey){
    int i;
    char*plaintext=malloc(sizeof(char)*(length+1));
    if(!plaintext)perror("Malloc Failed.\n");    
    for (i=0; i<length; i++) {
        plaintext[i]=randomKey[i]^cipherText[i];    /*XOR the ciphertext with the key to decrypt*/
    }
    plaintext[length] = '\0';
    return plaintext;
}


/*--------------ASKHSH 2-----------------*/

/*vohthitikh sunarthsh pou antistoixizei ta grammata se arithmous*/
int char_to_int(char letter){
    if (letter=='A') return 0;
    else if(letter=='B') return 1;
    else if(letter=='C') return 2;
    else if(letter=='D') return 3;
    else if(letter=='E') return 4;
    else if(letter=='F') return 5;
    else if(letter=='G') return 6;
    else if(letter=='H') return 7;
    else if(letter=='I') return 8;
    else if(letter=='J') return 9;
    else if(letter=='K') return 10;
    else if(letter=='L') return 11;
    else if(letter=='M') return 12;
    else if(letter=='*') return 13;
    else if(letter=='O') return 14;
    else if(letter=='P') return 15;
    else if(letter=='Q') return 16;
    else if(letter=='R') return 17;
    else if(letter=='S') return 18;
    else if(letter=='T') return 19;
    else if(letter=='U') return 20;
    else if(letter=='V') return 21;
    else if(letter=='W') return 22;
    else if(letter=='X') return 23;
    else if(letter=='Y') return 24;
    else if(letter=='Z') return 25;
    else if (letter=='a') return 26;
    else if(letter=='b') return 27;
    else if(letter=='c') return 28;
    else if(letter=='d') return 29;
    else if(letter=='e') return 30;
    else if(letter=='f') return 31;
    else if(letter=='g') return 32;
    else if(letter=='h') return 33;
    else if(letter=='i') return 34;
    else if(letter=='j') return 35;
    else if(letter=='k') return 36;
    else if(letter=='l') return 37;
    else if(letter=='m') return 38;
    else if(letter=='*') return 39;
    else if(letter=='o') return 40;
    else if(letter=='p') return 41;
    else if(letter=='q') return 42;
    else if(letter=='r') return 43;
    else if(letter=='s') return 44;
    else if(letter=='t') return 45;
    else if(letter=='u') return 46;
    else if(letter=='v') return 47;
    else if(letter=='w') return 48;
    else if(letter=='x') return 49;
    else if(letter=='y') return 50;
    else if(letter=='z') return 51;
    else if(letter==' ') return 52;
    return 0;
}
/*vohthitikh sunarthsh pou antistoixizei tous arithmous se grammata*/
int int_to_char(int num){
    if (num==0) return 'A';
    else if(num==1) return 'B';
    else if(num==2) return 'C';
    else if(num==3) return 'D';
    else if(num==4) return 'E';
    else if(num==5) return 'F';
    else if(num==6) return 'G';
    else if(num==7) return 'H';
    else if(num==8) return 'I';
    else if(num==9) return 'J';
    else if(num==10) return 'K';
    else if(num==11) return 'L';
    else if(num==12) return 'M';
    else if(num==13) return '*';
    else if(num==14) return 'O';
    else if(num==15) return 'P';
    else if(num==16) return 'Q';
    else if(num==17) return 'R';
    else if(num==18) return 'S';
    else if(num==19) return 'T';
    else if(num==20) return 'U';
    else if(num==21) return 'V';
    else if(num==22) return 'W';
    else if(num==23) return 'X';
    else if(num==24) return 'Y';
    else if(num==25) return 'Z';
    else if (num==26) return 'a';
    else if(num==27) return 'b';
    else if(num==28) return 'c';
    else if(num==29) return 'd';
    else if(num==30) return 'e';
    else if(num==31) return 'f';
    else if(num==32) return 'g';
    else if(num==33) return 'h';
    else if(num==34) return 'i';
    else if(num==35) return 'j';
    else if(num==36) return 'k';
    else if(num==37) return 'l';
    else if(num==38) return 'm';
    else if(num==39) return '*';
    else if(num==40) return 'o';
    else if(num==41) return 'p';
    else if(num==42) return 'q';
    else if(num==43) return 'r';
    else if(num==44) return 's';
    else if(num==45) return 't';
    else if(num==46) return 'u';
    else if(num==47) return 'v';
    else if(num==48) return 'w';
    else if(num==49) return 'x';
    else if(num==50) return 'y';
    else if(num==51) return 'z';
    else if(num==52) return ' ';
    return 0;
}

char* affine_encr(char *plaintext){
    int length,i,x;
    char* ciphertext;
    length=strlen(plaintext);
    ciphertext=malloc(sizeof(char)*length);
    for(i=0;i<length;i++){
        x=char_to_int(plaintext[i]);       /*metatrepw ta grammata se arithmous gia na kanw thn praksh*/
        if(x!=52){  /*space character*/
            if(x<26)x=(5*x+8)%26;   /*an to x einai mikrotero tou 26 tote eimaste sta kefalaia grammata tou pinaka*/
            else x=(5*x+8)%26+26;   /*alliws eimaste sta mikra opote kanoume +26*/
        }
        ciphertext[i]=int_to_char(x);   /*metatrepw tous arithmous se grammata kai epistrefw to ciphertext*/
    }
    return ciphertext;
}

char* affine_decr(char* ciphertext){
    int length,i,y;
    char* plaintext;
    length=strlen(ciphertext);
    plaintext=malloc(sizeof(char)*length);
    for(i=0;i<length;i++){
        y=char_to_int(ciphertext[i]);   /*metatrepw ta grammata se arithmous gia na kanw thn praksh*/
        if(y!=52) { /*space character*/
            if(y<26) y=21*(y-8)%26;   /*an to y einai mikrotero tou 26 tote eimaste sta kefalaia grammata tou pinaka*/
            else y=21*(y-8)%26+26;  /*alliws eimaste sta mikra opote kanoume +26*/
            if (y<0)y=y+26; /*wrap around. logw afaireshs vgainei arnhtikos arithmos ektos oriwn*/
        }
        plaintext[i]=int_to_char(y);     /*metatrepw tous arithmous se grammata kai epistrefw to plaintext*/
    }
    return plaintext;
}



/*--------------ASKHSH 3-----------------*/
void decryptor(char *ciphertext) {
    char plain, cipher, text[256], plains[52], ciphers[52], buffer[100], string[100];
    char b[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', '*', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 
                  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', '*', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int length, i, counter = 0, j, flag;
    int count[52] = {0};
    int count2[52] = {0};
    FILE *fp;
    char* filename = "tests/words.txt";

    /*Upologizw thn suxnothta kathe xarakthra*/
    i = 0;
    while (ciphertext[i] != '\0') {
        for (j = 0; j < 52; j++) {
            if (ciphertext[i] == b[j]) {
                count[j]++;
            }
        }
        i++;
    }

    printf("CIPHERTEXT FREQUENCY:\n");
    for (j = 0; j < 52; j++) {
        if (count[j] != 0) printf("%c: %d\n", b[j], count[j]);
    }

    /*Upologizw th suxnothta sto dictionary*/
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    printf("DICTIONARY FREQUENCY:\n");
    while (fscanf(fp, "%s", buffer) == 1) {
        i = 0;
        while (buffer[i] != '\0') {
            for (j = 0; j < 52; j++) {
                if (buffer[i] == b[j]) {
                    count2[j]++;
                }
            }
            i++;
        }
    }

    for (j = 0; j < 52; j++) {
        if (count2[j] != 0) printf("%c: %d\n", b[j], count2[j]);
    }

    length = strlen(ciphertext);
    strcpy(text, ciphertext);

    while (1) {
        printf("Give the alphabet letter: ");
        scanf(" %c", &plain);
        printf("Give the cipher alphabet letter: ");
        scanf(" %c", &cipher);
        printf("Mapping: %c -> %c\n", cipher, plain);

        /*Apothikeuw oti exw kanei map*/
        plains[counter] = plain;
        ciphers[counter] = cipher;
        counter++;

        for (i = 0; i < length; i++) {
            flag = 0;
            for (j = 0; j < counter; j++) {
                if (ciphertext[i] == ciphers[j]) {
                    text[i] = plains[j];
                    flag = 1;
                }
            }
            if (flag == 0 && isalpha(text[i])) {
                text[i] = '*';  
            }
        }

        printf("Partially decrypted text:\n%s\n", text);

        printf("Enter partially decrypted word: ");
        scanf("%s", string);

        /*Kanw reset ton file pointer kai psaxnw gia matching words*/
        rewind(fp);
        while (fscanf(fp, "%s", buffer) == 1) {
            if (strlen(buffer) == strlen(string)) {
                flag = 0;
                for (i = 0; i < strlen(string); i++) {
                    if (string[i] != '*' && string[i] != buffer[i]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    printf("Matching word in dictionary: %s\n", buffer);
                }
            }
        }
    }

    fclose(fp);
}

/*--------------ASKHSH 4-----------------*/
char* trithemius_encr(char* plainText){
char tabula_recta_lower[26][26]={ 
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
    {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
    {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
    {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
    {'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
    {'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
    {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
    {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
    {'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
    {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
    {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
    {'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
    {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
    {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
    {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
    {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
    {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
    {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
    {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
    {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
    {'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
    {'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
    {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
    {'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
    {'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
    {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}
};
char tabula_recta_upper[26][26]={ 
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A'},
    {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B'},
    {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'},
    {'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D'},
    {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E'},
    {'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F'},
    {'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
    {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
    {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
    {'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
    {'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'},
    {'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'},
    {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
    {'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'},
    {'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'},
    {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
    {'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'},
    {'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
    {'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'},
    {'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'},
    {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'},
    {'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
    {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'},
    {'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
    {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'}
};
    int i,length,j,k,counter;
    char *tmp;
    int *col,*type;
    length=strlen(plainText);
    tmp = malloc((sizeof(char)*(length + 1)));
    col=malloc(sizeof(int)*length);
    type=malloc(sizeof(int)*length);
    tmp[0]=plainText[0];
    k=1;
    for(i=1;i<length;i++){
        if(plainText[i]==' '){      /*apothikeuw kathe shmeio stikshs ws mia diaforetikh periptwsh*/
            type[k]=2;
            k++;
        }
        else if(plainText[i]=='.'){
            type[k]=3;
            k++;
        }
        else if(plainText[i]==','){
            type[k]=4;
            k++;
        }
        else if(plainText[i]=='?'){
            type[k]=5;
            k++;
        }
        else if(plainText[i]=='!'){
            type[k]=6;
            k++;
        }
        else if(plainText[i]==':'){
            type[k]=7;
            k++;
        }
        else if(plainText[i]==';'){
            type[k]=8;
            k++;
        }
        else {          
            for(j=0;j<26;j++){          
                if(plainText[i]==tabula_recta_upper[0][j]){
                    col[k]=j;   /*apothikeuw th sthlh sthn opoia tha prepei na koitaksw*/
                    type[k]=0;  /*0=kefalaia*/
                    k++;
                }
                else if(plainText[i]==tabula_recta_lower[0][j]){
                    col[k]=j;
                    type[k]=1; /*1=mikra;*/
                    k++;
                }
            }
        }
    }
    k=1;
    counter=1;
    for(i=1;i<length;i++){
        if(type[i-1]==2 || type[i-1]==3 || type[i-1]==4 ||type[i-1]==5 || type[i-1]==6 || type[i-1]==7|| type[i-1]==8) {
            k=i-counter; /*an vreis keno mh proxwrhseis thn epanalhpsh*/
            counter++;
        }
        if (type[i]==0) tmp[i]=tabula_recta_upper[k%26][col[i]];   /*vazw sto array pou tha epistrepsw th katallhlh timh analoga me to an einai gramma h shmeio stikshs h keno*/
        else if(type[i]==1) tmp[i]=tabula_recta_lower[k%26][col[i]];
        else if(type[i]==2)tmp[i]=' ';
        else if(type[i]==3)tmp[i]='.';
        else if(type[i]==4)tmp[i]=',';
        else if(type[i]==5)tmp[i]='?';
        else if(type[i]==6)tmp[i]='!';
        else if(type[i]==7)tmp[i]=':';
        else if(type[i]==8)tmp[i]=';';
        k++;
    }
    free(col);
    free(type);
    tmp[length]='\0'; 
    return tmp;
}

char* trithemius_decr(char* cipherText){
char tabula_recta_lower[26][26]={ 
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
    {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
    {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
    {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
    {'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
    {'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
    {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
    {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
    {'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
    {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
    {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
    {'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
    {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
    {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
    {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
    {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
    {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
    {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
    {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
    {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
    {'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
    {'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
    {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
    {'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
    {'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
    {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}
};
char tabula_recta_upper[26][26]={ 
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A'},
    {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B'},
    {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'},
    {'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D'},
    {'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E'},
    {'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F'},
    {'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G'},
    {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
    {'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
    {'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
    {'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'},
    {'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'},
    {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'},
    {'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N'},
    {'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O'},
    {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
    {'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'},
    {'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
    {'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'},
    {'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'},
    {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'},
    {'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V'},
    {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'},
    {'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
    {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'}
};
    int i,length,j,k,counter;
    char* tmp;
    char temp[26][26];
    int *col,*type;
    length=strlen(cipherText);
    type=malloc(sizeof(int)*length);
    tmp=malloc(sizeof(char)*length);
    col=malloc(sizeof(int)*length);
    tmp[0]=cipherText[0];
    k=1;
    for(i=1;i<length;i++){
        if(cipherText[i]==' '){
            type[k]=2;
            k++;
        }
        else if(cipherText[i]=='.'){
            type[k]=3;
            k++;
        }
        else if(cipherText[i]==','){
            type[k]=4;
            k++;
        }
        else if(cipherText[i]=='?'){
            type[k]=5;
            k++;
        }
        else if(cipherText[i]=='!'){
            type[k]=6;
            k++;
        }
        else if(cipherText[i]==':'){
            type[k]=7;
            k++;
        }
        else if(cipherText[i]==';'){
            type[k]=8;
            k++;
        }
        for(j=0;j<26;j++){
            if(cipherText[i]==tabula_recta_upper[0][j]){
                col[k]=j;   /*krataw tis sthles pou tha koitaksw*/
                type[k]=0; 
                k++;
            }
            else if(cipherText[i]==tabula_recta_lower[0][j]){
                col[k]=j;
                type[k]=1;
                k++;
            }
        }
    }

    for (i=0; i<26; i++) {
        for (j=0; j<26; j++) {
            temp[i][j]=tabula_recta_lower[i][j];
        }
    }           /*anapodogurizoume to array gia to decryption*/
    for (i=0; i<26; i++) {
        for (j=0; j<26; j++) {
            tabula_recta_lower[i][j]=temp[26-i][j];
        }
    }
    for (i=0; i<26; i++) {
        for (j=0; j<26; j++) {
            temp[i][j]=tabula_recta_upper[i][j];
        }
    }           /*anapodogurizoume to array gia to decryption*/
    for (i=0; i<26; i++) {
        for (j=0; j<26; j++) {
            tabula_recta_upper[i][j]=temp[26-i][j];
        }
    }
    k=1;
    counter=1;
    for(i=1;i<length;i++){
        if(type[i-1]==2 || type[i-1]==3 || type[i-1]==4 ||type[i-1]==5 || type[i-1]==6 || type[i-1]==7|| type[i-1]==8) {
            k=i-counter; /*an vreis keno mh proxwrhseis thn epanalhpsh*/
            counter++;
        }
        if (type[i]==0) tmp[i]=tabula_recta_upper[k%26][col[i]];   /*vazw sto array pou tha epistrepsw th katallhlh timh analoga me to an einai gramma h shmeio stikshs h keno*/
        else if(type[i]==1) tmp[i]=tabula_recta_lower[k%26][col[i]];
        else if(type[i]==2)tmp[i]=' ';
        else if(type[i]==3)tmp[i]='.';
        else if(type[i]==4)tmp[i]=',';
        else if(type[i]==5)tmp[i]='?';
        else if(type[i]==6)tmp[i]='!';
        else if(type[i]==7)tmp[i]=':';
        else if(type[i]==8)tmp[i]=';';
        k++;
    }
    free(col);
    free(type);
    tmp[length]='\0'; 
    return tmp;
}
/*--------------ASKHSH 5-----------------*/

char keep[200],keep2a[200][200];

char* scytale_encr(char* plainText, int diameter){
    char text[200];
    char* ciphertext;
    char scytale[200][5];
    int length,i,k,j,rows;
    length=strlen(plainText);
    k=0;
    ciphertext = malloc(200*sizeof(char));
    for(i=0;i<length;i++){
        if(plainText[i]==' ' || plainText[i]==',' || plainText[i]=='.' || plainText[i]=='?' || plainText[i]=='!'|| plainText[i]==':'|| plainText[i]==';'){
            keep[i]=plainText[i];       /*krataw se enan global pinaka ta shmeia stikshs gia na kserw pou na ta valw meta*/
        }
        else {
            keep[i]='*';        /*sth thesh twn grammatwn vazw asterakia, ta opoia tha antikatasthsw meta me to swsto gramma*/
            text[k]=plainText[i];
            k++;
        }
    }
    text[k]='\0';
    length=strlen(text);
    rows=(length+diameter-1)/diameter;  /*kanw stroggulopoihsh stis grammes analoga me to posous xarakthres dwsei o xrhsths*/
    k=0;
    for (i=0; i<rows; i++) {
        for (j=0;j<diameter; j++) { /*diavazw to text katheta sthlh-sthlh*/
            if (k<length) {
                scytale[i][j]=text[k];   /*kai vazw to text sth skutalh*/
                k++;
            } 
            else {
                scytale[i][j]=' '; /*padding*/
                keep2a[i][j]='*';  /*krataw ta spaces gia na ta ksanavalw pisw*/
            }
        }
    }
    printf("\nScytale Encryption:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<diameter;j++){
            printf("| %c |",scytale[i][j]);
        }
        printf("\n");
    }

    k=0;
    for (j=0; j<diameter; j++) {
        for (i=0; i<rows; i++) {        /*diavazw to text orizontia*/
            if (scytale[i][j]!= ' ') {
                ciphertext[k]=scytale[i][j];  /*afairw ta kena*/
                k++;
            }
        }
    }
    ciphertext[k]='\0';
    return ciphertext;
}
char* scytale_decr(char* cipherText, int diameter) {
    char scytale[200][5];
    char *plaintext;
    int i, k, j, length, rows;
    plaintext = malloc(200 * sizeof(char));
    length=strlen(cipherText);
    rows=(length+diameter-1)/diameter;
    k=0;
    for (j=0; j<diameter; j++) {
        for (i=0; i<rows; i++) {        /*diatrexw tis sthles kai apothikeuw pisw sth skutalh*/
            if (keep2a[i][j] != '*') {          
                scytale[i][j]=cipherText[k];    /*an vrw xarakthra ton vazw sth skutalh*/
                k++;
            } 
            else {
                scytale[i][j]=' ';      /*alliws vazw keno*/
            }
        }
    }

    k=0;
    for (i=0; i<rows; i++) {
            for (j=0; j<diameter; j++) {
            if (scytale[i][j]!= ' ') {
                plaintext[k]=scytale[i][j];   /*vazw to text ths skutalhs se 1d array*/
                k++;
            }
        }
    }
    plaintext[k]='\0';
    k=0;
    for (i=0; i<strlen(keep); i++) {
        if (keep[i]=='*' && k<strlen(plaintext)) {      /*antikathistw ta asterakia me to text*/
            keep[i]=plaintext[k];
            k++;
        }
    }
    return keep;
}

/*--------------ASKHSH 6-----------------*/

char keep2[200];
char* rail_fence_encr(char *plainText, int num) {
    int length,i,j,direction,k; 
    char zigzag[1000][1000];
    char text[200];
    char *final;
    length= strlen(plainText);
    final=malloc(sizeof(char)*200);
    k=0;
    for(i=0;i<length;i++){
        if(plainText[i]==' ' || plainText[i]==',' || plainText[i]=='.' || plainText[i]=='?' || plainText[i]=='!'|| plainText[i]==':'|| plainText[i]==';'){
            keep2[i]=plainText[i]; /*krataw se enan global pinaka ta shmeia stikshs gia na kserw pou na ta valw meta*/
        }
        else {
            keep2[i]='*';  /*sth thesh twn grammatwn vazw asterakia, ta opoia tha antikatasthsw meta me to swsto gramma*/
            text[k]=plainText[i];
            k++;
        }
    }
    text[k]='\0';
    length=strlen(text);

    for (i=0; i<num; i++) {
        for (j=0; j<length; j++) {
            zigzag[i][j]=' ';       /*arxikopoiw ton pinaka me kena*/
        }
    }

    /*algorithmos eisagwghs keimenou se zigzag morfh*/
    i=0;
    direction=DOWN; /*arxika h kateuthunsh einai pros ta katw*/
    
    for (j=0; j<length; j++) {
        zigzag[i][j]=text[j];
        if (i==0) {                 /*an eimaste sth prwth grammh katevainoume*/
            direction=DOWN; 
        }
        else if (i==num-1) {        /*an eimaste sth teleutaia grammh anevainoume*/
            direction=UP;
        } 
        if (direction==DOWN) {      /*an theloume na katevoume katw auksanoume ta rows gia na katevoume ston pinaka*/
            i++;
        } 
        else if(direction==UP){        /*an theloume na anevoume pros ta panw meiwnoume ta rows gia na anevoume ston pinaka*/
            i--;    
        }
    }
    for (i=0; i<num; i++) {
        for (j=0; j<length; j++) {
            printf("| %c |",zigzag[i][j]);      
        }
        printf("\n");
    }
    k=0;
    for(i=0;i<num;i++){
        for(j=0;j<length;j++){
            if(zigzag[i][j]!=' '){      /*apothikeuw se ena 1d array to text xwris kena*/
                final[k]=zigzag[i][j];
                k++;
            }
        }
        final[k]=' ';       /*keno after a rail*/
        k++;
    }
    final[k]='\0';
    return final;
}
char* rail_fence_decr(char *cipherText){
    int length,i,j,direction,k; 
    char text[200];
    char *final;
    int num;
    char zigzag[1000][1000];
    length=strlen(cipherText);
    final=malloc(sizeof(char)*200);
    k=0;
    num=1;
    for(i=0;i<length;i++){
        if(cipherText[i]!=' '){     /*apothikeuw to text xwris kena*/
            text[k]=cipherText[i];
            k++;
        }
        else num++;     /*an vrw kena ta apothikeuw giati o aritmhmos twn kenwn=arithos twn rails*/
    }
    text[k]='\0';
    length=strlen(text);
    for (i=0; i<num; i++) {
        for (j=0; j<length; j++) {
            zigzag[i][j]=' ';       /*arxikopoiw ton pinaka me kena*/
        }
    }

    /*idios algorithmos eisagwghs keimenou se zigzag morfh*/
    i=0;
    direction=DOWN;

    for (j=0; j<length; j++) {
        zigzag[i][j]='*';       /*anti gia to text edw sto zigzag vazoume asterakia wste na ta antikatasthsoume meta orizontia*/
        if (i==0) {
            direction=DOWN;
        }
        else if (i==num-1) {
            direction=UP;
        } 
        if (direction==DOWN) {
            i++;
        } 
        else if(direction==UP){
            i--;
        }
    }
    k=0;
    for(i=0;i<num;i++){
        for(j=0;j<length;j++){
            if(zigzag[i][j]=='*'){  /*opou sunanthsw asteraki vazw to ciphertext diavazontas ton pinaka orizontia*/
                zigzag[i][j]=text[k];   /*etsi prokuptei sto zigzag na exoume to plaintext*/
                k++;
            }
        }
    }   
    for (i=0; i<num; i++) {
        for (j=0; j<length; j++) {
            printf("| %c |",zigzag[i][j]);
        }
        printf("\n");
    }
    k=0;
    for (j=0; j<length; j++) {
        for (i=0; i<num; i++) {
            if (zigzag[i][j]!=' ') {
                final[k]=zigzag[i][j];      /*apothikeuw se ena 1d array to text*/
                k++;
            }
        }
    }
    final[k]='\0';
    k=0;
    for (i=0; i<strlen(keep2); i++) {
        if (keep2[i]=='*' && k<strlen(final)) {     /*vazw ta kena kai ta shmeia stikshs pou eixa apothikeusei*/
            keep2[i]=final[k];
            k++;
        }
    }
    keep2[i]='\0';
    return keep2;
}
