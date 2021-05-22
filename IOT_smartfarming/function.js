// khoi tao cac thong so
let btn1 = document.querySelector('#btn1');
let img1 = document.querySelector('#quat_1');
let btn2 = document.querySelector('#btn2');

// functions nut bam
btn1.addEventListener('click', ()=>{
    img1.src = 'img/quat_on.gif'; 
})

btn2.addEventListener('click', ()=>{
    img1.src = 'img/quat.gif';
})
// khoi tao cac thong so
let btn3 = document.querySelector('#btn3');
let img2 = document.querySelector('#tuoi_cay');
let btn4 = document.querySelector('#btn4');

// functions nut bam
btn3.addEventListener('click', ()=>{
    img2.src = 'img/tuoi_cay_on_1.gif'; 
})

btn4.addEventListener('click', ()=>{
    img2.src = 'img/tuoi_cay.gif';
})
// khoi tao cac thong so
let btn5 = document.querySelector('#btn5');
let img3 = document.querySelector('#LED_1');
let btn6 = document.querySelector('#btn6');

// functions nut bam
btn5.addEventListener('click', ()=>{
     img3.src = 'img/den_on_fix.gif' ;
})

btn6.addEventListener('click', ()=>{
    img3.src = 'img/den.gif';
})

$(document).ready(function(){
    var database = firebase.database();
    var ledStatus;
  
    database.ref().on("value", function(snap){
      ledStatus = snap.val().ledStatus;
      if(ledStatus == 1){
        $(".lightStatus").text("The light is on");
      } else {
        $(".lightStatus").text("The light is off");
      }
    });
  
    $(".btn5").click(function(){
      var firebaseRef = firebase.database().ref().child("ledStatus");
  
      {
        firebaseRef.set(1);
        //ledStatus = 1;
      }
    });
    $(".btn6").click(function(){
      var firebaseRef = firebase.database().ref().child("ledStatus");
  
      {
        firebaseRef.set(0);
        //ledStatus = 0;
      } 
    });
  });

