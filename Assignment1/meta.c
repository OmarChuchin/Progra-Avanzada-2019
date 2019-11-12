#include <stdio.h>

int main(){

  printf("%s\n","#include \"stdio.h\"\n\n\n" );
  printf("%s\n", "int main(void) {");
  printf("%s\n", "printf(\"Hello World\\n\");");
  printf("%s\n}\n","return 0;");
  return 0;
}
