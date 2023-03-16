#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

typedef struct person {

	char name[100];
	int age;
	int salary;

}humanBeing;


int humansEqual(humanBeing *person1, humanBeing *person2) {
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;
	return TRUE;
}


int main() {

	humanBeing person1;
	humanBeing person2;

	printf("Input person1's name, age, salary : ");
	scanf("%s", person1.name);
	scanf("%d", &person1.age);
	scanf("%d", &person1.salary);
	printf("Input person2's name, age, salary : ");
	scanf("%s", person2.name);
	scanf("%d", &person2.age);
	scanf("%d", &person2.salary);

	if (humansEqual(&person1, &person2)) {
		printf("The two human beings are the same\n");
	}
	else{
		printf("The two human beings are not the same\n");
	}



	return 0;
}