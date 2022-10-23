uint8_t IR1 = 0;
uint8_t IR2 = 0;
uint8_t IR3 = 0;
uint8_t IR4 = 0;
uint8_t IR5 = 0;
uint8_t IRread = 0;
// Sensor read out
uint8_t black = 0; // Detect black line read out == 0
uint8_t white = 1; // Detect white area read out == 1

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
    else
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
    else
    {
      do
      {
        Motor(spl, spr);
        IR2 = digitalRead(s2);
        IR4 = digitalRead(s4);
      } while ((IR2 == black) && (IR3 == black));
      Motor(0, 0);
      break;
    }
  }
}

void FFL(int spl, int spr) //เดินตามเส้นเจอแยกซ้ายข้ามแล้วหยุด
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);

    if ((IR1 == black) && (IR2 == black) && (IR3 == black)) { // Exit loop when Sensor IR1, 2 and 3 no longer detect black line
      while ((IR1 == black) && (IR2 == black) && (IR3 == black)) {
        Motor(spl, spr);
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
      }
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

void FFR(int spl, int spr) //เดินตามเส้นเจอแยกขวาข้ามแล้วหยุด
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    //IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR3 == black) && (IR4 == black) && (IR5 == black)) {
      while ((IR3 == black) && (IR4 == black) && (IR5 == black)) {
        Motor(spl, spr);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        IR5 = digitalRead(s5);
      }
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
      do
      {
        Motor(0, spr);
        IR1 = digitalRead(s1);
        IR3 = digitalRead(s3);
        IR5 = digitalRead(s5);
      } while ((IR1 == black) || (IR3 == white) || (IR5 == black));
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
      do
      {
        Motor(spl, 0);
        IR1 = digitalRead(s1);
        IR3 = digitalRead(s3);
        IR5 = digitalRead(s5);
      } while ((IR1 == black) || (IR3 == white) || (IR5 == black));
      Motor(0, 0);
      break;
    }
  }
}

void DL(int spl, int spr) // เดินไปส่งคนซ้าย
{
  while (1)
  {
    IR1 = digitalRead(s1);
    IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    //IR4 = digitalRead(s4);
    //IR5 = digitalRead(s5);

    if ((IR1 == black) && (IR2 == black) && (IR3 == black))
    {
      IR1 = digitalRead(s1);
      IR2 = digitalRead(s2);
      IR3 = digitalRead(s3);
      while ((IR1 == black) && (IR2 == black) && (IR3 == black))
      {
        Motor(spl, spr);
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
      }
      while (1)
      {
        Motor(spl, spr);
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        if ((IR1 == black) && (IR2 == black) && (IR3 == black))
        {
          //ส่งคน
          Motor(0, 0);
          delay(5000);
          IR1 = digitalRead(s1);
          IR2 = digitalRead(s2);
          IR3 = digitalRead(s3);
          while ((IR1 == black) && (IR2 == black) && (IR3 == black))
          {
            Motor(spl, spr);
            IR1 = digitalRead(s1);
            IR2 = digitalRead(s2);
            IR3 = digitalRead(s3);
          }
          Motor(0, 0);
          break;
        }
      }
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

void DR(int spl, int spr) // เดินไปส่งคนซ้าย
{
  while (1)
  {
    //IR1 = digitalRead(s1);
    //IR2 = digitalRead(s2);
    IR3 = digitalRead(s3);
    IR4 = digitalRead(s4);
    IR5 = digitalRead(s5);

    if ((IR3 == black) && (IR4 == black) && (IR5 == black))
    {
      IR3 = digitalRead(s3);
      IR4 = digitalRead(s4);
      IR5 = digitalRead(s5);
      while ((IR3 == black) && (IR4 == black) && (IR5 == black))
      {
        Motor(spl, spr);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        IR5 = digitalRead(s5);
      }
      while (1)
      {
        Motor(spl, spr);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);
        IR5 = digitalRead(s5);
        if ((IR3 == black) && (IR4 == black) && (IR5 == black))
        {
          //ส่งคน
          Motor(0, 0);
          delay(5000);
          IR3 = digitalRead(s3);
          IR4 = digitalRead(s4);
          IR5 = digitalRead(s5);
          while ((IR3 == black) && (IR4 == black) && (IR5 == black))
          {
            Motor(spl, spr);
            IR3 = digitalRead(s3);
            IR4 = digitalRead(s4);
            IR5 = digitalRead(s5);
          }
          Motor(0, 0);
          break;
        }
      }
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

void path(int spl, int spr) //ทางม้าลาย
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
    Motor(0, 0);
    tone(Buz, 1500);
    delay(5000);
    noTone(Buz);
    int cnt = 0;
    FF(spl, spr);
    FF(spl, spr);
  }
}

void EvadeL(int spl, int spr) //หลบทางซ้าย
{
  Motor(-spl, -spr);
  delay(500); // กะ
  do
  {
    Motor(spl, -spr);
    IR1 = digitalRead(s1);
  } while (IR1 == white);
  Motor(0, spr);
  delay(500); //กะ
  Motor(spl, spr);
  delay(1000); //กะ
  do
  {
    Motor(0, spr);
    IR3 = digitalRead(s3);
  } while (IR3 == white);
  Motor(spl, 0);
  delay(500); //กะ
  Motor(0, 0);
}

void EvadeR(int spl, int spr) //หลบทางขวา
{
  Motor(-spl, -spr);
  delay(500); // กะ
  do
  {
    Motor(-spl, spr);
    IR5 = digitalRead(s5);
  } while (IR5 == white);
  Motor(spl, 0);
  delay(500); //กะ
  Motor(spl, spr);
  delay(1000); //กะ
  do
  {
    Motor(spl, 0);
    IR3 = digitalRead(s3);
  } while (IR3 == white);
  Motor(0, spr);
  delay(500); //กะ
  Motor(0, 0);
}

void EnterBlack(int spl, int spr) // เข้าเขตมืด
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
      black = 1;
      white = 0;
      Motor(0, 0);
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
      black = 0;
      white = 1;
      Motor(0, 0);
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
    while (1)
    {
      Motor(-spl, -spr);
      IR2 = digitalRead(s2);
      IR3 = digitalRead(s3);
      IR4 = digitalRead(s4);

      if ((IR2 == white) && (IR4 == white) && (IR3 == black))
        break;
    }
    while (1)
    {
      Motor(-spl, spr);
      IR2 = digitalRead(s2);
      if (IR2 == black)
      {
        while (1)
        {
          Motor(-spl, spr);
          IR3 = digitalRead(s3);
          if (IR3 == black)
            break;
        }
        Motor(0, 0);
        break;
      }
    }
  }
}

void branchL1(int spl, int spr) // เลี้ยวกิ่งแคบซ้าย
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
      while (1)
      {
        Motor(0, spr);
        IR1 = digitalRead(s1);
        if (IR1 == black)
        {
          while (1)
          {
            Motor(-spl, spr);
            IR3 = digitalRead(s3);
            if (IR3 == black)
              break;
          }
          Motor(0, 0);
          break;
        }
      }
    }
  }
}

void branchL2(int spl, int spr) // เลี้ยวกิ่งกว้างซ้าย
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
    else
    {
      while (1)
      {
        Motor(0, spr);
        IR1 = digitalRead(s1);
        if (IR1 == black)
        {
          while (1)
          {
            Motor(-spl, spr);
            IR3 = digitalRead(s3);
            if (IR3 == black)
              break;
          }
          Motor(0, 0);
          break;
        }
      }
    }
  }
}

void branchR1(int spl, int spr) // เลี้ยวกิ่งแคบขวา
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
      while (1)
      {
        Motor(spl, 0);
        IR5 = digitalRead(s5);
        if (IR5 == black)
        {
          while (1)
          {
            Motor(spl, -spr);
            IR3 = digitalRead(s3);
            if (IR3 == black)
              break;
          }
          Motor(0, 0);
          break;
        }
      }
    }
  }
}

void branchR2(int spl, int spr) // เลี้ยวกิ่งกว้างขวา
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
    else
    {
      while (1)
      {
        Motor(spl, 0);
        IR5 = digitalRead(s5);
        if (IR5 == black)
        {
          while (1)
          {
            Motor(spl, -spr);
            IR3 = digitalRead(s3);
            if (IR3 == black)
              break;
          }
          Motor(0, 0);
          break;
        }
      }
    }
  }
}

void accident(int spl, int spr)
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
    else
    {
      Motor(0, 0);
      while (1)
      {
        Motor(-spl, -spr);
        IR1 = digitalRead(s1);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);

        if ((IR2 == black) && (IR1 == white) && (IR3 == black))
        {
          break;
        }
      }
      uint8_t d = 0;
      while (1)
      {
        Motor(-spl, spr);
        IR3 = digitalRead(s3);
        if (IR3 == white)
          d = 1;

        IR3 = digitalRead(s3);
        if ((IR3 == black) && (d == 1))
        {
          Motor(0, 0);
          break;
        }
      }
      break;
    }

  }
}

void traffic(int spl, int spr)
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
    else
    {
      Motor(0, 0);
      delay(6000);
      FF(spl, spr);
      FF(spl, spr);
    }
  }
}

void L(int spl, int spr) //เลี้ยวแยกครึ่งซ้าย
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
      while (1)
      {
        Motor(spl, -spr);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);

        if ((IR2 == white) && (IR4 == white) && (IR3 == black))
        {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}

void R(int spl, int spr) //เลี้ยวแยกครึ่งขวา
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
      while (1)
      {
        Motor(-spl, spr);
        IR2 = digitalRead(s2);
        IR3 = digitalRead(s3);
        IR4 = digitalRead(s4);

        if ((IR2 == white) && (IR4 == white) && (IR3 == black))
        {
          Motor(0, 0);
          break;
        }
      }
      break;
    }
  }
}
