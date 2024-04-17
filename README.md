Dupla: 
Tamires Cristina da Silva Oliveira - RA: 11.219.048-3
Pedro Henrique Silva Reis - RA: 11.120.129-9

PROJETO 1 - COMPUTAÇÃO EMBARCADA

Introdução
Este projeto é um jogo de perguntas e respostas implementado em um Arduino UNO. O objetivo do jogo é responder corretamente a uma série de perguntas de múltipla escolha. O jogo inclui diferentes níveis de dificuldade, pontuação e feedback sonoro.

Metodologia
- Materiais Utilizados
- Arduino UNO
- 1 LED vermelho
- 4 botões (push bottom)
- Resistores conforme necessidade
- Buzzer
- Display LCD 16x2
	
Desenvolvimento do Projeto
O projeto foi desenvolvido utilizando a IDE do Arduino através do TinkerCad. O código é escrito em C++, a linguagem de programação padrão do Arduino.
O jogo é controlado por quatro botões: dois para responder às perguntas (sim ou não), um para pular a pergunta atual e outro para desistir ou reiniciar o jogo. Um LED vermelho é usado para indicar se a resposta está correta ou não, além de indicar que o tempo está acabando; e um buzzer usado para dar feedback sonoro, quando a resposta é correta é fornecido um tipo de som, e quando a resposta está erradoa, é outro tipo de som.
As perguntas e respostas são armazenadas em arrays no código, e uma função random é usada para selecionar uma pergunta aleatória a cada rodada. A pontuação do jogador é exibida no display LCD.
As perguntas escolhidas foram relacionadas a Computação Móvel e separadas por ordem de dificuldade. Colocamos perguntas de nível fácil, médio e difícil. Além de ter uma pergunta final para finalizar o jogo. Todas as perguntas são de resposta ‘verdadeiro’ ou ‘falso’, e o jogador tem a opção de pular a pergunta caso não saiba a resposta. O código comentado está disponível no github.

Experimentos
Inicialmente, realizamos uma simulação do nosso projeto de jogo de perguntas e respostas no TinkerCad. Esta etapa foi importante para validar a lógica do nosso código e o design do nosso circuito antes de passarmos para a implementação física. Para nossa satisfação, a simulação funcionou perfeitamente, o que aumentou nossa confiança e expectativa para a próxima fase do projeto.
Em seguida, passamos para a montagem do projeto físico. Utilizamos um Arduino Uno como a base do nosso sistema, juntamente com vários outros componentes eletrônicos e cada componente foi cuidadosamente conectado conforme o design do nosso circuito.
Após a montagem do circuito, fizemos o download do nosso código na placa, e para nossa alegria, o projeto físico funcionou exatamente como esperávamos. As perguntas eram exibidas corretamente no display LCD, os botões respondiam precisamente e o LED e o buzzer davam o feedback adequado.

Conclusão
Após a conclusão do projeto, podemos dizer que o desenvolver deste apresentou desafios que exigiram uma compreensão da linguagem C++ e uma abordagem criativa para a resolução de problemas.
Uma das principais dificuldades encontradas foi a implementação de um array para representar os diferentes níveis de dificuldade das perguntas. Isso se mostrou um desafio porque exigia uma compreensão sólida de como os arrays multidimensionais funcionam em C++, bem como a capacidade de manipulá-los. 
Outro desafio significativo foi a execução de um único botão para iniciar e desistir do jogo. Isso exigiu uma lógica de controle complexa para garantir que o botão pudesse alternar entre dois estados diferentes e desencadear ações diferentes dependendo do estado atual do jogo.
Para solucionar essas dificuldades, realizamos algumas pesquisas para relembrar os conceitos fundamentais da linguagem C++ e poder explorar diferentes abordagens para resolver esses problemas. Descobrimos que a melhor solução era criar funções específicas para lidar com essas tarefas complexas. Isso não só tornou o código mais organizado e fácil de entender, mas também permitiu que o código rodasse sem problemas.
No final, apesar dos desafios, conseguimos desenvolver um jogo de perguntas e respostas funcional e interativo em um Arduino. 
