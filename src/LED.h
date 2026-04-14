#ifndef LED_h
#define LED_h


#include <Arduino.h>

/**
 * @class Led
 * @brief CLasse para controle não bloqueante de um LED.
 * 
 * Permite ligar, deligar, ligar por um tempo,
 * piscar continuamente a piscar por quanatidade definida
 * 
 * @note o método ()update deve ser chamado 
 * 
 */
class Led
{
    private:
       uint8_t pino;
       bool estado;

      bool apagarNoTempo;
      uint32_t apagarNoMomento;
      bool estadoPiscar;

      uint32_t tempoEspera;
      uint32_t tempoAnteriorPiscar;
      uint16_t repeticoes; 

     /**
      * @brief Constrói um objeto Led.
      * @param pin - pino ao qual o Led foi conectado.
      */
      void funcaoApagarNoTempo();

     /**
      * 
      */
      void funcaoPiscar();

    public:


      /**
      * @brief Constrói um objeto Led.
      * @param pin - pino ao qual o Led foi conectado.
      */
       Led(uint8_t pin);


       /**
        * @brief Liga o led continuamnete
        */
       void acender();

       /**
      * @brief Liga o Led por um tempo determinado.
      * @param tempoLigado Tempo, em millissegundos, que o Led ficara ligado.
      */
       void acender(uint32_t tempoLigado);


       /**
        * @brief Desliga o Led e cancela modos automáticos.
        */
       void apagar();
       
      /**
       * @brief  
       */
       void piscar();

      /**
       * @brief 
       */
       void piscar(float freq);

       /** 
        * @brief 
       */
       void piscar(float freq, uint16_t repeticoes);


       /** 
        * @brief 
       */
       void alternar();

       /** 
        * @brief 
       */
       void setEstado(bool estado);

       /**
        * @brief 
        */
       uint8_t getPino();

       /** 
        *@brief Atualiza a logica interna e atualiza o pino.
       */
       void update();

};

#endif  
