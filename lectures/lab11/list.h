//list.h
//list is a linear data collection


/* Methods
    insert
    remove(position)
    
*/


#ifndef LIST_H
#define LIST_H

class List {

    private:
    int * elements = nullptr;
    void clear();
    unsigned int elementCount = 0;
    unsigned int arraySize = defal;


    public:
    
    constexpr static unsigned int defal = 5;
    List();
    List(unsigned int arraySize);
    ~List();
    
    int getElementCount() const;
    bool insert(unsigned int position, int newElement);
    bool remove(unsigned int position);
    bool retrieve(unsigned int position, int *retrieveElement) const;
    bool modify(unsigned int position, int newElement);
    void printList() const;

};
#endif