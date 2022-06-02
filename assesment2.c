#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int validity(int n)
{
    int i, sum=0,rem1,rem2,m;
    m=n;
    if(n>=10)
       {
          while(n>0)
          {
              rem1=n%10;
              n=n/10;
              rem2=n%10;
              rem2=rem2*2;
              n=n/10;
              sum=sum+rem1+rem2;
              i++;
          }
        if(sum%10==0)
        {
            printf("The card number %d is valid.",m);
        }
        else
        {
            printf("The card number %d is invalid.",m);
        }
       }
    else
        printf("Card number should have at least 2 digits.");
    return n;
}
int main() {
    int n;
    scanf("%d",&n);
    validity(n);


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

}
