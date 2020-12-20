#include <stdio.h>
#include <string.h>
#include <time.h>


// INSERTION SORT



void insertionSort(int *array,int size){

	int   i, j, k;
 
   for (i = 0; ++i < size; ) {
      k = array[i];
      for (j = i; array[j - 1] > k; ) {
         array[j] = array[j - 1];
            if (--j <= 0) break;
      }
      array[j] = k;
   }
}

void insertionCharSort(char *array, int size){

	int   i, j; char k;
 
   for (i = 0; ++i < size; ) {
      k = array[i];
      for (j = i; array[j - 1] > k; ) {
         array[j] = array[j - 1];
            if (--j <= 0) break;
      }
      array[j] = k;
   }
}





// SELECTION SORT

void selectionSort(int *array, int size){

	int i, j, MinValue, temp;
	for (i = 0; i < size; i++)
	{
		MinValue = i;
		for (j = i+1; j < size; j++)
		{
			if (array[j] < array[MinValue])
			{
				MinValue = j;
			}
		}
		temp = array[i];
		array[i] = array[MinValue];
		array[MinValue] = temp;
	}
}

void selectionCharSort(char *array, int size){

	int i, j, MinValue; char temp;
	for (i = 0; i < size; i++)
	{
		MinValue = i;
		for (j = i+1; j < size; j++)
		{
			if (array[j] < array[MinValue])
			{
				MinValue = j;
			}
		}
		temp = array[i];
		array[i] = array[MinValue];
		array[MinValue] = temp;
	}
}


// BUBBLE SORT

void bubbleSort(int *array, int size){

	int i, j, temp;

	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-i-1; j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void bubbleCharSort(char *array, int size){

	int i, j; char temp;

	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-i-1; j++)
		{
			if (array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}



// MERGE SORT

void merge(int *Arr, int start, int mid, int end) {
	int temp[end - start + 1];

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}


void mergeSort(int *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}
 

void mergeChar(char *Arr, int start, int mid, int end) {
	char temp[end - start + 1];

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}


void mergeCharSort(char *Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeCharSort(Arr, start, mid);
		mergeCharSort(Arr, mid+1, end);
		mergeChar(Arr, start, mid, end);
	}
}



// PRINT FUNCTIONS

void printArray(int *array, int size){
	
	int i;
	for(i=0; i < size; i++){
		printf("%d",array[i]);
	}
   	putchar('\n');
}

void printCharArray(char *array){
   		printf("%s\n",array);
}


// QUICK SORT

void quickSort(int *array, int left, int right) {
	

int k, j, q, temp;
k = left;
j = right;
q = array[(left+right)/2]; 

do{
	while ((array[k] < q) && (k < right))
		k++;
	while ((array[j] > q) && (j > left))
		j--;
	if (k <= j) {
		temp = array[k];
		array[k] = array[j];
		array[j] = temp;
		k++; j--;
	}
}while(k <= j);

if (left < j)
	quickSort(array, left, j);
if (k < right)
	quickSort(array, k, right);
}

void quickCharSort(char *array, int left, int right) {
	

int k, j; char q, temp;
k = left;
j = right;
q = array[(left+right)/2]; 

do{
	while ((array[k] < q) && (k < right))
		k++;
	while ((array[j] > q) && (j > left))
		j--;
	if (k <= j) {
		temp = array[k];
		array[k] = array[j];
		array[j] = temp;
		k++; j--;
	}
}while(k <= j);

if (left < j)
	quickCharSort(array, left, j);
if (k < right)
	quickCharSort(array, k, right);
}


// HEAP SORT

void heapify(int *array, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int temp;
 
    if (l < n && array[l] > array[largest])
        largest = l;
 
    if (r < n && array[r] > array[largest])
        largest = r;
 
    if (largest != i)
    {        
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
 
        heapify(array, n, largest);
    }
}

void heapSort(int *array, int size)
{
    int i, temp;
    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
 
    
    for (i = size-1; i>=0; i--)
    {
        temp = array[0];
		array[0] = array[i];
		array[i] = temp;
 
        heapify(array, i, 0);
    }
}

void heapifyChar(char *array, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    char temp;
 
    if (l < n && array[l] > array[largest])
        largest = l;
 
    if (r < n && array[r] > array[largest])
        largest = r;
 
    if (largest != i)
    {        
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
 
        heapifyChar(array, n, largest);
    }
}

void heapCharSort(char *array, int size)
{
    int i; char temp;
    for (i = size / 2 - 1; i >= 0; i--)
        heapifyChar(array, size, i);
    
    for (i = size-1; i>=0; i--)
    {
        temp = array[0];
		array[0] = array[i];
		array[i] = temp;
 
        heapifyChar(array, i, 0);
    }
}


int main(){

	clock_t start, end;
	   
	   //INSERTION SORTS
	
    char myName[] = "SERKANURSAVAS";
	int c_size = strlen(myName);
	int studentNumber[] = {2,0,1,7,5,5,5,5,0,7};
	int a_size = sizeof(studentNumber) / sizeof(studentNumber[0]);
	
	start = clock();
	insertionSort(studentNumber, a_size);
	insertionCharSort(myName, c_size);
	printArray(studentNumber, a_size);
	printCharArray(myName);
	end = clock();
	double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
	   //SELECTION SORTS
	   
	char myName1[] = "SERKANURSAVAS";
	int studentNumber1[] = {2,0,1,7,5,5,5,5,0,7};
	
	start = clock();
	selectionSort(studentNumber1, a_size);
	selectionCharSort(myName1, c_size);
	printArray(studentNumber1, a_size);
	printCharArray(myName1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
	   //BUBBLE SORTS
	   
	char myName2[] = "SERKANURSAVAS";
	int studentNumber2[] = {2,0,1,7,5,5,5,5,0,7};
	
	start = clock();
	bubbleSort(studentNumber2, a_size);
	bubbleCharSort(myName2, c_size);
	printArray(studentNumber2, a_size);
	printCharArray(myName2);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
	   //MERGE SORTS
	   
	char myName3[] = "SERKANURSAVAS";
	int studentNumber3[] = {2,0,1,7,5,5,5,5,0,7};
	
	start = clock();
	mergeSort(studentNumber3, 0, a_size-1);
	mergeCharSort(myName3, 0, c_size-1);
	printArray(studentNumber3, a_size);
	printCharArray(myName3);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
	
	   //QUICK SORTS
	   
	char myName4[] = "SERKANURSAVAS";
	int studentNumber4[] = {2,0,1,7,5,5,5,5,0,7};
	
	start = clock();
	quickSort(studentNumber4, 0, a_size-1);
	mergeCharSort(myName4, 0, c_size-1);
	printArray(studentNumber4, a_size);
	printCharArray(myName4);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
		//HEAP SORT
	
	char myName5[] = "SERKANURSAVAS";
	int studentNumber5[] = {2,0,1,7,5,5,5,5,0,7};

	start = clock();
	heapSort(studentNumber5, a_size);
	heapCharSort(myName5, c_size);
	printArray(studentNumber5, a_size);
	printCharArray(myName5);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by CPU %f\n", cpu_time_used);
	putchar('\n');
	
    return 0;
}

