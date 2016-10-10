#include<stdio.h>
#include <ctype.h>
#define MAX_NUMBER 100
#define LEN 20

int mark = 0;

void insert(void);
void show(void);
void read_part_name(char str[], int n);
int find_part_number(int);
void print(void);
void update(void);


struct part {
	int number;
	char name[LEN + 1];
	int on_hand;
}inventory[MAX_NUMBER];


int main(void)
{
	char choice, take;
	for (;;) {
		printf("Please input button :\n");
		scanf(" %c", &choice);			//�ո��scanf(" %c")��ʾҪ���������������������ַ���һ�����ո�һ����%c��Ϊʲô�ӿո���
										//������Ϊ�س���(\n)Ҳ���������������У����Խ�\n��ֵ���ո�����%c����ȷ��ֵ�����򣬲��ӿո񣬻س���\n�ᱻ��ֵ��%c��
		while ((take = getchar()) != '\n');  //	ȥ��'\n'???????
		switch (choice)
		{
		case 'i':insert(); break;
		case 's':show(); break;
		case 'p':print(); break;
		case 'u':update(); break;
		case 'q':return 0;
		default: printf("Illegal code\n");
		}
		printf("\n");
	}
}


void insert(void)
{
	int part_number, take;

	if (mark == 100)					//�����������Ƿ�100����100���޷�����
	{
		printf("overtload!!\n");
		return;              //����ʲô�أ�
	}
	printf("Please input part_number\n");
	scanf("%d", &part_number);

	int temp;
	if (mark > 0)
	{
		if ((temp = find_part_number(part_number)) == -1)
		{
			inventory[mark].number = part_number;
		}
		else
		{
			printf("The part is exist!\n");
			return;
		}
	}
	else
		inventory[mark].number = part_number;

	printf("Please input part's name\n");
	read_part_name(inventory[mark].name, LEN + 1);

	printf("how much on_hand?\n");
	scanf("%d", &inventory[mark].on_hand);
	mark++;
	take = getchar();			//���û�����getchar �������һ��'\n',����Ϊʲô����������������
}


void show()
{
	int part_number, temp2;
	printf("Please input part's number\n");
	scanf(" %d", &part_number);
	if (((temp2 = find_part_number(part_number)) == -1) || mark == 0)
	{
		printf("No that part exist!\n");
		return 0;
	}
	else
	{
		int i = 0;
		i = find_part_number(part_number);
		printf("Number:    name        on hand       \n");
		printf("%4d      %8s %8d\n ", inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}


}


void read_part_name(char str[], int n)
{
	int ch, i = 0;						//Ϊʲô��int ?��Ϊgetchar()�ǻ�ȡASC����
	ch = getchar();
	while (isspace(ch = getchar()));

	while (ch != '\n'&&ch != EOF)
	{
		if (i < n)
		{
			str[i++] = ch;
			ch = getchar();
		}
	}
}



/**********************************Print parts************************************************/
void print()
{
	int temp;
	if (mark == 0)
	{
		printf("NO part is exist!\n");
		getchar();     //���û�����getchar �������һ��'\n',����Ϊʲô����������������          
		return 0;			//����0????????????????????????????????????????
	}
	else
		for (int i = 0; i < mark; i++)
		{
			printf("Number:    name        on hand       \n");
			printf("%4d      %8s %8d\n ", inventory[i].number, inventory[i].name, inventory[i].on_hand);
		}

}


int find_part_number(int part_number_insert)
{
	for (int i = 0; i <= mark; i++)				//����Ƿ��ظ�����������
	{
		if (part_number_insert == inventory[i].number)
		{
			return i;							//���������ͬ�ı�žͷ���i
		}
		else
		{
			return -1;							//�����������ͬ�ı�žͷ���-1
		}
	}
}



/************************************Upadte****************************************************/
void update(void)
{
	int temp3, update_number, part_number;
	printf("Please input part_number for update:\n");
	scanf("%d", &part_number);

	if ((temp3 = find_part_number(part_number)) == -1)
	{
		printf("Error ,no that part_number!\n");
		return;
	}
	else
		printf("Please input numbe of on_hand for upadte:\n");

	scanf("%d", &update_number);
	inventory[temp3].on_hand += update_number;

}
