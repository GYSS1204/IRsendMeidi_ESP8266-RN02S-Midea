/*
 * 美的空调遥控器RN02S13红外发射控制库，需配合IRremoteESP8266库使用。
 * 可以控制的参数：温度（精确到0.5），模式，风速，开关机，定时，扫风，ECO，防直吹。
 * 温度设置，17-30，分辨率0.5
 * 设置模式，0自动，1制冷，2制热，3抽湿，4送风
 * 设置风速，0自动，1为20%，2为40%，3为60%，4为80%，5为100%
 * ECO，扫风，防直吹，参数1为打开，参数0为关闭。
 * 作者：光阴似水1204
 * 了解更多请访问www.songzx.top
 * 时间：2021年9月17日
 */
#include <Arduino.h>
#include "IRsendMeidi.h"
#include <IRsend.h>
const uint8_t IR_LED = 4;   //设置发送信号的GPIO引脚号，官方推荐4
IRsendMeidi irsendmeidi(IR_LED);  //声明类对象


void setup() {

irsendmeidi.begin_2();   //初始化
irsendmeidi.setZBPL(40); //设置红外载波频率，单位kHz,不调用此函数则默认38，由于未知原因，我设置为40，示波器测得频率为38左右，当发送信号后没反应时，尝试更改此值。
irsendmeidi.setCodeTime(500,1600,550,4400,4400,5220); //设置信号的高低电平占比，分别为标记位，1位，0位，前导码低电平，前导码高电平，间隔码高电平
//不调用此函数默认为（500,1600,550,4400,4400,5220）

}

void loop() {
      irsendmeidi.setPowers(1); //打开空调
      delay(5000);   
      irsendmeidi.setModes(1);  //设置为制冷模式
      delay(5000);
      irsendmeidi.setTemps(26); //设置温度为26度
      delay(5000);
      irsendmeidi.setTimers(2); //定时2小时
      delay(5000);
      irsendmeidi.setTimers(9.5); //定时9.5小时
      delay(5000);
      irsendmeidi.setFanSpeeds(5); //设置风速为100%
      delay(5000);
      irsendmeidi.setFanSpeeds(1); //设置风速为20%
      delay(5000);
      irsendmeidi.setEco(1);       //打开ECO
      delay(5000);
      irsendmeidi.setEco(0);       //关闭ECO
      delay(5000);
      irsendmeidi.setTemps(26.5);   //设置温度为26.5度
      delay(5000);
      irsendmeidi.setSwingUD(1);   //打开上下扫风
      delay(5000);
      irsendmeidi.setFZC(1);       //打开防直吹模式
      delay(5000);
      irsendmeidi.setPowers(0);    //关闭空调
      delay(10000);

}
