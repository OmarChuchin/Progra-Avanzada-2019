#include <stdio.h>

int main(){
  //char string[] ="What is the difference between a ' and a \"? Or between a \" and a \\";
  /*char bslash='\\';
  char quote='\"';
  char sim_quote='\'';
  printf("%c\n", sim_quote);*/
  char string1[]="What is the difference between a \' and a \"? Or between a \" and a \\\"?";
  char string2[]="One is what we see when we're typing our program. The other is what appears on the \"console.\"";
  printf("%s\n", string1);
  printf("%s\n", string2);
  return 0;
}
