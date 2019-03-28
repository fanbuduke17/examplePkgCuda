#include <thrust/version.h>
#include <iostream>
#include <Rcpp.h>

// [[Rcpp::export]]
void thrust_version(void) {
    int major = THRUST_MAJOR_VERSION;
    int minor = THRUST_MINOR_VERSION;
    int subminor = THRUST_SUBMINOR_VERSION;
    int patch = THRUST_PATCH_NUMBER;

    Rcpp::Rcout << "Thrust v" << major << "." << minor << "." << subminor << "-" << patch << std::endl;
}