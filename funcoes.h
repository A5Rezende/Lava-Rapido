#define tam 10

struct no_l{
    
    int placa_carro;
    int cpf_cliente;

    struct no_l *prox;
}; 
typedef struct no_l Lista_l;

struct fl_l{
    
    int placa[tam];
    int ini, fim;

};
typedef struct fl_l Fila_l;

/*--------------------------------------MATRIZ------------------------------------------------------------------*/

int Listar_matriz(int m[4][5]){
    int i, e;
    for(i = 0; i < 4; i++){
        for(e = 0; e < 5; e++){
            printf(" %d ", m[i][e] );
        }
    printf("\n");
    }
}

int Adicionar_matriz(int m[4][5], int p){
    int i, e;
    for(i = 0; i < 4; i++){
        for(e = 0; e < 5; e++){
            if(m[i][e] == p){
                return 1; /* Adição feita */
            }
        }
    }
    for(i = 0; i < 4; i++){
        for(e = 0; e < 5; e++){
            if(m[i][e] == 0){
                m[i][e] = p;
                return 0; /* Adição feita */
            }
        }
    }
    return 1; /* Matriz cheia */
}

int Retirar_matriz(int m[4][5], int p){
    int i, e;
    for(i = 0; i < 4; i++){
        for(e = 0; e < 5; e++){
            if( m[i][e] == p){
                m[i][e] = 0;
                return 0; /* Adição feita */
            }
        }
    }
    return 1; /* Não encontrado na matriz */
}

int Encontra_carro_matriz(int m[4][5], int p){
    int i, e;
    for(i = 0; i < 4; i++){
        for(e = 0; e < 5; e++){
            if(m[i][e] == p){
                printf("linha : %d \n", i+1);
                printf("Coluna : %d \n", e+1);
                return 0; /* Adição feita */
            }
        }
    }
    printf("Carro não encontrado\n");
    return 1; /* Não encontrado na matriz */
}

/*--------------------------------------LISTA------------------------------------------------------------------*/

int Inicializar_LS (Lista_l **inicio)
{
    *inicio= NULL;
    return 0; /* sem erro */
}

int Inserir_fim_LS (Lista_l **inicio, int p, int c)
{
    /*Obter_pos_LS para seber se ja tem cadastro*/
    Lista_l *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Lista_l *) malloc(sizeof(Lista_l));
    no_novo -> placa_carro = p;
    no_novo -> cpf_cliente = c;

    no_novo -> prox = NULL;

    if (*inicio==NULL)
    {
        /* lista vazia. */
        *inicio = no_novo;
    }
    else   /* lista nao vazia */
    {
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            percorre = percorre -> prox;
        }
        percorre->prox = no_novo;
    }
    return 0;
}

int Obter_pos_LS (Lista_l *inicio, int p, int *pos)
{
    *pos = 0;
    while (inicio != NULL)
    {
        (*pos)++;
        if (p == inicio->placa_carro)
            return 0;     /* dado encontrado */
        inicio = inicio -> prox;
    }
    if (inicio == NULL)
        *pos = 0;
    return 1;  /* dado nao encontrado */
}

int Verifica_cadastro (Lista_l *inicio, int p)
{
    while (inicio != NULL)
    {
        if (p == inicio->placa_carro){
            printf("Placa : %d\n", inicio->placa_carro);
            printf("Cpf : %d\n", inicio->cpf_cliente);
            return 0;   
        }
        inicio = inicio -> prox;
    }
    if (inicio == NULL){
        return 1;  /* dado nao encontrado */
        printf("Carro nao encontrado\n");
    }
}

int Obter_Tamanho_LS(Lista_l *inicio, int *tamanho)
{
    Lista_l *percorre;
    *tamanho = 0;
    if(inicio != NULL)
    {
        percorre = inicio;
        while (percorre != NULL)
        {
            (*tamanho)++;
            percorre = percorre -> prox;
        }
    }
    else
    {
        *tamanho = 0;
    }
}

int Remover_inicio_LS (Lista_l **inicio)
{
    Lista_l *aux;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else
    {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

int Remover_fim_LS (Lista_l **inicio)
{
    Lista_l *aux, *percorre;
    int tamanho=0;
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover ultimo */
    }
    else
    {
        percorre = *inicio;
        while (percorre->prox != NULL)
        {
            aux = percorre;
            percorre = percorre -> prox;
        }
        aux->prox = NULL;
        free(percorre);
        return 0;   
    }
}

int Remover_meio_LS (Lista_l **inicio, int pos)
{
    int tamanho;
    Lista_l *aux, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
        return 1;  /*) posicao invalida para remocao */

    Obter_Tamanho_LS(*inicio, &tamanho);
    if (pos > tamanho)
        return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */
    /* procura pela posicao de remocao */
    if (pos==1)
    {
        /* remocao no fim */
        Remover_inicio_LS(inicio);
    }
    else
    {
        if (pos == tam)
        {
            Remover_fim_LS(inicio);
        }
        else
        {
            int pos_aux=1;
            percorre = *inicio;
            while (pos_aux!=pos) /* parar uma posicao antes */
            {
                aux = percorre;
                percorre = percorre -> prox;
                pos_aux++;
            }
            aux -> prox = percorre -> prox;
            free(percorre);
        }
    }
    return 0;
}

int Listar_LS (Lista_l *inicio)
{
    int i;
    Lista_l *aux;

    if (inicio == NULL)
    {
        return 1;  /* lista vazia */
    }
    printf("Placa | Cpf  \n");
    aux = inicio;
    do
    {
        printf("%d",inicio -> placa_carro);
        printf(" | ");
        printf("%d \n",inicio -> cpf_cliente);
        inicio = inicio->prox;
    }
    while (inicio != NULL);

    printf("\n");
    return 0; /* sem erro */
}

/*--------------------------------------FILA------------------------------------------------------------------*/

int  inicializa (Fila_l *f)
{
    (*f).ini = -1;
    (*f).fim = -1;
    return 0;
}

int verifica_cheio(Fila_l f)
{
    if (f.fim == tam-1 ){
        return 1;   // fila cheia
    }else{
        return 2;  // fila não cheia
    }
}

int insere(Fila_l *f, int x)
{

    int erro = verifica_cheio(*f);
    if (erro != 1)
    {
       (*f).fim++;
       (*f).placa[(*f).fim]=x;// inserção efetuada
       if ((*f).ini == -1)
          (*f).ini = 0;
       return 0;
    }
    else
       return 1; // impossivel inserção. overflow
}

int verifica_vazio(Fila_l f)
{
    if(f.ini == f.fim+1){
       return 0;  // fila vazia
    }else {
        return -1;
    }
}

int obter_primeiro(Fila_l f, int *dado)
{  int i;
    if ((f.ini == -1 ) || (f.ini == tam) || (f.ini == f.fim+1))
       return 1;   // fila vazia
    else {
       *dado =  f.placa[f.ini];
       return 0;
    }
}

int remover(Fila_l *f)
{
    int erro = verifica_vazio(*f);
    if (erro != 0)
    {
      (*f).ini++;  // remocao efetuada
       return 0;
    }
    else
       return 1; // impossivel remover. Underflow
}

int listar(Fila_l f)
{  int i,erro;
    erro=verifica_vazio(f);
    if (erro!=0)
    {
       for (i=f.ini; i<=f.fim; i++){
        printf("%d",f.placa[i]);
        printf("\n");
       }
       return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}

int verificar_fila(Fila_l f, int p)
{  int i,erro;
    erro=verifica_vazio(f);
    if (erro!=0)
    {
       for (i=f.ini; i<=f.fim; i++){
            if(f.placa[i] == p){
                return 0;
            }
       }
       return 1;
    }
    else return 2;  // nao possivel listar pois a fila esta vazia
}