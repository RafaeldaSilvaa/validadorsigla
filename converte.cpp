#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int eLetra(char x)
{
	if ((x>='A')&&(x<='Z'))
	   return(1);
	else
	   return(0);
}

int eNumero(char x)
{
	if ((x>='0')&&(x<='9'))
	   return(1);
	else
	   return(0);
}



int eVazio (char x)
{
if (x==' ')
   return(1);
else
   return(0);
}


int main()
{
	FILE *fpe, *fps;
	
	char entrada[200];
	char saida[200];
	
	char linha[256];
	int c;
	
	
	/*
	printf("Digite o nome do arquivo de entrada: ");
	gets(entrada);
	printf("Digite o nome do arquivo de saida: ");
	gets(saida);
*/


	if ((fpe=fopen("entrada.txt", "rt"))==NULL)
	{
		printf("Erro ao abrir arquivo %s\n", entrada);
		getch();
		exit(0);
	}
	
	if ((fps=fopen("saida.txt", "wt"))==NULL)
	{
		printf("Erro ao abrir arquivo %s\n", saida);
		getch();
		exit(0);
	}
	
	
	while (fgets(linha, 255, fpe)!=NULL)
	{
		if (eLetra(linha[0])&&
		   ((eNumero(linha[1]))|| (eLetra(linha[1]))) &&
		   ((eNumero(linha[2]))||(eVazio(linha[2]))))
		   {
				fprintf(fps, "%s", linha);
		  }
	}
	
	fclose(fpe);
	fclose(fps);

	printf("Validacao executada...\n");
	getch();

//	return(0);
}
