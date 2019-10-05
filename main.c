#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define MAX_DATAS 366

typedef struct{

    char notas[30];
}TipoEventos;

typedef struct
{
    int dia,mes,ano;
    TipoEventos eventos[5];
}TipoData;

typedef struct{

    TipoData datas[MAX_DATAS];
    int pos;
}TipoVetor;

void diasemana(TipoVetor *,int);
int contdiasanos(TipoData);
void mostrarCalendario(TipoVetor);
void horariounix(TipoData,TipoData);
void menuinicial(void);
void validacaodedata(TipoData);
void colecaodedatas(TipoVetor);
void operacoescomdatas(TipoData,TipoData);
void calcularodiadasemana(TipoData);
void gestaodocalendario(TipoVetor);
void lerdata(TipoData*);
int Validacao(TipoData);
int Verifformatdata(TipoData);
void apresentardata1(TipoData);
void apresentardata2(TipoData);
void apresentardata3(TipoData);
void InserirvetorData(TipoVetor*);
void mostrarVetorDatas(TipoVetor);
void VetordatasAleatorio(TipoVetor*);
int Verificardata(TipoVetor*);
void Mostrardatamaior(TipoVetor);
void Mostrardatamenor(TipoVetor);
void Ordemcrescente(TipoVetor*);
void Ordemdecrescente(TipoVetor*);
int retornabissexto(TipoData);
void anobissexto(TipoData);
void mostrardatahoje();
void adicionarndias(TipoData);
int verificaanobissexto(TipoData);
void removerndias(TipoData);
void comparardatas(TipoData,TipoData);
void difdatas(TipoData,TipoData);
int validadias(TipoData);
int devolndias(TipoData);
void difdatasuteis(TipoData,TipoData);
int diautil(TipoData);
void criacaleendario(TipoVetor*);
void adicionarevento(TipoVetor *);
void mostrareventos(TipoVetor);
int diasano(TipoData);
int datamaior(TipoData data1,TipoData data2);
void alterarevento(TipoVetor*);
void calcularpascoa(TipoVetor);
void calculardiasfestivos(TipoVetor);
void mostraeventodata(TipoVetor);
void mostrarinfdata(TipoVetor);
void eventos(TipoVetor *,int);
void feriadomovel(TipoVetor);
void feriadofixo(TipoVetor);
void removerndias(TipoData);
void feriadosfestivos(TipoVetor);
void mudancahora(TipoVetor);
void outroseventos(TipoVetor);

int main(){

    int op;
    TipoData data1,data2;
    TipoVetor vetor;

    setlocale(LC_ALL,"Portuguese");

    do{
        system("cls");
        menuinicial();
        printf("Introduza uma das opcoes:\n");
        scanf("%d",&op);

        switch(op){
            case 1: validacaodedata(data1);break;
            case 2: colecaodedatas(vetor);break;
            case 3: operacoescomdatas(data1,data2);break;
            case 4: calcularodiadasemana(data1);system("pause");break;
            case 5: gestaodocalendario(vetor);break;
            case 6: printf("Adeus");exit(1);break;
            default: printf("Opção incorreta\n");break;
        }
    }while(op!=6);
    return 0;
}
void menuinicial(){

    printf("\nMenu inicial\n");
    printf("1. Validacao de data\n");
    printf("2. Colecao de datas\n");
    printf("3. Operacao com datas\n");
    printf("4. Calcular o dia da semana\n");
    printf("5. Gestão de Calendario\n");
    printf("6. Terminar o programa\n");
}
void validacaodedata(TipoData data){

    int op;

    do{
        system("cls");
        printf("\nMenu Validacao de data\n");
        printf("1. Ler data\n");
        printf("2. Verificar formatacao de data\n");
        printf("3. Verificar validade da data\n");
        printf("4. Apresentar uma data no formato \"dd//mm//aaaa\"\n");
        printf("5. Apresentar uma data no formato \"dd \" de \" mm \" de \" aaaa\"\n");
        printf("6. Apresentar uma data no formato \"dd \" de \" mês \" de \" aaaa\"\n");
        printf("7. Voltar ao menu anterior");

        printf("Introduza uma das opcoes:\n");
        scanf("%d",&op);

        switch(op){

            case 1: lerdata(&data);break;
            case 2: if(Verifformatdata(data)==1){
                        printf("O formato da data é correto\n");

                    }
                    else{
                        printf("O formato da data é incorreto\n");
                    }
                    system("pause");break;
            case 3: if(Validacao(data)==1){
                        printf("data válida\n");

                    }
                    else{
                        printf("data invalida %d\n");
                    }
                    system("pause");
                    break;
            case 4: apresentardata1(data);system("pause");break;
            case 5: apresentardata2(data);system("pause");break;
            case 6: apresentardata3(data);system("pause");break;
            case 7: main();break;
            default: printf("Opcao incorreta\n");system("pause");break;
        }
    }while(op!=7);
}
void colecaodedatas(TipoVetor vetor){

    int op;
    srand(time(NULL));
    vetor.pos=0;

    do{
        system("cls");
        printf("\nMenu Colecao de datas\n");
        printf("1. Inserir uma data num vetor de datas;\n");
        printf("2. Mostrar o vetor de datas;\n");
        printf("3. Preencher um vetor com datas aleatórias válidas;\n");
        printf("4. Verificar se uma data existe no vetor;\n");
        printf("5. Mostrar a data maior do vetor e a sua posição;\n");
        printf("6. Mostrar a data menor do vetor e a sua posição;\n");
        printf("7. Ordenar as datas do vetor por ordem crescente;\n");
        printf("8. Ordenar as datas do vetor por ordem decrescente;\n");
        printf("9. Voltar ao menu anterior\n");
        printf("Introduza uma das opcoes:\n");
        scanf("%d",&op);

        switch(op){

            case 1: InserirvetorData(&vetor);
            system("pause");
            break;
            case 2: mostrarVetorDatas(vetor);
            system("pause");
            break;
            case 3: VetordatasAleatorio(&vetor);
            system("pause");
            break;
            case 4: switch(Verificardata(&vetor)) {
                    case 1:printf("Data já existente na coleção\n");
                    break;
                    case 0: printf("Não foi adicionada à coleção\n");
                    break;
                    case 2:printf("Data adicionada na coleção\n");
                    break;

                }
            system("pause");
            break;
            case 5: Mostrardatamaior(vetor);
            system("pause");
            break;
            case 6: Mostrardatamenor(vetor);
            system("pause");
            break;
            case 7: Ordemcrescente(&vetor);system("pause");break;
            case 8: Ordemdecrescente(&vetor);system("pause");break;
            case 9: main();break;
            default: printf("Opcao incorreta\n");system("pause");break;
        }
    }while(op!=9);
}
void operacoescomdatas(TipoData data1,TipoData data2){

    int op;

    do{
        system("cls");
        printf("\nMenu Operaçoes com datas\n");
        printf("1. Verificar se data é de um ano bissexto \n");
        printf("2. Mostrar a data de hoje;\n");
        printf("3. Adicionar n dias a uma determinada data;\n");
        printf("4. Remover n dias a uma determinada data;\n");
        printf("5. Comparar duas datas\n");
        printf("6. Mostrar diferença entre duas datas (em dias);\n");
        printf("7. Mostrar quantos dias úteis existem entre duas datas;\n");
        printf("8. Mostrar o horário Unix de uma data;\n");
        printf("9. Voltar ao menu anterior;\n");
        printf("Introduza uma das opcoes:\n");
        scanf("%d",&op);

        switch(op){

            case 1: anobissexto(data1);
            system("pause");
            break;
            case 2: mostrardatahoje();
            system("pause");
            break;
            case 3: adicionarndias(data1);
            system("pause");
            break;
            case 4: removerndias(data2);system("pause");break;
            case 5: comparardatas(data1,data2);system("pause");break;
            case 6: difdatas(data1,data2);system("pause");break;
            case 7: difdatasuteis(data1,data2);system("pause");break;
            case 8: horariounix(data1,data2);system("pause");break;
            case 9: main();break;
            default: printf("Opcao incorreta\n");break;
        }
    }while(op != 9);
}
void calcularodiadasemana(TipoData data){

    int i,s=0;
    int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char dsemana[7][10];

	strcpy(dsemana[0],"Domingo");
	strcpy(dsemana[1],"Segunda");
	strcpy(dsemana[2],"Terca");
	strcpy(dsemana[3],"Quarta");
	strcpy(dsemana[4],"Quinta");
	strcpy(dsemana[5],"Sexta");
	strcpy(dsemana[6],"Sabado");

	printf("\nCalcula dia da semana\n");

	do{
		printf("Introduza uma data: \n");
		lerdata(&data);
	}while(Validacao(data)==0);

	if((data.ano%400==0) || ((data.ano%4==0)&&(data.ano%100!=0))){

        meses[1]=29;
	}
	for(i=0;i<data.mes-1;i++){

        s=s+meses[i];
	}
	s=s+(data.dia+data.ano+(data.ano/4)-2);
	s=s%7;
	printf("\n%s",dsemana[s]);
}
void gestaodocalendario(TipoVetor calendario){

    int op,i,j;

    for(i=0;i<366;i++){
        for(j=0;j<6;j++){
            strcpy(calendario.datas[i].eventos[j].notas,"");
        }
    }

    do{
        system("cls");
        printf("\nMenu Operaçoes com datas\n");
        printf("1. Criar um calendário para um determinado ano 9 \n");
        printf("2. Adicionar um evento ao calendário;\n");
        printf("3. Alterar informação de um evento;\n");
        printf("4. Calcular e mostrar a data da Páscoa para o ano do calendário;\n");
        printf("5. Calcular e mostrar os feriados ou dias festivos associados à data da Páscoa;\n");
        printf("6. Mostrar todos os eventos;;\n");
        printf("7. Mostrar os eventos do tipo feriado móvel;\n");
        printf("8. Mostrar os eventos do tipo feriado fixo;;\n");
        printf("9. Mostrar os eventos do tipo dia festivo;\n");
        printf("10. Mostrar outros eventos;\n");
        printf("11.Calcular e mostrar os dias da mudança de hora;\n");
        printf("13. Procurar e mostrar informação de uma data do calendário;\n");
        printf("14. Listar calendário;\n");
        printf("15.Voltar ao menu anterior\n");
        printf("Introduza uma das opcoes:\n");
        scanf("%d",&op);

        switch(op){

            case 1: criacaleendario(&calendario);system("pause");break;
            case 2: adicionarevento(&calendario);system("pause");break;
            case 3: alterarevento(&calendario);system("pause");break;
            case 4: calcularpascoa(calendario);system("pause");break;
            case 5: calculardiasfestivos(calendario);system("pause");break;
            case 6: mostrareventos(calendario);system("pause");break;
            case 7: feriadomovel(calendario);system("pause");break;
            case 8: feriadofixo(calendario);system("pause");break;
            case 9: feriadosfestivos(calendario);system("pause");break;
            case 10: outroseventos(calendario);system("pause");break;
            case 11: mudancahora(calendario);system("pause");break;
            case 12: mostraeventodata(calendario);system("pause");break;
            case 13: mostrarinfdata(calendario);system("pause");break;
            case 14: printf("14\n");system("pause");break;
            case 15: main();break;
            default: printf("Opcao incorreta\n");system("pause");break;
        }
    }while(op != 15);
}
void lerdata (TipoData *data){

    printf("Introduza o dia: \n");
    scanf("%d",&data->dia);
    printf("Introduza o mes: \n");
    scanf("%d",&data->mes);
    printf("Introduza o ano: \n");
    scanf("%d",&data->ano);
}
int Verifformatdata(TipoData data){

    if (data.dia>=1 && data.dia <= 99){
        if(data.mes>=1 && data.mes<=99){
            if(data.ano>=1000 && data.ano<= 9999){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
int verificaanobissexto(TipoData data1){

    if(((data1.ano%4==0 && data1.ano%100!=0) || data1.ano%400==0)){

        return 1;
    }
    else{

        return 0;
    }
}
int Validacao(TipoData data){

    if(Verifformatdata(data)==1){

        switch(data.mes){

            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:if(data.dia>=1 && data.dia<=31 && data.ano<=2090){

                        return 1;
                    }
                    else{
                        return 0;
                    }
                    break;
            case 2:if(data.dia>=1 && data.dia<=29 && verificaanobissexto(data)==1 && data.ano<=2090){

                        return 1;
                   }
                   else
                        if(data.dia>=1 && data.dia<=28 && verificaanobissexto(data)==0 && data.ano<=2090){

                            return 1;
                        }
                        else{
                            return 0;
                        }
                    break;
            case 4:
            case 6:
            case 9:
            case 11:if(data.dia>=1 && data.dia<=30 && data.ano<=2090){

                        return 1;
                    }else{
                        return 0;
                    }
                    break;
            default:return 0;break;
        }
    }
}
void apresentardata1(TipoData data){

    if(Validacao(data)==1){
        printf("%d/%d/%d\n",data.dia, data.mes, data.ano);
    }
    else{
        printf("Data Invalida\n");
    }
}
void apresentardata2(TipoData data){
    if(Validacao(data)==1){
        printf("%d do %d de %d\n",data.dia, data.mes, data.ano);
    }
    else{
        printf("Data Invalida\n");

    }
}
void apresentardata3(TipoData data){
    if(Validacao(data)==1){

        switch(data.mes){
            case 1:  printf("%d de Janeiro de %d\n",data.dia, data.ano);
            break;
            case 2:  printf("%d de Fevereiro de %d\n",data.dia, data.ano);
            break;
            case 3:  printf("%d de Março de %d\n",data.dia, data.ano);
            break;
            case 4:  printf("%d de Abril de %d\n",data.dia, data.ano);
            break;
            case 5:  printf("%d de Maio de %d\n",data.dia, data.ano);
            break;
            case 6:  printf("%d de Junho de %d\n",data.dia, data.ano);
            break;
            case 7:  printf("%d de Julho de %d\n",data.dia, data.ano);
            break;
            case 8:  printf("%d de Agosto de %d\n",data.dia, data.ano);
            break;
            case 9:  printf("%d de Setembro de %d\n",data.dia, data.ano);
            break;
            case 10:  printf("%d de Outubro de %d\n",data.dia, data.ano);
            break;
            case 11:  printf("%d de Novembro de %d\n",data.dia, data.ano);
            break;
            case 12:  printf("%d de Dezembro de %d\n",data.dia, data.ano);
            break;
        }
    }else
        printf("Data Invalida\n");
}
void InserirvetorData(TipoVetor *vetor){

    do{

        lerdata(&vetor->datas[vetor->pos]);
    }while(Validacao(vetor->datas[vetor->pos])==0);

    vetor->pos++;
}
void mostrarVetorDatas(TipoVetor vetor){

    int i;

    for(i=0; i<vetor.pos; i++)
    {
        printf("%d/%d/%d\n",vetor.datas[i].dia,vetor.datas[i].mes ,vetor.datas[i].ano);
    }
}
void VetordatasAleatorio(TipoVetor *vetor){

    int i,q=0;

    printf("Introduza um numero de datas aleatórias\n");
    printf("O numero maximo que pode introduzir são, %d\n", MAX_DATAS-vetor->pos);
    scanf(" %d",&q);
    for(i=vetor->pos;i<=q+vetor->pos;i++){

        do{

            vetor->datas[i].mes=rand()%12+1;
            vetor->datas[i].dia=rand()%31+1;
            vetor->datas[i].ano=rand()%9999+1;
        }while(Validacao(vetor->datas[i])==0);
    }
    vetor->pos=q+vetor->pos;
}
int Verificardata(TipoVetor* vetor){

    int i;
    char st;
    TipoData data1;

    do{

        lerdata (&data1);
    }while(Validacao(data1)==0);

    for(i=0;i<vetor->pos;i++){

        if(vetor->datas[i].dia==data1.dia && vetor->datas[i].mes==data1.mes && vetor->datas[i].ano==data1.ano){

            return 1;
        }
    }

    printf("Pretende inserir a data  na coleção? [S/N]\n");
    scanf(" %c",&st);

    if(st=='S'){

            vetor->datas[vetor->pos].dia=data1.dia;
            vetor->datas[vetor->pos].mes=data1.mes;
            vetor->datas[vetor->pos].ano=data1.ano;
            vetor->pos++;
            return 2;
    }
    else
        if(st=='N'){

            return 0;
        }
        else
            printf("caracter não existente");
}
void Mostrardatamenor(TipoVetor vetor){

    int i;
    int menord=31,menorm=12,menora=2090,pos1;

    for(i=0;i<vetor.pos;i++){

        if(menora>vetor.datas[i].ano){

            menora=vetor.datas[i].ano;
            menorm=vetor.datas[i].mes;
            menord=vetor.datas[i].dia;
            pos1=i;
        }
        else
            if(menora==vetor.datas[i].ano && menorm>vetor.datas[i].mes){

                menora=vetor.datas[i].ano;
                menorm=vetor.datas[i].mes;
                menord=vetor.datas[i].dia;
                pos1=i;
            }
            else
                if(menora==vetor.datas[i].ano && menorm==vetor.datas[i].mes && menord>vetor.datas[i].dia){

                    menora=vetor.datas[i].ano;
                    menorm=vetor.datas[i].mes;
                    menord=vetor.datas[i].dia;
                    pos1=i;
                }
    }
    printf("Menor data:\n%d/%d/%d na posição %d da coleção\n",menord,menorm,menora,pos1);
}
void Mostrardatamaior(TipoVetor vetor){

    int i;
    int maiord=1,maiorm=1,maiora=1900,pos1;

    for(i=0;i<vetor.pos;i++){

        if(maiora<vetor.datas[i].ano){

            maiora=vetor.datas[i].ano;
            maiorm=vetor.datas[i].mes;
            maiord=vetor.datas[i].dia;
            pos1=i;
        }
        else
            if(maiora==vetor.datas[i].ano && maiorm>vetor.datas[i].mes){

                maiora=vetor.datas[i].ano;
                maiorm=vetor.datas[i].mes;
                maiord=vetor.datas[i].dia;
                pos1=i;
            }
            else
                if(maiora==vetor.datas[i].ano && maiorm==vetor.datas[i].mes && maiord>vetor.datas[i].dia){

                    maiora=vetor.datas[i].ano;
                    maiorm=vetor.datas[i].mes;
                    maiord=vetor.datas[i].dia;
                    pos1=i;
                }
    }
    printf("Maior data:\n%d/%d/%d na posição %d da coleção\n",maiord,maiorm,maiora,pos1);
}
void Ordemcrescente(TipoVetor *vetor){

    int i,j;
    TipoData t;

    for(i=0;i<vetor->pos-1;i++){
        for(j=i+1;j<vetor->pos;j++){

            if(vetor->datas[i].ano>vetor->datas[j].ano){

                t=vetor->datas[i];
                vetor->datas[i]=vetor->datas[j];
                vetor->datas[j]=t;
            }
            else
                if(vetor->datas[i].ano==vetor->datas[j].ano && vetor->datas[i].mes>vetor->datas[j].mes){

                    t=vetor->datas[i];
                    vetor->datas[i]=vetor->datas[j];
                    vetor->datas[j]=t;
                }
                else
                    if(vetor->datas[i].ano==vetor->datas[j].ano && vetor->datas[i].mes==vetor->datas[j].mes && vetor->datas[i].dia>vetor->datas[j].dia){

                        t=vetor->datas[i];
                        vetor->datas[i]=vetor->datas[j];
                        vetor->datas[j]=t;
                    }
        }
    }
}
void Ordemdecrescente(TipoVetor *vetor){

    int i,j;
    TipoData t;

    for(i=0;i<vetor->pos-1;i++){
        for(j=i+1;j<vetor->pos;j++){

            if(vetor->datas[i].ano<vetor->datas[j].ano){

                t=vetor->datas[i];
                vetor->datas[i]=vetor->datas[j];
                vetor->datas[j]=t;
            }
            else
                if(vetor->datas[i].ano==vetor->datas[j].ano && vetor->datas[i].mes<vetor->datas[j].mes){

                    t=vetor->datas[i];
                    vetor->datas[i]=vetor->datas[j];
                    vetor->datas[j]=t;
                }
                else
                    if(vetor->datas[i].ano==vetor->datas[j].ano && vetor->datas[i].mes==vetor->datas[j].mes && vetor->datas[i].dia<vetor->datas[j].dia){

                        t=vetor->datas[i];
                        vetor->datas[i]=vetor->datas[j];
                        vetor->datas[j]=t;
                    }
        }
    }
}
int retornabissexto(TipoData data){
 if(verificaanobissexto(data)==1)
    return 366;
else
    return 365;

}
void adicionarndias(TipoData data2){

    int dias, total=0;

    do{

        lerdata(&data2);
    }while(Validacao(data2)==0);

    printf("Introduza o numeros de dias para adicionar à data: \n");
    scanf("%d",&dias);
    total = data2.dia+dias;
    while(total >= validadias(data2)){
        total = total - validadias(data2);
        data2.mes++;
        if(data2.mes > 12){

            if(total <= retornabissexto(data2))
            {
            data2.ano++;
            data2.mes = data2.mes-12;
            }
            else
                if(total >= retornabissexto(data2))
                    do{
                    data2.ano++;
                    data2.mes = data2.mes-12;
                    total = total - retornabissexto(data2);
                    }while(total <= retornabissexto(data2));
        }
    }
    printf("%d/%d/%d",total,data2.mes,data2.ano);
}
void removerndias(TipoData data2){
    int dias, total=0;

    do{

        lerdata(&data2);
    }while(Validacao(data2)==0);

    printf("Introduza o numeros de dias para remover à data: \n");
    scanf("%d",&dias);
    total = data2.dia-dias;
    while(total <= -validadias(data2)){
        data2.mes--;
        total = total + validadias(data2);
        if(data2.mes < 1){

            if(total <= -retornabissexto(data2))
            {
            data2.ano--;
            data2.mes = (-data2.mes)+12;
            }
            else
                if(total >= -retornabissexto(data2))
                    do{
                    data2.ano--;
                    data2.mes = (-data2.mes)-12;
                    total = total + retornabissexto(data2);
                    }while(total <= -retornabissexto(data2));
        }

    }
    printf("%d/%d/%d",total,data2.mes,data2.ano);

}
void anobissexto(TipoData data1){

    do{

        lerdata(&data1);
    }while(Validacao(data1)==0);

    if((( data1.ano % 4 == 0 && data1.ano % 100 != 0 ) || data1.ano % 400 == 0) ){ // MODIFICAR!!!!!!

        printf("%d é um ano é bissexto!\n",data1.ano);
    }
    else{

        printf("%d não é um ano é bissexto!\n",data1.ano);
    }
}
void mostrardatahoje(){

    printf("DATA : %s \n",__DATE__);
}
void comparardatas(TipoData data1,TipoData data2){

    do{

        lerdata(&data1);
    }while(Validacao(data1)==0);

    do{

        lerdata(&data2);
    }while(Validacao(data2)==0);

    if(data1.ano<=data2.ano){
        if(data1.ano<data2.ano){
            printf("A data1 é menor que a data2\n");
        }
        if(data1.ano==data2.ano){
            printf("A data1 é igual à data2\n");
        }
    }
    else
        if(data1.ano==data2.ano && data1.mes<=data2.mes){
            if(data1.mes<data2.mes){
                printf("A data1 é menor que a data2\n");
            }
            if(data1.mes==data2.mes){
                printf("A data1 é igual à data2\n");
            }
        }
        else
            if(data1.ano==data2.ano && data1.mes==data2.mes && data1.dia<=data2.dia){
                if(data1.dia<data2.dia){
                    printf("A data1 é menor que a data2\n");
                }
                if(data1.dia==data2.dia){
                    printf("A data1 é igual à data2\n");
                }
            }
            else{
                printf("A data1 é maior que a data2\n");
            }
}
int validadias(TipoData data2){

    switch(data2.mes){

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:return 31;break;
        case 2:if(verificaanobissexto(data2)==1){

                    return 29;
                }
                else
                    return 28;
                break;
        case 4:
        case 6:
        case 9:
        case 11:return 30;
                break;
        default:return 0;break;
        }

}
int diasano(TipoData data){

    int contd=0,ano=data.ano-1;

    while(ano>=1){
        if(((ano%4==0 && ano%100!=0) || ano%400==0)){
            contd=contd+366;
        }
        else{
            contd=contd+365;
        }
        ano--;
    }
    return contd;
}
int datamaior(TipoData data1, TipoData data2){

    if(data1.ano>data2.ano){

        return 1;
    }
    else
        if(data1.ano==data2.ano && data1.mes>data2.mes){

            return 1;
        }
        else
            if(data1.ano==data2.ano && data1.mes==data2.mes && data1.dia>data2.dia){

                return 1;
            }
            else{

                return 0;
            }
}
int devolndias(TipoData data){

    int i=0;

    switch(data.mes){

        case 2: return 31;
        case 3: if(verificaanobissexto(data)==1){
                    return 60;
                }
                else
                    return 59;
        case 4: if(verificaanobissexto(data)==1){
                    return 91;
                }
                else
                    return 90;
        case 5: if(verificaanobissexto(data)==1){
                    return 121;
                }
                else
                    return 120;
        case 6: if(verificaanobissexto(data)==1){
                    return 152;
                }
                else
                    return 151;
        case 7: if(verificaanobissexto(data)==1){
                    return 182;
                }
                else
                    return 181;
        case 8: if(verificaanobissexto(data)==1){
                    return 213;
                }
                else
                    return 212;
        case 9: if(verificaanobissexto(data)==1){
                    return 244;
                }
                else
                    return 243;
        case 10:if(verificaanobissexto(data)==1){
                    return 274;
                }
                else
                    return 273;
        case 11:if(verificaanobissexto(data)==1){
                    return 305;
                }
                else
                    return 304;
        case 12:if(verificaanobissexto(data)==1){
                    return 335;
                }
                else
                    return 334;
    }
}
void difdatas(TipoData data1,TipoData data2){

    int difdia,difmes,difano,mesd1=0,anod1,mesd2=0,anod2,total1=0,total2=0,antd1,antd2,total;
    int i=0,j;

    do{

        lerdata(&data1);
    }while(Validacao(data1)==0);
    fflush(stdin);
    do{

        lerdata(&data2);
    }while(Validacao(data2)==0);

    switch(data1.mes){

        case 2: mesd1=devolndias(data1);break;
        case 3: mesd1=devolndias(data1);break;
        case 4: mesd1=devolndias(data1);break;
        case 5: mesd1=devolndias(data1);break;
        case 6: mesd1=devolndias(data1);break;
        case 7: mesd1=devolndias(data1);break;
        case 8: mesd1=devolndias(data1);break;
        case 9: mesd1=devolndias(data1);break;
        case 10:mesd1=devolndias(data1);break;
        case 11:mesd1=devolndias(data1);break;
        case 12:mesd1=devolndias(data1);break;
    }

    anod1=diasano(data1);
    total1=data1.dia+mesd1+anod1;

    switch(data2.mes){

        case 2: mesd2=devolndias(data2);break;
        case 3: mesd2=devolndias(data2);break;
        case 4: mesd2=devolndias(data2);break;
        case 5: mesd2=devolndias(data2);break;
        case 6: mesd2=devolndias(data2);break;
        case 7: mesd2=devolndias(data2);break;
        case 8: mesd2=devolndias(data2);break;
        case 9: mesd2=devolndias(data2);break;
        case 10:mesd2=devolndias(data2);break;
        case 11:mesd2=devolndias(data2);break;
        case 12:mesd2=devolndias(data2);break;
    }
    anod2=diasano(data2);
    total2=data2.dia+mesd2+anod2;

    total=total1-total2;

    if(datamaior(data1,data2)==1){

        printf("%d dias\n",total);
    }
    else{

        printf("%d dias\n",-1*total);
    }
}
int diautil(TipoData data){

    int i,s=0;
    int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char dsemana[7][10];

	strcpy(dsemana[0],"Domingo");
	strcpy(dsemana[1],"Segunda");
	strcpy(dsemana[2],"Terca");
	strcpy(dsemana[3],"Quarta");
	strcpy(dsemana[4],"Quinta");
	strcpy(dsemana[5],"Sexta");
	strcpy(dsemana[6],"Sabado");

	if((data.ano%400==0) || ((data.ano%4==0)&&(data.ano%100!=0))){

        meses[1]=29;
	}
	for(i=0;i<data.mes-1;i++){

        s=s+meses[i];
	}
	s=s+(data.dia+data.ano+(data.ano/4)-2);
	s=s%7;

    switch (s){

        case 1: if(data.dia==1 && data.mes==1){
                    return 0;
                }
                else
                    return 1;
                break;
        case 2: if(data.dia==1 && data.mes==5 || data.dia==25 && data.mes==12){
                    return 0;
                }
                else
                    return 1;
                break;
        case 3: if(data.dia==25 && data.mes==4 || data.dia==15 && data.mes==8){

                    return 0;
                }
                else
                    return 1;
                break;
        case 4: if(data.dia==31 && data.mes==5 || data.dia==1 && data.mes==11){
                    return 0;
                }
                else
                    return 1;
                break;
        case 5: if(data.dia==30 && data.mes==3 || data.dia==5 && data.mes==10){
                    return 0;
                }
                else
                    return 1;
                break;
        case 0: if(data.dia==1 && data.mes==4 || data.dia==10 && data.mes==6){
                    return 0;
                }
                else
                    return 1;
                break;
    }
}
void difdatasuteis(TipoData data1,TipoData data2){

    int mesd1=0,anod1,mesd2=0,anod2,total1=0,total2=0,antd1,antd2,total,max,cont=0,t=0,c=0;
    TipoData data;

    do{
        do{

            lerdata(&data1);
        }while(Validacao(data1)==0);
    }while(diautil(data1)==0);

    do{
        do{

            lerdata(&data2);
        }while(Validacao(data2)==0);
    }while(diautil(data2)==0);

    data.dia=data1.dia;
    data.mes=data1.mes;
    data.ano=data1.ano;

    while(data.ano<=data2.ano){

        data.ano++;
        c++;
        if(c>=2){
            if(verificaanobissexto(data)){
                cont=cont+366;
            }
            else{
                cont=cont+365;
            }
        }
    }
    while(data.mes!=data2.mes){

        data.mes++;
        if(data.mes>12){
            data.mes=1;
        }
        t=t++;
        if(t>=2){
            max=validadias(data);
            cont=cont+max;
        }
    }
    while(data.dia!=data2.dia){

        if(diautil(data1)){
            cont++;
        }
        data1.dia++;
        if(data1.dia>max){
            data1.dia=1;
        }
    }
    /*
    while(data1.ano<=data2.ano){
        while(data1.mes<data2.mes || data1.mes>data2.mes){
            max=validadias(data1);
            while(data1.dia!=data2.dia){

                if(diautil(data1)){
                    cont++;
                }
                data1.dia++;
                if(data1.dia>max){
                    data1.dia=1;
                }
            }
            data1.mes++;
            if(data1.mes>12){
                data1.mes=1;
            }
            t=t++;
            if(t>=2){
                cont=cont+max;
            }
        }
        data1.ano++;
        c++;
        if(c>=2){
            if(verificaanobissexto(data1)){
                cont=cont+366;
            }
            else{
                cont=cont+365;
            }
        }
    }*/
    printf("%d\n",cont);
    /*switch(data1.mes){

        case 2: mesd1=devolndias(data1)-8;break;
        case 3: mesd1=devolndias(data1)-16;break;
        case 4: mesd1=devolndias(data1)-26;break;
        case 5: mesd1=devolndias(data1)-36;break;
        case 6: mesd1=devolndias(data1)-46;break;
        case 7: mesd1=devolndias(data1)-55;break;
        case 8: mesd1=devolndias(data1)-64;break;
        case 9: mesd1=devolndias(data1)-73;break;
        case 10:mesd1=devolndias(data1)-83;break;
        case 11:mesd1=devolndias(data1)-92;break;
        case 12:mesd1=devolndias(data1)-101;break;
    }
    anod1=diasano(data1);
    total1=data1.dia+mesd1+anod1;

    switch(data2.mes){

        case 2: mesd2=devolndias(data2)-8;break;
        case 3: mesd2=devolndias(data2)-16;break;
        case 4: mesd2=devolndias(data2)-26;break;
        case 5: mesd2=devolndias(data2)-36;break;
        case 6: mesd2=devolndias(data2)-46;break;
        case 7: mesd2=devolndias(data2)-55;break;
        case 8: mesd2=devolndias(data2)-64;break;
        case 9: mesd2=devolndias(data2)-73;break;
        case 10:mesd2=devolndias(data2)-83;break;
        case 11:mesd2=devolndias(data2)-92;break;
        case 12:mesd2=devolndias(data2)-101;break;
    }
    anod2=diasano(data2);
    total2=data2.dia+mesd2+anod2;

    total=total1-total2;

    if(datamaior(data1,data2)==1){

        printf("%d dias\n",total);
    }
    else{

        printf("%d dias\n",-1*total);
    }*/
}
void horariounix(TipoData data1,TipoData data2){

    int mesd1=0,anod1,mesd2=0,anod2,total1=0,total2=0,total,dsegundos;
    int i=0,j;

    data2.dia=1;
    data2.mes=1;
    data2.ano=1970;

    do{

        lerdata(&data1);
    }while(Validacao(data1)==0 && data1.ano<1970);
    fflush(stdin);

    switch(data1.mes){

        case 2: mesd1=devolndias(data1);break;
        case 3: mesd1=devolndias(data1);break;
        case 4: mesd1=devolndias(data1);break;
        case 5: mesd1=devolndias(data1);break;
        case 6: mesd1=devolndias(data1);break;
        case 7: mesd1=devolndias(data1);break;
        case 8: mesd1=devolndias(data1);break;
        case 9: mesd1=devolndias(data1);break;
        case 10:mesd1=devolndias(data1);break;
        case 11:mesd1=devolndias(data1);break;
        case 12:mesd1=devolndias(data1);break;
    }
    if(verificaanobissexto(data1)==1){

    anod1=data1.ano*366;
    }
    else{
        anod1=data1.ano*365;
    }
    total1=data1.dia+mesd1+anod1;
    printf("%d\n",total1);
    fflush(stdin);

    switch(data2.mes){

        case 2: mesd2=devolndias(data2);break;
        case 3: mesd2=devolndias(data2);break;
        case 4: mesd2=devolndias(data2);break;
        case 5: mesd2=devolndias(data2);break;
        case 6: mesd2=devolndias(data2);break;
        case 7: mesd2=devolndias(data2);break;
        case 8: mesd2=devolndias(data2);break;
        case 9: mesd2=devolndias(data2);break;
        case 10:mesd2=devolndias(data2);break;
        case 11:mesd2=devolndias(data2);break;
        case 12:mesd2=devolndias(data2);break;
    }
    if(verificaanobissexto(data2)==1){
        anod2=data2.ano*366;
    }
    else{
        anod2=data2.ano*365;
    }
    total2=data2.dia+mesd2+anod2;
    printf("%d\n",total2);
    total=total1-total2;
    printf("%d\n",total);
    dsegundos=total*86400;

    if(dsegundos>=0){
        printf("%d/%d/%d->%d\n",data1.dia,data1.mes,data1.ano,dsegundos);
    }
    else
        printf("%d/%d/%d->%d\n",data1.dia,data1.mes,data1.ano,-1*dsegundos);


}
void diasemana(TipoVetor *calendario,int j){

    int i,s=0;
    int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char dsemana[7][10];

	strcpy(dsemana[0],"Domingo");
	strcpy(dsemana[1],"Segunda");
	strcpy(dsemana[2],"Terca");
	strcpy(dsemana[3],"Quarta");
	strcpy(dsemana[4],"Quinta");
	strcpy(dsemana[5],"Sexta");
	strcpy(dsemana[6],"Sabado");

	if((calendario->datas[j].ano%400==0) || ((calendario->datas[j].ano%4==0)&&(calendario->datas[j].ano%100!=0))){

        meses[1]=29;
	}
	for(i=0;i<calendario->datas[j].mes-1;i++){

        s=s+meses[i];
	}
	s=s+(calendario->datas[j].dia+calendario->datas[j].ano+(calendario->datas[j].ano/4)-2);
	s=s%7;
	strcpy(calendario->datas[j].eventos[0].notas,dsemana[s]);
}
void eventos(TipoVetor *calendario,int j){

    int i,s=0;
    int meses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char dsemana[7][10];

	strcpy(dsemana[0],"Domingo");
	strcpy(dsemana[1],"Segunda");
	strcpy(dsemana[2],"Terca");
	strcpy(dsemana[3],"Quarta");
	strcpy(dsemana[4],"Quinta");
	strcpy(dsemana[5],"Sexta");
	strcpy(dsemana[6],"Sabado");

	if((calendario->datas[j].ano%400==0) || ((calendario->datas[j].ano%4==0)&&(calendario->datas[j].ano%100!=0))){

        meses[1]=29;
	}
	for(i=0;i<calendario->datas[j].mes-1;i++){

        s=s+meses[i];
	}
	s=s+(calendario->datas[j].dia+calendario->datas[j].ano+(calendario->datas[j].ano/4)-2);
	s=s%7;


    switch (s){

        case 1: if(calendario->datas[j].dia==1 && calendario->datas[j].mes==1){

                    strcpy(calendario->datas[j].eventos[1].notas,"ANO NOVO");
                }
                break;
        case 2: if(calendario->datas[j].dia==1 && calendario->datas[j].mes==5){

                    strcpy(calendario->datas[j].eventos[1].notas,"DIA DO TRABALHADOR");
                }
                if(calendario->datas[j].dia==25 && calendario->datas[j].mes==12){

                    strcpy(calendario->datas[j].eventos[1].notas,"NATAL");
                }
                if(calendario->datas[j].dia==13 && calendario->datas[j].mes==2){

                    strcpy(calendario->datas[j].eventos[1].notas,"CARNAVAL");
                }
                break;
        case 3: if(calendario->datas[j].dia==25 && calendario->datas[j].mes==4){

                    strcpy(calendario->datas[j].eventos[1].notas,"DIA DA LIBERDADE");
                }
                if(calendario->datas[j].dia==15 && calendario->datas[j].mes==8){

                    strcpy(calendario->datas[j].eventos[1].notas,"ASSUNCAO DE NOSSA SENHORA");
                }
                break;
        case 4: if(calendario->datas[j].dia==31 && calendario->datas[j].mes==5){

                    strcpy(calendario->datas[j].eventos[1].notas,"CORPO DE DEUS");
                }
                if(calendario->datas[j].dia==1 && calendario->datas[j].mes==11){

                    strcpy(calendario->datas[j].eventos[1].notas,"DIA DE TODOS OS SANTOS");
                }
                break;
        case 5: if(calendario->datas[j].dia==30 && calendario->datas[j].mes==3){

                    strcpy(calendario->datas[j].eventos[1].notas,"SEXTA-FEIRA SANTA");
                }
                if(calendario->datas[j].dia==5 && calendario->datas[j].mes==10){

                    strcpy(calendario->datas[j].eventos[1].notas,"IMPLANTACAO DA REPUBLICA");
                }
                break;
        case 0: if(calendario->datas[j].dia==1 && calendario->datas[j].mes==4){

                    strcpy(calendario->datas[j].eventos[1].notas,"PASCOA");
                }
                if(calendario->datas[j].dia==10 && calendario->datas[j].mes==6){

                    strcpy(calendario->datas[j].eventos[1].notas,"DIA DE PORTUGAL");
                }
                break;
    }
}
void criacaleendario(TipoVetor *calendario){

    int ano, d,i=0, m=1,max=0;
    int mesi=1;

    do{

        printf("Introduza um ano: \n", ano);
        scanf("%d", &ano);
    }while(ano <= 1900 || ano >= 2090);

    calendario->datas[i].ano= ano;

    while(m <= 12){
        calendario->datas[i].mes= m;
        max=validadias(calendario->datas[i]);
        for(d=1;d<=max;d++){

            calendario->datas[i].dia = d;
            calendario->datas[i].mes= m;
            calendario->datas[i].ano= ano;
            diasemana(calendario,i);
            eventos(calendario,i);
            i++;
        }
        m++;
    }
}
void adicionarevento(TipoVetor *calendario){

    TipoData data;
    char string[30];
    int i,element1,element2,element,l=0,t=0;

    do{

        lerdata(&data);
    }while(Validacao(data)==0 && data.ano!=calendario->datas[0].ano);

    fflush(stdin);

    for(i=0;i<366;i++){
        if(calendario->datas[i].dia==data.dia && calendario->datas[i].mes==data.mes && calendario->datas[i].ano==data.ano){
                do{
                    printf("Introduza um evento para a data %d/%d/%d: ",data.dia,data.mes,data.ano);
                    gets(string);
                    t=strlen(string);
                }while(t>30);

                while(l<5){
                    element=0;
                    if(strlen(calendario->datas[i].eventos[l].notas)==0){

                        strcat(calendario->datas[i].eventos[l].notas,string);
                        break;
                    }
                    l++;
                    element1=strlen(calendario->datas[i].eventos[l].notas);
                    element2=strlen(string);
                    element=element1+element2;
                    if(element<=30){

                        strcat(calendario->datas[i].eventos[l].notas,string);
                        break;
                    }
                    l++;
                }
        }
    }
}
void alterarevento(TipoVetor *calendario){

    TipoData data;
    char st[30];
    int i,j,t;

    do{

        lerdata(&data);
    }while(Validacao(data)==0 && data.ano!=calendario->datas[0].ano);

    for(i=0;i<366;i++){
        if(calendario->datas[i].dia==data.dia && calendario->datas[i].mes==data.mes && calendario->datas[i].ano==data.ano){
            for(j=0;j<5;j++){
                printf("\n%d/%d/%d %s\n",calendario->datas[i].dia,calendario->datas[i].mes ,calendario->datas[i].ano,calendario->datas[i].eventos[j].notas);
            }
            printf("Introduza a linha quer substituir\n");
            scanf("%d",&t);
            fflush(stdin);
            printf("Introduza novo evento\n");
            gets(st);
            strcpy(calendario->datas[i].eventos[t].notas,st);
            printf("\n%d/%d/%d %s\n",calendario->datas[i].dia,calendario->datas[i].mes ,calendario->datas[i].ano,calendario->datas[i].eventos[t].notas);

        }
    }
}
void calcularpascoa(TipoVetor calendario){

    int a = calendario.datas[0].ano%19;
    int b = calendario.datas[0].ano/100;
    int c = calendario.datas[0].ano%100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b - f + 1) / 3;
    int h = (19 * a + b - d - g + 15) % 30;
    int i =  c / 4;
    int k = c % 4;
    int l = (32 + 2 * e + 2 * i - h - k) % 7;
    int m = (a + 11 * h + 22 * l) / 451;
    int mes = (h + l - 7 * m + 114) / 31;
    int dia = ((h + l - 7 * m + 114) % 31) + 1;
    printf("O dia da pascoa do ano %d, é: ",calendario.datas[0].ano);
    printf("%d/%d/%d\n",dia,mes,calendario.datas[0].ano);
}
void calculardiasfestivos(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){
            if(strcmp(calendario.datas[i].eventos[j].notas,"PASCOA")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void mostrareventos(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        printf("\n%d/%d/%d ",calendario.datas[i].dia,calendario.datas[i].mes ,calendario.datas[i].ano);
        for(j=0;j<5;j++){
            if(calendario.datas[i].eventos[j].notas!='\0'){
                printf("%s\n",calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void mostraeventodata(TipoVetor calendario){

    int dia,mes,i,j;

    printf("Introduza o dia\n");
    scanf("%d",&dia);
    fflush(stdin);
    printf("Introduza o mes\n");
    scanf("%d",&mes);

    for(i=0;i<366;i++){
        if(calendario.datas[i].dia==dia && calendario.datas[i].mes==mes){
            for(j=0;j<5;j++){
                printf("%s\n",calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void mostrarinfdata(TipoVetor calendario){

    char st[30];
    int i,j;

    fflush(stdin);
    printf("Introduza um evento\n");
    gets(st);

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){
            if(strcmp(calendario.datas[i].eventos[j].notas,st)==0){
                printf("%d/%d/%d\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano);
            }
        }
    }
}
void listacalendario(TipoVetor calendario){

    int i,j;

    printf("");
}
void feriadomovel(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){

            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DO TRABALHADOR")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"SEXTA-FEIRA SANTA")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"PASCOA")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"CORPO DE DEUS")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void feriadofixo(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){

            if(strcmp(calendario.datas[i].eventos[j].notas,"NATAL")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DA LIBERDADE")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"IMPLANTACAO DA REPUBLICA")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DE PORTUGAL")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void feriadosfestivos(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){

            if(strcmp(calendario.datas[i].eventos[j].notas,"NATAL")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"ANO NOVO")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"CARNAVAL")==0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void outroseventos(TipoVetor calendario){

    int i,j;

    for(i=0;i<366;i++){
        for(j=0;j<5;j++){

            if(strcmp(calendario.datas[i].eventos[j].notas,"NATAL")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"ANO NOVO")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"CARNAVAL")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DA LIBERDADE")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"IMPLANTACAO DA REPUBLICA")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DE PORTUGAL")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"SEXTA-FEIRA SANTA")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"CORPO DE DEUS")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DE TODOS OS SANTOS")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"ASSUNCAO DE NOSSA SENHORA")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"PASCOA")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
            if(strcmp(calendario.datas[i].eventos[j].notas,"DIA DO TRABALHADOR")!=0){
                printf("%d/%d/%d %s\n",calendario.datas[i].dia,calendario.datas[i].mes,calendario.datas[i].ano,calendario.datas[i].eventos[j].notas);
            }
        }
    }
}
void mudancahora(TipoVetor calendario){

    printf("25//3//%d\n",calendario.datas[0].ano);
    printf("28//10//%d\n",calendario.datas[0].ano);
}





