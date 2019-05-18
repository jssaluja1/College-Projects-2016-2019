
var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];

window.onload = function()
{
      var contnt = document.querySelector("#output");

      var table = "";

      for(var strt=0; strt <users.length; strt++)
      { 
            table += "<tr>" +
                              "<td>" + users[strt].first_name + "</td>" + 
                              "<td>" + users[strt].last_name + "</td>" +
                              "<td>" + users[strt].age + "</td>" +
                              "<td>"  + 
                              "<a href ='mailto:" + users[strt].email + "'>" + users[strt].email + "</a>" + "</td>" + 
                     "</tr>";
      }

      contnt.innerHTML += table; 
};
