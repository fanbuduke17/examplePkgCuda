#ifndef CUDA_UTIL_H
#define CUDA_UTIL_H

#include <Rcpp.h>
#include <cuda.h>
#include <curand.h>

#define CUDA_CALL(x) do { if((x)!=cudaSuccess) {        \
Rcpp::stop("Error at ",__FILE__, ":", __LINE__, ".\n"); \
}} while(0)
  
#define CURAND_CALL(x) do { if((x)!=CURAND_STATUS_SUCCESS) { \
Rcpp::stop("Error at ",__FILE__, ":", __LINE__, ".\n");      \
}} while(0)

#endif
