// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};

window.onload = function()
{
      var contnt = document.querySelector("#music");

      var listen = ""; 
       for(var strt=0;strt<audio.source.length;strt++)
       {
           listen += "<figure>" + "<audio controls>" + "<source src = '" + audio.source[strt].src + "' type = '" + audio.source[strt].type + "'/>" + "</audio>" + "</figure>";
       }
      contnt.innerHTML = listen; 
};
