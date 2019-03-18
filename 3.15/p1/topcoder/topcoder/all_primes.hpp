//
//  all_primes.hpp
//  topcoder
//
//  Created by FUFEI DU on 3/18/19.
//  Copyright © 2019 FUFEI DU. All rights reserved.
//

#ifndef all_primes_hpp
#define all_primes_hpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef unordered_map<int, bool> dictib;
vi all_prime(int top){
  vi seed = {2,3,5,7,11,13,17,19};
  if(top< *(seed.end()-1)){
    return seed;
  }
  //    find seed position
  int pos = 0;
  for(;pos<seed.size();pos++){
    if(seed[pos]*seed[pos]>=top){
      break;
    }
  }
  if (pos==seed.size()-1){
    while( *(seed.end()-1) * *(seed.end()-1) <top ){
      int start =*(seed.end()-1);
      int target = start*start;
      for(int i = start+2; i<target; i++){
        int is_prime = 1;
        for(auto prime:seed){
          if((i%prime)==0){
            is_prime=0;
            break;
          }
        }
        if(is_prime){
          seed.push_back(i);
        }
      }
    }
  }
  for (int i = *(seed.end()-1)+2; i<=top; i++) {
    int is_prime = 1;
    for (auto prime:seed) {
      if (i%prime==0) {
        is_prime=0;
        break;
      }
    }
    if (is_prime) {
      seed.push_back(i);
    }
  }
  
  return seed;
}
#endif /* all_primes_hpp */
