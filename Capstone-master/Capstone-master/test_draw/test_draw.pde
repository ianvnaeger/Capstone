

void setup() {
  size(500, 600);
  
}


void draw() {
   background(47,151,255);
   fill(255,255,255);
   stroke(255);
   strokeWeight(1);
   rect(50,400,150,50,10);
   rect(300,400,150,50,10);
   rect(50,500,150,50,10);
   rect(300,500,150,50,10);
   rect(100,150,300,80,10);
   
   
   fill(47,151,255);
   textSize(32);
   text("Drink 1",65,435);
   text("Drink 2",315,435);
   text("Drink 3",65,535);
   text("Drink 4",315,535);
   
   fill(255,255,255);
   textSize(45);
   text("Bartender Status:",65,100);
   
   fill(47,151,255);
   textSize(32);
   text("No Drink Selected",110,200);
   
   if (mousePressed && mouseX>50 && mouseX<200 && mouseY>400 & mouseY<450){
      //myPort.write('A');
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(50,400,150,50,10);  
   }
   
   
   if (mousePressed && mouseX>300 && mouseX<450 && mouseY>400 & mouseY<450){
      //myPort.write('B');
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(300,400,150,50,10);  
   }
   
   
   
   if (mousePressed && mouseX>50 && mouseX<200 && mouseY>500 & mouseY<550){
      //myPort.write('C');
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(50,500,150,50,10);  
   }
   
   
   if (mousePressed && mouseX>300 && mouseX<450 && mouseY>500 & mouseY<550){
      //myPort.write('D');
      //Hightlight the buttons in red color when pressed
      stroke(255,0,0);
      strokeWeight(2);
      noFill();
      rect(300,500,150,50,10);  
   }  
   
}