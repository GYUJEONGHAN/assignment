/*
meter ������ ���̸� �Է� �޾Ƽ� inch�� feet ������ ���̷� ����ϴ� ���α׷�
201821133 �ѱ���
2022.09.16
*/
#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
#include <stdio.h>

#define INCHES_PER_METER 39.37  //inch ������ �����ϴ� ��ũ�� ���
#define FEET_PER_METER 3.281    //feet ������ �����ϴ� ��ũ�� ���

int main(void)
{
	double length; //�Է¹��� �Ǽ��� ���� ����

	printf("meter ������ ���̸� �Է��Ͻÿ�: "); 
	scanf("%lf", &length); //�Է¹���

    printf("���: \n");
	printf("%.2f inches\n", length * INCHES_PER_METER); //length�� ���� inch ���
	printf("%.2f feet\n", length * FEET_PER_METER);     //length�� ���� feet ���

	return 0;
}