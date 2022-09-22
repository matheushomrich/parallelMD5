#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "md5.h"

void print_bytes(void *p, size_t length){
	uint8_t *pp = (uint8_t *)p;
	for(unsigned int i = 0; i < length; ++i){
		if(i && !(i % 16)){
			printf("\n");
		}
		printf("%02X ", pp[i]);
	}
	printf("\n");
}

void print_hash(uint8_t *p){
	for(unsigned int i = 0; i < 16; ++i){
		printf("%x", p[i]);
	}
	printf("\n");
}

bool compare(uint8_t *hash1, uint8_t *hash2){
	bool isEqual = true;
	for(unsigned int i = 0; i < 16; ++i){
		if(hash1[i] != hash2[i]){
			isEqual = false;
			break;
		}
	}
	return isEqual;
}

