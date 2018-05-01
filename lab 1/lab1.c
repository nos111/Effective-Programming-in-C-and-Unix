
#include <stdio.h>
#include <time.h>
void readWrite(char * inputfile, char * outputfile, int time) {
  FILE * fp = fopen(inputfile, "r");
  FILE * outputFP = fopen(outputfile, "w");
  if(fp == NULL || outputFP == NULL) {
    printf("There was an error reading from source file");
  }
  char buff[10000][32];
  int temp = 0;
  for(size_t i = 0; ;i++){
    temp = fscanf(fp,"%s", buff[i]);
    //printf(" %d ", temp);
    fprintf(outputFP, "%s", buff[i]);
    fprintf(outputFP,"\n");
    if(temp <= 0) return;
  }
  fclose(fp);
  fclose(outputFP);

  
  /*
  int i = 0;
  while(fscanf(fp,"%s", buff) > 0 ) {
    i++;
  }
  printf("the words total is %u \n",i);
  */
  
};
void readSortWrite();

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
      printf("got here");
      //clock_t start, end;
      //start = clock(); 
      readWrite(inputFile, outputFile, 0);
      //end = clock();
      //int cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
      //printf("The time in seconds is %d", cpu_time_used);

      break;
    case 4: 
      inputFile = argv[1];
      outputFile = argv[2];
      mode1 = argv[3];
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

}