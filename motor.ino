void MotorInit(){// Initialize pin mode
  pinMode(3,OUTPUT); //pwmL
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(6,OUTPUT); //pwmR
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
}

void Motor(int spl , int spr){    // ค่าในตัวเเปลไม่เกิน 100

  if(spl>0 ){   

   analogWrite (3,(spl*255)/100);
   digitalWrite(4,HIGH);
   digitalWrite(2,LOW);
    
  }else if(spl<0 ){

   analogWrite (3,((-spl)*255)/100);
   digitalWrite(4,LOW);
   digitalWrite(2,HIGH);
    
  }else{
   analogWrite (3,255);
   digitalWrite(4,LOW);
   digitalWrite(2,LOW);    
  }

  if(spr>0 ){

   analogWrite (6,(spr*255)/100);
   digitalWrite(7,HIGH);
   digitalWrite(5,LOW);
    
  }else if(spr<0 ){

   analogWrite (6,((-spr)*255)/100);
   digitalWrite(7,LOW);
   digitalWrite(5,HIGH);
    
  }else{
   analogWrite (6,255);
   digitalWrite(7,LOW);
   digitalWrite(5,LOW);    
  }

  if(spl>100){
    spl = 100 ;
  }else if(spl< -100){
           spl = -100 ;
         }

  if(spr>100){
    spr = 100 ;
  }else if(spr< -100){
           spr = -100 ;
         }
  
}
//-------------------------------------------------------------- SWITCH
int sw(int sum){                   
  int val = 0 ;
  if(sum == 3){
     val = digitalRead(Sw3);
    }else{}
  if(sum == 4){  
     val = digitalRead(Sw4);
    }else{}
 return val ; 
}
