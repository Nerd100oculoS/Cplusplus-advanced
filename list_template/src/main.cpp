#include "../include/list_template.hpp"

int main(){ 

    SimpleList<int> l;

    l.insert(2,0);
    l.insert(3,1);
    l.insert(1,0);
    l.insert(4,3);
    l.insert(5,4);

    l.print();
    l.remove(0);
    l.remove(0);
    int i = l.return_value(0);
    cout << "valor retornado: " << i << endl;
    cout << endl << endl;
    l.print(); 

    return 0;
}