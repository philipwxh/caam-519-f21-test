#include "my_vector_struct.h"
#include <stdlib.h>
#include <stdio.h>

// implementation of the functions

// constructor
my_vector vector_constructor(const int length){

  // declaring a vector
  my_vector vec;
  vec.v = NULL;
  
  // return if a bad length value is given
  if (length <= 0){
    printf("vector_constructor: the vector length is negative!\n");
    vec.length = length;
    vec.status = 1;
    return vec;
  }
  else{ // length > 0 and we try to allocate memory
    vec.length = length;
    vec.v = (double*) calloc(length, sizeof(double));
    if(vec.v != NULL){ //A == NULL means out of memory
      vec.status = 0;
    }
    else{
      vec.status = 1;
    }
    return vec;
  }
}

// destructor
void vector_destructor(my_vector* vec){
  free(vec->v);
  // status is nonzero indicating the vector cannot be used.
  vec->status = 1;
}

// set <-- this function writes to a value in a given index, in the vector
void vector_set(my_vector* vec, const int index, const double value){
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_set: index exceeds vector length\n");
    }
    else{
      // set value.
      vec->v[index] = value;
    }
  }
  else {
    printf("vector_set: this vector cannot be used now\n");
  }
}

// get <-- this function reads the a value from a given index, from the vector
double vector_get(my_vector* vec, const int index){
  double value = 0.0;
  if (vec->status == 0){
    if (index > vec->length - 1){
      printf("vector_get: index exceeds vector length\n");
    }
    else{
      // set value.
      value = vec->v[index];
    }
  }
  else {
    printf("vector_get: this vector cannot be used now\n");
  }
  return value;
}


// vector scalar multiplication
my_vector vector_scalar_multiplication(my_vector* v, double num){
  // initialized a new vector called x
  my_vector x = vector_constructor(v->length);

  // here the input is the scalar num and we have checked that v is a usable vector
  if (v->status == 0){

    //get the address of x for the pointer
    my_vector* ptr_x = &x;
    
    for (int i=0; i < v->length ;++i){
	const double index_value = num*vector_get(v, i); 
	vector_set(ptr_x, i, index_value); // check if I need to do this on w instead of the pointer
    }
  }
  else {
    printf("vector_scalar_multiplication: this is an invalid vector we have inputted");
  }

  return x;
}

// vector dot multiplication
double vector_dot_product(my_vector* v, my_vector* w){
  //define output
  double output = 0;

  // here the input is the scalar num and we have checked that v is a usable vector. Do same for w and check if lengths are the same
  if ((v->status == 0 && w->status) == 0 && v->length == w->length){

    //get the address of x for the pointer
    
    for (int i=0; i < v->length ;++i){
	output+= vector_get(w, i)*vector_get(v, i); 
    }
  }
  else {
    printf("vector_dot_product: this is an invalid vector we have inputted");
  }

  return output;
}

// vector addition
my_vector vector_addition(my_vector* v, my_vector* w){
  // initialized a new vector x
  my_vector x = vector_constructor(v->length);
  // here the input is the scalar num and we have checked that v is a usable vector. Do same for w and check if lengths are the same
  if ((v->status == 0 && u->status) == 0 && v->length == u ->length){

    //get the address of x for the pointer
      my_vector* ptr_x = &x;
    
    for (int i=0; i < v->length ;++i){
	const double index_value = vector_get(w, i)+vector_get(v, i); 
	vector_set(ptr_x, i, index_value);
    }
  }
  else {
    printf("vector_dot_multiplication: this is an invalid vector we have inputted");
  }

  return x;
}


