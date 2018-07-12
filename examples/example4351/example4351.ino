/*!
   ADF4351 example program
*/

#include <Arduino.h>
#include "adf4351.h"

#define SWVERSION "1.0"

#define PIN_SS 9  ///< SPI slave select pin, default value

ADF4351  vfo(PIN_SS, SPI_MODE0, 1000000UL , MSBFIRST) ;


void setup()
{
  Serial.begin(9600) ;
  Serial.print("Hello adf4351 demo v") ;
  Serial.println(SWVERSION) ;
  Wire.begin() ;
  /*!
     setup the chip (for a 10 mhz ref freq)
     most of these are defaults
  */
  vfo.pwrlevel = 0 ; ///< sets to -4 dBm output
  vfo.RD2refdouble = 0 ; ///< ref doubler off
  vfo.RD1Rdiv2 = 0 ;   ///< ref divider off
  vfo.ClkDiv = 150 ;
  vfo.BandSelClock = 80 ;
  vfo.RCounter = 1 ;  ///< R counter to 1 (no division)
  vfo.ChanStep = steps[2] ;  ///< set to 10 kHz steps

  /*!
     sets the reference frequency to 10 Mhz
  */
  if ( vfo.setrf(10000000UL) ==  0 )
    Serial.println("ref freq set to 10 Mhz") ;
    else
      Serial.println("ref freq set error") ;
      /*!
         initialize the chip
      */
      vfo.init() ;

  /*!
     enable frequency output
  */
  vfo.enable() ;
}



void loop()
{
  /*!
     do a set of freq changes (40 Mhz, 4 GHz, and 1Ghz, )
  */
  delay(5000);
  Serial.println("setf() to 40 MHz") ;

  if ( vfo.setf(40000000UL) == 0 ) {
    Serial.print("setf() success freq:") ;
    Serial.println(vfo.cfreq) ;
  } else {
    Serial.println("setf() error") ;
  }

  delay(5000);
  Serial.println("setf() to 2 GHz") ;

  if ( vfo.setf(4000000000UL) == 0 ) {
    Serial.print("setf() success freq:") ;
    Serial.println(vfo.cfreq) ;
  } else {
    Serial.println("setf() error") ;
  }

  delay(5000);
  Serial.println("setf() to 1 GHz") ;

  if ( vfo.setf(1000000000UL) == 0 ) {
    Serial.print("setf() success freq:") ;
    Serial.println(vfo.cfreq) ;
  } else {
    Serial.println("setf() error") ;
  }

  /*!
     change the step value to 100kHz
     do a set of 5 channel steps change every 5 seconds
     1,000.100 Mhz
     1,000.200 Mhz
     ...
     1,000.500 Mhz

     print out the PLL values

  */
  unsigned long newf ;
  vfo.ChanStep = steps[4] ; ///< change to 100 kHz

  for (int i = 0; i < 5; i++) {
    delay(5000);
    newf = vfo.cfreq + vfo.ChanStep ;

    if ( vfo.setf(newf) == 0 ) {
      Serial.print("setf() success freq:") ;
      Serial.println(vfo.cfreq) ;
    } else {
      Serial.println("setf() error") ;
    }

    Serial.println(vfo.cfreq) ;
    Serial.print("PLL INT:");
    Serial.println(vfo.N_Int);
    Serial.print("PLL FRAC:");
    Serial.println(vfo.Frac);
    Serial.print("PLL MOD:");
    Serial.println(vfo.Mod);
    Serial.print("PLL PFD:");
    Serial.println(vfo.PFDFreq);
    Serial.print("PLL output divider:");
    Serial.println(vfo.outdiv);
    Serial.print("PLL prescaler:");
    Serial.println(vfo.Prescaler);
    Serial.println("");
  }

  /*!
     disable the output for 5 seconds
     and then enable it.
  */
  delay(5000);
  vfo.disable() ;
  delay(5000);
  vfo.enable() ;
  /*!
     change freq back to 1 Ghz
  */
  delay(5000);

  if ( vfo.setf(1000000000UL) == 0 ) {
    Serial.print("setf() success freq:") ;
    Serial.println(vfo.cfreq) ;
  } else {
    Serial.println("setf() error") ;
  }

  delay(5000) ;
}
