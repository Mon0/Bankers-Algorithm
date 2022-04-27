#include <iostream>
#include <fstream>

//Number of processes (P0, P1, P2, P3, P4)
int n = 5;

//Number of resources
int m = 3;

//Allocation of resources
int alloc[n][m];

//Max resource demand
int max[n][m];

//Available resources
int available[m];

//Need matrix
int need[n][m];

//Answer
int ans[n];

inf f[n] = {0,0,0,0,0};

int index = 0;

int main(int argc, char* argv[]) {
   int max2 = 0;
   int alloc2 = 0;
   
   //check for file open
   std::ifstream in(argv[1]);
   if (!in) {
      std::cerr << "Can not open file!" << argv[1] << std::endl;
      exit;
   }
   else if(in) {
      char chara;
      int i = 0;
      while(in >> chara) {
         if(chara == ';') {
            break;
         }
         //iterate through txt file to fill in the Allocation table
         else {
            alloc[alloc2][i] = chara - '0';
            i++;
            if(i == m) {
               i = 0;
               alloc2++;
            }
         }
      }
   i = 0;
   while(in >> chara) {
      if(chara == ';') {
         break;
      }
      //iterate through the txt file to fill in the Max table
      else {
         max[max2][i] = chara - '0';
         i++;
         if(i == m) {
            i = 0;
            max2++;
         }
      }   
   }
   i = 0;
   while(in >> chara) {
      if(chara == ';') {
         break;
      }
      //iterate and fill in Available table
      else {
         available[i] = chara - '0';
         i++;
         if(i == m) {
            //only one row for available
            i = 0;
         }
      }
   }
   }
   //Need defined
   for(int x = 0; x < n; x++) {
      for(int y = 0; y < m; y++){
         need[x][y] = max[x][y] = alloc[x][y];
      }
   }
   
   int a = 0;
   int x, y, z;
   for(z = 0; z < n; z++) {
      for(x = 0; x < n; x++) {
         if(f[x] == 0) {
            int flag = 0;
            for(y = 0; y < m; y++) {
               if(need[x][y] > available[y]) {
                  flag = 1;
                  break;
               }
            }
            if(flag == 0) {
               ans[index++] = x;
               for(a = 0; a < m; a++) {
                  available[a] += alloc[x][a];
               }
               f[x] = 1;
            }
         }
      }
   }
   
   int flag = 1
   
   //Check for safe sequence
   for(int i = 0; i < n; i++) {
      if(f[i] == 0) {
         flag = 0;
         std::cout << "The sequence is not safe" << std::endl;
         break;
      }
   }
   
   //Print safe sequence
   if(flag == 1) {
      std::cout << "The safe sequence is: " << std::endl;
      for(i = 0; i < n; i++) {
         if( i == n - 1) {
            std::cout << " P" << ans[i] << " ->";
         }
         else {
            std::cout << " P" << ans[i] << ",";
         }
      }
   }
   return 0;
}
