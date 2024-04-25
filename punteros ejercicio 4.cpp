#include<stdio.h>
int vector1[] = {5, 10, 15, 20, 25};
int size = sizeof(vector1) / sizeof(int);
int vector2[size];
int i;
void copiar_Vector(int *vector1, int *vector2, int size);

int main()
{
	copiar_Vector(vector1, vector2, size);
	printf("El segundo vector es: ");
	for(i = 0; i < size, i++)
	{
		printf("%d", vector2[i]);
	}
	printf("/n");
	return 0;
}

    void copiar_Vector(int *vector1, int *vector2, int size)
    {
    	int i;
    	for(i = 0; i < size; i++)
    	{
    		*(vector2 + i) = *(vector1 + i)
		}
	}