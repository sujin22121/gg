#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

struct node { //�ڱ� ���� �� �� �ִ� ����ü node ����
	int data;
	struct node* next;
};

void makeArr(int arr[]) // int�� ���� 20���� �����ϴ� �迭 ���� 
{
	for (int i = 0; i < 20; i++)
		arr[i] = rand() % 999 + 1;
}

void printList(struct node* a) //���Ḯ��Ʈ�� �޾Ƽ� ���
{
	for (; a != NULL; a = a->next)
		printf("%d ", a->data);
	printf("\n");
}

void sort(int arr[]) // �迭�� ������������ ����
{
	int i, j, min, temp;
	for (i = 0; i < 19; i++) {
		min = i;
		for (j = i + 1; j < 20; j++)
			if (arr[j] < arr[min])
				min = j;
		SWAP(arr[i], arr[min], temp);
	}
}

struct node* linkList(int arr[]) //��ũ�帮��Ʈ
{
	struct node* A = NULL;
	struct node* B = NULL;
	struct node* last = NULL;
	int i = 0;

	A = (struct node*)malloc(sizeof(struct node));
	A->data = arr[0];
	A->next = NULL;
	last = A;

	for (i = 1; i < 20; i++)
	{
		B = (struct node*)malloc(sizeof(struct node));
		B->data = arr[i];
		B->next = NULL;

		last->next = B;
		last = B;
	}

	return A;
}

struct node* connectionList(struct node* a, struct node* b) // �� ���� ��ũ�帮��Ʈ�� ���ڷ� �޾� ������������ ����
{
	struct node* start;
	struct node* last;

	if (a->data < b->data)
	{
		start = a;
		last = start;
		a = a->next;
	}

	else
	{
		start = b;
		last = start;
		b = b->next;
	}
	
	while (a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			last->next = b;
			last = b;
			b = b->next;
		}

		else
		{
			last->next = b;
			last = b;
			b = b->next;
		}
	}

	if (a == NULL)
		last->next = b;
	else
		last->next = a;
	return start;
}

void main()
{
	srand(time(NULL));
	int arr1[20];
	int arr2[20];
	struct node* a;
	struct node* b;
	struct node* d;

	makeArr(arr2);
	sort(arr2);
	b = linkList(arr2);
	printf("b����Ʈ: ");
	printList(b);

	d = connectionList(a, b);
	printf("d ����Ʈ: ");
	printList(d);
}


