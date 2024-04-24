#include<stdio.h>
int arr[] = {51, 60, 70, 80, 99};
int size = sizeof(arr) / sizeof (int);
int max, min;
void numero_Max_Min(int *arr, int size, int *max, int *min);

int main(){
	numero_Max_Min(arr, size, &max, &min);
	printf("El valor maximo es: %d y el valor minimo es: %d", max, min);
	return 0;
}
	void numero_Max_Min(int *arr, int size, int *max, int *min){
		int i;
		*max = *min = *arr;
		
		for(i=1; i<size;i++)
		{
			if(*(arr+i) > *max)
			{
				*max = *(arr+i);
			}
			
			if(*(arr+i) < *min)
			{
				*min = *(arr+i);
			}
		}
	}

