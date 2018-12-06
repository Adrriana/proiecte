#include<stdio.h>
#include<string.h>

int main(){
    char text[] = "AZI";
    char key[] = "HELLO";
    int textLen = strlen(text), keyLen = strlen(key), i, j;

    char newKey[textLen], encrypted[textLen], decrypted[textLen];


    
    for(i = 0, j = 0; i < textLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < textLen; ++i)
        encrypted[i] = ((text[i] + newKey[i]) % 26) + 'A';

    encrypted[i] = '\0';

    //decryption
    for(i = 0; i < textLen; ++i)
        decrypted[i] = (((encrypted[i] - newKey[i]) + 26) % 26) + 'A';

    decrypted[i] = '\0';

    printf("Textul este: %s", text);
    printf("\nKey: %s", key);
    printf("\nNoua cheie generata: %s", newKey);
    printf("\nMesajul criptat: %s", encrypted);
    printf("\nMesajul decriptat: %s", decrypted);

    return 0;
}
