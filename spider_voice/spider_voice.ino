#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Initialize software serial on pins A0 and A1
SoftwareSerial mySoftwareSerial(A0, A1);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  // Serial communication with the module
  mySoftwareSerial.begin(9600);
  // Initialize Arduino serial
  Serial.begin(115200);
  // Check if the module is responding and if the SD card is found
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Initializing DFPlayer module ... Wait!"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Not initialized:"));
    Serial.println(F("1. Check the DFPlayer Mini connections"));
    Serial.println(F("2. Insert an SD card"));
    while (true)
      ;
  }

  Serial.println();
  Serial.println(F("DFPlayer Mini module initialized!"));
  
  // Set fixed volume to 30
  myDFPlayer.volume(30); // Maximum volume level
  Serial.println(F("Volume set to 30"));

  // Play track 1
  Serial.println(F("Playing track 1"));
   myDFPlayer.play(6);  // Play track 1
  
}

void loop() {
  // No further action required in the loop
 
  
  
}
