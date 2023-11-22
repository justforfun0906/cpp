#include <stdio.h>
/* 2016/09/22 */
long long first4(long long x){
   return x/10000;
}
long long last4(long long x){
   /* The operator % in C computes the remainder after division.
      For example, the answer of 23%7 will be 2.*/
   return x%10000;
}
long long first8(long long x){
   return x/100000000;
}
long long last8(long long x){
   return x%100000000;
}
long long shift4(long long x){
   return x*10000;
}
int main(void){
   long long x;
   long long a, b;
   long long c1, c2, c3;
  /* Assume that the input is always an 8-digit positive long longeger. */
   scanf("%lld", &x); 
   a = first4(x);
   b = last4(x);
   c3 = last4(b*b);
   c2 = shift4(last4(a*a)) + first4(b*b) + last8(2*a*b);
   c1 = first4(a*a) + first8(c2);
   c2 = last8(c2);
   printf("%4lld%08lld%04lld", c1, c2, c3);  
   //printf("a=%lld b=%lld c1=%lld c2=%lld c3=%lld", a, b, c1, c2, c3);
   /* %04d will display a 4-digit number and add 0 as padding before the number if necessary */
   return 0;
   //7683517885639684
   //76821517885639684
}