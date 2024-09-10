/*--------------ASKHSH 1-----------------*/
char* random_key_generator(int length);
char* one_time_pad_encr(char* plainText, int length, char* randomKey);
char* one_time_pad_decr(char* cipherText, int length, char* randomKey);
/*--------------ASKHSH 2-----------------*/
char* affine_encr(char* plaintext);
char* affine_decr(char* ciphertext);
/*--------------ASKHSH 3-----------------*/
void decryptor(char *ciphertext);
/*--------------ASKHSH 4-----------------*/
char* trithemius_encr(char* plainText);
char* trithemius_decr(char* cipherText);
/*--------------ASKHSH 5-----------------*/
char* scytale_encr(char* plainText, int diameter);
char* scytale_decr(char* cipherText,int diameter);
/*--------------ASKHSH 6-----------------*/
char* rail_fence_encr(char *plainText, int num);
char* rail_fence_decr(char *cipherText);
