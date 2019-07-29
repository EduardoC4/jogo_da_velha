#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Gerar numeros aleatorios

int main(){
   char c;
 do{
            int i, j, k, L, M = 1, N = 1, posicao1, posicao2, tabuleiroGuia[3][3], ligado = 1,x,y;
            char tabuleiroNovo[3][3];
            for(i=0;i<3;i++){
                for(j=1;j<4;j++){
                    tabuleiroGuia[i][j-1] = j + 3*i;
                }
            }
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    tabuleiroNovo[i][j] = '.';
                }
            }
            srand(time(0)); //Gerador de numeros aleatorios
        while(ligado >=1 && ligado <=5){ // Loop infinito. O codigo do jogo deve ser implementado dentro desta estrutura de repetição.
                  // Vocês podem modificar a condição do while para especificar uma condi��o de parada.

                    printf("Jogador Atual: X\n");
                    printf("Posicoes:                             "); printf("Estado Atual do Jogo:     \n");

                    for(i=0;i<3;i++){ //Loop para imprimir o tabuleiro guia.
                        printf("   %d|%d|%d", tabuleiroGuia[i][0],tabuleiroGuia[i][1],tabuleiroGuia[i][2]);
                        printf("                                      %c|%c|%c", tabuleiroNovo[i][0],tabuleiroNovo[i][1],tabuleiroNovo[i][2]);
                        printf("\n");}
                    while ( M == 1){ //Repetição para posição "X".
                            printf("Escolha onde deseja Marcar: ");
                            scanf("%d",&posicao1); // Le algo do usu�rio e descarta o valor.


                            if(posicao1 == 5 && tabuleiroNovo[1][1] == '.'){
                                            tabuleiroNovo[1][1] = 'X';
                                            M = 0;
                            }
                            for (L=1;L<4;L++){
                                if (posicao1 == L && tabuleiroNovo[0][L-1] == '.'){
                                            tabuleiroNovo[0][L-1] = 'X';
                                            M = 0;
                                    }
                            }
                            for (L=4;L<7;L++){
                                if (posicao1 == L && tabuleiroNovo[1][L-4] == '.'){
                                            tabuleiroNovo[1][L-4] = 'X';
                                            M = 0;
                                    }
                            }
                            for (L=7;L<10;L++){
                                if (posicao1 == L && tabuleiroNovo[2][L-7] == '.'){
                                            tabuleiroNovo[2][L-7] = 'X';
                                            M = 0;
                                    }
                            }
                            if(M == 1) printf("\nErro! Entre com outro valor...\n");
                        }
            printf("----------------------------------------------------------\n");
                //Início da condição para repetição do while corpo:
                for(i=0;i<3;i++){
                    if (tabuleiroNovo[i][0] == 'X' && tabuleiroNovo[i][1] == 'X' && tabuleiroNovo[i][2] == 'X'){
                            N = 3;
                    }
                    if (tabuleiroNovo[0][i] == 'X' && tabuleiroNovo[1][i] == 'X' && tabuleiroNovo[2][i] == 'X'){
                            N = 3;
                    }
                    if (tabuleiroNovo[0][0] == 'X' && tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[2][2] == 'X'){
                            N = 3;
                    }
                    if (tabuleiroNovo[2][0] == 'X' && tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[0][2] == 'X'){
                            N = 3;
                    }
                }
                if (ligado == 5 && N != 3){ //Condição para um jogo empatado
                    N = 5;
                }//Fim da condição

                    while (N == 1){ // Repetição para posição "O".
                        if (ligado == 1){
                                                if (tabuleiroNovo[1][1] == '.' ){
                                                        tabuleiroNovo[1][1] = 'O';
                                                        N = 0;
                                                }
                                if (tabuleiroNovo[1][1] == 'X'){
                                        while (N == 1){
                                                    x = rand() % 3;
                                                    y = rand() % 3;
                                                if (x == 0) y = 2;
                                                if (x == 2) y = 0;
                                                if (y == 1) {x = 2; y = 0;}
                                                if (x == 1) {x = 0; y = 0;}
                                                if(tabuleiroNovo[x][y] == '.'){
                                                    tabuleiroNovo[x][y] = 'O';
                                                    N = 0;
                                                }else N = 1;
                                            }
                                }
                        }
                        if (ligado == 2){
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[0][i] == 'X' && tabuleiroNovo[1][i] == 'X' && tabuleiroNovo[2][i] == '.'){
                                            tabuleiroNovo[2][i] = 'O';
                                            N = 0;
                                    }
                                }
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[0][i] == 'X' && tabuleiroNovo[2][i] == 'X' && tabuleiroNovo[1][i] == '.'){
                                            tabuleiroNovo[1][i] = 'O';
                                            N = 0;
                                    }
                                }
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[1][i] == 'X' && tabuleiroNovo[2][i] == 'X' && tabuleiroNovo[0][i] == '.'){
                                            tabuleiroNovo[0][i] = 'O';
                                            N = 0;
                                    }
                                }
                                //Fim das verticais
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[i][0] == 'X' && tabuleiroNovo[i][1] == 'X' && tabuleiroNovo[i][2] == '.'){
                                            tabuleiroNovo[i][2] = 'O';
                                            N = 0;
                                    }
                                }
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[i][0] == 'X' && tabuleiroNovo[i][2] == 'X' && tabuleiroNovo[i][1] == '.'){
                                            tabuleiroNovo[i][1] = 'O';
                                            N = 0;
                                    }
                                }
                                for (i=0;i<3;i++){
                                    if (tabuleiroNovo[i][1] == 'X' && tabuleiroNovo[i][2] == 'X' && tabuleiroNovo[i][0] == '.'){
                                            tabuleiroNovo[i][0] = 'O';
                                            N = 0;
                                    }
                                }
                                //Fim das horizontais
                                if(tabuleiroNovo[1][1] == 'X'){
                                    if(tabuleiroNovo[2][2] == 'X' && tabuleiroNovo[0][0] == '.'){
                                            tabuleiroNovo[0][0] = 'O';
                                            N = 0;
                                    }
                                    if(tabuleiroNovo[0][0] == 'X' && tabuleiroNovo[2][2] == '.'){
                                            tabuleiroNovo[2][2] = 'O';
                                            N = 0;
                                    }
                                    if(tabuleiroNovo[0][2] == 'X' && tabuleiroNovo[2][0] == '.'){
                                            tabuleiroNovo[2][0] = 'O';
                                            N = 0;
                                    }
                                    if(tabuleiroNovo[2][0] == 'X' && tabuleiroNovo[0][2] == '.'){
                                            tabuleiroNovo[0][2] = 'O';
                                            N = 0;
                                    }
                                }

                                if (N == 1 && tabuleiroNovo[1][1] == 'O'){
                                        if (tabuleiroNovo[0][0] == 'X' || tabuleiroNovo[0][2] == 'X' || tabuleiroNovo[2][0] == 'X' || tabuleiroNovo[2][2] == 'X'){
                                            while (N == 1){
                                                        x = rand() % 3;
                                                        y = rand() % 3;
                                                if (x == 0) y = 1;
                                                if (x == 2) y = 1;
                                                if (y == 0) x = 1;
                                                if (y == 2) x = 1;
                                                if(tabuleiroNovo[x][y] == '.'){
                                                    tabuleiroNovo[x][y] = 'O';
                                                    N = 0;
                                                }
                                            }
                                        }
                                        if (tabuleiroNovo[0][1] == 'X' || tabuleiroNovo[1][0] == 'X' || tabuleiroNovo[2][1] == 'X' || tabuleiroNovo[1][2] == 'X'){
                                                if (tabuleiroNovo[0][1] == 'X' && tabuleiroNovo[1][0] == 'X'){
                                                    tabuleiroNovo[0][0] = 'O';
                                                    N = 0;
                                                }
                                                while (N == 1){
                                                        x = rand() % 3;
                                                        y = rand() % 3;
                                                if (x == 0) y = 2;
                                                if (y == 0) x = 0;
                                                if (x == 1) {x = 2; y = 0;}
                                                if (y == 2) {x = 2; y = 0;}
                                                if (x == 2) {y = 0;}
                                                if (y == 0) {x = 2; y = 2;}
                                                if(tabuleiroNovo[x][y] == '.'){
                                                    tabuleiroNovo[x][y] = 'O';
                                                    N = 0;
                                                }else N =1;
                                            }
                                        }
                                    }
                                if (N == 1 && tabuleiroNovo[1][1] == 'X'){
                                        if (tabuleiroNovo[0][0] == 'O' && tabuleiroNovo[2][2] == 'X'){
                                            tabuleiroNovo[2][0] = 'O';
                                            N = 0;
                                            break;
                                        }
                                        if (tabuleiroNovo[0][2] == 'O' && tabuleiroNovo[2][0] == 'X'){
                                            tabuleiroNovo[2][2] = 'O';
                                            N = 0;
                                            break;
                                        }
                                        if (tabuleiroNovo[0][2] == 'O' && tabuleiroNovo[0][2] == 'X'){
                                            tabuleiroNovo[0][0] = 'O';
                                            N = 0;
                                            break;
                                        }
                                        if (tabuleiroNovo[2][2] == 'O' && tabuleiroNovo[0][0] == 'X'){
                                            tabuleiroNovo[0][2] = 'O';
                                            N = 0;
                                            break;
                                        }
                                        if (tabuleiroNovo[2][0] == 'O' && tabuleiroNovo[0][2] == 'X'){
                                            tabuleiroNovo[0][0] = 'O';
                                            N = 0;
                                            break;
                                        }
                                                if (tabuleiroNovo[0][1] == 'O') {tabuleiroNovo[0][2] = 'O'; N = 0;}
                                                if (tabuleiroNovo[1][2] == 'O') {tabuleiroNovo[2][2] = 'O'; N = 0;}
                                                if (tabuleiroNovo[2][1] == 'O') {tabuleiroNovo[2][0] = 'O'; N = 0;}
                                                if (tabuleiroNovo[1][0] == 'O') {tabuleiroNovo[0][0] = 'O'; N = 0;}
                                    }
                                }
                            if (ligado == 3 ||ligado == 4 || ligado ==5){
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][0] == 'O' && tabuleiroNovo[i][1] == 'O' && tabuleiroNovo[i][2] == '.' && N == 1){
                                                                                tabuleiroNovo[i][2] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][0] == 'O' && tabuleiroNovo[i][2] == 'O' && tabuleiroNovo[i][1] == '.' && N == 1){
                                                                                tabuleiroNovo[i][1] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][1] == 'O' && tabuleiroNovo[i][2] == 'O' && tabuleiroNovo[i][0] == '.' && N == 1){
                                                                                tabuleiroNovo[i][0] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                //condição pa a IA HORIZONTAL
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[0][i] == 'O' && tabuleiroNovo[1][i] == 'O' && tabuleiroNovo[2][i] == '.' && N == 1){
                                                                                tabuleiroNovo[2][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[0][i] == 'O' && tabuleiroNovo[2][i] == 'O' && tabuleiroNovo[1][i] == '.' && N == 1){
                                                                                tabuleiroNovo[1][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[1][i] == 'O' && tabuleiroNovo[2][i] == 'O' && tabuleiroNovo[0][i] == '.' && N == 1){
                                                                                tabuleiroNovo[0][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                //condição p/ a IA VERTICAL
                                                if(tabuleiroNovo[0][0] == 'O' && tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[2][2] == '.' && N == 1){
                                                                                tabuleiroNovo[2][2] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[0][0] == 'O' && tabuleiroNovo[2][2] == 'O' && tabuleiroNovo[1][1] == '.' && N == 1){
                                                                                tabuleiroNovo[1][1] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[2][2] == 'O' && tabuleiroNovo[0][0] == '.' && N == 1){
                                                                                tabuleiroNovo[0][0] = 'O';
                                                                                N = 0;
                                                }//condiçao p/ IA diagonal(1)
                                                if(tabuleiroNovo[0][2] == 'O' && tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[2][0] == '.' && N == 1){
                                                                                tabuleiroNovo[2][0] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[0][2] == 'O' && tabuleiroNovo[2][0] == 'O' && tabuleiroNovo[1][1] == '.' && N == 1){
                                                                                tabuleiroNovo[1][1] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[2][0] == 'O' && tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[0][2] == '.' && N == 1){
                                                                                tabuleiroNovo[0][2] = 'O';
                                                                                N = 0;
                                                }

                                        if (N == 1){
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][0] == 'X' && tabuleiroNovo[i][1] == 'X' && tabuleiroNovo[i][2] == '.' && N == 1){
                                                                                tabuleiroNovo[i][2] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][0] == 'X' && tabuleiroNovo[i][2] == 'X' && tabuleiroNovo[i][1] == '.' && N == 1){
                                                                                tabuleiroNovo[i][1] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[i][1] == 'X' && tabuleiroNovo[i][2] == 'X' && tabuleiroNovo[i][0] == '.' && N == 1){
                                                                                tabuleiroNovo[i][0] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                //condição pa a IA HORIZONTAL
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[0][i] == 'X' && tabuleiroNovo[1][i] == 'X' && tabuleiroNovo[2][i] == '.' && N == 1){
                                                                                tabuleiroNovo[2][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[0][i] == 'X' && tabuleiroNovo[2][i] == 'X' && tabuleiroNovo[1][i] == '.' && N == 1){
                                                                                tabuleiroNovo[1][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                for(i=0;i<3;i++){
                                                            if (tabuleiroNovo[1][i] == 'X' && tabuleiroNovo[2][i] == 'X' && tabuleiroNovo[0][i] == '.' && N == 1){
                                                                                tabuleiroNovo[0][i] = 'O';
                                                                                N = 0;
                                                            }
                                                }
                                                //condição p/ a IA VERTICAL
                                                if(tabuleiroNovo[0][0] == 'X' && tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[2][2] == '.' && N == 1){
                                                                                tabuleiroNovo[2][2] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[0][0] == 'X' && tabuleiroNovo[2][2] == 'X' && tabuleiroNovo[1][1] == '.' && N == 1){
                                                                                tabuleiroNovo[1][1] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[2][2] == 'X' && tabuleiroNovo[0][0] == '.' && N == 1){
                                                                                tabuleiroNovo[0][0] = 'O';
                                                                                N = 0;
                                                }//condiçao p/ IA diagonal(1)

                                                if(tabuleiroNovo[0][2] == 'X' && tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[2][0] == '.' && N == 1){
                                                                                tabuleiroNovo[2][0] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[0][2] == 'X' && tabuleiroNovo[2][0] == 'X' && tabuleiroNovo[1][1] == '.' && N == 1){
                                                                                tabuleiroNovo[1][1] = 'O';
                                                                                N = 0;
                                                }
                                                if(tabuleiroNovo[2][0] == 'X' && tabuleiroNovo[1][1] == 'X' && tabuleiroNovo[0][2] == '.' && N == 1){
                                                                                tabuleiroNovo[0][2] = 'O';
                                                                                N = 0;
                                                }
                                        }

                                   if (N == 1) {
                                            while(N == 1){
                                                    x = rand() % 3;
                                                    y = rand() % 3;
                                                if(tabuleiroNovo[x][y] == '.'){
                                                        tabuleiroNovo[x][y] = 'O';
                                                        N = 0;
                                                    }else N = 1;
                                            }
                                        }
                            }// Fim do if(ligado == 3 ||ligado == 4 || ligado ==5)
                }//Fim do While
               //Início da condição para repetição do while corpo:
                for(i=0;i<3;i++){
                    if (tabuleiroNovo[i][0] == 'O' && tabuleiroNovo[i][1] == 'O' && tabuleiroNovo[i][2] == 'O'){
                            N = 4;
                    }
                    if (tabuleiroNovo[0][i] == 'O' && tabuleiroNovo[1][i] == 'O' && tabuleiroNovo[2][i] == 'O'){
                            N = 4;
                    }
                    if (tabuleiroNovo[0][0] == 'O' && tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[2][2] == 'O'){
                            N = 4;
                    }
                    if (tabuleiroNovo[2][0] == 'O' && tabuleiroNovo[1][1] == 'O' && tabuleiroNovo[0][2] == 'O'){
                            N = 4;
                    }
                }
                ligado = ligado + 1;
                //Início da condição para repetição do while corpo
                    if (N == 3){
                            printf("O jogador X VENCEU!!!\n");
                            ligado = 0;

                            for(i=0;i<3;i++){ //Loop para imprimir o tabuleiro guia.
                        printf("   %d|%d|%d", tabuleiroGuia[i][0],tabuleiroGuia[i][1],tabuleiroGuia[i][2]);
                        printf("                                      %c|%c|%c", tabuleiroNovo[i][0],tabuleiroNovo[i][1],tabuleiroNovo[i][2]);
                        printf("\n");}
                    }
                    if (N == 4){
                            printf(" Voce Perdeu OTARIO!!!\n");
                            ligado = 0;

                            for(i=0;i<3;i++){ //Loop para imprimir o tabuleiro guia.
                        printf("   %d|%d|%d", tabuleiroGuia[i][0],tabuleiroGuia[i][1],tabuleiroGuia[i][2]);
                        printf("                                      %c|%c|%c", tabuleiroNovo[i][0],tabuleiroNovo[i][1],tabuleiroNovo[i][2]);
                        printf("\n");}
                    }
                    if (N == 5){
                        printf("Jogo Empatado!!!\n");
                        ligado = 0;

                            for(i=0;i<3;i++){ //Loop para imprimir o tabuleiro guia.
                        printf("   %d|%d|%d", tabuleiroGuia[i][0],tabuleiroGuia[i][1],tabuleiroGuia[i][2]);
                        printf("                                      %c|%c|%c", tabuleiroNovo[i][0],tabuleiroNovo[i][1],tabuleiroNovo[i][2]);
                        printf("\n");}
                    }
                //Fim da condição
            M = 1;
            N = 1;
        }
        printf("\n\nDeseja jogar novamente pobre mortal(S/N)?: ");
        scanf("%s", &c);
        printf("\n\n");
        } while (c == 'S' || c == 's');
}
