// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm"}
    ]
};
window.onload = function()
{
    var contnt = document.querySelector("#movie");
    var pic = ""; 
    for(var strt=0;strt<video.source.length;strt++)
    {
        pic += "<figure>" +"<video width ='"+video.width + "'height ='"+video.height + "'controls>" + "<source src = '" + video.source[strt].src + "' type = '" + video.source[strt].type + "'/>" + "</video>" + "</figure>";
    }  
    contnt.innerHTML = pic; 
};
