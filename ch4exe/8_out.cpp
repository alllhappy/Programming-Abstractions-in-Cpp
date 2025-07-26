
#include<iostream>
#include<fstream>
#include"input.h"


void removeComments(std::ifstream &infile, std::ofstream &outfile);

int main() {
    std::ifstream sourceFile;
    promptUserForFile(sourceFile);

    std::ofstream output;
    output.open("8_out.cpp");
    removeComments(sourceFile,output);
    sourceFile.close();
    output.close();
    return 0;
}
void removeComments(std::ifstream &infile, std::ofstream &outfile){
    char ch;
    while(infile.get(ch)){

                bool flag=false;
        if(ch=='/'){
            infile.get(ch);
            if(ch=='/'){
                                                flag=true;
                while(infile.get(ch)){
                    if(ch=='\n') break;
                }

            }
            else if(ch=='*'){
                                flag=true;
                while(infile.get(ch)){
                    if(ch=='*'){
                        infile.get(ch);
                        if(ch=='/') break;
                    }
                }
            }
            else{
                infile.unget();
            }
            
                        if(flag==false){
                outfile.put('/');
            }
        }
        else{
            outfile.put(ch);
        }
       
    
        

        
    }

}
