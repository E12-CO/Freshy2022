void startt(){
  
  delay(500);
  digitalWrite(L1,HIGH);
  delay(200);
  digitalWrite(L2,HIGH);
  delay(200);
  digitalWrite(L3,HIGH);
   tone(Buz,1000); 
  delay(50);
   digitalWrite(L2,LOW);
  delay(50);
    digitalWrite(L3,LOW);
  delay(50);
   digitalWrite(L2,HIGH);
  noTone(Buz);
  digitalWrite(L1,LOW);
  delay(50);
   digitalWrite(L2,LOW);
  delay(50);
    digitalWrite(L3,LOW);
  delay(50);
   digitalWrite(L2,HIGH);
  digitalWrite(L1,HIGH);
  tone(Buz,1000);  
  delay(150);
  noTone(Buz);
   digitalWrite(L2,LOW);
  delay(20);
    digitalWrite(L3,LOW);
  digitalWrite(L1,LOW);
  delay(150);

  // To start the robot, press button number 4.
  while(digitalRead(Sw4)== 0);
  
  delay(1000);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  tone(Buz,1500); 
  delay(100);
  noTone(Buz);
  delay(200);
  tone(Buz,1500); 
  delay(100);
  noTone(Buz);
  
  delay(500);

  tone(Buz,1500); 
  delay(1000);
  noTone(Buz);
  
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L1,LOW);
  
  delay(500);

    
  }
