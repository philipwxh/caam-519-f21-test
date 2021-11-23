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
  
  my_vector y = vector_addition(ptr_v, ptr_w);
  my_vector* ptr_y = &y;
  
  printf("Result of adding v+w: [");
  for (int i=0; i < ptr_y->length ;++i){
    double index_value = vector_get(ptr_y, i);
    printf("%f%s", index_value, ", ");
}
printf("]\n");

  my_vector z = vector_scalar_multiplication(ptr_v, 2);
  my_vector* ptr_z = &z;
  
  printf("Result of multiplying v by 2: [");
  for (int i=0; i < ptr_z->length ;++i){
    double index_value = vector_get(ptr_z, i);
  printf("%f%s", index_value, ", ");
}
printf("]\n");

  double d = vector_dot_product(ptr_v, ptr_w);
  printf("%s%f","Result of dot product v.w: ",d);
  
  // free up space occupied by these vectors
  vector_destructor(ptr_v);
  vector_destructor(ptr_w);
  vector_destructor(ptr_y);
  vector_destructor(ptr_z);

}