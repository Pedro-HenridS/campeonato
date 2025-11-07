#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void _Menu_Principal(){
char escolha;

while (escolha != 'Q'){
printf("Escolha uma opção\n");
printf("1 - Consultar Time\n");
printf("2 - Consultar Partida\n");
printf("3 - Atualizar Partida\n");
printf("4 - Remover Partida\n");
printf("5 - Atualizar Partida\n");
printf("6 - Imprimir tabela de classificação\n");
printf("Q - Sair \n");
scanf(" %c", &escolha);

switch(escolha){
    case '1': 
    break;
    case '2': 
    break;
    case '6': 
    break;
    case 'Q': printf("Tchauzin");
    break;
}
}
}

int main(int argc, char const *argv[])
{
    _Menu_Principal();
<<<<<<< HEAD

=======
    
>>>>>>> fea7b606187cf2698016de449e27532666be2eba
    return 0;
    
}
