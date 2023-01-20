#include <stdio.h>

struct boletim{
    float notas[2][2];
    float media;
    int passou;
};

struct alunos{
    char nome[50];
    int serie;
    struct boletim b;
};

int lerQtdAlunos();
struct alunos lerAlunos(int numAluno);
struct boletim lerNotas();
float calcularMedia(struct boletim b);
int validarPassou(struct boletim b);
void mostraAlunos(struct alunos aluno);
// N modificar acima
int main(){

    int i;
    int qtdAlunos = lerQtdAlunos();
    struct alunos aluno[qtdAlunos];

    for(i = 0; i < qtdAlunos; i++){

        printf("\nAluno numero %d", i+1);

        aluno[i] = lerAlunos(i);

        aluno[i].b = lerNotas();

        aluno[i].b.media = calcularMedia(aluno[i].b);

        aluno[i].b.passou = validarPassou(aluno[i].b);

    }
    for(i=0; i<qtdAlunos; i++){
        mostraAlunos(aluno[i]);
    };

    return 0;
}

int lerQtdAlunos(){
    int nAlunos;
    printf("Insira a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &nAlunos);
    return nAlunos;
};

struct alunos lerAlunos(int numAluno){
    struct alunos aluno;
    printf("\n%d - Insira nome do aluno: ", numAluno+1); //i = n do aluno atual
    scanf("%s",&aluno.nome);

    printf("\n%d - Insira a serie do aluno: ", numAluno+1);
    scanf("%d", &aluno.serie);

    return aluno;
};

struct boletim lerNotas() {
    struct alunos aluno;
    for (int lin = 0; lin < 2; lin++) {

        for (int col = 0; col < 2; col++) {
            if (lin == 0) {
                do {
                    printf("\nNotas de trabalho devem ser de 0 a 2");
                    printf("\nInsira a nota do trabalho %d do aluno: ", col + 1);
                        scanf("%f", &aluno.b.notas[0][col]);
                } while (aluno.b.notas[0][col] > 2 || aluno.b.notas[0][col] < 0);
            } else {
                do {
                    printf("\nNotas de prova devem ser de 0 a 3");
                    printf("\nInsira a nota %d de prova: ", col + 1);
                    scanf("%f", &aluno.b.notas[1][col]);
                } while (aluno.b.notas[1][col] > 3 || aluno.b.notas[1][col] < 0);
            }
        }
    }
    return aluno.b;
};

float calcularMedia(struct boletim b){

    for (int lin = 0; lin < 2; lin++){
        for(int col = 0; col < 2; col++){
            b.media += b.notas[lin][col];
        }
    }
    return b.media;
};

int validarPassou(struct boletim b){
    if(b.media >= 6){
        return b.passou = 1;
    } else {
        return b.passou = 0;
    }
};

void mostraAlunos(struct alunos aluno){
    printf("\n\t %s", aluno.nome);
    printf("\n\t %d", aluno.serie);
    if(aluno.b.passou == 1){
        printf("\nO aluno PASSOU com media %.1f", aluno.b.media);
    } else {
        printf("\nO aluno REPROVOU com media %.1f", aluno.b.media);
    }
};
