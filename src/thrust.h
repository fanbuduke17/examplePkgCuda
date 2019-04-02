

void thrust_version(void);

Rcpp::NumericMatrix gpu_sq_exp_cov(Rcpp::NumericMatrix const& d, 
                                   double sigma2 = 1, double range=1);
