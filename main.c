#include <stdio.h>
#include <stdlib.h>


typedef struct
{

    char nome[50];
    int mat;


} Alunos;


aloca_vetor(int N)
{
    int i;
    Alunos *p;
    p=(Alunos*)malloc(sizeof(Alunos)*N);
    if(p==NULL)
    {
        printf("nao foi alocado");
        exit(1);
    }
    return p;
}

void imprimir(int N,Alunos *p)
{
    int i;
    Alunos *k=p;

    for(i=0; i<N; i++)

    {
        printf("Aluno: %s\nID: %d\n",(k+i)->nome,(k+i)->mat);
        printf("\n");
    }
}

void rapida (int n, Alunos* v)
{

    if (n <= 1) return;
    else
    {


        Alunos x = v[0];
        int a = 1;
        int b = n-1;
        do
        {
            while (a < n && v[a].mat <= x.mat) a++;
            while (v[b].mat > x.mat) b--;
            if (a < b)
            {
                /* faz troca */
                Alunos temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
        }
        while (a <= b);
        /* troca pivô */
        v[0] = v[b];
        v[b] = x;
        /* ordena sub-vetores restantes */
        rapida(b,v);
        rapida(n-a,&v[a]);
    }

}


int main()
{

int i,N=3;

    Alunos *p;

    p=aloca_vetor(N);

    for(i=0; i<N; i++)
    {
        printf("Digite o nome da pessoa %d\n",i+1);
        scanf("%s",(p+i)->nome);

        printf("Digite a ID da pessoa %d\n",i+1);
        scanf("%d",&(p+i)->mat);
    }


imprimir(N,p);

rapida(N,p);

imprimir(N,p);

    return 0;
}


