#include <stdio.h>
int main (void)
{
 int a,b;
 printf("enter two intgers:");
 scanf("%d %d",&a,&b);
 printf("sum=%d\n",a+b);
 printf("difference=%d\n",a-b);
 printf("product=%\n",a*b);
 if (b!=0)
{
  printf("quotient=%d\n",a/b);
  scanf("remainder=%d\n",a-b);
}
else
 {
   ("division & remainder cannot be performed because the second integer is zero.\n");
 }
return 0;
}