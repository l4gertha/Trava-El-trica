//Definição de nome dos pinos do ESP32.
// Criação de variáveis para que funcionem em todo o progrma.
#define LEDCERTO 32
#define LEDERRADO 33
String texto;
int valor_lido;
int senha;
int verificar;

//Inicialização da porta serial.
//Configurações dos pinos como saída.
void setup() {
  Serial.begin(115200);
  pinMode (LEDCERTO, OUTPUT);
  pinMode (LEDERRADO, OUTPUT);  
}

//Atribui valores padrões (iniciais) para as variaveis.
//Chama as funções criadas.
void loop() {
  senha = 7312; 
  verificar = 0;
  entrada();
  verificar_senha();
  led_verde ();
  led_vermelho ();
  verificar = 0;
  valor_lido = 0;
}

//Função para ler a entrada.
//Vê se tem algo para ler.
//Atribui o texto à variavel texto.
//Transforma o texto em número.
void entrada () {
  if (Serial.available () > 0) {
    texto =  Serial.readString ();
    valor_lido = texto.toInt ();
  }
}

//Função para verificar se a senha está correta.
//Variavel senha possui um valor pré-determinado.
//Se a variavel valor_lido for igual a senha, a variavel verificar fica com o valor de 1
//Se não, a variavel verificar fica com o valor 2.
void verificar_senha () {
  senha = 7312;
  if (valor_lido == senha) {
  verificar = 1;
  } 
  if (valor_lido != senha && valor_lido != 0) {
  verificar = 2;
  }
}

//Função para acender o LED verde por 5s, indicando que a senha está correta.
//Se a variavel verificar for igual 1, o led verde acende pro 5s.
void led_verde () {
  if (verificar == 1) {
    digitalWrite (LEDCERTO, true); 
    delay (5000); 
    digitalWrite (LEDCERTO, false);
  }
}

//Função para acender o pisca LED vermelho, indicando que a senha está errada.
//Se a variavel verificar for igual 5, o led vermelho acende piscando 3x.
void led_vermelho () {
  if (verificar == 2) {
    digitalWrite (LEDERRADO, true); 
    delay (500); 
    digitalWrite (LEDERRADO, false);
    delay (500);
    digitalWrite (LEDERRADO, true); 
    delay (500); 
    digitalWrite (LEDERRADO, false);
    delay (500);
    digitalWrite (LEDERRADO, true); 
    delay (500); 
    digitalWrite (LEDERRADO, false);
    delay (500);
  }
}

