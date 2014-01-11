int led_pin = 13;
int ctl_pin = 11;
int val = 0;
String inputString = "";
boolean dataComplete = false;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_pin, OUTPUT);     
  pinMode(ctl_pin, OUTPUT);
  digitalWrite(ctl_pin, val);
  Serial.begin(9600);
  inputString.reserve(128);
}

// the loop routine runs over and over again forever:
void loop() {
  if (dataComplete)
  {
    Serial.print("Raw: ");
    Serial.println(inputString);
    Serial.print("Val: ");
    val = inputString.toInt();
    Serial.println(val);
    if(val > 255)
    {
      val = 255;
    }
    //if (val < MIN) do start up proceedure
    analogWrite(ctl_pin, val);
    inputString = "";
    dataComplete = false;
  }
}

void serialEvent()
{
  while(!dataComplete && Serial.available())
  {
    char inChar = (char)Serial.read();
    if(inChar == '\n')
    {
      Serial.println();
      dataComplete = true;
    }
    else
    {
      inputString += inChar;
    }
  }
}
