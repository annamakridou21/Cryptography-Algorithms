#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "cs457_crypto.h"
char* random_key_generator(int length);
int main(int argc, char *argv[]) {
FILE *file;
char* s1,*s2,*scytale_e,*scytale_d,* text,* p,*p1,*c,*encryptedText,*decryptedText,*plaintext,* key,*cipher;
char ciphertext[200];
int i,length,exercise;
printf("\nGive the number of the exercise you want to test: ");
scanf("%d",&exercise);
printf("\n");
if(exercise==1){
    plaintext="hello4934";
    length=strlen(plaintext);
    key=random_key_generator(length);
    cipher=one_time_pad_encr(plaintext, length, key);
    printf("Plaintext given: ");
    for (i=0; i<length; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\nPlaintext in HEX: ");
    for (i=0; i<length; i++) {
        printf("%x", plaintext[i]);
    }
    printf("\nKey: ");
    for (i = 0; i < length; i++) {
        printf("%x", key[i]);
    }
    printf("\n\n");
    for (i = 0; i < length; i++) {
        printf("%x XOR %x=%x\n", plaintext[i],key[i],cipher[i]);
    }
    printf("\nEncrypted text:");
    for (i = 0; i < length; i++) {
        printf("%x", cipher[i]);
    }
    printf("\n");

    plaintext=one_time_pad_decr(cipher,length,key);
    printf("Decrypting the plaintext again:");
    for (i = 0; i < length; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");
    free(key);
    free(cipher);
}
else if(exercise==2){
    text="affine CIPHER";
    length=strlen(text);
    p=malloc(sizeof(char)*length);
    p=affine_encr(text);
    printf("Encrypting: %s\n==>",text);
    printf("%s",p);
    printf("\n");
    c=malloc(sizeof(char)*length);
    c=affine_decr(p);
    printf("Decrypting: %s\n==>",p);
    printf("%s",c);
}
else if(exercise==3){
    if (argc!=2) {
    return 1;
    }
    file=fopen(argv[1], "r");
    if (file==NULL) {
        perror("File failed.\n");
        return 1;
    }
    fgets(ciphertext, 200, file);
    fclose(file);
    decryptor(ciphertext);
}
else if(exercise==4){
    p1= "HELLO HELLO ???HELLO HELLO HELLO !!!";
    encryptedText = trithemius_encr(p1);

    printf("Plaintext: %s\n", p1);
    printf("Encrypted Text: %s\n", encryptedText);


    decryptedText = trithemius_decr(encryptedText);
    printf("Decrypted Text: %s\n", decryptedText);
    
    free(encryptedText); 
    free(decryptedText); 
}
else if(exercise==5){
    text="I am hurt!!! very badly helpppp!!!";
    printf("\nPlaintext: %s\n",text);
    scytale_e=scytale_encr(text,5);
    printf("\nCiphertext: %s\n",scytale_e);
    scytale_d=scytale_decr(scytale_e,5);
    printf("\nPlaintext Decrypted: %s\n",scytale_d);
}
else if(exercise==6){
    text = "WE ARE DISCOVERED. RUN AT ONCE.";
    printf("Plaintext: %s\n\n",text);
    cipher="WIRA EDSEENTE AECVDUOC RORN";
    s1=rail_fence_encr(text, 4);
    printf("\nCiphertext: %s\n\n",s1);
    s2=rail_fence_decr(cipher);
    printf("\nPlaintext: %s\n",s2);
}
return 0;
}
