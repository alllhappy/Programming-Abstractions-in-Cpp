/*Some files use tab characters to align data into columns.  Doing so, however, 
can cause problems for applications that are unable to work directly with tabs.  
For these applications, it is useful to have access to a program that replaces 
tabs in an input file with the number of spaces required to reach the next tab 
stop.  In programming, tab stops are usually set at every eight columns.  For 
example, suppose that the input file contains a line of the form 
abc\tpqrst\txyz
abc is 3 characters, so it's at position 3.
The first tab (\t) should bring you to position 8 → So you add 5 spaces.
pqrst is 5 more characters → You’re now at position 13.
The second tab should bring you to position 16 → Add 3 spaces.
Then comes xyz.
So the final result would look like
abc     pqrst   xyz
Write a program that copies an input file to an output file, replacing all tab 
characters by the appropriate number of spaces.
*/

#include<iostream>
#include<fstream>
#include<string>
#include"input.h"


int main() {
    std::ifstream infile;
    std::ofstream outfile;
    promptUserForFile(infile);
    promptUserForOutFile(outfile);
    char ch;
    int counter=0;
    while(infile.get(ch)){
        // assumption that tab do not exist as space tab /t but literals / followed b by t
        //if tab is encountered insert space untile multiple of 8 is reached
        // checking for \ character first then t character to know that tab is present
        if(ch=='\\'){ // way to write \ character
            infile.get(ch);
            if(ch=='t'){ // yes it is a tab
                while(counter%8 !=0){
                counter++;
                std::cout<<counter<<" ";
                outfile.put(' ');
                }

            }
            else{
                infile.unget();
                outfile.put('\\');
                counter++;
                continue;
            }
        }
        else{
            outfile.put(ch);
            if(ch=='\n'){
                counter=0;
            }
            else{
                 counter++;
            }
           
        }
 
    }


    infile.close();
    outfile.close();
    return 0;       
}

