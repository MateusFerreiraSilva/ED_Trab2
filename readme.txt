Autor: Mateus Ferreira Silva <ferreiramateus201306@gmail.com>

O programa de segmentação de imagens .ppm com a utilização de grafos foi feito em c++ utilizando somente bibliotecas nativas da linguagem, então basta ter um compilador de c++ em sua máquina para utilizá-lo.

O programa foi dividido em vários arquivos, para compilá-los e gerar um executável há um arquivo Makefile que pode nos ajudar nesse processo.
Utilize o comando "make all" para gerar um executável com nome "prog".
Para executar: ./prog x filename.ppm

Input:
O programa recebe dois argumentos de linha de comando x e filename.ppm.
Onde x é um número inteiro de 0 a 255 que representa o valor máximo da variação de cor entre pixels para segmentação.
E filename.ppm é o nome do arquivo a ser lido.

Output:
O programa escreve as imagens segmentadas em um diretório com nome "SEG" que está no mesmo diretório do executável.

Observações: 
1 - O arquivo deve ser do formato .ppm padrão, onde há alguns meta-dados escritos em modo texto e logo em seguida os valores dos pixels escritos em modo binário.
2 - O arquivo não deve conter comentários em meio ao seus meta-dados.
3 - Deve existir um diretório com nome SEG no mesmo diretório de onde o programa é executado.
4 - Há um pasta com nome "images_set" onde há algumas imagens .ppm que obtive em: http://www.cs.cornell.edu/courses/cs664/2003fa/images/