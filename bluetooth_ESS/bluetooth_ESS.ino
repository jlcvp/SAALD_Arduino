#define NUM_BTNS 3
#define ON HIGH
#define OFF LOW
#define EMPRESTIMO 'R'
#define DEVOLUCAO 'D'

typedef struct pckote{
  char indice;
  char acao;
  char eol;
} pct;

const int input[]={8,9,10};

boolean btns_state[NUM_BTNS]={OFF,OFF,OFF};

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<NUM_BTNS;i++)
  {
    pinMode(input[i],INPUT);
  }
}

void loop()
{
  for(int i=0;i<NUM_BTNS;i++)
  {
    int btn = digitalRead(input[i]);
    if(btn!=btns_state[i])
    {
      btns_state[i] = btn;
      pct pacote;
      pacote.eol='\n';
      pacote.indice = '0' + i;
      if(btn==ON)
      {
        
        pacote.acao = DEVOLUCAO;
      }
      else
      {
        pacote.acao = EMPRESTIMO;
      }
      
      byte buff[sizeof(pct)];
      memcpy(buff,&pacote,sizeof(pacote)); 
      Serial.write(buff,sizeof(buff));
      delay(1000);
      //Serial.write('\n');    
    }
  }
  
  delay(300);
}

