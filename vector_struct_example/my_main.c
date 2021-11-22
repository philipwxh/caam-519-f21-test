#include "my_vector_struct.h"
#include <stdio.h>

int main(){
  // lets start making vector v
  const int len = 4;
  my_vector v = vector_constructor(len);
  my_vector* ptr_v = &v;

  // this is the vector v
  int v_array[4] = {-1,5,2,3};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(v_array)/sizeof(int) ;++i){
    vector_set(ptr_v,i,v_array[i]);
  }

  // start making vector w
  my_vector w = vector_constructor(len);
  my_vector* ptr_w = &w;

  // this is the vector w
  int w_array[4] = {1,-1,1,-2};
  // putting in vector v into the structure of my_vector using vector_set
  for (int i=0; i < sizeof(w_array)/sizeof(int); ++i){
    vector_set(ptr_w,i,w_array[i]);
  }

  // compute v-w
  my_vector neg_w = vector_scalar_multiplication(&w, -1);
  my_vector v_w = vector_addition(&v,&neg_w);
  // print result of v-w
  printf("v-w equals to:\n");
  for (int i = 0; i < v_w.length; ++i){
    printf("%g\n", vector_get(&v_w, i));
  }

  // compute v·w
  double dot_production = vector_dot_product(&v,&w);
  // print result of v·w
  printf("v·w equals to: %g\n", dot_production);

  vector_destructor(&v);
  vector_destructor(&w);
  vector_destructor(&neg_w);
  vector_destructor(&v_w);

  return 0;
}