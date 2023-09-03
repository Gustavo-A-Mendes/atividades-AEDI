/* TAD: Disciplina(nome, codigo) */

/* Tipo exportado */
typedef struct disciplina Disciplina;

/* Funções exportadas */

/* Função disc_cria
cria uma nova disciplina, alocando espaço na memória e
preenchendo os parâmetros
*/
Disciplina *disc_cria(char *nome, int codigo);

/* Função disc_codigo
retorna o código da disciplina
*/
int disc_codigo(Disciplina *disc);

/* Função disc_procura
faz uma varredura nas disciplinas criadas em busca da
disciplina selecionada, a partir do seu código
*/
Disciplina *disc_procura(Disciplina **disciplinas, int cod, int n);

/* Função disc_lista
imprime os dados das disciplinas criadas no sistema
*/
void disc_lista(Disciplina **disc, int count);

/* Função disc_exclui
  exclui a disciplina, liberando espaço da memória
*/
void disc_exclui(Disciplina *disciplina);
