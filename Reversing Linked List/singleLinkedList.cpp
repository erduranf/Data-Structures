//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999 

#include <iostream>
#include <conio.h>


using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();                            //Default constructor 
	linkedListIterator(nodeType<Type> *ptr);       //Constructor with a parameter. 
	Type operator*();                              //Function to overload the dereferencing operator *. 
	linkedListIterator<Type> operator++();          //Overload the pre-increment operator. 
	bool operator==(const linkedListIterator<Type>& right) const;       //Overload the equality operator. 
	bool operator!=(const linkedListIterator<Type>& right) const;        //Overload the not equal to operator. 

private:
	nodeType<Type> *current; //pointer to point to the current  
							 //node in the linked list 
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
	current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;

	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}


//*****************  class linkedListType   **************** 

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator= (const linkedListType<Type>&);   //Overload the assignment operator. 

	void initializeList();        //Initialize the list to an empty state. 
	bool isEmptyList() const;     //Function to determine whether the list is empty.  
	void print() const;           //Function to output the data contained in each node. 
	int length() const;           //Function to return the number of nodes in the list. 
	void destroyList();            //Function to delete all the nodes from the list. 
	Type front() const;            //Function to return the first element of the list. 
	Type back() const;            //Function to return the last element of the list. 
	bool search(const Type& searchItem) const;     //Function to determine whether searchItem is in the list. 
	void insertFirst(const Type& newItem);         //Function to insert newItem at the beginning of the list. 
	void insertLast(const Type& newItem);          //Function to insert newItem at the end of the list. 
	void deleteNode(const Type& deleteItem);       //Function to delete deleteItem from the list. 
	linkedListIterator<Type> begin();              //Function to return an iterator at the begining of the  
	linkedListIterator<Type> end();                //Function to return an iterator one element past the  
	linkedListType();                              //default constructor 
	linkedListType(const linkedListType<Type>& otherList);   //copy constructor 
	~linkedListType();        //destructor 
	void reverseList();     //makes list in reverse order

protected:
	int count;   //variable to store the number of  
	nodeType<Type> *first; //pointer to the first node of the list 
	nodeType<Type> *last;  //pointer to the last node of the list 

private:
	void copyList(const linkedListType<Type>& otherList);  //Function to make a copy of otherList. 

};


template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return(first == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType() //default constructor 
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory 
							//occupied by the node 
	while (first != NULL)   //while there are nodes in the list 
	{
		temp = first;        //set temp to the current node 
		first = first->link; //advance first to the next node 
		delete temp;   //deallocate the memory occupied by temp 
	}
	last = NULL; //initialize last to NULL; first has already 
				 //been set to NULL by the while loop 
	count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them 
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list 

	current = first;    //set current so that it points to  
						//the first node 
	while (current != NULL) //while more data to print 
	{
		cout << current->info << " ";
		current = current->link;
	}
}//end print 

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}  //end length 

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != NULL);

	return first->info; //return the info of the first node   
}//end front 

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != NULL);

	return last->info; //return the info of the last node     
}//end back 

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);

	return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(NULL);

	return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node 
	nodeType<Type> *current; //pointer to traverse the list 

	if (first != NULL) //if the list is nonempty, make it empty 
		destroyList();

	if (otherList.first == NULL) //otherList is empty 
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the  
								   //list to be copied 
		count = otherList.count;

		//copy the first node 
		first = new nodeType<Type>;  //create the node 

		first->info = current->info; //copy the info 
		first->link = NULL;        //set the link field of  
								   //the node to NULL 
		last = first;              //make last point to the 
								   //first node 
		current = current->link;     //make current point to 
									 //the next node 

									 //copy the remaining list 
		while (current != NULL)
		{
			newNode = new nodeType<Type>;  //create a node 
			newNode->info = current->info; //copy the info 
			newNode->link = NULL;       //set the link of  
										//newNode to NULL 
			last->link = newNode;  //attach newNode after last 
			last = newNode;        //make last point to 
								   //the actual last node 
			current = current->link;   //make current point  
									   //to the next node 
		}//end while 
	}//end else 
}//end copyList 



template <class Type>
linkedListType<Type>::~linkedListType() //destructor 
{
	destroyList();
}//end destructor 

template <class Type>
linkedListType<Type>::linkedListType
(const linkedListType<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}//end copy constructor 


 //overload the assignment operator 
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy 
	{
		copyList(otherList);
	}//end else 

	return *this;
}

template <class Type>
bool linkedListType<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list 
	bool found = false;

	current = first; //set current to point to the first  
					 //node in the list 

	while (current != NULL && !found)    //search the list 
		if (current->info == searchItem) //searchItem is found 
			found = true;
		else
			current = current->link; //make current point to 
									 //the next node 
	return found;
}//end search 

template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node 

	newNode = new nodeType<Type>; //create the new node 

	newNode->info = newItem;    //store the new item in the node 
	newNode->link = first;      //insert newNode before first 
	first = newNode;            //make first point to the 
								//actual first node 
	count++;                    //increment count 

	if (last == NULL)   //if the list was empty, newNode is also  
						//the last node in the list 
		last = newNode;
}//end insertFirst 

template <class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node 

	newNode = new nodeType<Type>; //create the new node 

	newNode->info = newItem;  //store the new item in the node 
	newNode->link = NULL;     //set the link field of newNode 
							  //to NULL 

	if (first == NULL)  //if the list is empty, newNode is  
						//both the first and last node 
	{
		first = newNode;
		last = newNode;
		count++;        //increment count 
	}
	else    //the list is not empty, insert newNode after last 
	{
		last->link = newNode; //insert newNode after last 
		last = newNode; //make last point to the actual  
						//last node in the list 
		count++;        //increment count 
	}
}//end insertLast 


template <class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list 
	nodeType<Type> *trailCurrent; //pointer just before current 
	bool found;

	if (first == NULL)    //Case 1; the list is empty.  
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		if (first->info == deleteItem) //Case 2  
		{
			current = first;
			first = first->link;
			count--;
			if (first == NULL)    //the list has only one node 
				last = NULL;
			delete current;
		}
		else //search the list for the node with the given info 
		{
			found = false;
			trailCurrent = first;  //set trailCurrent to point 
								   //to the first node 
			current = first->link; //set current to point to  
								   //the second node 

			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}//end while 

			if (found) //Case 3; if found, delete the node 
			{
				trailCurrent->link = current->link;
				count--;

				if (last == current)   //node to be deleted  
									   //was the last node 
					last = trailCurrent; //update the value  
										 //of last 
				delete current;  //delete the node from the list 
			}
			else
				cout << "The item to be deleted is not in "
				<< "the list." << endl;
		}//end else 
	}//end else 
}//end deleteNode 

template <class Type>
void linkedListType<Type>::reverseList()
{
	nodeType<Type> *trail = NULL, *cur = NULL, *lead = NULL;
	cur = first;	//current points to the first node
	last = first;	//last points to the first node
	while (cur != NULL)
	{
		lead = cur->link;	//lead points to the node after current
		cur->link = trail;	//current points to the node before itself
		trail = cur;	//trail is moved forward by one
		cur = lead;		//current is moved forward by one
	}	//end of the list, current is NULL, trail points to the last node
	first = trail;	//the last node becomes the first
}//end reverseList


int main()
{
	int i = 0;
	linkedListType<int> List1;
	List1.initializeList();
	cout << "Enter integers ending with -999" << endl;
	while (1) 
	{
		cin >> i;
		if (i != -999)
			List1.insertLast(i);
		else break;
	}
	cout << endl << endl << "List1: " << endl;
	List1.print();
	List1.reverseList();
	cout << endl << "List1: (reverse order) " << endl;
	List1.print();
	cout << endl;

	return 0;
}
