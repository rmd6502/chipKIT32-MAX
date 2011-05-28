#include "Wiring.h"
#include "SoftSPI.h"

BYTE SoftSPIClass::_SCKpin = 0;
BYTE SoftSPIClass::_SSpin = 0;
BYTE SoftSPIClass::_MOSIpin = 0;
BYTE SoftSPIClass::_MISOpin = 0;

BYTE SoftSPIClass::transfer(BYTE _data) {
  BYTE ret = 0;
  BYTE bitnum = 128;
  BYTE val;

  for (BYTE i = 0; i < 8; ++i) {
    digitalWrite(_SCKpin, HIGH);
    digitalWrite(_MOSIpin, (_data & bitnum) ? HIGH : LOW);
    val = digitalRead(_MISOpin);
    digitalWrite(_SCKpin, LOW);
    ret <<= 1;
    ret |= (val == HIGH ? 1 : 0);
    bitnum >>= 1;
  }
  return ret;
}

  // SPI Configuration methods

void SoftSPIClass::begin(BYTE SSpin, BYTE SCKpin, BYTE MOSIpin, BYTE MISOpin) {
  _SSpin = SSpin;
  _SCKpin = SCKpin;
  _MOSIpin = MOSIpin;
  _MISOpin = MISOpin;

  pinMode(SSpin, OUTPUT);
  pinMode(SCKpin, OUTPUT);
  pinMode(MISOpin, INPUT);
  pinMode(MOSIpin, OUTPUT);
  digitalWrite(SSpin, HIGH);
  digitalWrite(SCKpin, LOW);
}

void SoftSPIClass::end() {
}

void SoftSPIClass::setBitOrder(BYTE) {
}
void SoftSPIClass::setDataMode(WORD) {
}
void SoftSPIClass::setClockDivider(BYTE) {
}
