#ifndef URL_HPP
#define URL_HPP

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class URL{
    
    private:
        string esquema, dominio, caminho;
        int porta;

    public:

        URL(){}

        URL(const URL& cc){
            this->esquema = cc.esquema;
            this->dominio = cc.dominio;
            this->porta = cc.porta;
            this->caminho = cc.caminho; 
        }

        URL(string esquema, string dominio, int porta, string caminho){
            this->esquema = esquema;
            this->dominio = dominio;
            this->porta = porta;
            this->caminho = caminho; 
        }

        void set_esquema(string esquema){this->esquema = esquema;}
        void set_dominio(string dominio){this->dominio = dominio;}
        void set_porta(int porta){this->porta = porta;}
        void set_caminho(string caminho){this->caminho = caminho;}

        void print(){
            cout << endl << endl;
            cout << "Esquema: " << get_esquema() << endl;
            cout << "Dominio: " << get_dominio() << endl;
            cout << "Porta: " << get_porta() << endl;
            cout << "Caminho: " << get_caminho() << endl;
        }

        string get_esquema(){return esquema;}
        string get_dominio(){return dominio;}
        int get_porta(){return porta;}
        string get_caminho(){return caminho;}
};

URL operator"" _url(const char* str, size_t len){
    
    cout << endl << str << endl;

    URL aux;
    string url(str);
    stringstream str_url(url);
    char deli = ':';
    string token = ""; // p armazenar

    int cont_ED = 0;

    while(getline(str_url,token, deli)){
        
        ++cont_ED;
        switch(cont_ED){

            case 1:
                aux.set_esquema(token);
            break;

            case 2:
                token.erase(0,2); // elimina as barras (//)
                aux.set_dominio(token);
                deli = '/';
            break;

            case 3:
                aux.set_porta(stoi(token));
                deli = '\0';
            break;

            default:
                aux.set_caminho(token);
            break;
        }
    }

    return aux;
}

#endif