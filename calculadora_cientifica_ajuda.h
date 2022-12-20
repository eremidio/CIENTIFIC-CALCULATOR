/*CABEÇALHO*/
#include<gtkmm.h>
#include<iostream>

using namespace std;
using namespace Glib;
using namespace Gtk;

/*CLASSE DE MENU DE AJUDA LABEL+SCROLLEDWINDOW*/
class HelpWindow: public Window{
public:

//CONSTRUTOR E DESTRUIDOR DA CLASSE
HelpWindow();
virtual ~HelpWindow();
//WIDGETS
ScrolledWindow help_scrolledwindow;
Label help_label;
Box help_box;

};

//DESTRUIDOR DA CLASSE
HelpWindow::~HelpWindow(){
};

//CONSTRUTOR DA CLASSE
HelpWindow::HelpWindow(){

//LAYOUT
add(help_scrolledwindow);
help_scrolledwindow.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
help_scrolledwindow.add(help_label);
help_label.set_justify(JUSTIFY_FILL);
//TEXTO DE AJUDA A SER EXIBIDO NA JANELA SECUNDÁRIA
help_label.set_text("CALCULADORA CIENTÍFICA - Versão 1.0\n"
"----------------------------------------------------------------\n\n"
"Este aplicativo permite ao usuário realizar cálculos matemáticos básicos. Diversas funcionalidades estão presentes.\nO aplicativo permite ao usuário realizar operações aritméticas elementares, cálculos com funções trigonométricas e hiperbólicas, funções exponenciais e logarítmicas, operações com números complexos,\noperações com manipulação de bits, além operar com números inteiros em diferentes bases.\n\n"

"1.0 - LAYOUT E FUNCIONALIDADE GERAL DO APLICATIVO\n"
"----------------------------------------------------------------\n\n"
"Este aplicativo dispõe dos seguintes elementos gráficos: um display no qual o usuário pode entrar dados manualmente dando um duplo clique ou usando os botões de inserção de dados; um teclado númerico contendo os digitos de 0 a 9, o separador de casas decimais '.' e o botão de confirmação '=';\nalém de um menu fixo de funções de uso geral; e um menu contendo várias guias, cada guia contém botões que acionam funções que executam cálculos matemáticos especificos quando clicados.\n"
"O display da calculadora em a dupla finalidade de receber os argumentos que serão usados para performar os cálculos e exibir os resultados destes.\n"
"Algumas operações matemáticas exigem apenas um argumento. Nestes casos o usuário deve inserir um argumento válido no display da calculadora e acionar o botão que efetua a operação desejada. O resultado será exibido no display da calculadora.\n" 
"Quando uma operação requerir mais de uma parcela o usuário deve inserir a primeira parcela da operação acionar o botão que efetua a operação desejada, inserir a segunda parcela da operação e em seguida pressionar um botão de confirmação '=', '=_c' ou '=_b'.\nApós pressionar o botão de confirmação o resultado será exibido no display da calculadora.\n"
"Deixando o cursor do mouse em cima de qualquer botão da calculadora, o usuário pode visualizar uma pequena mensagem que informa qual operação matemática determinado botão efetua ao ser clicado.\nAlguns botões que são usados apenas para se inserir dados não dispõem desta funcionalidade.\n\n"
"2.0 - MENUS \n"
"----------------------------------------------------------------\n"
"Descrição breve das funções disponibilizadas na calculadora.\n\n"
"2.1 - MENU DE FUNÇÕES DE USO GERAL \n"
"----------------------------------------------------------------\n\n"
"O botão 'CE' remove conteúdo exibido no display e reseta as variáveis usadas nos cálculos para valores padrões.\n"
"O botão 'MR' remove conteúdo exibido no display e aloca seu conteúdo no cachê de memória da calculadora (operação útil apenas para números reais ou inteiros).\n"
"O botão 'MC' esvazia o cachê de memória da calculadora e exibe o conteúdo alocado no display.\n"
"O botão '+/-' efetua a troca de sinal do número exibido no display da calculadora (função útil apenas para números reais e inteiros).\n\n"
"2.2 - MENU DE OPERADORES ARITMÉTICOS \n"
"----------------------------------------------------------------\n"
"Este menu contém os botões  '+' , '-' , 'X' , '/' que efetuam as quatros operações aritméticas elementares. Estes requerem que o usuário pressione o botão de confirmação '=' após inserir a seguna parcela da operação.\n"
"O botão '|x|' retorna o valor absoluto de um número.\n"
"O botão 'x!' retorna o fatorial de um número inteiro.\n"
"O botão '1/x' retorna o inverso de um número.\n"
"O botão '%' efetua cálculos de porcentagem. Este requer que o usuário pressione o botão de confirmação '=' após inserir a segunda parcela da operação. Primeiramente deve-se inserir o total e em seguida o percentual desejado.\n"
"O botão 'mod' retorna a congruência (classe de equivalência) de dois números inteiros. Este requer que o usuário pressione o botão de confirmação '=' após inserir a segunda parcela da operação.\n"
"O botão 'Apr' aproxima um número real pelo inteiro mais próximo a este número\n"
"O botão 'π' retorna o valor de pi (nenhum argumento é necessário).\n"
"O botão 'e' retorna o valor do número de Euler (nenhum argumento é necessário).\n\n"
"2.3 - MENU DE FUNÇÕES HIPERBÓLICAS E TRIGONOMÉTRICAS \n"
"----------------------------------------------------------------\n"
"Os botões de seleção 'rad' e 'graus' são usados para se efetuar a medida de ângulos em graus ou radianos. Isto requer atenção nos cálculos de funções trigonométricas.\n"
"Os botões 'sen', 'cos' e 'tan', dado um certo ângulo, retornam o valor das funções trigonométricas seno, cosseno e tangente, respectivamente.\n"
"Os botões 'senh', 'cosh' e 'tanh', dado um certo argumento,  retornam o valor das funções seno hiperbólico, cosseno hiperbólico e tangente hiperbólica, respectivamente.\n"
"O botão de seleção 'Funções inversas' redefinem os demais botões deste menu para computarem as funções trigonométricas e hiperbólicas inversas correspondentes.\n\n"
"2.4 - MENU DE OPERADORES DE NÚMEROS COMPLEXOS \n"
"----------------------------------------------------------------\n"
"Para que as funções que estão disponíveis neste menu operem corretamente. Números complexos devem ser escritos na seguinte forma z=a+bi, onde 'a' denota a parte real e 'b' denota a parte imaginária de um número complexo.\nPor exemplo, -5+8i, 2+7.35i, -2-2i, etc; são inserções válidas.\n"
"Este menu contém os botões  '+_c' , '-_c' , 'X_c' , '/_c' que efetuam as quatros operações aritméticas elementares com números complexos. Estes requerem que o usuário pressione o botão de confirmação '=_c' após inserir a segunda parcela da operação.\n"
"O botão 'Im' retorna a parte imaginária de um número complexo.\n"
"O botão 'Re' retorna a parte real de um número complexo.\n"
"O botão 'Conj' retorna o conjugado de um número complexo.\n"
"O botão 'Arg' retorna o argumento de um número complexo.\n"
"O botão 'exp_c' retorna o valor da função exponencial para um dado número complexo.\n"
"O botão 'ln_c' retorna o valor da função logaritmo natural para um dado número complexo.\n"
"O botão 'Abs' retorna o módulo de um número complexo.\n"
"O botão 'x^n' retorna o valor da potência de um dado número complexo elevado a um número real qualquer. Este requer que o usuário pressione o botão de confirmação '=_c' após inserir a segunda parcela da operação.\nO usuário deve inserir primeiro um número complexo (base) e em seguida inserir o valor do expoente real.\n"
"O botão 'x²_c' retorna o quadrado de um número complexo.\n"
"O botão '√_c' retorna a raíz quadrada de um número complexo.\n"
"Os botões 'i', '+', '-' inserem os respectivos caractéres no display da calculadora.\n\n"
"2.5 - MENU DE FUNÇÕES EXPONENCIAIS E LOGARÍTMICAS \n"
"----------------------------------------------------------------\n"
"O botão 'x²' retorna o quadrado de um número.\n"
"O botão '√' retorna a raíz quadrada de um número.\n"
"O botão 'x³' retorna o cubo de um número.\n"
"O botão '³√' retorna a raíz cúbica de um número.\n"
"O botão 'exp' retorna o valor da função exponencial para um dado argumento.\n"
"O botão 'ln' retorna o valor da função logaritmo natural para um dado argumento.\n"
"O botão 'log' retorna o valor do logaritmo na base 10 para um dado argumento.\n"
"O botão 'log2' retorna o valor da função logaritmo na base 2 para um dado argumento.\n"
"Este menu ainda dispõe de dois submenus contendo duas caixas de entradas e um botão que efetua cálculos de logaritmos e exponenciais para diversas bases.\nBasta inserir argumentos válidos em cada uma das entradas e clicar nos botões correspondentes para que os resultados sejam exibidos no display da calculadora.\n\n"
"2.6 - MENU DE FUNÇÕES DE MUDANÇAS DE BASES E OPERAÇÕES \n"
"----------------------------------------------------------------\n"
"Menu de funções de operações de conversão de números para diferentes bases e nfunções de manipulação de bits de números inteiros. Use a seguinte notação para números escritos nas bases binária (0b...), octal (0...) e hexadecimal (0x...).\n Inserção de dados não conformes com estas notações podem acarretar erros lógicos no programa.\n"
"O botão BIN expressa um número inteiro em notação binária (base 2).\n"
"O botão OCT expressa um número inteiro em notação octal (base 8).\n"
"O botão HEX expressa um número inteiro em notação hexadecimal (base 16).\n"
"O botão DEC expressa um número inteiro escrito em notação binária, octal ou hexadecimal para a notação decimal.\n"
"Este menu ainda disponibiliza botões 'AND', 'OR', 'XOR', 'NOT','SHL'(SHIFT-LEFT), 'SHR'(SHIFT_RIGHT) que acionam os respectivos operadores bitwise.\nO operador NOT requer apenas um número inteiro como argumento, ao passo que os demais operadores 'AND', 'OR', 'XOR', 'NOT', 'SHL', 'SHR' requerem dois números inteiros.\nEstes requerem que o usuário pressione o botão de confirmação '=_b' após inserir a segunda parcela da operação.\n"
"Os botões 'a', 'b', 'c', 'd', 'e', 'f', 'x' inserem os respectivos caractéres no display da calculadora.\n\n"

"3.0 - AGRADECIMENTOS\n"
"----------------------------------------------------------------\n\n"
"Obrigado pela preferência. Sugestões de melhorias entrar em contato com: e.r.emidio@yandex.com.\n\n"

);



};
