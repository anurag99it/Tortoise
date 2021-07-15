/* my approach is to store every coordinate that turtle crosses and compare every new 
coordinate that tutle comes on with the previous stored one's and if they coincide then 
we say that it crosses its own path.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> x;
vector<int> y;

int crossing(int a[],int n){     //given array of his movements and size of that array and returns the segment on which it is overlapping 
    x.push_back(0);             // setting initial coordinates to (0,0)
    y.push_back(0);
    for(int i=0;i<n;i++){                //traversing for whole array  ^
        if(i%4==0){                      //considering +ve y direction |      
            for(int j=0;j<a[i];j++){     //for each movement      
                for(int k=0;k<x.size();k++){  
                    if(x[k]==x[x.size()-1] && y[k]==y[y.size()-1]+1 && j!=0 && k!=0)  //checking if this coordinate already exist 
                      return a[i];
                    }
                        x.push_back(x[x.size()-1]);
                        y.push_back(y[y.size()-1]+1);
                }
            }
        else if(i%4==1){                            //now for +ve x direction ->            
            for(int j=0;j<a[i];j++){
                for(int k=0;k<y.size();k++){
                    if(y[k]==y[y.size()-1] && x[k]==x[x.size()-1]+1)           //checking if this coordinate already exist
                      return i;
                    }
                        y.push_back(y[y.size()-1]);
                        x.push_back(x[x.size()-1]+1);
                }
            }
        else if(i%4==2){                            //now for -ve y direction |            
            for(int j=0;j<a[i];j++){                          //              
                for(int k=0;k<y.size();k++){
                    if(y[k]==y[y.size()-1]-1 && x[k]==x[x.size()-1])           //checking if this coordinate already exist
                      return i;
                    }
                        y.push_back(y[y.size()-1]-1);
                        x.push_back(x[x.size()-1]);
                }
            }
        else if(i%4==3){                            //now for -ve x direction <-            
            for(int j=0;j<a[i];j++){                          //              
                for(int k=0;k<y.size();k++){
                    if(y[k]==y[y.size()-1] && x[k]==x[x.size()-1]-1)           //checking if this coordinate already exist
                      return i;
                    }
                        y.push_back(y[y.size()-1]);
                        x.push_back(x[x.size()-1]-1);
                }
            }    
    }    
}
