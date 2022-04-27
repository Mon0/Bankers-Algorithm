# Bankers-Algorithm

In order to run this program, the cpp and txt files need to be downloaded and palced within the same directory. 

Compiles and executes respectively using:

$ g++ algorithm.cpp -o banker

$ ./banker data.txt


The program works by reading in the txt file and filling out the corresponding arrays using the data in the txt file. 
The data within the txt file needs to be arranged in similar fashion to the data in the txt file for the program to function correctly. 
Once the arrays are filled, the data is used to fill a fourth Need table.
From there it will loop through all the process rows and both determine if the sequence is safe and output the safe sequence if there is one.
