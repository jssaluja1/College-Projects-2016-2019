// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangoes" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];

window.onload=function()
{
    var ele1 = document.querySelector("#list1");
    var ls1 = "<ol>";
    for(var strt=0;strt<fruits.length;strt++)
    {
        ls1 += "<li>" + fruits[strt] + "</li>";
    }
    ls1+="</ol>";
    ele1.innerHTML=ls1;
    
    var ele2 = document.querySelector("#list2");
    var ls2 = "<ul>";

    for(var strt=0;strt<directory.length;strt++)
    {
        ls2+="<li>";
        if(directory[strt].type == "file")
        {
           ls2+=directory[strt].name;
        }
        else if(directory[strt].type == "directory")
        {
           ls2+=directory[strt].name + "<ul>";
            for(var kstr = 0;kstr<directory[strt].files.length;kstr++)
            {
                ls2 += "<li>" + directory[kstr].files[kstr].name + "</li>";
            }
            ls2+="</ul>";
        }
        ls2+="</li>";
    }
    ls2+="</ul>";
    ele2.innerHTML = list2;
}

