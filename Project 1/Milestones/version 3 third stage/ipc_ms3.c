//Name        : JASMEET SINGH SALUJA
//Student No. : 102579166
#include <stdio.h>

// define statements go here
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
const double TAX = 0.13;

/* ms1 prototypes*/
void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");
}
void prnTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void prnFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
	{
		printf("                                           Grand Total: |     %.2lf\n", gTotal);
	}
}
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

double getDbl(void)
{
	double Value;
	char NL = 'x';
	while (NL != '\n')
	{
		scanf("%lf%c", &Value, &NL);
		if (NL != '\n')
		{
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	}
	return Value;
}

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
double getDblLimited(double lowerLimit, double upperLimit)
{
	double Value;
	Value = getDbl();
	do
	{
		if (Value < lowerLimit || Value > upperLimit)
		{
			printf("Invalid value, %.6f< value < %.6f: ", lowerLimit, upperLimit);
			scanf("%lf", &Value);
		}
	} while (Value < lowerLimit || Value > upperLimit);
	return Value;
};

/* ipc_ms2 prototype*/
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
			printf("Only (Y)es or (N)o are acceptable: ");
		}

	} while (!((CH == 'y') || (CH == 'Y') || (CH == 'n') || (CH == 'N')));

	if (CH == 'Y' || CH == 'y')
	{
		RET = 1;
	}
	return RET;
} //ms2

struct Item
{
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};


/* ms3 prototypes*/

double totalAfterTax(struct Item item)
{
	double sum;
	if (item.isTaxed == 1)
	{
		sum = (item.quantity * item.price) + (item.quantity * item.price *TAX);
	}
	else if (item.isTaxed == 0)
	{
		sum = item.quantity * item.price;
	}
	return sum;
}

int isLowQty(struct Item item)
{
	int minimum = 1;
	if (item.minQuantity < 5)
	{
	    minimum = 0;
	}
	return minimum;
}

struct Item itemEntry(int sku)
{
	struct Item store;

	printf("        SKU: %d\n", sku);
	store.sku = sku;

	printf("       Name: ");
	scanf(" %20[^\n]", store.name);
	clrKyb();

	printf("      Price: ");
	store.price = getDbl();

	printf("   Quantity: ");
	store.quantity = getInt();

	printf("Minimum Qty: ");
	store.minQuantity = getInt();

	printf("   Is Taxed: ");
	store.isTaxed = yes();

	return store;
}

void dspItem(struct Item item, int linear)
{
	double priceinclTax;
	priceinclTax = totalAfterTax(item);
	if (linear == 1) 
	{
		if (item.isTaxed == 1)
		{
			printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceinclTax);
		}
		else if (item.isTaxed == 0)
		{
			printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceinclTax);
		}
		if (item.quantity < item.minQuantity)
		{
			printf("***\n");
		}
		else if (item.quantity >= item.minQuantity)
		{
			printf("\n");
		}
	}
	else
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		if (item.isTaxed == 1)
		{
			printf("   Is Taxed: Yes\n");
		}
		else
		{
			printf("   Is Taxed: No\n");
		}
		if (item.quantity <= item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}


}

void listItems(const struct Item item[], int NoOfItems) 
{
	int i = 0;
	float grand = 0;
	prnTitle();
	for (i = 0; i < NoOfItems; i++)
	{
		printf("%-4d", i + 1);
		dspItem(item[i], 1);
		grand += totalAfterTax(item[i]);
	}
	prnFooter(grand);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i;
	int Num = 0;
	for (i = 0; i < NoOfRecs; i++)
	{
		if (sku == item[i].sku)
		{
			*index = i;
			Num = 1;
		}
	}
	return Num;
}
double totalAfterTax(struct Item item)
{
	double sum;
	if (item.isTaxed == 1)
	{
		sum = (item.quantity * item.price) + (item.quantity * item.price *TAX);
	}
	else if (item.isTaxed == 0)
	{
		sum = item.quantity * item.price;
	}
	return sum;
}

int isLowQty(struct Item item)
{
	int minimum = 1;
	if (item.minQuantity < 5)
	{
		minimum = 0;
	}
	return minimum;
}

struct Item itemEntry(int sku)
{
	struct Item store;

	printf("        SKU: %d\n", sku);
	store.sku = sku;

	printf("       Name: ");
	scanf(" %20[^\n]", store.name);
	clrKyb();

	printf("      Price: ");
	store.price = getDbl();

	printf("   Quantity: ");
	store.quantity = getInt();

	printf("Minimum Qty: ");
	store.minQuantity = getInt();

	printf("   Is Taxed: ");
	store.isTaxed = yes();

	return store;
}

void dspItem(struct Item item, int linear)
{
	double priceinclTax;
	priceinclTax = totalAfterTax(item);
	if (linear == 1)
	{
		if (item.isTaxed == 1)
		{
			printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceinclTax);
		}
		else if (item.isTaxed == 0)
		{
			printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|", item.sku, item.name, item.price, item.quantity, item.minQuantity, priceinclTax);
		}
		if (item.quantity < item.minQuantity)
		{
			printf("***\n");
		}
		else if (item.quantity >= item.minQuantity)
		{
			printf("\n");
		}
	}
	else
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		if (item.isTaxed == 1)
		{
			printf("   Is Taxed: Yes\n");
		}
		else
		{
			printf("   Is Taxed: No\n");
		}
		if (item.quantity <= item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}


}

void listItems(const struct Item item[], int NoOfItems)
{
	int i = 0;
	float grand = 0;
	prnTitle();
	for (i = 0; i < NoOfItems; i++)
	{
		printf("%-4d", i + 1);
		dspItem(item[i], 1);
		grand += totalAfterTax(item[i]);
	}
	prnFooter(grand);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i;
	int Num = 0;
	for (i = 0; i < NoOfRecs; i++)
	{
		if (sku == item[i].sku)
		{
			*index = i;
			Num = 1;
		}
	}
	return Num;
}
/* Constant double TAX value */




/*int main() {
   struct Item I[21] = {
      { 4.4,275,0,10,2,"Royal Gala Apples" },
      { 5.99,386,0,20,4,"Honeydew Melon" },
      { 3.99,240,0,30,5,"Blueberries" },
      { 10.56,916,0,20,3,"Seedless Grapes" },
      { 2.5,385,0,5,2,"Pomegranate" },
      { 0.4,495,0,100,30,"Banana" },
      { 0.5,316,0,123,10,"Kiwifruit" },
      { 4.49,355,1,20,5,"Chicken Alfredo" },
      { 5.49,846,1,3,5,"Veal Parmigiana" },
      { 5.29,359,1,40,5,"Beffsteak Pie" },
      { 4.79,127,1,30,3,"Curry Checken" },
      { 16.99,238,1,10,2,"Tide Detergent" },
      { 10.49,324,1,40,5,"Tide Liq. Pods" },
      { 10.99,491,1,50,5,"Tide Powder Det." },
      { 3.69,538,1,1,5,"Lays Chips S&V" },
      { 3.29,649,1,15,5,"Joe Org Chips" },
      { 1.79,731,1,100,10,"Allen's Apple Juice" },
      { 6.69,984,1,30,3,"Coke 12 Pack" },
      { 7.29,350,1,50,5,"Nestea 12 Pack" },
      { 6.49,835,1,20,2,"7up 12 pack" }
   };
   double val;
   int ival;
   int searchIndex;
   val = totalAfterTax(I[0]);
   printf("totalAfterTax:\n    yours=%lf\nprogram's=44.000000\n", val);
   val = totalAfterTax(I[7]);
   printf("totalAfterTax:\n    yours=%lf\nprogram's=101.474000\n", val);
   ival = isLowQty(I[0]);
   printf("isLowQty:\n    yours=%d\nprogram's=0\n",ival);
   ival = isLowQty(I[14]);
   printf("isLowQty:\n    yours=%d\nprogram's=1\n",ival);
   pause();
   printf("itemEntry, enter the following values:\n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: n\n");
   printf("Enter the values:\n");
   I[20] = itemEntry(999);
   printf("dspItem, Linear:\nYours: ");
   dspItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
   printf("dspItem, Form:\nYours:\n");
   dspItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 50\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: No\n");
   I[20].quantity = 2;
   I[20].isTaxed = 1;
   pause();
   printf("dspItem, Linear with low value and taxed:\nYours: ");
   dspItem(I[20], LINEAR);
   printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
   printf("dspItem, Form with low value:\nYours:\n");
   dspItem(I[20], FORM);
   printf("Programs: \n");
   printf("        SKU: 999\n"
      "       Name: Red Apples\n"
      "      Price: 4.54\n"
      "   Quantity: 2\n"
      "Minimum Qty: 5\n"
      "   Is Taxed: Yes\n"
      "WARNING: Quantity low, please order ASAP!!!\n");
   pause();
   printf("Listing Items: \n");
   listItems(I, 21);
   pause();
   printf("Locate Item, successful search:\n");
   printf("program: Found the item 999 at index: 20\n");
   printf("  Yours: ");
   if (locateItem(I, 21, 999, &searchIndex)) {
      printf("Found the item 999 at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 999 is in the array!\n");
   }

   printf("Locae Item, unsuccessful search:\n");
   printf("Progam: No item with the sku 732 is in the array!\n");
   printf(" Yours: ");
   if (locateItem(I, 21, 732, &searchIndex)) {
      printf("Found the item at index: %d\n", searchIndex);
   }
   else {
      printf("No item with the sku 732 is in the array!\n");
   }
   return 0;
}*/



/*   item entry output 
        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum Qty: 5
   Is Taxed: n

        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum Qty: 5
   Is Taxed: No
WARNING: Quantity low, please order ASAP!!!
   

*/

/*  dspItems
|999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|

        SKU: 999
       Name: Red Apples
      Price: 4.54
   Quantity: 50
Minimum qty: 5
   Is Taxed: No

*/


/*ms1 and 2 functions: */

