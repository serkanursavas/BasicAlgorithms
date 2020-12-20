#include <stdio.h>
#include <string.h>

typedef struct
  {   int studentId[15];
      char fullName[30];
      char grade[5];
  }STUDENT;

	// HASH FUNCTION
	int hashFunction(int number, int TABLE_SIZE){
		number = (number % TABLE_SIZE) + (3 - (number % 3));
		return number % TABLE_SIZE;
	}
	
	int hashFunction2(int number, int TABLE_SIZE){
		number = (number%1000);
		number = number*number;
		return number % TABLE_SIZE;
	}

	int hashFunction3(int number, int TABLE_SIZE){
		number = number%10000;
		number = number*(number+5);
		return number % TABLE_SIZE;
	}

	int hashFunction4(int number, int TABLE_SIZE){
		int val;
		val = (number%100000000)-(number%1000000);
		number = val * (number%100);
		return number % TABLE_SIZE;
	}

	int hashFunction5(int number, int TABLE_SIZE){
		return number % TABLE_SIZE;
	}
	
int main(void) {

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
	
	// CREATING HASH TABLE
		int TABLE_SIZE; 														//	DEĞİŞKEN DIŞARDAN ALINACAK
		printf("\nEnter Table Size: ");
		scanf("%d", &TABLE_SIZE);
		STUDENT hashTable[TABLE_SIZE];
		for(int i = 0; i < TABLE_SIZE; i++){
			*hashTable[i].studentId = 0;
			strcpy(hashTable[i].fullName, "-");
			strcpy(hashTable[i].grade, "-");
		}
	
	// MENU
	int choice, hashPosition, studentNumber, hashNumarasi;
	char *name, *grade, *resolutionName, *hashName;
	int totalCounter = 0;
	int resolutionModelCounter = 0;

	char *bestHashName, *bestResolutionName;
	int bestTotalCounter = 0;
	int bestResolutionCounter = 0; 
	int bestTableSize = 0;

  do{	
			// PROCESS SELECTION
			printf( "\n1 - Display Hash Table"
							"\n2 - Insert Elements"
							"\n3 - Clear Hash Table"
							"\n4 - Show Best Function"
							"\n  - Any Key For Exit\n"
							"\nEnter Your Choice: ");
							scanf("%d", &choice);
							printf("\n\n");
							switch(choice){
								case 1:
										for(int i = 0; i < TABLE_SIZE; i++){
											if(*hashTable[i].studentId == 0){
												printf("Hash Table [%d] is empty\n", i);
											}
											else{
											printf("%d\t %s \t %s\n", *hashTable[i].studentId, hashTable[i].fullName, hashTable[i].grade);
											}
										}
										printf("\n*******************************Hash Table displayed.*******************************\n");
										break;
								case 2:
										// CHOOSING HASH FUNCTIONS
										printf( "1 - Hash Function1"
														"\n2 - Hash Function2"
														"\n3 - Hash Function3"
														"\n4 - Hash Function4"
														"\n5 - Hash Function5\n"
														"\nEnter Your Choice: ");
										scanf("%d", &hashNumarasi);

										// CHOOSING RESOLUTION MODEL
										int resolutionModelNo;
											printf( "\n\n"
															"1 - Linear Probing\n"
															"2 - Quadratic Probing\n\n"
															"Choose your resolution model: ");
											scanf("%d", &resolutionModelNo);

										// READ DATAS FROM STRUCT AND INSERTING HASH TABLE
										totalCounter += 273;
										for(int i = 0; i < 273; i++){
											studentNumber =*student_data[i].studentId;
											totalCounter++;
											name = student_data[i].fullName;
											totalCounter++;
											grade= student_data[i].grade;
											totalCounter++;
										
											totalCounter++;
											if(hashNumarasi == 1){
												hashPosition = hashFunction(studentNumber, TABLE_SIZE);
												totalCounter++;
												hashName = "FIRST HASH FUNCTION";
											}
											totalCounter++;
											if(hashNumarasi == 2){
												hashPosition = hashFunction2(studentNumber, TABLE_SIZE);
												totalCounter++;
												hashName = "SECOND  HASH FUNCTION";
											}
											totalCounter++;
											if(hashNumarasi == 3){
												hashPosition = hashFunction3(studentNumber, TABLE_SIZE);
												totalCounter++;
												hashName = "3rd HASH FUNCTION";
											}
											totalCounter++;
											if(hashNumarasi == 4){
												hashPosition = hashFunction4(studentNumber, TABLE_SIZE);
												totalCounter++;
												hashName = "4th HASH FUNCTION";
											}
											totalCounter++;
											if(hashNumarasi == 5){
												hashPosition = hashFunction5(studentNumber, TABLE_SIZE);
												totalCounter++;
												hashName = "5th HASH FUNCTION";
											}
										
											totalCounter++;
											if(*hashTable[hashPosition].studentId == 0){
												*hashTable[hashPosition].studentId = studentNumber;
												totalCounter++;
												strcpy(hashTable[hashPosition].fullName, name);
												totalCounter++;
												strcpy(hashTable[hashPosition].grade, grade);
												totalCounter++;
											}
											else{
												int counter = 1;
												totalCounter++;
												totalCounter++;
												resolutionModelCounter++;
												resolutionModelCounter++;
												if(resolutionModelNo == 1){
													resolutionName = "LINEAR PROBING";
													while(counter < TABLE_SIZE){
														hashPosition++;
														totalCounter++;
														resolutionModelCounter++;
														hashPosition %= TABLE_SIZE;
														totalCounter++;
														totalCounter++;
														resolutionModelCounter++;
														resolutionModelCounter++;
														if(*hashTable[hashPosition].studentId == 0){
															*hashTable[hashPosition].studentId = studentNumber;
															totalCounter++;
															resolutionModelCounter++;
															strcpy(hashTable[hashPosition].fullName, name);
															totalCounter++;
															resolutionModelCounter++;
															strcpy(hashTable[hashPosition].grade, grade);
															totalCounter++;
															resolutionModelCounter++;
															break;
														}
														counter++;
														totalCounter++;
														resolutionModelCounter++;
													}											
												}
												totalCounter++;
												resolutionModelCounter++;
												if(resolutionModelNo == 2){
													resolutionName = "QUADRATIC PROBING";
													int newHashPostion;
													totalCounter++;
													resolutionModelCounter++;
													while(counter < TABLE_SIZE){
														newHashPostion = hashPosition + counter * counter;
														totalCounter++;
														resolutionModelCounter++;
														newHashPostion %= TABLE_SIZE;
														totalCounter++;
														totalCounter++;
														resolutionModelCounter++;
														resolutionModelCounter++;
														if(*hashTable[newHashPostion].studentId == 0){
															*hashTable[newHashPostion].studentId = studentNumber;
															totalCounter++;
															resolutionModelCounter++;
															strcpy(hashTable[newHashPostion].fullName, name);
															totalCounter++;
															resolutionModelCounter++;
															strcpy(hashTable[newHashPostion].grade, grade);
															totalCounter++;
															resolutionModelCounter++;
															break;
														}
														counter++;
														totalCounter++;
														resolutionModelCounter++;
													}
												}
												totalCounter++;
												if(counter >= TABLE_SIZE){
													printf("There isn't any empty slots\n");
												}
											}
										}
										printf("\n***************************************\n\n");
										printf("TABLE SIZE: %d\n", TABLE_SIZE);
										printf("PROBING MODEL: %s\n", resolutionName);
										printf("NUMBER OF OPERATIONS PERFORMED: %d\n", totalCounter);
										printf("NUMBER OF ANALSYS TECNIQUE OP. PERF.: %d\n", resolutionModelCounter);
										
										printf("\n***************************************\n");

										if((totalCounter < bestTotalCounter || bestTotalCounter == 0)){
											bestHashName = hashName;
											bestResolutionName = resolutionName;
											bestTableSize = TABLE_SIZE;
											bestTotalCounter = totalCounter;
											bestResolutionCounter = resolutionModelCounter;
										}
										printf("\n*******************Data added to the table*******************\n");
										break;
								case 3:
										for(int i = 0; i < TABLE_SIZE; i++){
											*hashTable[i].studentId = 0;
											strcpy(hashTable[i].fullName, "-");
											strcpy(hashTable[i].grade, "-");
										}
										totalCounter = 0;
										resolutionModelCounter = 0;
										printf("*******************************The Hash Table has been cleared.*******************************.\n");
										break;
								case 4:
										printf("***************According To Table Size and Analysis Technique***************\n\n");
										printf(" ->  The -%s- performs better than any other.\n ->  It has the fewest number of transactions, with -%d- transactions on -%d- table size.\n ->  Also, -%d- transactions show the best results with the analysis technique with -%s-.\n\n\n",bestHashName, bestTotalCounter, bestTableSize, bestResolutionCounter, bestResolutionName );
										printf("******************************");
										break;
								default:
										return 0;
							}
	}while(1);
}
