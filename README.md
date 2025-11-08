
📄 README.md - Campeonato Computacional de Futebol (Parte I)
Este template de README.md está estruturado para atender aos requisitos de documentação interna e de execução solicitados para a Parte I do Trabalho de Programação.

⚽ Campeonato Computacional de Futebol (Parte I)
Este projeto implementa a primeira parte de um sistema simplificado de gerenciamento de dados de um campeonato de futebol, focado na consulta de partidas e resultados e na obtenção da tabela de pontuação.

A entrega simula um banco de dados relacional usando dois arquivos CSV para persistência de dados, que são carregados em memória usando Tipos Abstratos de Dados (TADs).

🚀 Como Executar o Projeto
O programa foi desenvolvido para ser compilado e executado em ambiente Linux Ubuntu 22.04 com GCC 11, conforme recomendado.

Pré-requisitos
Compilador GCC (versão 11 ou superior)

Ferramenta Make

Passos de Execução
Clone o repositório:

Bash
git clone [SEU_LINK_DO_REPOSITORIO]
cd [NOME_DO_SEU_REPOSITORIO]
Preparação dos Dados: Os arquivos de dados para teste (times.csv, partidas_vazio.csv, partidas_parcial.csv, partidas_completo.csv) devem estar disponíveis na estrutura de diretórios do projeto.


➡️ Ação Necessária: Antes de compilar, ajuste o arquivo partidas.csv para um dos cenários de teste disponíveis (vazio, parcial ou completo).

Bash
cp dados/partidas_[CENARIO].csv partidas.csv
# Substitua [CENARIO] por vazio, parcial ou completo.
Compilação do Projeto: Utilize o Makefile fornecido para compilar todos os módulos e gerar o executável.

Bash
make
Execução do Sistema: O executável main.exe será criado no diretório output/.

Bash
./output/main.exe
Limpeza (Opcional): Para remover os arquivos objeto (.o) e o executável, use:

Bash
make clean
🧱 Estrutura do Repositório
O projeto segue uma estrutura modular clara, com o código principal em main.c  e os TADs e serviços distribuídos em diretórios:

.
├── include/
│   ├── time.h
│   └── partida.h
├── src/
│   ├── main.c           # Programa principal e menu.
│   ├── bd_time.c        # Implementação do TAD BDTimes.
│   ├── bd_partida.c     # Implementação do TAD BDPartidas.
│   ├── time.c           # Implementação do TAD Time.
│   └── partida.c        # Implementação do TAD Partida.
├── service/
│   └── handle_file.c    # Funções de manipulação de arquivos CSV.
├── dados/               # Diretório para dados de teste
├── Makefile
└── README.md
➡️ Ação Necessária: Ajuste os nomes dos arquivos .c e .h acima para refletir a sua implementação exata, se for diferente.

🧩 Tipos Abstratos de Dados (TADs)
A modularização é um requisito central do projeto. Os dados são gerenciados por quatro TADs principais:

1. TAD Time
Campo/Estatística	Descrição
ID, Nome	
Dados de identificação lidos de times.csv.

V, E, D	
Vitórias, Empates e Derrotas (calculadas).

GM, GS	
Gols Marcados e Gols Sofridos (acumulados).

PG	
Pontos Ganhos (3V+E) (calculado sob demanda).

S	
Saldo de Gols (GM−GS) (calculado sob demanda).

2. TAD Partida
Campo	Descrição
ID	
Identificador único da partida.

Time1, Time2	
IDs dos times participantes.

GolsTime1, GolsTime2	
Quantidade de gols marcados.

3. TAD BDTimes

Responsabilidade: Gerencia a coleção de todos os TADs Time.


Ações: Carregar dados iniciais de times.csv , buscar, listar e atualizar estatísticas de um time.

Estrutura Interna: Vetor estático de structs Time* (Ponteiros para TAD Time). [Ajuste se usar outra estrutura]

4. TAD BDPartidas

Responsabilidade: Gerencia a coleção de todos os TADs Partida.


Ações: Carregar dados iniciais de partidas.csv , fornecer acesso estruturado aos resultados para cálculo de estatísticas.

Estrutura Interna: Vetor estático de structs Partida* (Ponteiros para TAD Partida). [Ajuste se usar outra estrutura]

⚙️ Decisões de Implementação
Aqui você deve detalhar as escolhas técnicas cruciais feitas durante o desenvolvimento.

1. Estrutura de Dados
Decisão: O TAD BDTimes e o TAD BDPartidas utilizam vetores estáticos de ponteiros para as structs Time e Partida.


Justificativa: Essa escolha é baseada na simplicidade de implementação e na previsibilidade do consumo de memória, conforme sugerido pelo enunciado para esta primeira parte.

2. Leitura de Arquivos CSV
Decisão: Para ler os arquivos CSV linha por linha e token por token, as funções fgets, strcspn, strtok e atoi foram utilizadas.


Justificativa: Esta combinação de funções C padrão oferece controle granular sobre a leitura da linha, tratamento de strings e conversão segura para tipos inteiros, o que é fundamental para a robustez.

3. Implementação da Busca (Prefixos)
Decisão: A busca por nome de time (para opções 1 e 2 do menu) é realizada comparando o prefixo fornecido pelo usuário com o nome completo do time, utilizando a função strncmp (ou similar).


Justificativa: Isso garante que a funcionalidade "suporte a pesquisa por prefixo", permitindo que, por exemplo, "NET" encontre "NETunos".

➡️ Ação Necessária: Complete esta seção com suas próprias decisões, como:

Como você lidou com a alocação dinâmica (ex: malloc) dentro dos TADs?

Detalhes sobre a modularização (como os TADs BDPartidas e BDTimes se comunicam para o cálculo das estatísticas).

📋 Funcionalidades Implementadas (Parte I)
As seguintes funcionalidades, requeridas para esta entrega, foram implementadas e testadas:

Opção	Funcionalidade	Descrição	Pontos (Critério 1)
1	Consultar time	
Permite buscar um time por prefixo do nome e exibe todas as suas estatísticas (V, E, D, GM, GS, S, PG).

3
2	Consultar partidas	
Permite buscar partidas por prefixo do nome do time mandante, visitante ou ambos.

3
6	Imprimir tabela	
Exibe a tabela completa de classificação com todas as estatísticas, ordenada pelo ID do time (sem ordenação por PG nesta parte).

3
Q	Sair	
Encerra a execução do sistema.

-

Total de Pontos de Funcionalidade: 9/9 

🏆 Critérios de Avaliação (Pontuação)
Critério	Valor	Pontuação Obtida
1. Funcionalidades (9 pontos)	9	[PONTUAÇÃO]
2. Lógica e organização (2 pontos)	2	[PONTUAÇÃO]
3. Documentação README.md (2 pontos)	2	[PONTUAÇÃO]
4. Documentação Interna (1 ponto)	1	[PONTUAÇÃO]
Total P (Critérios 1-4)	14	[PONTUAÇÃO_P]
5. Robustez (R)	[0, 1]	[VALOR_R]
6. Dias de Atraso (D)	-	[VALOR_D]

Fórmula da Nota Final: nota=(1− 
31
2 
D
 −1
​
 )×R×P 

➡️ Ação Necessária: Preencha os campos [PONTUAÇÃO], [PONTUAÇÃO_P], [VALOR_R] e [VALOR_D] após a finalização e teste do projeto.
