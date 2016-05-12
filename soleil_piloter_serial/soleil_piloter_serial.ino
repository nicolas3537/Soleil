String inputString = "";         // a string to hold incoming data
int valeur = 0;
String second = "";
boolean stringComplete = false;  // whether the string is complete

// gestion des sorties
int ledR = 3;
int ledG = 4;
int ledB = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  //pinMode(PosSoleil, INPUT);
  Serial.begin(115200);
  Serial.println("Hello");
}


void loop() {
  // put your main code here, to run repeatedly:
if (stringComplete) {
      Serial.println(inputString.substring(0,1));
      valeur = inputString.substring(1).toInt();
      Serial.println(valeur);
      if (inputString.substring(0,1) == "r") {
        analogWrite(ledR,inputString.substring(1).toInt());
      }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
      
    }
  }
}
