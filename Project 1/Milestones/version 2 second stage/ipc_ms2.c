#include <stdio.h>

void clrKyb(void)
{
	while (getchar() != '\n');
}
void pause(void)
{
	printf("Press <ENTER> to continue...");
	clrKyb();
}

int getInt(void)
{
	int Value;
	char NL = 'x';
	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	}
	return Value;
}

int yes(void)
{
	char CH;
	int RET = 0;

	do
	{
		scanf("%c", &CH);
		clrKyb();

		if (!((CH == 'y') || (CH == 'Y') || (CH == 'n') || (CH == 'N')))
		{
			printf("Only (Y)es or (N)o are acceptable:");
		}

	} while (!((CH == 'y') || (CH == 'Y') || (CH == 'n') || (CH == 'N')));

	if (CH == 'Y' || CH == 'y')
	{
		RET = 1;
	}
	return RET;
} //ms2
int getIntLimited(int lowerLimit, int upperLimit)
{
	int Value;
	Value = getInt();
	do
	{
		if (Value < lowerLimit || Value > upperLimit)
		{

			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
			scanf("%d", &Value);
		}
	} while (Value < lowerLimit || Value > upperLimit);
	return Value;
}
void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n");
}
int menu(void)
{
	int select = 0;
	printf("1- List all items\n");
	printf("2 - Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &select);
	clrKyb();
	while (select < 0 || select>7)
	{
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &select);
		clrKyb();
	}
	return select;
}
void GrocInvSys(void)
{
	int sel;
	int done = 0;
	welcome();
	printf("\n");
	while (!done)
	{
		sel = menu();
		if (sel == 1)
		{
			printf("List Items!\n");
			pause();
		}
		else if (sel == 2)
		{
			printf("Search Items!\n");
			pause();
		}
		else if (sel == 3)
		{
			printf("Checkout Item!\n");
			pause();
		}
		else if (sel == 4)
		{
			printf("Stock Item!\n");
			pause();
		}
		else if (sel == 5)
		{
			printf("Add/Update Item!\n");
			pause();
		}
		else if (sel == 6)
		{
			printf(">Delete Item!\n");
			pause();
		}
		else if (sel == 7)
		{
			printf("Search by name!\n");
			pause();
		}
		else if (sel == 0)
		{
			printf("Exit the program? (Y)es/(N)o): ");
			done = yes();
		}
	}
}//ms2


int main(void) {
   GrocInvSys();
   return 0;
}

// implmement MS2 fucntions here

// copy MS1 functions here



/*
---=== Grocery Inventory System ===---

1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 8
Invalid value, 0 < value < 7: 1
List Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 2
Search Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 3
Checkout Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 4
Stock Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 5
Add/Update Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 6
Delete Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 7
Search by name!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : x
Only (Y)es or (N)o are acceptable: n
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : y
*/