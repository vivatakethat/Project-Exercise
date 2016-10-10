/* Maintains a parts database (array version) */
#include<stdio.h>
#include"readline.h" 

#define NAME_LEN 25
#define MAX_PARTS   100

struct part {
	int number;			/*���*/
	char name[NAME_LEN + 1];	/*����*/
	int on_hand;			/*�ֻ�����*/
}inventory[MAX_PARTS];

int num_parts = 0;	/*		number of parts currently stored			*/

int  find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/****************************************************************
* main:Prompts the user to enter an operation code,				*
*		then calls a function to perform the requested			*
*		action.Repeats until the user enters the				*
*		command 'q'.Prints an error message if the user			*
*		enters an illegal code									*
****************************************************************/


int main(void)
{
	char code;

	for (;;) {
		printf("Enter operation code:");
		scanf(" %c", &code);
		while (getchar() != '\n');	/*skips to end of line*/
		switch (code) {
		case 'i':insert();
			break;
		case 's':search();
			break;
		case 'u':update();
			break;
		case 'p':print();
			break;
		case 'q':return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

/****************************************************************************
*	find_part:Looks up apart number in the inventory						*
*				array.Returns the array index if the part					*
*				number is found;otherwise,returns -1.						*
****************************************************************************/

int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;
	return -1;
}

/********************************************************************
*	insert:Prompts the user for information about a new				*
*			part and then inserts the part into the					*
*			database.Prints an error message and returns			*
*			Prematurely if the part already exists or the			*
*			database is full.										*
********************************************************************/

void insert(void)
{
	int part_number;

	if (num_parts == MAX_PARTS) {				/*	num_parts�ǵ�ǰ�������,�ж�num_parts�Ƿ񳬳�����	*/
		printf("Database is full;can't add more parts.\n");
		return;
	}

	printf("Enter part number:");
	scanf("%d", &part_number);					 /*		part_number ���		*/

	if (find_part(part_number) >= 0) {			/*	��part_number��Ϊ��������find_part����ȥ����Ƿ�����ͬ�Ĳ���		*/
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;		/*��ʽ	�����д�� inventory������  */
	printf("Enter part name:");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand:");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

/********************************************************************
*	search:Prompts(Ѹ��,׼ȷ) the user to enter apart number,the		*
*			looks up the part in the database.IF the part			*
*			exists,prints the name and quantity on hand;			*
*			if not,prints an error message.							*
********************************************************************/

void search(void)
{
	int i, number;

	printf("Enter part number:");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

/*******************************************************************
*	update: Prompts the user to enter a part number.				*
*			Prints an error message if the part doesn't				*
*			exist; otherwise,Prompts the user to ednter				*
*			change in quantity on hand and uptates the              *
*			database.												*
********************************************************************/

void update(void)
{
	int i, number, change;

	printf("Enter part number:");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand:");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}


/*********************************************************************
*	Print:Prints alisting of all parts in the database,				 *
*			showing the part number,part name,and				     *
*			quantity on hand.Parts are printed in the				 *
*			order in which the were entered int the database.		 *
*********************************************************************/

void print(void)
{
	int i;

	printf("Part Number Part Name			"
		"Quantityh on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d    %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}
