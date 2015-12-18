#include <stdio.h>
#include <stdlib.h>



int main() {
  //  long max=6000000;
    //srand(max);
  long n,i;
  FILE *fp;
  fp=fopen("4Mlong.txt","w");
  for (i = 1;i <= 4000000; i++)
  {
    n = ((rand() %300  + 1)*(rand() %40000  + 1));
    fprintf(fp,"%10ld \t",n);
  }
    fclose(fp);
    fp=fopen("4Mlong.txt","r");
  for(i=0;i<100;i++)
  {

      fscanf(fp,"%10ld",&n);
      printf("%10ld\t",n);
  }
    fclose(fp);
  return 0;
}
