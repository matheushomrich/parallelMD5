#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"
#include "printer.h"
#include "time.h"
#include <omp.h>

#define EASY 0
#define MEDIUM 1
#define HARD 2


int generateRandomNum()
{
    return rand() % 26;
}

void generatePassWord(int size, int difficulty, char letters[], char numberLetters[],char result[])
{
    if (difficulty == EASY)
    {
        for (size_t i = 0; i < size; i++)
        {
            int randomNumber = generateRandomNum();
            // printf("Numero gerado:%d letra -> %c ",randomNumber, letters[randomNumber]);
            result[i] = letters[randomNumber];
            if (i == size - 1)
            {
                result[i + 1] = 0;
            }
        }
    }
    else if (difficulty == MEDIUM)
    {
        int randomNumber = generateRandomNum();
            // printf("Numero gerado:%d letra -> %c ",randomNumber, numbersLetters[randomNumber]);
            result[i] = numberLetters[randomNumber];
            if (i == size - 1)
            {
                result[i + 1] = 0;
            }
    }
    else if (difficulty == HARD)
    {
        // printf("HARD");
    }
}

int main(int argc, char *argv[])
{
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char numbersletters[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4, '5', '6', '7', '8', '9'};
    char numbersLettersSybomls[1] = ['a']
    uint8_t *hash;
    uint8_t *result;
    int dificuldade = atoi(argv[2]);
    char *senha = argv[1];
    int tamanhoSenha = strlen(senha);
    result = md5String(senha);
    int count = 0;
    double starttime, stoptime;
    starttime = omp_get_wtime(); 
    char generatedPassWord[tamanhoSenha + 1];
    int flag = 1;
    #pragma omp parallel num_threads(atoi(argv[3])) shared(count,flag,result) private(hash,generatedPassWord,stoptime)
    {
        srand(omp_get_thread_num());
        while(flag)
        {
            generatePassWord(tamanhoSenha, dificuldade, letters, numbersletters, generatedPassWord);
            hash = md5String(generatedPassWord);
            count++;
            
            if(compare(result, hash)){
                stoptime = omp_get_wtime();
                printf("Tempo de execucao: %3.2f segundos\n", stoptime-starttime);
                printf("Senha encontrada: %s\n", generatedPassWord);
                printf("Quantidade de iteracoes: %d\n", count);
                printf("Thread: %d\n\n", omp_get_thread_num());
                flag = 0;
            }
        }
    }
    free(result);
}
