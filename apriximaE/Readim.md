O número  e  pode ser calculado atraveś da seguinte soma infinita:



 e = \sum_{n=0}^{\infty} \frac{1}{n!} = \frac{1}{0!} +  \frac{1}{1!} + \frac{1}{2!} + \ldots 

 



Podemos calcular o valor de e considerando o número de termos do somatório tal que

 e(n) = \sum_{i=0}^{n} \frac{1}{i!}
 



Os valores de e encontrados em cada iteração são:

 \begin{tabular}{lll}
Iter & valor & error\_relativo \\
0  & 1.000000 & -\\
1 &  2.000000 & 0.500000\\
2 &  2.500000 & 0.200000\\
3 &  2.666667 & 0.062500\\
4 & 2.708333 & 0.015385\\
\end{tabular}
 

Faça um programa que recebe uma tolerância para o erro relativo da aproximação de  e  e imprime o valor dessa aproximação precisão com 15 casas decimais.

Entrada

Um número ponto flutuante com precisão dupla epsilon.

Saída

O menor valor e(n) tal que  o erro relativo entre duas aproximações seja menor que epsilon.

Entrada                                                                                 	Saída                                                            
0.1	2.666666666666667
0.01	2.716666666666666
0.001	
