## kata for C programming and testing ##
-----
### How to Create Bulk Executable File Samples with unique SHA1 ###
- **file_sample/write_file_open_browser.cc**
- which writes eicar.com at working folder and open google page by default browser

#### Windows: ####
+ install C/C++ compiler or IDE, such as http://www.codeblocks.org/
+ use gcc -DBUILDNUM= to generate file sample with loop
 + cd C:\Program Files (x86)\CodeBlocks\MinGW\bin
 + for /l %x in (1001, 1, 1100) do gcc -DBUILDNUM=%x D:\temp\write_file_open_browser.cc -DBUILDNUM=%x -o D:\temp\%x.exe


#### Linux ####
+ use gcc -DBUILDNUM= to generate file sample with loop
 + for num in {1001..1100}; do gcc -DBUILDNUM=$num write_file_open_browser.cc -o $num.o; done


#### Mac ####
+ use gcc -DBUILDNUM= to generate file sample with loop
 + for num in {1001..1100}; do gcc -DBUILDNUM=$num write_file_open_browser.cc -o $num.m; done

