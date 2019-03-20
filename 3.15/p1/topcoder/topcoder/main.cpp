//
//  main.cpp
//  topcoder
//
//  Created by FUFEI DU on 3/16/19.
//  Copyright © 2019 FUFEI DU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "p1.hpp"
#include "p2.hpp"
#include "p3.hpp"
#include "all_primes.hpp"
#include <unordered_map>
typedef vector<vector<int>> vvi;
typedef unordered_map<int, bool> dictib;
using namespace std;


int main(int argc, const char * argv[]) {
  
//  SwappingNode s = SwappingNode();
//  vi ls = s.swapNodes(lf, 4);
//  for(auto i:ls){
//    cout<<i<<" ";
//  }
  PrimeAlters p = PrimeAlters();
  vi a = {100003,294001};
  vi b = {100003,100003};
  vi c = {7331,72652729};
  vi d = {8219,28784281};
  string s =p.isReachable(a, b);
  cout<<p.isPrime(c[1]);
  cout<<s<<endl;
  return 0;
}
