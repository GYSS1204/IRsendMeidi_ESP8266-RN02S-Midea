#include <Arduino.h>
#ifndef  IRSENDMEIDI_H_
#define  IRSENDMEIDI_H_

class IRsendMeidi{
  public:
  void begin_2(); //初始化，放入void setup()中
  explicit IRsendMeidi(uint8_t ir_led);
  void setCodeTime(int marks,int one_spaces,int zero_spaces, int l_marks, int l_spaces, int s_spaces);
  //设置发送码的高低电平时间
  void setTemps(float Temps1);  //设置温度
  void setModes(int Modes1);    //设置模式
  void setFanSpeeds(int FanSpeeds1);   //设置风速
  void setEco(bool Eco);  //开关ECO
  void setPowers(bool Powers);  //开关空调
  void setZBPL(int khz);   //设置载波频率
  void setSwingUD(bool SwingUD);  //开关上下扫风
  void setSwingLR(bool SwingLR);  //开关左右扫风
  void setFZC(bool FZC);   //开关防直吹
  void setTimers(float Timers);  //设置定时
  void Send_Code(uint8_t A, uint8_t B,uint8_t C);  //ABC码发送
};
#endif
