#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 40000

int i,j;
int a[size];
int e[size];
clock_t start, end;
double cpu_time_used;

void input();
void output();
void sel_sort();
void ins_sort();
void lsearch();
void Mergesort(int *,int);
void Merge(int *,int *,int *,int,int );
int bisearch(int *,int,int,int,int);
void bubble();
void quicksort(int *,int ,int);
int partition(int *,int ,int);
void shellsort(int [],int);

int main()
{
    int ch;
    while(1)
    {
        printf("\n\t<--CHOOSE OPERATION TO PERFORM -->\n");
        printf("\n\t1.Input Array From File");
        printf("\n\t2.View the current state of the array");
        printf("\n\t3.Sort Array Using Bubble Sort");
        printf("\n\t4.Sort Array using Selection Sort");
        printf("\n\t5.Sort Array using Insertion Sort");
        printf("\n\t6.Sort Array using Merge Sort");
        printf("\n\t7.Sort Array using Shell Sort");
        printf("\n\t8.Sort Array using Quick Sort");
        printf("\n\t9.Exit");
        printf("\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:input();
                break;
            case 2:output();
                break;
            case 3:bubble();
                break;
            case 4:sel_sort();
                break;
            case 5:ins_sort();
                break;
            case 6:printf("\n");

                    for(i=0;i<size;i++)
                    {
                        e[i]=a[i];
                    }
                    start = clock();
                    Mergesort(e,size);
                    end =clock();
                    cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
                    for(i=0;i<size;i++)
                    {
                        printf("%d\t",e[i]);
                    }
                    printf("\n\t\t<---SORT SUCCESS--->\n");
                    printf("Time Taken = %d milliseconds",(int)(1000*cpu_time_used));

                break;
            case 7:printf("\n");

                    for(i=0;i<size;i++)
                    {
                        e[i]=a[i];
                    }
                    start = clock();
                    shellsort(e,size);
                    end =clock();
                    cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
                    for(i=0;i<size;i++)
                        printf("%d\t",e[i]);
                    printf("\n\t\t<---SORT SUCCESS--->\n");
                    printf("Time Taken = %d milliseconds",(int)(1000*cpu_time_used));

                break;
            case 8:
                    for(i=0;i<size;i++)
                    {
                        e[i]=a[i];
                    }
                    start = clock();
                    quicksort(e,0,size-1);
                    end =clock();
                    cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
                    for(i=0;i<size;i++)
                    {
                        printf("%d\t",e[i]);
                    }
                    printf("\n\t\t<---SORT SUCCESS--->\n");
                    printf("Time Taken = %d milliseconds",(int)(1000*cpu_time_used));
                break;
            case 9:exit(0);
                break;
        }
    }
return 0;
}


void input()
{
    FILE *fp;
    fp=fopen("40Kint.txt","r");
    for(i=0;i<size;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
    fclose(fp);
    printf("\n\t\t<---INPUT SUCESS--->\n");
}

void output()
{

    printf("\n Present state of the array is :");
    for(i=0;i<size;i++)
    {
        printf("%d \t",a[i]);
    }
}

void bubble()
{
    int d[size];
    int temp;
    for(i=0;i<size;i++)
    {
        d[i]=a[i];
    }
    start = clock();
     for(i=1;i<size;i++)
     {
        for(j=0;j<size-1;j++)
        {

                if(d[j]>d[j+1])
                {
                    temp=d[j];
                    d[j]=d[j+1];
                    d[j+1]=temp;
                }
        }
     }
     end =clock();
     cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
     for(i=0;i<size;i++)
    {
        printf("%d\t",d[i]);
    }
     printf("\n\t\t<---SORT SUCCESS--->\n");
     printf("Time Taken = %f seconds",cpu_time_used);

}

void sel_sort()
{
    int d[size];
    int temp;
    for(i=0;i<size;i++)
    {
        d[i]=a[i];
    }
    start = clock();
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(d[i]>d[j])
            {
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }
     end =clock();
     cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
                 for(i=0;i<size;i++)
    {
        printf("%d\t",d[i]);
    }

     printf("\n\t\t<---SORT SUCCESS--->\n");
     printf("Time Taken = %f seconds",cpu_time_used);
}

void ins_sort()
{
    int d[size];
    for(i=0;i<size;i++)
    {
        d[i]=a[i];
    }
    int temp;
    printf("the array after insertion sort is :");
    start = clock();
    for(i=1;i<size;i++)
    {
        j=i-1;
        temp=d[i];
        while(j>=0&&d[j]>temp)
        {
            d[j+1]=d[j];
            j--;
        }
        d[j+1]=temp;
    }
    end =clock();
     cpu_time_used = ((double) (end - start)/CLOCKS_PER_SEC);
            for(i=0;i<size;i++)
    {
        printf("%d\t",d[i]);
    }

     printf("\n\t\t<---SORT SUCCESS--->\n");
     printf("Time Taken = %f seconds",cpu_time_used);
}

void Mergesort(int *arr,int n)
{

    int k;
    if(n<2)
        return;
    int mid=n/2;
    int left[mid],right[n-mid];
    for(i=0;i<mid;i++)
        left[i]=arr[i];
    for(j=mid,k=0;j<n;j++,k++)
    right[k]=arr[j];
    Mergesort(left,mid);
    Mergesort(right,n-mid);
    Merge(left,right,arr,mid,n-mid);


}

void Merge(int *left,int *right, int *arr,int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];i++;
        }
        else
        {
            arr[k]=right[j];j++;
        }
        k++;
    }
    while(i<n)
    {
        arr[k]=left[i];i++,k++;
    }
    while(j<m)
    {
        arr[k]=right[j];j++;k++;
    }
}

void quicksort(int x[10],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

void shellsort(int b[],int n)
{
   int j,i,m,mid;
   for(m = n/2;m>0;m/=2)
   {
         for(j = m;j< n;j++)
         {
               for(i=j-m;i>=0;i-=m)
               {
                if(b[i+m]>=b[i])
                break;
                else
                {
                mid = b[i];
                b[i] = b[i+m];
                b[i+m] = mid;
                }
               }
          }
    }
}













