void read_sensor(){
  Serial.print(" s1:");
  Serial.print(digitalRead(A0));
  Serial.print(" s2:");
  Serial.print(digitalRead(A1));
  Serial.print(" s3:");
  Serial.print(digitalRead(A2));
  Serial.print(" s4:");
  Serial.print(digitalRead(A3));
  Serial.print(" s5:");
  Serial.println(digitalRead(A4)); 

  delay(100);
}
