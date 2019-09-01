#include <stdio.h>

int main(){
  char string[]="A \"quoted\" String is\n'much' better if you learn\nthe rules of \"escape sequences.\"\nAlso, \"\" represents an empty String.\nDon't forget: use \\\" instead of \" !\n'' is not the same as \"";
  printf("%s\n", string);
}
