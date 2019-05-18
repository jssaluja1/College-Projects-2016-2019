#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


/********************************************************************
Milestones 1 to 4  prototypes, definitions and etc...*/

/*Milestone 3 and 4 definitions*/

/*Milestone 3 definitions*/
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0

/*Milestone 4 definitions*/
//#define MAX_ITEM_NO 	21
#define MAX_QTY 		999
#define SKU_MAX 		999
#define SKU_MIN 		100
/*End of definitions*/

/*Milestone 1 to 4 prototypes*/

/*Milestone 1 prototypes*/
void welcome(void);
void prnTitle(void);
void prnFooter(double gTotal);
void pause(void);
void clrKyb(void);
int getInt(void);
double getDbl(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDblLimited(double lowerLimit, double upperLimit);

/*Milestone 2 prototypes*/
int yes(void);
void GrocInvSys(void);
int menu(void);

/*Milestone 3 prototypes*/
const double TAX = 0.13;
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

/*Milestone 4 prototypes*/
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);
/*End of prototypes*/

/*End of milestone 1 to 4 stuff
*********************************************************************/



/********************************************************************
Milestone 5 definitions and prototypes*/

#define MAX_ITEM_NO 500   
#define DATAFILE "items.txt" 

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

/*End of milestone 5 definitions and prototypes
*********************************************************************/




/**************************************************************************
TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR
TT       EE         SS             TT       EE          RR     RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
TT       EE               SS       TT       EE          RR  RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
***************************************************************************
Tester for saveItem, loadItem, saveItems and loadItems:
uncomment this to test your functions prior to putting all the code together by adding a * and / here:
*/

/*
void prnFile() {
FILE* tp = fopen("test.txt", "r");
char ch;
if (tp) {
for (; fscanf(tp,"%c", &ch) == 1; putch(ch));
fclose(tp);
}
else {
printf("text.txt not found\n");
}
}


int main(void) {
int i, n;
struct Item GI[3] = {
{ 4.4,275,0,10,2,"Royal Gala Apples" },
{ 5.99,386,0,20,4,"Honeydew Melon" },
{ 3.99,240,0,30,5,"Blueberries" },
};
struct Item I;
struct Item IN[3];
printf("***********Testing saveItem:\n");
printf("Your saveItem saved the following in test.txt: \n");
FILE* tp = fopen("test.txt", "w");
if (tp) {
for (i = 0; i < 3; i++) saveItem(GI[i], tp);
fclose(tp);
prnFile();
}
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItem!\n\n\n");
pause();
printf("***********Testing loadItem:\n");
printf("Your loadItem loaded the following from test.txt: \n");
tp = fopen("test.txt", "r");
if (tp) {
for (i = 0; i < 3; i++) {
loadItem(&I, tp);
dspItem(I, LINEAR);
}
fclose(tp);
tp = fopen("test.txt", "w");
fclose(tp);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItem!\n\n\n");
pause();
printf("***********Testing saveItems:\n");
printf("Your saveItems saved the following in test.txt: \n");
saveItems(GI, "test.txt", 3);
prnFile();
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItems!\n\n\n");
pause();
printf("***********Testing loadItems:\n");
printf("Your loadItems loaded the following from test.txt: \n");
loadItems(IN, "test.txt", &n);
for (i = 0; i < n; i++) {
dspItem(IN[i], LINEAR);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItems!\n\n\n");
pause();
printf("Done!\n");
return 0;
}

*/
/* End MS5 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************/


/********************************************************************

Main function to run the application
uncomment this to test your functions after putting all the code together by adding a * and / here:
*/

int main(void) {
	GrocInvSys();
	return 0;
}


/* End Main function
********************************************************************/





/********************************************************************
Milestone 5 functions*/

//displays and saves items to the text file.
void saveItem(struct Item item, FILE* dataFile) 
{
	// Displays an item's information (SKU, Quantity, minQuantity, Price, isTaxed and Name) and saves it in the text file.
	fprintf(dataFile, "%d,%d,%d,%0.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);

	return;
}
// Displays an item's information (SKU, Quantity, minQuantity, Price, isTaxed and Name) and loads it from the text file.
int loadItem(struct Item* item, FILE* dataFile) {
	FILE *fp = NULL;
	int ret = 0;
	char arr[21];
	fp = fopen("items.txt", "r");
	if (fp != NULL) {
		fscanf(dataFile, "%d,%d,%d,%lf,%d,%21[^\n]", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, arr);

		strcpy(item->name, arr);
		ret = 1;

	}
	return ret;
}



int saveItems(struct Item* item, char fileName[], int NoOfRecs) {
	int decision = 0;
	int i;
	FILE *fp = NULL;
	fp = fopen("items.txt", "w");
	if (fp != NULL) {

		for (i = 0; i < NoOfRecs; i++)
		{

			saveItem(item[i], fp);
		}
		fclose(fp);
		decision = 1;
	}
	else {
		printf("Can't open file");
	}
	return decision;
}


int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr)
{

	FILE *fp = NULL;
	int i;
	int decision = 0;
	fp = fopen("items.txt", "r");
	if (fp != NULL) {
		*NoOfRecsPtr = 19;
		for (i = 0; i < *NoOfRecsPtr; i++) {
			loadItem(&item[i], fp);
		}
		decision = 1;
		fclose(fp);

	}
	else {
		printf("Failed to open file\n");
	}
	return decision;
}
/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/

/*Milestone 1 functions*/
// Displays the welcome message.
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");

	return;
}

// Displays the title.
void prnTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
	return;
}

// Displays the footer.
void prnFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0) {
		printf("                                           Grand Total: |%12.2lf\n", gTotal);

	}
	return;

}

void clrKyb(void) {

	char key;
	do {
		scanf("%c", &key);
	} while (key != '\n');

	return;
}

void pause(void) {

	printf("Press <ENTER> to continue...");
	clrKyb();
	return;
}

int getInt(void) {
	char NL = 'x';
	int value;


	while (NL != '\n') {

		scanf("%d%c", &value, &NL);

		if (NL != '\n') {
			clrKyb();
			printf("Invalid integer, please try again: ");

		}
	}
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit) {
	int Value;
	Value = getInt();
	while (Value < lowerLimit || Value > upperLimit) {
		printf("Invalid value, %d <= value <= %d: ", lowerLimit, upperLimit);

		Value = getInt();
	}
	return Value;

}

double getDbl(void) {
	char DNL = 'y';
	double value;


	while (DNL != '\n')
	{
		scanf("%lf%c", &value, &DNL);
		if (DNL != '\n')
		{
			clrKyb();
			printf("Invalid number, please try again: ");

		}
	}
	return value;
}

double getDblLimited(double lowerLimit, double upperLimit) {
	double Value;
	Value = getDbl();
	while (Value < lowerLimit || Value > upperLimit)
	{
		printf("Invalid value, %lf <= value <= %lf: ", lowerLimit, upperLimit);

		Value = getDbl();
	}
	return Value;
}

/*Milestone 2 functions*/
int yes(void) {
	char Ch;
	int Ret = 0;
	do
	{
		scanf(" %c", &Ch);
		clrKyb();

		if (!((Ch == 'y') || (Ch == 'Y') || (Ch == 'n') || (Ch == 'N')))
		{
			printf("Only (Y)es or (N)o are acceptable: ");
		}

	} while (!((Ch == 'y') || (Ch == 'Y') || (Ch == 'n') || (Ch == 'N')));

	if (Ch == 'Y' || Ch == 'y')
	{
		Ret = 1;
	}
	return Ret;
}

void GrocInvSys(void) {
	struct Item arr[500];
	int hold;
	int li, si, ad, sis;
	int sel;
	int done = 0;



	welcome();

	li = loadItems(arr, DATAFILE, &hold);
	if (li == 0) {
		printf("Could not read from %s.\n", DATAFILE);
	}
	while (!done)

	{
		sel = menu();
		if (sel == 1) {
			printf("List Items!\n");	// Displays the list of items in the items.txt.
			listItems(arr, hold);
			pause();
		}
		else if (sel == 2) {
			printf("Search Items!\n");	// Searches the list for the items in the item.txt. 
			search(arr, hold);
			pause();
		}
		else if (sel == 3) {
			printf("Checkout Item!\n");	// Prompts user to add a quantity number to checkout items.
			adjustQty(arr, hold, CHECKOUT);
			si = saveItems(arr, DATAFILE, hold);
			if (si == 0) {
				printf("could not update data file %s\n", DATAFILE);
				pause();
			}

		}
		else if (sel == 4) {
			printf("Stock Item!\n");	// Prompts user to add a quantity number to stock items.
			adjustQty(arr, hold, STOCK);
			ad = saveItems(arr, DATAFILE, hold);
			if (ad == 0) {
				printf("could not update data file %s\n", DATAFILE);
				pause();
			}
			pause();
		}
		else if (sel == 5) {
			printf("Add/Update Item!\n"); // Prompts user to add or update the items in the items.txt.
			addOrUpdateItem(arr, &hold);
			sis = saveItems(arr, DATAFILE, hold);
			if (sis == 0)
			{
				printf("could not update data file %s\n", DATAFILE);
				pause();
			}
			pause();

		}
		else if (sel == 6) {
			printf("Delete Item!\n");
			printf("Not implemented!\n");
			pause();
		}
		else if (sel == 7) {
			printf("Search by name!\n");
			printf("Not implemented!\n");
			pause();
		}
		else if (sel == 0) {
			printf("Exit the program? (Y)es/(N)o : ");	// Prompts user to exit and close the program. 
			done = yes();

		}
	}
	return;
}

int menu(void) {
	int select;						// Prompts user to select option in the input.
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &select);
	clrKyb();

	while (select < 0 || select > 5) {			// Displays the inclusive of 0 to 5.
		printf("Invalid value, 0 < value < 5: "); // Displays the error message.
		scanf("%d", &select);
		clrKyb();
	}
	return select;
}


/*Milestone 3 functions*/
double totalAfterTax(struct Item item) {

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

int isLowQty(struct Item item) {
	int minimum = 1;

	if (item.minQuantity < 5)
	{
		minimum = 0;
	}
	return minimum;
}

struct Item itemEntry(int sku) {
	struct Item data; // Temporary struct to hold the elements. 

	printf("        SKU: %d\n", sku);
	data.sku = sku;

	printf("       Name: ");
	scanf("%20[^\n]", data.name);
	clrKyb();

	printf("      Price: ");
	data.price = getDblLimited(0.01, 1000.00);


	printf("   Quantity: ");
	data.quantity = getIntLimited(1, MAX_QTY);


	printf("Minimum Qty: ");
	data.minQuantity = getIntLimited(0, 100);


	printf("   Is Taxed: ");
	data.isTaxed = yes();

	return data;
}

void dspItem(struct Item item, int linear) {
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


	return;
}

void listItems(const struct Item item[], int NoOfItems) {
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
	return;
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
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

/*Milestone 4 functions*/
void search(const struct Item item[], int NoOfRecs) {
	int tempSku, found, searchIndex;
	printf("Please enter the SKU: ");
	scanf("%d", &tempSku);
	found = locateItem(item, NoOfRecs, tempSku, &searchIndex);
	if (found == 0) {
		printf("Item not found!\n");

	}
	else {
		printf("        SKU: %d\n", tempSku);
		printf("       Name: %s\n", item[searchIndex].name);
		printf("      Price: %.2lf\n", item[searchIndex].price);
		printf("   Quantity: %d\n", item[searchIndex].quantity);
		printf("Minimum Qty: %d\n", item[searchIndex].minQuantity);
		if (item[searchIndex].isTaxed == 1) {
			printf("   Is Taxed: Yes\n");
		}
		else {
			printf("   Is Taxed: No\n");
		}

		if (item[searchIndex].quantity <= item[searchIndex].minQuantity) {
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
	clrKyb();
}

void updateItem(struct Item* itemptr) {
	int sku = itemptr->sku, yn;
	struct Item item;
	printf("Enter new data:\n");
	item = itemEntry(sku);
	item.sku = sku;
	printf("Overwrite old data? (Y)es/(N)o: ");
	yn = yes();

	if (yn == 1) {

		*itemptr = item;
		printf("--== Updated! ==--\n");

	}
	else {
		printf("--== Aborted! ==--\n");
	}

}

void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item temp;
	int decision = 0;

	if (*NoOfRecs >= MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {

		temp = itemEntry(sku);

		printf("Add Item? (Y)es/(N)o: ");
		decision = yes();

		if (decision == 1) {
			temp.sku = sku;
			item[*NoOfRecs] = temp;
			*NoOfRecs += 1;

			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}

	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int tempSku, i, progress, search = 0;
	printf("Please enter the SKU: ");
	do {
		scanf("%d", &tempSku);
	} while (tempSku > SKU_MAX || tempSku < SKU_MIN);
	for (i = 0; i < *NoOfRecs; i++) {
		if (tempSku == item[i].sku) {
			dspItem(item[i], FORM);
			printf("Item already exists, Update? (Y)es/(N)o: ");
			progress = yes();

			search = 1;
			if (progress == 0) {
				printf("--== Aborted! ==--\n");
				break;

			}
			else {
				updateItem(&item[i]);
				break;
			}
		}
	}
	if (search == 0) {
		addItem(item, NoOfRecs, tempSku);
	}

}

void adjustQty(struct Item item[], int NoOfRecs, int stock) {
	int found, sku, index, choseNum;
	char tostock[] = "to stock", tocheck[] = "to checkout";
	printf("Please enter the SKU: ");
	scanf("%d", &sku);
	found = locateItem(item, NoOfRecs, sku, &index);
	if (found == 0) {
		printf("SKU not found in storage!\n");
	}
	else {
		dspItem(item[index], FORM);
		if (stock == STOCK) {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tostock, MAX_QTY - item[index].quantity);
			scanf("%d", &choseNum);
			getIntLimited(1, MAX_QTY);
			printf("Invalid value, 0 < value < 5: ");
			scanf("%d", &choseNum);

			if (choseNum == 0) {
				printf("--== Aborted! ==--\n");
			}
			else {
				item[index].quantity += choseNum;
				printf("--== Stocked! ==--\n");

			}

		}
		else {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tocheck, item[index].quantity);
			scanf("%d", &choseNum);
			printf("Invalid value, 0 < value < %d: ", item[index].quantity);
			getIntLimited(0, item[index].quantity);

			if (choseNum == 0) {

				printf("--== Aborted! ==--\n");
			}

			else {
				item[index].quantity -= choseNum;

				printf("--== Checked out! ==--\n");
				if (item[index].quantity <= choseNum) {
					printf("Quantity is low, please reorder ASAP!!!\n");
				}
			}
		}
	}


}
/*End of milestone 1 to 4 functions
*********************************************************************/

