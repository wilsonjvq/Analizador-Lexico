#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

void analizadorLexico(string L){
    int j;
    string Keywords[63] = {
        "auto",         "double",      "int",           "struct",
        "break",        "else",        "long",          "switch",
        "case",         "enum",        "register",      "typedef",
        "char",         "extern",      "return",        "union",
        "const",        "float",       "short",         "unsigned",
        "continue",     "for",         "signed",        "void",
        "default",      "goto",        "sizeof",        "volatile",
        "do",           "if",          "static",        "while",
        "asm",          "bool",        "catch",          "class",
        "const_cast",   "delete",      "dynamic_cast",   "explicit",
        "export",       "false",       "friend",         "inline",
        "mutable",      "namespace",   "new",            "operator",
        "private",      "protected",   "public",         "reinterpret_cast",
        "static_cast",  "template",    "this",           "throw",
        "true",         "try",         "typeid",         "typename",
        "using",        "virtual",     "wchar_t"};

    int Tamanio = L.length();
    int InicioLexema = 0;
    int Avance = 0;
    int Estado = 0;
    char Caracter = ' ';

    while(Avance < Tamanio){//3<11
        Caracter = L[InicioLexema];
        while(Caracter == ' '){
            Avance++;
            InicioLexema++;
            Caracter = L[InicioLexema];
        }

        //Lexema Identificador
        int IdValido = 0;
        Estado = 0;
        while(Estado != 2 && Estado != 3){
            Caracter = L[Avance];
            if(Estado == 0){
                if(isalpha(Caracter) || Caracter == '_'){
                    Estado = 1;
                    Avance++;
                }else{
                    Estado = 3;
                }
            }else if(Estado == 1){
                if(isalpha(Caracter) || Caracter == '_' || isdigit(Caracter)){
                    Avance++;
                }else{
                    Estado = 2;
                    IdValido = 1;
                }
            }
        }
        int KeywordValido = 0;
        if(IdValido){
            for(j = 0; j < 63; j++){
                if(L.substr(InicioLexema, Avance-InicioLexema) == Keywords[j]){
                    KeywordValido = 1;
                }
            }
            if(KeywordValido){
                cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Keyword" << endl;
            }else{
                cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: identificador" << endl;
            }
            InicioLexema = Avance;
        }else{
            Avance = InicioLexema;
        }


        //Lexema Numero Entero
        int NumeroEnteroValido = 0;
        Estado = 0;
        while(Estado != 2 && Estado != 3){
            Caracter = L[Avance];
            if(Estado == 0){
                if(isdigit(Caracter)){
                    Estado = 1;
                    Avance++;
                }else{
                    Estado = 3;
                }
            }else if(Estado == 1){
                if(isdigit(Caracter)){
                    Avance++;
                }else{
                    Estado = 2;
                    NumeroEnteroValido = 1;
                }
            }
        }
        if(NumeroEnteroValido){
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Numero entero" << endl;
            InicioLexema = Avance;
        }else{
            Avance = InicioLexema;
        }

        //Lexema Delimitador
        Caracter = L[Avance];
        if(Caracter == '['){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Corchetes izquierdo" << endl;
            InicioLexema = Avance;
        }else if(Caracter == ']'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Corchetes derecho" << endl;
            InicioLexema = Avance;
        }else if(Caracter == '('){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Parentesis izquierdo" << endl;
            InicioLexema = Avance;
        }else if(Caracter == ')'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Parentesis derecho" << endl;
            InicioLexema = Avance;
        }else if(Caracter == '{'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Llaves izquierdo" << endl;
            InicioLexema = Avance;
        }else if(Caracter == '}'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Llaves derecho" << endl;
            InicioLexema = Avance;
        }else if(Caracter == ','){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Comas" << endl;
            InicioLexema = Avance;
        }else if(Caracter == ';'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Punto y coma" << endl;
            InicioLexema = Avance;
        }else if(Caracter == ':'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Dos puntos" << endl;
            InicioLexema = Avance;
        }
        //Operadores de comparacion
        else if(Caracter == '>'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador mayor" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '<'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador Menor" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '='){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador Igual" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '!'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador Diferente" << endl;
            InicioLexema = Avance;
        }
        //Operadores de aritmeticos
        else if(Caracter == '+'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador suma" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '-'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador resta" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '*'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador producto" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '/'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador division" << endl;
            InicioLexema = Avance;
        }
        else if(Caracter == '%'){
            Avance++;
            cout << "   " << L.substr(InicioLexema, Avance-InicioLexema) << " :: Operador modulo" << endl;
            InicioLexema = Avance;
        }
    }
};

int main() {
    string nombreArchivo = "Codigo.txt";
    ifstream Archivo(nombreArchivo.c_str());
    string Linea;

    int i;
    for(i = 1; getline(Archivo, Linea); i++){
        cout << i << " - " << Linea << endl;
        analizadorLexico(Linea);
    }
    //Imprimir los Keywords
    /*
    for(i = 0; i < 63; i++){
        cout << i << ": " << Keywords[i] << endl;
    }
    */
}
