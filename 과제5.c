#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

struct node { //자기 참조 할 수 있는 구조체 node 선언
	int data;
	struct node* next;
};

void makeArr(int arr[]) // int형 변수 20개를 저장하는 배열 생성 
{
	for (int i = 0; i < 20; i++)
		arr[i] = rand() % 999 + 1;
}

void printList(struct node* a) //연결리스트를 받아서 출력
{
	for (; a != NULL; a = a->next)
		printf("%d ", a->data);
	printf("\n");
}

void sort(int arr[]) // 배열을 오름차순으로 정렬
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

struct node* linkList(int arr[]) //링크드리스트
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

struct node* connectionList(struct node* a, struct node* b) // 두 개의 링크드리스트를 인자로 받아 오름차순으로 연결
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
	printf("b리스트: ");
	printList(b);

	d = connectionList(a, b);
	printf("d 리스트: ");
	printList(d);
}


