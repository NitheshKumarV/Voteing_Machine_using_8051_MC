#include <REGX51.H>
#define LCD_dat P2
sbit rs = P1^0;
sbit en = P1^1;
sbit Start_Stop = P1^3;
sbit Permission = P1^4;		
sbit Result_Vote= P1^5;
sbit RESET = P1^6;
sbit Reset = P1^7;
sbit Party0 = P3^0;
sbit Party1 = P3^1;
sbit Party2 = P3^2;
sbit Party3 = P3^3;
sbit Party4 = P3^4;
sbit Party5 = P3^5;
sbit Party6 = P3^6;
sbit Party7 = P3^7;
void delay(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
void to_char(unsigned int value){char tens,units;
																	tens=value/10;
																	lcd_data(tens+48);
																	units=value%10;
                                  lcd_data(units+48);}
void main(void)
	{
		unsigned int p0=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,Vote=0,Per=0;
		//unsigned char Result[5];
		Start:
	lcd_cmd (0x38);
	lcd_cmd (0x0e);
	if(Start_Stop == 0){lcd_cmd (0x01);
											lcd_cmd (0x80);
											lcd_str("Voteing Started");
											delay(3000);
	while(1)
	{  lcd_cmd (0x01);
		 lcd_cmd (0x80);
		 lcd_str("Wait for a while");
		 delay(2000);
		 lcd_cmd (0x01);
		 if(Permission==0){Per = 1;}
		 while(Per == 1){lcd_cmd (0x80);
										 lcd_str("You Can Vote Now");
			                      if(Party0 == 0){p0++;
																				 lcd_cmd (0x01);
																				 lcd_cmd (0x80);
																				 lcd_str("You Voted For");
												                 lcd_cmd(0xC0);
												                 lcd_str("Party 0");
																				 delay(3000);
															           Per = 0;
																					}
												 else if(Party1 == 0){p1++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
																							lcd_str("Party 1");
																				      delay(3000);
															                Per = 0;}
												 else if(Party2 == 0){p2++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 2");
																				      delay(3000);
															                Per = 0;}
												 else if(Party3 == 0){p3++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 3");
																				      delay(3000);
															                Per = 0;}
												 else if(Party4 == 0){p4++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 4");
																				      delay(3000);
															                Per = 0;}
												 else if(Party5 == 0){p5++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 5");
																				      delay(3000);
															                Per = 0;}
												 else if(Party6 == 0){p6++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 6");
																				      delay(3000);
															                Per = 0;}
												 else if(Party7 == 0){p7++;
												                      lcd_cmd (0x01);
																				      lcd_cmd (0x80);
																				      lcd_str("You Voted For");
												                      lcd_cmd(0xC0);
												                      lcd_str("Party 7");
																				      delay(3000);
															                Per = 0;}
		                      }
	if (Start_Stop == 0){break;}
	
	
	
	
	
	}//While end
	while(1){
		lcd_cmd (0x01);
	  lcd_cmd (0x80);
		lcd_str("Select Mode");
		delay(2000);
		if (Result_Vote == 0){
						       lcd_cmd(0x01);
									 lcd_cmd(0x80);
									 lcd_str("Result");
									 lcd_cmd(0xC0);
									 delay(2000);
									 lcd_cmd(0x80);
		               lcd_str("Party 0 Scored");
									 lcd_cmd(0xC0);
			             to_char(p0);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 1 Scored");
									 lcd_cmd(0xC0);
									 to_char(p1);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 2 Scored");
									 lcd_cmd(0xC0);
									 to_char(p2);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 3 Scored");
									 lcd_cmd(0xC0);
									 to_char(p3);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 4 Scored");
									 lcd_cmd(0xC0);
									 to_char(p4);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 5 Scored");
									 lcd_cmd(0xC0);
									 to_char(p5);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 6 Scored");
									 lcd_cmd(0xC0);
									 to_char(p6);
		               delay(1000);
									 lcd_cmd(0x80);
		               lcd_str("Party 7 Scored");
									 lcd_cmd(0xC0);
									 to_char(p7);
		               delay(1000);
	                }
	else if (RESET == 0){
	                if(RESET == 0){p0=0;
																 p1=0;
																 p2=0;
																 p3=0;
																 p4=0;
																 p5=0;
																 p6=0;
																 p7=0;
																 Per=0;
																 }
									}
	else if (Start_Stop == 0){break;}
	}//other while
	delay(3000);
	if (Start_Stop == 0){goto Start;}
	}//Start end
	}//Main end
		void lcd_str(unsigned char *str)
{
   unsigned int loop = 0;
	for(loop =0;str[loop]!='\0';loop++)
	{ 
		lcd_data(str[loop]);
	}
}

void lcd_data(unsigned char ch)
{
LCD_dat = ch;
	rs =1; // for data rs = 1
	en = 1;
	delay(5);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
LCD_dat = ch;
	rs = 0; //for command rs = 0
	en = 1;
	delay(5);
	en = 0;
}
void delay(unsigned int dly)
{
unsigned int loop = 0;
unsigned int delay_gen = 0;
	for (loop=0; loop<dly; loop++){
		for (delay_gen=0; delay_gen<115; delay_gen++);
	}
}
