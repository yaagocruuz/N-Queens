Quando estamos programando uma linguagem do paradigma lógico, devemos pensar de forma diferente em relação ao o uso de linguagens de outros paradigmas, 
nós não programamos pensando em encontrar a solução mas sim na descrição do problema,durante nosso trabalho usamos o MiniSat na V.2.0 para resolver o problema das N-rainhas. 

O problema das N-rainhas consiste em encontrar todas as combinações possíveis de N rainhas num tabuleiro de dimensão N por N tal que nenhuma das rainhas ataque qualquer outra. 
Duas rainhas atacam-se uma à outra quando estão na mesma linha, na mesma coluna ou na mesma diagonal do tabuleiro. 
Além disso era necessário uma modelagem automática do problema que seria executado pelo MiniSat independente do N passado para aquela instância do problema. 
Para isso foi criado uma um código em C++ 11, usando a IDE QtCreator na sua Versão 5.8.0, depois executamos uma sequências de testes com valores distintos para N, numa máquina DELL com processador i5, 8gb de ram, 1Tb de armazenamento e 2.4 ghz.




Estratégia
Nós decidimos que para a representação de uma instância do problema das N-rainhas seria feito em um arquivo .cpp, onde esse arquivos seria responsável de ter todas as cláusulas necessárias para que o MiniSat fosse capaz de resolver o problema.
	A estratégia adotada para a criação desse arquivo se deu da seguinte forma, utilizamos uma matriz que seria utilizada para representar um tabuleiro NxN, onde essa essa matriz é preenchida com os valores de 1 até N², seguindo a seguinte ordem, matriz na posição [1][1] = 1; Matriz[1][2] = 2 até que Matriz[N][N] = N². Além disso criamos 4 métodos, PreencherLinha, PreencherColuna, PreencheDiagonais e PeencherLinhaColunaDiagonal, onde sua única função era chamar os métodos anteriores , os demais métodos tinha a responsabilidade de restringir a presença de mais de uma rainha em uma mesma linha,coluna ou diagonal, essa restrição é programada por uma multiplicação de todos os valores diferentes da posição que a rainha se encontra por -1, assim tínhamos apenas um único valor positivo por linha, coluna ou diagonal que representa o local que a rainhas estava localizada naquele momento.   
	Na main escrevíamos na primeira linha do arquivo o seu cabeçário, em seguida chamamos o método responsável por preencher a matriz. Depois que a matriz era preenchida pela primeira vez criamos 2 fors encadeados que seriam responsáveis por percorrer a matriz, para cada posição que nos encontrávamos chamamos o método PreencherLinhaColunaDiagonal, em seguida era feito o processo de construção do arquivo, para cada elemento negativo na matriz era feito uma linha no arquivo que representava uma cláusula do arquivo que seria executado no MiniSat, formalizando todo o padrão necessário, separados por espaço e com um 0 no final, todo esse processo era feito para cada posição Matriz[i][j]. 
