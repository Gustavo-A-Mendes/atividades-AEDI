/* TAD: Disciplina(nome, codigo) */

/* Tipo exportado */
typedef struct disciplina Disciplina;

/* Funções exportadas */

/* Função cria_disciplina
  cria uma nova disciplina, alocando espaço na memória e
  preenchendo os parâmetros
*/
Disciplina *cria_disciplina(char *nome, int codigo);

/* Função procura_disciplina
  faz uma varredura nas disciplinas criadas em busca da
  disciplina selecionada, a partir do seu código
*/
Disciplina *procura_disciplina(Disciplina **disciplinas, int cod, int n);

/* Função excluir_conta
  exclui a conta, liberando espaço da memória
*/
void excluir_disciplina(Disciplina* disciplina);
