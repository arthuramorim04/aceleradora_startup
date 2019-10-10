#include <iostream>
#include <string>

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
    cout << "ID: " << empresas.id_empresa;
    cout << "Nome: " << empresas.nm_empresa;
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

        //CadastroStartupAqui

    } while (opchar != 'S');
    fclose(arquivo_principal);
}

void cadastrar_empresa()
{
    int tamanho = 0;
    system("cls");
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

        //CadastroEmpresaAqui

    } while (opchar != 'S');
    fclose(arquivo_principal);
}
//criar função pra limpar as variaveis no final
void cadastrar_startup_fomentadas()
{
    do
    {
        //empresa
        int id_proc;
        int achou,
            cont = 0;
        system("cls");
        arquivo_principal = fopen("empresa.dat", "r+");
        fseek(arquivo_principal, sizeof(struct dados_empresa), 0);
        cout << "Digite ID da Empresa: ";
        cin >> id_proc;
        while (fread(&empresas, sizeof(empresas), 1, arquivo_principal) == 1)
        {
            if (id_proc == empresas.id_empresa)
            {
                system("CLS");
                id_empresa_temp = empresas.id_empresa;
                nm_empresa_temp = empresas.nm_empresa;
                cont = 1;
            }
        }

        if (cont == 0)
        {
            cout << "Empresa nao Cadastrada\n";
            fclose(arquivo_principal);
        }

        //startup
        id_proc = 0;
        cont = 0;
        system("cls");
        arquivo_principal = fopen("startup.dat", "r+");
        fseek(arquivo_principal, sizeof(struct dados_startup), 0);
        cout << "Digite o ID da Startup: ";
        cin >> id_proc;
        while (fread(&startup, sizeof(startup), 1, arquivo_principal) == 1)
        {
            if (id_proc == startup.id_startup)
            {
                system("CLS");
                id_startup_temp = startup.id_startup;
                nm_startup_temp = startup.nm_startup;
                desc_startup_temp = startup.desc_startup;
                area_startup_temp = startup.area_startup;
                id_equipe_startup_temp = startup.id_equipe_startup;
                nome_integrante_1_temp = startup.nome_integrante_1;
                email_integrante_1_temp = startup.email_integrante_1;
                nome_integrante_2_temp = startup.nome_integrante_2;
                email_integrante_2_temp = startup.email_integrante_2;
                nome_integrante_3_temp = startup.nome_integrante_3;
                email_integrante_3_temp = startup.email_integrante_3;
                dt_criacao_startup_temp = startup.dt_criacao_startup;
                cont = 1;
            }
        }

        if (cont == 0)
        {
            cout << "Startup nao Cadastrada\n";
            fclose(arquivo_principal);
        }
        //relacionar startup e empresa
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
            template_startup();
            template_empresa();

            st_fomentadas.id_empresa = id_empresa_temp;
            st_fomentadas.nm_empresa = nm_empresa_temp;
            st_fomentadas.nm_startup = nm_startup_temp;
            st_fomentadas.id_startup = id_startup_temp;
            cout << "\nDigite o codigo dessa operacao: ";
            cin >> st_fomentadas.cod_startup_acelerada;
            cout << "\n Valor de Investimento: ";
            cin >> st_fomentadas.val_fomentado;
            cout << "Data do investimento: ";
            getline(cin,st_fomentadas.dt_investimento);

            tamanho = tamanho + fwrite(&st_fomentadas, sizeof(struct startup_aceleradas), 1, arquivo_principal);

            cout << "\nCadastrar nova Aceleracao? <s> ou <n>:";
            cin >> opchar;
            opchar = toupper(opchar);

        } while (opchar != 'S');
        fclose(arquivo_principal);
        opchar = 'S';
    } while (opchar != 'S');
    fclose(arquivo_principal);

    fflush(stdin);
}
//funções de consulta

//funções de manipulação de dados

void menu()
{
    cout << "Startup Aceleradora";
    cout << "\n\n1. Cadastrar Empresa";
    cout << "\n2. Cadastrar Startup";
    cout << "\n3. Cadastrar nova Aceleracao";
    cout << "\n4. Consultar Empresa";
    cout << "\n5. Consultar Startup";
    cout << "\n6. Consultar Startup Acelerada";
    cout << "\n7. Editar Empresa";
    cout << "\n8. Editar Startup e Equipe";
    cout << "\n9. Sair do Sistema";

    cin >> op;

    switch (op)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
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
