*Membros e números USP:
    -Joao Vitor Villaca - 10724239
    -Bruno Gazoni - 7585037
    -Bruno Baldissera - 10724351

*Compilador usado: 
    -GCC

*Plataformas de desenvolvimento: 
    -Foram utilizados GitHub para compartilhamento de código e GNU/Linux como SO

*Instruções de uso:
    -
    
*Justificativas para as escolhas de estruturas:
    -O grupo tomou a decisão de usar listas ligadas simplesmente encadeadas como norte para o estruturamento dos dados. Também consideramos
     implementar listas circulares e/ou encadeadas com nó-cabeça, mas o início bem como o planejamento do projeto se deram em um momento
     anterior ao conhecimento mais aprofundado dessas estruturas. As listas são dinâmicas graças à natureza mutável das operações envolvidas
     no googlebot - vide inserção de novos sites em diferentes posições e remoção destes - e sua frequência num cenário realista.
     Listas duplamente encadeadas foram descartadas dado a ineficiência de operações como buscas e inserções ou remoções de elementos, já que 
     teria de haver muito manejamento de ponteiros e conexões. 
     
* Justificativas para as escolhas dos métodos:

	A inserção e remoção de ítens foi feita  a partir de reassimilação de ponteiros auxiliares (através de funções iterativas),
de forma a não gerar necessidade de maiores acessos à memória em função de empilhamentos recursivos. Consideramos
que a inserção não é realizada de forma ordenada, adequando o programa a uma amplitude maior de experiências de usuário. Assim,
as operações de remoção e inserção foram planejadas desconsiderando a ordenação do vetor, tendo como parâmetros um código específico a ser atribuído a um site, ou ainda sua posição no primeiro ou último lugar da lista.
	A inserção de novos dados no CSV foi feita a partir da administração de mudanças em structs, forma mais maleável de lidar com os inputs do usuário, que sobrescrevem o arquivo original por completo à chamada da função de atualização da database. Isso permite maior flexibilidade de acesso e atualização dos dados originais sem gerar necessidade de navegação contínua do CSV.
	Já a busca foi baseada no algoritmo de merge sort readaptado para uma lista encadeada sem nó-cabeça. O merge sort e sua natureza nlogn se demonstrou especialmente apto para a ordenação de listas encadeadas, apesar da necessidade de uso substancial de memória auxiliar, que é compensado pelo processamento facilitado.

