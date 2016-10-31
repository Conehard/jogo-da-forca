#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void topoJogo();

int main(){
	char palavra[20], letraoculta[20]="", letra[20], erros[20], nomep1[12], nomep2[12];
	int tamanho, pontos=0, retorno, contador, contador2=0, vidas;
	// Definir idioma do software.
	setlocale(LC_ALL, "Portuguese");
	topoJogo(); // Apenas exibe a função topo.
	//Salvar nome dos jogadores.
	printf("Player 1, digite o seu nome: ");
	gets(nomep1);
	printf("Player 2, digite o seu nome: ");
	gets(nomep2);
	system("cls");
	topoJogo();// Apenas exibe a função topo.
	// Salvar a palavra a ser advinhada.
	printf("%s, digite a palavra para %s advinhar: ",nomep1, nomep2);
	gets(palavra);
	system("cls");
	
    topoJogo();
    for(contador = 0; contador<strlen(palavra);contador++){
        tamanho=strlen(palavra);
		vidas = tamanho;
		while (vidas>0){
			retorno = 0;
			printf("\nPalavra sendo descoberta: %s\n",letraoculta);
			printf("Digite uma letra: ");
			gets(letra);
			if(vidas<5){
				printf("Letras digitadas %s\n", erros);
			}
			// For para verificar se a letra está correta ou não.
			for(contador = 0; contador<strlen(palavra);contador++){
				if (letra[0]==palavra[contador]){
                    letraoculta[contador] = palavra[contador];
                    retorno++;
				}
			}
			// Mensagens de erro.
			if(retorno==0){
				vidas--;
				if(vidas == 0){
					printf("\nQue pena, você perdeu.\n");
					printf("A palavra correta era: %s\n",palavra);
					system("pause");
				}else{
					printf("Você errou uma letra. Restam apenas %d vidas.\n", vidas);
					erros[contador2]=letra[0];
					contador2++;
					system("pause");
					system("cls");
					topoJogo(); // Apenas exibe a função topo.
				}
			// Mensagens de acerto.
			}else{
				if(pontos==tamanho){
					printf("Você acertou a palavra, parabéns %s\n",nomep2);
                    system("pause");
                    vidas=0;
				}else{
                    printf("Você acertou uma letra, Parabéns...\n");
                    pontos++;
                    system("pause");
                    system("cls");
					topoJogo(); // Apenas exibe a função topo.
				}
			}
		}
 	}
	return 0;
}

void topoJogo(){
    printf("-------------------------------------------------------\n");
	printf("------------ Jogo da Forca com 2 jogadores ------------\n");
	printf("- Quando você souber a palavra, digite-a por completo -\n");
	printf("-------------------------------------------------------\n\n");
}
