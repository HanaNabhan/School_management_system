#include "STD.h"
#include "SCHOOL_MANAGEMENT_SYSTEM.h"
#include<stdlib.h>
#include<stdio.h>


void NEW_STUDENT(Student_t** head ){
	static uint32 student_id = 1;
	printf("\nStudent id number : %d\n\n",student_id);
	// allocate memory for the student in heap and return pointer point to the block reserved
	Student_t* s= (Student_t* )malloc(sizeof(Student_t));
	// if there is a memory reserved 
	if(s !=NULL){
 
	// enter the data of each student
	printf(" Enter name : ");
	getchar();
	// string doesn't need & cause the array point to itself 
	fgets(s->Name, MAX_SIZE, stdin);
	printf("\n Enter phone : ");
	scanf("%d",&s->phone_number);
	getchar();  // Consume newline character
	/*printf("\n Enter ID : ");
	scanf("%d",&s->ID);*/
	s->ID=student_id;
	student_id++;
	printf("\n Enter date of birth : ");
	fgets(s->DateOfBirth,MAX_SIZE, stdin);
	printf("\n Enter Address: ");
	fgets(s->address,MAX_SIZE, stdin);
	printf("\n Enter Number Of Subjects : ");
	/* using %hhu format specifier instead of %c cause %c it will read ascii not the value*/
	scanf("%hhu",&s->number_of_subjects);
	getchar();
	printf("\n");
	
	
	/*allocate memory for the subjects score array in heap and return pointer point to the blocks reserved for subjects */
	s->score_ptr=(uint8 *)calloc(s->number_of_subjects ,sizeof(uint8));
	/* if there is no memory reserved*/
	if(s->score_ptr==NULL){
		 printf("No memory\n");
		 free(s->Name);
         free(s->DateOfBirth);
         free(s->address);
         free(s);
		s=NULL;
		return;
	
	}
	
	else{
		//nothing
	}
	
	// s is the last node
	s->next=NULL;
	//check if it is the first element
	if(*head==NULL){
		//make head points to the element
		*head=s;
		
	}else{
		//loop in the list to find the last element before the new s
		  Student_t* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
			// assign the next pointer to point to new s
            current->next = s;

	}
	
	
	}
	/* if there isn't memory print there is no memory*/
	else{
		printf("No memory\n");
	}
	
	
}
void STUDENT_LIST(Student_t ** head){
	printf(" \t\t\t List of Student\n ////////////////////////////////\n");
	//printf all student data
	Student_t *it=NULL;
	it=*head;
	uint8 i;
	while(it!=NULL){
	printf("\n ID : %d \n",it->ID);
		
	printf(" name : %s\n",it->Name);
	
	printf("\n phone Number : %d\n",it->phone_number);
	
	
	printf("\n DateOfBirth : %s \n ",it->DateOfBirth);
	
	printf("\n Address: %s\n \n",it->address);
	
	printf("\n Number Of Subjects  : %hhu\n \n",it->number_of_subjects);
	
	
     	for(i=0 ;i<it->number_of_subjects;i++){
			printf(" score of subject %d  : %hhu \n",i+1,it->score_ptr[i]);
			
		}
		
	it = it -> next;
	}
}

void  STUDENT_EDIT(Student_t ** head){
	
	if(*head !=NULL){
		// accesss the student data with their id 
	uint32 id_it;
	printf("Enter ID  \n");
	scanf("%d",&id_it);
	if(id_it>NUMBER_OF_STUDENTS(head)){
		
		
		printf("\n the ID is WRONG !!\n");
		return ;
	}
	
	// loop to find the specific student
	Student_t *it=NULL;
	it=*head;
	while(it->ID!=id_it){
		it=it->next;
	}
	// enter the number to access the data to be changed
	printf("Enter 1 to Edit Address \n");
	printf("Enter 2 to Edit phone Number \n");
	printf("Enter 3 to Edit subject score \n");
	Student_t * ptr =NULL;
	
	uint8 x , i;
	
	scanf("%d",&x);
	
	ptr=it;
	
	switch(x){
		
		case 1 :
		
			printf("\n Enter New Address: ");
			getchar();
			
			fgets(it->address,MAX_SIZE, stdin);
			
			printf("\n Address is Edited \n ");
			
			break;
		case 2 :
		
			printf("\n Enter phone Number: ");
			
			scanf("%d",&it->phone_number);
			
			printf("\n phone Number is Edited \n");
			
			break;
		case 3 :
		
			printf("\n Enter number of subject: ");
			
			scanf("%d",&i);
			
			printf("\n New Score :  ");
			
			scanf("%hhu",&it->score_ptr[i-1]);
			
			printf("\n Score Changed!!\n");
			
			break;
		default:
		
			printf("\n No Change \n");
			
			break;
			
	}
	}
	else{
		printf("No memory\n");
	}

	
}
void  STUDENT_SCORE(Student_t *head,uint32 id) {
	if(head !=NULL){
	Student_t *it=NULL;
	it=head;
	if(id==0){
	while(it!=NULL){
		printf("\n Student ID %d\n",it->ID);
	if(it->score_ptr!=NULL){
		uint8 i;
		// enter each subject score
     	for(i=0 ;i<(it->number_of_subjects);i++){
			printf("enter score of subject %d  :  ",i+1);
			scanf("%hhu",&it->score_ptr[i]);
			
		}
	
	}
	else{
		
		
		printf("No memory\n");
	}
	it=it->next;
	}}
	
	else{
		it=head;
		while(it->ID !=id){
			
			it=it->next;
		
		}
		if(it==NULL){
			printf("WRONG ID !!");
			return ;
		}
		 printf("\n Student ID %d\n",it->ID);
		 
		 uint8 i;
		// enter each subject score
     	 for(i=0 ;i<(it->number_of_subjects);i++){
			printf("enter score of subject %d :  ",i+1);
			scanf("%hhu",&it->score_ptr[i]);
	}}
	
	}
	else{
		printf("No memory\n");
	}
}

void RANK_STUDENT(Student_t ** head){
	 uint8 x=0;
	 
	 if(*head !=NULL){
		 
		printf("\n Enter the subject to Rank : ");
		scanf("%d",&x);
		uint32 i,j; 
	    uint8 flag = 1;
		uint32 size= NUMBER_OF_STUDENTS(head);
		//printf("\n%d",size);
		Student_t *last=NULL,*stop=NULL,*temp=NULL;
		
		last=*head;
	     for (i = 0; i < size - 1; i++) {
 
          last=*head;
		  flag=1;
       
 
        for (j = 0; j < size - i - 1; j++) {
			
 
			stop=last->next;
 
            if (last->score_ptr[x-1] > stop->score_ptr[x-1]) {
				
				
				SWAP2NODES(head , j , j+1);
 
				
                flag = 0;
            }
 
            last=last->next;
        }
		if(flag == 1){
			
			break;
			
		}
	}

	 }
	else{
		printf("No memory\n");
	}
}

uint32 NUMBER_OF_STUDENTS(Student_t ** head){
	uint32 i=0;
	if(*head !=NULL){
		Student_t *it=NULL;
	    it=*head;
		
		while(it!=NULL){
			it=it->next;
			i++;
	
	    }
	 
	 }
	else{
		printf("No memory\n");
	}
	return i;
	
}
void SWAP2NODES(Student_t ** head , uint32 X, uint32 Y){
	
	Student_t *x=NULL , *xprev=NULL ,*y=NULL,*yprev=NULL,*temp =NULL;
	
	uint32 i =0 ;
	x=*head;
	while(i<X &&x != NULL){
		xprev=x;
		x=x->next;
		i++;	
	}
	i =0 ;
	y=*head;
	while(y != NULL && i < Y){
		yprev=y;
		y=y->next;
		i++;
	}
	if(x==NULL || y==NULL){
		return ; 
	}
	if(xprev !=NULL){
		xprev->next=y;
	}
	else{
		*head=y;
	}
	if(yprev !=NULL){
		yprev->next=x;
	}
	else{
		*head= x;
	}
	
	temp=y->next;
	y->next=x->next;
	x->next=temp;
	
	
	
	
}

 void DELETE_STUDENT(Student_t **head , uint32 pos){
	 
	 if(head !=NULL){
		 
		 
		Student_t *temp = *head;
		if (pos == 1) {
            *head = (*head)->next;
            free(temp->score_ptr);
            free(temp);
            printf("Student at position %d deleted\n", pos);
            return;
        }
	 
		Student_t * it =NULL ;

		it=*head;
		temp=it->next;
		uint32 i = 1 ;
		while(it!=NULL && i<pos){
			temp=it;
			it=it->next;
			i++;
		}
		if (it == NULL) {
            printf("Position %d exceeds the number of students\n", pos);
            return;
        }
		temp->next=it->next;
		free(it->score_ptr);
		free(it);

	 }
	else{
		printf("No memory\n");
	}
 }