
int i,j,k;//Declara��o(Declarar i,j,k como variavel do tipo inteiro).
for(i=0; i<n; i++)//Atribui��o(i =inicia a 0); Compara��o(i � menor que n, se sim continua, se n�o finaliza o for); Incrementa(i recebe soma + 1).
{
    for(j=0; j<n; j++)//Atribui��o(j =inicia a 0); Compara��o(j � menor que n, se sim continua, se n�o finaliza o for); Incrementa(j recebe soma + 1).
    {
        r[i][j]=0;//Atribui��o (r na posi��o da matriz recebe 0);
        for(k=0; k<n; k++)//Atribui��o(k =inicia a 0); Compara��o(k � menor que n, se sim continua, se n�o finaliza o for); Incrementa(k recebe soma + 1).
        {
            r[i][j]+=a[i][j]*b[k][j];// Atribui��o (r na posi��o da matriz, recebe valor da opera��o); Opera��o (a matriz multiplica b matriz, e soma com r matriz atual).
        }
    }
}

f(n)=3n+2
