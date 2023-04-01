#include<iostream>
#include<chrono>
#include<random>
#include<cstdlib>
#include<iomanip>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    // DEFAULT
    int x = 1, cont = 0, a = 0, b = 1, N = 4;
    int timestamp = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    bool num_ints = false;
     
    for(int i = 1; i < argc; i++){
        string aux(argv[i]);
        // cout << aux << endl;
        if(aux == "-i"){
            num_ints = true; // gera numeros inteiros
            N = 0;
        }else if(aux == "-n"){
            x = atoi(argv[i+1]); // quantidade de numeros pseudoaleatorios gerados
        }else if(aux == "-r"){
            a = atoi(argv[i+1]); // intervalor de [a,b]
            b = atoi(argv[i+2]);
        }else if(aux == "-p"){
            N = atoi(argv[i+1]); // num de casas decimais
        }else if(aux == "-s"){
            timestamp = atoi(argv[i+1]); // seed;
        }
    }

    default_random_engine seed(timestamp);
    if(num_ints){
        uniform_int_distribution<int> dist(a,b);
        while(cont != x){    
            cout << dist(seed) << " ";
            cont++;
        }
        cout << endl;
    }else{
        uniform_real_distribution<double> dist(a,b);
        while(cont != x){
            cout << fixed << setprecision(N) << dist(seed) << " ";
            cont++;
        }
        cout << endl;
    }
    return 0;
}