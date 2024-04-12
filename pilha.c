#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void push(int n);
int pop(void);

int *tos, *p1, stack[SIZE];

int main(int argc, char *argv[]) {
	int value;
	register int i;
	
	tos = stack;
	p1 = stack;
	
	do {
		printf("Digite um numero: ");
		scanf("%d", &value);
		if(value == -1) break;
		if(value == 0) printf("%d foi removido da pilha!\n", pop());
		else push(value);
	} while(value != -1);
	
	for(i=0; stack[i]; i++) printf("[%3d ]\n", stack[i]);
	
	return 0;
}
void push(int n) {
	if(p1 == (tos + SIZE)) {
		printf("Pilha cheia!\n");
		exit(1);
	}
	*p1 = n; p1++;
}
int pop(void) {
	int temp;
	if(p1 == tos) {
		printf("Pilha vazia!\n");
		exit(1);
	}
	p1--; temp = *p1; *p1 = 0;
	return temp;
}
