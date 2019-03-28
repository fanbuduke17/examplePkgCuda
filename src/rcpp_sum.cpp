#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
double rcpp_sum(Rcpp::NumericVector v) {
  double sum = 0;
  for(auto e : v) {
    sum += e;
  }
  
  return sum;
}
