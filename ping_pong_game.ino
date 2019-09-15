#include<LiquidCrystal.h>
LiquidCrystal lcd(7,9,10,11,12,13);
byte updot[8]={
  B01110,
  B11111,
  B11111,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};
byte downdot[8]={
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B11111,
  B11111,
  B01110
};
byte right[8]={
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};

byte left[8]={
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011
};


# define switch3 3
# define switch4 4
# define switch5 5
# define switch6 6

void setup()
{
  pinMode(switch3,INPUT);
  pinMode(switch4,INPUT);
  pinMode(switch5,INPUT);
  pinMode(switch6,INPUT);
  lcd.createChar(1,updot);
  lcd.createChar(2,downdot);
  lcd.createChar(3,left);
  lcd.createChar(4,left);
  lcd.createChar(5,right);
  lcd.createChar(6,right);
  lcd.begin(16,2);
}

int changep(int p)
{
  if(p==1)
   return 2;
  else if(p==2)
   return 1;
}

void loop()
{
  int p=1,c=1,r=0,h=6,v=2,t=150;

  lcd.setCursor(0,0);
  lcd.print("welcome to      ");
  lcd.setCursor(0,1);
  lcd.print("ping  pong  game");
  delay(2000);
  

  lcd.setCursor(0,0);
  lcd.print("<<<up      up>>>");
  lcd.setCursor(0,1);
  lcd.print("<<<down  down>>>");
  delay(3000);
  
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("loading");
  for(int i=0;i<16;i++)
  {
    delay(300);
    lcd.setCursor(i,1);
    lcd.print("#");
  }
  lcd.setCursor(0,0);
  lcd.print("enter up  button");
  lcd.setCursor(0,1);
  lcd.print("to start game   ");
  int start_input = digitalRead(switch3)==HIGH || digitalRead(switch5)==HIGH;
  while(!start_input)
  {
    start_input = digitalRead(switch3)==HIGH || digitalRead(switch5)==HIGH;
  }
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.write(byte(3));
  lcd.setCursor(15,0);
  lcd.write(byte(5));
  int posleft=1,posright=1;
  while(true)
  {
    lcd.setCursor(c,r);
    lcd.write(byte(p));
    int input_button1 = digitalRead(switch3)==HIGH && digitalRead(switch4)==LOW;
    int input_button2 = digitalRead(switch3)==LOW && digitalRead(switch4)==HIGH;
    int input_button3 = digitalRead(switch5)==HIGH && digitalRead(switch6)==LOW;
    int input_button4 = digitalRead(switch5)==LOW && digitalRead(switch6)==HIGH;
    delay(t);
    if(input_button1)
    {
      lcd.setCursor(0,1);
      lcd.print(" ");
      lcd.setCursor(0,0);
      lcd.write(byte(3));
      posleft=1;
    }
    else if(input_button2)
    {
      lcd.setCursor(0,0);
      lcd.print(" ");
      lcd.setCursor(0,1);
      lcd.write(byte(4));
      posleft=2;
    }
    if(input_button3)
    {
      lcd.setCursor(15,1);
      lcd.print(" ");
      lcd.setCursor(15,0);
      lcd.write(byte(5));
      posright=1;
    }
    else if(input_button4)
    {
      lcd.setCursor(15,0);
      lcd.print(" ");
      lcd.setCursor(15,1);
      lcd.write(byte(6));
      posright=2;
    }
    lcd.setCursor(c,r);
    lcd.print(" ");
    if((p==2 && r==0 && c>=2 && c<=13) || ( p==1 && r==1 && c>=2 && c<=13))
    {
      if(v==8 && h==6)
      {
        p=changep(p);
        if(r==0)
        {
          c++;
        }
        else if(r==1)
        {
          c++;r--;
        }
      }
      else if(v==2 && h==6)
      {
        p=changep(p);
        if(r==0)
        {
          r++;c++;
        }
        else if(r==1)
        {
          c++;
        }
      }
      else if(v==8 && h==4)
      {
        p=changep(p);
        if(r==0)
        {
          c--;
        }
        else if(r==1)
        {
          c--;r--;
        }
      }
      else if(v==2 && h==4)
      {
        p=changep(p);
        if(r==0)
        {
          r++;c--;
        }
        else if(r==1)
        {
          c--;
        }
      }
    }

    
    else if(p==1 && r==0 && c>=2 && c<=13)
    {
      if(v==8 && h==6)
      {
        p=changep(p);
        c++;v=2;
      }
      else if(v==2 && h==6)
      {
        p=changep(p);
        c++;
      }
      else if(v==8 && h==4)
      {
        p=changep(p);
        c--;v=2;
      }
      else if(v==2 && h==4)
      {
        p=changep(p);
        c--;
      }
    }
    else if(p==2 && r==1 && c>=2 && c<=13)
    {
      if(v==8 && h==6)
      {
        p=changep(p);
        c++;
      }
      else if(v==2 && h==6)
      {
        p=changep(p);
        c++;v=8;
      }
      else if(v==8 && h==4)
      {
        p=changep(p);
        c--;
      }
      else if(v==2 && h==4)
      {
        p=changep(p);
        c--;v=8;
      }
    }
    

    else if(c==1)
    {
      if(posleft==1 && r==0)
      {
        if(p==1)
        {
          c++;p=changep(p);h=6;v=2;
        }
        else if(p==2)
        {
          if(v==2 &&h==4)
          {
            h=6;r++;c++;p=changep(p);
          }
          else if(v==8 && h==4)
          {
            h=6;c++;p=changep(p);
          }
        }
      }
      else if(posleft==2 &&r==1)
      {
        if(p==1)
        {
          if(v==2 && h==4)
          {
            h=6;c++;p=changep(p);
          }
          else if(v==8 && h==4)
          {
            h=6;c++;r--;p=changep(p);
          }
        }
        else if(p==2)
        {
          c--;p=changep(p);h=6;v=8;
        }
      }
      else if(posleft==1 && r==1)
      {
        lcd.setCursor(0,1);
        lcd.print("<<loser         ");
        lcd.setCursor(0,0);
        lcd.print("        winner>>");
        delay(5000);
        lcd.setCursor(0,0);
        lcd.print("enter reset     ");
        lcd.setCursor(0,1);
        lcd.print("buton of arduino");
        exit(1);
      }
      else if(posleft==2 && r==0)
      {
        lcd.setCursor(0,1);
        lcd.print("<<loser         ");
        lcd.setCursor(0,0);
        lcd.print("        winner>>");
        delay(5000);
        lcd.setCursor(0,0);
        lcd.print("enter reset     ");
        lcd.setCursor(0,1);
        lcd.print("buton of arduino");
        exit(1);
      }
    }
    else if(c==14)
    {
      if(posright==1 &&r==0)
      {
        if(p==1)
        {
          c--;p=changep(p);h=4;v=2;
        }
        else if(p==2)
        {
          if(v==2 &&h==6)
          {
            h=4;r++;c--;p=changep(p);
          }
          else if(v==8 && h==6)
          {
            h=4;c--;p=changep(p);
          }
        }
      }
      else if(posright==2 &&r==1)
      {
        if(p==1)
        {
          if(v==2 && h==6)
          {
            h=4;c--;p=changep(p);
          }
          else if(v==8 && h==6)
          {
            h=4;c--;r--;p=changep(p);
          }
        }
        else if(p==2)
        {
          c--;p=changep(p);h=4;v=8;
        }
      }
      else if(posright==1 && r==1)
      {
        lcd.setCursor(0,1);
        lcd.print("         loser>>");
        lcd.setCursor(0,0);
        lcd.print("<<winner        ");
        delay(5000);
        lcd.setCursor(0,0);
        lcd.print("enter reset     ");
        lcd.setCursor(0,1);
        lcd.print("buton of arduino");
        exit(1);
      }
      else if(posright==2 && r==0)
      {
        lcd.setCursor(0,1);
        lcd.print("         loser>>");
        lcd.setCursor(0,0);
        lcd.print("<<winner        ");
        delay(5000);
        lcd.setCursor(0,0);
        lcd.print("enter reset     ");
        lcd.setCursor(0,1);
        lcd.print("buton of arduino");
        exit(1);
      }
    }

  }
  }
