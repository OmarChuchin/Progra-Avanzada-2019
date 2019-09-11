#include "exam.h"

int main(int argc, char const *argv[]) {

  if(testZeroParameters()){
    printf("%s\n", "Perfect");
  }
  else{
    printf("%s\n", "Failure");
  }
  if(testThreeParameters()){
    printf("%s\n", "Perfect");
  }
  else{
    printf("%s\n", "Failure");
  }
  if(testAllBitsActive()){
    printf("%s\n", "Perfect");
  }
  else{
    printf("%s\n", "Failure");
  }

  return 0;
}

unsigned int bitManager(char numberParameters, ...){
  if(numberParameters>MAX_NUM_ARGS){
    numberParameters=MAX_NUM_ARGS;
  }
  if(numberParameters<0){
    numberParameters=0;
  }
  unsigned int result=0;
  unsigned short counter=3;//Porque en binario es 11 los dos LSB
  char secondRound = 0;
  va_list parameters;
  va_start(parameters,numberParameters);
  for(char i=0;i<numberParameters;i++){
    //temp= counter & va_arg(parameters,short unsigned int);
    //temp= counter & va_arg(parameters,int);
    unsigned int temp = counter & (unsigned short)va_arg(parameters, int);
    if(secondRound){//Ya no alcanzan a llegar a los segundos 16 bits del integer
      temp = temp << 16;
    }
    result += temp;
    counter = counter<<2;//Porque asi si counter es 3, 0011, ahora es 12, 1100
    //Permitiendo asi recorrerse dos bits a la izquierda cada vez
    //Para cuando se pase de sus 16 bits
    if(counter==0){
      counter=3;
      secondRound++;
    }
  }
  va_end(parameters);
  return result;
}

char testZeroParameters(){
  unsigned int test0 = bitManager(0);
  if(test0==0){
    return 1;
  }
  return 0;
}

char testThreeParameters(){
  unsigned int test3;
  // 15 = 1111, 8 = 1000, 16 = 10000
  unsigned short fifteen = 15,eight= 8,sixteen=16;
  test3=bitManager(3,fifteen,eight,sixteen);
  //27 = 011011
  if(test3==27){
    return 1;
  }
  return 0;
}

char testAllBitsActive(){
  unsigned short shZero = 0, all = ~shZero; //All bits of a type short are active if we negate 0
  unsigned int testAll, iZero = 0, iAll = ~iZero;//All bits of a type int are active if we negate 0
  testAll = bitManager(18,all,all,all,all,all,all,all,all,all,all,all,all,all,all,all,all,shZero,shZero);
  if(testAll==iAll){
    return 1;
  }
  return 0;
}
