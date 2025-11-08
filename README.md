# ⚽ Campeonato Computacional de Futebol — Parte I

## 📖 Descrição do Projeto
Este projeto implementa a **Parte I** de um sistema simplificado de gerenciamento de dados de um campeonato de futebol. O sistema permite **consultar partidas e resultados**, bem como **obter a tabela de pontuação** dos times. Os dados são armazenados em arquivos CSV e carregados em memória por meio de **Tipos Abstratos de Dados (TADs)**, simulando um banco de dados relacional.

---

## 🚀 Como Executar
### 🧩 Pré-requisitos
- **GCC** (versão 11 ou superior)
- **Make**

### 🪜 Passos de Execução
```bash
# Clone o repositório
git clone [SEU_LINK_DO_REPOSITORIO]
cd [NOME_DO_SEU_REPOSITORIO]

# Preparar os dados
cp dados/partidas_[CENARIO].csv partidas.csv
# Substitua [CENARIO] por: vazio | parcial | completo

# Compilar o projeto
make

# Executar o sistema
./output/main.exe

# Limpar arquivos compilados (opcional)
make clean
```

---

## 🧱 Estrutura de Diretórios
```
.
├── include/
│   ├── time.h
│   ├── partida.h
│   ├── bd_time.h
│   ├── bd_partida.h
│   ├── handle_times_csv.h
│   ├── handle_partidas_csv.h
│   └── find_index.h
│
├── src/
│   ├── main.c
│   ├── time.c
│   ├── partida.c
│   ├── bd_time.c
│   ├── bd_partida.c
│   ├── handle_times_csv.c
│   ├── handle_partidas_csv.c
│   └── find_index.c
│
├── dados/
│   ├── times.csv
│   ├── partidas_vazio.csv
│   ├── partidas_parcial.csv
│   └── partidas_completo.csv
│
├── output/
│   └── main.exe
│
├── Makefile
└── README.md
```

---

## 🧩 Tipos Abstratos de Dados (TADs)
### 1. `Time`
| Campo | Descrição |
|--------|------------|
| ID, Nome | Identificação do time (de `times.csv`) |
| V, E, D | Vitórias, Empates e Derrotas |
| GM, GS | Gols Marcados e Sofridos |
| PG | Pontos Ganhos (3×V + E) |
| S | Saldo de Gols (GM − GS) |

### 2. `Partida`
| Campo | Descrição |
|--------|------------|
| ID | Identificador da partida |
| Time1, Time2 | IDs dos times participantes |
| GolsTime1, GolsTime2 | Gols marcados por cada time |

### 3. `BDTimes`
Gerencia o conjunto de todos os times.
- Carrega os dados de `times.csv`
- Permite buscar, listar e atualizar estatísticas
- Estrutura interna: vetor estático de `Time`

### 4. `BDPartidas`
Gerencia o conjunto de todas as partidas.
- Carrega os dados de `partidas.csv`
- Permite consultas e listagem de resultados
- Estrutura interna: vetor estático de `Partida`

---

## ⚙️ Decisões de Implementação
**Estrutura de Dados:** Vetores estáticos de structs pela simplicidade e previsibilidade de memória.  
**Leitura de CSV:** Uso de `fgets`, `strtok`, `strcspn` e `atoi` para leitura controlada.  
**Busca por Prefixo:** Implementada com `strncmp`, verificando se o nome começa com o prefixo informado.

---

## 📋 Funcionalidades Implementadas
| Opção | Funcionalidade | Descrição |
|--------|----------------|------------|
| 1 | Consultar time | Busca por prefixo do nome e exibe estatísticas completas |
| 2 | Consultar partidas | Busca partidas por prefixo (mandante, visitante ou ambos) |
| 6 | Imprimir tabela | Exibe tabela de classificação por ID |
| Q | Sair | Encerra o sistema |

**Total de pontos de funcionalidade:** 9/9

---

## 🏆 Critérios de Avaliação
| Critério | Valor | Pontuação |
|-----------|--------|------------|
| 1. Funcionalidades | 9 | [PONTUAÇÃO] |
| 2. Lógica e organização | 2 | [PONTUAÇÃO] |
| 3. Documentação (README.md) | 2 | [PONTUAÇÃO] |
| 4. Documentação interna | 1 | [PONTUAÇÃO] |
| **Total P** | **14** | **[PONTUAÇÃO_P]** |
| 5. Robustez (R) | [0,1] | [VALOR_R] |
| 6. Dias de atraso (D) | — | [VALOR_D] |

**Fórmula:**  
```
nota = (1 − (3/2)D − 1) × R × P
```
