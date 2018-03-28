#include <stdio.h>  //for printf and scanf
#include <stdlib.h> //for malloc

#define LOW 0
#define HIGH 199
#define START 53

//compare function for qsort
//you might have to sort the request array
//use the qsort function 
// an argument to qsort function is a function that compares 2 quantities
//use this there.
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
//added Method that sorts
int * sort(int *arr){
  int i,j,temp1, temp2;
  
  int *ptr;
  int len = sizeof(arr);
  for(i=0; i<len; i++){
      for(j=0; j<len-1;j++){
          if(*(arr+j)>*(arr+j+1)){
            ptr=arr+j;
            temp1 =*ptr++;
            temp2 =*ptr;
            *ptr--=temp1;
            *ptr=temp2;
          }
      }
  } 
  for(i=0;i<len;i++)
    printf(" %d ",arr[i]);
  return arr;
}
//added print
/*void print(int *request, int numRequest){
    for (int i = 0; i < numRequest; i++)
    {
        printf(" -> %d", request[i]);
    }
}*/
//function to swap 2 integers
void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a = (*a ^ *b);
        *b = (*a ^ *b);
        *a = (*a ^ *b);
        return;
    }
}

//Prints the sequence and the performance metric
void printSeqNPerformance(int *request, int numRequest)
{
    int i, last, acc = 0;
    last = START;
    printf("\n");
    printf("%d", START);
    for (i = 0; i < numRequest; i++)
    {
        printf(" -> %d", request[i]);
        acc += abs(last - request[i]);
        last = request[i];
    }
    printf("\nPerformance : %d\n", acc);
    return;
}

//access the disk location in FCFS
void accessFCFS(int *request, int numRequest)
{
    //simplest part of assignment
    printf("\n----------------\n");
    printf("FCFS :");
    printSeqNPerformance(request, numRequest);
    printf("----------------\n");
    return;
}

//access the disk location in SSTF
void accessSSTF(int *request, int numRequest)
{
    //write your logic here
    printf("\n----------------\n");
    printf("SSTF :");
    printSeqNPerformance(request, numRequest);
    printf("----------------\n");
    return;
}

//access the disk location in SCAN
void accessSCAN(int *request, int numRequest)
{
    int *bigger;
    int *smaller;
    int head = START;
	//write your logic here
    printf("\n----------------\n");
    printf("SCAN :");
    for(int i=0; i<sizeof(request); i++){
        if((*(request+i))<head){ //start on the left side
            *(smaller+i)=*(request+i);
        }else{
            *(bigger+i)=*(request+i);
        }
    }
    int *p1,*p2;
    p1=sort(bigger);
    int newCnt1=sizeof(p1);
    //printSeqNPerformance(newRequest, newCnt);
    printf("----------------\n");
    return;
}

//access the disk location in CSCAN
void accessCSCAN(int *request, int numRequest)
{
    int *bigger;
    int *smaller;
    int head = START;
    //write your logic here
    printf("\n----------------\n");
    printf("CSCAN :");
    for(int i=0; i<sizeof(request); i++){
        if((*(request+i))>head){
            *(bigger+i)=*(request+i);
        }else{
            *(smaller+i)=*(request+i);
        }
    }
    int *p1,*p2;
    p1=sort(bigger);
    int newCnt1=sizeof(p1);
    //p2=sort(smaller);
    //int newCnt2=sizeof(p2);
    printSeqNPerformance(p1, newCnt1);
    //printSeqNPerformance(p2, newCnt2);

    printf("----------------\n");
    return;
}

//access the disk location in LOOK
void accessLOOK(int *request, int numRequest)
{
    //write your logic here
    printf("\n----------------\n");
    printf("LOOK :");
    //printSeqNPerformance(newRequest, newCnt);
    printf("----------------\n");
    return;
}

//access the disk location in CLOOK
void accessCLOOK(int *request, int numRequest)
{
    //write your logic here
    printf("\n----------------\n");
    printf("CLOOK :");
    //printSeqNPerformance(newRequest,newCnt);
    printf("----------------\n");
    return;
}

int main()
{
    int *request, numRequest, i,ans;

    //allocate memory to store requests
    printf("Enter the number of disk access requests : ");
    scanf("%d", &numRequest);
    request = malloc(numRequest * sizeof(int));

    printf("Enter the requests ranging between %d and %d\n", LOW, HIGH);
    for (i = 0; i < numRequest; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("\nSelect the policy : \n");
    printf("----------------\n");
    printf("1\t FCFS\n");
    printf("2\t SSTF\n");
    printf("3\t SCAN\n");
    printf("4\t CSCAN\n");
    printf("5\t LOOK\n");
    printf("6\t CLOOK\n");
    printf("----------------\n");
    scanf("%d",&ans);

    switch (ans)
    {
    //access the disk location in FCFS
    case 1: accessFCFS(request, numRequest);
        break;

    //access the disk location in SSTF
    case 2: accessSSTF(request, numRequest);
        break;

        //access the disk location in SCAN
     case 3: accessSCAN(request, numRequest);
        break;

        //access the disk location in CSCAN
    case 4: accessCSCAN(request,numRequest);
        break;

    //access the disk location in LOOK
    case 5: accessLOOK(request,numRequest);
        break;

    //access the disk location in CLOOK
    case 6: accessCLOOK(request,numRequest);
        break;

    default:
        break;
    }
    return 0;
}
