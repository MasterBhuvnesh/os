#include <stdio.h>
void bubbleSort(int array[],int array2[], int size) {
  for (int step = 0; step < size - 1; ++step) { 
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        int temp2 = array2[i];
        array2[i] = array2[i + 1];
        array2[i + 1] = temp2;
      }
    }
  }
}
int main() {
int n=3,m=3,k=3,l=3;
float avgwt=0.0;
float avgtat=0.0;
    int pid[n], BT[m],WT[k],TAT[l];
    
    printf("Enter values for PID array:\n");
    for (int i = 0; i < n; i++) {
        printf("PID[%d]: ", i+1);
        scanf("%d", &pid[i]);
    }
    
    
    printf("Enter values for BT array:\n");
    for (int i = 0; i < m; i++) {
        printf("BT[%d]: ", i+1);
        scanf("%d", &BT[i]);
    }
    
    bubbleSort(BT,pid, m);
    for (int i = 0; i < k; i++) {
    if((i==0)){
    WT[i]=0;
    }
    else{
    WT[i]=BT[i-1]+WT[i-1];
    }
    }
    for (int i = 0; i < m; i++) {
      TAT[i]=BT[i]+WT[i]; 
    }
    printf("\nPID  -->  BT  -->  WT  -->  TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d    -->  %d   -->  %d   -->   %d\n", pid[i], BT[i],WT[i],TAT[i]);
    }
    for (int i = 0; i < n; i++) {
    avgwt+=WT[i];
    }
        for (int i = 0; i < n; i++) {
    avgtat+=TAT[i];
    }
printf("AVERAGE WT  is %.2f\n",avgwt/k);
printf("AVERAGE TAT  is %.2f\n",avgtat/k);
    return 0;
}