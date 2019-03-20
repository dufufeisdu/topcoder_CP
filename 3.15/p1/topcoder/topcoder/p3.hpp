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
  
  bool find_path_itration(int num,int label){
    if (num==label) {
      return true;
    }
    dictib dict = {{num,true}};
    dictib deleted_num={};
    while(!dict.empty()){
      for(auto it = dict.begin();it!=dict.end();){
        num = (*it).first;
        it = dict.erase(it);
        deleted_num.insert({num,true});
        //use vector to store all the digits of a num
        vi digits = {};
        while(num/10){
          digits.pb(num%10);
          num/=10;
        };
        digits.pb(num);
        //create a 2d array store all the changable digits
        vvi all_digits(digits.size()*10,digits);
        for(int i = 0,j=0; i<all_digits.size();i++,j++){
          all_digits[i][j/10]= j%10;
        }
        
        //itarate through all nums, find good one
        for(auto arr:all_digits){
          //high digit should not be 0
          if(arr[arr.size()-1]==0){
            continue;
          }
          //assemble digits to number
          int candidate = 0;
          for(int i =0,j=1; i<arr.size();i++,j*=10){
            candidate+=arr[i]*j;
          }
          
          if(isPrime(candidate)){
            if (candidate==label) {
              return true;
            }else{
              if(deleted_num.find(candidate)==deleted_num.end()){
                dict.insert({candidate,true});
              }
            }
          }
        }
      }
    }
    return false;
  };
  string isReachable(vector <int> source, vector <int> target){
    string s = "";
    
    for(int i = 0;i<source.size();i++){
      int integer = source[i];
      int label = target[i];
      
      if (find_path_itration(integer, label)){
        s+="1";
      }else{
        s+="0";
      }
    }
    return s;
  }
};
#endif /* p3_hpp */
