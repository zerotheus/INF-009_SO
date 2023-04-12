Instituto Federal da Bahia
Disciplina: INF009 – Sistemas Operacionais

Exercício de Semáforos

Problema:
Em algum lugar perto de Redmond, Washington, há um barco a remo que é usado para
atravessar um rio. Os passageiros deste barco são hackers do Linux e funcionários da Microsoft
(servos)

A balsa pode acomodar exatamente quatro pessoas; não sairá da costa com mais ou menos. Para
garantir a segurança dos passageiros, não é permitido colocar um hacker no barco com três
servos, ou colocar um servo com três hackers. Qualquer outra combinação é segura.
À medida que cada thread embarca no barco, ela deve invocar uma função chamada board().

Você deve garantir que todas as quatro threads de cada barco chamem a função board() antes
qualquer uma das threads do próximo barco.

Após todas as quatro threads terem invocado função board(), exatamente uma delas deve
chamar uma função rowBoat(), indicando que essa thread irá assumir os remos. Não importa
qual thread chama a função, desde que alguma o faça.

** Não se preocupe com a direção da viagem. Suponha que estamos interessados apenas em
tráfego indo em uma das direções.

Exercício:
Implemente uma solução (em pseudocódigo de alto nível), usando semáforos, que implemente
uma solução para o problema descrito.

<h1>Aviso</h1>

<p>Como o intuito é aprendizado as outras versoes que tem nao apresentaram consistencia na resolução, somente a fixed apresenta o resultado desejado depois da adiação do sleep, ponto negativo, tenho de fazer uma versao windows e uma linux</p>