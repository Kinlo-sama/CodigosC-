#include <iostream>
#include <cstring>
#include <dirent.h>
using namespace std;
int main(){
    const char* directorio = "./";  // Especifica la ruta relativa al directorio
    string basura= "y2mate.com -";
    DIR* dir;
    struct dirent* entrada;

    dir = opendir(directorio);

    if (dir) {
        while ((entrada = readdir(dir)) != nullptr) {
            // Ignora las entradas "." y ".."
            if (strcmp(entrada->d_name, ".") != 0 && strcmp(entrada->d_name, "..") != 0) {
                string linea = entrada->d_name;
                if(linea.find(basura) != string::npos){
                    size_t tam = basura.size();
                    string nuevo = linea.substr(tam) + ".mp4";
                    rename(&linea[0],&nuevo[0]);
                }
            }
        }
        closedir(dir);
    }else{
    	cout<<"Error";
    }
}
