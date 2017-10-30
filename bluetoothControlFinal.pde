import processing.serial.*;
Serial myPort;
String bartenderStatus = "No Drink Selected";

void setup(){
   size(500,600);
   myPort = new Serial(this, "COM5", 38400); 
   myPort.bufferUntil('\n');
   
}

void serialEvent(Serial myPort){
   bartenderStatus = myPort.readStringUntil('\n'); 
}

void draw(){
   background(47,151,255);
   fill(255,255,255);
   stroke(255);
   strokeWeight(1);
   rect(50,400,400,50,10);
   
   
   
   fill(67,151,255);
   textSize(32);
   text("Order A Drink",140,435);
   
   
   fill(255,255,255);
   textSize(45);
   text("Robotic Bartender",60,200);
   
   
   if (mousePressed && mouseX>50 && mouseX<450 && mouseY>400 & mouseY<450){
      myPort.write('A');
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(50,400,400,50,10);  
   }
    
   
}