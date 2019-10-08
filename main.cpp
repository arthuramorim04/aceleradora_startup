#include <iostream>
#include <string>

using namespace std;

// Variaveis Globais

int op, opc;

struct dados_startup{
    int id_startup;
    string nm_startup;
    string desc_startup;
    char area_startup[40];
    int id_equipe_startup;
    string nome_integrante_1;
    string email_integrante_1;
    string nome_integrante_2;
    string email_integrante_2;
    string nome_integrante_3;
    string email_integrante_3;
    string  dt_criacao_startup;

}startup;

struct dados_empresa{
    int id_empresa;
    string nm_empresa;
    float val_fomento; 

}empresa;

struct startup_aceleradas{
    int cod_startup_acelerada;
    int id_startup;
    string nm_startup;
    int empresa;
    string nm_empresa;
    float val_fomentado;
}st_fomentadas;

//area de arquivos

FILE *arquivo_principal;
FILE *arquivo_temporario;

//funções de criação de arquivos

void criar_arquivo_startup(){
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
  if ((arquivo_principal = fopen("startup.dat", "a")) == NULL)
  {
    system("cls");
    cout << "Erro de criacao de arquivo";
    return;
  }
  fclose(arquivo_principal);
}

void criar_arquivo_empresa(){
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
  if ((arquivo_principal = fopen("empresa.dat", "a")) == NULL)
  {
    system("cls");
    cout << "Erro de criacao de arquivo";
    return;
  }
  fclose(arquivo_principal);
}

void criar_arquivo_startup_aceleradas(){
    // a verifica se o arquivo existe, se exite abre, se nao cria, retorna null caso ocorra erro
  if ((arquivo_principal = fopen("startups_aceleradas.dat", "a")) == NULL)
  {
    system("cls");
    cout << "Erro de criacao de arquivo";
    return;
  }
  fclose(arquivo_principal);
}

void criar_arquivo_temporario(){
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


//funções de consulta


//funções de manipulação de dados

void menu(){
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
    case 1:        break;
    case 2:        break;
    case 3:        break;
    case 4:        break;
    case 5:        break;
    case 6:        break;
    case 7:        break;
    case 8:        break;
    case 9:        exit;
     }
}

main(){

    criar_arquivo_empresa();
    criar_arquivo_startup();
    criar_arquivo_startup_aceleradas();

   do
   {
       menu();
   } while (opc != 9);
   
}
