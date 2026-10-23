#include<iostream>
using namespace std;
int main()
{
   float num =11111111111.200;
   cout<<num<<endl;
   cout<<sizeof(num)<<endl;
   char arr[] = "hello world\n";
   string arr1(arr);
   cout<<arr1<<endl;
   int *parr = new int[8] {1,2,3,4,5,6,7,8};
   int *new_parr = new int[6];
   int j = 0;
   int *p = new int(0);
   for(int i=0;i<8;i++)
   {
      if (parr[i]==1)
      {
         continue;
      }
      else if (parr[i]==5)
      {
         continue;
      }
      else
      {
         parr[j++] = parr[i];
      }
   }
   for(int i=0;i<5;i++)
   {
      cout<<parr[i]<<endl;
   }
   delete parr;
   delete new_parr;
   parr  = nullptr;
   new_parr = nullptr;
   return 0;
}