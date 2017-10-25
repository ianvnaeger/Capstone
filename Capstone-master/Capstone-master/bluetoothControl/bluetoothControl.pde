import processing.serial.*;
Serial myPort;
String bartenderStatus = "No Drink Selected";

void setup(){
   size(500,600);
   myPort = new Serial(this, "COM6", 38400); 
   myPort.bufferUntil('\n');
   
}

void serialEvent(Serial myPort){
   bartenderStatus = myPort.readStringUntil('\n'); 
}

void draw(){
  //Set up the background color and five rectangles
   background(47,151,255);
   fill(255,255,255);
   stroke(255);
   strokeWeight(1);
   rect(50,400,150,50,10);
   rect(300,400,150,50,10);
   rect(50,500,150,50,10);
   rect(300,500,150,50,10);
   rect(100,150,300,80,10);
   
   //Set up the text for drinks
   fill(47,151,255);
   textSize(32);
   text("Drink 1",65,435);
   text("Drink 2",315,435);
   text("Drink 3",65,535);
   text("Drink 4",315,535);
   
   //Set up the text for the topic of bartender status
   fill(255,255,255);
   textSize(45);
   text("Bartender Status:",65,100);
   
   //Set up the text for the bartender status
   fill(47,151,255);
   textSize(32);
   text(bartenderStatus,110,200);
   
   //When drink 1 is selected
   if (mousePressed && mouseX>50 && mouseX<200 && mouseY>400 & mouseY<450){
      
      myPort.write('A');
      
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(50,400,150,50,10);  
   }
   
   //When drink 2 is selected
   if (mousePressed && mouseX>300 && mouseX<450 && mouseY>400 & mouseY<450){
      myPort.write('B');
      
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(300,400,150,50,10);  
   }
   
   
   //When drink 3 is selected
   if (mousePressed && mouseX>50 && mouseX<200 && mouseY>500 & mouseY<550){
      myPort.write('C');
      
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(50,500,150,50,10);  
   }
   
   //When drink 4 is selected
   if (mousePressed && mouseX>300 && mouseX<450 && mouseY>500 & mouseY<550){
      myPort.write('D');
      
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(300,500,150,50,10);  
   }  
   
}