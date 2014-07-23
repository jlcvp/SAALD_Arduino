#define NUM_BTNS 3 //Numero de botoes
#define ON HIGH
#define OFF LOW
#define EMPRESTIMO 'R'
#define DEVOLUCAO 'D'

typedef struct pckote{
  char indice;
  char acao;
  char eol;
} pct;

const int input[]={8,9,10}; //pinos dos botoes

boolean btns_state[NUM_BTNS]={OFF,OFF,OFF}; //mudar aqui pra dar match na inicializacao do tamanho do vetor

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<NUM_BTNS;i++)
  {
    pinMode(input[i],INPUT); //setup dos botoes
  }
}

void loop()
{
  for(int i=0;i<NUM_BTNS;i++) //lê todos os botoes e verificar se mudaram de estado
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
      Serial.write(buff,sizeof(buff)); //envia os dados via serial (bluetooth)
      delay(700);
      //Serial.write('\n');    
    }
  }
  
  delay(300);
}

