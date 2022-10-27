#include "tudo.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
                                                                                                                    
//                AAA                lllllll                                                                            
//               A:::A               l:::::l                                                                            
//              A:::::A              l:::::l                                                                            
//             A:::::::A             l:::::l                                                                            
//            A:::::::::A             l::::l     ooooooooooo        cccccccccccccccc   aaaaaaaaaaaaa     rrrrr   rrrrrrrrr   
//           A:::::A:::::A            l::::l   oo:::::::::::oo    cc:::::::::::::::c   a::::::::::::a    r::::rrr:::::::::r  
//          A:::::A A:::::A           l::::l  o:::::::::::::::o  c:::::::::::::::::c   aaaaaaaaa:::::a   r:::::::::::::::::r 
//         A:::::A   A:::::A          l::::l  o:::::ooooo:::::o c:::::::cccccc:::::c            a::::a   rr::::::rrrrr::::::r
//        A:::::A     A:::::A         l::::l  o::::o     o::::o c::::::c     ccccccc     aaaaaaa:::::a   r:::::r     r:::::r
//       A:::::AAAAAAAAA:::::A        l::::l  o::::o     o::::o c:::::c                aa::::::::::::a   r:::::r     rrrrrrr
//      A:::::::::::::::::::::A       l::::l  o::::o     o::::o c:::::c               a::::aaaa::::::a   r:::::r            
//     A:::::AAAAAAAAAAAAA:::::A      l::::l  o::::o     o::::o c::::::c     ccccccca ::::a    a:::::a   r:::::r            
//    A:::::A             A:::::A    l:::::-  o:::::ooooo:::::o c:::::::cccccc:::::ca ::::a    a:::::a   r:::::r            
//   A:::::A               A:::::A   l::::::l o:::::::::::::::o  c:::::::::::::::::ca :::::aaaa::::::a   r:::::r            
//  A:::::A                 A:::::A  l::::::l  oo:::::::::::oo    cc:::::::::::::::c  a::::::::::aa:::a  r:::::r            
// AAAAAAA                   AAAAAAA llllllll    ooooooooooo        cccccccccccccccc   aaaaaaaaaa  aaaa  rrrrrrr            
                                                                                                                                                                        
// Declarando os menus:
char v; // voltar ao menu
int n=0; // quantidade de elementos do vetor de carros
int y=0; // quantidade de elementos do vetor de clientes

// vetores de estrutura
carro *carros = 0;
cliente *clientes = 0;

carro* insere_carro(carro *v, int *n, carro novo){
  v = (carro*) realloc(v, (*n+1) * sizeof(carro));
  v[*n]=novo;
  (*n)++;
  return v;
}

cliente* insere_cliente(cliente *u, int *y, cliente novo){
  u = (cliente*) realloc(u, (*y+1) * sizeof(cliente));
  u[*y] = novo;
  (*y)++;
  return u;
}

void ler_dados(){ 
    FILE *f1 = fopen("clientes.txt", "r");
    cliente add_cliente;
    while (fscanf (f1, "%[^\n]\n%[^\n]\n%d\n%d\n", add_cliente.nome, add_cliente.cpf, & add_cliente.ano_nascimento, & add_cliente.alugou) == 4){
        clientes = insere_cliente(clientes, &y, add_cliente);
    }
    fclose(f1);

    FILE *f2 = fopen("carros.txt", "r");
    carro add_carro;
    while (fscanf (f2, "%[^\n]\n%[^\n]\n%d\n%[^\n]\n%d\n%d\n", add_carro.modelo, add_carro.cor, & add_carro.ano, add_carro.placa, & add_carro.alugado, & add_carro.pos_cliente_alugou) == 6){
        carros = insere_carro(carros, &n, add_carro);
    }
    fclose(f2);
}

void armazenar_dados(){ 
  FILE *f1 = fopen("clientes.txt", "w");
  for (int i = 0; i < y; i++){
    fprintf(f1, "%s\n%s\n%d\n%d\n", clientes[i].nome, clientes[i].cpf, clientes[i].ano_nascimento, clientes[i].alugou);
  }
  fclose(f1);

  FILE *f2 = fopen("carros.txt", "w");
  for (int i = 0; i < n; i++){
    fprintf(f2, "%s\n%s\n%d\n%s\n%d\n%d\n", carros[i].modelo, carros[i].cor, carros[i].ano, carros[i].placa, carros[i].alugado, carros[i].pos_cliente_alugou);
  }
  fclose(f2);
}

//          --->    O menu_cadastro_carro serve para inicializar o menu de cadastro de carros   .
void menu_cadastro_carro(){ 
    system("cls");

    carro registro_carro;

    int encontrou_placa_igual = 0;

    printf("* ========================================================== *\n");
    printf("| Cadastro de veiculos  : \n");
    printf("|\n| ---> Por favor responda as perguntas abaixo  \n");
    printf("| \n");
    printf("|        - Modelo do veiculo  : ");
    scanf(" %[^\n]", registro_carro.modelo);
    printf("|        - Cor do veiculo     : ");
    scanf(" %[^\n]", registro_carro.cor);
    printf("|        - Ano do veiculo     : ");
    scanf(" %d", &registro_carro.ano);
    printf("|        - Placa do veiculo   : ");
    scanf(" %[^\n]", registro_carro.placa);

    registro_carro.alugado = 0;
    registro_carro.pos_cliente_alugou = y;

    for (int i = 0; i < n; i++){
        if (strncmp(carros[i].placa, registro_carro.placa, sizeof(carros[i].placa)) == 0) {
          encontrou_placa_igual = 1;              
        }
      }
      
      if (encontrou_placa_igual){
        printf("|\n| ERRO : A placa incerida ja existe no sistema \n");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        printf("\n\n* ========================================================== *\n");     
      }

      else{
        carros = insere_carro(carros, &n, registro_carro);
        Sleep(200);
        printf("| - Veiculo cadastrado com sucesso ! ");
        printf("\n* ========================================================== *\n");
        Sleep(200);
      }

    printf("\n| \n| Pressione qualquer tecla para voltar ao menu : ");
    scanf(" %c", &v);
    menu_geral();

}

//          --->    O menu_cadastro_cliente serve para inicializar o menu de cadastro de clientes   .
void menu_cadastro_cliente(){ 
    system("cls");
    
    cliente registro_cliente;

    int encontrou_cpf_igual = 0;

    printf("* ========================================================== *\n");
    printf("| Cadastro de novos clientes  : \n");
    printf("|\n| ---> Por favor responda as perguntas abaixo  \n");
    printf("| \n");
    printf("|        - Nome do cliente     : "); 
    scanf(" %[^\n]", registro_cliente.nome); 
    printf("|        - CPF do cliente      : ");
    scanf(" %[^\n]", registro_cliente.cpf);
    printf("|        - Ano de nascimento   : ");
    scanf("%d", &registro_cliente.ano_nascimento);

    registro_cliente.alugou = 0;

    // procurando os dados buscados nos vetores de clientes e carros 
      for (int i = 0; i < y; i++){
        if (strncmp(clientes[i].cpf, registro_cliente.cpf, sizeof(clientes[i].cpf)) == 0){
          encontrou_cpf_igual = 1;  
        }
      } 

    if (encontrou_cpf_igual){
      printf("|\n| ERRO : O CPF informado ja existe no sistema . \n");
      printf("\n\n* ========================================================== *\n");
    }
    
    else if (encontrou_cpf_igual == 0 && (2022 - registro_cliente.ano_nascimento) >= 18){

      clientes=insere_cliente(clientes, &y, registro_cliente);
      
      printf("\n| - Cadastro realizado com sucesso ! ");
      printf("\n\n* ========================================================== *\n");
      }

    else {
    Sleep(200);
      system("color c");
      printf("| ERRO : Usuario menor de idade.");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      }
    Sleep(200);

    printf("\n\n Pressione qualquer tecla para voltar ao menu : ");
    scanf(" %c", &v);
    menu_geral();
}

//          --->    O menu_alugar serve para alugar os veículos assim como fazer as verificações .
void menu_alugar(){ 
    system("cls");
    char x;
    printf("* ========================================================== *\n");

    printf("| Aluguel de veiculos  : \n");
    printf("|\n| ---> Por favor responda as perguntas abaixo  \n");
    printf("| \n");
    printf("|        - O usuario possui cadastro ? (s/n)  : ");
    scanf(" %c", &x);
    if (x == 'n' ||x == 'N'){
        printf("\n Deseja cadastrar o cliente ? (s/n) ");
        scanf(" %c", &x);
        if (x == 's' || x == 'S'){
          menu_cadastro_cliente();
        }
        else {
          menu_geral();
        }
      }
    else if(x =='s' || x =='S'){

      int pos_carro; // posição do carro buscado no vetor
      int pos_cliente; // posição do cliente buscado no vetor

      int encontrou_veiculo = 0;
      int encontrou_cliente = 0;

      int concluir = 1;

      char cpf_buscado[100];
      char placa_buscada[100];

      printf("|        - Digite o cpf do cliente     : ");
      scanf(" %[^\n]", cpf_buscado);
      printf("|        - Digite a placa do veiculo   : ");
      scanf(" %[^\n]", placa_buscada);
      
      // procurando os dados buscados nos vetores de clientes e carros 
      for (int i = 0; i < y; i++){
        if (strncmp(clientes[i].cpf, cpf_buscado, sizeof(clientes[i].cpf)) == 0){
          pos_cliente = i;
          encontrou_cliente = 1;  
        }
      }
      
      for (int i = 0; i < n; i++){
        if (strncmp(carros[i].placa, placa_buscada, sizeof(carros[i].placa)) == 0) {
          pos_carro = i;
          encontrou_veiculo = 1;              
        }
      }
      
      if (encontrou_cliente == 0){
        printf("|\n| ERRO : O CPF inserido nao consta no sistema \n");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        concluir = 0;      
      }

      if (encontrou_veiculo == 0){
        printf("|\n| ERRO : Essa placa nao pertence a nenhum veiculo no sistema \n");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        concluir = 0;      
      }  

      // verificando se o usuario possui um carro alugado
      if(encontrou_cliente && encontrou_veiculo && clientes[pos_cliente].alugou){
        
        int pos_carro_alugado;

        for (int i = 0; i < n; i++){
          if(carros[i].pos_cliente_alugou == pos_cliente && carros[i].alugado){
            pos_carro_alugado = i;
          }
        }

        printf("|\n| ERRO : O usuario ja possui o seguinte veiculo alugado :  %s  \n", carros[pos_carro_alugado].modelo);
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        concluir = 0;
      }   
      
      if(encontrou_cliente && encontrou_veiculo && carros[pos_carro].alugado == 1){
        int pos_cliente_alugou = carros[pos_carro].pos_cliente_alugou; 
        printf("|\n| ERRO : Esse veiculo ja esta alugado pelo seguinte cliente :  %s  \n", clientes[pos_cliente_alugou].nome);
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        concluir = 0;
      }
      
      // Caso não entre em nenhum caso de erro 
      if(concluir){
        // alterando valores booleanos 
        
        clientes[pos_cliente].alugou = 1;
        carros[pos_carro].alugado = 1;
        
        // armazenando posição nos vetores
        carros[pos_carro].pos_cliente_alugou = pos_cliente; 
        
        Sleep(200);
        printf("| - O Veiculo '%s' foi alugado por '%s' com sucesso !\n", carros[pos_carro].modelo, clientes[pos_cliente].nome);
      } 

      printf("* ========================================================== *\n");
      printf("\n| \n| Pressione qualquer tecla para voltar ao menu : ");
      scanf(" %c", &v);
      menu_geral();
    }
  }

void menu_remove_carro(){
  system ("cls");

  int nao_encontrou = 1;
  char placa_buscada[100];

  printf("* ========================================================== *\n");
  printf("|\n| ---------- Menu para remover carros cadastrados ----------\n");
  printf("| Digite a placa do veiculo que deve ser removido :");
  scanf(" %[^\n]", placa_buscada);
  for(int i = 0; i < n; i++){
    if(strncmp(carros[i].placa, placa_buscada, sizeof(carros[i].placa)) == 0){

      nao_encontrou = 0;

      if (carros[i].alugado){
        printf("|\n");
        printf("| ERRO : O veiculo esta em posse de um cliente. \n");
        printf("\n\n* ========================================================== *\n");
      }

      carros[i] = carros[n - 1];
      carros = (carro*) realloc(carros, (n-1) * sizeof(carro));
      n--;

      printf("|\n");
      printf("| ATENCAO : Veiculo removido com sucesso \n");
      printf("\n\n* ========================================================== *\n");
      break;

      
    }
  }

  if (nao_encontrou){
    printf("| ATENCAO : Veiculo buscado nao existe. \n");
    printf("\n\n* ========================================================== *\n");
  }
  
  printf("\n\nPressione qualquer tecla para voltar ao menu : ");
  scanf(" %c", &v);
  menu_geral();
}

//          --->    O menu_devolver serve para devolver um veículos alugado assim como fazer as verificações .
void menu_devolver(){
  system("cls");

    char cpf_buscado[100];
    char placa_buscada[100];

    int encontrou_cliente = 0;
    int encontrou_veiculo = 0;

    int pos_cliente = 0;
    int pos_carro = 0;

    int concluir = 1;

    printf("* ========================================================== *\n");

    printf("| Devolucao de veiculos  : \n");
    printf("|\n| ---> Por favor responda as perguntas abaixo  \n");
    printf("| \n");
    printf("|        - Informe o CPF do cliente    : ");
    scanf(" %[^\n]", cpf_buscado);                 
    printf("|        - Informe a placa do veiculo  : ");                  
    scanf(" %[^\n]", placa_buscada);

    
    // procurando os dados buscados nos vetores de clientes e carros 
    for (int i = 0; i < y; i++){
      if (strncmp(clientes[i].cpf, cpf_buscado, sizeof(clientes[i].cpf)) == 0){
        pos_cliente = i;
        encontrou_cliente = 1;  
        }
    }
      
    for (int i = 0; i < n; i++){
      if (strncmp(carros[i].placa, placa_buscada, sizeof(carros[i].placa)) == 0) {
        pos_carro = i;
        encontrou_veiculo = 1;     
                 
      }
    }

    if (encontrou_cliente == 0){
        printf("|\n| ERRO : O CPF inserido nao consta no sistema \n");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
      concluir = 0;      
    }

    if (encontrou_veiculo == 0){
      printf("|\n| ERRO : Essa placa nao pertence a nenhum veiculo no sistema \n");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      concluir = 0;      
    }

    // verificando se o usuário não alugou um veículo, ou se o veículo não está alugado.
    if(encontrou_cliente && encontrou_veiculo && clientes[pos_cliente].alugou == 0){
      
      printf("|\n| ERRO : Esse usuario nao possui um veiculo alugado .\n");
      Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
      concluir = 0;
    }   
      
      
    if(encontrou_cliente && encontrou_veiculo && carros[pos_carro].alugado == 0){
       
      printf("|\n| ERRO : Esse veiculo nao esta alugado .\n");
      Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
      concluir = 0;
    }

    // Caso não entre em nenhum caso de erro 
    if(concluir){
      // alterando valores booleanos 
      clientes[pos_cliente].alugou = 0;
      carros[pos_carro].alugado = 0;
      
      // armazenando posição nos vetores
      carros[pos_carro].pos_cliente_alugou = y; 
      
      Sleep(200);
      printf("| O veiculo '%s' foi devolvido por '%s' com sucesso !\n", carros[pos_carro].modelo, clientes[pos_cliente].nome);
    }  

    printf("* ========================================================== *\n");

    Sleep(200);
    printf("\n| \n| Pressione qualquer tecla para voltar ao menu : ");
    scanf(" %c", &v);
    menu_geral();
      
}

//          --->    O menu_verificar serve para verificar a situação atual de um cliente .
void menu_verificar(){ 
  system("cls");

  char cpf_buscado[100];

  int pos_carro;
  int pos_cliente;
  int encontrou_cliente = 0; 

  printf("* ========================================================== *\n");
  printf("| Verificar a situacao do cliente  : \n");
  printf("|\n| ---> Por favor responda as perguntas abaixo  \n");
  printf("| \n");
  printf("|        - Informe o CPF do cliente  : ");       
  scanf(" %[^\n]", cpf_buscado);       

  // procurando cpf inserido
  for (int i = 0; i < y; i++){
    if (strncmp(clientes[i].cpf, cpf_buscado, sizeof(clientes[i].cpf)) == 0){
      pos_cliente = i;
      encontrou_cliente = 1;  
      }
  }

  if (encontrou_cliente == 0){
       printf("|\n| ERRO : O CPF inserido nao consta no sistema \n");     
       Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");
        Sleep(200);
        system("color c");
        Sleep(200);
        system("color 3");  
  }

  // verificando se o usuario possui um carro alugado
  for (int i = 0; i < n; i++){
    if(carros[i].pos_cliente_alugou == pos_cliente && carros[i].alugado){
      pos_carro = i;
    }
  }
  
  if(encontrou_cliente){
    printf("* ========================================================== *\n");
    printf("|\n| ---> Informacoes do Cliente:  \n");
    printf("|   - Nome: %s \n", clientes[pos_cliente].nome);
    printf("|   - CPF: %s \n", clientes[pos_cliente].cpf);
    printf("|   - Ano de Nascimento: %d \n", clientes[pos_cliente].ano_nascimento);
    if(clientes[pos_cliente].alugou){
      
      printf("|\n| ---> Informacoes do Veiculo Alugado:  \n");
      printf("|   -  Modelo: %s \n", carros[pos_carro].modelo);
      printf("|   -  Cor: %s \n", carros[pos_carro].cor);
      printf("|   -  Placa: %s \n", carros[pos_carro].placa);
      printf("|   -  Ano: %d \n", carros[pos_carro].ano);
      
    } else{
      printf("|\n| O usuario nao possui veiculos em seu nome .\n");
    }
    
  }
  
  printf("* ========================================================== *\n");
  
  printf("\nPressione qualquer tecla para voltar ao menu : ");
  scanf(" %c", &v);
  menu_geral();

}

//          --->    O menu_cadastro serve para listar os cadastros de usuarios e veiculos .
void menu_cadastros(){
  system("cls");

  int escolha;

  printf("* ========================================================== *\n");
  printf("|\n| ---------- O que deseja fazer ? ----------\n");
  printf("|       01 - Verificar Clientes Cadastrados\n");
  printf("|       02 - Verificar Veiculos Cadastrados\n");
  printf("| \n");
  printf("\n\n* ========================================================== *\n");

  printf("\n Digite um numero : ");
  scanf("%d", & escolha);

  if (escolha == 1){
    system("cls");
    printf("\n\n* ========================================================== *\n");
    printf("|\n| - Usuarios Cadastrados: \n");
    if (y == 0){
      printf("|\n| ATENCAO : Nao existem usuarios registrados no sistema \n");
    } else{
      for(int i = 0; i < y; i++){
        printf("| (%d) - Nome: %s - CPF: %s", i+1, clientes[i].nome, clientes[i].cpf);
        if (clientes[i].alugou){
          printf(" [Alugou]");
        }
        printf("\n");

      }
    }
  }

  else if (escolha == 2){
    system("cls");
    printf("\n\n* ========================================================== *\n");
    printf("|\n| - Veiculos Cadastrados: \n");
    if (n == 0){
      printf("|\n| ATENCAO : Nao existem veiculos registrados no sistema \n");
    } else{
      for(int i = 0; i < n; i++){
        printf("| (%d) - Modelo: %s - Placa: %s", i+1, carros[i].modelo, carros[i].placa);
        if (carros[i].alugado){
          printf("  [ Alugado ]");
        }
        printf("\n");
      }
    }
  } else{
    Sleep(200);
      system("color c");
      printf("| - ERRO : Digite um numero valido ");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      menu_geral();
  }

  printf("\n\n* ========================================================== *\n");
  printf("\nPressione qualquer tecla para voltar ao menu : ");
  scanf(" %c", &v);
  menu_geral();
}

void desenvolvedores(){
 system("cls");

    printf("* ==================================================================== *\n\n");
                                                                                                               
    printf("             :::::::::       ::::::::::    :::     :::\n") ;
    printf("             +:+    +:+      +:+           +:+     +:+ \n");
    printf("             +:+    +:+      +:+           +:+     +:+ \n");
    printf("             +#+    +:+      +#++:++#      +#+     +:+ \n");
    printf("             +#+    +#+      +#+            +#+   +#+   \n");
    printf("             #+#    #+#      #+#             #+#+#+#  \n");
    printf("             #########       ##########        ###        \n");  

    printf ("\n - Pedro Nobrega          - Pedro Wilson          - Marcus Nogueira\n")     ;                                                                                    

    printf("\n* ==================================================================== *\n");
  
    printf(" \n Precione qualquer tecla para voltar ao menu : ");
    scanf(" %c", &v);
    menu_geral();
}

void logo(){
   system("cls");
    system("color 3");

    printf("* ===================================================================================================================== *");

    printf("\n\n       d8888 888                                          .d8888b.                    888                           \n");
    printf("      d88888 888                                         d88P  Y88b                   888     \n");
    printf("     d88P888 888                                         Y88b.                        888  \n");
    printf("    d88P 888 888  .d88b.   .d8888b  8888b.  888d888        Y888b.   888  888 .d8888b  888888  .d88b.  88888b.d88b. \n");
    printf("   d88P  888 888 d88  88b d88P          88b 888P              Y88b. 888  888 88K      888    d8P  Y8b 888  888  88b\n");
    printf("  d88P   888 888 888  888 888      .d888888 888                 888 888  888  Y8888b. 888    88888888 888  888  888 \n");
    printf(" d8888888888 888 Y88..88P Y88b.    888  888 888          Y88b  d88P Y88b 888     X88  Y88b.  Y8b.     888  888  888 \n");
    printf("d88P     888 888   Y88P     Y8888P  Y888888 888           Y8888P     Y88888  88888P    Y888   Y88888  888  888  888\n");
    printf("                                                                        888     \n");
    printf("                                                                   Y8b d88P      \n");
    printf("                                                                     Y88P1     \n\n") ;     
    printf("* ===================================================================================================================== *");

        Sleep(250);
        printf("\n\nC A R R E G A N D O .");
        Sleep(250);
        printf("\n\nC A R R E G A N D O . .");
        Sleep(500);
        printf("\n\nC A R R E G A N D O . . .");

        Sleep(1000); // Tempo de espera do menu         

    system("cls"); 

}

void sair(){
  logo();
  armazenar_dados();

  free(clientes);
  free(carros);
  system("exit");

}

//          --->    O menu geral serve para chamar os outros menus onde as funções estarão definidas.
void menu_geral(){
  int escolha = 0;
  int x = 0;
  if (x == 0){
    system("cls");

    printf("  oo ooo oooo    ooooooooo8 oo oooooo   oooo  oooo\n");
    printf("    888 888 888  888oooooo8   888   888   888   888\n");
    printf("    888 888 888  888          888   888   888   888\n");
    printf("   o888o888o888o   88oooo888 o888o o888o   888o88 8o\n\n");
    
                 
    printf("* ========================================================== *\n");

    printf("\n| Seja bem vindo ao sistema de aluguel de carros : \n");
    printf("|\n| ---------- O que deseja fazer ? ----------\n");
    printf("| \n");
    printf("|       01 - Cadastrar cliente\n");
    printf("|       02 - Cadastrar um veiculo \n");
    printf("|       03 - Remover um veiculo \n");
    printf("|       04 - Alugar um veiculo \n");
    printf("|       05 - Devolver um veiculo \n");
    printf("|       06 - Verificar situacao do cliente \n");
    printf("|       07 - Verificar cadastros \n");
    printf("|       08 - Desenvolvedores\n");
    printf("|       09 - Sair ");

    printf("\n\n* ========================================================== *\n");

    printf("\n Digite um numero : ");
    scanf("%d", & escolha);
    if (!(escolha > 0 && escolha <10)) {
      Sleep(200);
      system("color c");
      printf("ERRO : Digite um numero valido ");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");
      Sleep(200);
      system("color c");
      Sleep(200);
      system("color 3");

      x += 1;
    }
  if (x == 1){
     menu_geral();
      }
    
    
  // Aninhando as escolhas :

  if (escolha == 1){
    menu_cadastro_cliente();
  }
  if (escolha == 2){     
    menu_cadastro_carro();
  }
  if (escolha == 3){
     menu_remove_carro();
  }
  if (escolha == 4){
    menu_alugar();
  }
  if(escolha == 5){
    menu_devolver();
  }
  if(escolha == 6){
    menu_verificar();
  }
  if(escolha == 7){
    menu_cadastros();
  }
  if(escolha == 8){
    desenvolvedores();
  }
  if(escolha == 9){
    sair();
  }
  }
}