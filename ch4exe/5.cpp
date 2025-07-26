/*Two functions that are particularly useful are getRoot and 
getExtension, which divide a function into its root, which is the identifying 
part of the filename, and the extension, which indicates its type.  For example, 
given the filename Middlemarch.txt used in the preceding exercise, the 
root is Middlemarch and the extension is .txt (note that filelib.h defines 
the extension to includes the dot).  Write the code necessary to implement 
these functions.*/
#include<iostream>
#include<string>
#include<vector>


std::string getExtension(std::string fileName);
std::string getRoot(std::string fileName);
int main() {
    
    std::vector<std::string> fileNames={"haha.txt", "gta.exe","3.cpp"};
    for(int i=0;i<fileNames.size();i++){
        std::cout<<getRoot(fileNames[i])<<"   "<<getExtension(fileNames[i])<<std::endl;
    }

    return 0;
}
std::string getRoot(std::string fileName){
    std::string name="";
    for(int i=0;i<fileName.length();i++){
        if(fileName[i]=='.') break;
        name+=fileName[i]; 
    }
    return name;
}

std::string getExtension(std::string fileName){
    std::string ext="";
    bool flag=false;
    for(int i=0;i<fileName.length();i++){
        if(fileName[i]=='.') flag=true;

        if(flag==true){
            ext+=fileName[i];
        }
    }
    return ext;
}