//Antônio Gabriel Cardoso de Rezende Orlandini - 254161
//Alexandre De Castro Araújo Sant A. Silva - 248488
//Lucas Ferreira Machado Pinto - 247531 
//Lucas Peccinin Barbosa - 247536

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int Inicializar_LS              (Lista_l **P_inicio);
int Inserir_fim_LS              (Lista_l **P_inicio, int p, int c);
int Obter_pos_LS                (Lista_l *CP_inicio, int p, int *pos);
int Remover_meio_LS             (Lista_l **P_inicio, int pos);
int Listar_LS                   (Lista_l *CP_inicio);
int Obter_Tamanho_LS            (Lista_l *inicio, int *tamanho);
int Verifica_cadastro           (Lista_l *inicio, int p);

int inicializa                  (Fila_l *f);
int verifica_cheio              (Fila_l f);
int insere                      (Fila_l *f, int x);
int verifica_vazio              (Fila_l f);
int obter_primeiro              (Fila_l f, int *dado);
int remover                     (Fila_l *f);
int listar                      (Fila_l f);
int verificar_fila              (Fila_l f, int p);

int Listar_matriz               (int m[4][5]);
int Adicionar_matriz            (int m[4][5], int p);
int Retirar_matriz              (int m[4][5], int p);
int Encontra_carro_matriz       (int m[4][5], int p);

int main(void){

    int p;
    int c;

    int resp, pos;
    int erro;

    Lista_l *ini;
    erro = Inicializar_LS(&ini);

    Fila_l l;
    erro = inicializa(&l);

    Fila_l a;
    erro = inicializa(&a);
    
    int matriz[4][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

    int q;

    do {
        printf("Escolha:\n");
        printf("Sair -> 0\n");
        printf("Cadastrar carro -> 1\n");
        printf("Verificar cadastro -> 2\n");
        printf("Apagar cadastro -> 3\n");
        printf("Listar cadastros -> 4\n");
        printf("Adicionar carro a lavagem -> 5\n");
        printf("Remover carro da lavagem -> 6\n");
        printf("Listar Fila lavagem -> 7\n");
        printf("Adicionar carro a aspiração -> 8\n");
        printf("Remover carro da aspiração -> 9\n");
        printf("Listar Fila aspiração -> 10\n");
        printf("Retirar matriz -> 11\n");
        printf("Encontar carro no estacionamento -> 12\n");
        printf("Listar matriz -> 13\n");
        
        /*
        Funções a serem feitas:
        Verifica_Fila
        */
        
        scanf("%d", &q);
        
        switch (q)
        {
        case 1:
        
            printf("Placa:\n");
            scanf("%d",&p);
            printf("CPF:\n");
            scanf("%d",&c);

            erro=Obter_pos_LS (ini, p, &pos);

            if(erro == 1){
        
                erro=Inserir_fim_LS (&ini, p, c);
        
                if (erro == 0){ 
                    printf("Insercao realizada com sucesso\n");
                    system("pause");
                    break;
                }
                else{
                    printf("Insercao não realizada\n");
                }
            }
            else{
                printf("Placa já encontrada\n");
                break;
            }
        
        case 2:

            printf("Placa:\n");
            scanf("%d",&p);

            Verifica_cadastro(ini, p);
            
            break;

        case 3: 

            printf("Placa:\n");
            scanf("%d",&p);

            erro=Obter_pos_LS (ini, p, &pos);

            if(erro == 0){
                erro = Remover_meio_LS(&ini, pos);
                if(erro == 0){
                    printf("Cadastro removido\n");
                    break;   
                }
                else{
                    printf("Cadastro não removido\n");
                    break;
                }
            }
            else{
                printf("Placa não encontrada\n");
                break;
            }
        
        case 4:
            Listar_LS(ini);
            break;

        case 5:

            printf("Placa:\n");
            scanf("%d",&p);

            erro=Obter_pos_LS (ini, p, &pos);

            if(erro == 0){
                /*Verifica_Fila l e a*/
                erro = verificar_fila(l, p);

                if(erro == 0){
                    printf("Carro já inserido a lavagem\n");
                    break;
                }
                else{
                    erro = verificar_fila(a, p);

                    if (erro == 0)
                    {
                        printf("Carro já inserido a aspiração\n");
                        break;
                    }
                    else{
                        Retirar_matriz(matriz, p);

                        erro = insere(&l , p);

                        if(erro == 0){
                            printf("Carro inserido a Lavagem\n");
                            break;
                        }
                        else{
                            printf("Fila cheia\n");
                            break;
                        }
                    }    
                }
            }
            else{
                printf("Carro não cadastrado\n");
                break;
            }
        
        case 6:
            erro = obter_primeiro(l, &resp);

            if(erro == 0){
                erro = remover(&l);
                
                if(erro == 0){
                    Adicionar_matriz(matriz, resp);
                    printf("Operação efetuada\n");
                    break;
                }
                else{
                    printf("Operação não efetuada\n");
                    break;
                }
            }
            else{
                printf("Fila vazia\n");
                break;
            }
        case 7:
            listar(l);
            break;

        case 8:

            printf("Placa:\n");
            scanf("%d",&p);

            erro=Obter_pos_LS (ini, p, &pos);

            if(erro == 0){
                /*Verifica_Fila l e a*/
                erro = verificar_fila(a, p);

                if(erro == 0){
                    printf("Carro já inserido a aspiração\n");
                    break;
                }
                else{
                    erro = verificar_fila(l, p);

                    if (erro == 0)
                    {
                        printf("Carro já inserido a lavagem\n");
                        break;
                    }
                    else{
                        Retirar_matriz(matriz, p);

                        erro = insere(&a , p);

                        if(erro == 0){
                            printf("Carro inserido a aspiração\n");
                            break;
                        }
                        else{
                            printf("Fila cheia\n");
                            break;
                        }
                    }    
                }
            }
            else{
                printf("Carro não cadastrado\n");
                break;
            }
        
        case 9:
            erro = obter_primeiro(a, &resp);

            if(erro == 0){
                erro = remover(&a);
                
                if(erro == 0){
                    Adicionar_matriz(matriz, resp);
                    printf("Operação efetuada\n");
                    break;
                }
                else{
                    printf("Operação não efetuada\n");
                    break;
                }
            }
            else{
                printf("Fila vazia\n");
                break;
            }
        case 10:
            listar(a);
            break;
            
        case 11:
        
            printf("Placa:\n");
            scanf("%d",&p);
            
            erro = Retirar_matriz(matriz, p);
            
            if(erro == 0){
                printf("Placa retirada\n");
                break;   
            }
            else{
                printf("Placa não retirada\n");
                break;
            }
            
        case 12:
        
            printf("Placa:\n");
            scanf("%d",&p);
        
            Encontra_carro_matriz(matriz, p);
            break;
        
        case 13:
            erro = Listar_matriz(matriz);
            break;
        
        default:
            break;
        }

    } while(q != 0);
}