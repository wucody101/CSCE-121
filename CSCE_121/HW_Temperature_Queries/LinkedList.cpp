# include <iostream>
# include <string>
# include "LinkedList.h"
# include "Node.h"
# include <sstream>

using std::string, std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) /* TODO */ {
	// TODO: implement this function
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr)/* TODO */ {
	// TODO: implement this function
	Node* current = source.head;
	while (current != nullptr) {
		Node* ptr = new Node(current->data.id, current->data.year, current->data.month, current->data.temperature);
		if (head == nullptr) {
			head = ptr;
			tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
		current = current->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if (this != &source) {
		clear();
		Node* current = source.head;
		while (current != nullptr) {
			Node* ptr = new Node(current->data.id, current->data.year, current->data.month, current->data.temperature);
			if (head == nullptr) {
				head = ptr;
				tail = ptr;
			}
			else {
				tail->next = ptr;
				tail = ptr;
			}
			current = current->next;
		}
	}

	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	Node* enter = new Node(location, year, month, temperature);

	//empty list
	if (head == nullptr) { 
		head = enter;
		tail = enter;
	}

	else {
		Node* current = head;
		Node* previous = current;
		
		while (current != nullptr) {
			if (enter->data.id < current->data.id) {
				//std::cout << enter->data.id << " " << current->data.id;
				break;
			}
			
			if (current->data.id == enter->data.id && enter->data.year < current->data.year) {
				break;
			}

			if (current->data.year == enter->data.year && enter->data.month <= current->data.month) {
				break;
			}

			previous = current;
			current = current->next;
		}

		if (current == head) {
			enter->next = head;
			head = enter;
		}
		else {
			enter->next = current;
			previous->next = enter;
		}

	}

}	
	

void LinkedList::clear() {
	// TODO: implement this function
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;

	// TODO: implement this function
	Node* current = head;
	outputString = "";
	std::ostringstream output;
	while (current != nullptr) {
		output << current->data.id;
		output << " ";
		output << current->data.year;
		output << " ";
		output << current->data.month;
		output << " ";
		output << current->data.temperature;
		output << "\n";
		outputString = output.str();
		current = current->next;
	}
	
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
