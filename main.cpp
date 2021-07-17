// Warehouse Inventory Management
	// Implemented as a stack ordering system
#include <iostream>
#include <iomanip>
#include "Stack.h"

using namespace std;


void Shipping(Stack& OrdersToBeFilled, Stack& WidgetsOnHand);
void menu(Stack& WidgetsOnHand, Stack& OrdersToBeFilled);

int main()
{
	cout << fixed << showpoint << setprecision(2);

	Stack WidgetsOnHand, OrdersToBeFilled;
	menu(WidgetsOnHand, OrdersToBeFilled);

}


void menu(Stack& WidgetsOnHand, Stack& OrdersToBeFilled)
{
	int choice;
	double price = 0;
	int stock = 0;
	bool keepLooping = true;

	while (keepLooping)
	{
		cout << "\nChoose an option by inputing a number for selected choice" << endl;
		cout << "\n1: Show Current Inventory / Orders on hand" << endl;
		cout << "2: Place order to buy Widgets" << endl;
		cout << "3: Add Widgets to Warehouse" << endl;
		cout << "4: EXIT MENU. " << endl;
		cout << "_______________________________________________________________________________________________________________________" << endl;

		cout << "\nEnter choice here: ";
		cin >> choice;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "ERROR! You have entered an invalid input. Please enter an integer shown on the menu" << endl;
		}

		switch (choice)
		{
		case 1:
		{
			if ((OrdersToBeFilled.isEmpty()) && (WidgetsOnHand.isEmpty()))
				cout << "Current Inventory: \n-------------------- \nNo Orders and No Widgets\n";
			else if (OrdersToBeFilled.isEmpty() && !(WidgetsOnHand.isEmpty()))
			{
				cout << "Current Inventory: \n-------------------- " << endl;
				WidgetsOnHand.display();
			}
			else if (!(OrdersToBeFilled.isEmpty()) && WidgetsOnHand.isEmpty())
			{
				cout << "Current Inventory: \n-------------------- \nNo Widgets at the moment, here are our orders: " << endl;
				OrdersToBeFilled.display();
			}
			break;
		}
		case 2:
		{
			OrdersToBeFilled.delivery(stock);
			Shipping(OrdersToBeFilled, WidgetsOnHand);
			break;
		}
		case 3:
		{
			WidgetsOnHand.widgetShipment(stock, price);
			Shipping(OrdersToBeFilled, WidgetsOnHand);
			break;
		}
		case 4:
		{
			cout << "Goodbye" << endl;
			keepLooping = false;
			break;
		}
		default:
		{
			cout << "\nPlease enter an allowed choice that is shown " << endl;
		}
		}
	}
}


void Shipping(Stack& OrdersToBeFilled, Stack& WidgetsOnHand)
{
	int totalStockUsedForOrder = 0;
	int totalStockForOrder;
	if (OrdersToBeFilled.isEmpty() && !(WidgetsOnHand.isEmpty()))
	{
		WidgetsOnHand.display();
	}

	else if (!(OrdersToBeFilled.isEmpty()) && WidgetsOnHand.isEmpty())
	{
		cout << "\nOrder Number #" << right << setw(35) << OrdersToBeFilled.getOrderNumber() - 1
			<< "\nQuantity Ordered" << right << setw(33) << OrdersToBeFilled.peek()->getStock()
			<< "\nQuantity Shipped this Shipment" << setw(19) << "0"
			<< "\nQuantity to be Shipped" << setw(27) << OrdersToBeFilled.peek()->getStock()
			<< "\nTotal Cost to the Warehouse" << setw(22) << "N/A"
			<< "\nTotal Cost to the Customer" << setw(23) << "N/A"
			<< "\nProfit this Shipment" << setw(29) << "N/A" << endl;
	}

	int tempOrderNumber = OrdersToBeFilled.getOrderNumber();
	while (!(WidgetsOnHand.isEmpty()) && !(OrdersToBeFilled.isEmpty()))
	{
		if (WidgetsOnHand.peek()->getStock() == 0)
		{
			WidgetsOnHand.pop();
		}

		if (WidgetsOnHand.peek()->getStock() < OrdersToBeFilled.peek()->getStock())
		{
			cout << "\nOrder Number #" << right << setw(35) << OrdersToBeFilled.getOrderNumber() - 1
				<< "\nQuantity Ordered" << right << setw(33) << OrdersToBeFilled.peek()->getStock()
				<< "\nQuantity Shipped this Shipment" << setw(19) << WidgetsOnHand.peek()->getStock()
				<< "\nQuantity to be Shipped" << setw(27) << OrdersToBeFilled.peek()->getStock() - WidgetsOnHand.peek()->getStock()
				<< "\nTotal Cost to the Warehouse" << setw(22) << WidgetsOnHand.peek()->getStock() * WidgetsOnHand.peek()->getPrice()
				<< "\nTotal Cost to the Customer" << setw(23) << WidgetsOnHand.peek()->getStock() * WidgetsOnHand.peek()->getPrice() * 1.5
				<< "\nProfit this Shipment" << setw(29) << (WidgetsOnHand.peek()->getStock() * WidgetsOnHand.peek()->getPrice() * 1.5) - WidgetsOnHand.peek()->getStock() * WidgetsOnHand.peek()->getPrice() << endl;
			OrdersToBeFilled.peek()->setStock(OrdersToBeFilled.peek()->getStock() - WidgetsOnHand.peek()->getStock());
			WidgetsOnHand.pop();

		}
		else if (WidgetsOnHand.peek()->getStock() >= OrdersToBeFilled.peek()->getStock())
		{
			WidgetsOnHand.peek()->setStock(WidgetsOnHand.peek()->getStock() - OrdersToBeFilled.peek()->getStock());
			cout << "\nOrder Number #" << right << setw(35) << tempOrderNumber - 1//OrdersToBeFilled.getOrderNumber()
				<< "\nQuantity Ordered" << right << setw(33) << OrdersToBeFilled.peek()->getStock()
				<< "\nQuantity Shipped this Shipment" << setw(19) << OrdersToBeFilled.peek()->getStock()
				<< "\nQuantity to be Shipped" << setw(27) << "0"
				<< "\nTotal Cost to the Warehouse" << setw(22) << OrdersToBeFilled.peek()->getStock() * WidgetsOnHand.peek()->getPrice()
				<< "\nTotal Cost to the Customer" << setw(23) << OrdersToBeFilled.peek()->getStock() * WidgetsOnHand.peek()->getPrice() * 1.5
				<< "\nProfit this Shipment" << setw(29) << (OrdersToBeFilled.peek()->getStock() * WidgetsOnHand.peek()->getPrice() * 1.5) - OrdersToBeFilled.peek()->getStock() * WidgetsOnHand.peek()->getPrice() << endl;
			OrdersToBeFilled.pop();
			tempOrderNumber--;
			if (WidgetsOnHand.peek()->getStock() == 0)
			{
				WidgetsOnHand.pop();
			}
		}
	}
}