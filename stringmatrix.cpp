#include <Rcpp.h>
using namespace Rcpp;
//[[Rcpp::export]]
std::string matrix_char(CharacterMatrix xa){
  std::string combine;
  for(size_t i=0;i<xa.nrow();i++){
    combine +=xa(i,i);
  }
  return combine;
}

