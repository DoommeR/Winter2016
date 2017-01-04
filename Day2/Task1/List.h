#pragma once

//#include <optional>

template <typename DataType>
class List {
	struct Node {
		Node* next;
		DataType data;
	} *head;
public:
	
	List(void);
    ~List(void);
	void InsertNode(DataType data, int position);
	void RemoveNode(int position);
	void PrintList(void);
	//std::optional<DataType&> GetElement(size_t position);
};

template <typename DataType>
List<DataType>::List(void)
{
	//head = NULL;
}

template <typename DataType>
List<DataType>::~List(void)
{

}

template <typename DataType>
void List<DataType>::InsertNode(DataType data, int position)
{
	Node *nnode=new Node;
	nnode->data = data;
	nnode->next = head;
	head = nnode;

}

template <typename DataType>
void List<DataType>::RemoveNode(int position)
{

}

template <typename Datatype>
void List<Datatype>::PrintList(void)
{
	Node *tmp = head;

	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}
