// BigNumber test: unsigned long
#include <BigNumber.h>


void setup ()
{
  Serial.begin (9600);
  Serial.println ("starting");
  BigNumber::begin (10);  // initialize library

  uint32_t ffreq = 1065000000UL;
  uint32_t ChanStep = 1000; 
  int outdiv = 4 ; 

  BigNumber freq = BigNumber(ffreq)  ;

  char tmpstr[20] ; 
  float PFDFreq = 100000000.0 ; 
  dtostrf(PFDFreq,13,3,tmpstr) ; 

  Serial.print("tmpstr=") ;
  Serial.println(tmpstr) ; 
  BigNumber PFD = BigNumber(tmpstr) ;

  Serial.println(PFD) ; 

  BigNumber N =  ( BigNumber(freq) * BigNumber(outdiv)) / PFD   ;

  Serial.print("BN N") ; 
  Serial.println(N) ;
  int N_Int = (int) ((uint32_t) N) ;  

  Serial.print("N=") ; 
  Serial.println(N_Int);
  BigNumber BN_Mod  = PFD / BigNumber(ChanStep) ; 
  uint32_t Mod  = BN_Mod ;  
  BN_Mod = BigNumber(Mod) ; 
  Serial.print("Mod=") ;
  Serial.println(Mod) ; 

  BigNumber BN_Frac = ((N - BigNumber(N_Int)) * BN_Mod )  + BigNumber("0.5") ; 
  int Frac = (int) ( (uint32_t) BN_Frac) ; 

  Serial.print("frac=") ;
  Serial.println(Frac) ; 





}  // end of setup

void loop () { }
