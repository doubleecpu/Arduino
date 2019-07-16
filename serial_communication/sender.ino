int send_byte; //String data

void setup() {
  // Begin the Serial at 9600 Baud
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
void generate_random_int(){
  send_byte = random(1,10) % 10;
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW); //indicate not sending
  generate_random_int();
  delay(1500); 
  Serial.write(send_byte); //Tx the send_byte
   //Tx blink indicates sent
  delay(1500); 
}
