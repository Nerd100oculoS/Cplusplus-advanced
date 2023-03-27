#ifndef LIST_TEMPLATE__HPP_
#define LIST_TEMPLATE__HPP_

#include <iostream>


using namespace std;

/**
 * @brief Struct Node
 * 
 * @tparam T dynamic
 */
template<typename T>
struct Node{

    T data;
    Node<T> *_next;
};

/**
 * @brief Class List
 * 
 * @tparam T dynamic
 */
template<class T>
class SimpleList{

    private:
        Node<T> *_root;
        int _size;

    public:

        SimpleList();
        ~SimpleList(){};

        void insert(T value, int position);
        void remove(int position);
        T return_value(int position);
        void print();
};

/**
 * @brief Construct a new Simple List object
 * 
 * @tparam T dynamic
 */
template<class T>
SimpleList<T>::SimpleList(){
    _root = new Node<T>;
    _root->_next = nullptr;
    _size = 0;
}

/**
 * @brief Insert value at any position in Simple List
 * 
 * @tparam T dynamic
 * @param value value inserting
 * @param position position for insertion
 */
template<class T>
void SimpleList<T>::insert(T value, int position){

    if(!(position < 0  || position > _size)){

        Node<T> *node = new Node<T>;
        Node<T> *aux = _root;
        int cont = 0;

        while(cont != position){

            aux = aux->_next;
            cont++;
        }   

        node->data = value;
        node->_next = aux->_next;
        aux->_next = node;
        _size++;

    }else{
        cout << "Posição Inválida!\n\n";
    }
}

/**
 * @brief delete value at selected position on Simple List
 * 
 * @tparam T dynamic 
 * @param position position for remotion
 */
template<class T>
void SimpleList<T>::remove(int position){

    if(!(position < 0  || position > _size)){

        int cont = 0;
        Node<T> *aux_remove = _root;
        Node<T> *aux = nullptr;

        while(cont != position+1){
            aux = aux_remove;
            aux_remove = aux->_next;
            cont++;
        }

        aux->_next = aux_remove->_next;

        delete aux_remove;
    }else{
        cout << "Posição Inválida!\n\n";
    }
}

/**
 * @brief return value at selected position on Simple List
 * 
 * @tparam T dynamic
 * @param position 
 * @return T dynamic
 */
template<class T>
T SimpleList<T>::return_value(int position){

    if(!(position < 0  || position > _size)){

        int cont = 0;
        Node<T> *aux_remove = _root;
        Node<T> *aux = nullptr;

        while(cont != position+1){
            aux = aux_remove;
            aux_remove = aux->_next;
            cont++;
        }

        int value_aux = aux_remove->data;
        aux->_next = aux_remove->_next;

        delete aux_remove;
        return value_aux;
    }else{
        cout << "Posição Inválida!\n\n";
        return T(NULL);
    }
}

/**
 * @brief Print Simple List
 * 
 * @tparam T dynamic
 */
template<class T>
void SimpleList<T>::print(){

    Node<T> *aux = _root->_next;

    while(aux != nullptr){

        cout << aux->data << " ";
        aux = aux->_next;
    }

    cout << endl;
}
#endif