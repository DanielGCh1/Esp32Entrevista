void setup() {
  Serial.begin(115200);
  Serial.print("hola que hace");
  Serial.println("---");
  pinMode(2, OUTPUT);
}

void loop() {
  
  Serial.println("---");
  Serial.print("hola que hace");


  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
}
