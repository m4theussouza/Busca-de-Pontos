#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// declaracao do TAD TPonto
typedef struct{
    int x, y;
}TPonto;

// declaracao do TAD TListaPonto
typedef struct{
    TPonto *elementos; // vetor de pontos
    int maximo; // quantidade maxima de pontos no vetor de pontos
    int qtdAtual; // quantidade atual de pontos no vetor de pontos
}TListaPonto;

// declaracao de funcoes
TListaPonto *Init( int N );
void Desaloca( TListaPonto *lista);
void insereFinal( TListaPonto *lista, TPonto p);
void imprimeListaPontos( TListaPonto *lista );
void insereDadaPosicao(TListaPonto *lista, TPonto p, int posicao);
void removeDadaPosicao(TListaPonto *lista, int posicao);
void pontosAleatorios(TListaPonto *lista);
float pitagoras(TPonto, TPonto);
void distanciaEntrePontos(TListaPonto*,TPonto,int);


int main(void){
    // declarando Lista de Pontos;
    TListaPonto *lista;
    char opc;
    int i, posicao, kpontos;

    lista = Init( 10 ); //cria um vetor de pontos com 1000 posicoes

    // faz o menu de opcoes
    do{
        printf("1 - Adicionar no Final\n"
               "2 - Adicionar na posicao Indicada\n"
               "3 - Ver Quantidade de Pontos Na Lista\n"
               "4 - Remover Na Posicao Indicada\n"
               "5 - Para Adicionar Pontos Aleatorios de X e Y menores que 1000\n"
               "6 - Achar pontos mais próximos\n"
               "7 - sair\n");
        opc = getchar();

        if( opc == '1'){ //adicionar no final
            TPonto p;
            printf("digite os valores de x,y (separados por virgula):");
            scanf("%d,%d",&p.x,&p.y);
            printf("\nlista de pontos:");
            insereFinal(lista,p);
        }
        if( opc == '2'){
            TPonto p;
            printf("Digite em qual posicao deseja inserir a Coordenada: ");
            scanf("%d", &posicao);
            printf("Digite os valores de x,y a inserir (separados por virgula): ");
            scanf("%d,%d", &p.x, &p.y);
            insereDadaPosicao(lista,p,posicao);
        }
        if( opc == '3'){
            printf("A quantidade de Pontos atuais eh : %d", lista->qtdAtual );  
        }
        if( opc == '4'){
            TPonto p;
            p.x = 0;
            p.y = 0;
            printf("Digite em qual posicao deseja Remover a Coordenada: ");
            scanf("%d", &posicao);
            removeDadaPosicao(lista,posicao);
        }
        if( opc == '5'){
            pontosAleatorios(lista);
        }
        if( opc == '6'){
            TPonto p;
            int kpontos;
            printf("Qual ponto deseja calcular? separe por virgula\n Digite Aqui: ");
            scanf("%d,%d", &p.x, &p.y);
            printf("Quantos pontos deseja ?\n Digite Aqui: ");
            scanf("%d", &kpontos);
            distanciaEntrePontos(lista,p,kpontos);

        }  
        getchar();
        imprimeListaPontos( lista );
        
    }while (opc != '8');

    getchar();

    printf("\nfim do programa\n");
    // libera a lista de pontos

    Desaloca(lista);
    return 0;
}
// Função cria e devolve uma nova estrutura TListaPontos, inicializa os atributos da estrutura.
TListaPonto *Init( int N ){

    TListaPonto *lista;


    lista = (TListaPonto*) calloc(1,sizeof(TListaPonto));
    lista->qtdAtual = 0;
    lista->maximo   = N;

    // aloca um vetor de pontos
    lista->elementos = (TPonto*) calloc(N,sizeof(TPonto));

    return lista;
}
// Função desaloca a memoria utilizada por *listaPontos
void Desaloca( TListaPonto *lista){
    // libera o vetor
    free(lista->elementos);
    // libera a estrutura
    free(lista);
}

// insere um ponto no final da lista de pontos
void insereFinal( TListaPonto *lista, TPonto p){

    if( lista->qtdAtual < lista->maximo){
        lista->elementos[lista->qtdAtual] = p;
        (lista->qtdAtual)++;
    }
    else{
        printf("\nlista lotada\n");

    }

} 
// imprime a lista de pontos
void imprimeListaPontos( TListaPonto *lista ){
    int i;
    printf("\n");
    for(i=0;i<lista->qtdAtual;i++)
        printf("Coordenada Da Posicao %d: (%d,%d)\n ",i, lista->elementos[i].x,lista->elementos[i].y);
}  

void insereDadaPosicao(TListaPonto *lista, TPonto p, int posicao){
    if(lista->qtdAtual < lista->maximo && lista->elementos[posicao].x == 0 && lista->elementos[posicao].y == 0 ){
        lista->elementos[posicao] = p;
    }
    else{
        printf("Posicao Ocupada\n");
    }
}

void removeDadaPosicao(TListaPonto *lista, int posicao){
        // lista->elementos[posicao] = p;
    for (int i = posicao; i < lista->qtdAtual; i++){

       lista->elementos[i].x = lista->elementos[i+1].x;
       lista->elementos[i].y = lista->elementos[i+1].y;
    }

    lista->qtdAtual--;

    imprimeListaPontos(lista);
 
}

void pontosAleatorios(TListaPonto *lista){
        int i;
        srand((unsigned)time(NULL));
        for(i=lista->qtdAtual; i < lista->maximo; i++){
        lista->elementos[i].x = rand() % 1000;
        lista->elementos[i].y = rand() % 1000;
        (lista->qtdAtual)++;
        }
}

void distanciaEntrePontos(TListaPonto *lista, TPonto p, int kpontos){
    int i; 

    TListaPonto *vetorDistancia;
     
    vetorDistancia = Init(kpontos);
    
    float distancia;

    for(i = 0; i < lista->qtdAtual; i++)
    
    vetorDistancia[i] = pitagoras(p,lista->elementos[i]);

    printf("Distancia  = %lf\n", distancia);
}
    

float pitagoras(TPonto p1, TPonto p2){
    
    float distancia;
    
    distancia = sqrt( pow( ( p2.x - p1.x ),2) + pow( ( p2.y - p1.y ), 2) );

    return distancia;

}
