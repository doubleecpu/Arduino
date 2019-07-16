
int received_byte = 0; //variable to store recieved data
int last_byte_value = 0; //last received value not repeat if the (same)/(not changed yet)
void setup() {
  // Begin the Serial at 9600 Baud
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void blink_onboard_led(){
   int counter;
   int max_value;  //current design for 1-10
   max_value = abs(received_byte) % 10; 
   for (counter = 0; counter < max_value; counter++){  
     digitalWrite(LED_BUILTIN, HIGH);   // LED on
     delay(50);                        // wait 
     digitalWrite(LED_BUILTIN, LOW);    // LED off
     delay(50);                        // wait 
   }
   counter = 50 * (10 - max_value);
   delay(1000-counter);
}

void loop() {
  received_byte = Serial.read(); //store the serial data byte
  Serial.println(received_byte);
  if (last_byte_value != received_byte && received_byte != -1){
    blink_onboard_led();   // Blink LED 
  }
  digitalWrite(LED_BUILTIN, LOW);
  last_byte_value = received_byte;
}
