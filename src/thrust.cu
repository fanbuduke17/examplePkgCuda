#include <thrust/version.h>
#include <thrust/device_vector.h>

#include <Rcpp.h>

// [[Rcpp::export]]
void thrust_version(void) {
  int major = THRUST_MAJOR_VERSION;
  int minor = THRUST_MINOR_VERSION;
  int subminor = THRUST_SUBMINOR_VERSION;
  int patch = THRUST_PATCH_NUMBER;
  
  Rcpp::Rcout << "Thrust v" << major << "." << minor << "."
              << subminor << "-" << patch << "\n";
              
}

struct sq_exp_cov_functor{
  double sigma2;
  double range;
  sq_exp_cov_functor(double s, double r) : sigma2(s), range(r) { }
  __host__ __device__ double operator()(double &d) const{
    return sigma2 * exp(-d*d * range*range);
  }
};

Rcpp::NumericMatrix gpu_sq_exp_cov(Rcpp::NumericMatrix const& d, 
                                   double sigma2 = 1, double range=1) {
  thrust::device_vector<double> D(d.begin(), d.end());
  thrust::transform(D.begin(), D.end(), D.begin(), sq_exp_cov_functor(sigma2, range));
  Rcpp::NumericMatrix cov(d.nrow(), d.ncol());
  thrust::copy(D.begin(), D.end(), cov.begin());
  return cov;
}