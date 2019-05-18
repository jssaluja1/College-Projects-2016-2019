//Name  : Jasmeet Singh Saluja
//Std No: 102579166
#include <stdio.h>
#include <stdlib.h>

/***************************************************************
Tester Function prototypes and information, DO NOT MODIFY */

void searchTest();
void updateTest();
void addTest();
void addOrUpdateTest();
void adjustQtyTest();

struct Item 
{
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};

struct Item GI[21] = {
   { 4.4,275,0,10,2,"Royal Gala Apples" },
   { 5.99,386,0,20,4,"Honeydew Melon" },
   { 3.99,240,0,30,5,"Blueberries" },
   { 10.56,916,0,20,3,"Seedless Grapes" },
   { 2.5,385,0,5,2,"Pomegranate" },
   { 0.44,495,0,100,30,"Banana" },
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
int GNoOfRecs = 20;

/**************************************************************/

/*************************************************************
Student Milestone 3 definitions and prototypes go here:
(Do not copy struct Item since it is already implimented above*/
#define LINEAR         1
#define FORM           0
#define STOCK          1
#define CHECKOUT       0
#define TAX         0.13
void clrKyb(void);
int yes(void);
void dspItem(struct Item item, int linear);
struct Item itemEntry(int sku);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
/*End of Student Milestone 3 definitions and prototypes
*************************************************************/

/*************************************************************
Milestone 4 defintions and prototypes:*/
// write the define statements here:

#define MAX_ITEM_NO   21
#define MAX_QTY      999
#define SKU_MAX	     999
#define SKU_MIN      100

// function prototypes in order of implementation:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);


/*End of Milestone 4 defintions and prototypes:
***************************************************************/

/*************************************************************
Main tester */
/*int main() {
   searchTest();    //is working
   updateTest();      
   addTest();         // stopped working
   addOrUpdateTest(); // stopped working  after 
   adjustQtyTest();
   return 0;
}*/

/*End of main tester
******************************************************************/


/***************************************************************
Milestone 4 functions to be implemented */
void search(const struct Item item[], int NoOfRecs)
{
	int sku, found;
	int index;
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	found= locateItem(item, NoOfRecs, sku, &index);
	if(found==0)
	{
		printf("Item not found!\n");
	}
	else
	{
		printf("        SKU: %d\n", sku);
		printf("       Name: %s\n", item[index].name);
		printf("      Price: %.2lf\n", item[index].price);
		printf("   Quantity: %d\n", item[index].quantity);
		printf("Minimum Qty: %d\n", item[index].minQuantity);
		if (item[index].isTaxed == 1)
		{
			printf("   Is Taxed: Yes\n");
		}
		else 
		{
			printf("   Is Taxed: No\n");
		}
	}
}

void updateItem(struct Item* itemptr)
{
	int sku = itemptr->sku, ns;
	struct Item item;
	printf("Enter new data:\n");
	clrKyb();
	item = itemEntry(sku);
	item.sku = sku;
	printf("Overwrite old data? (Y)es/(N)o: ");
	ns = yes();
	if (ns == 1)
	{
		*itemptr = item;
		printf("--== Updated! ==--\n");

	}
	else
	{
		printf("--== Aborted! ==--\n");
	}

}

void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	struct Item b;
	int ns;

	if (*NoOfRecs >= MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		clrKyb();
		b = itemEntry(sku);

		printf("Add Item? (Y)es/(N)o: ");
		ns = yes();

		if (ns == 1)
		{
			b.sku = sku;
			item[*NoOfRecs] = b;
			*NoOfRecs += 1;

			printf("--== Added! ==--\n");
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int Tempsku, i, ns, found = 0;
	printf("Please enter the SKU: ");
	do 
	{
		scanf("%d", &Tempsku);
	} while (Tempsku > SKU_MAX || Tempsku < SKU_MIN);
	for (i = 0; i<*NoOfRecs; i++) 
	{
		if (Tempsku == item[i].sku)
		{
			dspItem(item[i], FORM);
			printf("Item already exists, Update? (Y)es/(N)o: ");
			ns = yes();
			found = 1;
			if (ns == 0)
			{
				printf("--== Aborted! ==--\n");
				break;
			}
			else
			{
				updateItem(&item[i]); //cant run here
				break;
			}
		}
	}
	if (found == 0)
	{
		addItem(item, NoOfRecs, Tempsku);
	}

}

void adjustQty(struct Item item[], int NoOfRecs, int stock)
{
	int found, Tempsku, index, no;
	char tostock[] = "to stock", tocheck[] = "to checkout";
	printf("Please enter the SKU: ");
	scanf("%d", &Tempsku);
	found = locateItem(item, NoOfRecs, Tempsku, &index);
	if (found == 0) 
	{
		printf("SKU not found in storage!\n");
	}
	else {
		dspItem(item[index], FORM);
		if (stock == STOCK)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tostock, MAX_QTY - item[index].quantity);
			scanf("%d", &no);
			if (no == 0)
			{
				printf("--== Aborted! ==--\n");
			}
			else 
			{
				item[index].quantity += no;
				printf("--== Stocked! ==--\n");
			}
		}
		else 
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tocheck, item[index].quantity);
			scanf("%d", &no);
			if (no == 0) 
			{
				printf("--== Aborted! ==--\n");
			}
			else 
			{
				item[index].quantity -= no;
				printf("--== Checked out! ==--\n");
				if (item[index].quantity <= no)
				{
					printf("Quantity is low, please reorder ASAP!!!\n");
				}
			}
		}
	}
}
/*End of Milestone 4 functions
******************************************************************/

/*****************************************************************
Milestone 3 function implementations:
Please copy your milestone 3 functions here: */
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
int yes(void)
{
	char istaxed;
	scanf("%c", &istaxed);
	do {
		if (istaxed == 'Y' || istaxed == 'y')
		{
			return 1;
		}
		else if (istaxed == 'N' || istaxed == 'n')
		{
			return 0;
		}
		else
		{
			//printf("Only (Y)es or (N)o are acceptable:");
			scanf("%c", &istaxed);
		}
	} while (1);
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
	for (i = 0; i < NoOfItems; i++)
	{
		printf("%-4d", i + 1);
		dspItem(item[i], 1);
		grand += totalAfterTax(item[i]);
	}
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





/*End of Milestone 3 functions.
*******************************************************************/

/***************************************************************
Tester Functions DO NOT MODIFY */

void searchTest()
{
   printf("================Search Test:\n");
   printf("Enter 731: \n");
   search(GI, GNoOfRecs);
   printf("Enter 222: \n");
   search(GI, GNoOfRecs);
}
void updateTest() {
   struct Item I = { 11.11,111,1,11,1,"Ones!" };
   printf("================Update Test:\n");
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: n\n");
   updateItem(&I);
   printf("Unchanged Item Data:\n");
   dspItem(I, FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   updateItem(&I);
   printf("Updated Item: \n");
   dspItem(I, FORM);
}
void addTest() 
{
   printf("================Add Test:\n");
   printf("Total items in Storage: %d, Max no: %d\n", GNoOfRecs, MAX_ITEM_NO);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: n\n");
   addItem(GI, &GNoOfRecs, 222); //n
   printf("Garbage here! Nothing is added, No of items in storage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs], FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: y\n");
   addItem(GI, &GNoOfRecs, 222); //y
   printf("New item is added, No of itemsinstorage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs - 1], FORM);
   printf("Adding 333: \n");
   addItem(GI, &GNoOfRecs, 333);
}
void addOrUpdateTest() {
   GNoOfRecs = MAX_ITEM_NO;
   printf("================AddOrUpdate Test:\n");
   printf("Enter 731 and then \'n\':\n");
   addOrUpdateItem(GI, &GNoOfRecs); // n
   printf("Enter 731, \'y\' and then:\n"
      "       Name: Apple\n"
      "      Price: 1.80\n"
      "   Quantity: 101\n"
      "Minimum Qty: 11\n"
      "   Is Taxed: n\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   addOrUpdateItem(GI, &GNoOfRecs); // yes new data Yes
   printf("Updated Item: \n");
   dspItem(GI[16], FORM);
   printf("Enter 444: \n");
   addOrUpdateItem(GI, &GNoOfRecs); //n
}

void adjustQtyTest() 
{
   printf("================AdjustQty Test:\n");
   printf("Invalid SKU Test; Enter 444:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   printf("Aborting Entry test; Enter 731 and then 0:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Checking out with low quantity warning; Enter 731 and then 90:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Stocking; Enter 731 and then 50:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   dspItem(GI[16], FORM);
}

/* End test functions
*********************************************************************/
