#include<ctype.h>
#include<stdio.h>
#include"readline.h"

int read_line(char str[], int n)					//	n��NAME_LEN���β�,ֵ��25 ; str[]��inventory[num_parts].name���β�
{
	int ch, i = 0;						//		Ϊʲôch��int ���ͣ�			

	while (isspace(ch = getchar()));			/* �ú���������������1��scanf�����µ�'\n',������ʼ���ַ����д洢�ַ�ǰ�����հ׷��� */
												// getchar()һ��һ���ַ���ȡ,���ܶ�ȡ`\n`		/*	����洢�û���������ƵĿ�ʼ��¼��հ�       /
												/*�����������ǿո���߻س������ ��ѭ�� */



	while (ch != '\n'&&ch != EOF) {		/*	����Ĳ��ǻس���	û�г���,��  ִ��ѭ����	*/
		if (i < n)
			str[i++] = ch;					/*str�ַ������鴢��������ַ���*/
		ch = getchar();
	}

	str[i] = '\0';							/*	��û����������һ������	str�ַ�����������Ը�Ԫ��Ϊ ���ַ�		*/
	return i;						/*�����ʲô���ã�	i��ֵ Ϊ���룺�ַ�������*/
}
