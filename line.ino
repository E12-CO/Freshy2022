uint8_t IR1 = 0;
uint8_t IR2 = 0;
uint8_t IR3 = 0;
uint8_t IR4 = 0;
uint8_t IR5 = 0;
uint8_t IRread = 0;
// Sensor read out
uint8_t black = 1; // Detect black line read out == 0
uint8_t white = 0; // Detect white area read out == 1

void FST(int spl, int spr) //เดินตามเส้นเจอแยกหยุด
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR2 == black) && (IR4 == black) && (IR3 == black))
    {
      Motor(0, 0);
      break;
    }
  }
}

void FF(int spl, int spr) //เดินตามเส้นเจอแยกข้ามแล้วหยุด
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR2 == black) && (IR4 == black) && (IR3 == black))
    {
      Motor(spl, spr);
      while (1)
      {
        IR2 = digitalRead(s2);
        IR4 = digitalRead(s4);
        if (IR2 == white && IR4 == white)
          break;
      }
      MotorStop();
      break;
    }
  }
}

void FFR(int spl, int spr) //เดินตามเส้นเจอแยกซ้ายข้ามแล้วหยุด
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if(IR1 == black)
      digitalWrite(L2, HIGH);
    if ((IR1 == black) && (IR2 == black) && (IR3 == black)) { // Exit loop when Sensor IR1, 2 and 3 no longer detect black line
      do {
        digitalWrite(L1, HIGH);
        Motor(spl, spr);
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
      } while ((IR1 == black) && (IR2 == black) && (IR3 == black));
      digitalWrite(L1, LOW);
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void darkone(int spl, int spr) //เดินตามเส้นเจอแยกซ้ายข้ามแล้วหยุด
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR1 == white) && (IR2 == white) && (IR3 == white)) { // Exit loop when Sensor IR1, 2 and 3 no longer detect black line
      while(1) {
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        if(IR4 == white)
        {
          Motor(spl, 0);
        }
        else if((IR1 == black) && (IR2 == black) && (IR3 == white))
        {
          MotorStop();
          break;
        }
        else
          Motor(spl,spr);
      } 
      digitalWrite(L1, LOW);
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == black) && (IR4 == black))
      Motor(spl, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == black))
      Motor(0, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == black))
      Motor(spl, 0);
  }
}

void darktwo(int spl, int spr) //เดินตามเส้นเจอแยกซ้ายข้ามแล้วหยุด
{
  while (1)
  {
    IR5 = digitalRead(s5);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR5 == white) && (IR4 == white) && (IR3 == white)) { // Exit loop when Sensor IR1, 2 and 3 no longer detect black line
      while(1) {
        IR5 = digitalRead(s5);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        if(IR2 == white)
        {
          Motor(0, spr);
        }
        else if((IR5 == black) && (IR4 == black) && (IR3 == white))
        {
          MotorStop();
          delay(3000);
          break;
        }
        else
          Motor(spl,spr);
      } 
      digitalWrite(L1, LOW);
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == black) && (IR4 == black))
      Motor(spl, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == black))
      Motor(0, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == black))
      Motor(spl, 0);
  }
}

void darkthree(int spl, int spr) //เดินตามเส้นเจอแยกซ้ายข้ามแล้วหยุด
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR1 == white) && (IR2 == white) && (IR3 == white)) { // Exit loop when Sensor IR1, 2 and 3 no longer detect black line
      while(1) {
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        if(IR4 == white)
        {
          Motor(0, spr);
        }
        else if((IR1 == black) && (IR2 == black) && (IR3 == white))
        {
          MotorStop();
          delay(3000);
          break;
        }
        else
          Motor(spl,spr);
      } 
      digitalWrite(L1, LOW);
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == black) && (IR4 == black))
      Motor(spl, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == black))
      Motor(0, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == black))
      Motor(spl, 0);
  }
}

void FFL(int spl, int spr) //เดินตามเส้นเจอแยกขวาข้ามแล้วหยุด
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR3 == black) && (IR4 == black) && (IR5 == black)) {
      do {
        digitalWrite(L1, HIGH);
        Motor(spl, spr);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        IR5 = digitalRead(s5);
      } while ((IR3 == black) && (IR4 == black) && (IR5 == black));
      Motor(0, 0);
      digitalWrite(L1, LOW);
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void FL(int spl, int spr) //เดินตามเส้นเจอแยกข้ามแล้วเลี้ยวซ้าย
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else
    {
      Motor(0, spr);
      delay(500);
      //      do
      //      {
      //        Motor(0, spr);
      //        IR1 = digitalRead(s1);
      //        IR3 = digitalRead(s3);
      //        IR5 = digitalRead(s5);
      //      } while ((IR1 == black) || (IR3 == white) || (IR5 == black));
      Motor(0, 0);
      break;
    }
  }
}

void FR(int spl, int spr) //เดินตามเส้นเจอแยกข้ามแล้วเลี้ยวขวา
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else
    {
      Motor(spl, 0);
      delay(400);
      //      do
      //      {
      //        Motor(spl, 0);
      //        IR1 = digitalRead(s1);
      //        IR3 = digitalRead(s3);
      //        IR5 = digitalRead(s5);
      //      } while ((IR1 == black) || (IR3 == white) || (IR5 == black));
      Motor(0, 0);
      break;
    }
  }
}

void DR(int spl, int spr) // เดินไปส่งคนซ้าย
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR1 == black) && (IR2 == black) && (IR3 == black))
    {
      Motor(spl, spr);
      digitalWrite(L1, HIGH);
      delay(400);
      Motor(0, 0);
      delay(3000);
      digitalWrite(L1, LOW);
      break;
      //      IR1 = digitalRead(s1);
      //      IR2 = digitalRead(s2);
      //      IR3 = digitalRead(s3);
      //      while ((IR1 == black) && (IR2 == black) && (IR3 == black))
      //      {
      //        Motor(spl, spr);
      //        IR1 = digitalRead(s1);
      //        IR2 = digitalRead(s2);
      //        IR3 = digitalRead(s3);
      //      }
      //      while (1)
      //      {
      //        Motor(spl, spr);
      //        IR1 = digitalRead(s1);
      //        IR2 = digitalRead(s2);
      //        IR3 = digitalRead(s3);
      //        if ((IR1 == black) && (IR2 == black) && (IR3 == black))
      //        {
      //          //ส่งคน
      //          Motor(0, 0);
      //          delay(5000);
      //          IR1 = digitalRead(s1);
      //          IR2 = digitalRead(s2);
      //          IR3 = digitalRead(s3);
      //          while ((IR1 == black) && (IR2 == black) && (IR3 == black))
      //          {
      //            Motor(spl, spr);
      //            IR1 = digitalRead(s1);
      //            IR2 = digitalRead(s2);
      //            IR3 = digitalRead(s3);
      //          }
      //          Motor(0, 0);
      //          break;
      //        }
      //      }
      //      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void DL(int spl, int spr) // เดินไปส่งคนซ้าย
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR3 == black) && (IR4 == black) && (IR5 == black))
    {
      Motor(spl, spr);
      digitalWrite(L1, HIGH);
      delay(400);
      Motor(0, 0);
      delay(3000);
      digitalWrite(L1, LOW);
      break;
      //      IR3 = digitalRead(s3);
      //      IR4 = digitalRead(s4);
      //      IR5 = digitalRead(s5);
      //      while ((IR3 == black) && (IR4 == black) && (IR5 == black))
      //      {
      //        Motor(spl, spr);
      //        IR3 = digitalRead(s3);
      //        IR4 = digitalRead(s4);
      //        IR5 = digitalRead(s5);
      //      }
      //      while (1)
      //      {
      //        Motor(spl, spr);
      //        IR3 = digitalRead(s3);
      //        IR4 = digitalRead(s4);
      //        IR5 = digitalRead(s5);
      //        if ((IR3 == black) && (IR4 == black) && (IR5 == black))
      //        {
      //          //ส่งคน
      //          Motor(0, 0);
      //          delay(5000);
      //          IR3 = digitalRead(s3);
      //          IR4 = digitalRead(s4);
      //          IR5 = digitalRead(s5);
      //          while ((IR3 == black) && (IR4 == black) && (IR5 == black))
      //          {
      //            Motor(spl, spr);
      //            IR3 = digitalRead(s3);
      //            IR4 = digitalRead(s4);
      //            IR5 = digitalRead(s5);
      //          }
      //          Motor(0, 0);
      //          break;
      //        }
      //      }
      //      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void path(int spl, int spr) //ทางม้าลาย
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR2 == black) && (IR4 == black) && (IR3 == black))
    {
      digitalWrite(L1, HIGH);
      Motor(0, 0);
      tone(Buz, 1500);
      delay(5000);
      noTone(Buz);
      Motor(spd, spd);
      delay(80);
      FF(spd, spd);
      digitalWrite(L1, LOW);
      break;
    }
  }
}

void EvadeL(int spl, int spr) //untest
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white) && (IR1 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white) && (IR1 == white))
      Motor(spl, 0);
    else if ((IR4 == black) && (IR5 == black) && (IR3 == black))
    {
      digitalWrite(L1, HIGH);
      Motor(spl, -spr);
      while (1)
      {
        IR5 = digitalRead(s5);
        if (IR5 == white)
        {
          MotorStop();
          break;
        }
      }
      Motor(spl, spr);
      delay(400);
      Motor(0, spr);
      delay(500);
      Motor(spl, spr);
      delay(1200);
      Motor(0, spr);
      delay(400);
      Motor(spl, spr);
      delay(500);
      Motor(-spl, spr);
      while (1)
      {
        IR4 = digitalRead(s4);
        if (IR4 == black)
        {
          break;
        }
      }

      Motor(spl, spr);
      while (1)
      {
        IR1 = digitalRead(s1);
        if (IR1 == black)
        {
          break;
        }
      }
      Motor(spl, 0);
      while (1)
      {
        IR4 = digitalRead(s4);
        if (IR4 == black)
        {
          MotorStop();
          break;
        }
      }
      digitalWrite(L1, LOW);
      break;
    }
  }
}

void EvadeR(int spl, int spr) //untest
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white) && (IR1 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white) && (IR1 == white))
      Motor(spl, 0);
    else if ((IR2 == black) && (IR1 == black) && (IR3 == black))
    {
      digitalWrite(L1, HIGH);
      Motor(-spl, spr);
      while (1)
      {
        IR1 = digitalRead(s1);
        if (IR1 == white)
        {
          MotorStop();
          break;
        }
      }
      Motor(spl, spr);
      delay(450);
      Motor(spl, 0);
      delay(350);
      Motor(spl, spr);
      delay(1500);
      IR3 = digitalRead(s3);
      if (IR3 == white)
      {
        Motor(spl, -spr);
        while (1)
        {
          IR2 = digitalRead(s2);
          if (IR2 == black)
          {
            break;
          }
        }

        Motor(spl, spr);
        while (1)
        {
          IR5 = digitalRead(s5);
          if (IR5 == black)
          {
            break;
          }
        }
        Motor(0, spr);
        while (1)
        {
          IR2 = digitalRead(s2);
          if (IR2 == black)
          {
            MotorStop();
            break;
          }
        }
      }
      digitalWrite(L1, LOW);
      break;
    }
  }
}

void reverse()
{
  if(black == 1)
    black = 0;
  else
    black = 1;
  if(white == 1)
    white = 0;
  else
    white = 1;  
}

void EnterBlack(int spl, int spr) // เข้าเขตมืด
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR1 == black) && (IR5 == black) && (IR3 == white))
    {
      digitalWrite(L3, HIGH);
      //reverse();
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void LeaveBlack(int spl, int spr) //ออกเขตมืด
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR2 == black) && (IR4 == black) && (IR3 == white))
    {
      digitalWrite(L3, LOW);
      //reverse();
      MotorStop();
      break;
    }

    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
  }
}

void rotate(int spl, int spr) //กลับรถ
{
  while (1)
  {
    Motor(-spl, -spr);
    while (1)
    {
      IR2 = digitalRead(s2);
      IR3 = digitalRead(s3);
      IR4 = digitalRead(s4);
      if ((IR2 == white) && (IR4 == white) && (IR3 == black))
        break;
    }

    while (1)
    {
      Motor(-spl, spr);
      //delay(500);
      while (1)
      {
        IR1 = digitalRead(s1);
        if (IR1 == black) {
          break;
        }
      }
      while (1)
      {
        IR4 = digitalRead(s4);
        if (IR4 == black) {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
    break;
  }
}

void branchR1(int spl, int spr) // เลี้ยวกิ่งแคบซ้าย
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR3 == black) && (IR2 == black))
    {
      Motor(spl, spr);
      delay(200);
      Motor(spl, -spr);
      while (1)
      {
        IR5 = digitalRead(s5);
        if (IR5 == black)
        {
          break;
        }
      }
      while (1)
      {
        IR2 = digitalRead(s2);
        if (IR2 == black) {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}

void branchR2(int spl, int spr) // เลี้ยวกิ่งกว้างซ้าย
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR3 == black) && (IR2 == black))
    {
      digitalWrite(L1, HIGH);
      Motor(spl, spr);
      delay(300);
      Motor(spl, -spr);
      //      while (1)
      //      {
      //        IR5 = digitalRead(s5);
      //        if (IR5 == black)
      //        {
      //          break;
      //        }
      //      }
      while (1)
      {
        IR2 = digitalRead(s2);
        if (IR2 == black) {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}

void branchL1(int spl, int spr) // เลี้ยวกิ่งแคบขวา
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR3 == black) && (IR4 == black))
    {
      Motor(spl, spr);
      delay(200);
      Motor(-spl, spr);
      while (1)
      {
        IR1 = digitalRead(s1);
        if (IR1 == black)
        {
          break;
        }
      }
      while (1)
      {
        IR4 = digitalRead(s2);
        if (IR4 == black) {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}

void branchL2(int spl, int spr) // เลี้ยวกิ่งกว้างขวา
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR3 == black) && (IR4 == black))
    {
      digitalWrite(L1, HIGH);
      Motor(spl, spr);
      delay(300);
      Motor(-spl, spr);
      //      while (1)
      //      {
      //        IR5 = digitalRead(s5);
      //        if (IR5 == black)
      //        {
      //          break;
      //        }
      //      }
      while (1)
      {
        IR4 = digitalRead(s4);
        if (IR4 == black) {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}

void accident(int spl, int spr) //untest
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR5 == black) && (IR1 == black) && (IR3 == black))
    {
      rotate(spd, spd);
      branchR1(spd, spd);
      break;
    }

  }
}

void traffic(int spl, int spr) //untest
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR2 == black) && (IR4 == black) && (IR3 == black))
    {
      digitalWrite(L2, HIGH);
      MotorStop();
      delay(6000);
      digitalWrite(L2, LOW);
      FF(spl, spr);
      FF(spl, spr);
      break;
    }
  }
}

void R(int spl, int spr) //untest
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR1 == black) && (IR2 == black) && (IR3 == black))
    {
      Motor(spl, spr);
      delay(200);
      Motor(spl, -spr);
      while (1)
      {
        IR4 = digitalRead(s4);
        if ((IR4 == white))
        {
          break;
        }
      }
      while (1)
      {
        IR3 = digitalRead(s3);

        if ((IR3 == black))
        {
          MotorStop();
          break;
        }
      }
      break;
    }
  }
}

void L(int spl, int spr) //untest
{
  while (1)
  {
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR2 == white) && (IR4 == white))
      Motor(spl, spr);
    else if ((IR2 == white) && (IR4 == black) && (IR3 == white))
      Motor(0, spr);
    else if ((IR2 == black) && (IR4 == white) && (IR3 == white))
      Motor(spl, 0);
    else if ((IR3 == black) && (IR4 == black) && (IR5 == black))
    {
      Motor(spl, spr);
      delay(200);
      Motor(-spl, spr);
      while (1)
      {
        IR2 = digitalRead(s2);
        if ((IR2 == white))
        {
          break;
        }
      }
      while (1)
      {
        IR3 = digitalRead(s3);

        if ((IR3 == black))
        {
          MotorStop();
          break;
        }
      }
      break;
    }
  }
}
