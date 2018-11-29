#include <stdio.h>
#include <stdlib.h>
int x=0, transacao=0;
typedef struct cliente
{
    char nome[100],end[200],conta[20],banco[20];
    int num,cpf,id;
    float valor,ultsaq,ultdep;
} c;

int main ()
{
    void Cadastra (c cliente[]);
    void busca (c cliente[]);
    void deposito (c cliente[]);
    void saque (c cliente[]);
    void transferencia (c cliente[]);
    void consulta (c cliente[]);
    void load (c cliente[]);
    void save (c cliente[]);
    void loadT();

    c cliente[100];
    load(cliente);
    loadT();
    printf("d");
    int i, menu1=-1,menu2=-1,menu3=-1,cont;
    while(menu1!=0)
    {
        system("cls");
        menu1=9;
        printf("\t\t\t\t***BANCO***\n\n\n\n");
        printf("Oque deseja fazer?\n\n");
        printf("1-CADASTRAMENTO E BUSCA DE USUARIO\n");
        printf("2-MANUTENCOES BANCARIAS\n");
        printf("0-SAIR\n");
        scanf("%d",&menu1);
        menu2=-1;
        menu3=-1;
        switch(menu1)
        {
        case 1:
            while(menu2!=0)
            {
                system("cls");
                printf("Digite o numero da operacao\n\n\n");
                printf("1-CADASTRAMENTO DE NOVO USUARIO\n");
                printf("2-BUSCA DE USUARIO\n");
                printf("0-Voltar ao menu anterior\n");
                scanf("%d",&menu2);
                switch(menu2)
                {
                case 1:
                    cadastra(cliente);
                    save(cliente);
                    break;
                case 2:
                    busca(cliente);
                    break;
                }
            }
            break;
        case 2:
            while(menu3!=0)
            {
                system("cls");
                printf("Digite o numero da operacao\n\n\n");
                printf("1- DEPOSITO\n");
                printf("2-SAQUE\n");
                printf("3-TRANSFERENCIA\n");
                printf("4-CONSULTA\n");
                printf("0-Voltar ao menu anterior\n");
                scanf("%d",&menu3);
                switch(menu3)
                {
                case 1:
                    deposito(cliente);
                    break;
                case 2:
                    saque (cliente);
                    break;
                case 3:
                    transferencia(cliente);
                    break;
                case 4:
                    consulta(cliente);
                    break;
                }
            }
        }
    }

}




void cadastra(c cliente[])
{
    system("cls");
    printf("*cliente %d\n\n",x+1);
    cliente[x].num = x+1;
    printf("Digite seu nome: \n");
    fflush(stdin);
    scanf ( "%[^\n]", cliente[x].nome);
    printf("Digite o CPF [apenas numeros]:\n");
    scanf("%d",&cliente[x].cpf);
    printf("Digite a sua identidade [apenas numeros]:\n");
    scanf("%d",&cliente[x].id);
    printf("Qual o seu endereço:\n");
    fflush(stdin);
    scanf ( "%[^\n]", cliente[x].end);
    printf("Digite o numero da conta:\n");
    fflush(stdin);
    scanf ( "%[^\n]", cliente[x].conta);
    printf("Digite o numero do banco:\n");
    fflush(stdin);
    printf("Itau = 1\nCaixa = 2\nBradesco = 3\nSantander = 4\nBanco do Brasil = 5\nSicoob = 6\n");
    scanf ( "%[^\n]", cliente[x].banco);
    x++;
}




void busca(c cliente[])
{
    int iden,aux=x,i,menu,cpf;
    system("cls");
    printf("digite 1 para busca por cpf e 2 para busca por numero de identificacao: \n");
    scanf("%d",&menu);
    if(menu==2)
    {
        printf("Digite o numero de identificacao: \n");
        scanf("%d",&iden);
        for (i=0; i<=x; i++)
        {
            if(cliente[i].num==iden)
            {
                aux=-1;
                printf("Cliente encontrado!!\n\n");
                printf("%s\n",cliente[i].nome);
                printf("numero da conta: %s\n",cliente[i].conta);
                printf("numero do banco: %s\n",cliente[i].banco);
                printf("CPF: %d\n",cliente[i].cpf);
                printf("identidade: %d\n",cliente[i].id);
                printf("Endereco: %s\n",cliente[i].end);
                system("pause");
            }
        }
    }
    if(menu==1)
    {
        printf("Digite o numero do cpf: \n");
        scanf("%d",&cpf);
        for (i=0; i<=x; i++)
        {
            if(cliente[i].cpf==cpf)
            {
                aux=-1;
                printf("Cliente encontrado!!\n\n");
                printf("%s\n",cliente[i].nome);
                printf("numero da conta: %s\n",cliente[i].conta);
                printf("numero do banco: %s\n",cliente[i].banco);
                printf("CPF: %d\n",cliente[i].cpf);
                printf("identidade: %d\n",cliente[i].id);
                printf("Endereco: %s\n",cliente[i].end);
                system("pause");
            }
        }
    }
    if(aux!=-1)
    {
        printf("\nCliente nao encontrado!!");
        system("pause");
    }
}




void deposito (c cliente[])
{
    int num,i,aux;
    float valor;
    char data[10];
    system("cls");
    printf("Digite o numero de identificacao bancario: \n");
    scanf("%d", &num);
    for (i=0; i<=x; i++)
    {
        if (cliente[i].num==num)
        {
            system("cls");
            aux=-1;
            printf("Cliente encontrado !!!\n\n\n");
            printf("Qual o valor a ser depositado ?\n");
            scanf("%f",&valor);
            printf("informe a data [dd/mm/aaaa]: \n");
            scanf("%s",data);
            cliente[i].valor +=valor;
            cliente[i].ultdep=valor;
            system ("cls");
            printf("OPERACAO REALIZADA COM SUCESSO\n\n\n\n");
            transacao++;

            FILE * arq;
            arq=fopen("contas.txt","a");
            fprintf(arq,"\n%d|1|%s|%d|%f|",transacao,data,num,valor);
            fclose(arq);
            fflush(arq);

            system("pause");
            break;
        }
    }
    if (aux!=-1)
    {
        printf("CLIENTE NAO ENCONTRADO...\n");
        system("pause");
    }
}




void saque (c cliente[])
{
    int num,i,aux,v=0;
    float valor;
    char data[10];
    system("cls");
    printf("Digite o numero de identificacao bancario: \n");
    scanf("%d", &num);
    for (i=0; i<=x; i++)
    {
        if (cliente[i].num==num)
        {
            system("cls");
            aux=-1;
            printf("Cliente encontrado !!!\n\n\n");
            printf("Qual o valor a ser sacado ?\n");
            scanf("%f",&valor);
            printf("informe a data [dd/mm/aaaa]: \n");
            scanf("%s",data);
            cliente[i].valor -=valor;
            cliente[i].ultsaq=valor;
            system ("cls");
            transacao++;

            FILE * arq;
            arq=fopen("contas.txt","a");
            fprintf(arq,"\n%d|2|%s|%d|%f|",transacao,data,num,valor);
            fclose(arq);
            fflush(arq);

            printf("OPERACAO REALIZADA COM SUCESSO\n\n\n\n");
            system("pause");
            break;
        }
    }
    if (aux!=-1)
    {
        printf("CLIENTE NAO ENCONTRADO...\n");
        system("pause");
    }
}


void transferencia (c cliente[])
{
    int num1,num2,i,aux=x,j;
    float valor;
    char data[10];
    printf("Qual o seu numero de indentificacao bancario?\n");
    scanf("%d",&num1);
    for (i=0; i<=x; i++)
    {
        if (cliente[i].num==num1)
        {
            system("cls");
            aux=-1;
            printf("Cliente encontrado !!!\n\n\n");
            printf("qual o numero de identificacao bancaria da conta para qual se quer transferir?\n");
            scanf("%d", &num2);
            for (j=0; j<=x; j++)
            {
                if(cliente[j].num==num2)
                {
                    printf("Qual o valor a ser transferido ?\n");
                    scanf("%f",&valor);
                    printf("informe a data [dd/mm/aaaa]: \n");
                    scanf("%s",data);
                    cliente[i].valor -=valor;
                    cliente[j].valor +=valor;
                    transacao++;


                    FILE * arq;
                    arq=fopen("contas.txt","a");
                    fprintf(arq,"\n%d|3|%s|%d|%f|%d|",transacao,data,num1,valor,num2);
                    fclose(arq);
                    fflush(arq);


                    aux=-1;
                    break;
                }
            }
        }

    }


    if(aux==-1)
    {
        printf("TRANSFERENCIA EFETUADA COMM SUCESSO !!");
        system ("pause");
    }
    else
    {
        printf("ERRO NA TRANSACAO !!");
        system ("pause");
    }
}





void consulta (c cliente[])
{
    int num,i,aux=x,j;
    float saldo = 0,v5;
    FILE * arq;
    const char s[2] = "|";
    char  linha[300];
    char *result, *token, v3[10];
    int v1,v2,v4,v6;

    printf("Informe o seu numero de indentificação bancaria: \n");
    scanf("%d",&num);
    for (i=0; i<=x; i++)
    {
        if(cliente[i].num==num)
        {
            system("cls");
            aux=-1;
            printf("Cliente encontrado!!!\n\n\n\n");
            printf("----------------------------------------------\n");
            printf("%s\n",cliente[i].nome);
            arq=fopen("contas.txt","r");
            while (!feof(arq))
            {
                result = fgets(linha, 300, arq);
                token = strtok(result, s);

                v1 = atoi(token);
                token = strtok(NULL, s);
                v2 = atoi(token);
                token = strtok(NULL, s);
                strcpy(v3, token);
                token = strtok(NULL, s);
                v4 = atoi(token);
                token = strtok(NULL, s);
                v5 = atoi(token);
                token = strtok(NULL, s);
                if(v2==3)
                {
                    v6 = atoi(token);
                    token = strtok(NULL, s);
                    if(v6==num)
                    {
                        saldo+=v5;
                    }
                }
                if(v4==num)
                {
                    if(v2==1)
                    {
                        saldo+=v5;
                    }
                    if(v2==2)
                    {
                        saldo-=v5;
                    }
                    if(v2==3)
                    {
                        saldo-=v5;
                    }
                }

            };


            fclose(arq);
            fflush(arq);
            printf("Saldo: R$ %.2f\n", saldo);
            printf("----------------------------------------------\n");
        }
    }
    if(aux!=-1)
    {
        printf("\n***erro no acesso a conta***\n");
    }
    system("pause");
}


void load (c cliente[])
{
    FILE * arq;
    const char s[2] = "|";
    char nome [100], conta[20], banco[20], end[200], linha[300];
    char *result, *token;
    int num, id, cpf;
    float valor;
    arq=fopen("cliente.txt","r");

    // while( fscanf(arq,"%d %s %d %d %s %s %s %f\n", &num, nome, &cpf, &id, end, conta, banco, &valor) != EOF ){

    while (!feof(arq))
    {
        result = fgets(linha, 300, arq);
        token = strtok(result, s);

        num = atoi(token);
        token = strtok(NULL, s);
        strcpy(nome, token);
        token = strtok(NULL, s);
        cpf = atoi(token);
        token = strtok(NULL, s);
        id = atoi(token);
        token = strtok(NULL, s);
        strcpy(end, token);
        token = strtok(NULL, s);
        strcpy(conta, token);
        token = strtok(NULL, s);
        strcpy(banco, token);
        token = strtok(NULL, s);


        printf("%d %s %d %d %s %s %s\n", num, nome, cpf, id, end, conta, banco,valor);
        strcpy (cliente[x].nome, nome);
        strcpy (cliente[x].banco, banco);
        strcpy (cliente[x].conta, conta);
        strcpy (cliente[x].end, end);
        cliente[x].num = num;
        cliente[x].cpf = cpf;
        cliente[x].id = id;
        x++;
    };
    fclose(arq);
    fflush(arq);
}

void save (c cliente[])
{
    FILE * arq;
    arq=fopen("cliente.txt","w");
    int i;
    for (i=0; i<x; i++)
    {
        if(i!=x-1)
            fprintf(arq,"%d|%s|%d|%d|%s|%s|%s|\n",cliente[i].num,cliente[i].nome,cliente[i].cpf,cliente[i].id,cliente[i].end,cliente[i].conta,cliente[i].banco);
        else
            fprintf(arq,"%d|%s|%d|%d|%s|%s|%s|",cliente[i].num,cliente[i].nome,cliente[i].cpf,cliente[i].id,cliente[i].end,cliente[i].conta,cliente[i].banco);
    }
    fclose(arq);
    fflush(arq);
}
void loadT()
{
    FILE * arq;
    const char s[2] = "|";
    char linha[300];
    char *result, *token;
    int a=0;
    arq=fopen("contas.txt","r");
    while (!feof(arq))
    {
        a++;
        result = fgets(linha, 300, arq);
        token = strtok(result, s);
        if(token != NULL)
        {
            transacao = atoi(token);
            token = strtok(NULL, s);
        }
    }
    fclose(arq);
    fflush(arq);
    transacao = a-1;
}
