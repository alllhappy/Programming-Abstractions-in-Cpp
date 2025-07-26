/*Another useful function in filelib.h is 
string defaultExtension(string filename, string ext); 
which adds ext to the end of filename if it doesn’t already have an 
extension.  For example, 
defaultExtension("Shakespeare", ".txt") 
would return "Shakespeare.txt".  If filename already has an extension, 
that name is returned unchanged, so that 
defaultExtension("library.h", ".cpp") 
would ignore the specified extension and return "library.h" unchanged.  If, 
however, ext includes a star before the dot, defaultExtension removes
any existing extension from filename and adds the new one (minus the star).  
Thus, 
defaultExtension("library.h", "*.cpp") 
would return "library.cpp".  Write the code for defaultExtension so 
that it behaves as described in this exercise. */
#include<iostream>
#include<string>

int dotPos(std::string fileName);
std::string defaultExtension(std::string fileName, std::string ext);
int main() {
    std::string file="haha.txt";
    std::string ext="*.cpp";
    std::cout<<defaultExtension(file,ext);
    return 0;
}
std::string defaultExtension(std::string fileName, std::string ext){
    int pos=dotPos(fileName);
    int pos2=dotPos(ext);
    if(ext[0]=='*' || pos==-1){
        if(pos==-1) pos=fileName.size();
        std::string name=fileName.substr(0,pos);
        if(pos2!=0) ext=ext.substr(pos2);
        std::string finalName=name+ext;
        return finalName;
    }
    return fileName;
}

int dotPos(std::string fileName){
    int pos=-1;
    for(int i=0;i<fileName.size();i++){
        if(fileName[i]=='.'){
             pos=i;
             break;
        }
    }
    return pos;
}