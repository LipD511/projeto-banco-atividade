#ifndef MEUBANCO_H
#define MEUBANCO_H

#define TIPO_CORRENTE          1
#define TIPO_SALARIO           2
#define TIPO_POUPANCA          3

#define MAX_NOME               100
#define MAX_HISTORICO          512
#define QTD_FINALISTAS_SORTEIO 5

typedef struct {
    char nome[MAX_NOME];
    int numero_base;               
    int tipo_conta;                
    double saldo;                 
    double saldo_corrente;         
    double saldo_salario;          
    double saldo_poupanca;         
    int possui_corrente;          
    int possui_salario;            
    int possui_poupanca;           
    int possui_emprestimo;         
    int comprou_titulo;            
    char historico[MAX_HISTORICO];
} Carteira;

typedef struct {
    Carteira *clientes;
    int quantidade_clientes;
    int banco_aberto;              
    int proximo_numero;            
} Banco;


void inicializar_banco(Banco *banco);
void abrir_banco(Banco *banco);
void consultar_historico(const Banco *banco);
void efetuar_sorteio(Banco *banco);
void liberar_banco(Banco *banco);


void acessar_conta_cliente(Banco *banco);
void registrar_evento_historico(Carteira *cliente, const char *descricao_evento);
void atualizar_saldo_total(Carteira *cliente);
int validar_combinacao_contas(int possui_corrente, int possui_salario);
double calcular_limite_emprestimo(const Carteira *cliente);
int apto_titulo_capitalizacao(const Carteira *cliente);
void verificar_alerta_saldo_negativo(const Carteira *cliente);


long long soma_fibonacci(int quantidade_termos);
int eh_primo(long long numero);
int escolher_vencedor_fibonacci(const Banco *banco, const int indices_finalistas[QTD_FINALISTAS_SORTEIO]);

#endif
