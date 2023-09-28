
#include "STD.h"
#include "SCHOOL_MANAGEMENT_SYSTEM.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Welcome to the School Management System\n");
    printf("---------------------------------------\n");
    printf("You can perform tasks such as adding students and managing their records\n\n");

    Student_t* head = NULL;
    uint8 choice;
	uint32 position;
	
    while (1) {
        printf("Please choose an option from the menu to get started:\n");
        printf("1. Add a new student\n");
        printf("2. Add students scores\n");
        printf("3. Rank students depending on their specific subject\n");
        printf("4. Print all student records\n");
        printf("5. Delete a student record\n");
        printf("6. Print the number of students\n");
		printf("7. Edit  students\n");
        printf("0. Exit the system\n");
        printf("---------------------------------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%hhu", &choice) != 1) {
			
            printf("Invalid input. Please enter a number.\n");
           
            continue;
        }

        switch (choice) {
            case 0:
                printf("\nExiting the system.\n");
                return 0;

            case 1:
                NEW_STUDENT(&head);
                break;

            case 2:
                printf("\n 0- All Students \n");
			    printf(" or  Enter Student ID  \n");
				//getchar();
				scanf("%d",&position);
				STUDENT_SCORE(head,position);
				break;

            case 3:
                RANK_STUDENT(&head);
                break;

            case 4:
                STUDENT_LIST(&head);
                break;

            case 5:
                printf("\n Enter the position : ");
				//getchar();
				scanf("%d",&position);
				DELETE_STUDENT(&head ,position);
				break;

            case 6:
                printf("\nNumber of students: %d\n", NUMBER_OF_STUDENTS(&head));
                break;
			case 7:
			    STUDENT_EDIT(&head);
				break;

            default:
                printf("\nInvalid choice. Please enter a number from the menu.\n");
                break;
        }
		printf("\n");
    }
}