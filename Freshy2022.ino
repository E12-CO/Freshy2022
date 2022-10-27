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

uint8_t spd = 40;
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
  IFFR(spd,spd);
  
//  //game();
//  //เข้าเขตมืด
//  EnterBlack(spd, spd);
//
//  //ข้ามจุด3
//  FFR(spd, spd);
//  FFR(spd, spd);
//
//  //เจอกิ่ง
//
//  //ส่งคนจุด2 ซ้าย
//  DL(spd, spd);
//
//  //เจอกิ่ง
//
//  //ส่งคนจุด3 ขวา
//  DR(spd, spd);
//
//  //ออกจากเขตมืด
//  LeaveBlack(spd, spd);

}



void game()
{
  FF(spd,spd);
  
  //เลี้ยวเข้าครั้งแรก
  FR(spd, spd);

  //เดินตรงจนเจอเขตลดความเร็ว
  FF(spd, spd);

  //เข้าเขตลดความเร็ว
  spd = 30;
  FF(spd, spd);

  //ออกเขตลดความเร็ว
  spd = 40;

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
//  FFR(spd, spd);
//  FFR(spd, spd);
  darkone(spd, spd);
  
  //เจอกิ่ง

  //ส่งคนจุด2 ซ้าย
  //DL(spd, spd);
  darktwo(spd,spd);
  
  //เจอกิ่ง

  //ส่งคนจุด3 ขวา
  //DR(spd, spd);
  darkthree(spd,spd);

  //ออกจากเขตมืด
  LeaveBlack(spd, spd);

  //เจออุบัติเหตุ
  accident(spd, spd);

  //หลบทางพัง
  EvadeL(spd, spd);

  //กุว่าแตก

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
  delay(100);
  MotorStop();
}

void loop() {
  // put your main co00000000de here, to run repeatedly:
  read_sensor();
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
