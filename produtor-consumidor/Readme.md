<p>O problema do produtor e consumidor, também referido como Bounded Buffer Problem (BBP), consiste em um desafio de sincronização de duas ou mais threads (tarefas) concorrentes que têm acesso a um mesmo recurso do programa que está sendo executado. O fato de o recurso estar sendo compartilhado, implica na possibilidade de conflitos entre as threads que disputam pelo controle da CPU para acessar esse mesmo recurso.

No caso do BBP, o recurso disputado é um buffer de memória (um vetor), de tamanho limitado/fixo, daí o motivo do nome. O produtor é o responsável por enfileirar novos jobs ou dados nesse buffer, e o consumidor assume a responsabilidade de extrair esses dados do buffer. Porém o seguinte problema poderá emergir: E se o produtor produzir muito rápido, e o consumidor não for capaz de acompanhá-lo?</p>

<p>Retirado de: https://deinfo.uepg.br/~alunoso/2021/SO/producerconsumer_java/</p>