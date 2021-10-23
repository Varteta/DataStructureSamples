#include <stdio.h>

//Implementing Single Linked List

typedef struct _Node Node;
typedef struct _Node
{
	int nData;
	Node* pNext;
};

Node* pFirst = NULL;
Node* pLast = NULL;

void AddNode(int nData)
{
	Node* pNode = new Node;
	pNode->nData = nData;
	pNode->pNext = NULL;


	if (pFirst == NULL)
	{
		pFirst = pNode;
	}
	else
	{
		//pLast should point to new node
		pLast->pNext = pNode;
	}
	pLast = pNode;
}

void Traverse()
{
	Node* pTemp = pFirst;
	while (pTemp)
	{
		printf("\n%d", pTemp->nData);
		pTemp = pTemp->pNext;
	}
}

//Add Node at the beginning
void AddNodeBeg(int nData)
{
	Node* pNode = new Node();
	pNode->pNext = NULL;
	pNode->nData = nData;

	//In case our linked list is empty
	if (pFirst == NULL)
	{
		pFirst = pNode;
		pLast = pNode;
	}
	else
	{
		pNode->pNext = pFirst;
		pFirst = pNode;
	}

}

//To find the node address with a particular data
Node* FindNodeAfter(int nData)
{
	Node* pNode = pFirst;
	while (pNode)
	{
		if (pNode->nData == nData)
		{
			break;
		}
		pNode = pNode->pNext;
	}
	return pNode;
}

//Add node in middle/ after some node
void AddAfter(int nData, int nDataToAdd)
{
	//Find the data node after which I need to add
	//my node
	Node* pNode = FindNodeAfter(nData);
	if (pNode != NULL)
	{
		Node* pNewNode = new Node;
		pNewNode->nData = nDataToAdd;
		pNewNode->pNext = pNode->pNext;
		pNode->pNext = pNewNode;
		printf("\nAdded Successfully");
	}
	else
	{
		printf("\nNot able to find the node");
	}
}

//Add a node before a node
void AddNodeBefore(int nData, int nDataToAdd)
{
	Node* pTempNode = pFirst;
	Node* pAddAfter = NULL;
	bool bAdded = false;
	//Case 1: The node is first node
	if (pFirst->nData == nData)
	{
		AddNodeBeg(nDataToAdd);
		bAdded = true;
	}
	else
	{
		while (pTempNode != NULL && pTempNode->pNext != NULL)
		{
			if (pTempNode->pNext->nData == nData)
			{
				pAddAfter = pTempNode;
				Node* pNewNode = new Node;
				pNewNode->nData = nDataToAdd;
				pNewNode->pNext = pAddAfter->pNext;
				pAddAfter->pNext = pNewNode;

				bAdded = true;
				break;
			}
			pTempNode = pTempNode->pNext;
		}
	}
	if (bAdded != true)
	{
		printf("\nThe node not added");
	}
	else
	{
		printf("\nThe node was added");
	}
}

int main()
{

	//Add node at the last.
	//120
	AddNode(10);
	AddNode(30);
	AddNode(20);
	AddNode(60);
	AddNode(50);

	AddNodeBefore(70, 120);

	printf("\nThe elements in Linked list are:");
	Traverse();
	return 0;
}