## School_management_system
School management system with c programming

This repository contains a set of functions for managing student records in a school management system. The functions are implemented in C programming language and provide functionality such as adding new students, displaying student lists, editing student information, entering student scores, ranking students based on scores, and deleting students from the system.

Functions
void NEW_STUDENT(Student_t** head)
This function adds a new student to the system. It prompts the user to enter the student's information such as name, phone number, date of birth, address, and number of subjects. 
It allocates memory for the student and their subject scores, and adds the student to the linked list of students.

void STUDENT_LIST(Student_t** head)
This function displays a list of all students in the system. 
prints their ID, name, phone number, date of birth, address, number of subjects, and subject scores.

void STUDENT_EDIT(Student_t** head)
This function allows the user to edit the information of a specific student. It prompts the user to enter the ID of the student they want to edit and the field they want to modify (address, phone number, or subject scores). It then updates the corresponding field with the new information provided by the user.

void STUDENT_SCORE(Student_t* head, uint32 id)
This function allows the user to enter the scores for the subjects of a specific student. If the ID is provided, it finds the student with the given ID and prompts the user to enter scores for each subject. 
If the ID is 0, it prompts the user to enter scores for all students in the system.

void RANK_STUDENT(Student_t** head)
This function ranks the students based on their scores in a specific subject.
The user needs to enter the subject number, and the function sorts the students in ascending order of their scores in that subject.

uint32 NUMBER_OF_STUDENTS(Student_t** head)
This function returns the total number of students in the system.

void SWAP2NODES(Student_t** head, uint32 X, uint32 Y)
This function swaps the positions of two students in the linked list.

void DELETE_STUDENT(Student_t** head, uint32 pos)
This function deletes a student from the system based on their position in the linked list.
