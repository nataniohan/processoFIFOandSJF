#include <iostream>
#include <vector>
#include <cstdlib> // Para usar rand()
#include <ctime>   // Para usar time()


using namespace std;
class ProcessoFIFO {
public:
    int id;
    int tempo;
    ProcessoFIFO();
    ProcessoFIFO(int id, int tempo);

    int getId() const;
    int getTempo() const;
};

ProcessoFIFO::ProcessoFIFO() {
    ////////
};

ProcessoFIFO::ProcessoFIFO(int id, int tempo) {
    this->id = id;
    this->tempo = tempo;
};

int ProcessoFIFO::getId() const {
    return id;
};
int ProcessoFIFO::getTempo() const {
    return tempo;
};

class GerenciadorProcessos {
private:
    vector<ProcessoFIFO> processos;

public:
    void inserirProcessos(int quantidade) {
        srand(time(0)); // Inicializa a semente do gerador de números aleatórios
        for (int i = 1; i <= quantidade; ++i) {
            int tempo = std::rand() % 100 + 1; // Gera um tempo aleatório entre 1 e 100
            processos.emplace_back(ProcessoFIFO(i, tempo));
        }
    }

    void excluirUltimoProcesso() {
        if (!processos.empty()) {
            processos.pop_back();
        }
        else {
            cout << "Nenhum processo para excluir!" << endl;
        }
    }

    double calcularMediaTempo() const {
        if (processos.empty()) {
            return 0.0;
        }

        int somaTempo = 0;
        for (const auto& processo : processos) {
            somaTempo += processo.getTempo();
        }

        return (somaTempo) / processos.size();
    }

    void exibirProcessos() const {
        for (const auto& processo : processos) {
            cout << "ID: " << processo.getId() << ", Tempo: " << processo.getTempo() << endl;
        }
    }
};

int main() {
    GerenciadorProcessos gerenciador;

    int quantidade;
    cout << "Informe a quantidade de processos: ";
    cin >> quantidade;

    gerenciador.inserirProcessos(quantidade);

    cout << "Processos inseridos:" << endl;
    gerenciador.exibirProcessos();

    double mediaTempo = gerenciador.calcularMediaTempo();
    cout << "Media de tempo dos processos: " << mediaTempo << endl;

    cout << "Excluindo o ultimo processo..." << endl;
    gerenciador.excluirUltimoProcesso();

    cout << "Processos apos exclusao do ultimo:" << endl;
    gerenciador.exibirProcessos();

    return 0;
}