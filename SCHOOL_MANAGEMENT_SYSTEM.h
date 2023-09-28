#ifndef SCHOOL_MANAGEMENT_H
#define SCHOOL_MANAGEMENT_H

#define MAX_SIZE 30

typedef struct Student_t
{

	uint32 ID;
	uint32 phone_number;
	uint8 Name[MAX_SIZE];
	uint8 DateOfBirth[MAX_SIZE];
	uint8 address[MAX_SIZE];
	uint8 number_of_subjects;
	uint8 *score_ptr;
	struct Student_t *next;

} Student_t;

void NEW_STUDENT(Student_t **head);
void STUDENT_LIST(Student_t **head);
void STUDENT_EDIT(Student_t **head);
void DELETE_STUDENT(Student_t **head, uint32 pos);
void STUDENT_SCORE(Student_t *head, uint32 i);
void RANK_STUDENT(Student_t **head);
uint32 NUMBER_OF_STUDENTS(Student_t **head);
void SWAP2NODES(Student_t **head, uint32 x, uint32 y);
#endif