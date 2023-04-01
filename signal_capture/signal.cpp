#include <iostream>
#include <csignal>

using namespace std;

void signalHandler(int signum) {
   cout << "\nPara encerrar, pressione Ctrl + C novamente\n"; 
   signal(SIGINT, SIG_DFL);
}

int main(){

   signal(SIGINT, signalHandler);  
   while(true){}

   return 0;
}