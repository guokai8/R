#include <Rcpp.h>
using namespace Rcpp;
//[[Rcpp::export]]
int printt_c(int xa){
  for(int i=0;i<xa;i++){
    Rprintf("hello world\n");
  }
  return xa;
}
  
