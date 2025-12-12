# Projeto-Final-APC-1-
Nome: João Pedro Matos da Silva Barroso Vertelo
Matrícula: 252023465

Jogo da velha, em C:

->Tela inicial
Ao inicializar o programa, abrirá uma interface inicial, na qual informará o usuário para que comece o jogo.

->Jogo
O programa pedirá para que o usuário que estiver controlando o caracter "X" informe a linha e a coluna da sua jogada, sendo válido, apenas, valores dentro de uma matriz 3 por 3, o mesmo acontecerá para o usuário que estiver no controle do caracter "O". Ao final do jogo será imprimido na tela o vencedor (X ou O) ou se tenha havido um empate (Velha).

->Funcionalidades
telaInicial(): limpa a tela e mostra posteriormente a interface de início do jogo;
inicializarTabuleiro(): preenche todas as casas do modelo do jogo com um "espaço vazio";
exibirTabuleiro(): monta a matriz de maneira organizada;
verificarVitoria(): verifica todas as direções e sentidos da matriz, caso haja 3 caracteres iguais nessas condições ela retorna 1(vitória encontrada), caso contrário retorna 0;
verificarEmpate(): verifica se o jogo já finalizou (se todas as casas foram preenchidas com caracteres "X" e "O") e caso não encontre nenhum espaço e as condições do verificarVitoria não tenham sido atingidas, este retorna 1 (deu velha);
limparBuffer(): serve para limpar o buffer de entrada, removendo caracteres que ficaram  da digitção anterior;
