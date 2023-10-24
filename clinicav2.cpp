#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente
{
public:
  string nome;
  string cpf;
  string dataNascimento;
};

class Medico
{
public:
  string nome;
  string crm;
  string especialidade;
};

class ClinicaSemDodoi
{
private:
  vector<Paciente> pacientes;
  vector<Medico> medicos;

public:
  void incluirPaciente()
  {
    Paciente paciente;
    cout << "Nome do paciente: ";
    cin.ignore();
    getline(cin, paciente.nome);
    cout << "CPF do paciente: ";
    cin >> paciente.cpf;
    cout << "Data de nascimento do paciente: ";
    cin.ignore();
    getline(cin, paciente.dataNascimento);
    pacientes.push_back(paciente);
    cout << "Paciente incluído com sucesso." << endl;
  }

  void excluirPaciente()
  {
    string cpfExcluir;
    cout << "CPF do paciente a ser excluído: ";
    cin >> cpfExcluir;
    for (size_t i = 0; i < pacientes.size(); i++)
    {
      if (pacientes[i].cpf == cpfExcluir)
      {
        pacientes.erase(pacientes.begin() + i);
        cout << "Paciente excluído com sucesso." << endl;
        return;
      }
    }
    cout << "Paciente nao encontrado." << endl;
  }

  void alterarPaciente()
  {
    string cpfAlterar;
    cout << "CPF do paciente a ser alterado: ";
    cin >> cpfAlterar;
    for (Paciente &paciente : pacientes)
    {
      if (paciente.cpf == cpfAlterar)
      {
        cout << "Nome atual: " << paciente.nome << endl;
        cout << "Novo nome (ou pressione Enter para manter o mesmo): ";
        cin.ignore();
        getline(cin, paciente.nome);
        cout << "Data de nascimento atual: " << paciente.dataNascimento << endl;
        cout << "Nova data de nascimento (ou pressione Enter para manter a mesma): ";
        cin.ignore();
        getline(cin, paciente.dataNascimento);
        cout << "Paciente alterado com sucesso." << endl;
        return;
      }
    }
    cout << "Paciente nao encontrado." << endl;
  }

  void listarPacientes()
  {
    cout << "\nLista de Pacientes:" << endl;
    for (const Paciente &paciente : pacientes)
    {
      cout << "Nome: " << paciente.nome << endl;
      cout << "CPF: " << paciente.cpf << endl;
      cout << "Data de nascimento: " << paciente.dataNascimento << endl;
      cout << "--------------------" << endl;
    }
  }

  void localizarPaciente()
  {
    string cpfLocalizar;
    cout << "CPF do paciente a ser localizado: ";
    cin >> cpfLocalizar;
    for (const Paciente &paciente : pacientes)
    {
      if (paciente.cpf == cpfLocalizar)
      {
        cout << "Nome: " << paciente.nome << endl;
        cout << "CPF: " << paciente.cpf << endl;
        cout << "Data de nascimento: " << paciente.dataNascimento << endl;
        return;
      }
    }
    cout << "Paciente nao encontrado." << endl;
  }

  void incluirMedico()
  {
    Medico medico;
    cout << "Nome do medico: ";
    cin.ignore();
    getline(cin, medico.nome);
    cout << "CRM do medico: ";
    cin >> medico.crm;
    cout << "Especialidade do medico: ";
    cin.ignore();
    getline(cin, medico.especialidade);
    medicos.push_back(medico);
    cout << "Medico incluido com sucesso." << endl;
  }

  void excluirMedico()
  {
    string crmExcluir;
    cout << "CRM do medico a ser excluído: ";
    cin >> crmExcluir;
    for (size_t i = 0; i < medicos.size(); i++)
    {
      if (medicos[i].crm == crmExcluir)
      {
        medicos.erase(medicos.begin() + i);
        cout << "Medico excluido com sucesso." << endl;
        return;
      }
    }
    cout << "Medico nao encontrado." << endl;
  }

  void alterarMedico()
  {
    string crmAlterar;
    cout << "CRM do medico a ser alterado: ";
    cin >> crmAlterar;
    for (Medico &medico : medicos)
    {
      if (medico.crm == crmAlterar)
      {
        cout << "Nome atual: " << medico.nome << endl;
        cout << "Novo nome (ou pressione Enter para manter o mesmo): ";
        cin.ignore();
        getline(cin, medico.nome);
        cout << "Especialidade atual: " << medico.especialidade << endl;
        cout << "Nova especialidade (ou pressione Enter para manter a mesma): ";
        cin.ignore();
        getline(cin, medico.especialidade);
        cout << "Medico alterado com sucesso." << endl;
        return;
      }
    }
    cout << "Medico nao encontrado." << endl;
  }

  void listarMedicos()
  {
    cout << "\nLista de Medicos:" << endl;
    for (const Medico &medico : medicos)
    {
      cout << "Nome: " << medico.nome << endl;
      cout << "CRM: " << medico.crm << endl;
      cout << "Especialidade: " << medico.especialidade << endl;
      cout << "--------------------" << endl;
    }
  }

  void localizarMedico()
  {
    string crmLocalizar;
    cout << "CRM do medico a ser localizado: ";
    cin >> crmLocalizar;
    for (const Medico &medico : medicos)
    {
      if (medico.crm == crmLocalizar)
      {
        cout << "Nome: " << medico.nome << endl;
        cout << "CRM: " << medico.crm << endl;
        cout << "Especialidade: " << medico.especialidade << endl;
        return;
      }
    }
    cout << "Medico nao encontrado." << endl;
  }

  void menuPrincipal()
  {
    while (true)
    {
      cout << "\nMenu Principal" << endl;
      cout << "1. Gestao de Pacientes" << endl;
      cout << "2. Gestao de Medicos" << endl;
      cout << "0. Sair" << endl;

      int opcao;
      cin >> opcao;

      switch (opcao)
      {
      case 1:
        menuPacientes();
        break;

      case 2:
        menuMedicos();
        break;

      case 0:
        cout << "Saindo do programa." << endl;
        return;

      default:
        cout << "Opcao invalida. Tente novamente." << endl;
      }
    }
  }

  void menuPacientes()
  {
    while (true)
    {
      cout << "\nMenu de Gestao de Pacientes" << endl;
      cout << "1. Incluir" << endl;
      cout << "2. Excluir" << endl;
      cout << "3. Alterar (apenas por CPF)" << endl;
      cout << "4. Listar" << endl;
      cout << "5. Localizar (por CPF)" << endl;
      cout << "0. Voltar" << endl;

      int opcao;
      cin >> opcao;

      switch (opcao)
      {
      case 1:
        incluirPaciente();
        break;

      case 2:
        excluirPaciente();
        break;

      case 3:
        alterarPaciente();
        break;

      case 4:
        listarPacientes();
        break;

      case 5:
        localizarPaciente();
        break;

      case 0:
        cout << "Voltando para o menu anterior." << endl;
        return;

      default:
        cout << "Opcao invalida. Tente novamente." << endl;
      }
    }
  }

  void menuMedicos()
  {
    while (true)
    {
      cout << "\nMenu de Gestao de Medicos" << endl;
      cout << "1. Incluir" << endl;
      cout << "2. Excluir" << endl;
      cout << "3. Alterar (apenas por CRM)" << endl;
      cout << "4. Listar" << endl;
      cout << "5. Localizar (por CRM)" << endl;
      cout << "0. Voltar" << endl;

      int opcao;
      cin >> opcao;

      switch (opcao)
      {
      case 1:
        incluirMedico();
        break;

      case 2:
        excluirMedico();
        break;

      case 3:
        alterarMedico();
        break;

      case 4:
        listarMedicos();
        break;

      case 5:
        localizarMedico();
        break;

      case 0:
        cout << "Voltando para o menu anterior." << endl;
        return;

      default:
        cout << "Opcao invalida. Tente novamente." << endl;
      }
    }
  }
};

int main()
{
  system("cls");
  ClinicaSemDodoi clinica;
  clinica.menuPrincipal();

  return 0;
}
