#include <cstdio>
#include <cstdint>
#include <stdlib.h>

int element(int a)
{
	int b;
	asm
	(
		"movl %1, %%eax\n\t" 
		"movl %%eax, %0\n\t"
		:"=r"(b)        	
		:"r"(a)         	
		:"%eax"
	);
	return a;
}

int el(int b, int c, int i)
{
	asm
	(
 		"movl %1, %%eax\n\t"
		"movl %2, %%ebx\n\t"
		"movl %3, %%ecx\n\t"

 		"cmp $0, %%ecx\n\t"
		"je ls\n\t"
		"movl %%ebx, %%eax\n\t"
		"movl %%eax, %0\n\t"
		
		"ls:\n\t"
		"movl %%eax, %0\n\t"

		:"=r" (b)
		:"r" (b), "r" (c), "r" (i)
		:"%eax", "%ebx", "%ecx"
	);
	return b;
	
}

int elmass(int mass1, int mass2, int i)
{
	int a = mass1, b = mass2;
	int mass = el(mass1, mass2, i);
	return mass;
}

int main()
{
	int n, elem;
	printf("Size: ");
	scanf("%d", &n);
	int *mass1 = new int [n], *mass2 = new int [n];
	printf("Mass1: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		mass1[i] = element(elem);
	}
	printf("Mass2: \n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		mass2[i] = element(elem);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", mass1[i]);
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d", mass2[i]);
		printf("\n");
	}

	int size = n * 2;
	int *mass = new int [size];
	printf("Mass3: \n");
	for (int i = 0; i < size; i++)
	{
		mass[i] = elmass(mass1[i/2], mass2[i/2],i % 2);
		printf("%d", mass[i]);
		printf("\n");
	}

}
