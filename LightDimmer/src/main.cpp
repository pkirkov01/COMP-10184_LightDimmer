// I Petar Kirkov, 000800914 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else.

#include <Arduino.h>

// Variable which gets the digital signal of the button
int iButton;

// State of the button (OFF/DIMMER)
int btnState = 1; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Analog signal value of the light dimmer
  int dimmerValue = analogRead(A0);

  // Read and save the digital signal from the button
  iButton = digitalRead(D5);


  // Turn the LED off if the button state is 1 
  if (btnState == 1)
  {
    // Turn the light off
    digitalWrite(D4, HIGH);

    // Save the current state of the button into a global variable
    btnState = iButton;

  }

  // Turn the light on 
  else
  {
    // Analog signal which dims the light
    analogWrite(D4, dimmerValue);

  }
  
  delay(1);

  // Read the digital signal from the button
  iButton = digitalRead(D5);
  
  
  
}