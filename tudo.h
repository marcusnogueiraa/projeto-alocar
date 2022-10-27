#ifndef TUDO_H
#define TUDO_H

typedef struct{
      char nome[100];
      char cpf[100];
      int ano_nascimento;
      int alugou;
      
    }cliente;

typedef struct{
      char modelo[100];
      char cor[100];
      int ano;
      char placa[8];
      int alugado; 
      int pos_cliente_alugou; // posição no vetor do cliente que alugou o carro  
    }carro;

carro* insere_carro(carro *v, int *n, carro novo);
cliente* insere_cliente(cliente *u, int *y, cliente novo);
void ler_dados();
void armazenar_dados();
void menu_cadastro_carro();
void menu_cadastro_cliente();
void menu_alugar();
void menu_devolver();
void menu_verificar();
void menu_cadastros();
void desenvolvedores();
void logo();
void sair();
void menu_geral();
void menu_remove_carro();

#endif