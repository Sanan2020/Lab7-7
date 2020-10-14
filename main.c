#include <stdio.h>

char name[100];   /* เก็บชื่อ */
int temp[7][2];   /* เก็บค่าอุณหภูมิ */
int Max,Min;      /* เก็บค่าสูงสุด ต่ำสุด*/
float SumH,SumL;  /* เก็บค่าเฉลี่ยของอุณหภูมิ */
int midH,midL;    /* เก็บค่ากลางของอุณหภูมิ */
int main(void) {
  printf("Enter your name : ");
  scanf("%s",name);
  printf("Hello %s\n",name);
  printf("********************************\n");
//1 รับค่า
  /* ชื่อวัน */
  char day[7][10] = {"Monday", "Tuesday", "Wednesday","Thursday"
                      ,"Friday", "Saturday","Sunday"};
  /* รับค่าอุณหภูมิ 14 ค่า */
  for(int i=0;i<=6;i++){
    printf("High Temp %s : ",day[i]);
    scanf("%d",&temp[i][0]);
    printf("Low  Temp %s : ",day[i]);
    scanf("%d",&temp[i][1]); 
  }
  printf("********************************\n");
//2 Max,Min 
  Max = temp[0][0];
  Min = temp[0][0];
  for(int i=0; i<=6; i++){
    if (temp[i][0]>Max){  //เช็ค Max colum 0
      Max=temp[i][0];
    }
    if (temp[i][0]<Min){  //เช็ค Min colum 0
      Min=temp[i][0];
    }
  }

  for(int i=0; i<=6; i++){
    if (temp[i][1]>Max){  //เช็ค Max colum 1
      Max=temp[i][1];
    }
    if (temp[i][1]<Min){  //เช็ค Min colum 1
      Min=temp[i][1];
    }
  }
printf("Max Temperature is %d C\n",Max);
printf("Min Temperature is %d C\n",Min);
//3 Average
  for(int i=0;i<=6;i++){
    SumH = SumH + temp[i][0];
    SumL = SumL + temp[i][1];
  }
  SumH = SumH/7;
  SumL = SumL/7;
  printf("Average High Temperature is %.2f C\n",SumH);
  printf("Average Low  Temperature is %.2f C\n",SumL);
//4 Median
int swapH;
   for (int a=0;a<6;a++)
  {
    for (int b=0 ;b<7-a-1;b++)
    {
      if (temp[b][0] > temp[b+1][0]) /* High */
      {
        swapH         = temp[b][0];
        temp[b][0]   = temp[b+1][0];
        temp[b+1][0] = swapH;
      }
    }
  }
  midH = temp[3][0];
  printf("Median High Temperature is %d C\n",midH);
  int swapL;
   for (int c=0;c<6;c++)
  {
    for (int d=0 ;d<7-c-1;d++)
    {
      if (temp[d][1] > temp[d+1][1]) /* Low */
      {
        swapL         = temp[d][1];
        temp[d][1]   = temp[d+1][1];
        temp[d+1][1] = swapL;
      }
    }
  }
  midL = temp[3][1];
  printf("Median Low Temperature is %d C\n",midL);
}