#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<time.h>

/*
https://github.com/andremorales/registros
set project
function      status
Incluir       done
Buscar        done
Listar        not done
Alterar       done
Excluir       done
*/
struct registro {
  int cod;
  char nome[30];
  int tel;
  char sex[2];
  char jog[30];
  int vazio; //VAZIO = 0 e DISPONIVEL = 1.
} registros[100];


void cadastrar(int cod, int pos);
void consultar();
void alterar (int cod);
int verifica_pos();
void zerar();
int verifica_cod(int cod);
void excluir();
int pronome(char auxpronome[30]);
int verifica_tel(int tel);

main() {
  system("MODE con cols=139 lines=40");
  setlocale(LC_ALL,"Portuguese");
  zerar();
  srand(time(NULL));
  for (int abert=1;abert<5;abert++){
    system("color a");
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
    printf("8 888888888o.   8 8888888888       ,o888888o.    8 8888    d888888o. 8888888 8888888888 8 888888888o.      ,o888888o.       d888888o.    \n");
    printf("8 8888    `88.  8 8888            8888     `88.  8 8888  .`8888:' `88.     8 8888       8 8888    `88.  . 8888     `88.   .`8888:' `88.  \n");
    printf("8 8888     `88  8 8888         ,8 8888       `8. 8 8888  8.`8888.   Y8     8 8888       8 8888     `88 ,8 8888       `8b  8.`8888.   Y8  \n");
    printf("8 8888     ,88  8 8888         88 8888           8 8888  `8.`8888.         8 8888       8 8888     ,88 88 8888        `8b `8.`8888.      \n");
    printf("8 8888.   ,88'  8 888888888888 88 8888           8 8888   `8.`8888.        8 8888       8 8888.   ,88' 88 8888         88  `8.`8888.     \n");
    printf("8 888888888P'   8 8888         88 8888           8 8888    `8.`8888.       8 8888       8 888888888P'  88 8888         88   `8.`8888.    \n");
    printf("8 8888`8b       8 8888         88 8888   8888888 8 8888     `8.`8888.      8 8888       8 8888`8b      88 8888        ,8P    `8.`8888.   \n");
    printf("8 8888 `8b.     8 8888         `8 8888       .8' 8 8888 8b   `8.`8888.     8 8888       8 8888 `8b.    `8 8888       ,8P 8b   `8.`8888.  \n");
    printf("8 8888   `8b.   8 8888            8888     ,88'  8 8888 `8b.  ;8.`8888     8 8888       8 8888   `8b.   ` 8888     ,88'  `8b.  ;8.`8888  \n");
    printf("8 8888     `88. 8 888888888888     `8888888P'    8 8888  `Y8888P ,88P'     8 8888       8 8888     `88.    `8888888P'     `Y8888P ,88P'  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    system("cls");
    system("color 3");
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
    printf("8 888888888o.   8 8888888888       ,o888888o.    8 8888    d888888o. 8888888 8888888888 8 888888888o.      ,o888888o.       d888888o.    \n");
    printf("8 8888    `88.  8 8888            8888     `88.  8 8888  .`8888:' `88.     8 8888       8 8888    `88.  . 8888     `88.   .`8888:' `88.  \n");
    printf("8 8888     `88  8 8888         ,8 8888       `8. 8 8888  8.`8888.   Y8     8 8888       8 8888     `88 ,8 8888       `8b  8.`8888.   Y8  \n");
    printf("8 8888     ,88  8 8888         88 8888           8 8888  `8.`8888.         8 8888       8 8888     ,88 88 8888        `8b `8.`8888.      \n");
    printf("8 8888.   ,88'  8 888888888888 88 8888           8 8888   `8.`8888.        8 8888       8 8888.   ,88' 88 8888         88  `8.`8888.     \n");
    printf("8 888888888P'   8 8888         88 8888           8 8888    `8.`8888.       8 8888       8 888888888P'  88 8888         88   `8.`8888.    \n");
    printf("8 8888`8b       8 8888         88 8888   8888888 8 8888     `8.`8888.      8 8888       8 8888`8b      88 8888        ,8P    `8.`8888.   \n");
    printf("8 8888 `8b.     8 8888         `8 8888       .8' 8 8888 8b   `8.`8888.     8 8888       8 8888 `8b.    `8 8888       ,8P 8b   `8.`8888.  \n");
    printf("8 8888   `8b.   8 8888            8888     ,88'  8 8888 `8b.  ;8.`8888     8 8888       8 8888   `8b.   ` 8888     ,88'  `8b.  ;8.`8888  \n");
    printf("8 8888     `88. 8 888888888888     `8888888P'    8 8888  `Y8888P ,88P'     8 8888       8 8888     `88.    `8888888P'     `Y8888P ,88P'  \n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");

    system("cls");
  };
  int op=0,retorno,codaux=0,posicao,codauxalt=0;
  while(op!=5){
    system("color a");
    system("cls");
    printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # \n\n");
    printf("8 888888888o.   8 8888888888       ,o888888o.    8 8888    d888888o. 8888888 8888888888 8 888888888o.      ,o888888o.       d888888o.    \n");
    printf("8 8888    `88.  8 8888            8888     `88.  8 8888  .`8888:' `88.     8 8888       8 8888    `88.  . 8888     `88.   .`8888:' `88.  \n");
    printf("8 8888     `88  8 8888         ,8 8888       `8. 8 8888  8.`8888.   Y8     8 8888       8 8888     `88 ,8 8888       `8b  8.`8888.   Y8  \n");
    printf("8 8888     ,88  8 8888         88 8888           8 8888  `8.`8888.         8 8888       8 8888     ,88 88 8888        `8b `8.`8888.      \n");
    printf("8 8888.   ,88'  8 888888888888 88 8888           8 8888   `8.`8888.        8 8888       8 8888.   ,88' 88 8888         88  `8.`8888.     \n");
    printf("8 888888888P'   8 8888         88 8888           8 8888    `8.`8888.       8 8888       8 888888888P'  88 8888         88   `8.`8888.    \n");
    printf("8 8888`8b       8 8888         88 8888   8888888 8 8888     `8.`8888.      8 8888       8 8888`8b      88 8888        ,8P    `8.`8888.   \n");
    printf("8 8888 `8b.     8 8888         `8 8888       .8' 8 8888 8b   `8.`8888.     8 8888       8 8888 `8b.    `8 8888       ,8P 8b   `8.`8888.  \n");
    printf("8 8888   `8b.   8 8888            8888     ,88'  8 8888 `8b.  ;8.`8888     8 8888       8 8888   `8b.   ` 8888     ,88'  `8b.  ;8.`8888  \n");
    printf("8 8888     `88. 8 888888888888     `8888888P'    8 8888  `Y8888P ,88P'     8 8888       8 8888     `88.    `8888888P'     `Y8888P ,88P'  \n\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: ::::   BY: ANDRE MORALES      : ::: :::\n");
    printf(":+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+:   :+:+: :+: :::                        :+:+: :+:  \n");
    printf("  :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::::   ::: :::\n");
    printf("\n\n\nMENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Alterar\n5 - Sair\n\nOpcao:  ");
    scanf("%d",&op);
    fflush(stdin);
    system("color 7");
    switch(op) {
      case 1: {                  // CADASTRAR
        system("cls");
        system("color a");
        printf("\n\n");
        printf("         ::::::::      :::     :::::::::      :::      :::::::: ::::::::::: :::::::::   :::::::: \n");
        printf("        :+:    :+:   :+: :+:   :+:    :+:   :+: :+:   :+:    :+:    :+:     :+:    :+: :+:    :+: \n");
        printf("        +:+         +:+   +:+  +:+    +:+  +:+   +:+  +:+           +:+     +:+    +:+ +:+    +:+ \n");
        printf("        +#+        +#++:++#++: +#+    +:+ +#++:++#++: +#++:++#++    +#+     +#++:++#:  +#+    +:+ \n");
        printf("        +#+        +#+     +#+ +#+    +#+ +#+     +#+        +#+    +#+     +#+    +#+ +#+    +#+ \n");
        printf("        #+#    #+# #+#     #+# #+#    #+# #+#     #+# #+#    #+#    #+#     #+#    #+# #+#    #+# \n");
        printf("         ########  ###     ### #########  ###     ###  ########     ###     ###    ###  ########  \n");


        posicao=verifica_pos();
        if (posicao!=-1) {
          //printf("\nEntre com o codigo desejado\n");
          codaux=(codaux+1);
          printf("Codigo %d\n\n",codaux);
          //scanf("%d",&codaux);fflush(stdin);

          retorno=verifica_cod(codaux);
          if (retorno==1)
          cadastrar(codaux,posicao);
          else
          printf("\nCodigo ja existente\n");
        }
        else {
          printf("\nResgistros cheios\n");
        }
        break;
      }
      case 2: {                  // CONSULTAR
        system("cls");
        printf("\n\n");
        system("color a");
        printf(" ::::::::   ::::::::  ::::    :::  ::::::::  :::    ::: :::    ::::::::::: :::     \n");
        printf(":+:    :+: :+:    :+: :+:+:   :+: :+:    :+: :+:    :+: :+:        :+:   :+: :+:   \n");
        printf("+:+        +:+    +:+ :+:+:+  +:+ +:+        +:+    +:+ +:+        +:+  +:+   +:+  \n");
        printf("+#+        +#+    +:+ +#+ +:+ +#+ +#++:++#++ +#+    +:+ +#+        +#+ +#++:++#++: \n");
        printf("+#+        +#+    +#+ +#+  +#+#+#        +#+ +#+    +#+ +#+        +#+ +#+     +#+ \n");
        printf("#+#    #+# #+#    #+# #+#   #+#+# #+#    #+# #+#    #+# #+#        #+# #+#     #+# \n");
        printf(" ########   ########  ###    ####  ########   ########  ########## ### ###     ### \n");
        consultar();
        break;
      }
      case 3: {
        system("cls");
        printf("\n\n");
        system("color a");
        printf(" ::::::::: :::    :::  ::::::::  :::       :::    ::: ::::::::::: :::::::::  \n");
        printf(":+:        :+:    :+: :+:    :+: :+:       :+:    :+:     :+:     :+:    :+: \n");
        printf("+:+         +:+  +:+  +:+        +:+       +:+    +:+     +:+     +:+    +:+ \n");
        printf("+#++:++#     +#++:+   +#+        +#+       +#+    +:+     +#+     +#++:++#:  \n");
        printf("+#+         +#+  +#+  +#+        +#+       +#+    +#+     +#+     +#+    +#+ \n");
        printf("#+#        #+#    #+# #+#    #+# #+#       #+#    #+#     #+#     #+#    #+# \n");
        printf("########## ###    ###  ########  ########## ########  ########### ###    ### \n");
        excluir();
        break;
      }
      case 4: {
        system("cls");
        system("color a");
        printf("\n\n");
        printf("    :::     :::    ::::::::::: :::::::::: :::::::::      :::     :::::::::  \n");
        printf("  :+: :+:   :+:        :+:     :+:        :+:    :+:   :+: :+:   :+:    :+: \n");
        printf(" +:+   +:+  +:+        +:+     +:+        +:+    +:+  +:+   +:+  +:+    +:+ \n");
        printf("+#++:++#++: +#+        +#+     +#++:++#   +#++:++#:  +#++:++#++: +#++:++#:  \n");
        printf("+#+     +#+ +#+        +#+     +#+        +#+    +#+ +#+     +#+ +#+    +#+ \n");
        printf("#+#     #+# #+#        #+#     #+#        #+#    #+# #+#     #+# #+#    #+# \n");
        printf("###     ### ########## ###     ########## ###    ### ###     ### ###    ### \n");
        printf("\nEntre com o codigo desejado\n");
        fflush(stdin);
        //printf("Codigo %d\n\n",codauxalt);
        scanf("%d",&codauxalt);fflush(stdin);
        if (registros[codauxalt].vazio==1) {
          alterar(codauxalt);
        }
        else {
          printf("\n Codigo nao encontrado \n");
          printf("\n\n");
          system("pause");
        }
        break;
      }
      case 5: {
        system("cls");
        system("color a");
        printf("\n\n");
        printf("::::::::::: ::::::::  :::    :::     :::     :::    :::      :::      :::      :::\n");
        printf("    :+:    :+:    :+: :+:    :+:   :+: :+:   :+:    :+:      :+:      :+:      :+:\n");
        printf("    +:+    +:+        +:+    +:+  +:+   +:+  +:+    +:+      +:+      +:+      +:+\n");
        printf("    +#+    +#+        +#++:++#++ +#++:++#++: +#+    +:+      +#+      +#+      +#+\n");
        printf("    +#+    +#+        +#+    +#+ +#+     +#+ +#+    +#+      +#+      +#+      +#+\n");
        printf("    #+#    #+#    #+# #+#    #+# #+#     #+# #+#    #+#                           \n");
        printf("    ###     ########  ###    ### ###     ###  ########       ###      ###      ###\n");
        break;
      }

    }
  }
  getch();
}
//---------------------------------------------------------------------------------------------------------------
// cadastrar
void cadastrar (int cod, int pos) {
  int aux=0,auxcont=999,cond,auxtel;
  char auxnome [30];
  fflush(stdin);
  pos=verifica_pos();
  registros[pos].cod=cod;
  fflush(stdin);
  do {
    printf("\nNome:\n");
    gets(auxnome);
    fflush(stdin);
    auxcont=pronome(auxnome);
    if (auxcont !=999 ) {
      printf("\nNome ja existente !\n");
      aux=1;
    }
    else{
      aux=0;
      strcpy(registros[pos].nome,auxnome);
    }
  } while(aux!=0);
  do{
    printf("\nTelefone\n");
    scanf("%d",&auxtel);
    fflush(stdin);
    cond=verifica_tel(auxtel);
    if (cond!=999){
      printf("\nTelefone ja existente !\n");
    }
    else{
      registros[pos].tel=auxtel;
    }
  }while (cond!=999);
  printf("\nSexo (M ou F):\n");
  gets(registros[pos].sex);
  fflush(stdin);
  printf("\nJogo preferido:\n");
  gets(registros[pos].jog);
  fflush(stdin);
  registros[pos].vazio=1;
  printf("\nCadastro Realizado com Sucesso!\n\n");
  printf("\n\n");
  system("pause");
}
//---------------------------------------------------------------------------------------------------------------
// alterar
void alterar (int pos) {
  int aux=0,auxcont=999,cond,auxtel;
  char auxnome [30];
  fflush(stdin);
  do {
    printf("\nNome:\n");
    gets(auxnome);
    fflush(stdin);
    auxcont=pronome(auxnome);
    if (auxcont !=999 ) {
      printf("\nNome ja existente !\n");
      aux=1;
    }
    else{
      aux=0;
      strcpy(registros[pos].nome,auxnome);
    }
  } while(aux!=0);
  do{
    printf("\nTelefone\n");
    scanf("%d",&auxtel);
    fflush(stdin);
    cond=verifica_tel(auxtel);
    if (cond!=999){
      printf("\nTelefone ja existente !\n");
    }
    else{
      registros[pos].tel=auxtel;
    }
  }while (cond!=999);
  printf("\nSexo (M ou F):\n");
  gets(registros[pos].sex);
  fflush(stdin);
  printf("\nJogo preferido:\n");
  gets(registros[pos].jog);
  fflush(stdin);
  registros[pos].vazio=1;
  printf("\nAlteracao realizada com Sucesso!\n\n");
  printf("chego" );
  printf("\n\n");
  system("pause");
}
//----------------------------------------------------------------------------------------------------------------
//consultar
void consultar() {
  int op,tel,auxtel,auxnome;
  char nome [30];
  printf("\n\n\n1 - Por Telefone\n2 - Por Nome\n\nOpcao:  ");
  scanf("%d",&op);
  switch(op){
    case 1:{
      printf("\n Numero desejado\n");
      scanf("%d",&tel);
      auxtel=verifica_tel(tel);

      if (auxtel!=999){
        printf("\nCodigo : %d\n",registros[auxtel].cod);
        printf("\nNome : %s\n",registros[auxtel].nome);
        printf("\nTelefone : %d\n",registros[auxtel].tel);
        printf("\nSexo : %s\n",registros[auxtel].sex);
        printf("\nJogo preferido : %s\n",registros[auxtel].jog);
      }
      else{
        printf("\n Telefone não encotrado !\n");
      }
      break;
    }
    case 2:{
      printf("\n Nome desejado\n");
      fflush(stdin);
      gets(nome);
      auxnome=pronome(nome);
      if (auxnome!=999){
        printf("\nCodigo : %d\n",registros[auxnome].cod);
        printf("\nNome : %s\n",registros[auxnome].nome);
        printf("\nTelefone : %d\n",registros[auxnome].tel);
        printf("\nSexo : %s\n",registros[auxnome].sex);
        printf("\nJogo preferido : %s\n",registros[auxnome].jog);
      }
      else{
        printf("\n Nome não encotrado !\n");
      }
      break;
    }
  }
  printf("\n\n");
  system("pause");
}
//--------------------------------------------------------------------------------------------------------------------------
// verifica_pos
int verifica_pos() {
  int cont=0;
  while (cont<=100) {
    if (registros[cont].vazio==0)
    return(cont);
    cont++;
  }
  return(-1);
}
//--------------------------------------------------------------------------------------------------------------------------
// zerar
void zerar() {
  int cont;
  for (cont=0;cont<=100;cont++)
  registros[cont].vazio=0;
}
//--------------------------------------------------------------------------------------------------------------------------
// verifica_cod
int verifica_cod(int cod) {
  int cont=0;
  while (cont<=100) {
    if (registros[cont].cod==cod)
    return(0);
    cont++;
  }
  return(1);
}
//--------------------------------------------------------------------------------------------------------------------------
// verifica_tel
int verifica_tel(int tel) {
  int cont=0,resu=999;
  for (cont=0;cont<=100;cont++){
    if (registros[cont].tel==tel){
      resu=cont;
    }
  }
  return(resu);
}

//--------------------------------------------------------------------------------------------------------------------------
// Procura nome
int pronome(char auxpronome[30]){

  int cont,aux=999,auxcont;

  for(cont=0; cont<=100;cont++){
    auxcont=strcmp(registros[cont].nome,auxpronome);
    if (auxcont==0) {
      aux=cont;
    }
  }
  return(aux);
}

//--------------------------------------------------------------------------------------------------------------------------
// excluir
void excluir() {
  char auxnome[30];
  int cod,aux,tel,cont=0,op=0;
  printf("\nEscolha metodo de Exclusao\n\n1 - Por codigo\n2 - Por telefone \n3 - Por nome\n\nopcao: ");
  fflush(stdin);
  scanf("%d",&op);
  if (op==1) {
    printf("\nEntre com o codigo do registro que deseja excluir\n");
    scanf("%d",&cod);
    while (cont<=100) {
      if (registros[cont].cod==cod)
      if (registros[cont].vazio==1) {
        registros[cont].vazio=0;
        printf("\nExclusao feita com sucesso\n");
        break;
      }
      cont++;
      if (cont>100)
      printf("\nCodigo nao encontrado\n");
    }
  }

  if (op==2) {
    printf("\nEntre com o telefone do registro que deseja excluir\n");
    scanf("%d",&tel);
    while (cont<=100) {
      if (registros[cont].tel==tel)
      if (registros[cont].vazio==1) {
        registros[cont].vazio=0;
        printf("\nExclusao feita com sucesso\n");
        break;
      }
      cont++;
      if (cont>100)
      printf("\nTelefone nao encontrado\n");
    }
  }
  if (op==3) {
    printf("\nEntre com o nome do registro que deseja excluir\n\n");
    fflush(stdin);
    gets(auxnome);
    aux=pronome(auxnome);
    if(aux!=999){
      registros[aux].vazio=0;
      printf("\nExclusao feita com sucesso\n");
    }
    else{
      printf("\nNome nao encontrado\n");
    }
  }
  printf("\n\n");
  system("pause");
}
