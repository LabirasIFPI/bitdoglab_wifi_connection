#include <stdio.h>
#include "pico/stdlib.h"
#include "wifi_manager.h"

int main(){
	// Inicializações do seu sistema
    stdio_init_all();
    sleep_ms(2000); // Pausa para abrir o monitor serial

    // 1. Inicializa o hardware do Wi-Fi
    wifi_arch_init();

	// 2. Tenta conectar à rede
    if (wifi_connect()) {
        printf("Conectado com sucesso!");
    } else {
        printf("Falha ao conectar ao Wi-Fi.\n");
    }

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
        
        // A lógica do seu programa pode continuar aqui.
        // A conexão Wi-Fi será mantida em background.
    }
}
