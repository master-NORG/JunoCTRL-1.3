#include <EEPROM.h>

//unsigned long hertz = 0;
//long start;
//byte startBlock;
byte brown;
byte initNoteFix = 0;

// Variables for potentiometer functions

const byte analogPin0 = 0;
const byte analogPin1 = 1;
const byte analogPin2 = 2;
const byte analogPin3 = 3;
const byte analogPin4 = 4;
const byte analogPin5 = 5;
const byte analogPin6 = 6;
const byte analogPin7 = 7;

const byte select[] = {2,3,4};
byte getTemp;

byte paramChange[7] = {240,65,54,0,35,32,1};
byte snapShot[7] = {240,65,53,0,35,32,1};

const byte test[3] = {144, 80, 80};

int paramList[36];
int paramValue;
int paramValueCC;
int potSwitch;
int potSwitchVal;
byte allowPotSwitch;
byte all2 = 1;

byte ccModeSelect;

byte potCounter = 0;

byte potParamChart[29] = {11,13,15,12,8,6,14,7, 22,27,33,35,26,25,24,23, 29,34,21,20,30,32,31,28, 18,19,17,16,9};

int rawReadArray[29];

byte potEnable = 0;
byte readBlock = 1;
int low2;
int high2;

byte channel;
int value;
int rawRead;
byte whichAnalogPin;
byte whichParam;
byte lastParam = 128;

#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

//Variables for buttons and leds

int RWcount = 0;

byte ledStateArray[8] = {0,0,0,0,0,0,0,0};

byte ledT2state;
byte ledT3state;
byte ledT4state;
byte ledT5state;

byte butStateT1 = LOW;
byte butStateT2 = LOW;
byte butStateT3 = LOW;
byte butStateT4 = LOW;
byte butStateT5 = LOW;

byte LbutStateT1 = LOW;
byte LbutStateT2 = LOW;
byte LbutStateT3 = LOW;
byte LbutStateT4 = LOW;
byte LbutStateT5 = LOW;

long LdebTimeT1 = 0;
long LdebTimeT2 = 0;
long LdebTimeT3 = 0;
long LdebTimeT4 = 0;
long LdebTimeT5 = 0;
long debdelay = 40;

//MIDI CC OUTPUT MODE related variables

byte chanList[16] = {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191};
byte chanSelect;

byte ccList[37];

byte ModPosSwitch;


//Variables for switch functions

const byte latchPin = 6;
const byte clockPin = 7;
const byte dataPin0 = 5;
const byte dataPin1 = 13;
const byte dataPin2 = 8;
const byte dataPin3 = 9;
const byte dataPin4 = 10;

byte dByte;
byte bByte;

byte shiftdata0[8];
byte shiftdata1[8];
byte shiftdata2[8];
byte shiftdata3[8];
byte shiftdata4[8];

byte byteVal;
int RWcounter = 7;
byte digEnable = 0;
byte latchEn = 1;


//MIDI IN

byte incomingByte;
byte lastIncomingByte = 249;
byte lastIncomingByte2 = 249;

byte ChanMessages[3];
byte xbyte = 1;
byte allow;
byte allow1 = 0;
byte twobyteChan;

int sysCounter = 0;
byte SysMessages[255];

int longSys = 0;
int longCount = 0;
int longOn = 0;
int maxCount = 0;

//CC Conversion Stuff

int paramConA[36];
int paramConB[36];
int conCount1 = 0;
byte conCCList[37];
byte conCCMessages[2];

byte whichCC;
int conCounter = 1;
int lasttemp = 0;
byte lastCCpack[2] = {140, 140};

byte chanListIn[16] = {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191};
byte chanSelectIn;

byte allow2 = 0;
byte allow3 = 1;
byte openGate = 0;

//DUAL MODE variables

byte dualModeOn = 1;

byte dualNoteOff[16] = {128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143};      //zstatus
byte dualNoteOn[16] = {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159};
byte dualAftertouch[16] = {160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175};
byte dualCC[16] = {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191};
byte dualProgram[16] = {192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207};
byte dualChanAfter[16] = {208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223};
byte dualPitchBend[16] = {224,225,226,227,228,229,230,231,232,234,235,236,237,238,239};

byte dualChannelSelect;

byte modPosVar1;
byte modPosVar2;


//ASSIGN variables

byte assignCounter = 0;
byte assignCount = 0;
byte assignOn = 0;
byte assignKnobSelect = 36;
int assignFlashDelay = 0;
int assignFlash = 0;

int assignLastFlash;

byte middleCpressed = 0;

int assignGateOpen = 0;
int assignGateOpen2 = 0;
int assignFlip = 0;

int secondByteAllow = 0;

int assignVal[5];

int assignVal2;

byte tempAllow = 1;
byte assignHeld = 0;

byte trigger = 0;
byte disableSysCon = 0;
long disableClock;

//Chord memory related

byte tempSet = 1;
byte chordHold = 0;
byte assignHold = 0;
byte lightSet = 0;
byte chordMemory;
byte chCount[8];
byte lastChordCount;
//byte chordValtemp[5];

byte chSelect;

byte chord1[5];
byte chord2[5];
byte chord3[5];
byte chord4[5];
byte chord5[5];
byte chord6[5];
byte chord7[5];
byte chord8[5];


byte readingT3;
byte chordTemp;
byte chordAllow = 0;
byte noteOff = 0;

byte notesOn = 0;

byte tempCount = 1;
byte tempdeny = 1;
byte currentNote = 128;
byte chordNotes[6] = {128,128,128,128,128,128};

byte letgo = 1;
byte snapHold = 0;
byte monoChords;
byte lightup = 0;
byte offAllow;

int doubleVal0;
byte doubleSave0;
byte doubleYes0;
int doubleOrig0;

int doubleVal0cc;
byte doubleSave0cc;
byte doubleYes0cc;
int doubleOrig0cc;

int doubleVal1;
byte doubleSave1;
byte doubleYes1;
int doubleOrig1;

int doubleVal1cc;
byte doubleSave1cc;
byte doubleYes1cc;
int doubleOrig1cc;

byte lastModReading;

byte whichChan;
byte chordArray[10] = {128,128,128,128,128,128,128,128,128,128};
byte blockRemove = 1;
byte noteCount = 0;
byte noteMute = 0;

byte tempChordMem;

int chordValtemp1[6];
int chordVal1[6];
byte lowestVal[8];
int add = 0;


//snapshot vars

byte ssArray[108];
byte snapC = 0;
byte ssOpen = 0;
long ssLastMillis;
byte snap2 = 0;

byte dualCCswitched = 0;
byte blockParse = 1;
                                                                              //------------------------------
                                                        //---------------------------------------------
//Functions ----------------------------------------------------------------------------
                                                                      //---------------------------------------------
                                                                                //-------------------------------------
/*
   *⦁ int getValue1(int channel, int analogPin) {
    ⦁ int formatVal(int channel, int value) {
    ⦁ int formatPotSwitchCC(int which, int value) {
    ⦁ int fourPos(byte input) {
    ⦁ int sixPos(byte input) { 
    ⦁ int fourPosCC(int input) { 
    ⦁ byte formatConVal(byte which, byte value) {
    ⦁ void chordSave(int whichNote) {
    ⦁ void ReadWrite() {
    ⦁ void SysexCon2()
    ⦁ void SysexConversion() {
    ⦁ void MidiParsing() {
    ⦁ void longSysFunc() {
    ⦁ void whichChanFunc() {
    ⦁ void regChordMem(int whichNote) {
    ⦁ void findLowest() {
    ⦁ void factoryDefault() {
    ⦁ void SuperAnalogRead() {
    ⦁ void WhichStuff() { 
    ⦁ void chBankWrite(byte chSelect,int i,byte newVal) {
    ⦁ byte chBankRead(byte chSelect,int i) {
    ⦁ modpos() {
 */

int getValue1(int channel, int analogPin) { //zget

  //if(potEnable != 1) {                   //this was for when we were testing the unit reading each value twice and taking the second one

    if (analogPin < 3) {              //if the reading is of a pot connected to a multiplexer this makes the digital outs send the current channel number to the multiplexers
      getTemp = (byte)channel << 2;        //shifts the channel 2 to the left, 000,001,010,011,100,101,111
      PORTD &= B11100011;    //clears the register where the channel value goes
      PORTD = PORTD | getTemp;       //puts the channel in binary to the digital out registers  
      
    }

      #if defined(ADCSRB) && defined(MUX5)
      // the MUX5 bit of ADCSRB selects whether we're reading from channels
      // 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
      ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((analogPin >> 3) & 0x01) << MUX5);
      #endif
      
      // set the analog reference (high two bits of ADMUX) and select the
      // channel (low 4 bits).  this also sets ADLAR (left-adjust result)
      // to 0 (the default).
      #if defined(ADMUX)
      ADMUX = (DEFAULT << 6) | (analogPin & 0x07);
      #endif
  //}
  

  // start the conversion
  sbi(ADCSRA, ADSC);
  
}



int formatVal(int channel, int value) {    //takes the value and channel number and formats the value into what the sysex input will accept on the alphajuno
  int fvalue;
  int tvalue;
  if (channel > 10 && channel < 35) {
    fvalue = value / 8;
  } else {
    if (channel > 6 && channel < 10) {
      if (value < 216) {
        fvalue = 0;
      } else {
        if (value > 215 && value < 532) {
          fvalue = 1;
        } else {
          if (value > 531 && value < 828) {
            fvalue = 2;
          } else {
            if (value > 827) {
              fvalue = 3;
            }
          }
        }
      }
    } else {
      if (channel == 6) {
        if (value < 216) {
          fvalue = 3;
        } else {
          if (value > 215 && value < 532) {
            fvalue = 2;
          } else {
            if (value > 531 && value < 828) {
              fvalue = 1;
            } else {
              if (value > 827) {
                fvalue = 0;
              }
            }
          }
        }
      } else {
      if (channel == 4 || channel == 5) {
        fvalue = value / 171;    //note: not perfectly even, 1024 is not divisible by 6
      } else {
        if (channel == 10) {
          fvalue = value / 512;
        } else {
          if (channel == 35) {
            fvalue = value / 79;    //note: not perfectly even, 1024 is not divisible by 13
          }
        }
      }
    }
    }
  }
  return fvalue;
}

int formatPotSwitchCC(int which, int value) {
  int fvalue;
  if (which > 6 && which < 10) {
    if (ccModeSelect || ModPosSwitch == 2) {
    if (value < 216) {
      fvalue = 0;
    } else {
      if (value > 215 && value < 532) {
        fvalue = 43;
      } else {
        if (value > 531 && value < 828) {
          fvalue = 85;
        } else {
          if (value > 827) {
            fvalue = 127;
          }
        }
      }
    }
    } else {
      fvalue = value / 8;  //this is what you would remove to delete this cc type thang
    }
  } else {
    if (which == 6) {
      if (ccModeSelect || ModPosSwitch == 2) {
    if (value < 216) {
      fvalue = 127;
    } else {
      if (value > 215 && value < 532) {
        fvalue = 85;
      } else {
        if (value > 531 && value < 828) {
          fvalue = 43;
        } else {
          if (value > 827) {
            fvalue = 0;
          }
        }
      }
    }
    } else {
      fvalue = value / 8;
    }
  } else {
    fvalue = value / 8;
  }
  }
    return fvalue;
}


int fourPos(byte input) {    //just makes 0 into position 3 for the 4 pos switch
  int output;
  if (input == 8) {
    output = 3;
  } else {
    if (input == 4) {
      output = 2;
    } else {
      if (input == 0) {
        output = 4;
      } else {
        output = (int)input - 1;
      }
    }
  }
  return output;
}

int sixPos(byte input) {    //just makes 0 into position 5 for the 6 pos switch
  int output;
  if (input == 32) {
    output = 5;
  } else {
    if (input == 4) {
      output = 2;
    } else {
      if (input == 8) {
        output = 3;
      } else {
        if (input == 16) {
          output = 4;
        } else {
          if (input == 0) {
            output = 6;
          } else {
            output = (int)input - 1;
          }
        }
      }
    }
  }
  return output;
}

int fourPosCC(int input) {      // converts switch value to it's proper midi cc format to be outputted
  int output;
      switch (input) {
        case 0:
          output = 0;
          break;
        case 1:
          output = 43;
          break;
        case 2:
          output = 85;
          break;
        case 3:
          output = 127;
          break;
      }
  return output;
}

int sixPosCC(int input) {      //coverts to cc values for 6 pos switch
  int output;
      switch (input) {
        case 0:
          output = 0;
          break;
        case 1:
          output = 26;
          break;
        case 2:
          output = 51;
          break;
        case 3:
          output = 77;
          break;
        case 4:
          output = 102;
          break;
        case 5:
          output = 127;
          break;
      }
  return output;
}

  

byte formatConVal(byte which, byte value) {
  int output;
  if (which > 10 && which != 35) {
    output = value;
  } else {
    if (which == 6) {                   //ccModeSelect
      if (value < 43) {
        output = 0;
      } else {
        if (value > 42 && value < 85) {
          output = 1;
        } else {
          if (value > 84 && value < 127) {
            output = 2;
          } else {
            if (value == 127) {
              output = 3;
            }
          }
        }
      }
      
    } else {
    if (which < 4 || (which < 10 && which > 6)) {
      if (value < 43) {
        output = 0;
      } else {
        if (value > 42 && value < 85) {
          output = 1;
        } else {
          if (value > 84 && value < 127) {
            output = 2;
          } else {
            if (value == 127) {
              output = 3;
            }
          }
        }
      }
    } else {
      if (which == 10) {
        if (value < 127) {
          output = 0;
        } else {
          if (value == 127) {
            output = 1;
          }
        }
      } else {
        if ( which == 4 || which == 5) {
          if (value < 26) {
            output = 0;
          } else {
            if (value > 25 && value < 51) {
              output = 1;
            } else {
              if (value > 50 && value < 77) {
                output = 2;
              } else {
                if (value > 76 && value < 102) {
                  output = 3;
                } else {
                  if (value > 101 && value < 127) {
                    output = 4;
                  } else {
                    if (value == 127) {
                      output = 5;
                    }
                  }
                }
              }
            }
          }
        } else {
          if (which == 35) {
            output = value;
    }
        }
      }
    }
    }
  }
  return output;
}

void chordSave(int whichNote) {
  chordNotes[0] = whichNote;
  for(int i=1;i<6;i++) { //clears chord notes
    chordNotes[i] = 128;
  }
  for (int i=1;i<6;i++) {
    if (i > chCount[chSelect]) { //don't write extra notes to chord array
      break;
    }
    int temp2 = i - 1;
    int temp = whichNote + (chBankRead(chSelect,temp2) - lowestVal[chSelect]);
    if (temp >= 0 && temp < 128) {
      chordNotes[i] = temp;
    } else {
      chordNotes[i] = 128;
    }
  }
}

void ReadWrite() {
  //if (RWcount == 0) {   // not necessary anymore now that it only is done every conversion
      if(latchEn) {
      PORTD |= B01000000;  //latch pin 1    
      PORTD ^= B01000000; //latch pin 0
      latchEn = 0;
      }
      //for (int i=7; i>=0; i--) {
        PORTD ^= B10000000;  //clock pin 0
        dByte = PIND;
        bByte = PINB;
        shiftdata0[RWcounter] = !bitRead(dByte, 5);
        shiftdata1[RWcounter] = !bitRead(bByte, 5);
        shiftdata2[RWcounter] = !bitRead(bByte, 0);
        shiftdata3[RWcounter] = !bitRead(bByte, 1);
        if (RWcounter<3) {
      byte ledtemp = ledStateArray[RWcounter];
      if (ledStateArray[RWcounter] == 1) {
        PORTB |= B00000100;
      } else {
        PORTB &= B11111011;
      }
        //digitalWrite(dataPin4, ledStateArray[i]);
    }
        PORTD |= B10000000;    //clock pin 1
      //}for
  //}
  //potEnable = 0;
  RWcounter--;
  if(RWcounter < 0) {
    RWcounter = 7;
    digEnable = 1;
    latchEn = 1;

  }
}
void SysexCon2() {
  
    if (paramConA[conCount1] != paramConB[conCount1]) {    //these right here check if there is a difference between those two arrays.  This is so the midi-sysex converter isn't converting a value to sysex every midi message, just incase the messages are being sent at too fast of a rate.  just like the pots only get checked once per cycle, in the case of the converter it's 2 checks per cycle.
        for (int count = 0; count<7; count++) {
              Serial.write(paramChange[count]);
        }
        Serial.write(conCount1);
        Serial.write(paramConB[conCount1]);
        Serial.write(247);
        
        paramConA[conCount1] = paramConB[conCount1];
      }
      
      int conCount2 = conCount1 + 18;
      
      if (paramConA[conCount2] != paramConB[conCount2]) {
        if (conCount2 != 35) {
          for (int count = 0; count<7; count++) {
                Serial.write(paramChange[count]);
          }
          Serial.write(conCount2);
          Serial.write(paramConB[conCount2]);
          Serial.write(247);
          paramConA[conCount2] = paramConB[conCount2];
        } else {
          if (paramConB[conCount2] > 0) {
              Serial.write(chanList[dualChannelSelect]);
              Serial.write(65);
              Serial.write(127);
            } else {
              Serial.write(chanList[dualChannelSelect]);
              Serial.write(65);
              Serial.write(0);
            }
            Serial.write(chanList[dualChannelSelect]);
            Serial.write(5);
            Serial.write(paramConB[conCount2]);
        }
        paramConA[conCount2] = paramConB[conCount2];
      }
}



void SysexConversion() {
  if ((ModPosSwitch == 0 || ModPosSwitch == 2)) {                                //CONVERSION FROM CC TO SYSEX zsyscon
        
      if (incomingByte == chanListIn[chanSelectIn]) {
        conCounter = 1;  //resets conCounter variable to 1, which is just a way to alternate which data byte it should be sending
        allow2 = 1;  //open data byte gate
        allow3 = 1;  //allow MIDI PARSING gate open
        openGate = 0;
      } else {
          if (incomingByte > 127 && incomingByte != chanListIn[chanSelectIn] && incomingByte < 248) {  //< 248 stops active sensing (254) from closing gates
          allow2 = 0;  //close data byte gate
          allow3 = 1;  //allow MIDI PARSING gate open
          openGate = 0;
          } else {
            if (incomingByte > 247) {      // 2015-11-29 so this lets system realtime messages through the midi parsing section, otherwise the midi parsing is closed until a status byte from a non-system realtime message is received
              allow3 = 1;
            }
          }
      }
        
      if (allow2 == 1) {            //ALLOW2 is for the data bytes, and gets opened when a applicable status byte is received
        if (incomingByte < 128) {
          lasttemp = 0;  //this is a functional variable resetting that ends up being used to check for duplicate incoming paramter values
          conCounter = !conCounter;
          if (conCounter == 0) {
            for (int i= 0; i<36; i++) {   //compares first data byte to the clist of conversion CCs
              if (incomingByte == conCCList[i]) {  //is there a match?
                allow3 = 0;  //close MIDI PARSING() since there is a match
                openGate = 1;  //if there is a match open the gate
                whichCC = i;  //notes which CC number it matched with
                break;
              } else {
                  allow3 = 1;  //no matches, so allow MIDI PARSING()
                  openGate = 0;  //no matches, so close gate
              }
            }
          }
          
          conCCMessages[conCounter] = incomingByte;  //data byte 1 will be inputed first since conCounter gets set to 0 once the first data byte appears, then when the second appears conCounter sets to 1 so then the data byte 2 gets put in this array
          
      if (openGate == 1) {
        if (conCounter == 1 && incomingByte < 128) {  //if conCounter is 0, it means only the first data byte has appeared, once the serial read gets the second data byte this will open
          allow3 = 0;  //no MIDI parsing
          for (int i=0;i<2;i++) {
            if (lastCCpack[i] == conCCMessages[i]) {  //this checks to see if both of the new data bytes are different from the old ones
              lasttemp++;
            }
          }
          if (lasttemp != 2 && disableSysCon != 1) {  //if last temp equals 2 then it means there was no change in the CC parameter value, so it's not necessary to send out a sysex command
            if(whichCC > 5 && whichCC < 10) {
              paramValue = formatConVal(whichCC, conCCMessages[1]);  //formats cc value into a value that the sysex command will use
             if (paramValue != paramConA[whichCC]) {  //another check to make sure the new value is different from the old one
                  for (int count = 0; count<7; count++) {
                    Serial.write(paramChange[count]);
                  }
                  Serial.write(whichCC);
                  Serial.write(paramValue);
                  Serial.write(247);
                  paramConA[whichCC] = paramValue;
                  paramConB[whichCC] = paramValue;
              }
            } else {
              paramValue = formatConVal(whichCC, conCCMessages[1]);
              paramConB[whichCC] = paramValue;                        //so unless it is a switch parameter, the SyexCon2() takes care of the serial write command that would normally go here
            }
          }
          lasttemp = 0;  //reset this functional variable back to zero
          for (int i=0;i<2;i++) {
            lastCCpack[i] = conCCMessages[i];  //just saves current messages to another arry to compare for duplicates
          }
        }
      }
        }
      }  
    }
}

void MidiParsing() {
  if (allow3 == 1) {                                     //MIDI PARSING BEGINS  <-------------------- zparse
        
      if (incomingByte > 127 && incomingByte < 240) {      //SYSEX OR NOTE/CONTROL MESSAGE?
        if (ModPosSwitch == 2) {
          if (0/*incomingByte == dualCC[(byte)chanSelectIn]*/) {
            allow = 0;        //this checks to see if we are in dual mode or not, then if we are we only let through MIDI messages that are NOT on the current CTRL channel (chanSelecIn)
          } else {
            allow = 1;
            }
        } else {
          allow = 1;
        }
      } else {
          if (incomingByte > 239 && incomingByte < 248) {
            allow = 0;      //this just blocks sysex messages from opening up the dual mode channel switching and chord memory code blocks
          }
      }
  
   
     if (allow == 1) {      //dual mode switching and chord memory section
          

       if (incomingByte > 127 && incomingByte < 240) { //are these midi control messages
         if (ModPosSwitch == 2) {   //if dual mode is selected

          
           if (incomingByte == dualNoteOff[chanSelectIn]) {       //if note received is on the "ctrl" channel, then it gets converted to the "dual" channel, because the Alpha Juno is set to the dual channel and the DAW is sending the midi from the ctrl channel
             ChanMessages[0] = dualNoteOff[dualChannelSelect];
             xbyte = 1;
           } else {
             if (incomingByte == dualNoteOn[chanSelectIn]) {
               ChanMessages[0] = dualNoteOn[dualChannelSelect];
               xbyte = 1;
             } else {
               if (incomingByte == dualCC[chanSelectIn]) {          //same as above for all these messages, you want other cc messages to reach the Alpha Juno, so they need to be converted to dual channel
                ChanMessages[0] = dualCC[dualChannelSelect];
                xbyte = 1;
                dualCCswitched = 1;
               } else {
                  if (incomingByte == dualAftertouch[chanSelectIn]) {
                    ChanMessages[0] = dualAftertouch[dualChannelSelect];
                    xbyte = 1;
                  } else {
                    if (incomingByte == dualProgram[chanSelectIn]) {
                      ChanMessages[0] = dualProgram[dualChannelSelect];
                      xbyte = 1;
                    } else {
                      if (incomingByte == dualChanAfter[chanSelectIn]) {
                        ChanMessages[0] = dualChanAfter[dualChannelSelect];
                        xbyte = 1;
                      } else {
                        if (incomingByte == dualPitchBend[chanSelectIn]) {
                          ChanMessages[0] = dualPitchBend[dualChannelSelect];
                          xbyte = 1;
                        } else {
                          ChanMessages[0] = incomingByte;
                          xbyte = 1;
                        }
                      }
                    }
                  }
               }
             }
           }

           
         } else {
           ChanMessages[0] = incomingByte;
           xbyte = 1;
         }
         if (incomingByte > 191 && incomingByte < 224) {
           twobyteChan = 1;
         } else {
           twobyteChan = 0;
         }
         
         } else {
          
           if(incomingByte < 128) {
           

           
         if (twobyteChan == 1) {
           ChanMessages[1] = incomingByte;
           for (int i=0; i<2; i++) {
             Serial.write(ChanMessages[i]);
           }
         } else {
               xbyte = !xbyte;
               ChanMessages[xbyte + 1] = incomingByte;

               if (xbyte == 1) {        //EVERYTHING THAT FOLLOWS HAPPENS ONCE THE THIRD BYTE IS RECEIVED
                blockParse = 1;
                 
                if (ChanMessages[0] == dualCC[dualChannelSelect] && dualCCswitched == 1) {  //checks if this is a CC message on the dual channel, also checks if this message was originally from the CTRL channel and was switched, if so then we want to block it because it was a cc that was meant only to trigger the sysex and should be blocked
                  for (int i=0;i<37;i++) {
                    if (conCCList[i] == ChanMessages [1]) {//checks to see if one of these cc messages is on the conCC list
                      blockParse = 0;  //blocks the next block of code from executing, therefore stopping the sending of a midi cc for a sysexconverting CC on the dualChannel (cc's on the dual channel won't trigger sysex param changes, but it's just uncessary messages in the output buffer)
                      break;
                    }
                  }
                  dualCCswitched = 0;
                }
              

                 if (blockParse) {
                 
                 if (chordMemory && monoChords) {
                     if ((ChanMessages[0] == dualNoteOn[whichChan]) && (ChanMessages[2] != 0) && notesOn) {      //if note held then activate noteOffs upon pressing new chord
                       offAllow = 1;
                     } else {
                       offAllow = 0;
                     }
                   if (offAllow) {
                     for(int i=0;i<6;i++) {
                       if (i > chCount[chSelect]) {
                         break;
                       }
                       if(chordNotes[i] != 128) {
                         if (ModPosSwitch == 2) {
                           Serial.write(dualNoteOff[dualChannelSelect]);
                         } else {
                           Serial.write(dualNoteOff[chanSelectIn]);
                         }
                         Serial.write(chordNotes[i]);
                         Serial.write(64);
                       }
                     }
                   }
                   offAllow = 0;
                 }


                 
                 
                  //zmem 
                   if (chordMemory && monoChords) {
                       if (ChanMessages[0] == dualNoteOff[whichChan] || (ChanMessages[0] == dualNoteOn[whichChan] && ChanMessages[2] == 0)) {     
                         noteOff = 1;
                       } else {
                         noteOff = 0;         //
                         initNoteFix = 1;
                       }
                     if (noteOff) {   //if note off
                             if (ChanMessages[1] != currentNote && initNoteFix != 0) { //this part needs to exist because in monochord mode if you press a new note without letting go of the last one it automatically sends notes off to the previous note (plus other chordmem notes), so once you actually let go of the previous note then there is no need to send note offs again.
                                 tempdeny = 0;
                             }
                             if (tempdeny) {
                                 for (int i=0; i<3; i++) {
                                     Serial.write(ChanMessages[i]);
                                 }
                                 notesOn = 0;
                             }
                     } else { //if noteOn or anything else than noteOff
                         for (int i=0; i<3; i++) {
                             Serial.write(ChanMessages[i]);  //XXXXXXXXXXXXXXXXXXXXX
                         }
                         if (ChanMessages[0] == dualNoteOn[whichChan]) { //fixed this line Jan 2020, previously chord memory wouldn't work when other midi channel messages were passing through the junoctrl
                           notesOn = 1;
                           currentNote = (int)ChanMessages[1];
                           chordSave((int)ChanMessages[1]);
                         }
                     }
                   noteOff = 0;  
                   } else { //if chordMemory in reg mode aka POLY CHORD MODE
                     if(chordMemory && monoChords == 0) {
                       regChordMem((int)ChanMessages[1]); //call the reg function
                       if(noteMute == 0) {                //okay this is a werid one to explain, basically if there are multiple of the same note on the chord array then you don't want to send a note off signal here, because another chord is still using "pressing" that note, you only signal a note off signal when there are no duplicates of that note... sorry if you're reading this in the future and it's confusing i just can't explain it better, i'm not even 100% clear, but i have an idea right now of how it works, so hopefully this helped
                         for (int i=0; i<3; i++) {
                           Serial.write(ChanMessages[i]);           // XXXXXXXXXX YES ANY TYPE OF MESSAGE CAN BE EXECUTED HERE,NOT JUST MIDI NOTES//@@@@@@@
                         }
                       }
                       
                       noteMute = 0;  //unmute notes
                       
                     } else {         //if chordMemory is off
                       for (int i=0; i<3; i++) {
                         Serial.write(ChanMessages[i]); //XXXXXXXXXXXXXX
                       }
                     }
                   }
                 



              
                   if (chordMemory && tempdeny && monoChords) {
                       if (ChanMessages[0] == dualNoteOff[whichChan] || ChanMessages[0] == dualNoteOn[whichChan]) {
                         chordAllow = 1;
                       } else {
                         chordAllow = 0;
                       }
                     if (chordAllow) {
                       int chordMath;
                       switch(chCount[chSelect]) {
                         case 1:
                           chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {  //keeps it from playing numbers below 0 or above 127
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                             }
                           break;
                           
                         case 2:
                         
                           chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           break;
                           
                           
                         case 3:
                         
                           chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                                Serial.write(ChanMessages[0]);
                                Serial.write(chordMath);
                                Serial.write(ChanMessages[2]);
                           }
                           break;
                           
                         case 4:
                         
                           chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,3) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           break;
                           
                         case 5:
                         
                           chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,3) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           
                           chordTemp = chBankRead(chSelect,4) - lowestVal[chSelect];
                           chordMath = (int)ChanMessages[1] + chordTemp;
                           if (chordMath >= 0 && chordMath < 128) {
                               Serial.write(ChanMessages[0]);
                               Serial.write(chordMath);
                               Serial.write(ChanMessages[2]);
                           }
                           break;
                       }
                       
                     }
                     chordAllow = 0;
                   } else {
                     if (chordMemory && monoChords == 0) {
                         if (ChanMessages[0] == dualNoteOff[whichChan] || ChanMessages[0] == dualNoteOn[whichChan]) {
                           chordAllow = 1;
                         } else {
                           chordAllow = 0;
                         }
                         int chordMath;
                       if (chordAllow) {
                         switch(chCount[chSelect]) {
                           case 1:
                             
                             chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {  //keeps it from playing numbers below 0 or above 127
                               regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                               }
                             break;
                             
                           case 2:
                           
                             chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             break;
                             
                             
                           case 3:
                           
                             chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                  regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             break;
                             
                           case 4:
                           
                             chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,3) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             break;
                             
                           case 5:
                           
                             chordTemp = chBankRead(chSelect,0) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,1) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,2) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,3) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             
                             chordTemp = chBankRead(chSelect,4) - lowestVal[chSelect];
                             chordMath = (int)ChanMessages[1] + chordTemp;
                             if (chordMath >= 0 && chordMath < 128) {
                                 regChordMem(chordMath);
                                 if (noteMute == 0) {
                                   Serial.write(ChanMessages[0]);
                                   Serial.write(chordMath);
                                   Serial.write(ChanMessages[2]);
                                 }
                                 noteMute = 0;
                             }
                             break;
                         } 
                     }
                     }
                   }
                   tempdeny = 1;
                 }

               }  //if(xbyte == 1)

               
           }
         }
       }
        
      }                                // SYSTEM MESSAGES zsmes
      
      if(allow == 0 || incomingByte > 247) {
        
        if (ModPosSwitch != 2) {
          if (incomingByte > 239) {
          
            if (incomingByte == 248) {                       //most common system message first which is timing clock
              Serial.write(incomingByte);
              allow1 = 0;
            } else {
              if (incomingByte == 254) {
                Serial.write(incomingByte);
                allow1 = 0;
              } else {
                switch (incomingByte) {
                  case 240:
                    SysMessages[0] = incomingByte;          //SYSTEM EXCLUSIVE SET FIRST BYTE IN ARRAY
                    sysCounter = 0;
                    allow1 = 1;
                    break;     
                    
                  case 246:                                //SINGLE BYTE system messages
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 250:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 251:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 252:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 255:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                    
                  case 249:                          //undefined messages
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 253:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;        
                    
                    
                  case 241:                                //2 BYTE  system messages SET FIRST BYTE IN ARRAY
                    SysMessages[0] = incomingByte;
                    allow1 = 2;
                    sysCounter = 0;
                    break;
                  case 243:
                    SysMessages[0] = incomingByte;
                    allow1 = 2;
                    sysCounter = 0;
                    break;           
                    
                    
                  case 242:                                  //3 BYTE system messages SET FIRST BYTE IN ARRAY
                    SysMessages[0] = incomingByte;
                    allow1 = 3;
                    sysCounter = 0;
                    break;
                  case 244:                                  //more undefined messages that would just let themselves pass throuhg, but nothing else.  these will still cancel runtime and block the channel voice and mode messages
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                  case 245:
                    Serial.write(incomingByte);
                    allow1 = 0;
                    break;
                }
              }
            }
          }
        
          if (sysCounter > 0) {
            switch (allow1) {            //DEPENDING ON WHICH SYS STATUS BYTE take the following action with data bytes
              case 1:
                  if (sysCounter < 255) {            //the <255 stops the syscounter for triggering the serial write to loop more than 255 bytes which is the maximum allowance for sysex messages.
                    SysMessages[sysCounter] = incomingByte;
                    if (incomingByte == 247) {    
                      allow1 = 0;
                      longSys = 1;
                      maxCount = sysCounter;
                      //for (int i=0; i<=sysCounter; i++) {
                        //Serial.write(SysMessages[i]);  
                      //}
                    }
                  }
                  break;
              case 2:
                  SysMessages[sysCounter] = incomingByte;
                  if (sysCounter == 1) {                  // <--- i think this is the source of the midi timecode bug not working, must test with gear
                    for (int i=0;i<2;i++) {
                      Serial.write(SysMessages[i]);
                    }
                    allow1 = 0;
                  }
                  break;
              case 3:
                  SysMessages[sysCounter] = incomingByte;
                  if (sysCounter == 2) {
                    for (int i=0;i<3;i++) {
                      Serial.write(SysMessages[i]);
                    }
                    allow1 = 0;
                  }
                  break;
            }
          }
          sysCounter++;
         
        }
      }
    }

}

void longSysFunc() {
  if(longSys && longOn == 0) {
      longOn = 1;
      longCount = 0;
    }
    if (longOn) {
        Serial.write(SysMessages[longCount]);
        longCount++;
        if (longCount > maxCount) {
          longOn = 0;
          longSys = 0;
        }
    }
}

void whichChanFunc() {
  switch(ModPosSwitch) {
    case 0:
      whichChan = chanSelectIn;
      break;
    case 1:
      whichChan = chanSelect;
      break;
    case 2:
      whichChan = dualChannelSelect;  //formerly dualChannelSelect
      break;
  }
}
void regChordMem(int whichNote) {
  if (ChanMessages[0] == dualNoteOn[whichChan] && ChanMessages[2] != 0) {
    for (int i=0;i<10;i++) {
      if (chordArray[i] == 128) {
        chordArray[i] = whichNote;
        break;
      }
      if (i == 9) {
        for (int i=0;i<10;i++) {
          chordArray[i] = 128;
        }
        chordArray[0] = whichNote;
      }
    }
  } else {
    if (ChanMessages[0] == dualNoteOff[whichChan] || (ChanMessages[0] == dualNoteOn[whichChan] && ChanMessages[2] == 0)) {      //zwhich
      noteCount = 0;
      blockRemove = 1;
      for (int i=0;i<10;i++) {
        if (whichNote == chordArray[i]) {
          if (blockRemove) {
            chordArray[i] = 128;    //removes note from array
            blockRemove = 0;      //but only 1, if there are duplicates the others remain
          }
          noteCount++;
          if (noteCount > 1) {  //if there are duplicates then note mute gets signaled
            noteMute = 1;
            break;
          }
        }
      }
    }
  }
}

void findLowest() {
                          int a = chordVal1[0];
                          int b = chordVal1[1];
                          int c = chordVal1[2];
                          int d = chordVal1[3];
                          int e = chordVal1[4];
                          int f = chordVal1[5];
                          
                          if (a < b) {
                            lowestVal[chSelect] = a;
                          } else {
                            lowestVal[chSelect] = b;
                          }
                          
                          if (chCount[chSelect] > 2) {
                            if (lowestVal[chSelect] < c) {
                            } else {
                              lowestVal[chSelect] = c;
                            }
                            if (chCount[chSelect] > 3) {
                              if (lowestVal[chSelect] < d) {
                              } else {
                                lowestVal[chSelect] = d;
                              }
                              if (chCount[chSelect] > 4) {
                                if (lowestVal[chSelect] < e) {
                                } else {
                                  lowestVal[chSelect] = e;
                                }
                                if (chCount[chSelect] > 5) {
                                  if (lowestVal[chSelect] < f) {
                                  } else {
                                    lowestVal[chSelect] = f;
                                  }
                                }
                              }
                            }
                          }
}

void factoryDefault() {        // zfact
        int val;
        int val2;
        
        for (int i=0;i<36;i++) {
        val = i+11;
        EEPROM.write(val, val);
        conCCList[i] = val;
        }
        for (int i=0;i<36;i++) {
          val = i + 47;
          val2 = i + 11;
          EEPROM.write(val, val2);
          ccList[i] = val2;
        }
        
        EEPROM.write(0,0);
        EEPROM.write(1,0);
        EEPROM.write(2, 0);
        EEPROM.write(3, 0);
        EEPROM.write(4, 1);
        EEPROM.write(5, 1);
        
        EEPROM.write(6, 51);
        EEPROM.write(7, 55);
        //EEPROM.write(83, 2); formerly chordcount
        EEPROM.write(84, 1); //monoChords on
        //EEPROM.write(85,48);//lowestVal
        EEPROM.write(101, 168); //eeprom factory default automatically if never done before
        
    for(int i=0;i<8;i++) {
      int temp = i+93;
      EEPROM.write(temp,48);      //lowest vals
      lowestVal[i] = 48;
    }
    
    
    EEPROM.write(102,0);    //chSelect
    chSelect = 0;
    
    for (int i=0;i<8;i++) {                  //chCount
        int temp = i+138;
        EEPROM.write(temp,2);
        chCount[i] = 2;
    }
    
    
      for(int i=0;i<5;i++) {                  //chord 1
        int temp = i+6;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord1[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord1[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord1[i] = 128;
          }
        }
      }
      
      for(int i=0;i<5;i++) {                  //chord 2
        int temp = i+103;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord2[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord2[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord2[i] = 128;
          }
        }
      }

      for(int i=0;i<5;i++) {                  //chord 3
        int temp = i+108;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord3[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord3[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord3[i] = 128;
          }
        }
      } 

      for(int i=0;i<5;i++) {                  //chord 4
        int temp = i+113;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord4[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord4[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord4[i] = 128;
          }
        }
      }   

      for(int i=0;i<5;i++) {                  //chord 5
        int temp = i+118;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord5[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord5[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord5[i] = 128;
          }
        }
      }
      
      for(int i=0;i<5;i++) {                  //chord 6
        int temp = i+123;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord6[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord6[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord6[i] = 128;
          }
        }
      }

      for(int i=0;i<5;i++) {                  //chord 7
        int temp = i+128;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord7[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord7[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord7[i] = 128;
          }
        }
      }

      for(int i=0;i<5;i++) {                  //chord 8
        int temp = i+133;
        if(i == 0) {
          EEPROM.write(temp,51);
          chord8[i] = 51;
        } else {
          if (i == 1) {
            EEPROM.write(temp,55);
            chord8[i] = 55;
          } else {
            EEPROM.write(temp,128);
            chord8[i] = 128;
          }
        }
      }
        
        ////chordVal[0] = 51;      //turn this into chord1 stuff
        //chordVal[1] = 55;
        
        //chordCount = 2;
        chordMemory = 0;
        
        ledT4state = 0;
        ledT3state = 0;
        
        chanSelectIn = 0;
        chanSelect = 0;
        dualChannelSelect = 1;
        ccModeSelect = 1;
        monoChords = 1;
        //lowestVal = 48;
        
        snapShot[3] = (byte)chanSelectIn;
        paramChange[3] = (byte)chanSelectIn;
}

void SuperAnalogRead() {

channel = potCounter % 8;
  if (readBlock) {
    getValue1(channel, whichAnalogPin);
    readBlock = 0;
    //delayMicroseconds(50);
  }
if (readBlock == 0 && (bit_is_set(ADCSRA, ADSC)) == 0) {

    low2 = ADCL;
    high2 = ADCH;
    rawRead = (high2 << 8) | low2;        //smooth this here DYLAN
    float rrA;
    float rr;
    rrA = rawReadArray[potCounter];
    rr = rawRead;
    rawReadArray[potCounter] = round((rrA*0.5)+(rr*0.5));
    //rawReadArray[potCounter] = (rawReadArray[potCounter]*0.9) + (rawRead*0.1);
    potEnable = 1;
    
    readBlock = 1;
}
}

void WhichStuff() {        //based on the potCounter determines the multiplexer/pin that needs to be read from and then which parameter the potCounter corresponds to on the alphaJuno
  

  
  if (potCounter < 8) {
  whichAnalogPin = analogPin0;
} else {
  if (potCounter > 7 && potCounter < 16) {
    whichAnalogPin = analogPin1;
  } else {
    whichAnalogPin = analogPin2;
  }
}

whichParam = potParamChart[potCounter];

if (potCounter > 23) {
      whichAnalogPin = potCounter - 21;
}
}

void chBankWrite(byte chSelect,int i,byte newVal) {
  switch(chSelect) {
    case 0:
      chord1[i] = newVal;
      break;
    case 1:
      chord2[i] = newVal;
      break;
    case 2:
      chord3[i] = newVal;
      break;
    case 3:
      chord4[i] = newVal;
      break;
    case 4:
      chord5[i] = newVal;
      break;
    case 5:
      chord6[i] = newVal;
      break;
    case 6:
      chord7[i] = newVal;
      break;
    case 7:
      chord8[i] = newVal;
      break;
  }
}

byte chBankRead(byte chSelect,int i) {
  byte output;
  switch(chSelect) {
    case 0:
      output = chord1[i];
      break;
    case 1:
      output = chord2[i];
      break;
    case 2:
      output = chord3[i];
      break;
    case 3:
      output = chord4[i];
      break;
    case 4:
      output = chord5[i];
      break;
    case 5:
      output = chord6[i];
      break;
    case 6:
      output = chord7[i];
      break;
    case 7:
      output = chord8[i];
      break;
  }
  return output;
}


void modPos() {
  
      if (modPosVar1 == 1) {        
        ModPosSwitch = 1;      //CC mode
        allow3 = 1;
      } else {
        if (modPosVar2 == 1) {
          ModPosSwitch = 2;    //dual mode
          paramChange[3] = (byte)dualChannelSelect;
          snapShot[3] = (byte)dualChannelSelect;
          } else {
            ModPosSwitch = 0;      //CTRL mode
            paramChange[3] = (byte)chanSelectIn;
            snapShot[3] = (byte)chanSelectIn;
          }
        }
}
//Program Begins ---------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//-----------------------------------------------------------------
//--------------------------------------------------
//--------------------------------------
//-------------------------
//-----------------
//-----------
//------
//---
//-
//ENTER THE VOID!!!!!!

void setup() {          //#zset
  
  
  
  if (EEPROM.read(101) != 168) {
    factoryDefault();
  } else {
  
      chordMemory = EEPROM.read(1);
      ccModeSelect = EEPROM.read(5);
      
      chanSelectIn = EEPROM.read(2);
      chanSelect = EEPROM.read(3);
      dualChannelSelect = EEPROM.read(4);
      
      
      //chordCount = EEPROM.read(83);
      monoChords = EEPROM.read(84);
      
      snapShot[3] = (byte)chanSelectIn;
      paramChange[3] = (byte)chanSelectIn;
      
      for (int i=0;i<36;i++) {                      //Sets the conCCList to what is in the EEPROM memory
        int tempval = i + 11;  
        conCCList[i] = EEPROM.read(tempval);
      }
      
    
    
      for (int i=0;i<36;i++) {      //sets the default values of the midi cc output numbers
        int tempval = i + 47;
        ccList[i] = EEPROM.read(tempval);
      }
      
        ledT3state = EEPROM.read(1);
        ledT4state = EEPROM.read(0);
  }
  
  ccList[36] = 36;
  
  
  for(int bit = 0; bit < 3; bit++) {  //configures multipexer select pins for output
    pinMode (select[bit], OUTPUT);
  }
  
    delay(1); //SILVIU ADDED THIS to allow the voltage to settle before the initial analogRead

  for (int i = 0; i<29; i++) {        //gets initial pot potisions
    
    int whichAnalogPin;
    int value;
    
    if (i < 24) {
      if (i < 8) {
        whichAnalogPin = analogPin0;
      } else {
        if (i > 7 && i < 16) {
          whichAnalogPin = analogPin1;
        } else {
          whichAnalogPin = analogPin2;
        }
      }
      getValue1(i, whichAnalogPin);    //starts the adc conversion to read the pot
      
      while(bit_is_set(ADCSRA, ADSC)) {  //waits until the conversion is done before proceeding
      }
      
      low2 = ADCL;
      high2 = ADCH;
      value = (high2 << 8) | low2;      //puts the value into the value variable
      
      int whichParam = potParamChart[i];  //i looks at the potParamChart array, if i=0 this means that it's reading from the first pin of the first multiplexer, the potentiometer on that pin is controlling parameter 11 on the alpha juno.  so i represents ascending order of pins on multiplexer, the potParamChart sets whichParam to the correct parameter on the alpha juno.      paramList[whichParam] = value;
      paramList[whichParam] = value;
      rawReadArray[i] = value;    //PART OF SMOOTHING -- puts the value onto the array which holds which was the last value read on that pin, irrespective of whether that triggers a serial write or not
    } else {
      int whichAnalogPin2 = i - 21;
      value = analogRead(whichAnalogPin2);
      int whichParam = potParamChart[i];
      paramList[whichParam] = value;
      rawReadArray[i] = value;  //PART OF SMOOTHING -- ""          ""         ""
  }
  }

  Serial.begin(31250);
  
  ledT2state = 0;

  
  ledStateArray[0] = ledT2state;      //collects the current state of all the LEDs
  ledStateArray[1] = ledT3state;
  ledStateArray[2] = ledT4state;

  
  pinMode(latchPin, OUTPUT);   // sets pin modes for shift registers
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin0, INPUT);
  pinMode(dataPin1, INPUT);
  pinMode(dataPin2, INPUT);
  pinMode(dataPin3, INPUT);
  pinMode(dataPin4, OUTPUT);
  
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
  digitalWrite(latchPin,0); //this is just so the shiftout register gets reset for sure-- it may not be necessary
  digitalWrite(latchPin, 1);  //collects shiftreg data and makes arrays
  digitalWrite(latchPin,0);
  
  for (int i=7; i>=0; i--) {
    digitalWrite(clockPin, 0);
    shiftdata0[i] = !digitalRead(dataPin0);
    shiftdata1[i] = !digitalRead(dataPin1);
    shiftdata2[i] = !digitalRead(dataPin2);
    shiftdata3[i] = !digitalRead(dataPin3);
    digitalWrite(dataPin4, ledStateArray[i]);
    digitalWrite(clockPin, 1);
  }
  
  
  
  ccList[36] = 36;
  
  
//------------------------------------------------------ take arrays and get switch positions out of them then puts them in the paramList array

    byteVal = 0;                          
      for (int i=3; i>=0; i--) {                // Param 3 - pulse type
      bitWrite(byteVal, i, shiftdata0[i]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
          paramList[3] = svalue;
        }
      }
  
    byteVal = 0;
      for (int i=5; i>3; i--) {                    // Param 4 - Sawtooth type
        int itemp = i - 4;
        bitWrite(byteVal, i, shiftdata3[itemp]);
      }
      for (int i=3; i>=0; i--) {                
      int itemp = i + 4;
      bitWrite(byteVal, i, shiftdata0[itemp]);
      if (i == 0) {
        int svalue = sixPos(byteVal);
          paramList[4] = svalue;
        }
      }
      
    byteVal = 0;
    for (int i=3; i>=0; i--) {                // Param 2 - VCA env mode
    bitWrite(byteVal, i, shiftdata1[i]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
        paramList[2] = svalue;
      }
    }
    

    byteVal = 0;
    for (int i=3; i>=0; i--) {                // Param 0 - DCO env mode
    int itemp = i + 4;
    bitWrite(byteVal, i, shiftdata1[itemp]);
    if (i == 0) {
      byte svalue = fourPos(byteVal);
        paramList[0] = svalue;
      }
    }
 
 
    byteVal = 0;
    for (int i=3; i>=0; i--) {      // Param 1 - VCF env mode
    int itemp = i + 4;     
    bitWrite(byteVal, i, shiftdata2[itemp]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
        paramList[1] = svalue;
      }
    }
   
    byteVal = 0; 
    for (int i=5; i>=0; i--) {                // Param 5 - Sub type
    int itemp = i + 2;
    bitWrite(byteVal, i, shiftdata3[itemp]);
    if (i == 0) {
      int svalue = sixPos(byteVal);
        paramList[5] = svalue;
      }
    }
    
    paramList[10] = ledT4state * 127;              //Chorus state put to paramList
    
    
    for (int i=0;i<36;i++) {
      paramConA[i] = 128;
      paramConB[i] = 128;
    }
    
    //---------eeprom to go elsewhere
    
    
    //done
    
    
    
    
    
    //-----------------------
    
    
      for (int i=0;i<8;i++) {                  //lowest val
        int temp = i+93;
        lowestVal[i] = EEPROM.read(temp);
      }
      
      chSelect = EEPROM.read(102);              //chord select
      
      for (int i=0;i<8;i++) {                  //chord count
        int temp = i+138;
        chCount[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 1
        int temp = i+6;
        chord1[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 2
        int temp = i+103;
        chord2[i] = EEPROM.read(temp);
      }     

      for(int i=0;i<5;i++) {                  //chord 3
        int temp = i+108;
        chord3[i] = EEPROM.read(temp);
      }

      for(int i=0;i<5;i++) {                  //chord 4
        int temp = i+113;
        chord4[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 5  
        int temp = i+118;
        chord5[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 6
        int temp = i+123;
        chord6[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 7
        int temp = i+128;
        chord7[i] = EEPROM.read(temp);
      }
      
      for(int i=0;i<5;i++) {                  //chord 8
        int temp = i+133;
        chord8[i] = EEPROM.read(temp);
      }
      
      
//start = millis();

//-------------------------------------------------------------------------   
   
//-------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//-------------------------------------------------------------------------   
   
//-------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//-------------------------------------------------------------------------   
   
//-------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//-------------------------------------------------------------------------   
   
//-------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
}

void loop() {  //zloop
  
  
bByte = PINB;
modPosVar1 = !bitRead(bByte, 3);    //the mode switch is connected directly to arduino pins
modPosVar2 = !bitRead(bByte, 4);
//modPosVar1 = !digitalRead(11);
//modPosVar2 = !digitalRead(12);

modPos();


whichChanFunc();

//----------------MIDI ASSIGN MODE ON -------->>>>>>>>>>>>>>>>>>>>>>>>>>
  if (chordHold && assignHold) {  // this is the chord assign loop  zcassign
    lightSet = 0;
    tempChordMem = chordMemory;
    chordMemory = 0;
    lastChordCount = chCount[chSelect];
    chCount[chSelect] = 0;
  }
  while(chordHold && assignHold) {      //CHORD BANK ASSIGN MODE!!
    //RWcount = 0;      //don't need the extra speed in this loop, so don't need to alternate the reads
    
    bByte = PINB;
    modPosVar1 = !bitRead(bByte, 3);
    modPosVar2 = !bitRead(bByte, 4);
    //modPosVar1 = !digitalRead(11);
    //modPosVar2 = !digitalRead(12);
    
    modPos();
    
    whichChanFunc();
    
      if (potCounter > 28) {
        potCounter = 0;
      } 
      
      if (conCount1 > 17) {
        conCount1 = 0;
      }
      if (lightSet == 0) {
        assignLastFlash = millis();
          ledT2state = 1;                //turn on t2 and t3 lights
          ledT3state = 1;
          ledStateArray[0] = ledT2state;
          ledStateArray[1] = ledT3state;
          ledStateArray[2] = ledT4state;
          
          middleCpressed = 0;
          lightSet = 1;
      }
          
        assignFlash = millis();                      //flash lights after reference note pressed
        if ((assignFlash - assignLastFlash) > 250) {
          ledT2state = !ledT2state; // no eeprom save here necessary
          ledT3state = !ledT3state;
          assignLastFlash = assignFlash;
        }
      
      if (lightup == 0) {                  //once 5 notes are pressed, then lights stay on
        ledStateArray[0] = ledT2state;
        ledStateArray[1] = ledT3state;
        ledStateArray[2] = ledT4state;
      } else {
        ledStateArray[0] = 1;           
        ledStateArray[1] = 1;
        ledStateArray[2] = 1;
      }
      
      ReadWrite();
      
      

          
   
      
      
    WhichStuff();
    SuperAnalogRead();
    
    if (potEnable) {
                //paramValues get updated, but after exiting chord assign mode new values are not sent out of the controller
      if ((rawReadArray[potCounter] < (paramList[whichParam] - 6)) || (rawReadArray[potCounter] > (paramList[whichParam] + 6))) {
        if ((rawReadArray[potCounter] / 8) != (paramList[whichParam] / 8)) {
          paramList[whichParam] = rawReadArray[potCounter];
        
        if(whichParam > 25 && whichParam < 34) {      //envelope knobs are turned to select which chord from 8 chord bank
          

          
          if (chCount[chSelect] == 0 || chCount[chSelect] == 1) {    //if no real chord is made
                        chCount[chSelect] = lastChordCount;  //reverts chordcount back to original
                        int which;
                        switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                        for (int i=0;i<5;i++) {
                          int which2 = which + i;
                          chBankWrite(chSelect,i,EEPROM.read(which2));    //reverts chord notes back to last set
                        }
                      } else {      //if an actual chord is pressed
                          findLowest();
                          chCount[chSelect]--;
                          int add = 0;
                          for (int i=0;i<6;i++) {
                            int temp = i - add;
                            if (chordVal1[i] != lowestVal[chSelect]) {
                              chBankWrite(chSelect,temp,chordVal1[i]);  //sets new values to chord
                            } else {
                              add = 1;
                            }
                          }
                          int which;
                          switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                          for (int i=0;i<5;i++) {
                            int which2 = which + i;
                            EEPROM.write(which2,chBankRead(chSelect,i));
                          }
                          switch(chSelect) {
                            case 0:
                              EEPROM.write(138,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 1:
                              EEPROM.write(139,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 2:
                              EEPROM.write(140,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 3:
                              EEPROM.write(141,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 4:
                              EEPROM.write(142,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 5:
                              EEPROM.write(143,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 6:
                              EEPROM.write(144,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 7:
                              EEPROM.write(145,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                          }
                          
                          EEPROM.write((chSelect+93), lowestVal[chSelect]);
                        }
                        
                        
          if (whichParam == 33) {
            chSelect = 0;
          } else {
           chSelect = whichParam - 25; 
          }

          lightup = 0;
          
          lastChordCount = chCount[chSelect];
          chCount[chSelect] = 0; 
          
        }
        
        //if which param is one of the 8 envelope knobs then switch to that bank and reset the chordcount variable 
      }
    }

    potEnable = 0;
    potCounter++;
    }
    
    
          
      SysexCon2();
         
      if (Serial.available() > 0) {
        incomingByte = Serial.read();
        
         SysexConversion();

         MidiParsing();
          
                        
        if (incomingByte > 143 && incomingByte < 160) {  //chord Assigning
          assignGateOpen = 1;
          assignFlip = 1;
        } else {
          if (incomingByte > 127 && incomingByte < 248) {  //system realtime does NOT close gate!!
            assignGateOpen = 0;
          }
        }
        if (assignGateOpen == 1) {
          if (incomingByte < 128) {
            assignFlip = !assignFlip;
            if (assignFlip == 0) {
              if(chCount[chSelect] < 6) {
                int incoming = (int)incomingByte;
                chordValtemp1[chCount[chSelect]] = incoming;
              }
            } else {
              if (chCount[chSelect] < 6 && incomingByte != 0) {
                int denyChord = 1;
                for (int i=0;i<6;i++) {
                  if (i >= chCount[chSelect]) {
                    break;
                  }
                  if (chordValtemp1[chCount[chSelect]] == chordVal1[i]) {
                    denyChord = 0;
                  }
                }
                if (denyChord) {
                  chordVal1[chCount[chSelect]] = chordValtemp1[chCount[chSelect]];
                  if (chCount[chSelect] < 6) {
                  chCount[chSelect]++;
                  }
                  if (chCount[chSelect] > 5) {
                    lightup = 1;
                  }
                }
              }
            }
          }
        }
      
   
      }
      
      longSysFunc();
      
      if(digEnable) {
      
          int readingT2 = shiftdata2[1];      //T2 Midi Assign button CHORD HOLD
  
  
              if(readingT2 != LbutStateT2) {
                LdebTimeT2 = millis();
              }
              
              if ((millis() - LdebTimeT2) > debdelay) {
                if (readingT2 != butStateT2) {
                  butStateT2 = readingT2;
                  if (butStateT2 == LOW) {
                    lightSet++;
                    if(lightSet>3) {
                    
                      chordHold = 0;
                      assignHold = 0;
                      chordMemory = tempChordMem;
                      ledT3state = chordMemory;
                      ledT2state = 0;
                      lightup = 0;
                      
          if (chCount[chSelect] == 0 || chCount[chSelect] == 1) {    //if no real chord is made
                        chCount[chSelect] = lastChordCount;  //reverts chordcount back to original
                        int which;
                          switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                        for (int i=0;i<5;i++) {
                          int which2 = which + i;
                          chBankWrite(chSelect,i,EEPROM.read(which2));    //reverts chord notes back to last set
                        }
                      } else {      //if an actual chord is pressed
                          findLowest();
                          chCount[chSelect]--;
                          int add = 0;
                          for (int i=0;i<6;i++) {
                            int temp = i - add;
                            if (chordVal1[i] != lowestVal[chSelect]) {
                              chBankWrite(chSelect,temp,chordVal1[i]);  //sets new values to chord
                            } else {
                              add = 1;
                            }
                          }
                          
                          int which;
                          switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                          for (int i=0;i<5;i++) {
                            int which2 = which + i;
                            EEPROM.write(which2,chBankRead(chSelect,i));
                          }
                          
                          switch(chSelect) {
                            case 0:
                              EEPROM.write(138,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 1:
                              EEPROM.write(139,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 2:
                              EEPROM.write(140,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 3:
                              EEPROM.write(141,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 4:
                              EEPROM.write(142,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 5:
                              EEPROM.write(143,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 6:
                              EEPROM.write(144,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                            case 7:
                              EEPROM.write(145,chCount[chSelect]);
                              EEPROM.write(102,chSelect);
                              break;
                          }
                              
                          
                          EEPROM.write((chSelect+93), lowestVal[chSelect]);
                        }
                          
                          
                      }
                  }
                }
              }
              
              
              LbutStateT2 = readingT2;
              
              int readingT3 = shiftdata2[2];      //button T3 Chord CHORD HOLD
            
            
            if(readingT3 != LbutStateT3) {
              LdebTimeT3 = millis();
            }
            
            if ((millis() - LdebTimeT3) > debdelay) {
              if (readingT3 != butStateT3) {
                butStateT3 = readingT3;
                if (butStateT3 == LOW) {
                  lightSet++;
                    if(lightSet>3) {
                    
                    chordHold = 0;
                    assignHold = 0;
                    chordMemory = tempChordMem;
                    ledT3state = chordMemory;
                    ledT2state = 0;
                    lightup = 0;
          if (chCount[chSelect] == 0 || chCount[chSelect] == 1) {    //if no real chord is made
                        chCount[chSelect] = lastChordCount;  //reverts chordcount back to original
                        int which;
                          switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                        for (int i=0;i<5;i++) {
                          int which2 = which + i;
                          chBankWrite(chSelect,i,EEPROM.read(which2));    //reverts chord notes back to last set
                        }
                      } else {      //if an actual chord is pressed
                          findLowest();
                          chCount[chSelect]--;
                          int add = 0;
                          for (int i=0;i<6;i++) {
                            int temp = i - add;
                            if (chordVal1[i] != lowestVal[chSelect]) {
                              chBankWrite(chSelect,temp,chordVal1[i]);  //sets new values to chord
                            } else {
                              add = 1;
                            }
                          }
                          int which;
                          switch(chSelect) {
                            case 0:
                              which = 6;
                              break;
                            case 1:
                              which = 103;
                              break;
                            case 2:
                              which = 108;
                              break;
                            case 3:
                              which = 113;
                              break;
                            case 4:
                              which = 118;
                              break;
                            case 5:
                              which = 123;
                              break;
                            case 6:
                              which = 128;
                              break;
                            case 7:
                              which = 133;
                              break;
                          }
                          for (int i=0;i<5;i++) {
                            int which2 = which + i;
                            EEPROM.write(which2,chBankRead(chSelect,i));
                          }
                          switch(chSelect) {
                            case 0:
                              EEPROM.write(138,chCount[chSelect]);
                              break;
                            case 1:
                              EEPROM.write(139,chCount[chSelect]);
                              break;
                            case 2:
                              EEPROM.write(140,chCount[chSelect]);
                              break;
                            case 3:
                              EEPROM.write(141,chCount[chSelect]);
                              break;
                            case 4:
                              EEPROM.write(142,chCount[chSelect]);
                              break;
                            case 5:
                              EEPROM.write(143,chCount[chSelect]);
                              break;
                            case 6:
                              EEPROM.write(144,chCount[chSelect]);
                              break;
                            case 7:
                              EEPROM.write(145,chCount[chSelect]);
                              break;
                          }
                          
                          EEPROM.write((chSelect+93), lowestVal[chSelect]);
                        }
                    }
                }
              }
            }
            
            LbutStateT3 = readingT3;

  }
      conCount1++;
    
  }


 while (assignOn) {        //zasson -------------------------------------------ASSIGN ON
   chordMemory = 0;
   RWcount = 0; //don't need the extra time between cycles in this loop
   
   bByte = PINB;
    modPosVar1 = !bitRead(bByte, 3);
    modPosVar2 = !bitRead(bByte, 4);
    //modPosVar1 = !digitalRead(11);
    //modPosVar2 = !digitalRead(12);

    modPos();
    
    int modPosReading = ModPosSwitch;
    
    if (modPosReading != lastModReading) {
      assignCount = 0;
    }
    
    lastModReading = modPosReading;
    
    whichChanFunc();
        
    if (potCounter > 28) {
      potCounter = 0;
    }
    
    if (conCount1 > 17) {
      conCount1 = 0;
    }
    
    if (assignCounter == 0) {                            //set led flash period
      assignFlashDelay = 250;
    } else {
      if (assignCounter == 1) {
        assignFlashDelay = 50;
      }
    }
    
                                                              //led flasher
      if (middleCpressed == 1) {
        assignFlash = millis();
        if ((assignFlash - assignLastFlash) > assignFlashDelay) {
          ledT2state = !ledT2state; // no eeprom save here necessary
          assignLastFlash = assignFlash;
        }
      }
      
      SysexCon2();
  
    if (Serial.available() > 0) {
      incomingByte = Serial.read();
      
      SysexConversion();

      MidiParsing();
      
      if (middleCpressed == 0) {
        int off;
        if (incomingByte > 127 && incomingByte < 160) {
          assignGateOpen = 1;
          assignFlip = 1;
          secondByteAllow = 0;
          if (incomingByte > 127 && incomingByte < 144) {
            off = 1;
          } else {
            if (incomingByte > 143 && incomingByte < 160) {
              off = 0;
            }
          }
        } else {
          if (incomingByte > 127 && incomingByte < 248) {          //the < 248 let's system realtime messages not fuck up everything!
            assignGateOpen = 0;
          }
        }
        if (assignGateOpen && incomingByte < 128) {
              assignFlip = !assignFlip;
              if (assignFlip == 0) {
                if (incomingByte == 48) {
                  secondByteAllow = 1;
                } else {
                  secondByteAllow = 0;
                }
              }
              if (secondByteAllow && incomingByte == 0) {
                middleCpressed = 1;
                assignKnobSelect = 36;
              }
              if (secondByteAllow && off == 1) {
                middleCpressed = 1;
                assignKnobSelect = 36;
              }
        }
      }
                    
      if (assignCounter == 0 && middleCpressed == 1) {
        if (incomingByte > 143 && incomingByte < 160) {
          assignGateOpen = 1;
          assignFlip = 1;
        } else {
          if (incomingByte > 127 && incomingByte < 248) {            //system realtime doesn't fsu
            assignGateOpen = 0;
          }
        }
        if (assignGateOpen == 1) {
          if (incomingByte < 128) {
            assignFlip = !assignFlip;
            if (assignFlip == 0) {
              if (incomingByte > 47 && incomingByte < 58) {
                int incoming = (int)incomingByte - 48;
                assignVal[assignCount] = incoming;
                
                secondByteAllow = 1;
              } else {
                secondByteAllow = 0;
              }
            } else {
              if (secondByteAllow == 1 && incomingByte != 0 && assignKnobSelect != 36) {
                switch (assignCount) {
                  case 0:
                    if (ModPosSwitch == 0 | ModPosSwitch == 2) {    //SYSEX + DUAL MOD CASE 0
                      for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal[0] == conCCList[i]) {
                            doubleVal0 = conCCList[i];    //saves the value of the current assignment incase someone is entering a 2 digit value
                            conCCList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            doubleSave0 = i;          //saves the knob incase someone enters a 2 digit value
                            doubleYes0 = 1;
                            doubleOrig0 = conCCList[assignKnobSelect];
                            break;
                          } else {
                            doubleYes0 = 0;
                          }
                        }
                      conCCList[assignKnobSelect] = assignVal[0];
                      
                      int tempval = assignKnobSelect + 11;
                      EEPROM.write(tempval, assignVal[0]);  
                    } else {                                          //MIDI CC MODE CASE 0*************************************************
                      for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal[0] == ccList[i]) {
                            doubleVal0cc = ccList[i];    //saves the value of the current assignment of the duplicate incase someone is entering a 2 digit value
                            ccList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            doubleSave0cc = i;          //saves the knob incase someone enters a 2 digit value
                            doubleYes0cc = 1;            //1 indicating there was a duplicate value
                            doubleOrig0cc = ccList[assignKnobSelect]; //saves the value of what we are assigning to the knob now
                            break;
                          } else {
                            doubleYes0cc = 0;
                          }
                        }
                      ccList[assignKnobSelect] = assignVal[0];
                      int tempval = assignKnobSelect + 47;
                      EEPROM.write(tempval, assignVal[0]);
                    }
                    break;
                  case 1:
                    if (ModPosSwitch == 0 || ModPosSwitch == 2) {    //SYSEX + DUAL MODE CASE 1
                      if (doubleYes0) {                                    //so if someone enters another digit then it cancels the previous nulling and returns it to its original value
                        conCCList[doubleSave0] = doubleVal0;
                        conCCList[assignKnobSelect] = doubleOrig0;
                      }
                      assignVal2 = (assignVal[0] * 10) + assignVal[1];
                      for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal2 == conCCList[i]) {
                            doubleVal1 = conCCList[i];    //saves the value of the current assignment incase someone is entering a 3 digit value
                            conCCList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            doubleSave1 = i;          //saves the knob incase someone enters a 2 digit value
                            doubleYes1 = 1;            //1 indicating there was a duplicate value
                            doubleOrig1 = conCCList[assignKnobSelect];
                            break;
                          } else {
                            doubleYes1 = 0;
                          }
                        }
                      conCCList[assignKnobSelect] = assignVal2;
                      int tempval = assignKnobSelect + 11;
                      EEPROM.write(tempval, assignVal2);
                    } else {                                          //MIDI CC MODE CASE 1
                      if (doubleYes0cc) {                                    //so if someone enters another digit then it cancels the previous nulling and returns it to its original value
                        ccList[doubleSave0cc] = doubleVal0cc;
                        ccList[assignKnobSelect] = doubleOrig0cc;               //returns assigned value to what it was before so that in the for loop it doesn't use the value--ugh too difficult to explain, just look at the code you will get it
                      }
                      assignVal2 = (assignVal[0] * 10) + assignVal[1];
                      for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal2 == ccList[i]) {
                            doubleVal1cc = ccList[i];    //saves the value of the current assignment incase someone is entering a 3 digit value
                            ccList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            doubleSave1cc = i;          //saves the knob incase someone enters a 2 digit value
                            doubleYes1cc = 1;            //1 indicating there was a duplicate value
                            doubleOrig1cc = ccList[assignKnobSelect];
                            break;
                          } else {
                            doubleYes1cc = 0;
                          }
                        }
                      ccList[assignKnobSelect] = assignVal2;
                      int tempval = assignKnobSelect + 47;
                      EEPROM.write(tempval, assignVal2);
                    }
                    break;
                  case 2:
                    if (ModPosSwitch == 0 || ModPosSwitch == 2) {    //SYSEX + DUAL MODE CASE 2
                      if (doubleYes0) {                                    //so if someone enters another digit then it cancels the previous nulling and returns it to its original value
                        conCCList[doubleSave0] = doubleVal0;
                        conCCList[assignKnobSelect] = doubleOrig0;
                      }
                      if (doubleYes1) {                                    
                        conCCList[doubleSave1] = doubleVal1;
                        conCCList[assignKnobSelect] = doubleOrig1;
                      }
                      assignVal2 = ((assignVal[0] * 100) + (assignVal[1] * 10)) + assignVal[2];
                      if (assignVal2 < 120) {
                        for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal2 == conCCList[i]) {
                            conCCList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            break;
                          } 
                        }
                        conCCList[assignKnobSelect] = assignVal2;
                        int tempval = assignKnobSelect + 11;
                        EEPROM.write(tempval, assignVal2);
                      }
                    } else {                                          //MIDI CC MODE CASE 2
                      if (doubleYes0) {                                    //so if someone enters another digit then it cancels the previous nulling and returns it to its original value
                        ccList[doubleSave0cc] = doubleVal0cc;
                        ccList[assignKnobSelect] = doubleOrig0cc;
                      }
                      if (doubleYes1) {                                    
                        ccList[doubleSave1cc] = doubleVal1cc;
                        ccList[assignKnobSelect] = doubleOrig1cc;
                      }
                      assignVal2 = ((assignVal[0] * 100) + (assignVal[1] * 10)) + assignVal[2];
                      if (assignVal2 < 120) {
                        for (int i=0;i<36;i++) {                          //checks to see if there is already an assignment
                          if (assignVal2 == ccList[i]) {
                            ccList[i] = 255;        //assigns 255 to the knob so that it is disabled from sysex conversion/cc output
                            break;
                          } 
                        }
                        ccList[assignKnobSelect] = assignVal2;
                        int tempval = assignKnobSelect + 47;
                        EEPROM.write(tempval, assignVal2);
                      }
                    }
                    break;
                  case 3:
                    break; //so once 3 digits are enter then nothing happens here
                }
                assignCount++;
                if (assignCount > 2) {      //once 3 digits are enter then nothing happens here
                  assignCount = 3;
                }
              }
            }
          }
        }
      }
      
      if (assignCounter == 1 && middleCpressed == 1) {        //CHANNEL --------------------
        if (incomingByte > 143 && incomingByte < 160) {
          assignGateOpen = 1;
          assignFlip = 1;
        } else {
          if (incomingByte > 127 && incomingByte < 248) {        //system realtime not fing shit up again! < 248
            assignGateOpen = 0;
          }
        }
        if (assignGateOpen == 1) {
          if (incomingByte < 128) {
            assignFlip = !assignFlip;
            if (assignFlip == 0) {
              if (incomingByte > 47 && incomingByte < 58) {
                int incoming = (int)incomingByte - 48;
                assignVal[assignCount] = incoming;
                
                secondByteAllow = 1;
              } else {
                secondByteAllow = 0;
              }
            } else {
              if (secondByteAllow == 1 && incomingByte != 0) {
                switch (assignCount) {
                  case 0:
                    if (ModPosSwitch == 0) {    //sysex mode
                      if ((assignVal[0] - 1) != dualChannelSelect) {
                        if ((assignVal[0] - 1) >= 0) {
                      chanSelectIn = assignVal[0] - 1;
                      EEPROM.write(2, chanSelectIn);
                      byte temp = (byte)chanSelectIn;
                      snapShot[3] = temp;
                      paramChange[3] = temp;
                        }
                      }
                    } else {
                      if (ModPosSwitch == 1) {
                        if ((assignVal[0] - 1) >= 0) {
                        chanSelect = assignVal[0] - 1;
                        EEPROM.write(3, chanSelect);
                        }
                      } else {
                        if (ModPosSwitch == 2) {
                          if ((assignVal[0] - 1) != chanSelectIn) {
                            if ((assignVal[0] - 1) >= 0 ) {
                              dualChannelSelect = assignVal[0] - 1;
                              EEPROM.write(4, dualChannelSelect);
                              snapShot[3] = (byte)dualChannelSelect;  //Jan 30, 2019
                              paramChange[3] = (byte)dualChannelSelect;  //Jan 30, 2019
                            }
                          }
                        }
                      }
                    }
                    break;
                  case 1:
                    if (ModPosSwitch == 0) {    //sysex mode + dual mode
                      if (assignVal[0] == 0) {
                        assignVal2 = assignVal[1];
                      } else {
                        assignVal2 = (assignVal[0] * 10) + assignVal[1];
                      }
                      if ((assignVal2 - 1) != dualChannelSelect) {
                        if (((assignVal2 - 1) >= 0) && ((assignVal2 - 1) < 16)) {
                          chanSelectIn = assignVal2 - 1;
                          EEPROM.write(2, chanSelectIn);
                          byte temp = (byte)chanSelectIn;
                          snapShot[3] = temp;
                          paramChange[3] = temp;
                        }
                      }
                    } else {
                      if (ModPosSwitch == 1) {
                        if (assignVal[0] == 0) {
                        assignVal2 = assignVal[1];
                      } else {
                        assignVal2 = (assignVal[0] * 10) + assignVal[1];
                      }
                        if ((assignVal2 - 1) >= 0 && ((assignVal2 - 1) < 16)) {
                        chanSelect = assignVal2 - 1;
                        EEPROM.write(3, chanSelect);
                        }
                      } else {
                        if (ModPosSwitch == 2) {
                          if (assignVal[0] == 0) {
                            assignVal2 = assignVal[1];
                          } else {
                            assignVal2 = (assignVal[0] * 10) + assignVal[1];
                          }
                          if ((assignVal2 - 1) != chanSelectIn) {
                            if (((assignVal2 - 1) >= 0) && ((assignVal2 - 1) < 16)) {
                          dualChannelSelect = assignVal2 - 1;
                          EEPROM.write(4, dualChannelSelect);
                            }
                          }
                        }
                }
              }
              break;
            }
            assignCount++;
                if (assignCount == 2) {
                  assignCount = 0;
                }
          }
        }
      }
        }
      }
    }
    
    longSysFunc();
       
WhichStuff();
SuperAnalogRead();

if (potEnable) {
  if ((rawReadArray[potCounter] < (paramList[whichParam] - 6)) || (rawReadArray[potCounter] > (paramList[whichParam] + 6))) {
    if ((rawReadArray[potCounter] / 8) != (paramList[whichParam] / 8)) {
    paramList[whichParam] = rawReadArray[potCounter];
    
    if (assignCounter == 0 && middleCpressed == 1) {
    if(assignCounter == 1 && middleCpressed == 1) {
          } else {
            assignCount = 0;
          }
    assignKnobSelect = whichParam;
    }
  }
}      
      potEnable = 0;
      potCounter++;
}
          
      ledStateArray[0] = ledT2state;      //collects the current state of all the LEDs
      ledStateArray[1] = ledT3state;
      ledStateArray[2] = ledT4state;
      
      ReadWrite();
      
      
    if (digEnable) {
      int readingT2 = shiftdata2[1];      //T2 Midi Assign in while loop
  
  
      if(readingT2 != LbutStateT2) {
        LdebTimeT2 = millis();
      }
      
      if ((millis() - LdebTimeT2) > debdelay) {
        if (readingT2 != butStateT2) {
          butStateT2 = readingT2;
          if (butStateT2 == LOW) {
            assignCounter++;
            if (assignCounter == 1 && middleCpressed == 0) {
              assignOn = 0;
              assignCounter = 0;
              assignCount = 0;
              ledT2state = 0;
              chordMemory = ledT3state;
            }
            if (assignCounter == 1 && middleCpressed == 1) {
              assignCount = 0;
            }
            if (assignCounter == 2)  {
              assignOn = 0;
              assignCounter = 0;
              assignCount = 0;
              ledT2state = 0;
              middleCpressed = 0;
              assignKnobSelect = 36;
              chordMemory = ledT3state;

            }
          }
        }
      }
      
      
      LbutStateT2 = readingT2;
      
      
      int readingT4 = shiftdata2[3];      //button T1 Chorus    
      if(readingT4 != LbutStateT4) {
        LdebTimeT4 = millis();
      } 
      if ((millis() - LdebTimeT4) > debdelay) {
        if (readingT4 != butStateT4) {
          butStateT4 = readingT4;
          if (butStateT4 == HIGH) {
            assignKnobSelect = 10;
            if(assignCounter == 1 && middleCpressed == 1) {
          } else {
            assignCount = 0;
          }       
          }
        }
      }
      LbutStateT4 = readingT4;
      
      byteVal = 0;
        for (int i=3; i>=0; i--) {    // param 3 pulse type
          bitWrite(byteVal, i, shiftdata0[i]);
          if (i == 0) {
            int svalue = fourPos(byteVal);
            if(svalue != paramList[3] && svalue != 4) {
              paramList[3] = svalue;
              assignKnobSelect = 3;
              if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }
            }
          }
        }
        
      byteVal = 0;
      for (int i=5; i>3; i--) {
        int itemp = i - 4;
        bitWrite(byteVal, i, shiftdata3[itemp]);
      }
      for (int i=3; i>=0; i--) {                // param 4 saw type
        int itemp = i + 4;
        bitWrite(byteVal, i, shiftdata0[itemp]);
        if (i == 0) {
          int svalue = sixPos(byteVal);
          if(svalue != paramList[4] && svalue != 6) {
            paramList[4] = svalue;
            assignKnobSelect = 4;
            if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }
          }
        }
      }
      
      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 2 vca env mode
      bitWrite(byteVal, i, shiftdata1[i]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[2] && svalue != 4) {
          paramList[2] = svalue;
          assignKnobSelect = 2;
          if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }
        }
      }
    }

      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 0 dco env mode
      int itemp = i + 4;
      bitWrite(byteVal, i, shiftdata1[itemp]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[0] && svalue != 4) {
          paramList[0] = svalue;
          assignKnobSelect = 0;
          if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }
        }
      }
      }
      
      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 1 vcf env mode
      int itemp = i + 4;
      bitWrite(byteVal, i, shiftdata2[itemp]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[1] && svalue != 4) {
          paramList[1] = svalue;
          assignKnobSelect = 1;
          if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }
        }
      }
      }   

      byteVal = 0;
      for (int i=5; i>=0; i--) {                // param 5 sub type
        int itemp = i + 2;
        bitWrite(byteVal, i, shiftdata3[itemp]);
        if (i == 0) {
          int svalue = sixPos(byteVal);
          if(svalue != paramList[5] && svalue != 6) {
            paramList[5] = svalue;
            assignKnobSelect = 5;
            if(assignCounter == 1 && middleCpressed == 1) {
              } else {
                assignCount = 0;
              }    
          }
        }
      }
    }
  conCount1++;
  }


//>>>>>>>>>>>>>----------------------------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

      
      
  
  if (potCounter > 28) {
    potCounter = 0;
  }
  
  if (conCount1 > 17) {
    conCount1 = 0;
  }
  
  SysexCon2();
  
    
  if (Serial.available() > 0) {                              //NOTE AND CONTROL MESSAGE INPUT
    incomingByte = Serial.read();

       
    SysexConversion();
      
//--------------------------------------------------------------------------------- end of CC converter

    MidiParsing();      
          // also remember you must make the pot, switch and button code update running status when they send cc's so they aren't unneccesarily sending the data byte each time  
          //also, for the love of god please make it impossible to write more bytes than the SysMessages array can hold or else it will be a big problem later!!
  }
  
  longSysFunc();

 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        //POTENTIOMETERS: #zpot
                                        
                                      
WhichStuff();        //which pin to read from and which paramter it corresponds to based on the potCounter
SuperAnalogRead();
  

if (potEnable) {
    if(chordHold == 0) {
      tempSet = 1;
    }  
  if ((rawReadArray[potCounter] < (paramList[whichParam] - 6)) || (rawReadArray[potCounter] > (paramList[whichParam] + 6))) {
    if ((rawReadArray[potCounter] / 8) != (paramList[whichParam] / 8)) {
    
      if(chordHold && tempSet) {
        tempSet = 0;
        lastParam = 100;
      }

      if(chordHold) {      //envelope knobs are turned to select which chord from 8 chord bank
        all2 = 0;
        if(whichParam != lastParam) {
          if (letgo == 1 && ledT3state) {
              letgo = 0;
            }
            if(ModPosSwitch != 2) {                    //all notes off
            Serial.write(dualCC[chanSelectIn]);
            Serial.write(123);
            Serial.write(0);
            } else {
              Serial.write(dualCC[chanSelectIn]);
              Serial.write(124);
              Serial.write(0);
              
              Serial.write(dualCC[chanSelectIn]);
              Serial.write(125);
              Serial.write(0);
            }

            for(int i=0;i<10;i++) {
              chordArray[i] = 128;
            }
                        switch(whichParam) {
                            case 33:
                              chSelect = 0;
                              EEPROM.write(102,0);
                              break;
                            case 26:
                              chSelect = 1;
                              EEPROM.write(102,1);
                              break;
                            case 27:
                              chSelect = 2;
                              EEPROM.write(102,2);
                              break;
                            case 28:
                              chSelect = 3;
                              EEPROM.write(102,3);
                              break;
                            case 29:
                              chSelect = 4;
                              EEPROM.write(102,4);
                              break;
                            case 30:
                              chSelect = 5;
                              EEPROM.write(102,5);
                              break;
                            case 31:
                              chSelect = 6;
                              EEPROM.write(102,6);
                              break;
                            case 32:
                              chSelect = 7;
                              EEPROM.write(102,7);
                              break;
                          }
      }
            lastParam = whichParam;
      }

      
    if (whichParam > 5 && whichParam < 10) {
      potSwitch = paramList[whichParam];
      potSwitchVal = formatVal(whichParam, potSwitch);       //pot switch stuff
    }
    paramList[whichParam] = rawReadArray[potCounter];
    paramValue = formatVal(whichParam, rawReadArray[potCounter]);
    
    
    
    
    if (whichParam > 5 && whichParam < 10) {        // this is for the potentiometers that we use as switches - they need to only send out a msg when the value changes
        if (ccModeSelect == 0 && ModPosSwitch == 1) {
        allowPotSwitch = 1;
      } else {
        if (paramValue != potSwitchVal) {
          allowPotSwitch = 1;
        } else {
          allowPotSwitch = 0;
        }
      }
    } else {
      allowPotSwitch = 1;
    }
    
    
    if (allowPotSwitch == 1 && all2 == 1) {
    switch (ModPosSwitch) {
      case 0:
        if (whichParam != 35) {     
          for (int count = 0; count<7; count++) {
            Serial.write(paramChange[count]);
          }
          Serial.write(whichParam);
          Serial.write(paramValue);
          Serial.write(247);
        } else {
          paramValueCC = formatPotSwitchCC(whichParam, rawReadArray[potCounter]);
          if (paramValueCC > 0) {
            Serial.write(chanList[chanSelectIn]);
            Serial.write(65);
            Serial.write(127);
          } else {
            Serial.write(chanList[chanSelectIn]);
            Serial.write(65);
            Serial.write(0);
          }
          Serial.write(chanList[chanSelectIn]);
          Serial.write(5);
          Serial.write(paramValueCC);
        }
          
        break;
      case 1:  
        if (ccList[whichParam] != 255) {  //doesn't allow disabled cc assignments
          paramValueCC = formatPotSwitchCC(whichParam, rawReadArray[potCounter]);
          Serial.write(chanList[chanSelect]);
          Serial.write(ccList[whichParam]);
          Serial.write(paramValueCC);
        }
        break;
       case 2:
       if (conCCList[whichParam] != 255) {
          paramValueCC = formatPotSwitchCC(whichParam, rawReadArray[potCounter]);
          Serial.write(chanList[chanSelectIn]); //channel
          Serial.write(conCCList[whichParam]);  //CC number
          Serial.write(paramValueCC);            //value
          break;
       }
        }
    }
  }
}

potCounter++;
potEnable = 0;
all2 = 1;
}

        //collects the current state of all the LEDs
  ledStateArray[0] = ledT2state;
  ledStateArray[1] = ledT3state;
  ledStateArray[2] = ledT4state;

  ReadWrite();
  


if (digEnable) {
//------------------------------------------------ Button and led code

int readingT4 = shiftdata2[3];      //button T4 Chorus zrus


if(readingT4 != LbutStateT4) {
  LdebTimeT4 = millis();
}

if ((millis() - LdebTimeT4) > debdelay) {
  if (readingT4 != butStateT4) {
    butStateT4 = readingT4;
    if (butStateT4 == HIGH) {
      ledT4state = !ledT4state;
      EEPROM.write(0, ledT4state);
      paramList[10] = ledT4state * 127;
      switch (ModPosSwitch) {
        case 0:
          for (int i=0;i<7;i++) {
            Serial.write(paramChange[i]);
          }
          Serial.write(10);
          Serial.write(ledT4state);
          Serial.write(247);
          break;
        case 1:
          Serial.write(chanList[chanSelect]);
          Serial.write(ccList[10]);
          Serial.write(ledT4state * 127);
          break;
        case 2:
          Serial.write(chanList[chanSelectIn]);
          Serial.write(conCCList[10]);
          Serial.write(ledT4state * 127);
          break;
      }
             
    }
  }
}

LbutStateT4 = readingT4;

//--------------------

int readingT2 = shiftdata2[1];      //T2 Midi Assign #zassign


if(readingT2 != LbutStateT2) {
  LdebTimeT2 = millis();
}

if ((millis() - LdebTimeT2) > debdelay) {
  if (readingT2 != butStateT2) {
    butStateT2 = readingT2;
    if (chordHold == 0) {
      if (butStateT2 == LOW) {
        ledT2state = 1;
        assignOn = 1;
        lastModReading = ModPosSwitch;
      } else {
        assignHeld = 1;
    }
  } else {
    if (butStateT2 == HIGH) {
      assignHold = 1;
    }
  }
}
}


LbutStateT2 = readingT2;


//---------------

int readingT3 = shiftdata2[2];      //T3 Chord #zchord


if(readingT3 != LbutStateT3) {
  LdebTimeT3 = millis();
}

if ((millis() - LdebTimeT3) > debdelay) {
  if (readingT3 != butStateT3) {
    butStateT3 = readingT3;
    if (butStateT3 == LOW) {
      if(letgo == 1) {
          chordMemory = !chordMemory;
          ledT3state = !ledT3state;
          EEPROM.write(1, ledT3state);
          chordHold = 0;
          if(chordMemory == 0) {
            
            if(ModPosSwitch != 2) {                    //all notes off
            Serial.write(dualCC[chanSelectIn]);
            Serial.write(123);
            Serial.write(0);
            } else {
              Serial.write(dualCC[chanSelectIn]);
              Serial.write(124);
              Serial.write(0);
              
              Serial.write(dualCC[chanSelectIn]);
              Serial.write(125);
              Serial.write(0);
            }
            
            notesOn = 0;
            for(int i=0;i<10;i++) {
              chordArray[i] = 128;
            }
            
          } else {
            initNoteFix = 0;        //if chordmem gets turned on then this init note fix gets set to zero
          }
      } else {
        letgo = 1;
        chordHold = 0;
        snapHold = 0;
        ledT4state = paramList[10] / 127;
        ledT3state = chordMemory;
        ledT2state = 0;
      }
            
    } else {
      chordHold = 1;
      lightSet = 0;
    }
  }
}

LbutStateT3 = readingT3;

if (chordHold && snapHold) {
  if (letgo == 1) {
    monoChords = !monoChords;
    EEPROM.write(84,monoChords);
    ledT3state = 1;
    ledT2state = 1;
    ledT4state = 1;
    letgo = 0;
  }
}





int readingT1 = shiftdata2[0];      //T1 Snapshot zsnap

if(readingT1 != LbutStateT1) {
  LdebTimeT1 = millis();
}

if ((millis() - LdebTimeT1) > debdelay) {
  if (readingT1 != butStateT1) {
    butStateT1 = readingT1;
    if (butStateT1 == HIGH) {
      if (chordHold) {
        snapHold = 1;
      } else {
      switch (ModPosSwitch) {
        case 0:
          for (int i=0; i<7; i++) {
          Serial.write(snapShot[i]);
        }
        for (int i=0; i<6; i++) {
          Serial.write(paramList[i]);
        }
        for (int i=6; i<10; i++) {
          paramValue = formatVal(i,paramList[i]);
          Serial.write(paramValue);
        }
        Serial.write(paramList[10]);
        for (int i=11;i<35;i++) {
          paramValue = formatVal(i, paramList[i]);
          Serial.write(paramValue);
        }
        Serial.write(247);
        if ((paramList[35] / 8) > 0) {          //portamento
          Serial.write(chanList[chanSelectIn]);
          Serial.write(65);
          Serial.write(127);
        } else {
          Serial.write(chanList[chanSelectIn]);
          Serial.write(65);
          Serial.write(0);
        }
        Serial.write(chanList[chanSelectIn]);
        Serial.write(5);
        paramValue = formatPotSwitchCC(35,paramList[35]);
        Serial.write(paramValue);
        break;
      case 1:
        snapC = 0;
        for (int i=0;i<4;i++) {
          ssArray[snapC] = chanList[chanSelect];      // first 4 switches
            snapC++;
          ssArray[snapC] = ccList[i];
            snapC++;
          paramValue = fourPosCC(paramList[i]);
          ssArray[snapC] = paramValue;
            snapC++;
        }
        for (int i=4;i<6;i++) {
          ssArray[snapC] = chanList[chanSelect];      // switch 5 and 6
            snapC++;
          ssArray[snapC] = ccList[i];
            snapC++;
          paramValue = sixPosCC(paramList[i]);
          ssArray[snapC] = paramValue;
            snapC++;
        }
        for (int i=6;i<10;i++) {
          ssArray[snapC] = chanList[chanSelect];
            snapC++;
          ssArray[snapC] = ccList[i];
            snapC++;
          paramValueCC = formatPotSwitchCC(i,paramList[i]);
          ssArray[snapC] = paramValueCC;
            snapC++;
        }
        ssArray[snapC] = chanList[chanSelect];
          snapC++;
        ssArray[snapC] = ccList[10];
          snapC++;
        ssArray[snapC] = paramList[10];
          snapC++;
        
        for (int i=11;i<36;i++) {
          ssArray[snapC] = chanList[chanSelect];
            snapC++;
          ssArray[snapC] = ccList[i];
            snapC++;
          ssArray[snapC] = paramList[i] / 8;
            snapC++;
        }
        ssOpen = 1;
        snapC = 0;
        ssLastMillis = millis();
        break;
      case 2:
      for (int i=0; i<7; i++) {
          Serial.write(snapShot[i]);
        }
        for (int i=0; i<6; i++) {
          Serial.write(paramList[i]);
        }
        for (int i=6; i<10; i++) {
          paramValue = formatVal(i,paramList[i]);
          Serial.write(paramValue);
        }
        Serial.write(paramList[10]);
        for (int i=11;i<35;i++) {
          paramValue = formatVal(i, paramList[i]);
          Serial.write(paramValue);
        }
        Serial.write(247);
        if ((paramList[35] / 8) > 0) {          //portamento
          Serial.write(chanList[chanSelectIn]);
          Serial.write(65);
          Serial.write(127);
        } else {
          Serial.write(chanList[chanSelectIn]);
          Serial.write(65);
          Serial.write(0);
        }
        Serial.write(chanList[chanSelectIn]);
        Serial.write(5);
        paramValue = formatPotSwitchCC(35,paramList[35]);
        Serial.write(paramValue);
        break;
      /*
        snapC = 0;
        for (int i=0;i<4;i++) {
          ssArray[snapC] = chanList[dualChannelSelect];      // first 4 switches
            snapC++;
          ssArray[snapC] = conCCList[i];
            snapC++;
          paramValue = fourPosCC(paramList[i]);
          ssArray[snapC] = paramValue;
            snapC++;
        }
        for (int i=4;i<6;i++) {
          ssArray[snapC] = chanList[dualChannelSelect];      // switch 5 and 6
            snapC++;
          ssArray[snapC] = conCCList[i];
            snapC++;
          paramValue = sixPosCC(paramList[i]);
          ssArray[snapC] = paramValue;
            snapC++;
        }
        for (int i=6;i<10;i++) {
          ssArray[snapC] = chanList[dualChannelSelect];
            snapC++;
          ssArray[snapC] = conCCList[i];
            snapC++;
          paramValueCC = formatPotSwitchCC(i,paramList[i]);
          ssArray[snapC] = paramValueCC;
            snapC++;
        }
        ssArray[snapC] = chanList[dualChannelSelect];
          snapC++;
        ssArray[snapC] = conCCList[10];
          snapC++;
        ssArray[snapC] = paramList[10];
          snapC++;
        
        for (int i=11;i<36;i++) {
          ssArray[snapC] = chanList[dualChannelSelect];
            snapC++;
          ssArray[snapC] = conCCList[i];
            snapC++;
          ssArray[snapC] = paramList[i] / 8;
            snapC++;
        }
        ssOpen = 1;
        snapC = 0;
        ssLastMillis = millis();
        
        disableSysCon = 1;                        //so if in dual mode this variable will block the sysex converter for a little bit just so the buffer doesn't overfill while all these values are being converted
        allow3 = 1;*/
        //disableClock = millis();
        
      }
    }
    }
}

}
LbutStateT1 = readingT1;



//------------------------------------------------ Shift Register code, repetetive, but seems just as convoluted to make a condensed version of this code

  byteVal = 0;
  for (int i=3; i>=0; i--) {    // switch for parameter 3 (pulse type)
    bitWrite(byteVal, i, shiftdata0[i]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
      if(svalue != paramList[3] && svalue != 4) {
        paramList[3] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
            Serial.write(paramChange[i]);
          }
          Serial.write(3);
          Serial.write(svalue);
          Serial.write(247);
          break;
        case 1:
          Serial.write(chanList[chanSelect]);
          Serial.write(ccList[3]);
          paramValue = fourPosCC(svalue);
          Serial.write(paramValue);
          break;
        case 2:
          Serial.write(chanList[chanSelectIn]);
          Serial.write(conCCList[3]);
          paramValue = fourPosCC(svalue);
          Serial.write(paramValue);
          break;
        }
         
      }
    }
  }

  byteVal = 0;
  for (int i=5; i>=4; i--) {                // switch for param 4 (sawtooth type)
    int itemp = i - 4;
    bitWrite(byteVal, i, shiftdata3[itemp]);
  }
  for (int i=3; i>=0; i--) {
    int itemp = i + 4;
    bitWrite(byteVal, i, shiftdata0[itemp]);
    if (i == 0) {
      int svalue = sixPos(byteVal);
      if(svalue != paramList[4] && svalue != 6) {
        paramList[4] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
            Serial.write(paramChange[i]);
            }
            Serial.write(4);
            Serial.write(svalue);
            Serial.write(247);
            break;
          case 1:
            Serial.write(chanList[chanSelect]);
            Serial.write(ccList[4]);
            paramValue = sixPosCC(svalue);
            Serial.write(paramValue);
            break;
          case 2:
            Serial.write(chanList[chanSelectIn]);
            Serial.write(conCCList[4]);
            paramValue = sixPosCC(svalue);
            Serial.write(paramValue);
            break; 
        } 
      }
    }
  }
    byteVal = 0;
    for (int i=3; i>=0; i--) {                // switch for param 2 (vca env mode)
    bitWrite(byteVal, i, shiftdata1[i]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
      if(svalue != paramList[2] && svalue != 4) {
        paramList[2] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
              Serial.write(paramChange[i]);
            }
            Serial.write(2);
            Serial.write(svalue);
            Serial.write(247);
            break;
          case 1:
            Serial.write(chanList[chanSelect]);
            Serial.write(ccList[2]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
          case 2:
            Serial.write(chanList[chanSelectIn]);
            Serial.write(conCCList[2]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
        }
      }
    }
  }  
    byteVal = 0;
    for (int i=3; i>=0; i--) {                // switch for param 0 (dco env mode)
    int itemp = i + 4;
    bitWrite(byteVal, i, shiftdata1[itemp]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
      if(svalue != paramList[0] && svalue != 4) {
        paramList[0] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
              Serial.write(paramChange[i]);
            }
            Serial.write(0);
            Serial.write(svalue);
            Serial.write(247);
            break;
          case 1:
            Serial.write(chanList[chanSelect]);
            Serial.write(ccList[0]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
          case 2:
            Serial.write(chanList[chanSelectIn]);
            Serial.write(conCCList[0]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
        }
      }
    }
    }
    

    
    byteVal = 0;
    for (int i=3; i>=0; i--) {        // switch for param 1 (vcf env mode)
    int itemp = i + 4;
    bitWrite(byteVal, i, shiftdata2[itemp]);
    if (i == 0) {
      int svalue = fourPos(byteVal);
      if(svalue != paramList[1] && svalue != 4) {
        paramList[1] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
              Serial.write(paramChange[i]);
            }
            Serial.write(1);
            Serial.write(svalue);
            Serial.write(247);
            break;
          case 1:
            Serial.write(chanList[chanSelect]);
            Serial.write(ccList[1]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
          case 2:
            Serial.write(chanList[chanSelectIn]);
            Serial.write(conCCList[1]);
            paramValue = fourPosCC(svalue);
            Serial.write(paramValue);
            break;
        }
      }
    }
    }

    byteVal = 0;
    for (int i=5; i>=0; i--) {                // switch param 5 (sub wave type)
    int itemp = i + 2;
    bitWrite(byteVal, i, shiftdata3[itemp]);
    if (i == 0) {
      int svalue = sixPos(byteVal);
      if(svalue != paramList[5] && svalue != 6) {
        paramList[5] = svalue;
        switch(ModPosSwitch) {
          case 0:
            for (int i=0; i<7; i++) {
              Serial.write(paramChange[i]);
            }
            Serial.write(5);
            Serial.write(svalue);
            Serial.write(247);
            break;
          case 1:
            Serial.write(chanList[chanSelect]);
            Serial.write(ccList[5]);
            paramValue = sixPosCC(svalue);
            Serial.write(paramValue);
            break;
          case 2:
            Serial.write(chanList[chanSelectIn]);
            Serial.write(conCCList[5]);
            paramValue = sixPosCC(svalue);
            Serial.write(paramValue);
            break;
        }    
    }
  }
  }
  
  digEnable = 0;
}


//-----------------------ASSIGN HELD LOOP---------=======
//------------------------------------------------=======
//------------------------------------------------=======
while (assignHeld) {
  
  if (potCounter > 28) {
      potCounter = 0;
    }
    
  if(conCount1 > 17) {
    conCount1 = 0;
  }
    
    bByte = PINB;
    modPosVar1 = !bitRead(bByte, 3);
    modPosVar2 = !bitRead(bByte, 4);
    //modPosVar1 = !digitalRead(11);
    //modPosVar2 = !digitalRead(12);
    
    modPos();
    
    whichChanFunc();
    
    SysexCon2();
    
    
if (Serial.available() > 0) {                              //ASSIGN HELD NOTE AND CONTROL MESSAGE INPUT
    incomingByte = Serial.read();

       
    SysexConversion();

    MidiParsing();

  }
   
  longSysFunc();

    
     WhichStuff();
     
     SuperAnalogRead();
     
        //if (trigger == 0) {
    
    if (potEnable) {
        if ((rawReadArray[potCounter] < (paramList[whichParam] - 6)) || (rawReadArray[potCounter] > (paramList[whichParam] + 6))) {
    if ((rawReadArray[potCounter] / 8) != (paramList[whichParam] / 8)) {
          //paramList[whichParam] = value;
          trigger = 1;
        }
      }
      
      
      potCounter++;
      potEnable = 0;
    }
    
   //}
   

  
  if (tempAllow) {
        ledStateArray[0] = ledT2state;
        ledStateArray[1] = ledT3state;
        ledStateArray[2] = ledT4state;
      } else {
        ledStateArray[0] = 1;            //ASSIGN HELD turns all the lights on when you move one of the special knobs
        ledStateArray[1] = 1;
        ledStateArray[2] = 1;
      }
      
    ReadWrite();
    
    if (digEnable) {
  

  
  int readingT2 = shiftdata2[1];      //T2 Midi Assign button ASSIGN HELD
  
  
  if(readingT2 != LbutStateT2) {
    LdebTimeT2 = millis();
  }
  
  if ((millis() - LdebTimeT2) > debdelay) {
    if (readingT2 != butStateT2) {
      butStateT2 = readingT2;
      if (butStateT2 == LOW) {
        if (tempAllow && trigger == 0) {
        ledT2state = 1;
        assignOn = 1;
        assignLastFlash = millis();
        assignHeld = 0;
        middleCpressed = 0;
        } else {
          assignHeld = 0;
          tempAllow = 1;
          if((ledT4state * 127) != paramList[10]) {
            paramList[10] = ledT4state * 127;
              switch (ModPosSwitch) {
                case 0:
                  for (int i=0;i<7;i++) {
                    Serial.write(paramChange[i]);
                  }
                  Serial.write(10);
                  Serial.write(ledT4state);
                  Serial.write(247);
                  break;
                case 1:
                  Serial.write(chanList[chanSelect]);
                  Serial.write(ccList[10]);
                  Serial.write(ledT4state * 127);
                  break;
                case 2:
                  Serial.write(chanList[chanSelectIn]);
                  Serial.write(conCCList[10]);
                  Serial.write(ledT4state * 127);
                  break;
              }
          }
          trigger = 0;
          //allow3 = 1;
        }
      }
    }
  }
  
  
  LbutStateT2 = readingT2;
  
  
  int readingT4 = shiftdata2[3];      //button T4 Chorus ASSIGN HELD


if(readingT4 != LbutStateT4) {
  LdebTimeT4 = millis();
}

if ((millis() - LdebTimeT4) > debdelay) {
  if (readingT4 != butStateT4) {
    butStateT4 = readingT4;
    if (butStateT4 == HIGH) {
      ledT4state = !ledT4state;
      EEPROM.write(0, ledT4state);
      
      trigger = 1;
    }
  }
}

LbutStateT4 = readingT4;


readingT3 = shiftdata2[2];      //button T3 Chord ASSIGN HELD


if(readingT3 != LbutStateT3) {
  LdebTimeT3 = millis();
}

if ((millis() - LdebTimeT3) > debdelay) {
  if (readingT3 != butStateT3) {
    butStateT3 = readingT3;
    if (butStateT3 == HIGH) {
      if (tempAllow && ModPosSwitch == 1) {
      ccModeSelect = !ccModeSelect;
      EEPROM.write(5,ccModeSelect);
      tempAllow = 0;
      }
      
    }
  }
}

LbutStateT3 = readingT3;


int readingT1 = shiftdata2[0];      //T1 Snapshot ASSIGN HELD

if(readingT1 != LbutStateT1) {
  LdebTimeT1 = millis();
}

if ((millis() - LdebTimeT1) > debdelay) {
  if (readingT1 != butStateT1) {
    butStateT1 = readingT1;
    if (butStateT1 == HIGH) {
      if (tempAllow) {
        
        factoryDefault();
        
        
      tempAllow = 0;
      }
    }
  }
}

LbutStateT1 = readingT1;

    if (trigger == 0) {
        byteVal = 0;
        for (int i=3; i>=0; i--) {    // param 3 pulse type ASSIGN HELD
          bitWrite(byteVal, i, shiftdata0[i]);
          if (i == 0) {
            int svalue = fourPos(byteVal);
            if(svalue != paramList[3] && svalue != 4) {
              //paramList[3] = svalue;
              trigger = 1;
            }
          }
        }
        
      byteVal = 0;
      for (int i=5; i>3; i--) {
        int itemp = i - 4;
        bitWrite(byteVal, i, shiftdata3[itemp]);
      }
      for (int i=3; i>=0; i--) {                // param 4 saw type ASSIGN HELD
        int itemp = i + 4;
        bitWrite(byteVal, i, shiftdata0[itemp]);
        if (i == 0) {
          int svalue = sixPos(byteVal);
          if(svalue != paramList[4] && svalue != 6) {
            //paramList[4] = svalue;
            trigger = 1;
          }
        }
      }
      
      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 2 vca env mode ASSIGN HELD
      bitWrite(byteVal, i, shiftdata1[i]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[2] && svalue != 4) {
          //paramList[2] = svalue;
          trigger = 1;
        }
      }
    }

      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 0 dco env mode ASSIGN HELD
      int itemp = i + 4;
      bitWrite(byteVal, i, shiftdata1[itemp]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[0] && svalue != 4) {
          //paramList[0] = svalue;
          trigger = 1;
        }
      }
      }
      
      byteVal = 0;
      for (int i=3; i>=0; i--) {                // param 1 vcf env mode ASSIGN HELD
      int itemp = i + 4;
      bitWrite(byteVal, i, shiftdata2[itemp]);
      if (i == 0) {
        int svalue = fourPos(byteVal);
        if(svalue != paramList[1] && svalue != 4) {
          //paramList[1] = svalue;
          trigger = 1;
        }
      }
      }   

      byteVal = 0;
      for (int i=5; i>=0; i--) {                // param 5 sub type ASSIGN HELD
        int itemp = i + 2;
        bitWrite(byteVal, i, shiftdata3[itemp]);
        if (i == 0) {
          int svalue = sixPos(byteVal);
          if(svalue != paramList[5] && svalue != 6) {
            //paramList[5] = svalue;
            trigger = 1;   
          }
        }
      }
    }
    }
  conCount1++;
}

//-----------ASSIGN HELD LOOPS ENDS--XXXXXXXX

//-------------------------------------------
//------------------------------------------

//--------------------------------------------------- Shift Register code ends

if (ssOpen) {
  if ((millis() - ssLastMillis) > 2) {
    
    if (ssArray[snapC + 1] != 255) {
      
        if (ModPosSwitch == 2) {
        Serial.write(dualCC[dualChannelSelect]); // this too
        } else {
          Serial.write(dualCC[chanSelect]);
        }
        Serial.write(ssArray[snapC + 1]);          // this is the thing that writes the higher or lower value
        if (ssArray[snapC + 2] > 126) {
          Serial.write((ssArray[snapC + 2]) - 1);
        } else {
          Serial.write((ssArray[snapC + 2]) + 1);
        }
    

    
    for (int i=0;i<3;i++) {
      Serial.write(ssArray[snapC]);
      snapC++;
    }
  
    } else {
      snapC = snapC + 3;
    }
  
  
  if (snapC >= 108) {
    ssOpen = 0;
    if (ModPosSwitch == 2) {
      snap2 = 1;
      for (int i=0; i<7; i++) {
            Serial.write(snapShot[i]);       //sysex snapshot
          }
          for (int i=0; i<6; i++) {
            Serial.write(paramList[i]);
          }
          for (int i=6; i<10; i++) {
            paramValue = formatVal(i,paramList[i]);
            Serial.write(paramValue);
          }
          Serial.write(paramList[10]);
          for (int i=11;i<35;i++) {
            paramValue = formatVal(i, paramList[i]);
            Serial.write(paramValue);
          }
          Serial.write(247);
          if ((paramList[35] / 8) > 0) {          //portamento
            Serial.write(chanList[chanSelectIn]);
            Serial.write(65);
            Serial.write(127);
          } else {
            Serial.write(chanList[chanSelectIn]);
            Serial.write(65);
            Serial.write(0);
          }
          Serial.write(chanList[chanSelectIn]);
          Serial.write(5);
          paramValue = formatPotSwitchCC(35,paramList[35]);
          Serial.write(paramValue);
    }
  }
  ssLastMillis = millis();
  }
}

if (snap2) {
  if ((millis() - ssLastMillis) > 100) {     //makes the sysconverter wait 100 millis after all the cc snapshot and sysex snapshot is done
        disableSysCon = 0;
        snap2 = 0;
  }
}
conCount1++;

/*
hertz++;

if (millis() - start >= 1000) {
  int htemp;
  Serial.write(240);
  if (hertz < 15000) {
    htemp = 1;
  } else {
    if (hertz < 17000) {
      htemp = 2;
    } else {
      if (hertz < 19000) {
        htemp = 3;
      } else {
        if (hertz < 21000) {
          htemp = 4;
        } else {
          if (hertz < 23000) {
            htemp = 5;
          } else {
            htemp = 0;
          }
        }
      }
    }
  }
  Serial.write(htemp);
  Serial.write(247);
  hertz = 0;
  start = millis();
}
*/


}
