#include <stdio.h>
#include <stdlib.h>

// exemplo le um vetor de inteiros de arquivo

typedef struct coordenadas
	{
		int x;
		int y;
	}COORDENADAS;

void GuardaArquivos(struct coordenadas Vetor[], int TamanhoVetor){
   FILE *fp;
 	int  i;

	fp = fopen("arquivo.txt","w");   /* Arquivo ASCII, para escrita */
	 if(!fp)
	 {
	    printf( "Erro na abertura do arquivo");
	    exit(0);
	 }

	//Grava o tamanho do Vetor 
	fprintf(fp, "%d\n", TamanhoVetor);
 	
 	for(i=0; TamanhoVetor>i; i++)
  		fprintf(fp ,"%d %d     ",Vetor[i].x,Vetor[i].y  ); /* Grava os elementos do vetor, número a número */

 	fclose(fp);
}


void LeArquivos(){
    int qtdNumeros,i;
    struct coordenadas *vetor;
    // abrindo um arquivo para leitura
    FILE *fp = fopen("arquivo.txt","r");

    if( !fp ){
        printf("falha na abertura do arquivo\n");
        exit(1);
    }

    // le a quantidade de numeros no arquivo
    fscanf(fp,"%d", &qtdNumeros);

    // aloca o vetor de inteiros
    vetor = (COORDENADAS*) calloc(qtdNumeros,sizeof(int));
    // le os numeros do arquivos
    for(i=0; i < qtdNumeros;i++)
        fscanf(fp,"%d %d", &vetor[i].x, &vetor[i].y);

    for(i=0; i < qtdNumeros;i++)
        printf("vetor[%d]= x=%d y=%d\n",i,vetor[i].x, vetor[i].y);


    // liberar o vetor de inteiros
    free(vetor);
    // ao final, sempre devo fechar o arquivo
    fclose(fp);

}


int main(){

	

	struct coordenadas Vetor[] = {{1,2} ,{3,4}, {5,6}, {7,8}, {9,10}, {11,12}, {13,14}};	

	GuardaArquivos(Vetor, 7);
	LeArquivos();
 
  return 0; 

}
























