 /**********************************
 *          ALL DATA              *
 *  write your CustomerDB Object  *
 *      BELOW this Object         *
 **********************************/

var allData = [
    {type:"store", data:{store_id: 297, name: "Scotiabank - Main Branch", address_id: 1023}},
    {type:"store", data:{store_id: 614, name: "Scotiabank - Hamilton", address_id: 1984}},
    {type:"store", data:{store_id: 193, name: "Scotiabank - Mississauga", address_id: 1757}},
    {type:"customer", data:{customer_id: 26, store_id:297, first_name: "Dave", last_name: "Bennett", email: "dbennett@gmail.com", address_id: 4536, add_date: null}},
    {type:"customer", data:{customer_id: 59, store_id:193, first_name: "John", last_name: "Stevens", email: "jstevens22@hotmail.com", address_id: 2473, add_date: null}},
    {type:"customer", data:{customer_id: 29, store_id:614, first_name: "Sarah", last_name: "Pym", email: "spym99@hotmail.com", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 63, store_id:297, first_name: "Steven", last_name: "Edwards", email: "steven2231@hotmail.com", address_id: 1836, add_date: null}},
    {type:"customer", data:{customer_id: 71, store_id:614, first_name: "Martin", last_name: "Scott", email: "mdog33@gmail.com", address_id: 2727, add_date: null}},
    {type:"customer", data:{customer_id: 24, store_id:614, first_name: "Jonathan", last_name: "Pym", email: "jjpym@yahoo.ca", address_id: 1611, add_date: null}},
    {type:"customer", data:{customer_id: 36, store_id:193, first_name: "Kaitlyn", last_name: "Adams", email: "katy38@hotmail.com", address_id: 5464, add_date: null}},
    {type:"customer", data:{customer_id: 73, store_id:297, first_name: "Melissa", last_name: "Bennett", email: "mbennett@gmail.com", address_id: 4536, add_date: null}},         
    {type:"address", data:{address_id: 1023, address: "2895 Yonge St.", city:"Toronto", province:"ON", postal_code:"L4C02G"}},
    {type:"address", data:{address_id: 1984, address: "3611 Main St. West", city:"Hamilton", province:"ON", postal_code:"R5O8H5"}},
    {type:"address", data:{address_id: 1757, address: "1177 Ontario St. Unit 8", city:"Mississauga", province:"ON", postal_code:"L9H6B3"}},
    {type:"address", data:{address_id: 4536, address: "3945 John St.", city: "Ajax", province: "ON", postal_code: "L7M4T9"}},
    {type:"address", data:{address_id: 2473, address: "391 Baker St. Apt 231", city: "Mississauga", province: "ON", postal_code: "M4T8S3"}},
    {type:"address", data:{address_id: 1611, address: "183 City Ct.", city: "Hamilton", province: "ON", postal_code: "J3T9V2"}},
    {type:"address", data:{address_id: 1836, address: "67 Rhymer Ave.", city: "Stouffville", province: "ON", postal_code: "L3C8H4"}},
    {type:"address", data:{address_id: 2727, address: "287 Brant St. Apt 4A", city: "Waterdown", province: "ON", postal_code: "R93G3P"}},
    {type:"address", data:{address_id: 5464, address: "11 New St. Apt 2B", city: "Brampton", province: "ON", postal_code: "L694R7"}},
];

var CustomerDB = {
  //Properties
  customers: [],
  addresses: [],
  stores: [],
 
  //Methods
   //Customer Methods
  addCustomer: function(customerObj)                          //addCustomer(customerObj) function
    {         
    
        this.customers.push(customerObj);
        this.customers[this.customers.length - 1].add_date = new Date();
    },

  
    outputCustomerById: function(customer_id)
    { //outputCustomerById(customer_id) function
    for (var i = 0 ; i < this.customers.length ; i++) {
     if (customer_id == this.customers[i].customer_id) {
      console.log("Customer " + (this.customers[i]).customer_id + 
                  ": " + (this.customers[i]).first_name + 
                  " " + (this.customers[i]).last_name + 
                  " (" + (this.customers[i]).email + ")");
      console.log("Home Address: " + (this.getAddressById(this.customers[i].address_id)).address + 
                  " " + (this.getAddressById(this.customers[i].address_id)).city + 
                  ", " + (this.getAddressById(this.customers[i].address_id)).province + 
                  ". " + (this.getAddressById(this.customers[i].address_id)).postal_code);
      console.log("Joined: " + this.customers[i].add_date);
      break;
        }
    
    }
  
    },

  outputCustomersByStore: function(store_id) { //outputCustomersByStore(store_id) function
console.log("Customers in Store: " + (this.getStoreById(store_id)).name);
console.log("");

for (var i = 0 ; i < this.customers.length ; i++) {
  if (this.customers[i].store_id == store_id) {
   this.outputCustomerById(this.customers[i].customer_id);
   console.log("");
  }
}
  },
 
  outputAllCustomers: function() {              //outputAllCustomers() function
    console.log("All Customers");
    console.log("");
    
    for(var i = 0 ; i < this.customers.length ; i++) {
      this.outputCustomerById(this.customers[i].customer_id);
      console.log("");
    }
return;
  },
  
  removeCustomerById: function(customer_id) {    //removeCustomerById(customer_id)
    var index;
    var count = 0;
    for (var i = 0 ; i < this.customers.length ; i++) {
     if(customer_id == this.customers[i].customer_id) {
       index = i;
       for(var i = index+1;i<this.customers.lenght;i++){
         if(this.customer[i].address_id == this.customers[index].address_id)
           count++;
         if(count == 0 )
           this.removeAddressById(this.customers[index].address_id);
     }
          
    }
    }
    this.customers.splice(index,1);
  }, 
 
   //Store Methods
  addStore: function(storeObj) {                //addStore(storeObj) function
    this.stores.push(storeObj);
    this.stores[this.stores.length - 1].add_date = new Date();
  },

  getStoreById: function(store_id) { //getStoreById(store_id) function
   for (var i = 0 ; i < this.stores.length ; i++) 
    if (store_id == this.stores[i].store_id) break;
   return store_id == this.stores[i].store_id ? this.stores[i] : {};
  },
 
   outputAllStores: function() {                //outAllStores() function
     console.log("All Stores");
     console.log("");
     
     for (var i = 0 ; i < this.stores.length ; i++) {
      console.log("Store " + this.stores[i].store_id + ": " + this.stores[i].name);
      console.log("Location: " + this.stores[i].address_id + 
                  ": " + (this.getAddressById(this.stores[i].address_id)).address + 
                  " " + (this.getAddressById(this.stores[i].address_id)).city + 
                  ", " + (this.getAddressById(this.stores[i].address_id)).province + 
                  ". " + (this.getAddressById(this.stores[i].address_id)).postal_code);
      console.log("");
     }
   },
 
   //Address Methods
  addAddress: function(addressObj) {            //addAddress(addressObj) function
    this.addresses.push(addressObj);
    this.addresses[this.addresses.length - 1].add_date = new Date(); 
  },

  getAddressById: function(address_id) { //getAddressById(address_id) function
   for (var i = 0 ; i < this.addresses.length ; i++) 
   if (address_id == this.addresses[i].address_id) break;
   return address_id == this.addresses[i].address_id ? this.addresses[i] : {};
  },

 
  outputAllAddresses: function() {              //outputAllAddresses() function
    console.log("All Addresses");
    console.log("");
    
    for (var i = 0 ; i < this.addresses.length ; i++) {
     console.log("Address " + this.addresses[i].address_id + 
                 ": " + this.addresses[i].address + 
                 " " + this.addresses[i].city + 
                 ", " + this.addresses[i].province + 
                 ". " + this.addresses[i].postal_code);
     console.log("");
    }
  },

  removeAddressById: function(address_id) {
     for (var i = 0 ; i < this.addresses.length ; i++) {
      if (address_id == this.addresses[i].address_id){
        this.addresses.splice(i,1);
        }
     }
  },
 
   //insertData methods
  insertData: function(obj) {                   //insertData(obj) function
    switch (obj[obj.length - 1 - this.customers.length - this.addresses.length - this.stores.length].type) {
      case "customer":
        this.addCustomer((obj[obj.length - 1 - this.customers.length - this.addresses.length - this.stores.length]).data);
        break;
      case "address":
        this.addAddress((obj[obj.length - 1 - this.customers.length - this.addresses.length - this.stores.length]).data);
        break;
      case "store":
        this.addStore((obj[obj.length - 1 - this.customers.length - this.addresses.length - this.stores.length]).data);
        break;
    }
   if (obj.length - this.customers.length - this.addresses.length - this.stores.length != 0) 
    this.insertData(obj);
   return;
  },
 
 
print: function(i) { //temp print function
if (i < this.customers.length)
console.log(this.customers[i]);
else if (i - this.customers.length < this.addresses.length)
console.log(this.addresses[i - this.customers.length]);
else if (i - this.customers.length - this.addresses.length < this.stores.length)
console.log(this.stores[i - this.customers.length - this.addresses.length]);
else
return;
this.print(i + 1); 
}, 
 
};


CustomerDB.insertData(allData);



// output all customers

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n"); 

// output all stores

console.log("CustomerDB.outputAllStores();\n\n--------------------------\n\n");
CustomerDB.outputAllStores();
console.log("--------------------------\n\n"); 

// output all customers in the "Main Branch"

console.log("CustomerDB.outputCustomersByStore(297);\n\n--------------------------\n\n");
CustomerDB.outputCustomersByStore(297);
console.log("--------------------------\n\n"); 

// remove Customer Dave Bennett (customer_id 26) and Martin Scott (customer_id 71)

console.log("CustomerDB.removeCustomerById(26);\nCustomerDB.removeCustomerById(71);\n\n");
CustomerDB.removeCustomerById(26);
CustomerDB.removeCustomerById(71);
console.log("--------------------------\n\n"); 

// output all customers again
// NOTE: Dave Bennett and Martin Scott should be missing

console.log("CustomerDB.outputAllCustomers();\n\n--------------------------\n\n");
CustomerDB.outputAllCustomers();
console.log("--------------------------\n\n");

// output all addresses again
// NOTE: only addrss 287 Brant St. Apt 4A Waterdown, ON. R93G3P should be missing

console.log("CustomerDB.outputAllAddresses();\n\n--------------------------\n\n");
CustomerDB.outputAllAddresses();
console.log("--------------------------\n\n");
