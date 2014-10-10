#include <Rcpp.h>
using namespace Rcpp;
//[[Rcpp::export]]
SEXP ff(NumericVector x){
  IntegerVector factor(x);
  //factor.attr("class")="factor";
  return factor;
}
//[[Rcpp::export]]
NumericVector out_f(NumericVector xs){
  NumericVector x(xs);
  NumericVector::iterator it=std::min_element(x.begin(),x.end());
  return wrap(it-x.begin());
}

