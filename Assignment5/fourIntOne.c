#include <stdio.h>

int main(int argc, char const *argv[]) {
  unsigned char a,b,c,d;

  scanf("%hhu\n", &a);
  scanf("%hhu\n", &b);
  scanf("%hhu\n", &c);
  scanf("%hhu",   &d);

  unsigned int result = a, temp = b;
  temp = b<<8;
  result+=temp;
  temp=c;
  temp=temp<<16;
  result+=temp;
  temp=d;
  temp=temp<<24;
  result+=temp;

  printf("%u\n", result);

  return 0;
}
