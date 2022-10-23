#define s1 A0
#define s2 A1
#define s3 A2
#define s4 A3
#define s5 A4

#define Buz 8  /*
                  USE tone(Buz ,2000); 
                      noTone(Buz);
*/
#define L1 9
#define L2 10
#define L3 11


#define Sw4 12
#define Sw3 13

uint8_t spd = 200;
uint16_t cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sw3, INPUT);
  pinMode(Sw4, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(Buz, OUTPUT);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  MotorInit();
  
  startt();
}

void game()
{
  //เลี้ยวเข้าครั้งแรก
  FR(spd, spd);

  //เดินตรงจนเจอเขตลดความเร็ว
  FST(spd, spd);

  //เข้าเขตลดความเร็ว
  spd = 100;
  FF(spd, spd);

  //ออกเขตลดความเร็ว
  spd = 200;

  //ส่งคนจุดแรก ขวา
  DR(spd, spd);

  //เจอทางม้าลาย
  path(spd, spd);

  //ข้ามจุดส่ง2
  FFR(spd, spd);
  FFR(spd, spd);

  //หลบทางพัง
  EvadeR(spd, spd);

  //เจอกิ่ง

  //เข้าเขตมืด
  EnterBlack(spd, spd);

  //ข้ามจุด3
  FFR(spd, spd);
  FFR(spd, spd);

  //เจอกิ่ง

  //ส่งคนจุด2 ซ้าย
  DL(spd, spd);

  //เจอกิ่ง

  //ส่งคนจุด3 ขวา
  DR(spd, spd);

  //ออกจากเขตมืด
  LeaveBlack(spd, spd);

  //เจออุบัติเหตุ
  accident(spd, spd);

  //หลบทางพัง
  EvadeL(spd, spd);

  //ข้ามจุด6
  FFR(spd, spd);
  FFR(spd, spd);

  //เลี้ยวกิ่ง
  branchL1(spd, spd);

  //เลี้ยวกิ่ง
  branchL2(spd, spd);

  //ส่งคนที่4 ขวา
  DR(spd, spd);

  //กลับรถ
  rotate(spd, spd);

  //เลี้ยวกิ่ง
  branchR2(spd, spd);

  //ข้ามจุด8
  FFL(spd, spd);
  FFL(spd, spd);

  //เลี้ยวกิ่ง
  branchR2(spd, spd);

  //ส่งคน5 ซ้าย
  DL(spd, spd);

  //เลี้ยวซ้ายแยก
  FL(spd, spd);

  //ข้ามจุด10
  FFR(spd, spd);
  FFR(spd, spd);

  //ไฟแดง
  traffic(spd, spd);

  //เลี้ยวขวา
  R(spd, spd);

  //เข้าจุดเริ่ม
  FF(spd, spd);
  Motor(spd, spd);
  delay(1000);
  Motor(0, 0);
}

void loop() {
  // put your main co00000000de here, to run repeatedly:
  //  Motor(80 ,80);
  //  Serial.println("5555");
  //  delay(2000);
  //    Motor(0 ,80);
  //  Serial.println("5555R");
  //  delay(20040);
  //      Motor(80 ,0);
  //  Serial.println("5555L");
  //  delay(2000);
  //  read_sensor();
}


//UNUSE
//  //กลับรถ
//  rotate(spd,spd);
//
//  //เลี้ยวกิ่ง
//  branchR1(spd,spd);
//
//  //ออกจากเขตมืด
//  LeaveBlack(spd,spd);
//
//  //ส่งคนจุด4 ซ้าย
//  DL(spd,spd);
//
//  //เลี้ยวกิ่ง
//  branchR2(spd,spd);
//
//  //ข้ามจุด7
//  FFL(spd,spd);
//  FFL(spd,spd);
