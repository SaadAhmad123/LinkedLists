#include<iostream>
#include<string>
#include<typeinfo>

template <class T> 
class LinkedList{

	private:

		struct Node{
			T Element;
			Node* next;
		};

		int Lenght;   // Lenght of the list.

		Node* Head;    // Head of the List. First element
		Node*Tail;     // Last Element of the list.
		Node*SeqConductor; // The conductor for getElementSequence function.

	public:
	 LinkedList<T>(){
	 	Lenght = 0;
	 	Head=NULL;
	 	Tail=NULL;
	 	SeqConductor = Head;
	 }

	 int getLenght(){return Lenght;}



	 // Adds the elements to the end of the list.
	 void Add(T element)
	 {

		if(Head == NULL)     // If head is NULL i.e the List is totally empty. Then create a new head.
		{
			Head = new Node;
			Head->next = NULL;
			Head->Element = element;
			Tail = Head;   // Registering the Last element.
			Lenght++;
	 		SeqConductor = Head;
		}
		else              // If the head is not NULL... Then move to the end and Add the element at the tail of the List.
		{
			Node *newNode;
			newNode = new Node;
			newNode->next = NULL;
			newNode->Element = element;
			Tail->next = newNode;
			Tail = newNode;  
			Lenght++;
		}	 	
	 }
	 // End Add function.



	 // This is the function that fetch the elements based on , zero based index.
	 T getElement(int index)
	 {
	 	T found;
	 	if(index > Lenght)
	 	{
	 		throw "\nError. The index is out of range.\n";
	 	}
	 	else
	 	{
	 		Node* conductor;
	 		conductor = Head;
	 		for(int c = 0; c < index; c++)
	 		{
	 			conductor = conductor->next;
	 		}
	 		found = conductor->Element;
	 	}
	 	return found;
	 }
	 // End getElement function.



	 // To get elements in sequence.
	 T getElementsInSequence()
	 {
	   	if(Head==NULL)
	   	{
	   		throw "\nThe list contains no data\n";
	   	}	
	   	else
	   	{
	   		if(SeqConductor == NULL)
	   		{
	   			throw "\nEnd of the List.\n";
	   		}
	   		Node* container;
	   		container = SeqConductor;
	   		SeqConductor = SeqConductor->next;
	   		return container->Element;	
	   	}
	 }	
	 // end getElementsInSequence function.


	 // This function tells if the Sequence has ended or not. Support for getElementInSequence.
	 bool endOfList()
	 {
	 	if(SeqConductor == NULL)
	 	{
	 		return false;
	 	}
	 	else
	 	{
	 		return true;
	 	}
	 }
	 // End endOfList().


	 // Start Clear Buffer function
	 void ClearBuffer()
	 {
	 	SeqConductor = Head;
	 }
	 // End Clear Buffer ();



	 // Function to search for the required element. If the datatype is built-in use their equality operator.
	 // If not... then the user has to define a function of equality comparison.
	 int Search(T element, bool(*equalityComparatorFunction)(T theListElement, T theTargetElement) = NULL)
	 {

	 	if(equalityComparatorFunction == NULL){
	 		if(typeid(Head->Element) == typeid(int) 
	 			||typeid(Head->Element) == typeid(double) 
	 			||typeid(Head->Element) == typeid(std::string) 
	 			||typeid(Head->Element) == typeid(long) 
	 			||typeid(Head->Element) == typeid(bool) 
	 			||typeid(Head->Element) == typeid(char) 
	 			||typeid(Head->Element) == typeid(short) 
	 			||typeid(Head->Element) == typeid(float) 
	 			||typeid(Head->Element) == typeid(wchar_t))
	 		{
		 		int counter = 0;
	 			bool found = false;
	 			Node* dumySeqConductor;
	 			dumySeqConductor = SeqConductor;
	 			SeqConductor = Head;
	 			while(this->endOfList())
	 			{
	 				T theElement = this->getElementsInSequence();
		 			if(theElement == element)
		 			{
	 					found = true;
	 					break;
	 				}
	 				counter++;
	 			}
	 			SeqConductor = dumySeqConductor;
	 			if(!found)
	 			{
	 				return -1;
		 		}
	 			else
	 			{
	 				return counter;
	 			}

	 		}
	 		else
	 		{
	 	 	throw "\nError. The equality comparator function is not defined for the user-defined types.\n";
	 		}
	 	}
	 	else 
	 	{
	 			int counter = 0;
	 			bool found = false;
	 			Node* dumySeqConductor;
	 			dumySeqConductor = SeqConductor;
	 			SeqConductor = Head;
	 			while(this->endOfList())
	 			{
	 				T theElement = this->getElementsInSequence();
		 			if((*equalityComparatorFunction)(theElement, element) == true)
		 			{
	 					found = true;
	 					break;
	 				}
	 				counter++;
	 			}
	 			SeqConductor = dumySeqConductor;
	 			if(!found)
	 			{
	 				return -1;
		 		}
	 			else
	 			{
	 				return counter;
	 			}

	 	}
	 }
	 // End search function.


	 // Function to sort for the list elements. If the datatype is built-in use their comparer operator.
	 // If not... then the user has to define a function of comparison.
	 void Sort(bool (*Comparer)(T thePreviousElement, T theNextElement) = NULL)
	 {
	 	if(Comparer == NULL){
	 		if(typeid(Head->Element) == typeid(int) 
		 		||typeid(Head->Element) == typeid(double) 
		 		||typeid(Head->Element) == typeid(std::string) 
	 			||typeid(Head->Element) == typeid(long) 
	 			||typeid(Head->Element) == typeid(bool) 
	 			||typeid(Head->Element) == typeid(char) 
	 			||typeid(Head->Element) == typeid(short) 
	 			||typeid(Head->Element) == typeid(float) 
	 			||typeid(Head->Element) == typeid(wchar_t) 
	 		)
	 		{
	 			Node* passConductor;
	 			passConductor = Head;
	 			bool AllowBreak = false;
	 			while(passConductor!= NULL)
	 			{
	 				passConductor = passConductor->next;
	 				Node* sortConductor;
	 				sortConductor = Head;
	 				Node* previousNode;
	 				previousNode = NULL;
	 				while (sortConductor != NULL)
	 				{
	 					if(sortConductor == Head)
	 					{}
	 					else
	 					{
	 						if(previousNode->Element > sortConductor->Element)
	 						{
	 							T dumy = previousNode->Element;
	 							previousNode->Element = sortConductor->Element;
	 							sortConductor->Element = dumy;	
	 						}
	 					}
	 					previousNode = sortConductor;
	 					sortConductor = sortConductor->next;
	 				}
	 			}
	 		}
	 		else{
	 			throw "\nError. The comparer function is not defined for user-defined types\n";
	 		}
	 	}
	 	else
	 	{
	 		Node* passConductor;
	 		passConductor = Head;
	 		bool AllowBreak = false;
	 		while(passConductor!= NULL)
	 		{
	 			passConductor = passConductor->next;
	 			Node* sortConductor;
	 			sortConductor = Head;
	 			Node* previousNode;
	 			previousNode = NULL;
				while (sortConductor != NULL)
	 			{
	 				if(sortConductor == Head)
	 				{}
	 				else
	 				{
	 					if((*Comparer)(previousNode->Element, sortConductor->Element) == true)
	 					{
	 						T dumy = previousNode->Element;
							previousNode->Element = sortConductor->Element;
	 						sortConductor->Element = dumy;	
	 					}
	 				}
					previousNode = sortConductor;
	 				sortConductor = sortConductor->next;
	 			}
	 		}	
	 	}
	 }
	 // End Sort function.

	 // The function to insert an element after the specified index
	 void Insert(int index, T element)
	 {
	 	if(Lenght==0 && index == 0)
	 	{
	 		this->Add(element);
	 	}
	 	else if(index > Lenght)
	 	{
	 		throw "\nError. Index out of range.\n";
	 	}
	 	else if(index == Lenght)
	 	{
	 		this->Add(element);
	 	}
	 	else if(index == Lenght-1)
	 	{
	 		this->Add(element);
	 	}
	 	else
	 	{
	 		Node* conductor;
	 		conductor = Head;
	 		for(int c = 0; c < index; c++)
	 		{
	 			conductor = conductor->next;
	 		}
	 		Node* newNode = new Node;
	 		newNode->Element = element;
	 		newNode->next = (conductor->next);
	 		conductor->next = newNode;
	 		Lenght++;
	 	}
	 }
	 // End of insert function
	
	// Function to Replace an element at a specific place from an other.
	void Replace(int index, T element)
	{
		if(Head == NULL)
		{
			throw "\nError. The list is Empty.\n";
		}
		if(index < 0 && index >= this->Lenght)
		{	
			throw "\nError. Index out of range.\n";
		}
		else{
			Node* conductor ;
			conductor = Head;
			if(index == 0)
			{
				Head->Element = element;
			}
			else
			{
				for(int c = 0; c < index; c++)
				{
					conductor = conductor->next;
				}
				conductor->Element = element;
			}
		}
	}
	// End Replace funtion.

	// Function to Swap to elements in the list based on their 0-baed index.
	void Swap(int index1, int index2)
	{
		if(Head == NULL)
		{
			throw "\nError. The list is Empty.\n";
		}
		if(index1 < 0 && index1 >= this->Lenght)
		{
			throw "\nError. Index1 is out of range.\n";	
		}
		if(index2 < 0 && index2 >= this->Lenght)
		{
			throw "\nError. Index2 is out of range.\n";
		}

		T element1 = this->getElement(index1);
		T element2 = this->getElement(index2);

		this->Replace(index1, element2);
		this->Replace(index2, element1);

	}
	// End Swap function.


	// Method to Delete and item based on 0-based index
	void Delete(int index)
	{
		if(Head == NULL)
		{
			throw "\nError. The list is Empty.\n";
		}
		if(index < 0 && index >= Lenght)
		{
			throw "\nError. Index out of range.\n";
		}


		if(index == 0)
		{
			Node* dumy;
			dumy = Head;
			Head = dumy->next;
			dumy->next = NULL;
			SeqConductor = Head;
			delete dumy;

		}
		else{
			Node* conductor;
			conductor = Head;
			Node* backConductor;

			for(int c = 0; c < index; c++)
			{
				backConductor = conductor;
				conductor = conductor->next;
			}
			if(index == Lenght-1)
			{
				backConductor->next = NULL;
				delete conductor;
			}
			else
			{
				backConductor->next = conductor->next;
				conductor->next = NULL;
				delete conductor;
			}
		}

		Lenght--;

	}
	// End delete function.

	 // Just for debugging purpose
	 void DebugPrint()
	 {
	 	if(Head == NULL)
	 	{
	 		std::cout<<"No data";
	 	}
	 	else
	 	{
	 		Node* conductor;
	 		conductor = Head;

	 		while(true)
	 		{
	 			std::cout<<"\nElement = " << conductor->Element;
	 			if(conductor->next==NULL)
	 			{
	 				break;
	 			}
	 			else
	 			{
	 				conductor = conductor->next;
	 			}
	 		}
	 	}
	 }

	 // End Debug printing function

		

};   


// End LinkedList Class.
