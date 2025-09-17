

# 📡 Módulo de Conexão Wi-Fi para Raspberry Pi Pico W

Um módulo simples e reutilizável para conectar um **Raspberry Pi Pico W** a uma rede Wi-Fi usando o SDK C. O objetivo deste projeto é fornecer uma maneira fácil de adicionar conectividade à internet aos seus projetos, com configuração mínima.

-----

## 🌟 Recursos

  - 💡 **Simplicidade:** Conecte-se ao Wi-Fi com uma única chamada de função: `wifi_connect()`.
  - 🧱 **Modularidade:** Separação clara entre a lógica de conexão (`wifi_manager`) e o código principal da sua aplicação.
  - 🔒 **Segurança:** As credenciais de rede são mantidas em um arquivo (`wifi_credentials.h`) que pode (e deve) ser ignorado pelo Git.

    > **Nota:** Ele está presente nesse repositório **somente para fins didáticos**.
  - ⚙️ **Configuração Fácil:** Inclui um `CMakeLists.txt` de exemplo, pronto para ser usado.

## 🛠️ Pré-requisitos

### 🔩 Hardware

  - Raspberry Pi Pico W

### 💻 Software

  - [Pico C/C++ SDK](https://github.com/raspberrypi/pico-sdk) configurado no seu ambiente.
  - [ARM GCC Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
  - CMake

## 🚀 Como Usar

### 1\. Clone este repositório

```bash
git clone https://github.com/LabirasIFPI/bitdoglab_wifi_connection.git
cd bitdoglab_wifi_connection
```

### 2\. ✍️ Configure suas Credenciais

Crie o arquivo `wifi_credentials.h` na pasta do seu projeto e adicione o SSID e a senha da sua rede Wi-Fi.

```c
#ifndef WIFI_CREDENTIALS_H
#define WIFI_CREDENTIALS_H

#define WIFI_SSID "O_NOME_DA_SUA_REDE"
#define WIFI_PASSWORD "A_SENHA_DA_SUA_REDE"

#endif // WIFI_CREDENTIALS_H
```

> ⚠️ **AVISO DE SEGURANÇA**
> Para proteger suas senhas, em um projeto real, **SEMPRE** adicione o arquivo `wifi_credentials.h` ao seu `.gitignore`.

### 3\. 👨‍💻 Compile o Projeto

Crie um diretório de `build`, execute o `cmake` para configurar e o `make` para compilar.

```bash
mkdir build
cd build
cmake ..
make
```

### 4\. ✨ Flashe o Pico W (Fazer upload do código)

  - Pressione e segure o botão **`BOOTSEL`** no seu Pico W e conecte-o ao computador.
  - Ele aparecerá como um dispositivo de armazenamento USB (como um pen drive).
  - Arraste o arquivo `.uf2` gerado na pasta `build` (ex: `meu_projeto.uf2`) para dentro do Pico W.

A placa irá reiniciar automaticamente. Se a conexão for bem-sucedida, você poderá acompanhar as mensagens de status pelo monitor serial USB.
