// Steve J Duber
// Prog Assignment 2
// 11/28/21

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
  
int main(){
  
  int n, m, i, j, k;
  //highly inefficient way to do this but it works
  int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15;
  int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15;
  int c1, c2, c3;
  vector<int> dataVec;
  
  ifstream data ("data.txt");
  if(data.is_open()){
    while (!data.eof()){
      int tmp;
      data >> tmp;
      dataVec.push_back(tmp);
    }
    //this is likely the worst code to ever exist
    c3=dataVec.back();dataVec.pop_back();c2=dataVec.back();dataVec.pop_back();c1=dataVec.back();dataVec.pop_back();

    b15=dataVec.back();dataVec.pop_back();b14=dataVec.back();dataVec.pop_back();b13=dataVec.back();dataVec.pop_back();
    b12=dataVec.back();dataVec.pop_back();b11=dataVec.back();dataVec.pop_back();b10=dataVec.back();dataVec.pop_back();
    b9=dataVec.back();dataVec.pop_back();b8=dataVec.back();dataVec.pop_back();b7=dataVec.back();dataVec.pop_back();
    b6=dataVec.back();dataVec.pop_back();b5=dataVec.back();dataVec.pop_back();b4=dataVec.back();dataVec.pop_back();
    b3=dataVec.back();dataVec.pop_back();b2=dataVec.back();dataVec.pop_back();b1=dataVec.back();dataVec.pop_back();

    a15=dataVec.back();dataVec.pop_back();a14=dataVec.back();dataVec.pop_back();a13=dataVec.back();dataVec.pop_back();
    a12=dataVec.back();dataVec.pop_back();a11=dataVec.back();dataVec.pop_back();a10=dataVec.back();dataVec.pop_back();
    a9=dataVec.back();dataVec.pop_back();a8=dataVec.back();dataVec.pop_back();a7=dataVec.back();dataVec.pop_back();
    a6=dataVec.back();dataVec.pop_back();a5=dataVec.back();dataVec.pop_back();a4=dataVec.back();dataVec.pop_back();
    a3=dataVec.back();dataVec.pop_back();a2=dataVec.back();dataVec.pop_back();a1=dataVec.back();dataVec.pop_back();

  }
  else{
    cout << "File unable to be read";
    return 1;
  }
  
  n = 5; //processes
  m = 3; //resources
  int alloc[5][3] = { { a1, a2, a3 }, // Allocation Matrix
                     { a4, a5, a6 }, 
                     { a7, a8, a9 }, 
                     { a10, a11, a12 }, 
                     { a13, a14, a15 } }; 
  
  int max[5][3] = { { b1, b2, b3 }, // MAX Matrix
                   { b4, b5, b6 },
                   { b7, b8, b9 },
                   { b10, b11, b12 },
                   { b13, b14, b15 } };
  
  int avail[3] = { c1, c2, c3 }; // Available Resources
  
  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  int need[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
  int y = 0;
  for (k = 0; k < 5; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {
  
        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > avail[j]){
            flag = 1;
            break;
          }
        }
  
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }
  
  cout << "The system is in a safe state\n";
  cout << "Here is the safe sequence:\n";
  for (i = 0; i < n - 1; i++)
    cout << " P" << ans[i] << " ->";
  cout << " P" << ans[n - 1] << endl;
  
  return 0;
}