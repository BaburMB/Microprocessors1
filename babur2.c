#include <16f877.h>
#fuses XT, NOWDT,NOPROTECT, NOBROWNOUT,NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay(clock=4000000)
#use fast_io(b)
#use fast_io(d)
#use fast_io(a)

int a=0, b=0;

void main()
{
                                                                                                                                                                                 
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF);

set_tris_b(0x00);
set_tris_d(0b00000001);
set_tris_a(0x00);


output_b(0x00);


   start:
    if (input(pin_a0)==true)
    { 
    while(1==1){
      for(a=pin_b0; a<=pin_b5; a++)
      {
         output_high(a);
         delay_ms(100);
         output_low(a);
      
      }
      for( b=a; b>=pin_b0; b--)
      {
         output_high(b);
         delay_ms(100);
         output_low(b);
       
      }
 
    }
    a=0;
    b=0;
    }
     goto start;             
}
