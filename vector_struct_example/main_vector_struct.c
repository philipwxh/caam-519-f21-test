#include "my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  int w_array[4] = {1,-1,1,-2};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
    vector_set(ptr_w,i,w_array[i]);
  }
  
  my_vector x;
  x = vector_addition(ptr_v, ptr_w);
  my_vector* ptr_x = &x;
  
  printf("Result of adding v+w: ");
  for (int i=0; i < ptr_x->length ;++i){
    double index_value = vector_get(ptr_x, i);
    printf("%f", index_value);
}
  // free up space occupied by these vectors
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_x);

}