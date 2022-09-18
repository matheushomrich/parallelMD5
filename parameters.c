#include "stdio.h"
#include "stdlib.h"
void sum(int* valorA, int* valorB);
int main(int argc, char const *argv[])
{	
	printf(argv[0]);
	printf("\n");
	int valorA = atoi(argv[1]);
	int valorB = atoi(argv[2]);
	
	int* teste = &valorA;

	int* endereco10 = 06422292;

	printf("valorA:%d\n",valorA);
	printf("valorB:%d\n",valorB);

	sum(&valorA,&valorB);

	printf("valorA:%d\n",valorA);
	printf("valorB:%d\n",valorB);
	
	printf("endereco:%d\n",endereco10);
	printf("endereco:%d\n",*endereco10);

	


	return 0;
}

void sum(int* valorA, int* valorB){
	printf("parametro1:%d\n",valorA);
	printf("parametro2:%d\n",valorB);

	*valorA = 10;
	*valorB = 10;
}
