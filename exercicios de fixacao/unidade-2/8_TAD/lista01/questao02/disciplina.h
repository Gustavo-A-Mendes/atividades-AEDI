/* TAD: disciplina(nome, codigo) */

/* Tipo exportado */
typedef struct disciplina Disciplina;

/* Funções exportadas */

/* Função cria_disciplina
  cria uma nova disciplina, alocando espaço na memória e
  preenchendo os parâmetros
*/
Disciplina *cria_disciplina(char *nome, int codigo);

/* Função procura_disciplina
  
*/
Disciplina *procura_disciplina(Disciplina **disciplinas, int cod);

/* Função excluir_conta
  exclui a conta, liberando espaço da memória
*/
void excluir_disciplina(Disciplina* disciplina);
