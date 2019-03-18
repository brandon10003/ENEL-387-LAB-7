#include "uart.h"
#include "stm32f10x.h"
 
 void inituart(void)
 {
	USART3->CR1 |= USART_CR1_UE;
	USART3->BRR = 0x9C4;
	USART3->CR1 |= USART_CR1_TE;
	USART3->CR1 |= USART_CR1_RE;
 }
uint8_t readusart(void)
{
	uint8_t in;
	while((USART3->SR & USART_SR_RXNE) != USART_SR_RXNE){}
		in = USART3->DR;
	
	
	return in;
}
void writeusart(uint8_t out)
{
	while((USART3->SR & USART_SR_TXE) != USART_SR_TXE){
	}
	USART3->DR = out;
}