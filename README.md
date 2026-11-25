# Sistema de Gerenciamento de Senhas de Atendimento Clínico

## Objetivo

Este projeto foi desenvolvido em linguagem C para controlar as senhas de atendimento de uma clínica.

O sistema permite cadastrar pacientes, identificar automaticamente a categoria de atendimento, gerar uma senha e controlar a ordem das chamadas.

As regras de prioridade utilizadas são as definidas na proposta da atividade.

---

## Funcionalidades

O programa possui:

- Cadastro de pacientes;
- Classificação automática;
- Geração de senhas;
- Fila de atendimento;
- Consulta da próxima senha;
- Chamada de paciente;
- Finalização de atendimento;
- Painel de atendimento;
- Contagem de pacientes aguardando;
- Menu interativo.

---

## Categorias

### Urgente

Paciente com idade superior a 80 anos.

Exemplo:

```text
U001
U002
U003
```

### Preferencial

Paciente que seja:

- Gestante;
- Lactante;
- Pessoa com necessidade especial;
- Pessoa com condição de obesidade;
- Mulher com 60 anos ou mais;
- Homem com 65 anos ou mais.

Exemplo:

P001
P002
P003


### Normal

Paciente que não possui nenhuma das condições anteriores.

Exemplo:

N001
N002
N003

A ordem de atendimento é:

Urgente
Preferencial
Normal

Dentro de cada categoria, a ordem de cadastro é respeitada.

---

## Menu

O programa possui o seguinte menu:

1 - Cadastrar paciente
2 - Consultar proxima senha
3 - Chamar paciente
4 - Finalizar atendimento
5 - Mostrar painel
6 - Sair

---

## Funções utilizadas

### `menu()`

Mostra as opções do sistema.

### `cadastrarPaciente()`

Recebe os dados do paciente e realiza seu cadastro.

### `classificarPaciente()`

Define se o paciente é Normal, Preferencial ou Urgente.

### `gerarSenha()`

Gera a senha de acordo com a categoria.

### `proximaSenha()`

Procura o próximo paciente que deve ser chamado.

### `consultarProxima()`

Mostra a próxima senha sem realizar a chamada.

### `chamarPaciente()`

Realiza a chamada do próximo paciente.

### `finalizarAtendimento()`

Finaliza o atendimento do paciente que está sendo atendido.

### `mostrarPainel()`

Mostra as senhas aguardando e a quantidade de pacientes por categoria.

---

## Estruturas utilizadas

O projeto utiliza:

- `struct`;
- vetor;
- funções;
- `if` e `else`;
- `for`;
- `do while`;
- `switch`;
- ponteiros;
- strings.

---

## Compilação

Para compilar usando GCC:

```bash
gcc main.c -o clinica
```

No Linux ou macOS:

```bash
./clinica
```

No Windows:

```bash
clinica.exe
```

---

## Exemplo

Cadastro de um paciente normal:

```text
Genero (F/M): M
Idade: 25
E lactante? (S/N): N
Possui necessidade especial? (S/N): N
Possui condicao de obesidade? (S/N): N

Paciente cadastrado!
Categoria: Normal
Senha: N001
```

Cadastro de uma paciente gestante:

```text
Genero (F/M): F
E gestante? (S/N): S

Paciente cadastrado!
Categoria: Preferencial
Senha: P001
```

Cadastro de paciente com mais de 80 anos:

```text
Genero (F/M): M
Idade: 85

Paciente cadastrado!
Categoria: Urgente
Senha: U001
```

Se as três senhas estiverem aguardando:

```text
N001
P001
U001
```

a próxima senha chamada será:

```text
U001
```

Depois:

```text
P001
```

e por último:

```text
N001
```

---

## Limitações

Os dados ficam armazenados somente enquanto o programa está aberto.

Ao encerrar o programa, os dados são perdidos.

O sistema permite cadastrar até 100 pacientes durante uma execução.

---

## Autor

Projeto desenvolvido para avaliação acadêmica de programação em linguagem C.
