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
<p>A minha tentativa de implementar uma mutex apenas minha falhou, leia-se implementar uma mutex que funcione perfeitamente como a do c++, ela nao conseguiu garantir em 100% dos casos que a balsa saisse cheia, ou sem as configuração restrita, ou evita-se de sair com a configuração indesejada, redundancia de verificações conseguia diminuir, as ocorrencias, mas isso nao é o desejado, um sleep(tempo) conseguia resolver, mas ainda sim era indesejado, pois nao podemos fazer nenhuma suposição sobre a velocidade das threads.
Dito isso a implementação da mutex padrão do c++ e da variavel atomica do c++ tiveram resultados satisfatorios, evitaram acesso multiplo de threads a trechos e variaveis de codigo compartilhas e nenhuma balsa saiu com configuração indesejada. Ainda tentarei me aproximar mais da implementação padrão do c++</p>
<p>Balsa, balsaAlternativa, BalsaFixed.cpp nao funcionam perfeitamente</p>
