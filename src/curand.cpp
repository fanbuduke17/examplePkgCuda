#include <Rcpp.h>

#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <curand.h>

#include "cuda_util.h"

// [[Rcpp::export]]
std::vector<double> gpu_rnorm(int n, int seed, double mu = 0, double sigma = 1) 
{
  double *dev_data;
  std::vector<double> host_data(n);
  
  CUDA_CALL(cudaMalloc((void **)&dev_data, n*sizeof(double)));
  
  curandGenerator_t gen;
  CURAND_CALL(curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_DEFAULT));

  CURAND_CALL(curandSetPseudoRandomGeneratorSeed(gen, (unsigned long long) seed));
  
  CURAND_CALL(curandGenerateNormalDouble(gen, dev_data, n, mu, sigma));
  
  CUDA_CALL(cudaMemcpy(&(host_data[0]), dev_data, n * sizeof(double), cudaMemcpyDeviceToHost));
  
  CURAND_CALL(curandDestroyGenerator(gen));
  CUDA_CALL(cudaFree(dev_data));
  
  return host_data;
}