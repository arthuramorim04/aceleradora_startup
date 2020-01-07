#include <iostream>
#include <string>
#include <string.h>

using namespace std;
//Variaveis Temporarias Empresas
int id_empresa_temp;
string nm_empresa_temp;
float val_fomento_temp;

//Variaveis Temporarias Startup
int id_startup_temp;
string nm_startup_temp;
string desc_startup_temp;
string area_startup_temp;
int id_equipe_startup_temp;
string nome_integrante_1_temp;
string email_integrante_1_temp;
string nome_integrante_2_temp;
string email_integrante_2_temp;
string nome_integrante_3_temp;
string email_integrante_3_temp;
string dt_criacao_startup_temp;

//Variaveis Temporarias Startup Acelerada

int id_st_acelerada_temp;
int id_acelerada_startup_temp;
int id_acelerada_empresa_temp;
float val_acelerada_fomento_temp;
string dt_acelerada_investimento;
string nm_acelerada_startup_temp;
string nm_acelerada_empresa_temp;

// Variaveis Globais

int op, opc;
char opchar;

struct dados_startup
{
    int id_startup;
    string nm_startup;
    string desc_startup;
    string area_startup;
    int id_equipe_startup;
    string nome_integrante_1;
    string email_integrante_1;
    string nome_integrante_2;
    string email_integrante_2;
    string nome_integrante_3;
    string email_integrante_3;
    string dt_criacao_startup;

} startup;

struct dados_empresa
{
    int id_empresa;
    string nm_empresa;

} empresas;

struct startup_aceleradas
{
    int cod_startup_acelerada;
    int id_startup;
    string nm_startup;
    int id_empresa;
    string nm_empresa;
    float val_fomentado;
    string dt_investimento;
} st_fomentadas;

//area de arquivos

FILE *arquivo_principal;
FILE *arquivo_temporario;

//templates

void template_startup_acelerada()
{

    cout << "\n** Informacoes da Aceleracao **\n";
    cout << "\nCodigo de aceleracao: " << st_fomentadas.cod_startup_acelerada;
    cout << "\nID empresa: " << st_fomentadas.id_empresa;
    cout << "\nNome empresa" << st_fomentadas.nm_empresa;
    cout << "\nID startup: " << st_fomentadas.id_startup;
    cout << "\nNome startup" << st_fomentadas.nm_startup;
    cout << "\nValor Investido: " << st_fomentadas.val_fomentado;
    cout << "\nData do investimento: " << st_fomentadas.dt_investimento;
}

void template_startup()
{
    cout << "\n** Startup **\n";
    cout << "\nID: " << startup.id_startup;
    cout << "\nNome: " << startup.nm_startup;
    cout << "\narea_startup" << startup.area_startup;
    cout << "\nDescricao: " << startup.desc_startup;
    cout << "\nInicio das Atividades: " << startup.dt_criacao_startup;
    cout << "\n** Equipe **\n";
    cout << "\nID Equipe: " << startup.id_equipe_startup;
    cout << "\nMembro 1: " << startup.nome_integrante_1;
    cout << "\nEmail 1: " << startup.email_integrante_1;
    cout << "\nMembro 2: " << startup.nome_integrante_2;
    cout << "\nEmail 2: " << startup.email_integrante_2;
    cout << "\nMembro 3: " << startup.nome_integrante_3;
    cout << "\nEmail 3: " << startup.email_integrante_3;
}

void template_empresa()
{
    cout << "\n** Empresa **\n";
    cout << "\nID: " << empresas.id_empresa;
    cout << "\nNome: " << empresas.nm_empresa;
}

//funções de criação de arquivos

void criar_arquivo_startup()
{
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
    if ((arquivo_principal = fopen("startup.dat", "a")) == NULL)
    {
        system("cls");
        cout << "Erro de criacao de arquivo";
        return;
    }
    fclose(arquivo_principal);
}

void criar_arquivo_empresa()
{
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
    if ((arquivo_principal = fopen("empresa.dat", "a")) == NULL)
    {
        system("cls");
        cout << "Erro de criacao de arquivo";
        return;
    }
    fclose(arquivo_principal);
}

void criar_arquivo_startup_aceleradas()
{
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
    if ((arquivo_principal = fopen("startups_aceleradas.dat", "a")) == NULL)
    {
        system("cls");
        cout << "Erro de criacao de arquivo";
        return;
    }
    fclose(arquivo_principal);
}

void criar_arquivo_temporario()
{
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
    if ((arquivo_temporario = fopen("temporario.dat", "a")) == NULL)
    {
        system("cls");
        cout << "Erro de criacao de arquivo";
        return;
    }
    fclose(arquivo_temporario);
}

//funções de cadastro
void cadastrar_startup()
{
    int tamanho = 0;
    system("cls");
    arquivo_principal = fopen("startup.dat", "r+");
    rewind(arquivo_principal);
    do
    {
        fread(&startup, sizeof(startup), 1, arquivo_principal);
        tamanho++;
    } while (!feof(arquivo_principal));
    fseek(arquivo_principal, sizeof(startup), tamanho);
    do
    {
        fflush(stdin);
        system("cls");
        cout << "\nDigite o nome da StartUp:";
        getline(cin, startup.nm_startup);
        fflush(stdin);
        cout << "Digite a ID da StartUp:";
        cin >> startup.id_startup;
        fflush(stdin);
        cout << "Digite a area da StartUp:";
        getline(cin, startup.desc_startup);
        fflush(stdin);
        cout << "Digite a data de criacao da StartUp:";
        getline(cin, startup.dt_criacao_startup);
        fflush(stdin);
        cout << "Digite a ID da Equipe StartUp:";
        cin >> startup.id_equipe_startup;
        fflush(stdin);
        cout << "Digite o email do integrante 1:";
        getline(cin, startup.email_integrante_1);
        fflush(stdin);
        cout << "Digite o email do integrante 2:";
        getline(cin, startup.email_integrante_2);
        fflush(stdin);
        cout << "Digite o email do integrante 3:";
        getline(cin, startup.email_integrante_3);

        cout << "\nRealizar novo cadastro?  <s> ou <n>:";
        cin >> opchar;
        opchar = toupper(opchar);

    } while (opchar == 'S');

    fclose(arquivo_principal);
}

//Cadastra Empresa
void cadastra_empresa()
{
    system("cls");
    int tamanho = 0;
    arquivo_principal = fopen("empresa.dat", "r+");
    rewind(arquivo_principal);
    do
    {
        fread(&empresas, sizeof(empresas), 1, arquivo_principal);
        tamanho++;
    } while (!feof(arquivo_principal));
    fseek(arquivo_principal, sizeof(empresas), tamanho);
    do
    {
        system("cls");
        cout << "\nDigite a ID da empresa:";
        cin >> empresas.id_empresa;
        fflush(stdin);
        cout << "\nDigite o nome da empresa:";
        getline(cin, empresas.nm_empresa);

        tamanho = tamanho + fwrite(&empresas, sizeof(struct dados_empresa), 1, arquivo_principal);

        cout << "\nRealizar novo cadastro?  <s> ou <n>:";
        cin >> opchar;
        opchar = toupper(opchar);

    } while (opchar == 'S');

    fclose(arquivo_principal);
}

// Consulta Empresa
void consulta_id_empresa()
{
    int procura_id_empresa;
    int achou;
    int cont = 0;
    system("cls");

    arquivo_principal = fopen("empresa.dat", "r+");
    fseek(arquivo_principal, sizeof(struct dados_empresa), 0);
    cout << "Digite a ID da empresa:";
    cin >> procura_id_empresa;
    while (fread(&empresas, sizeof(empresas), 1, arquivo_principal) == 1)
    {
        if (procura_id_empresa == empresas.id_empresa)
        {
            template_empresa();
            system("pause");
            cout << "\nPressione qualquer tecla para voltar ao menu inicial";
            getchar();
            cont = 1;
        }
    }

    if (cont == 0)
    {
        cout << "ID nao cadastrada\n";
        cout << "\nRealizar novo cadastro?  <s> ou <n>:";
        cin >> opchar;
        opchar = toupper(opchar);
        if (opchar = 'S')
        {
            cadastra_empresa();
        }
    }
}

//criar função pra limpar as variaveis no final

void cadastrar_startup_fomentadas()
{
        system("cls");
        int tamanho = 0;
        arquivo_principal = fopen("startups_aceleradas.dat", "r+");
        rewind(arquivo_principal);
        do
        {
            fread(&st_fomentadas, sizeof(startup_aceleradas), 1, arquivo_principal);
            tamanho++;
        } while (!feof(arquivo_principal));
        fseek(arquivo_principal, sizeof(st_fomentadas), tamanho);
        do
        {
            cout << "\nDigite o ID da Empresa: ";        
            cin >> st_fomentadas.id_empresa;
            cout << "\nDigite o ID da Startup: ";
            cin >> st_fomentadas.id_startup;
            cout << "\nDigite o ID dessa operacao: ";
            cin >> st_fomentadas.cod_startup_acelerada;
            cout << "\nValor de Investimento: ";
            cin >> st_fomentadas.val_fomentado;

            tamanho = tamanho + fwrite(&st_fomentadas, sizeof(struct startup_aceleradas), 1, arquivo_principal);
            
            cout << "\nRealizar novo cadastro?  <s> ou <n>:";
            cin >> opchar;
            opchar = toupper(opchar);

        } while (opchar == 'S' && opchar == 'N');
        fclose(arquivo_principal); 
    fflush(stdin);
}
//funções de consulta

void consulta_startup_acelerada()
{
    int id_procurar, achou, cont;
    cont = 0;

    system("cls");

    arquivo_principal = fopen("startups_aceleradas.dat", "r+");
    fseek(arquivo_principal, sizeof(struct startup_aceleradas), 0);
    cout << "digite o ID da aceleracao: ";
    cin >> id_procurar;
    while (fread(&st_fomentadas, sizeof(startup_aceleradas), 1, arquivo_principal) == 1)
    {
        if (id_procurar == st_fomentadas.cod_startup_acelerada)
        {
            template_startup_acelerada();
            cont = 1;
        }
    }

    if (cont == 0)
    {
        cout << "ID nao cadastrado!";
        getwchar();
    }
}

void menu()
{
    system("cls");
    cout << "Startup Aceleradora";
    cout << "\n\n1. Cadastrar Empresa";
    cout << "\n2. Cadastrar Startup";
    cout << "\n3. Cadastrar nova Aceleracao";
    cout << "\n4. Consultar Empresa";
    cout << "\n5. Consultar Startup";
    cout << "\n6. Consultar Startup Acelerada";
    cout << "\n7. Editar Empresa";
    cout << "\n8. Editar Startup e Equipe";
    cout << "\n9. Sair do Sistema\n\n";

    cin >> op;

    switch (op)
    {
    case 1:
        cadastra_empresa();
        break;
    case 2:
        cadastrar_startup();
        break;
    case 3:
        cadastrar_startup_fomentadas();
        break;
    case 4:
    consulta_id_empresa();
        break;
    case 5:
        break;
    case 6:
        consulta_startup_acelerada();
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        exit;
    }
}

main()
{

    criar_arquivo_empresa();
    criar_arquivo_startup();
    criar_arquivo_startup_aceleradas();

    do
    {
        menu();
    } while (opc != 9);
}