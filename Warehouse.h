#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>

using namespace std;

class Warehouse
{
	int _stock;
	double _price;
	int _orderNumber;
	int _deliveryNumber;
	Warehouse* _next;

public:

	void setStock(int stock);
	void setPrice(double price);
	void setNextWarehousePointer(Warehouse* warehousePointer);

	void incrementDeliveryNumber() { _deliveryNumber++; }
	void setDeliveryNumber(int& deliveryNumber) { _deliveryNumber = deliveryNumber; }

	void incrementOrderNumber() { _orderNumber++; }
	void setOrderNumber(int& orderNumber) { _orderNumber = orderNumber; }

	int getOrderNumber() { return _orderNumber; }

	int getStock() { return _stock; }
	double getPrice() { return _price; }
	int getDeliveryNumber() { return _deliveryNumber; }
	Warehouse* getNextWarehousePointer() { return _next; }

	Warehouse();
	~Warehouse();

};


#endif // !WAREHOUSE_H