#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int data;
        Node * next;

        Node();
        Node (int theData);
        Node ( int theData, Node *theNextNode);


};
#endif