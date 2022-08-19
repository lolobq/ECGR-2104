#include <iostream>

using namespace std;

//Node structure
template<typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Doubly Linked List class
template<typename T>
class DoublyLinkedList{
    //Private member variables
    private:
    Node<T>* head;
    Node<T>* tail;
    unsigned int numElements; //Unsigned int to ensure that there's only ever a positive number of elements
    
    //Public member variables and functions
    public:
    
    //Constructor:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    }
    
    //Copy Constructor:
    DoublyLinkedList(const DoublyLinkedList& objToCopy){
        cout << "Copy Constructor called" << endl;
        head = nullptr;
        tail = nullptr;
        numElements = 0;
        for(int i = 0; i < objToCopy.size(); i++){
            push(objToCopy.at(i));
        }
    }
    
    //Destructor:
    ~DoublyLinkedList(){
        cout << "Destructor called!" << endl;
        while(size() > 0){
            pop();
        }
    }
    
    //Copy Assignment Override:
    void operator=(const DoublyLinkedList& objToCopy){
        cout << "Copy assignment override called!" << endl;
        while(size() > 0){
            pop();
        }
        
        for(int i = 0; i < objToCopy.size(); i++){
            push(objToCopy.at(i));
        }
    }
    
    //Push: appends a new node to the end of the list
    void push(T data){
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        
        //Add one element if the list is empty -> make it the same for head and tail
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
        numElements++;
    }
    
    //Pop: removes the last node of the list
    void pop(){
        //Empty list
        if(head == nullptr)
        {
            return;
        }
        else{
            Node<T>* previous = tail->prev;
            
            if(previous != nullptr)
            {
                tail->prev->next = nullptr;
            }
            
            tail->prev = nullptr;
            delete tail;
            tail = previous;
        }
        
        numElements--;
    }
    
    //Size: return the size of the list
    int size() const{
        return numElements;
    }
    
    //Print: prints all the elements in the list to the console
    void print(){
        Node<T>* tempNode = head;
        
        for(int index = 0; index < size(); index++){
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }
    
    //At: returns a reference to the data at the requested index
    T& at(int idx) const{
        int currentIndex = 0;
        Node<T>* currentNode = head;
        
        while(currentIndex < idx){
            currentIndex++;
            currentNode = currentNode->next;
        }
        
        return currentNode->data;
    }
    
    //Insert: inserts a new node containing specified data at a specified position
    void insert(T data, int pos){
        if(pos > size()){
            cout << "That is not a valid index please try again." << endl;
            return;
        }
        
        Node<T>* tempNode = new Node<T>;
        tempNode->data = data;
        tempNode->next = nullptr;
        
        //Inserts at the front of the list
        if(pos == 0){
            tempNode->next = head;
            head->prev = tempNode;
            head = tempNode;
        }
        //Inserts at the end of the list
        else if(pos == size()){
            tail->next = tempNode;
            tempNode->prev = tail;
            tail = tempNode;
        }
        else{
            Node<T>* currentNode = head;
            for(int i = 0; i < pos; ++i){
                currentNode = currentNode->next;
            }
            tempNode->prev = currentNode;
            tempNode->next = currentNode->next;
            tempNode->prev->next = tempNode;
            currentNode->next = tempNode;
        }
        
        numElements++;
    }
    
    //Remove: removes an element at the specified position
    void remove(int pos){
        //Trying to remove from an invalid index
        if(pos > size()){
            cout << "That is not a valid index please try again." << endl;
            return;
        }
        
        //Trying to remove from empty list
        if(head == nullptr)
            return;
            
        //Trying to delete the last element
        if(pos == size() - 1){
            pop();
            return;
        }
        
        //Trying to delete the head
        if(pos == 0){
            Node<T>* nextNode = head->next;
            
            if(nextNode->next != nullptr)
                nextNode->prev = nullptr;
                
            delete head;
            head = nextNode;
            numElements--;
            return;
        }
        else{
            //Any other case
            Node<T>* currentNode = head;
            for(int i = 0; i < pos; i++){
                currentNode = currentNode->next;
            }
            
            Node<T>* nextNode = currentNode->next;
            Node<T>* prevNode = currentNode->prev;
            nextNode->prev = prevNode;
            prevNode->next = nextNode;

            currentNode->next = nullptr;
            currentNode->prev = nullptr;
            delete currentNode;
            currentNode = nullptr;
            
            numElements--;
        }
    }
    
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Test the doubly linked list code
void test(){
    DoublyLinkedList<int> dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList<int> dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);
    
    dll.print();
    dllCopy.print();
    
    dll = dllCopy;
    dll.print();
}

int main(){
    test();
    
    return 0;
}