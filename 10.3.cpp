#include <iostream>
using namespace std;

template <typename T>
class element{
  private:
    element* left;
    T data;
    element* right;
  public:
    element(T d = T(), element* nr = nullptr, element* nl = nullptr){
        data = d;
        right = nr;
        left = nl;
    }
    element(const element& other){
        this->data = other.data;
        this->left = other.left;
        this->right = other.right;
    }
    ~element(){
        //set_left_element(nullptr);
        //set_right_element(nullptr);
        ;
    }
    T get_data(){
        return data;
    }
    void set_data(T d){
        data = d;
    }
    element* get_right_element(){
        return right;
    }
    element* get_left_element(){
        return left;
    }
    void set_right_element(element* el){
        right = el;
    }
    void set_left_element(element* el){
        left = el;
    }
};

template <typename T>
class MyBinaryTree{
  private:
    element<T>* base;
    int count;
  public:
    MyBinaryTree(element<T>* nb = nullptr){
        base = nb;
        count = 0;
    }
    MyBinaryTree(const MyBinaryTree& other){
        this->base = other.base;
        this->count = other.count;
    }
    ~MyBinaryTree(){
        remove(base);
    }
    void print(){
        if(base == nullptr){
            return;
        }
        else{
            print(base);
        }
    }
    void print(element<T>* el){
        if(el != nullptr){
            print(el->get_left_element());
            cout << el->get_data() << " ";
            print(el->get_right_element());
        }
    }
    void remove(element<T>* el){
        if(el != nullptr){
            remove(el->get_left_element());
            remove(el->get_right_element());
            delete el;
            count--;
        }
    }
    void push(T data){
        if(base == nullptr){
            base = new element<T>(data);
            count = 1;
        }
        else{
            push(data, base);
        }
    }
    void push(T data, element<T>* el){
        if(data == el->get_data()){
            cout << "This element is already in tree" << endl;
        }
        else if(data < el->get_data()){
            if(el->get_left_element() == nullptr){
                element<T>* new_el = new element<T>(data);
                el->set_left_element(new_el);
            }
            else{
                push(data, el->get_left_element());
            }
        }
        else if(data > el->get_data()){
            if(el->get_right_element() == nullptr){
                element<T>* new_el = new element<T>(data);
                el->set_right_element(new_el);
            }
            else{
                push(data, el->get_right_element());
            }
        }

    }
};


int main(){
    MyBinaryTree<double> tree1;
    tree1.push(100.15);
    tree1.push(17.89);
    tree1.push(150.34);
    tree1.push(222.22);
    tree1.push(18.18);
    tree1.push(1.09);
    tree1.print();
    return 0;
}