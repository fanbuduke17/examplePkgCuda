#include <Rcpp.h>
using namespace Rcpp;

#include "thrust_version.h"

// [[Rcpp::export]]
List rcpp_hello_world() {

    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;

    return z ;
}


// [[Rcpp::export]]
void rcpp_thrust_version() {
  thrust_version();
}