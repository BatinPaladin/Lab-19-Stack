#include <iostream>
#include "Stack.h"
void main() {
	system("chcp 1251");
	int size  = -1;
	cout << "\n������� ������ �����:\n> ";
	while (size < 0) {
		cin >> size;
		if (size < 0) {
			cout << "\n������� ������������� �����:\n> ";
		}
	}
	if (size == 0) {
		cout << "\n���� ����!\n";
	}
	else {
		Stack* stack = new Stack;
		double el;
		for (int i = 0; i < size; i++) {
			cout << "\n������� " << i + 1 << " �������:\n> ";
			cin >> el;
			stack->Push(el);
		}
		stack->Show();
		int lenght = stack->Size();
		Stack* temp_stack = new Stack;
		if (lenght % 2 == 0) {
			for (int i = 0; i < lenght; i++) {
				if (i % 2 != 0) {
					temp_stack->Push(stack->Top());
				}
				stack->Pop();
			}
		}
		else {
			for (int i = 1; i <= lenght; i++) {
				if (i % 2 != 0) {
					temp_stack->Push(stack->Top());
				}
				stack->Pop();
			}
		}
		lenght = temp_stack->Size();
		for (int i = 0; i < lenght; i++) {
			stack->Push(temp_stack->Top());
			temp_stack->Pop();
		}
		stack->Show();
	}
	system("pause");
}