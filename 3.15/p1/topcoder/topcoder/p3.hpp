//
//  p3.hpp
//  topcoder
//
//  Created by FUFEI DU on 3/17/19.
//  Copyright © 2019 FUFEI DU. All rights reserved.
//

#ifndef p3_hpp
#define p3_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef unordered_map<int, bool> dictib;
typedef vector<vector<int>> vvi;
#define pb push_back
class PrimeAlters{
public:
  bool isPrime(int num){
    int top = sqrt(num);
    if(!(num%2)){
      return false;
    }
    for (int i = 3; i<=top; i+=2) {
      if (!(num%i)) {
        return false;
      }
    }
    return true;
  };
  bool find_path(int num,int label,dictib& dict){
    if(num<10){
      return true;
    }
    if(num==label){
      return true;
    }
    if(dict.find(num)!=dict.end()){
      return false;
    }
    dict.insert({num,true});
    
    if(!isPrime(num)){
      return false;
    }
    vi digits = {};
    do{
      digits.pb(num%10);
      num/=10;
    }while(num/10);
    digits.pb(num);
    vvi all_digits(digits.size()*10,digits);
    for(int i = 0,j=0; i<all_digits.size();i++,j++){
      all_digits[i][j/10]= j%10;
    }
    bool finded=false;
    for(auto arr:all_digits){
      if(arr[arr.size()-1]==0){
        continue;
      }
      int candidate = 0;
      for(int i =0,j=1; i<arr.size();i++,j*=10){
        candidate+=arr[i]*j;
      }
      finded = finded||find_path(candidate, label, dict);
    }
    return finded;
  }
  
  string isReachable(vector <int> source, vector <int> target){
    string s = "";
    
    for(int i = 0;i<source.size();i++){
      int integer = source[i];
      int label = target[i];
      dictib dict = {};
      
      if (find_path(integer, label, dict)){
        s+="1";
      }else{
        s+="0";
      }
    }
    return s;
  }
};
#endif /* p3_hpp */
