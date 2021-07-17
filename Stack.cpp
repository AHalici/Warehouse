#include "Stack.h"
#include <iostream>
#include <iomanip>

using namespace std;

Stack::Stack()
{
	topOfStack = nullptr;
}

Stack::~Stack()
{
	while (topOfStack != nullptr)
	{
		pop();
	}
}

Warehouse* Stack::peek() const
{
	return topOfStack;
}

bool Stack::isEmpty() const
{
	return (topOfStack == nullptr);
}

void Stack::pop()
{
	Warehouse* warehousePointer;
	warehousePointer = nullptr;

	if (topOfStack != nullptr)
	{
		warehousePointer = topOfStack;
		topOfStack = topOfStack->getNextWarehousePointer();
		delete warehousePointer;
	}
}

void Stack::push(int stock, double price)
{
	try
	{
		Warehouse* warehousePointer = new Warehouse;
		if (warehousePointer == nullptr)
		{
			cout << "ERROR could not be allocated" << endl;
		}
		warehousePointer->setPrice(price);
		warehousePointer->setStock(stock);
		warehousePointer->setDeliveryNumber(_deliveryNumber);
		warehousePointer->setOrderNumber(_orderNumber);
		warehousePointer->setNextWarehousePointer(topOfStack);
		topOfStack = warehousePointer;
	}
	catch (bad_alloc)
	{
		cout << "Allocation Failure" << endl;
	}
}

void Stack::delivery(int stock)
{
	cout << "How many widgets would you like to order?: ";
	cin >> stock;

	while (cin.fail() || stock <= 0)
	{
		cout << "ERROR! the amount of orders must be greater than 0. \nPlease enter another amount: \n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> stock;
	}
	push(stock, 0);
	incrementOrderNumber();
}

void Stack::widgetShipment(int stock, int price)
{
	cout << "You ordered a shipment" << endl;

	cout << "\nHow many orders would you like?: " << endl;
	cin >> stock;

	while (cin.fail() || stock <= 0)
	{
		cout << "\nERROR! the amount of orders must be greater than 0. \nPlease enter another amount: \n";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> stock;
	}
	cout << "Enter the price of the Widgets: \n$";
	cin >> price;

	while (cin.fail() || price < 0)
	{
		cout << "\nERROR! the amount of orders must be greater than 0. \nPlease enter another price: \n$";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> price;
	}

	push(stock, price);
	incrementDeliveryNumber();
}

void Stack::display()
{
	Warehouse* warehousePointer = topOfStack;
	int tempOrderNumber = _orderNumber;

	cout << "Delivery #" << setw(20) << "Quantity Shipped" << setw(20) << "Unit Price" << setw(30) << "Cost to the Warehouse" << setw(30) << "Cost to the Customer" << endl;

	while (warehousePointer != nullptr)
	{
		if (warehousePointer->getPrice() != 0)
		{
			cout << setw(10) << right << warehousePointer->getDeliveryNumber() << setw(20) << right << warehousePointer->getStock() << setw(20) << warehousePointer->getPrice() << setw(30) << warehousePointer->getStock() * warehousePointer->getPrice() << setw(30) << warehousePointer->getStock() * warehousePointer->getPrice() * 1.5 << endl;
		}
		if (warehousePointer->getPrice() == 0)
		{
			cout << "\nOrder Number #" << right << setw(35) << tempOrderNumber - 1//warehousePointer->getOrderNumber()
				<< "\nQuantity Ordered" << right << setw(33) << warehousePointer->getStock()
				<< "\nQuantity Shipped this Shipment" << setw(19) << "0"
				<< "\nQuantity to be Shipped" << setw(27) << warehousePointer->getStock()
				<< "\nTotal Cost to the Warehouse" << setw(22) << "N/A"
				<< "\nTotal Cost to the Customer" << setw(23) << "N/A"
				<< "\nProfit this Shipment" << setw(29) << "N/A" << endl;


		}
		warehousePointer = warehousePointer->getNextWarehousePointer();
		tempOrderNumber--;
	}
}