#include "Warehouse.h"

Warehouse::Warehouse()
{
	_stock = 0;
	_price = 0;
	_next = nullptr;
}

Warehouse::~Warehouse()
{
	_stock = 0;
	_price = 0;
	_next = nullptr;
}

void Warehouse::setStock(int stock)
{
	_stock = stock;
}
void Warehouse::setNextWarehousePointer(Warehouse* warehousePointer)
{
	_next = warehousePointer;
}
void Warehouse::setPrice(double price)
{
	_price = price;
}