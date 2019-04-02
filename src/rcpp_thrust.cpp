#include <Rcpp.h>

#include "thrust.h"

// [[Rcpp::export]]
void rcpp_thrust_version() {
  thrust_version();
}

// [[Rcpp::export]]
Rcpp::NumericMatrix rcpp_gpu_sq_exp_cov(Rcpp::NumericMatrix const& d, 
                                   double sigma2 = 1, double range=1) {
  return gpu_sq_exp_cov(d, sigma2, range);
}

