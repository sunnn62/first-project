#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
		element data[MAX_STACK_SIZE];
		int top;
} StackType;
// 스택초기화함수
void init_stack(StackType* s)
{
	s->top = -1;
}
// 공백상태검출함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화상태검출함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

void print_stack(char* name, StackType* s) {
	printf("%s [bottom -> top]: ", name);
	if (is_empty(s)) {
		printf("(empty)");
		
	}
	else {
		for (int i = 0; i <= s->top; i++) {
			printf("%d", s->data[i]);
			if (i != s->top) {
				printf(" ");
			}
		}
	}
		printf("\n");


	

}
StackType stack1, stack2;

void enqueue(int x) {
	push(&stack1, x);
	printf("[ENQUEUE] %d\n", x);
	print_stack("stack1", &stack1);
	print_stack("stack2", &stack2);
	printf("\n");
}

void dequeue(){
	if (is_empty(&stack2)) {
		while (!is_empty(&stack1)) {
			push(&stack2, pop(&stack1));

		}
	}
	int val = pop(&stack2);
	printf("[DEQUEUE]\n");
	printf("Returned: %d\n", val);
	print_stack("stack1", &stack1);
	print_stack("stack2", &stack2);
	printf("\n");

}

int main() {
	init_stack(&stack1);
	init_stack(&stack2);

	int operations[] = { 10, 20, 30, -1, 40, 50, -1, -1, 60, -1, -1, -1 };
	int n = sizeof(operations) / sizeof(operations[0]);
	printf("입력값 (양의 정수: enqueue, -1: dequeue): {");
	for (int i = 0; i < n; i++){
		printf("%d ", operations[i]);

	}
	printf("}\n\n");
	for (int i = 0; i < n; i++) {
		if (operations[i] == -1) {
			dequeue();
		}
		else {
			enqueue(operations[i]);
		}

	}
	return 0;
}

//덱 회문
int main(void)
{
	DequeType queue;
	char s[100] = "madam";

	init_deque(&queue);
	for (int i = 0; i < strlen(s); i++) {
		add_rear(&queue, s[i]);
	}

	int equal = 1;

	while (get_count(&queue) > 1 && equal) {
		char first = delete_front(&queue);
		char last = delete_rear(&queue);
		if (first != last)
			equal = 0;
	}

	if (equal)
		printf("회문입니다.\n");
	else
		printf("회문이 아닙니다.\n");
}
