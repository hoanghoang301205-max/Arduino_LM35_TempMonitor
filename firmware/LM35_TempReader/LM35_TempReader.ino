int adcValue;
float nhietDo;

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  adcValue = analogRead(A0);
  nhietDo = (adcValue * 500.0) / 1023.0;
  Serial.println(nhietDo, 1);
  delay(1000);
}

//code đuoc cap nhat boi le van hoang 
