//
//  p1.hpp
//  topcoder
//
//  Created by FUFEI DU on 3/17/19.
//  Copyright © 2019 FUFEI DU. All rights reserved.
//

#ifndef p1_hpp
#define p1_hpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
class SwappingNode{
public:
  vi swapNodes(vi leaves,int numberOfLeaves){
    while (numberOfLeaves>1){
      numberOfLeaves/=2;
      auto start = leaves.begin();
      auto end = leaves.end();
      while (start<end) {
        auto le = min_element(start, start+numberOfLeaves);
        start+=numberOfLeaves;
        auto ri = min_element(start,start+numberOfLeaves);
        if(*ri<*le){
          for(auto i = start;i<start+numberOfLeaves;i++){
            int a = *i;
            *i = *(i-numberOfLeaves);
            *(i-numberOfLeaves) = a;
          }
        }
        start+=numberOfLeaves;
      }
    }
    return leaves;
  }
};
#endif /* p1_hpp */
