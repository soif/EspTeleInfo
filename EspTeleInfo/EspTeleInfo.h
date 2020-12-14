// **********************************************************************************
// ESP8266 WifInfo WEB Server global Include file
// **********************************************************************************
// Creative Commons Attrib Share-Alike License
// You are free to use/extend this library but please abide with the CC-BY-SA license:
// Attribution-NonCommercial-ShareAlike 4.0 International License
// http://creativecommons.org/licenses/by-nc-sa/4.0/
//
// For any explanation about teleinfo ou use , see my blog
// http://hallard.me/category/tinfo
//
// This program works with the Wifinfo board
// see schematic here https://github.com/hallard/teleinfo/tree/master/Wifinfo
//
// Written by Charles-Henri Hallard (http://hallard.me)
//
// History : V1.00 2015-06-14 - First release
//
// All text above must be included in any redistribution.
//
// **********************************************************************************
// Forked into EspTeleInfo by François Déchery
// https://github.com/soif/
// **********************************************************************************

#ifndef ESPTELEINFO_H
#define ESPTELEINFO_H

// Include Arduino header
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <Ticker.h>
//#include <WebSocketsServer.h>
//#include <Hash.h>
#include <LibTeleinfo.h>
#include <FS.h>

extern "C" {
#include "user_interface.h"
}

#include "webserver.h"
#include "webclient.h"
#include "config.h"
#include "PString.h"

// Version #################################################################
#define ESPTELEINFO_VERSION "2.1.0b2"


// Pins ###########################################################
#define RED_LED_PIN		12	//D8
#define RGB_LED_PIN_R	14	//D5
#define RGB_LED_PIN_G	0		//D3
#define RGB_LED_PIN_B	2		//D4

// Settings #######################################################
//#define OLED_PIN_SDA  4
//#define OLED_PIN_SCL  5
#define OLED_I2C_ID 0x3C
#define OLED_WIDTH  128
#define OLED_HEIGHT  64
#define OLED_UNIT_X  80

#define BLINK_LED_NEW_MS	40		// ms blink (when NEW frame received)
#define BLINK_LED_UPD_MS	200	// ms blink (when UPDated frame received)


// Debug ###########################################################
#define DEBUG
#define INFO
#define DEBUG_SERIAL	Serial1
#define DEBUG_SERIAL1	


// I prefix debug macro to be sure to use specific for THIS library
// debugging, this should not interfere with main sketch or other 
// libraries
#ifdef DEBUG
#define Debug(x)     if (config.config & CFG_DEBUG) { DEBUG_SERIAL.print(x); }
#define Debugln(x)   if (config.config & CFG_DEBUG) { DEBUG_SERIAL.println(x); }
#define DebugF(x)    if (config.config & CFG_DEBUG) { DEBUG_SERIAL.print(F(x)); }
#define DebuglnF(x)  if (config.config & CFG_DEBUG) { DEBUG_SERIAL.println(F(x)); }
#define Debugf(...)  if (config.config & CFG_DEBUG) { DEBUG_SERIAL.printf(__VA_ARGS__); }
#define Debugflush() if (config.config & CFG_DEBUG) { DEBUG_SERIAL.flush(); }
#else
#define Debug(x)     {}
#define Debugln(x)   {}
#define DebugF(x)    {}
#define DebuglnF(x)  {}
#define Debugf(...)  {}
#define Debugflush() {}
#endif

#ifdef INFO
#define Info(x)     if (config.config & CFG_INFO) { DEBUG_SERIAL.print(x); } if (config.config & CFG_INFO) { flogger.print(x); floggerflush(); }
#define Infoln(x)   if (config.config & CFG_INFO) { DEBUG_SERIAL.println(x); } if (config.config & CFG_INFO) { flogger.println(x); floggerflush(); }
#define InfoF(x)    if (config.config & CFG_INFO) { DEBUG_SERIAL.print(F(x)); } if (config.config & CFG_INFO) { flogger.print(F(x)); floggerflush(); }
#define InfolnF(x)  if (config.config & CFG_INFO) { DEBUG_SERIAL.println(F(x)); } if (config.config & CFG_INFO) { flogger.println(F(x)); floggerflush(); }
#define Infof(...)  if (config.config & CFG_INFO) { DEBUG_SERIAL.printf(__VA_ARGS__); } if (config.config & CFG_INFO) { flogger.printf(__VA_ARGS__); floggerflush(); }
#define Infoflush() if (config.config & CFG_INFO) { DEBUG_SERIAL.flush(); }
#else
#define Info(x)    {}
#define Infoln(x)  {}
#define InfoF(x)   {}
#define InfolnF(x) {}
#define Infof(...) {}
#define Infoflush()  {}
#endif

// sysinfo informations
// ===================================================
typedef struct 
{
	String sys_uptime;
} _sysinfo;

// Exported variables/object instancied in main sketch
// ===================================================
extern ESP8266WebServer server;
extern WiFiUDP OTA;
extern TInfo tinfo;
extern uint8_t rgb_brightness;
extern unsigned long seconds;
extern _sysinfo sysinfo;
extern Ticker Tick_emoncms;
extern Ticker Tick_jeedom;
extern Ticker Tick_domoticz;
extern PString flogger;

// Exported function located in main sketch
// ===================================================
void ResetConfig(void);
void Task_emoncms();
void Task_jeedom();
void Task_domoticz();
void Task_domoticz();
void floggerflush();
void LedRgbColor(int rgb[3]);
void LedRgbColorCurrent();
#endif

