#include <stdio.h>


int * sort(int *arr){
  int i,j,temp1, temp2;
  
  int *ptr;
  for(i=0; i<4; i++){
      for(j=0; j<4-1;j++){
          if(*(arr+j)>*(arr+j+1)){
            ptr=arr+j;
            temp1 =*ptr++;
            temp2 =*ptr;
            *ptr--=temp1;
            *ptr=temp2;
          }
      }
  } 
  for(i=0;i<4;i++)
    printf(" %d ",arr[i]);
  return arr;
  

}

int main(){
    int arr[4]={5,3,4,2};
    int *p;
    p=sort(arr);
//for(int i=0;i<4;i++)
    //printf(" %d ",*(p+i));
}
