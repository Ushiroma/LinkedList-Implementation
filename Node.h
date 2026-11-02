#ifndef NODE_H
#define NODE_H

class Node {
private:
	int data;
	Node* nextNode;

public:
	Node() {
		data = 0;
		nextNode = nullptr;
	}

	//Mutators
	void setData(int d) {
		data = d;
	}

	void setNextNode(Node* nn) {
		nextNode = nn;
	}

	//Accessors
	int getData() {
		return data;
	}

	Node* getNextNode() {
		return nextNode;
	}

};

#endif // !NODE_H

