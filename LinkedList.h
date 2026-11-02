#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>

class LinkedList {
private:
	Node* head;

    
public:
	//Constructor
	LinkedList() {
		head = nullptr;
	}
//=========================================================================
    //Create linked list
    Node* createList() {
        Node* head = NULL; // Initialize head to empty node pointer
        return head;       // Return the location of the head
    }
//=========================================================================
	//Insert at front of the list
	void insertAtFront(int d) {
        //Allocate memory for temp
		Node* temp = new Node();

		//If memory was allocated successfully then
		if (temp != nullptr) {
			temp->setData(d);
			temp->setNextNode(nullptr);
			if (head == nullptr) {
				head = temp;
			}
			else {
				temp->setNextNode(head);
				head = temp;
			}
		}

		else {
			std::cout << "Memory allocation failed. Unable to insert node." << std::endl;
		}
	}
//=========================================================================
	//Remove from front of the list
    Node removeAtFront() {
        Node removedNode;
        if (!isEmpty()) {
            Node* temp = head;
            removedNode.setData(temp->getData());
            head = head->getNextNode();
            delete temp;
        }
        return removedNode;
    }
//=========================================================================
	//Insert at end of the list
    void insertAtBack(char data) {
        // Declare Temp1, Temp2 as NODE
        Node* temp1 = NULL;
        Node* temp2 = NULL;

        // Allocate memory for Temp1
        temp1 = new Node();

        // If memory was allocated successfully then
        if (temp1 != NULL) {
            // Temp1->Data <- Data
            temp1->setData(data);

            // Temp1->NextNode <- empty node pointer
            temp1->setNextNode(NULL);

            // If Head = empty node pointer
            if (head == NULL) {
                // Head <- Temp1
                head = temp1;
            }
            else {
                // Temp2 <- Head
                temp2 = head;

                // While (Temp2->NextNode <> empty node pointer)
                while (temp2->getNextNode() != NULL) {
                    // Temp2 <- Temp2->NextNode
                    temp2 = temp2->getNextNode();
                }

                // Temp2->NextNode <- Temp1
                temp2->setNextNode(temp1);
            }
        }
        else {
            // Write "Out of memory, unable to insert node"
            std::cout << "Out of memory, unable to insert node" << std::endl;
        }
    }
//=========================================================================
	//Search for a node in the list
    bool searchForNode(char key) {
        // Declare Temp as NODE
        Node* temp;

        // Temp <- Head
        temp = head;

        // While (Temp <> empty node pointer)
        while (temp != NULL) {
            // If Temp->Data = Key
            if (temp->getData() == key) {
                return true;
            }
            // Temp <- Temp->NextNode
            temp = temp->getNextNode();
        }

        // Return false
        return false;
    }
//=========================================================================
	//Count the number of nodes in the list
    int countNodes() {
        // Declare Temp as NODE
        Node* temp;

        // Declare Count as integer
        int count;

        // Temp <- Head
        temp = head;

        // Count <- 0
        count = 0;

        // While (Temp <> empty node pointer)
        while (temp != NULL) {
            // Increment Count
            count++;

            // Temp <- Temp->NextNode
            temp = temp->getNextNode();
        }

        // Return Count
        return count;
    }
//=========================================================================
	//Check if the list is empty
    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
//=========================================================================
	//Display the list
	void displayList() {
		// Declare Temp as NODE
		Node* temp;
		// Temp <- Head
		temp = head;
		// While (Temp <> empty node pointer)
		while (temp != NULL) {
			// Write Temp->Data
			std::cout << temp->getData() << " ";
			// Temp <- Temp->NextNode
			temp = temp->getNextNode();
		}
		std::cout << std::endl;
	}
//=========================================================================
	//Destroy the list
    void destroyList() {
        // Declare Temp as NODE
        Node* temp;

        // While (Head <> empty node pointer)
        while (head != NULL) {
            // Temp <- Head
            temp = head;

            // Head <- Head->NextNode
            head = head->getNextNode();

            // Deallocate Temp
            delete temp;
        }
    }

};

#endif // !LINKEDLIST
