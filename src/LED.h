#ifndef LED_h
#define LED_h

#include <Arduino.h> 


/**
   * @class Led
   * @brief Classe para controle não bloqueante de um Led,
   *
   * Permite Ligar, desligar, ligar por um tempo,
   * piscar continuamente e piscar por quantidade definido.
   *
   * @param pin  pino ao qual o Led foi conectado.
   * 
   * 
   * 
   * @note O método update() deve ser chamado continuamente no loop.
   */
class Led
{
private:
  uint8_t pino;
  bool estado;
  bool apagarNoTempo;
  uint32_t apagarNoMomento;
  uint32_t tempoEspera;
  bool estadoPiscar;
  uint32_t tempoAnteriorPisca;
  uint16_t repeticoes;


  /**
   * @brief Processa o desligamento temporizado. 
   */
  void funcaoApagarNoTempo();

  /**
   * @brief Processa a lógica de piscada do Led.
   */
  void funcaoPiscar();

public:
  /**
   * @brief Constrói um objeto Led.
   * 
   * @param pin Número do pino digital onde o Led está conectado.
   */
  Led(uint8_t pin);


 /**
  * @brief Liga o Led continuamente. 
  */
  void acender();

  /**
   *  @brief Liga o Led por um tempo determinado.
   * 
   * @param tempoLigado Tempo, em milissegundos, que o Led ficará ligado.
   */
  void acender(uint32_t tempoLigado);

/**
 * @brief Desliga o Led e cancela modos automáticos. 
 */
  void apagar();

  /**
   * @brief Ligar o Led e piscar infinitamente.
   */
  void piscar();

  /**
   * @brief Liga o Led e determina a frequência do piscar.
   * 
   * @param freq Frequência, que o Led irá piscar.
   */
  void piscar(float freq);

  /**
   * @brief Liga o Led e além de determinar a frequência que irá piscar ele determina a quantidade limite que esses ciclos aconteceram.
   * 
   * @param freq Frequência, do piscar.
   * @param repeticoes Repetições, determina a quantidade limite de piscadas
   */
  void piscar(float freq, uint16_t repeticoes);

  /**
   * @brief Alterna o estado de HIGH para LOW ou vice versa.
   */
  void alternar();

  /**
   * @brief Permite que eu altere o estado do Led localmente sem mexer na biblioteca. 
   * 
   * @param estado Estado, é o parâmetro que define se o Led liga o não.
   */
  void setEstado(bool estado);


  /**
   * @brief Permite que eu peça para o programa me retornar o pino que o Led está locado.
   */
  uint8_t getPino();


  /**
   * @brief Atualiza a lógica interna da classe e escreve no pino.
   * 
   * @note Deve ser chamado repetidamente dentro da função loop().
   */
  void update();
};

#endif