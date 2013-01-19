/**
 * This example is yet to be improved. It does not handle exceptions and may prove faulty.
 */

//Import OSC libs
import oscP5.*;
import netP5.*;

//OSC
OscP5 oscP5;

int[] vals;


void setup() {
  //Graphical
  size(100, 300);
  smooth();
  noStroke();
  //osc
  oscP5 = new OscP5(this, 9997);

  vals = new int[14];
  for (int i = 0; i < vals.length; i++) {
    vals[i] = 0;
  }
  
}

//Main function, draw frame
void draw() {
  background(255);
    fill(0);
    text("Levels : \n", 40, 30);
    for (int i=0 ; i<14 ; i++){
      text(vals[i], 40, 75+i*12);
    }
}


//If new OSC value, update happens here
void oscEvent(OscMessage msg) {
  if(msg.checkAddrPattern("/emokit/channels")){
    println("1) Channel readings:");
    for(int i=0 ; i<14 ; i++){
      vals[i] = msg.get(i).intValue();
      println("[" + i + "] : " + vals[i]);
    }
    println();
  } else if(msg.checkAddrPattern("/emokit/gyro")){
    println("2) Gyro:");
    println("x: " + msg.get(0).intValue() + " ; y: " + msg.get(1).intValue());
    println();
  } else
  if (msg.checkAddrPattern("/emokit/infos")) {
     //Todo
  }
}

