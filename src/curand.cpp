#include <Rcpp.h>

#include <cuda.h>
#include <curand.h>

#define CUDA_CALL(x) do { if((x)!=cudaSuccess) {     \
Rcpp::stop("Error at ",__FILE__,":",__LINE__,".\n"); \
}} while(0)
  
#define CURAND_CALL(x) do { if((x)!=CURAND_STATUS_SUCCESS) { \
  Rcpp::stop("Error at ",__FILE__,":",__LINE__,".\n");       \
}} while(0)

// [[Rcpp::export]]
std::vector<double> curand_rnorm(int n, int seed, double mu, double sigma) {
  
  curandGenerator_t gen;
  double* dev_data;
  std::vector<double> host_data(n);
  
  CUDA_CALL(cudaMalloc((void **)&dev_data, n*sizeof(float)));
  
  CURAND_CALL(curandCreateGenerator(&gen, CURAND_RNG_PSEUDO_DEFAULT));
  
  CURAND_CALL(curandSetPseudoRandomGeneratorSeed(gen, (unsigned long long) seed));
  
  CURAND_CALL(curandGenerateNormalDouble(gen, dev_data, n, mu, sigma));
  
  CUDA_CALL(cudaMemcpy(&(host_data[0]), dev_data, n * sizeof(float), cudaMemcpyDeviceToHost));
  
  /* Cleanup */
  CURAND_CALL(curandDestroyGenerator(gen));
  CUDA_CALL(cudaFree(dev_data));
  
  return host_data;
}