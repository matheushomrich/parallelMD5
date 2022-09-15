#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "md5.h"

int main(int argc, char *argv[]){

    char letters [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //char capitalLetters [26] = toupper(letters);
    char alph[] = {'.',',',':','?','=','-','(',')','/','%','@','!'};
    char numbers [10] = {0,1,2,3,4,5,6,7,8,9};
    uint8_t *hash;
    uint8_t *result;

    // flag dificudade
    const EASY;
    const MEDIUM;
    const HARD;

    char generateRandomNum( int minimum_number, int max_number) {
        return rand() % (max_number + 1 - minimum_number) + minimum_number;
    }

    //geradorDeSenha
    char hashGenerator(int size, const difficulty) {

        char result [size];

        if (difficulty == EASY) {

            for (int i = 0; i < size; ++i)
            {
                result[i] = letters[generateRandomNum(26, 0)];
            }

            return result;
        } else if (difficulty == MEDIUM) {
            printf("MEDIUM");
        } else if (difficulty == HARD) {
            printf("HARD");
        }
    }

	result = md5String(argv[1]);
	print_hash(result);
	
    hash = hashGenerator(4, EASY);

    while (result != hash) {
        printf(hashGenerator(4, EASY));
        hash = hashGenerator(4, EASY);
    }
    free(result);

}
