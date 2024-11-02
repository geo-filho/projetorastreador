Rastreador/Localizador para Bicicletas 🚲
Projeto desenvolvido como parte de uma disciplina extensionista na faculdade, este sistema consiste em um rastreador/localizador para bicicletas, focado em segurança e facilidade de uso.

Sobre o Projeto 📍
O rastreador utiliza módulos GSM (SIM800L) e GPS (NEO-6M) para coletar dados de localização em tempo real e enviá-los diretamente para um número de telefone via SMS. O link enviado pode ser aberto em um navegador, permitindo ao usuário visualizar a localização exata da bicicleta no Google Maps. Este projeto busca fornecer uma solução prática e acessível para a proteção e recuperação de bicicletas, especialmente em casos de roubo.

Funcionalidades 🔧
Rastreamento em Tempo Real: Coleta e atualiza as coordenadas da bicicleta utilizando GPS.
Envio de Coordenadas via SMS: Transmite a localização para o celular do proprietário em um link Google Maps para visualização rápida.
Atualizações Periódicas: Envia mensagens em intervalos configuráveis para monitoramento contínuo.

Tecnologias Utilizadas 🚀
Módulo GSM (SIM800L): Responsável pela comunicação e envio das coordenadas via SMS.
Módulo GPS (NEO-6M): Garante a precisão na obtenção da latitude e longitude da bicicleta.
Arduino: Controlador principal que gerencia as operações de coleta e envio de dados.

Como Funciona 🛠️
Configuração Inicial: O dispositivo realiza uma série de testes de conexão com a rede GSM e de disponibilidade de satélites GPS.
Coleta de Coordenadas: O módulo GPS NEO-6M obtém a posição em latitude e longitude da bicicleta.
Envio da Localização: O SIM800L utiliza as coordenadas coletadas para construir um link do Google Maps, que é então enviado ao número de telefone cadastrado.
Atualizações: A cada minuto (ou intervalo configurado), o dispositivo atualiza e retransmite a localização da bicicleta.
