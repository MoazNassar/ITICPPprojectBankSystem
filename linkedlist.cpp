

#include<iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
#include"STD_TYPES.h"

#include"LinkedList.h"

Node * Head = NULL; 														//The head of the client list , Global variable.


 void LinkedList_InsertNodeHead(Node * CopyStructNewAccount)                 
 {
	/*Node cereation Dynamic memmory allocation*/
	 Node * Local_PStructFirstNode = (Node*)malloc(sizeof(Node));
	
	/****************************************** Storing the data of the new ACCOUNT **************************************************/
	
	/*Storing the account ID from the user in the node.*/
	 Local_PStructFirstNode -> uint8BankAccountID   	= CopyStructNewAccount -> uint8BankAccountID;
	 //LinkedList_StringStore(CopyStructNewAccount -> uint8BankAccountID, Local_PStructFirstNode -> uint8BankAccountID);
	 
	/*Storing the account Name from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewAccount -> uint8clientFullName, Local_PStructFirstNode -> uint8clientFullName);
	/*Storing the account address from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewAccount -> uint8clientFullAddress, Local_PStructFirstNode -> uint8clientFullAddress);
	/*Storing the client national id from the user in the node.*/
	LinkedList_StringStore(CopyStructNewAccount -> uint8nationalID, Local_PStructFirstNode -> uint8nationalID);
	/*Storing the client age from the user in the node.*/
	 Local_PStructFirstNode -> uint8clientAge = CopyStructNewAccount -> uint8clientAge;
	/*Storing the cluent balance from the user in the node.*/
	 Local_PStructFirstNode -> uint8clientBalance = CopyStructNewAccount -> uint8clientBalance;
	 /*Storing the client password from the user in the node.*/
	 Local_PStructFirstNode -> uint8clientPassword = CopyStructNewAccount -> uint8clientPassword;
	/*Storing the account status from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewAccount -> uint8AccountStatus, Local_PStructFirstNode -> uint8AccountStatus);
	 /*Storing the client guard id from the user in the node.*/
	 LinkedList_StringStore(CopyStructNewAccount -> uint8GuardianNationalID, Local_PStructFirstNode -> uint8GuardianNationalID);
	/*********************************************************************************************************************************/
	/*Making the node to point to the Next Node Already exist and if not exist it will point on NULL*/
	 Local_PStructFirstNode -> NextNode = Head;  
	/*Making the head pointing on the first node*/
	 Head = Local_PStructFirstNode;
 }     


 Node  * LinkedList_ID_Search(uint64 Copy_uint8clientID)
 {
	Node * Local_uint8IDExistance = bankSystem_ID_NOT_EXIST;
	
	/*PTR to struct to Point on the Wanted Node and Initially point on the head*/
	 Node * Local_PStructUnknownNode = Head; 
	
	/*check if the list is empty or not*/
	 if(Head == NULL)
	 {
		Local_uint8IDExistance = bankSystem_ID_NOT_EXIST;
	 }
	 else
	 {
		/*Searching about the Node Position needed*/
		 while((Local_PStructUnknownNode != NULL) && (Local_PStructUnknownNode -> uint8BankAccountID != Copy_uint8clientID))
		 {
			/*Storing the Pointer of the Needed Node*/
			 Local_PStructUnknownNode = Local_PStructUnknownNode -> NextNode;
		 }
		 
		 if(Local_PStructUnknownNode != NULL)
		 {
			/*Return the Pointer of the Needed Node*/
			 Local_uint8IDExistance = Local_PStructUnknownNode;
		 }
		 else
		 {
			/*Return NULL if Not found*/
			 Local_uint8IDExistance = bankSystem_ID_NOT_EXIST;
		 }
	 }
	
	/*Return the Pointer of the Needed Node*/
	 return	Local_uint8IDExistance;
 }



 void LinkedList_StringStore(uint8 * Copy_uint8String, uint8 * Copy_uint8StoringDestination)
 {
	uint16 Local_uint8NameLoopCounter = 0;
	
	for(Local_uint8NameLoopCounter = 0; Local_uint8NameLoopCounter < bankSystem_NAME_SIZE; Local_uint8NameLoopCounter++)
	{
		Copy_uint8StoringDestination[Local_uint8NameLoopCounter] = Copy_uint8String[Local_uint8NameLoopCounter];
	}	
 }


 void LinkedList_StringPrint(uint8 * Copy_uint8String)
 {
	uint16 Local_uint8NameLoopCounter = 0;
	
	/*Printing the client Name char by char.*/
	for(Local_uint8NameLoopCounter = 0; Copy_uint8String[Local_uint8NameLoopCounter] != '\0'; Local_uint8NameLoopCounter++)
	{
		cout<< Copy_uint8String[Local_uint8NameLoopCounter];
	}
 }

 void LinkedList_Traverse()                               
 {
	/*Printing Loop Counter to itterate on the list*/
	 uint16 Local_uint8clientNumber = 1;
	/*PTR to struct point on the current node to print it*/
	 Node * Local_PStructprint = Head;
	
	/*check if the list is empty or not*/
	 if(Local_PStructprint == NULL)
	 {
		/*Printing that the list is empty*/
		 cout<<"The List is empty and No account Records.\n"<<endl;
		return;
	 }
	 else
	 {
		
		/*Printing a Header*/
		cout<<"|************************************** Accounts RECORDS ****************************************|\n";
		
		while(Local_PStructprint != NULL)
	    {
			/******************************************** Printing the data of the accounts ****************************************************/
			
			cout<<"The account Number   :" <<Local_uint8clientNumber<<endl;
			cout<<"Account ID           : " <<Local_PStructprint->uint8BankAccountID<<endl;
			cout<<"Client Name          : ";
			LinkedList_StringPrint(Local_PStructprint -> uint8clientFullName);
			cout<<endl;
			cout<<"client address       : ";
			LinkedList_StringPrint(Local_PStructprint -> uint8clientFullAddress);
			cout<<endl;
			cout<<"client Age           : " <<Local_PStructprint->uint8clientAge ;
			cout<<endl;
			cout<<"client balance       : " <<Local_PStructprint->uint8clientBalance ;
			cout<<endl;
			cout<<"user nationalid      : " <<Local_PStructprint->uint8nationalID;
			cout<<endl;
			cout<<"guard id             : " <<Local_PStructprint->uint8GuardianNationalID ;
			cout<<endl;
			cout<<"account status       : " <<Local_PStructprint->uint8AccountStatus ;
			cout<<endl;
			cout<<"user password        : " <<Local_PStructprint->uint8clientPassword ;
			cout<<endl;
			
			/*Closing the Header*/
			cout<<"|***********************************************************************************************|\n"<<endl;
			 
			/*********************************************************************************************************************************/
			
			/*Making the PTR Point to the Next Node*/
			Local_PStructprint = Local_PStructprint -> NextNode;
			/*Incerement the Loop Counter*/
			Local_uint8clientNumber++;
	    }
		
	 }
 }
