#include <stdio.h>
#include <stdarg.h>

#define MAX_NUM_ARGS 16

unsigned short power(unsigned short number, unsigned short times){
  if(times<1){
    return 1;
  }
  times--;
  return power(number,times)*number;
}

unsigned int bitManager(char numberParameters,unsigned short firstParameter , ...){

  if(numberParameters>MAX_NUM_ARGS){
    numberParameters=MAX_NUM_ARGS;
  }
  unsigned int result=0;
  unsigned short counter=3;//Porque en binario es 11 los dos LSB
  va_list parameters;
  va_start(parameters,numberParameters);
  for(char i=1;i<numberParameters;i++){
    result += counter & va_arg(parameters,unsigned short);
    counter*=4;//Porque asi si counter es 3, 0011, ahora es 12, 1100
    //Permitiendo asi recorrerse dos bits a la izquierda cada vez
    //Para cuando se pase de sus 16 bits
    if(counter==0){
      counter=3;
    }
  }

}

int main(int argc, char const *argv[]) {
  //nothing
  return 0;
}
