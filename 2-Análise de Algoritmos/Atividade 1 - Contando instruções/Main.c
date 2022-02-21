
int i,j,k;//Declaração(Declarar i,j,k como variavel do tipo inteiro).
for(i=0; i<n; i++)//Atribuição(i =inicia a 0); Comparação(i é menor que n, se sim continua, se não finaliza o for); Incrementa(i recebe soma + 1).
{
    for(j=0; j<n; j++)//Atribuição(j =inicia a 0); Comparação(j é menor que n, se sim continua, se não finaliza o for); Incrementa(j recebe soma + 1).
    {
        r[i][j]=0;//Atribuição (r na posição da matriz recebe 0);
        for(k=0; k<n; k++)//Atribuição(k =inicia a 0); Comparação(k é menor que n, se sim continua, se não finaliza o for); Incrementa(k recebe soma + 1).
        {
            r[i][j]+=a[i][j]*b[k][j];// Atribuição (r na posição da matriz, recebe valor da operação); Operação (a matriz multiplica b matriz, e soma com r matriz atual).
        }
    }
}

f(n)=3n+2
