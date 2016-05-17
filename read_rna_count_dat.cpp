//################################################################################
//# Author:Kai Guo guokai8@gmail.com ##############################################
//# 
//# Last modified: 2015-01-13 16:41######################################
//# 
//# Filename: read_file.cpp
//# 
//# Description: This script is writed for read data frame just like the rna seq count table quickly####
//#################################################################################
#include <Rcpp.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace Rcpp;
using namespace std;
//[[Rcpp::export]]
SEXP readfile(std::string filepath,std::string sep){
  ifstream fin(filepath);
  string linestr;
  string colstr;
  int icol=0,irow=0;
  const char * colChar;
  vector<string> colNames;
  getline(fin,linestr);
  stringstream strStr {};
  strStr.str(linestr);
  while(std::getline(strStr,colstr,sep[0]))
  {
    colNames.push_back(colstr);
  }
  strStr.clear();
  vector<string> rowNames;
  vector<vector<double>> countData;
  vector<double> rowdata;
  icol = colNames.size() - 1;
  double countValue;
  while(getline(fin,linestr)){
    strStr.str(linestr);
    getline(strStr,colstr,sep[0]);
    rowNames.push_back(colstr);
    while(getline(strStr,colstr,sep[0])){
      colChar=colstr.c_str();
      countValue=atof(colChar);
      rowdata.push_back(countValue);
  }
    countData.push_back(rowdata);
    strStr.clear();
    rowdata.clear();
    ++irow;
  }
  //NumericMatrix res(irow,icol);
  List res(irow);
  for(int i=0;i<irow;++i){
    res[i]=countData[i];
    //below is return NumericMatrix
    //rowdata=countData[i]
    //for(int j=0;j<icol;++j){
    //  res(i,j)=rowdata[j];
    //}
    //rowdata.clear();
  }
  StringVector rnames=wrap(rowNames);
  StringVector cnames=wrap(colNames);
  res.attr("row.names")=rnames;
  res.attr("names")=cnames;
  res.attr("class") = "data.frame";
  return res;
}

