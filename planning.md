# Planejamento do Projeto FDF

## Objetivo

Criar um modelo de wireframe simples de uma paisagem 3D, representado por segmentos de linha que conectam vários pontos (x, y, z). O programa deve renderizar o modelo em uma projeção isométrica e exibir a imagem em uma janela.

## Checklist

- [x] Configurar `libft`
- [x] Configurar `get_next_line`, `ft_printf`
- [x] Configurar MiniLibX
- [x] Configurar biblioteca math
- [x] Configurar Makefile
- [ ] Implementar leitura do arquivo .fdf
- [ ] Armazenar dados em estrutura apropriada
- [ ] Implementar projeção isométrica
- [ ] Desenhar wireframe
- [ ] Criar janela com MiniLibX
- [ ] Exibir imagem na janela
- [ ] Implementar interação com o usuário

## Fases e Etapas

### Fase 1: Preparação do Ambiente

#### Etapa 1.1: Instalação de Dependências
- **Objetivo:** Garantir que todas as bibliotecas e ferramentas necessárias estejam instaladas.
- **Passos:**
  - **Configurar a `libft`:**
    - A `libft` é uma biblioteca de funções úteis desenvolvido em projetos anteriores.
  - **Configurar a `get_next_line`, `ft_printf`, `etc`:**
    - A `get_next_line` é uma função que lê uma linha por vez de um arquivo.
    - A `ft_printf` é uma função que imprime dados formatados na tela.
  - **Configurar a MiniLibX:**
    - A MiniLibX é uma biblioteca gráfica simples usada para criar janelas, desenhar pixels, linhas e imagens.
  - **Configurar a biblioteca math:**
    - A biblioteca math é usada para funções matemáticas avançadas.
    - **Comando:** `sudo apt-get install libm-dev` (para sistemas baseados em Debian).

#### Etapa 1.2: Configuração do Makefile
- **Objetivo:** Criar um Makefile para compilar os arquivos fonte.
- **Passos:**
  - **Configurar as regras `NAME`, `all`, `clean`, `fclean`, `re`:**
    - `NAME`: Nome do executável.
    - `all`: Compilar todos os arquivos fonte.
    - `clean`: Remover arquivos objeto.
    - `fclean`: Remover arquivos objeto e o executável.
    - `re`: Recompilar tudo do zero.

### Fase 2: Leitura e Processamento do Arquivo .fdf

#### Etapa 2.1: Leitura do Arquivo
- **Objetivo:** Ler os dados do arquivo .fdf e armazená-los em uma estrutura apropriada.
- **Passos:**
  - **Utilizar funções como `open`, `read`, `close`:**
    - `open`: Abre o arquivo para leitura.
    - `read`: Lê os dados do arquivo.
    - `close`: Fecha o arquivo após a leitura.
  - **Usar `get_next_line()` e `ft_split()` da `libft` para ler e dividir os dados:**
    - `get_next_line()`: Lê uma linha do arquivo por vez.
    - `ft_split()`: Divide a linha em substrings com base em um delimitador (espaço).

#### Etapa 2.2: Armazenamento dos Dados
- **Objetivo:** Armazenar os dados lidos em uma estrutura de dados.
- **Passos:**
  - **Criar uma estrutura para armazenar as coordenadas (x, y, z):**
    - Uma estrutura em C é uma coleção de variáveis de diferentes tipos agrupadas sob um único nome.
    - Exemplo de estrutura:
    ```c
    typedef struct s_point {
        int x;
        int y;
        int z;
    } t_point;

    typedef struct s_map {
        int width;
        int height;
        t_point **points;
    } t_map;
    ```
    - `t_point` armazena as coordenadas de um ponto.
    - `t_map` armazena a largura, altura e uma matriz de pontos.

### Fase 3: Renderização do Modelo

#### Etapa 3.1: Projeção Isométrica
- **Objetivo:** Converter as coordenadas 3D para uma projeção isométrica.
- **Passos:**
  - **Implementar a fórmula de projeção isométrica:**
    - A projeção isométrica é uma técnica de renderização que representa um objeto tridimensional em duas dimensões.
    - Utiliza as funções `cos` e `sin` para calcular as novas coordenadas.
    - Fórmula básica:
    ```c
    int iso_x(int x, int y, int z) {
        return (x - y) * cos(0.523599);
    }

    int iso_y(int x, int y, int z) {
        return (x + y) * sin(0.523599) - z;
    }
    ```
    - `0.523599` radianos é aproximadamente 30 graus, o ângulo usado para a projeção isométrica.

#### Etapa 3.2: Desenho do Wireframe
- **Objetivo:** Desenhar o modelo wireframe na tela.
- **Passos:**
  - **Utilizar funções da MiniLibX para desenhar linhas entre os pontos:**
    - `mlx_pixel_put()`: Desenha um pixel na janela.
    - `mlx_line_put()`: Função personalizada para desenhar uma linha entre dois pontos.
    - Exemplo de função para desenhar uma linha:
    ```c
    void draw_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr) {
        // Implementação do algoritmo para desenhar linhas
    }
    ```

### Fase 4: Gerenciamento Gráfico

#### Etapa 4.1: Criação da Janela
- **Objetivo:** Criar uma janela para exibir a imagem.
- **Passos:**
  - **Utilizar a MiniLibX para criar a janela:**
    - `mlx_init()`: Inicializa a conexão com o servidor gráfico.
    - `mlx_new_window()`: Cria uma nova janela.
    - Exemplo:
    ```c
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "FDF");
    ```

#### Etapa 4.2: Exibição da Imagem
- **Objetivo:** Exibir a imagem na janela criada.
- **Passos:**
  - **Utilizar a MiniLibX para exibir a imagem:**
    - `mlx_put_image_to_window()`: Coloca a imagem na janela.
    - Exemplo:
    ```c
    void *img_ptr;
    int *data;

    img_ptr = mlx_new_image(mlx_ptr, 800, 600);
    data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    // Desenhar na imagem
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    ```

#### Etapa 4.3: Interação com o Usuário
- **Objetivo:** Permitir que o usuário interaja com a janela.
- **Passos:**
  - **Implementar a funcionalidade para fechar a janela ao pressionar ESC ou clicar no botão de fechar:**
    - `mlx_hook()`: Define eventos para teclas e mouse.
    - `mlx_loop()`: Inicia o loop de eventos.
    - Exemplo:
    ```c
    int close_window(void *param) {
      exit(0);
    }

    mlx_hook(win_ptr, 17, 0, close_window, NULL); // Evento de fechar janela
    mlx_hook(win_ptr, 2, 1L<<0, key_press, NULL); // Evento de pressionar tecla
    mlx_loop(mlx_ptr);
    ```

