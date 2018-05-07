
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void readWrite(char * inputfile, char * outputfile, int time) {
  clock_t start, end;
  if(time) {
    start = clock(); 
  }
  int wordCount = 0;
  int cellsNum = 500000;
  FILE * fp = fopen(inputfile, "r");
  FILE * outputFP = fopen(outputfile, "w");
  if(fp == NULL || outputFP == NULL) {
    printf("There was an error reading from source file");
  }
  char ** buff= (char**)malloc(sizeof(char*)* cellsNum);
  int temp = 0;
  for(size_t i = 0;i < cellsNum ;i++){
    wordCount++;
    buff[i] = (char*)malloc(100);
    temp = fscanf(fp,"%s", buff[i]);
    if(temp <= 0) {
      free(buff[i]);
      break;
    }
    fprintf(outputFP, "%s \n", buff[i]);
    free(buff[i]);
  }
  printf("the words total is %u \n",wordCount);
  fclose(fp);
  fclose(outputFP);
  free(buff);
  if(time) {
    end = clock();
    int cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time in seconds is %d", cpu_time_used);
  }
  return;
};

int findInsertLocation(char ** wordsArray, char * wordToInsert, int arrLenght){
  for(size_t i = 0; i < arrLenght; i++) {
    if(strcmp(wordToInsert, wordsArray[i]) <= 0) return i;
  }
  return 0;
};

void copyArrayItems(char ** wordsArray, int startLocation, int arrUsedSpace) {
  char * temp = wordsArray[startLocation];
  char * temp2;
  for(size_t i = arrUsedSpace; i > startLocation; i--) {
   wordsArray[i] = wordsArray[i - 1];
  }
};

void readSortWrite(char * inputfile, char * outputfile, int time) {
  clock_t start, end;
  if(time) {
    start = clock(); 
  }
  int wordCount = 0;
  int cellsNum = 500000;
  FILE * fp = fopen(inputfile, "r");
  FILE * outputFP = fopen(outputfile, "w");
  if(fp == NULL || outputFP == NULL) {
    printf("There was an error reading from source file");
  }
  char ** buff = (char**)malloc(sizeof(char*)* cellsNum);
  int temp = 0;
  for(size_t i = 0;i < cellsNum ;i++){
    wordCount++;
    buff[i] = (char*)malloc(sizeof(char*));
    char * tempWord = (char*) malloc(100);
    //read a word
    temp = fscanf(fp,"%s", tempWord);
    if(temp <= 0) {
      break;
    }
    //find insert location
    int insertLocation = findInsertLocation(buff, tempWord, wordCount);
    //copy the array
    copyArrayItems(buff, insertLocation, wordCount);
    //insert
    buff[insertLocation] = tempWord;
    
  }
  //write to the file when done
  for(size_t i = 0; i < wordCount; i++) {
    fprintf(outputFP, "%s \n", buff[i]);
    free(buff[i]);
  }  
  printf("the words total is %u \n",wordCount);
  fclose(fp);
  fclose(outputFP);
  free(buff);
  if(time) {
    end = clock();
    int cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time in seconds is %d", cpu_time_used);
  }
  return;
};

int main(int argc, char * argv[]) {
  char * inputFile, * outputFile, * mode1, * mode2;
  switch(argc) {
    case 1:
    case 2:
      printf("Insufficent arguments");
      return 0;
    case 3: 
      inputFile = argv[1];
      outputFile = argv[2];
      readWrite(inputFile, outputFile, 0);
      break;
    case 4: 
      inputFile = argv[2];
      outputFile = argv[3];
      mode1 = argv[1];

      if (strcmp(mode1, "-s") == 0) {
        readSortWrite(inputFile, outputFile, 1);
      } else if (strcmp(mode1, "-t") == 0) {
        readWrite(inputFile, outputFile, 1);
      } else {
        printf("Unknown mode \n");
      }
      break;
    case 5: 
      inputFile = argv[1];
      outputFile = argv[2];
      mode1 = argv[3];
      mode2 = argv[4];
      break;
    default:
      printf("Arguments error; <mode> <mode> <inputfile> <outputfile> \n");
  }
  return 0;

}