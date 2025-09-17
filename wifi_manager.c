#include <stdio.h>
#include "wifi_manager.h"
#include "wifi_credentials.h"

// Função para inicializar o hardware do Wi-Fi 
bool wifi_arch_init(void) {
		// Inicializa o chip wi-fi utilizando a biblioteca cyw43_arch
    if (cyw43_arch_init()) {
        printf("Falha ao inicializar o módulo Wi-Fi (cyw43_arch_init).\n");
        return false;
    }
    return true;
}

// Função para conectar à rede Wi-Fi
bool wifi_connect(void) {
		// 1. Habilita o modo Station (cliente Wi-Fi)
    cyw43_arch_enable_sta_mode();
    printf("Conectando à rede '%s'...\n", WIFI_SSID);
	
		// 2. Tenta conectar à rede com timeout
    // O último argumento define o timeout em milissegundos (30s)
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, WIFI_CONNECT_TIMEOUT_MS)) {
        printf("Falha ao conectar ao Wi-Fi.\n");
        return false;
    } 
    
    printf("Conectado com sucesso!\n");
    printf("IP: %s\n", ip4addr_ntoa(netif_ip4_addr(netif_default)));
    return true;
}