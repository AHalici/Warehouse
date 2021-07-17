#ifndef STACK_H
#define STACK_H
#include "Warehouse.h"


class Stack
{
	Warehouse* topOfStack;
	int _deliveryNumber = 1000;
	int _orderNumber = 1;

public:

	Warehouse* peek() const;
	bool isEmpty() const;

	int getDeliveryNumber() { return _deliveryNumber; }
	void incrementDeliveryNumber() { _deliveryNumber += 1; }

	int getOrderNumber() { return _orderNumber; }
	void incrementOrderNumber() { _orderNumber++; }

	void pop();
	void push(int stock, double price);

	void delivery(int stock);
	void widgetShipment(int stock, int price);

	void display();

	Stack();
	~Stack();
};

#endif // !STACK_H