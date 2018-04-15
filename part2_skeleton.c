#include <stdio.h>  //for printf and scanf
#include <stdlib.h> //for malloc
#include <stdbool.h>

#define LOW 0
#define HIGH 199
#define START 53

//compare function for qsort
//you might have to sort the request array
//use the qsort function
// an argument to qsort function is a function that compares 2 quantities
//use this there.
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
//added Method that sorts
int *sortAscedingOrder(int *arr, int len)
{
    int i, j, temp1, temp2;
    int *ptr;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                ptr = arr + j;
                temp1 = *ptr++;
                temp2 = *ptr;
                *ptr-- = temp1;
                *ptr = temp2;
            }
        }
    }
    return arr;
}

int *sortDescendingOrder(int *arr, int len)
{
    int i, j, temp1, temp2;
    int *ptr;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1; j++)
        {
            if (*(arr + j) < *(arr + j + 1))
            {
                ptr = arr + j;
                temp1 = *ptr++;
                temp2 = *ptr;
                *ptr-- = temp1;
                *ptr = temp2;
            }
        }
    }
    return arr;
}
//A method that appends
int *append(int *arr1, int n1, int *arr2, int n2)
{
    //int n1 = sizeof(arr1);
    //int n2 = sizeof(arr2);
    int *res;
    res = malloc((n1 + n2) * sizeof(int));
    int len = n1 + n2;
    int i = 0, j = 0, k = 0;
    while (k < len)
    {
        if (i < n1)
        {
            res[k] = arr1[i];
            i++;
        }
        else if (j < n2)
        {
            res[k] = arr2[j];
            j++;
        }
        else
        {
            int nothing = 0;
        }
        k++;
    }
    return res;
}
//a Method that checks the difference with each
int nearestService(int *req, int len, int begin)
{
    int *diff;
    int min = abs(begin - *(req + 0));
    int res = *(req + 0);
    diff = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        *(diff + i) = abs(begin - *(req + i));

        if ((min > *(diff + i)))
        {
            min = *(diff + i);
            res = *(req + i);
        }
    }
    /*int ans[2];
    ans[0]=min;
    ans[1]=res;
    return ans;*/
    return res;
}

bool isvalueinarray(int *arr, int val)
{
    int size = sizeof(arr);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return true;
    }
    return false;
}

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

//removing an element in an array
int *removeAnElment(int *request, int numRequest, int element)
{
    int *req;
    req = malloc((numRequest - 1) * sizeof(int));
    int i = 0;
    int indexOfReq =0;
    while (i < numRequest)
    {
        if (request[i] != element)
        {
            req[indexOfReq] = request[i];
            indexOfReq++;
        }
        i++;
    }
    return req;
}

//duplicate an array
int *populate(int *request, int numRequest)
{
    int *req;
    req = malloc((numRequest) * sizeof(int));
    int i = 0;
    while (i < numRequest)
    {
        req[i] = request[i];
        i++;
    }
    return req;
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
/*void accessSSTF(int *request, int numRequest)
{
    int *req, *ans, two;
    int num = numRequest;
    ans = malloc((numRequest) * sizeof(int));
    req = malloc((numRequest) * sizeof(int));
    two = malloc((2) * sizeof(int));
    for(int p=0; p<2; p++){
        res =(*(two+));
        min = (*(two+2));; 
    }
    int i = 0, j = 0, k = 0, begin = START, len;

    req = populate(request, numRequest);
    while (i < (numRequest))
    {
        len = num;
        res =(*(two+1));
        min = (*(two+2));;
    }
}*/

//access the disk location in SSTF
void accessSSTF(int *request, int numRequest)
{
    int *req,*ans;
    int num=numRequest;
    ans = malloc((numRequest) * sizeof(int)); 
    req = malloc((numRequest) * sizeof(int)); 
    int res = 0, i=0, j=0,k=0, begin = START, len;

    req = populate(request,numRequest);
   
    while(i<(numRequest)){
        len = num;
        res = nearestService(req,len, begin);
        (*(ans + i)) = res;
        //begin info
        begin = res;

        req = removeAnElment(req, num, begin);
        num--;

        i++;
    }
    printSeqNPerformance(ans, (numRequest));
    return;
    
}

//access the disk location in SCAN
void accessSCAN(int *request, int numRequest)
{
    int head = START;
    int bg = 0, sm = 0;
    //loop to get the size of (bigger than head) requests and (smaller than head)
    for (int i = 0; i < numRequest; i++)
    {
        if ((*(request + i)) > head)
        {
            bg++;
        }
        else
        {
            sm++;
        }
    }
    int *bigger;
    bigger = malloc((bg + 1) * sizeof(int));
    int *smaller;
    smaller = malloc((sm + 1) * sizeof(int));
    printf("\n----------------\n");
    printf("SCAN :");
    int k = 0, l = 0, i = 0;
    while (i <= numRequest)
    {
        if (i < numRequest)
        {
            if ((*(request + i)) > head)
            {
                *(bigger + k) = *(request + i);
                k++;
            }
            else
            {
                *(smaller + l) = *(request + i);
                l++;
            }
        }
        else
        {
            *(bigger + k) = HIGH;
            *(smaller + l) = LOW;
        }
        i++;
    }
    int *p1, *p2, *ans;

    // p1 = malloc(sizeof(bg+1));
    // p2 = malloc(sizeof(sm+1));
    p1 = malloc((bg + 1) * sizeof(int));

    p2 = malloc((sm + 1) * sizeof(int));
    //printf("\nsize of p1, %d",newCnt1);

    ans = malloc((numRequest + 2) * sizeof(int)); //answer is a bit bigger
                                                  // int near = nearestService(request);

    int nearBig = HIGH - START;
    int nearSmall = START - LOW;

    if (nearSmall < nearBig)
    {
        p2 = sortDescendingOrder(smaller, (sm + 1));
        p1 = sortAscedingOrder(bigger, (bg + 1));
        ans = append(p2, (sm + 1), p1, (bg + 1));
    }
    else
    {
        p2 = sortAscedingOrder(smaller, (sm + 1));
        p1 = sortDescendingOrder(bigger, (bg + 1));
        ans = append(p1, (bg + 1), p2, (sm + 1));
    }
    printSeqNPerformance(ans, (numRequest + 2));
    printf("----------------\n");
    return;
}
//access the disk location in CSCAN
void accessCSCAN(int *request, int numRequest)
{
    int head = START;
    int bg = 0, sm = 0;
    //loop to get the size of (bigger than head) requests and (smaller than head)
    for (int i = 0; i < numRequest; i++)
    {
        if ((*(request + i)) > head)
        {
            bg++;
        }
        else
        {
            sm++;
        }
    }
    //write your logic here
    int *bigger;
    bigger = malloc((bg + 1) * sizeof(int));
    int *smaller;
    smaller = malloc((sm + 1) * sizeof(int));
    printf("\n----------------\n");
    printf("CSCAN :");
    int k = 0, l = 0, i = 0;
    while (i <= numRequest)
    {
        if (i < numRequest)
        {
            if ((*(request + i)) > head)
            {
                *(bigger + k) = *(request + i);
                k++;
            }
            else
            {
                *(smaller + l) = *(request + i);
                l++;
            }
        }
        else
        {
            *(bigger + k) = HIGH;
            *(smaller + l) = LOW;
        }
        i++;
    }
    int *p1, *p2, *ans;
    p1 = malloc((bg + 1) * sizeof(int));
    p2 = malloc((sm + 1) * sizeof(int));

    ans = malloc((numRequest + 2) * sizeof(int)); //answer is a bit bigger
                                                  // int near = nearestService(request);
    int nearBig = HIGH - START;
    int nearSmall = START - LOW;

    if (nearBig < nearSmall)
    {
        p1 = sortAscedingOrder(bigger, (bg + 1));
        p2 = sortAscedingOrder(smaller, (sm + 1));
        ans = append(p1, (bg + 1), p2, (sm + 1));
    }
    else
    {
        p1 = sortDescendingOrder(bigger, (bg + 1));
        p2 = sortDescendingOrder(smaller, (sm + 1));
        ans = append(p2, (sm + 1), p1, (bg + 1));
    }
    printSeqNPerformance(ans, (numRequest + 2));
    printf("----------------\n");
    return;
}

//access the disk location in LOOK
void accessLOOK(int *request, int numRequest)
{
    int head = START;
    int bg = 0, sm = 0;
    //loop to get the size of (bigger than head) requests and (smaller than head)
    for (int i = 0; i < numRequest; i++)
    {
        if ((*(request + i)) > head)
        {
            bg++;
        }
        else
        {
            sm++;
        }
    }
    int *bigger;
    bigger = malloc(bg * sizeof(int));
    int *smaller;
    smaller = malloc(sm * sizeof(int));
    printf("\n----------------\n");
    printf("LOOK :");
    int k = 0, l = 0, i = 0;
    while (i <= numRequest)
    {
        if (i < numRequest)
        {
            if ((*(request + i)) > head)
            {
                *(bigger + k) = *(request + i);
                k++;
            }
            else
            {
                *(smaller + l) = *(request + i);
                l++;
            }
        }
        else
        {
            *(bigger + k) = HIGH;
            *(smaller + l) = LOW;
        }
        i++;
    }
    int *p1, *p2, *ans;
    p1 = malloc(bg * sizeof(int));
    p2 = malloc(sm * sizeof(int));

    ans = malloc(numRequest * sizeof(int)); //answer is a bit bigger
                                            // int near = nearestService(request);

    int nearBig = HIGH - START;
    int nearSmall = START - LOW;

    if (nearSmall < nearBig)
    {
        p2 = sortDescendingOrder(smaller, sm);
        p1 = sortAscedingOrder(bigger, bg);
        ans = append(p2, sm, p1, bg);
    }
    else
    {
        p2 = sortAscedingOrder(smaller, sm);
        p1 = sortDescendingOrder(bigger, bg);
        ans = append(p1, bg, p2, sm);
    }
    printSeqNPerformance(ans, numRequest);
    printf("----------------\n");
    return;
}
//access the disk location in CLOOK
void accessCLOOK(int *request, int numRequest)
{
    int head = START;
    int bg = 0, sm = 0;
    //loop to get the size of (bigger than head) requests and (smaller than head)
    for (int i = 0; i < numRequest; i++)
    {
        if ((*(request + i)) > head)
        {
            bg++;
        }
        else
        {
            sm++;
        }
    }
    //write your logic here
    int *bigger;
    bigger = malloc((bg) * sizeof(int));
    int *smaller;
    smaller = malloc((sm) * sizeof(int));
    printf("\n----------------\n");
    printf("CLOOK :");
    int k = 0, l = 0, i = 0;
    while (i <= numRequest)
    {
        if (i < numRequest)
        {
            if ((*(request + i)) > head)
            {
                *(bigger + k) = *(request + i);
                k++;
            }
            else
            {
                *(smaller + l) = *(request + i);
                l++;
            }
        }
        i++;
    }
    int *p1, *p2, *ans;
    p1 = malloc(bg * sizeof(int));
    p2 = malloc(sm * sizeof(int));
    ans = malloc((numRequest) * sizeof(int)); //answer is a bit bigger

    int nearBig = HIGH - START;
    int nearSmall = START - LOW;

    if (nearBig < nearSmall)
    {
        p1 = sortAscedingOrder(bigger, bg);
        p2 = sortAscedingOrder(smaller, sm);
        ans = append(p1, bg, p2, sm);
    }
    else
    {
        p1 = sortDescendingOrder(bigger, bg);
        p2 = sortDescendingOrder(smaller, sm);
        ans = append(p2, sm, p1, bg);
    }
    printSeqNPerformance(ans, numRequest);
    printf("----------------\n");
    return;
}

int main()
{
    int *request, numRequest, i, ans;

    //allocate memory to store requests
    request = malloc(numRequest * sizeof(int));
    //added
    numRequest = 8;

    request[0] = 98;
    request[1] = 183;
    request[2] = 37;
    request[3] = 122;
    request[4] = 14;
    request[5] = 124;
    request[6] = 65;
    request[7] = 67;

    printf("\nSelect the policy : \n");
    printf("----------------\n");
    printf("1\t FCFS\n");
    printf("2\t SSTF\n");
    printf("3\t SCAN\n");
    printf("4\t CSCAN\n");
    printf("5\t LOOK\n");
    printf("6\t CLOOK\n");
    printf("----------------\n");
    scanf("%d", &ans);

    switch (ans)
    {
    //access the disk location in FCFS
    case 1:
        accessFCFS(request, numRequest);
        break;

    //access the disk location in SSTF
    case 2:
        accessSSTF(request, numRequest);
        break;

        //access the disk location in SCAN
    case 3:
        accessSCAN(request, numRequest);
        break;

        //access the disk location in CSCAN
    case 4:
        accessCSCAN(request, numRequest);
        break;

    //access the disk location in LOOK
    case 5:
        accessLOOK(request, numRequest);
        break;

    //access the disk location in CLOOK
    case 6:
        accessCLOOK(request, numRequest);
        break;

    default:
        break;
    }
    return 0;
}
