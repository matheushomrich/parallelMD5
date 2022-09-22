#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"
#include "printer.h"
#include "time.h"

#define EASY 0
#define MEDIUM 1
#define HARD 2

int generateRandomNum() {
    return rand()%26;
}

void generatePassWord(int size, int difficulty, char letters[], char result[]){
    if (difficulty == EASY) {
        for (size_t i = 0; i < size; i++)
        {
            int randomNumber = generateRandomNum();
            // printf("Numero gerado:%d letra -> %c ",randomNumber, letters[randomNumber]);
            result[i] = letters[randomNumber];
            if(i == size - 1){
                result[i+1] = 0;
            }
        }
    } else if (difficulty == MEDIUM) {
        // printf("MEDIUM");
    } else if (difficulty == HARD) {
        // printf("HARD");
    }
}


int main(int argc, char *argv[]){
    char letters [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //char capitalLetters [26] = toupper(letters);
    char alph[] = {'.',',',':','?','=','-','(',')','/','%','@','!'};
    char numbers [10] = {0,1,2,3,4,5,6,7,8,9};
    uint8_t *hash;
    uint8_t *result;
    int dificuldade = atoi(argv[2]);
    char* senha = argv[1];
    int tamanhoSenha = strlen(senha);
	result = md5String(senha);   

    int count = 0;

    char generatedPassWord[tamanhoSenha + 1];
    generatePassWord(tamanhoSenha, dificuldade, letters, generatedPassWord);
 	hash = md5String(generatedPassWord);
    while (!compare(hash, result)) {
        printf("Tamanho da senha:%d\n",tamanhoSenha);
        generatePassWord(tamanhoSenha, dificuldade, letters, generatedPassWord);
        printf("Gerador de senha(Senha antes do hash): %s \n",generatedPassWord);
        hash = md5String(generatedPassWord);
        printf("Gerador de senha(Depois do hash): ");
        print_bytes(hash,16);  
        printf("Hash sendo procurado: ");
        print_bytes(result,16);  
        printf("\n");
        count ++;
    }

    printf("Senha encontrada: %s\n", generatedPassWord);
    printf("Quantidade de iteracoes: %d", count);

    free(result);
}
