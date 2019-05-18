// set a global httpRequest object
//NAME   : JASMEET SINGH SALUJA
//Std No : 102579166

var httpRequest;

window.onload = function()
{
	makeRequest(1);	
}


// TODO: when the page (window) has loaded, make a
// request for page 1

function makeRequest(pageNum) 
{
	
    // TODO: create a variable "url" to store the request to 
	// the current pageNum, ie:
	//
	// "http://reqres.in/api/users?page=1" // for page 1
	// "http://reqres.in/api/users?page=2" // for page 2
	// etc...
	var url="https://reqres.in/api/users?page="+pageNum;
	
	
	
	httpRequest = new XMLHttpRequest();
	
	// show an alert if we were unable to make an XMLHttpRequest object
	
	if (!httpRequest) 
	{
		alert('Cannot create an XMLHTTP instance');
		return false;
	}

	// execute the "showContents" function when
	// the httprequest.onreadystatechange event is fired
	
	httpRequest.onreadystatechange = showContents;
	
	// open a asynchronous HTTP (GET) request with the specified url
	
	httpRequest.open('GET', url, true);
	
	// send the request
	
	httpRequest.send();
}

// the function that handles the server response

function showContents()
{

//  check for response state
//  0      The request is not initialized
//  1      The request has been set up
//  2      The request has been sent
//  3      The request is in process
//  4      The request is complete

	if (httpRequest.readyState === 4)
	{
		// check the response code
		if (httpRequest.status === 200)
		{ // The request has succeeded
		// Javascript function JSON.parse to parse JSON data
			var jsData = JSON.parse(httpRequest.responseText);
			
			// TODO: use the jsData object to populate the correct
			// table cells, ie <tr><td>...</td></tr>
			// in the <tbody> element with id="data"
			
			var TBd= document.querySelector("#data");
			var EMPTY=document.querySelector("#nodata");
			var PAG=jsData.page;
			
			if(document.querySelector("#nodata"))
			{
				TBd.removeChild(EMPTY);
			}
			else
			{
				TBd.removeChild(document.querySelector("#newrow0"));
				TBd.removeChild(document.querySelector("#newrow1"));
				TBd.removeChild(document.querySelector("#newrow2"));
			}
			
		
			
		for (start = 0; start < jsData.data.length; start++)
		{
	
		var TR1 = document.createElement('tr');
		TR1.setAttribute("id","newrow"+start);
		document.getElementById("data").appendChild(TR1);
		
		
		var TD2=document.createElement("td");			
		
		var TxtN2=document.createTextNode(jsData.data[start].id);
		
		TD2.appendChild(TxtN2);
		document.getElementById("newrow"+start).appendChild(TD2);
		
		
			
		var TD3=document.createElement("td");
		var TxtN3=document.createTextNode(jsData.data[start].first_name);
		TD3.appendChild(TxtN3);
		document.getElementById("newrow"+start).appendChild(TD3);
		
		
			
			var TD4=document.createElement("td");
		var TxtN4=document.createTextNode(jsData.data[start].last_name);
		TD4.appendChild(TxtN4);
		document.getElementById("newrow"+start).appendChild(TD4);
		
		
		var IMAGE=document.createElement("img");
		var TD5=document.createElement("td");	
		
		
			
			IMAGE.setAttribute("src",jsData.data[start].avatar);
	    TD5.appendChild(IMAGE);
		document.getElementById("newrow"+start).appendChild(TD5);
		
		}
		
	
			
			// TODO: remove the class "active" from all elements with the class "pgbtn"
			
			var BClick= document.getElementsByClassName("pgbtn");
			for (start = 0; start < BClick.length; start++) 
			{	
				BClick[start].classList.remove("active");
			}
			
			var ACTIVE=document.querySelector("#pgbtn"+PAG);
			ACTIVE.classList.add("active");
			

		}
		
		else
		
		{
			alert('There was a problem with the request.');
		}
	}
}	
