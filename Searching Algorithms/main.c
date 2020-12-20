#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
  {   int studentId[15];
      char fullName[30];
      char grade[5];
  }STUDENT;

  // SEARCH IN INTEGER ARRAYS
int linearSearch(int *arr, int key, int size, int Result[]){
 int i=0, k;
  for (k=0; k < size; k++){
    if (arr[k] == key){
      // found, insert into Result array
      Result[i]=k;
      i++;
    }
  }
  return i;
}
int binarySearch(int *arr, int key, int size) {
  int left =0;
  int right = size-1;
  int middle;
  while (left <= right) {
    middle = (left + right)/2;
    if (key == arr[middle])
      return middle;
    else if (key > arr[middle])
      left = middle + 1;
    else
      right = middle - 1;
  }
  return-1;
}

  // SEARCH IN STRUCT ARRAYS WITH PRIMARY KEY
int linearSearchForStruct(STUDENT arr[], int key, int size){
  int i;
  for (i = 0; i < size; i++){
    if (*arr[i].studentId == key)
      return i;
    }
  return -1;
} 
int binarySearchForStruct(STUDENT arr[], int key, int size) {
  int left =0;
  int right = size-1;
  int middle;
  while (left <= right) {
    middle = (left + right)/2;
    if (key == *arr[middle].studentId)
      return middle;
    else if (key > *arr[middle].studentId)
      left = middle + 1;
    else
      right = middle - 1;
  }
  return-1;
}

  // SEARCH IN STRUCT ARRAYS WITH SECONDARY KEY
int secondaryKeySearchForName(STUDENT arr[], int size, int Result[], char *key){
  int i=0, k;
  
  for (k=0; k < size; k++){
    if (strcmp(arr[k].fullName,key)==0){
      // found, insert into Result array
      Result[i]=k;
      i++;
  }
}
return i;
}

int secondaryKeySearchForGrade(STUDENT arr[], int size, int Result[], char *key){
  int i=0, k;
  
  for (k=0; k < size; k++){
    if (strcmp(arr[k].grade,key)==0){
      // found, insert into Result array
      Result[i]=k;
      i++;
  }
}
return i;
}

int binarySearchWithSecondaryKey(STUDENT arr[], int size,int Result[], char *key) {
    int left,sum = 0;
    int right = size -1;
    int middle;
    while (left <= right) {
        middle = (left + right)/2;
      if (strcmp(key, arr[middle].fullName) == 0){
        Result[sum]=middle;
        sum++;
        if(strcmp(key, arr[middle-1].fullName) == 0){
          Result[sum]=middle-1;
          sum++;
        }
        if(strcmp(key, arr[middle+1].fullName) == 0){
          Result[sum]=middle+1;
          sum++;
        }
        break;
    }
      else if (strcmp(key, arr[middle].fullName) > 0){
        left = middle + 1;
        }
      else{
        right = middle - 1;
        }
  }
  return sum;
}

int binarySearchWithSecondaryKeyForGrade(STUDENT arr[], int size,int Result[], char *key) {
    int left,counter = 0;
    int right = size -1;
    int middle;
    while (left <= right) {
        middle = (left + right)/2;
      if (strcmp(key, arr[middle].grade) == 0){
        Result[counter]=middle;
        counter++;
        if(strcmp(key, arr[middle-1].grade) == 0){
          Result[counter]=middle-1;
          counter++;
        }
        if(strcmp(key, arr[middle+1].grade) == 0){
          Result[counter]=middle+1;
          counter++;
        }
        if(strcmp(key, arr[middle+2].grade) == 0){
          Result[counter]=middle+2;
          counter++;
        }
        if(strcmp(key, arr[middle-2].grade) == 0){
          Result[counter]=middle-2;
          counter++;
        }
        break;
    }
      else if (strcmp(key, arr[middle].grade) < 0){
        left = middle + 1;
        }
      else{
        right = middle - 1;
        }
  }
  return counter;
}

// SORTING AND PRINT FUNCTIONS

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

void insertionSortForStruct(STUDENT arr[],int size){
	int   i, j, k ;
  STUDENT temp;
  
   for (i = 0; ++i < size; ) {
      k = *arr[i].studentId;
      for (j = i; *arr[j - 1].studentId > k; ) {
          temp = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = temp;
          if (--j <= 0) break;
      }
      *arr[j].studentId = k;
   }
}

void SortForStructChar(STUDENT arr[],int size){
	int   i, j ;
  char k;
  STUDENT temp;
   for (i = 1; i < size; i++)
      for (j = 0; j < size - i; j++) {
         if (strcmp(arr[j].fullName, arr[j + 1].fullName) > 0) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
}

void printArray(int *array, int size){
	
	int i;
	for(i=0; i < size; i++){
		printf("%d\t",array[i]);
	}
   	putchar('\n');
}

void SortForStructCharForGrade(STUDENT arr[],int size){
	int   i, j ;
  char k;
  STUDENT temp;
   for (i = 1; i < size; i++)
      for (j = 0; j < size - i; j++) {
         if (strcmp(arr[j].grade, arr[j + 1].grade) < 0) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
}

void searchInArrays(){
  // LINEAR SEARCH IN ARRAYS
  int array1[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
  int array2[] = {3,44,48,5,47,15,36,26,27,2,48,5,19,50,48};
  int a_size = sizeof(array1) / sizeof(array1[0]);
  
  printf("***********************************LINEAR SEARCH IN ARRAYS***********************************\n\nFirst Array: ");
  printArray(array1, a_size);
  int numberToSearch[3] = {3, 5, 48};
  int counter;
  int Result[15];
  
  for(counter = 0; counter < 3; counter++){
    int result = linearSearch(array1, numberToSearch[counter], a_size, Result);
    printf("\tNumber to search: %d\t\t Index of the number: %d\n",numberToSearch[counter], Result[0]);
  }

  printf("\nSecond Array: ");
  printArray(array2, a_size);
  int result;
  for(counter = 0; counter < 3; counter++){
    result = linearSearch(array2, numberToSearch[counter], a_size, Result);
    printf("\n\tNumber to search: %d\t\t Index of the numbers: ",numberToSearch[counter]);
    for (int i = 0; i < result; i++){
      printf("%d,", Result[i]);
    }
  }

  // BINARY SEARCH IN ARRAYS
  selectionSort(array1, a_size);
  printf("\n\n***********************************BINARY SEARCH IN ARRAYS***********************************\n\n");
  printf("Sorted First Array:\t");
  printArray(array1, a_size);
  for(counter = 0; counter < 3; counter++){
    int result = binarySearch(array1, numberToSearch[counter], a_size);
    printf("\tNumber to search: %d\t\t Index of the number: %d\n",numberToSearch[counter], result);
  }

  selectionSort(array2, a_size);
  printf("\nSorted Second Array:\t");
  printArray(array2, a_size);
  for(counter = 0; counter < 3; counter++){
    int result = binarySearch(array2, numberToSearch[counter], a_size);
    printf("\tNumber to search: %d\t\t Index of the number: %d\n",numberToSearch[counter], result);
  }
}

void searchInStructWithPrimaryKey(){

  // READ DATA IN TEXT FILE
  FILE *file;
    int i = 0;
    STUDENT student_data[273];
    file = fopen("data.txt", "r");

    while (3 == fscanf(file, "%15d %30s %5s",  student_data[i].studentId,
    student_data[i].fullName,  student_data[i].grade))
    {
      i++;
    }

  // LINEAR SEARCH IN STRUCT WITH PRIMARY KEY
  int result = linearSearchForStruct(student_data, 2019556465, 273);
  printf("*******************************LINEAR SEARCH IN STRUCT WITH PRIMARY KEY*******************************\n\n");
  printf("Dialed Student ID:2019556465 \t\t Student Id: %d, Name: %s, Grade: %d\n", *student_data[result].studentId, student_data[result].fullName, *student_data[result].grade);

  int result1 = linearSearchForStruct(student_data, 2018556011, 273);
  printf("Dialed Student ID:2018556011 \t\t Student Id: %d, Name: %s, Grade: %d\n\n", *student_data[result1].studentId, student_data[result1].fullName, *student_data[result1].grade);
  
  // BINARY SEARCH IN STRUCT WITH PRIMARY KEY
  insertionSortForStruct(student_data, 273);

  printf("*******************************BINARY SEARCH IN STRUCT WITH PRIMARY KEY*******************************\n\n");
  int result2 = binarySearchForStruct(student_data, 2018556011, 273);
  printf("Dialed Student ID:2018556011 \t\t Student Id: %d, Name: %s, Grade: %d\n", *student_data[result2].studentId, student_data[result2].fullName, *student_data[result2].grade);

  int result3 = binarySearchForStruct(student_data, 2019556465, 273);
  printf("Dialed Student ID:2019556465 \t\t Student Id: %d, Name: %s, Grade: %d\n", *student_data[result3].studentId, student_data[result3].fullName, *student_data[result3].grade);
  
}

void searchInStructWithSecondaryKey(){
  // READ DATA IN TEXT FILE
  FILE *file;
    int i = 0;
    STUDENT student_data[273];
    file = fopen("data.txt", "r");

    while (3 == fscanf(file, "%15d %30s %5s",  student_data[i].studentId,
    student_data[i].fullName,  student_data[i].grade))
    {
      i++;
    }


  //LINEAR SEARCH IN STRUCT WITH SECONDARY KEY
  
  printf("*****************************LINEAR SEARCH IN STRUCT WITH SECONDARY KEY*****************************\n\n");
  char key[] = "MEHMET_IPEK";
  int Result[15];
  int result = secondaryKeySearchForName(student_data, 273, Result, key);
  printf("'MEHMET_IPEK' araması için bulunan sonuç sayısı: %d\n", result);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result[0]].studentId, student_data[Result[0]].fullName, student_data[Result[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n", *student_data[Result[1]].studentId, student_data[Result[1]].fullName, student_data[Result[1]].grade);

  char key1[] = "DENIZ_UGUR";
  int Result1[15];
  int result1 = secondaryKeySearchForName(student_data, 273, Result1, key1);
  printf("'DENIZ_UGUR' araması için bulunan sonuç sayısı: %d\n", result1);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n", *student_data[Result1[0]].studentId, student_data[Result1[0]].fullName, student_data[Result1[0]].grade);
  
  int Result2[15];
  int result2 = secondaryKeySearchForGrade(student_data, 273, Result2, "100");
  printf("Notu '100' olan öğrenci araması için sonuç sayısı: %d\n", result2);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result2[0]].studentId, student_data[Result2[0]].fullName, student_data[Result2[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n", *student_data[Result2[1]].studentId, student_data[Result2[1]].fullName, student_data[Result2[1]].grade);

  int Result3[15];
  int result3 = secondaryKeySearchForGrade(student_data, 273, Result3, "73");
  printf("Notu '73' olan öğrenci araması için sonuç sayısı: %d\n", result3);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result3[0]].studentId, student_data[Result3[0]].fullName, student_data[Result3[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n", *student_data[Result3[1]].studentId, student_data[Result3[1]].fullName, student_data[Result3[1]].grade);
  
  int Result4[15];
  int result4 = secondaryKeySearchForGrade(student_data, 273, Result4, "0");
  printf("Notu '0' olan öğrenci araması için sonuç sayısı: %d\n", result4);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result4[0]].studentId, student_data[Result4[0]].fullName, student_data[Result4[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result4[1]].studentId, student_data[Result4[1]].fullName, student_data[Result4[1]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n\n", *student_data[Result4[2]].studentId, student_data[Result4[2]].fullName, student_data[Result4[2]].grade);

  // BINARY SEARCH IN STRUCT WITH SECONDARY KEY
  SortForStructChar(student_data, 273);
  printf("*****************************BINARY SEARCH IN STRUCT WITH SECONDARY KEY*****************************\n\n");
  int Result6[15];
  int result6 = binarySearchWithSecondaryKey(student_data, 273, Result6, "DENIZ_UGUR");
  printf("'DENIZ_UGUR' araması için bulunan sonuç sayısı: %d\n", result6);
  printf("\tStudent Id: %d, Name: %s, Grade: %s\n\n", *student_data[Result6[0]].studentId, student_data[Result6[0]].fullName, student_data[Result6[0]].grade);

  int Result5[15];
  int result5 = binarySearchWithSecondaryKey(student_data, 273, Result5, "MEHMET_IPEK");
  printf("'MEHMET_IPEK' araması için bulunan sonuç sayısı: %d\n", result5);
  printf("\tStudent Id: %d, Name: %s, Grade: %s\n", *student_data[Result5[0]].studentId, student_data[Result5[0]].fullName, student_data[Result5[0]].grade);
  printf("\tStudent Id: %d, Name: %s, Grade: %s\n\n", *student_data[Result5[1]].studentId, student_data[Result5[1]].fullName, student_data[Result5[1]].grade);
  
  SortForStructCharForGrade(student_data,273);
  int Result7[15];
  int result7 = binarySearchWithSecondaryKeyForGrade(student_data, 273, Result7, "73");
  printf("Notu '73' olan öğrenci araması için sonuç sayısı: %d\n", result7);
  printf("\tStudent Id: %d, Name: %s, Grade: %s\n", *student_data[Result7[0]].studentId, student_data[Result7[0]].fullName, student_data[Result7[0]].grade);
  printf("\tStudent Id: %d, Name: %s, Grade: %s\n\n", *student_data[Result7[1]].studentId, student_data[Result7[1]].fullName, student_data[Result7[1]].grade);

  int Result8[15];
  int result8 = binarySearchWithSecondaryKeyForGrade(student_data, 273, Result8, "100");
  printf("Notu '100' olan öğrenci araması için sonuç sayısı: %d\n", result8);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result8[0]].studentId, student_data[Result8[0]].fullName, student_data[Result8[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n\n", *student_data[Result8[1]].studentId, student_data[Result8[1]].fullName, student_data[Result8[1]].grade);

  int Result9[15];
  int result9 = binarySearchWithSecondaryKeyForGrade(student_data, 273, Result9, "0");
  printf("Notu '0' olan öğrenci araması için sonuç sayısı: %d\n", result9);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result9[0]].studentId, student_data[Result9[0]].fullName, student_data[Result9[0]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result9[1]].studentId, student_data[Result9[1]].fullName, student_data[Result9[1]].grade);
  printf("\tStudent Id: %d\t Name: %s\t Grade: %s\t\n", *student_data[Result9[2]].studentId, student_data[Result9[2]].fullName, student_data[Result9[2]].grade);
}

int main(void) {
  searchInArrays();
  searchInStructWithPrimaryKey();
  searchInStructWithSecondaryKey();
  return 0;
}
