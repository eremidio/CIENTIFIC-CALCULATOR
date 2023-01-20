//ESTE ARQUIVO CONTÉM A DEFINÇÃO DOS MÉTODOS DA CLASSE DO APLICATIVO

/*CABEÇALHO*/
#include"calculadora_cientifica.h"
#include<gtkmm.h>
#include<iostream>
#include<string>
#include<sstream>
#include<array>
#include<memory>
#include<cstdlib>
#include<cmath>


using namespace std;
using namespace Glib;
using namespace Gtk;

//DESTRUIDOR DA CLASSE
calculator::~calculator(){
delete help_window;
};

//CONSTRUTOR DA CLASSE
calculator::calculator():base(ORIENTATION_VERTICAL, 5), box1(ORIENTATION_VERTICAL, 5),  box2(ORIENTATION_HORIZONTAL, 5), box21(ORIENTATION_VERTICAL, 5), one("1"), two("2"), three("3"), four("4"), five("5"), six("6"), seven("7"), eight("8"), nine("9"), zero("0"), point("."), equal_button("="), box22(ORIENTATION_VERTICAL, 5), clear_button("CE"), memory_button("MR"), memory_cache_button("MC"), plus_minus_button("+/-"), box23(ORIENTATION_HORIZONTAL, 5), box231(ORIENTATION_HORIZONTAL, 5), plus_button("+"), minus_button("-"), multiply_button("X"), divide_button("/"), abs_button("|x|"), factorial_button("x!"), inverse_button("1/x"), percent_button("%"), mod_button("mod"), round_button("Apr"), pi_button("π"), euler_button("e"), box232(ORIENTATION_VERTICAL, 5), box2321(ORIENTATION_HORIZONTAL, 5), box2322(ORIENTATION_HORIZONTAL, 5), empty_button("Selecione uma das opções"), rad_button("rad"), degree_button("graus"), inv_button("Funções inversas"), sin_button("sen"), cos_button("cos"), tan_button("tan"), sinh_button("sinh"), cosh_button("cosh"), tanh_button("tanh"), box233(ORIENTATION_VERTICAL, 5), complex_plus_button("+_c"), complex_minus_button("-_c"), complex_multiply_button("X_c"), complex_divide_button("/_c"), imaginary_button("Im"), real_button("Re"), conjugate_button("Conj"), argument_button("Arg"), complex_exp_button("exp_c"), complex_ln_button("ln_c"), norm_button("Abs"), i_button("i"), sign_plus_button("'+'"), sign_minus_button("'-'"), power_int_button("x^n"), complex_sqrt_button("√_c"), complex_square_button("x²_c"), complex_equal_button("=_c"), box234(ORIENTATION_HORIZONTAL, 5), box2341(ORIENTATION_VERTICAL, 5), box2342(ORIENTATION_VERTICAL, 5), box23421(ORIENTATION_VERTICAL, 5), box23422(ORIENTATION_VERTICAL, 5), square_button("x²"), square_root_button("√"), cube_button("x³"), cubic_root_button("³√"), exp_button("exp"), ln_button("ln"), log_button("log"), log2_button("log2"), get_log_button("Calcular logaritmo"), get_exp_button("Calcular exponencial"), box235(ORIENTATION_VERTICAL, 5), bin_button("BIN"), oct_button("OCT"), hex_button("HEX"), dec_button("DEC"), and_button("AND"), or_button("OR"), xor_button("XOR"), not_button("NOT"), shl_button("SHL"), shr_button("SHR"), bit_equal_button("=_b"), a_button("a"), b_button("b"), c_button("c"), d_button("d"), e_button("e"), f_button("f"), x_button("x")
{
//CONFIGURAÇÕES GERAIS DO APP
set_title("Calculadora científica");
set_border_width(5);
//WIDGET BASE
add(base);
//CONFIGURANDO O DISPLAY DA CALCULADORA
base.pack_start(box1);
box1.pack_start(display_entry, PACK_EXPAND_WIDGET, 5);
display_entry.set_visible(true);
display_entry.set_visibility(true);
display_entry.set_editable(true);
//SUPORTE PARA DEMAIS WIDGETS DA CALCULADORA
base.pack_start(box2);
//AJUSTANDO O TECLADO NÚMERICO DA CALCULADORA
box2.pack_start(box21);
box21.pack_start(numeric_frame, PACK_EXPAND_WIDGET, 5);
numeric_frame.add(numeric_grid);
numeric_frame.set_shadow_type(SHADOW_NONE);
numeric_grid.set_row_homogeneous(true);
numeric_grid.set_column_homogeneous(true);
numeric_grid.attach(seven, 0, 0, 1, 1);
numeric_grid.attach(eight, 1, 0, 1, 1);
numeric_grid.attach(nine, 2, 0, 1, 1);
numeric_grid.attach(four, 0, 1, 1, 1);
numeric_grid.attach(five, 1, 1, 1, 1);
numeric_grid.attach(six, 2, 1, 1, 1);
numeric_grid.attach(one, 0, 2, 1, 1);
numeric_grid.attach(two, 1, 2, 1, 1);
numeric_grid.attach(three, 2, 2, 1, 1);
numeric_grid.attach(zero, 0, 3, 1, 1);
numeric_grid.attach(point, 1, 3, 1, 1);
numeric_grid.attach(equal_button, 2, 3, 1, 1);
//ATIVANDO OS BOTÕES DO TECLADO NÚMERICO
zero.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_0));
one.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_1));
two.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_2));
three.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_3));
four.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_4));
five.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_5));
six.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_6));
seven.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_7));
eight.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_8));
nine.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_9));
point.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_point));
equal_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::equal));
equal_button.set_tooltip_text("Performa operações aritméticas básicas envolvendo duas parcelas.");
//AJUSTANDO TECLADO DE FUNCIONALIDADES DE USO GERAL
box2.pack_start(box22);
box22.pack_start(basic_frame, PACK_EXPAND_WIDGET, 5);
basic_frame.add(basic_grid);
basic_frame.set_shadow_type(SHADOW_NONE);
basic_grid.set_row_homogeneous(true);
basic_grid.set_column_homogeneous(true);
basic_grid.attach(clear_button, 0, 0, 1, 1);
basic_grid.attach(memory_button, 0, 1, 1, 1);
basic_grid.attach(memory_cache_button, 0, 2, 1, 1);
basic_grid.attach(plus_minus_button, 0, 3, 1, 1);
clear_button.set_tooltip_text("Remove conteúdos do display e zera os valores de variáveis do app.");
memory_button.set_tooltip_text("Registra o valor exibido no display do app no cachê da memória do app para uso posterior.");
memory_cache_button.set_tooltip_text("Exibe o valor registrado e zera o valor alocado no cachê de memória do app.");
plus_minus_button.set_tooltip_text("Inverte o sinal do valor exibido no display.");
//ATIVANDO BOTÕES DE TECLADO DE FUNCIONALIDADES DE USO GERAL
clear_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::clear));
memory_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::memory_register));
memory_cache_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::memory_clear));
plus_minus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::change_signal));
//MENU DE FUNÇÕES VARIADAS DA CALCULADORA
box2.pack_start(box23);
box23.pack_start(menu_notebook);
//AJUSTANDO TECLADO DE OPERADORES ARITMÉTICOS ELEMENTARESS
menu_notebook.append_page(box231,"Aritmética\nbásica");
box231.pack_start(arithmetic_frame, PACK_EXPAND_WIDGET, 5);
box231.set_tooltip_text("Operadores aritméticos elementares");
arithmetic_frame.add(arithmetic_grid);
arithmetic_grid.set_row_homogeneous(true);
arithmetic_grid.set_column_homogeneous(true);
arithmetic_grid.attach(plus_button, 0, 0, 1, 1);
arithmetic_grid.attach(minus_button, 0, 1, 1, 1);
arithmetic_grid.attach(multiply_button, 0, 2, 1, 1);
arithmetic_grid.attach(divide_button, 0, 3, 1, 1);
arithmetic_grid.attach(abs_button, 1, 0, 1, 1);
arithmetic_grid.attach(factorial_button, 1, 1, 1, 1);
arithmetic_grid.attach(inverse_button, 1, 2, 1, 1);
arithmetic_grid.attach(percent_button, 1, 3, 1, 1);
arithmetic_grid.attach(mod_button, 2, 0, 1, 1);
arithmetic_grid.attach(round_button, 2, 1, 1, 1);
arithmetic_grid.attach(pi_button, 2, 2, 1, 1);
arithmetic_grid.attach(euler_button, 2, 3, 1, 1);
abs_button.set_tooltip_text("Calcula o valor absoluto do número exibido no display.");
factorial_button.set_tooltip_text("Calcula o fatorial de um número inteiro.");
inverse_button.set_tooltip_text("Calcula o inverso do número exibido no display.");
percent_button.set_tooltip_text("Efetua cálculos envolvendo porcentagem.");
mod_button.set_tooltip_text("Determina relações de congruência entre dois números inteiros.");
round_button.set_tooltip_text("Aproxima o número exibido no display para o inteiro mais próximo do valor mostrado no display.");
pi_button.set_tooltip_text("Número pi");
euler_button.set_tooltip_text("Número de Euler (base de logaritmo neperiano)");
//ATIVANDO BOTÕES DO TECLADO OPERADORES ARITMÉTICOS BÁSICOS
plus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::sum));
minus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::subtract));
multiply_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::multiply));
divide_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::divide));
abs_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::absolute));
factorial_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::factorial));
inverse_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::invert));
percent_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::get_percent));
mod_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::congruence));
round_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::next_integer));
pi_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::show_pi));
euler_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::show_euler));
//AJUSTANDO TECLADO DE FUNÇÕES TROGONOMÉTRICAS E HIPERBÓLICAS
menu_notebook.append_page(box232,"Trig.\nHip.");
box231.set_tooltip_text("Funções trigonométricas e hiperbólicas");
box232.pack_start(box2321);
box232.pack_start(box2322);
box2321.pack_start(empty_button);
box2321.pack_start(rad_button);
box2321.pack_start(degree_button);
box2321.pack_start(inv_button);
rad_button.join_group(empty_button);
degree_button.join_group(empty_button);
inv_button.join_group(empty_button);
box2322.pack_start(trig_hyp_frame, PACK_EXPAND_WIDGET, 5);
trig_hyp_frame.add(trig_hyp_grid);
trig_hyp_frame.set_shadow_type(SHADOW_NONE);
trig_hyp_grid.set_row_homogeneous(true);
trig_hyp_grid.set_column_homogeneous(true);
trig_hyp_grid.attach(sin_button, 0, 0, 1, 1);
trig_hyp_grid.attach(cos_button, 1, 0, 1, 1);
trig_hyp_grid.attach(tan_button, 2, 0, 1, 1);
trig_hyp_grid.attach(sinh_button, 0, 1, 1, 1);
trig_hyp_grid.attach(cosh_button, 1, 1, 1, 1);
trig_hyp_grid.attach(tanh_button, 2, 1, 1, 1);
rad_button.set_tooltip_text("Medida de ângulos em radianos.");
degree_button.set_tooltip_text("Medida de ângulos em graus.");
inv_button.set_tooltip_text("Invoca funções trigonométricas inversa");
sin_button.set_tooltip_text("Calcula o seno de um ângulo ou arco seno de um argumento entre -1 e 1");
cos_button.set_tooltip_text("Calcula o cosseno de um ângulo ou o arco cosseno de um argumento entre -1 e 1");
tan_button.set_tooltip_text("Calcula a tangente de um ângulo ou o arco tangente de um argumento");
sinh_button.set_tooltip_text("Calcula o seno hiperbólico ou o arco seno hiperbólico de um argumento");
cosh_button.set_tooltip_text("Calcula o cosseno hiperbólico ou o arco cosseno hiperbólico de um argumento");
tanh_button.set_tooltip_text("Calcula a tangente hiperbólica ou o arco tangente hiperbólica de um argumento");
//ATIVANDO OS BOTÕES DO TECLADO DE FUNÇÕES TRIGONOMÉTRICAS E HIPERBÓLICAS
empty_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::null_angle));
rad_button.signal_toggled().connect(sigc::mem_fun(*this, &calculator::rad_angle));
degree_button.signal_toggled().connect(sigc::mem_fun(*this, &calculator::degree_angle));
inv_button.signal_toggled().connect(sigc::mem_fun(*this, &calculator::inverse_function));
sin_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::sine));
cos_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::cossine));
tan_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::tangent));
sinh_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::hyperbolic_sine));
cosh_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::hyperbolic_cossine));
tanh_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::hyperbolic_tangent));
//AJUSTANDO OS BOTÕES DO TECLADO DE FUNÇÕES COM NÚMEROS COMPLEXOS
menu_notebook.append_page(box233, "z=a+bi");
box233.set_tooltip_text("Números complexos\n\nNúmeros complexos devem ser escritos usando a notação algébrica: a+bi.\n'a' é a parte imaginária e 'b' é a parte complexa.\nA notação '_c' denota operadores matemáticos redefinidos para operarem com números complexos.");
box233.pack_start(complex_frame, PACK_EXPAND_WIDGET, 5);
complex_frame.set_shadow_type(SHADOW_NONE);
complex_frame.add(complex_grid);
complex_grid.set_row_homogeneous(true);
complex_grid.set_column_homogeneous(true);
complex_grid.attach(complex_plus_button, 0, 0, 1, 1);
complex_grid.attach(complex_minus_button, 0, 1, 1, 1);
complex_grid.attach(complex_multiply_button, 0, 2, 1, 1);
complex_grid.attach(complex_divide_button, 1, 0, 1, 1);
complex_grid.attach(imaginary_button, 1, 1, 1, 1);
complex_grid.attach(real_button, 1, 2, 1, 1);
complex_grid.attach(conjugate_button, 2, 0, 1, 1);
complex_grid.attach(argument_button, 2, 1, 1, 1);
complex_grid.attach(complex_exp_button, 2, 2, 1, 1);
complex_grid.attach(complex_ln_button, 3, 0, 1, 1);
complex_grid.attach(norm_button, 3, 1, 1, 1);
complex_grid.attach(i_button, 3, 2, 1, 1);
complex_grid.attach(sign_plus_button, 4, 0, 1, 1);
complex_grid.attach(sign_minus_button, 4, 1, 1, 1);
complex_grid.attach(power_int_button, 4, 2, 1, 1);
complex_grid.attach(complex_sqrt_button, 5, 0, 1, 1);
complex_grid.attach(complex_square_button, 5, 1, 1, 1);
complex_grid.attach(complex_equal_button, 5, 2, 1, 1);
imaginary_button.set_tooltip_text("Retorna a parte imaginária de um número complexo");
real_button.set_tooltip_text("Retorna a parte real de um número complexo");
conjugate_button.set_tooltip_text("Retorna o conjugado de um número complexo");
argument_button.set_tooltip_text("Retorna o argumento de um número complexo em radianos.");
complex_exp_button.set_tooltip_text("Retorna a exponencial de um número complexo.");
complex_ln_button.set_tooltip_text("Retorna o logaritmo natural de um número complexo.");
norm_button.set_tooltip_text("Retorna o módulo de um número complexo.");
i_button.set_tooltip_text("Unidade imaginária: i²=(-1).");
sign_plus_button.set_tooltip_text("Insere o sinal '+' ");
sign_minus_button.set_tooltip_text("Insere o sinal '-' ");
power_int_button.set_tooltip_text("Retorna o número complexo elevado a um expoente.");
complex_sqrt_button.set_tooltip_text("Retorna a raíz quadrada de um número complexo.");
complex_square_button.set_tooltip_text("Retorna o quadrado de um número complexo.");
complex_equal_button.set_tooltip_text("Perfoma operações básicas em números complexos envolvendo duas parcelas.");
//ATIVANDO OS BOTÕES DO TECLADO DE FUNÇÕES COM NÚMEROS COMPLEXOS 
complex_plus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_sum));
complex_minus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_subtract));
complex_multiply_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_multiply));
complex_divide_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_divide));
imaginary_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::get_imaginary));
real_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::get_real));
conjugate_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::conjugate));
argument_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::get_argument));
complex_exp_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_exponential));
complex_ln_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_logarithm));
norm_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_norm));
i_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_i));
sign_plus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_plus));
sign_minus_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_minus));
power_int_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::power_integer));
complex_sqrt_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_square_root));
complex_square_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::complex_square));
complex_equal_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::equal_complex));
//AJUSTANDO OS BOTÕES DO TECLADO DE FUNÇÕES EXPONENCIAIS E LOGARÍTMICAS
menu_notebook.append_page(box234, "Log.\nExp.");
box234.set_tooltip_text("Funções exponenciais e logarítmicas");
box234.pack_start(box2341);
box234.pack_start(box2342);
box2342.pack_start(box23421);
box2342.pack_start(box23422);
box2341.pack_start(exp_log_frame, PACK_EXPAND_WIDGET, 5);
exp_log_frame.set_shadow_type(SHADOW_NONE);
exp_log_frame.add(exp_log_grid);
exp_log_grid.set_row_homogeneous(true);
exp_log_grid.set_column_homogeneous(true);
exp_log_grid.attach(square_button, 0, 0, 1, 1);
exp_log_grid.attach(cube_button, 0, 1, 1, 1);
exp_log_grid.attach(square_root_button, 0, 2, 1, 1);
exp_log_grid.attach(cubic_root_button, 0, 3, 1, 1);
exp_log_grid.attach(exp_button, 1, 0, 1, 1);
exp_log_grid.attach(ln_button, 1, 1, 1, 1);
exp_log_grid.attach(log_button, 1, 2, 1, 1);
exp_log_grid.attach(log2_button, 1, 3, 1, 1);
box23421.pack_start(exp_grid, PACK_EXPAND_WIDGET, 0);
exp_grid.set_row_homogeneous(true);
exp_grid.set_column_homogeneous(true);
exp_grid.attach(base1_frame, 0, 0, 1, 1);
base1_frame.set_label("Base");
base1_frame.add(base1_entry);
base1_frame.set_shadow_type(SHADOW_NONE);
exp_grid.attach(exponent_frame, 1, 0, 1, 1);
exponent_frame.set_label("Expoente");
exponent_frame.add(exponent_entry);;
exponent_frame.set_shadow_type(SHADOW_NONE);
exp_grid.attach(get_exp_button, 0, 1, 2, 1);
box23422.pack_start(log_grid, PACK_EXPAND_WIDGET, 0);
log_grid.set_row_homogeneous(true);
log_grid.set_column_homogeneous(true);
log_grid.attach(base2_frame, 0, 0, 1, 1);
base2_frame.set_label("Base");
base2_frame.add(base2_entry);
base2_frame.set_shadow_type(SHADOW_NONE);
log_grid.attach(log_frame, 1, 0, 1, 1);
log_frame.set_label("Logaritmando");
log_frame.add(log_entry);
log_frame.set_shadow_type(SHADOW_NONE);
log_grid.attach(get_log_button, 0, 1, 2, 1);
square_button.set_tooltip_text("Retorna o quadrado de um número.");
cube_button.set_tooltip_text("Retorna o cubo de um número.");
square_root_button.set_tooltip_text("Retorna a raíz quadrada de um número.");
cubic_root_button.set_tooltip_text("Retorna a raíz cúbica de um número");
exp_button.set_tooltip_text("Retorna o valor da função exponencial de um argumento.");
ln_button.set_tooltip_text("Retorna o valor do logaritmo natural de um argumento.");
log_button.set_tooltip_text("Retorna o valor do logaritmo na base 10 de um argumento.");
log2_button.set_tooltip_text("Retorna o valor do logaritmo na base 2 de um argumento.");
get_log_button.set_tooltip_text("Retorna o valor da função logarítmica dada uma base e um logaritmando.");
get_exp_button.set_tooltip_text("Retorna o valor da função exponencial dada uma base e um expoente.");
//ATIVANDO OS BOTÕES DO TECLADO DE FUNÇÕES EXPONENCIAIS E LOGARITMÍCAS
square_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::square));
cube_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::cube));
square_root_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::square_root));
cubic_root_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::cubic_root));
exp_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::exponential));
ln_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::neperian_logarithm));
log_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::ten_logarithm));
log2_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::two_logarithm));
get_log_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::general_logarithm));
get_exp_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::general_exponential));
//AJUSTANDO OS BOTÕES DO TECLADO DE FUNÇÕES COM BITS E SISTEMAS DE NUMERAÇÃO
menu_notebook.append_page(box235, "bit.\nEnum.");
box235.set_tooltip_text("Menu de funções de operações de conversão de números para diferentes bases e\nfunções de manipulação de bits de números inteiros.\nUse a notação padrão de C++ para números escritos nas bases binária (0b...), octal (0...) e hexadecimal (0x...).");
box235.pack_start(bit_frame, PACK_EXPAND_WIDGET, 5);
bit_frame.add(bit_grid);
bit_frame.set_shadow_type(SHADOW_NONE);
bit_grid.set_row_homogeneous(true);
bit_grid.set_column_homogeneous(true);
bit_grid.attach(bin_button, 0, 0, 1, 1);
bit_grid.attach(oct_button, 0, 1, 1, 1);
bit_grid.attach(hex_button, 0, 2, 1, 1);
bit_grid.attach(dec_button, 1, 0, 1, 1);
bit_grid.attach(and_button, 1, 1, 1, 1);
bit_grid.attach(or_button, 1, 2, 1, 1);
bit_grid.attach(xor_button, 2, 0, 1, 1);
bit_grid.attach(not_button, 2, 1, 1, 1);
bit_grid.attach(shl_button, 2, 2, 1, 1);
bit_grid.attach(shr_button, 3, 0, 1, 1);
bit_grid.attach(a_button, 3, 1, 1, 1);
bit_grid.attach(b_button, 3, 2, 1, 1);
bit_grid.attach(c_button, 4, 0, 1, 1);
bit_grid.attach(d_button, 4, 1, 1, 1);
bit_grid.attach(e_button, 4, 2, 1, 1);
bit_grid.attach(f_button, 5, 0, 1, 1);
bit_grid.attach(x_button, 5, 1, 1, 1);
bit_grid.attach(bit_equal_button, 5, 2, 1, 1);
bin_button.set_tooltip_text("Expressa um número inteiro em notação binária.");
oct_button.set_tooltip_text("Expressa um número inteiro em base 8.");
hex_button.set_tooltip_text("Expressa um número inteiro em base 16.");
dec_button.set_tooltip_text("Expressa um número em base decimal.");
and_button.set_tooltip_text("Operador bit_AND.");
or_button.set_tooltip_text("Operador bit_OR.");
xor_button.set_tooltip_text("Operador bit_XÔR.");
not_button.set_tooltip_text("Operador bit_NOT.");
shl_button.set_tooltip_text("Operador bit_SHIFT_LEFT.");
shr_button.set_tooltip_text("Operador bit_SHIFT_RIGHT.");
bit_equal_button.set_tooltip_text("Efetua operações com bits envolvendo dois números inteiros.");
//ATIVANDO OS BOTÕES DO TECLADO DE FUNÇÕES COM BITS E SISTEMAS DE NUMERAÇÃO
bin_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::to_bin));
oct_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::to_oct));
hex_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::to_hex));
dec_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::to_dec));
and_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::bit_and));
or_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::bit_or));
xor_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::bit_xor));
not_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::bit_not));
shl_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::shift_left));
shr_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::shift_right));
bit_equal_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::bit_equal));
x_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_x));
a_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_a));
b_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_b));
c_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_c));
d_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_d));
e_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_e));
f_button.signal_clicked().connect(sigc::mem_fun(*this, &calculator::put_f));
//ASSISTENTE DE AJUDA (ÍCONE NO DISPLAY DA CALCULADORA)
display_entry.set_icon_from_icon_name("help-about");
display_entry.signal_icon_press().connect(sigc::mem_fun(*this, &calculator::help));

//ATIVANDO ATALHOS DE TECLADO
add_events(Gdk::KEY_PRESS_MASK);

//EXIBINDO OS WIDGETS DO APP
show_all_children();
}//FIM DO CONSTRTUTOR DA CLASSE


//MÉTODOS DA CLASSE

//FUNÇÕES DE ENTRADAS DE DADOS USANDO O TECLADO NÚMERICO
void calculator::put_0(){
const char c='0';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_1(){
const char c='1';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_2(){
const char c='2';
display_text=display_entry.get_text();
display_text.push_back(c); 

display_entry.set_text(display_text);
                        };

void calculator::put_3(){
const char c='3';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_4(){
const char c='4';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_5(){
const char c='5';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_6(){
const char c='6';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_7(){
const char c='7';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_8(){
const char c='8';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_9(){
const char c='9';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };
void calculator::put_point(){
const char c='.';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

//FUNÇÕES DE USO GERAL
void calculator::clear(){
display_entry.set_text("");
display_text=""; display_temp="";

number1=0.0; number2=0.0; result=0.0;
int_number1=0; int_number2=0; int_result=0;
ad=false; su=false; mu=false; di=false; mo=false; pe=false;

th_result=0.0; th_number1=0.0; angle=0.0;


string c_empty_string=""; stringstream(c_empty_string)>>c_digits_array;
cad=false; csu=false; cmu=false; cdi=false; cpo=false;
c_number1=0.0; c_number2=0.0; number1_real=0.0; number1_imaginary=0.0; number2_real=0.0; number2_imaginary=0.0; result_real=0.0; result_imaginary=0.0; argument=0.0; norm=0.0; c_result=0.0;

el_number1=0.0; el_number2=0.0; el_result=0.0;

blli_number1=0;
value=0; residue=0; counter=0; power2=1; power8=1; power16=1;
d_result=0;
string b_empty_string=""; stringstream(b_empty_string)>>b_digits_array;
b_number1=0; b_number2=0; 
bin=false; oct=false; hex=false;
b_and=false; b_or=false; b_xor=false; b_shl=false; b_shr=false;
                        };

void calculator::memory_register(){
display_text=display_entry.get_text();
stringstream(display_text)>>memory_value;
display_entry.set_text("");
                                  };

void calculator::memory_clear(){
display_entry.set_text(to_string(memory_value));
memory_value=0.0;
                               };

void calculator::change_signal(){
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
result=(-1.0)*number1;
display_entry.set_text(to_string(result));
                                };
//FUNÇÕES DE OPERADORES ARITMÉTICOS BÁSICOS
void calculator::sum(){
ad=true; su=false; mu=false; di=false; mo=false; pe=false;
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
display_entry.set_text("");
                      };

void calculator::subtract(){
ad=false; su=true; mu=false; di=false; mo=false; pe=false;
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
display_entry.set_text("");
                           };

void calculator::multiply(){
ad=true; su=false; mu=true; di=false; mo=false; pe=false;
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
display_entry.set_text("");
                           };

void calculator::divide(){
ad=true; su=false; mu=false; di=true; mo=false; pe=false;
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
display_entry.set_text("");
                      };

void calculator::absolute(){
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
result=abs(number1);
display_entry.set_text(to_string(result));
                           };

void calculator::factorial(){
//VARIÁVEIS LOCAIS
long long int fact, i;
fact=1;

//PROCEDIMENTOS EXECUTÁVEIS
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
int_number1=static_cast<long long int>(number1);

for(i=1; i<int_number1+1; i++)
fact=fact*i;

display_entry.set_text(to_string(fact));
                             };

void calculator::invert(){
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
result=(1.0)/number1;
display_entry.set_text(to_string(result));
                                };

void calculator::get_percent(){
ad=false; su=false; mu=false; di=false; mo=false; pe=true;
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
display_entry.set_text("");
                           };

void calculator::congruence(){
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
int_number1=static_cast<long long int>(number1);

ad=false; su=false; mu=false; di=false; mo=true; pe=false;
display_temp=display_text;
display_entry.set_text("");
                           };

void calculator::next_integer(){
display_text=display_entry.get_text();
stringstream(display_text)>>number1;
int_number1=static_cast<long long int>(number1);

if(number1-int_number1>0.5)
int_result=int_number1+1;
if(number1-int_number1<=0.5)
int_result=int_number1;

display_entry.set_text(to_string(int_result));
                              };

void calculator::show_pi(){
result=4.0*atan(1.0);
display_entry.set_text(to_string(result));
                          };


void calculator::show_euler(){
result=exp(1.0);
display_entry.set_text(to_string(result));
                          };

void calculator::equal(){
display_text=display_entry.get_text();
stringstream(display_text)>>number2;

if(ad==true)
result=number1+number2;
if(su==true)
result=number1-number2;
if(mu==true)
result=number1*number2;
if(di==true)
result=number1/number2;

if(mo==true){

int_number2=static_cast<long long int>(number2);
int_result=int_number1%int_number2;

display_temp+="≡";
display_temp+=to_string(int_result);
display_temp+="(mod";
display_temp+=to_string(int_number2);
display_temp+=")";
display_entry.set_text(display_temp);
return;
            };

if(pe==true){
result=number1*number2;
result=result/100.0;
            };

display_entry.set_text(to_string(result));                                                                 
                        };

//FUNÇÕES TRIGONOMÉTRICAS E HIPERBÓLICAS
void calculator::null_angle(){
return;
                             };

void calculator::rad_angle(){
rad=true;
degree=false;
inv=false;
                            };

void calculator::degree_angle(){
rad=false;
degree=true;
inv=false;
                               };

void calculator::inverse_function(){
rad=false;
degree=false;
inv=true;
                               };

void calculator::sine(){
const long double pi=4.0*atan(1.0);
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(rad==true && degree==false && inv==false){
angle=th_number1;
th_result=sin(angle);
                                            };

if(rad==false && degree==true && inv==false){
angle=pi*th_number1;
angle=angle/180.0;
th_result=sin(angle);
                                            };

if(rad==false && degree==false && inv==true){
th_result=asin(th_number1);
                                            };

display_entry.set_text(to_string(th_result));
                       };

void calculator::cossine(){
const long double pi=4.0*atan(1.0);
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(rad==true && degree==false && inv==false){
angle=th_number1;
th_result=cos(angle);
                                            };

if(rad==false && degree==true && inv==false){
angle=pi*th_number1;
angle=angle/180.0;
th_result=cos(angle);
                                            };

if(rad==false && degree==false && inv==true){
th_result=acos(th_number1);
                                            };

display_entry.set_text(to_string(th_result));
                         };

void calculator::tangent(){
const long double pi=4.0*atan(1.0);
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(rad==true && degree==false && inv==false){
angle=th_number1;
th_result=tan(angle);
                                            };

if(rad==false && degree==true && inv==false){
angle=pi*th_number1;
angle=angle/180.0;
th_result=tan(angle);
                                            };

if(rad==false && degree==false && inv==true){
th_result=atan(th_number1);
                                            };

display_entry.set_text(to_string(th_result));
                       };

void calculator::hyperbolic_sine(){
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(inv==false)
th_result=sinh(th_number1);             
if(inv==true)
th_result=asinh(th_number1);
                     
display_entry.set_text(to_string(th_result));
                       };

void calculator::hyperbolic_cossine(){
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(inv==false)
result=cosh(th_number1);             
if(inv==true)
result=acosh(th_number1);
                     
display_entry.set_text(to_string(th_result));
                       };

void calculator::hyperbolic_tangent(){
display_text=display_entry.get_text();
stringstream(display_text)>>th_number1;

if(inv==false)
th_result=tanh(th_number1);             
if(inv==true)
th_result=atanh(th_number1);
                     
display_entry.set_text(to_string(th_result));
                       };

//FUNÇÕES ENVOLVENDO NÚMEROS COMPLEXOS
void calculator::get_complex_parts(){
//VARIÁVEIS LOCAIS
int counter;
display_temp="";
//PROCEDIMENTOS
display_text=display_entry.get_text();
stringstream(display_text)>>c_digits_array;

for(counter=0; counter<sizeof(c_digits_array); counter++){
if(c_digits_array[counter]!='+' && c_digits_array[counter]!='-')
display_temp.push_back(c_digits_array[counter]);
else
break;
                                                       };

stringstream(display_temp)>>c_number1;
display_temp="";

for(; counter<sizeof(c_digits_array); counter++){
if(c_digits_array[counter]!='i')
display_temp.push_back(c_digits_array[counter]);
else
break;
                                              };

stringstream(display_temp)>>c_number2;
                                  };

void calculator::complex_sum(){
get_complex_parts();
number1_real=c_number1;
number1_imaginary=c_number2;
cad=true;
csu=false;
cmu=false;
cdi=false;
cpo=false;
display_entry.set_text("");
                              };

void calculator::complex_subtract(){
get_complex_parts();
number1_real=c_number1;
number1_imaginary=c_number2;
cad=false;
csu=true;
cmu=false;
cdi=false;
cpo=false;
display_entry.set_text("");
                                   };

void calculator::complex_multiply(){
get_complex_parts();
number1_real=c_number1;
number1_imaginary=c_number2;
cad=false;
csu=false;
cmu=true;
cdi=false;
cpo=false;
display_entry.set_text("");
                              };

void calculator::complex_divide(){
get_complex_parts();
number1_real=c_number1;
number1_imaginary=c_number2;
cad=false;
csu=false;
cmu=false;
cdi=true;
cpo=false;
display_entry.set_text("");
                              };

void calculator::get_imaginary(){
get_complex_parts();
display_entry.set_text(to_string(c_number2));
                                };

void calculator::get_real(){
get_complex_parts();
display_entry.set_text(to_string(c_number1));
                                };

void calculator::conjugate(){
display_text=display_entry.get_text();
stringstream(display_text)>>c_digits_array;

display_temp="";

for(counter=0; counter<sizeof(c_digits_array); counter++){
if(c_digits_array[counter]=='+'){
c_digits_array[counter]='-';
display_temp.push_back(c_digits_array[counter]);
continue;
                              };
if(c_digits_array[counter]=='-'){
c_digits_array[counter]='+';
display_temp.push_back(c_digits_array[counter]);
continue;
                              };
display_temp.push_back(c_digits_array[counter]);
                                                       };

display_entry.set_text(display_temp);
                            };

void calculator::get_argument(){
get_complex_parts();
argument=atan(c_number2/c_number1);
display_entry.set_text(to_string(argument));
                           };

void calculator::complex_exponential(){
display_temp="";

get_complex_parts();
argument=atan(c_number2/c_number1);
norm=sqrt(pow(c_number1, 2)+pow(c_number2, 2));
result_real=exp(norm)*cos(argument);
result_imaginary=exp(norm)*sin(argument);

display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
                                      };

void calculator::complex_logarithm(){
display_temp="";

get_complex_parts();
argument=atan(c_number2/c_number1);
norm=sqrt(pow(c_number1, 2)+pow(c_number2, 2));
result_real=log(norm);
result_imaginary=argument;

display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
                                    };

void calculator::complex_norm(){
get_complex_parts();
c_result=sqrt(pow(c_number1, 2)+pow(c_number2, 2));
display_entry.set_text(to_string(c_result));
                               };

void calculator::put_i(){
const char c='i';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_plus(){
const char c='+';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_minus(){
const char c='-';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::power_integer(){
get_complex_parts();
number1_real=c_number1;
number1_imaginary=c_number2;
cad=false;
csu=false;
cmu=false;
cdi=false;
cpo=true;
display_entry.set_text("");
                                };

void calculator::complex_square_root(){
display_temp="";

get_complex_parts();
argument=atan(c_number2/c_number1);
norm=sqrt(pow(c_number1, 2)+pow(c_number2, 2));
result_real=sqrt(norm)*cos(argument/2.0);
result_imaginary=sqrt(norm)*sin(argument/2.0);

display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
                                      };

void calculator::complex_square(){
display_temp="";

get_complex_parts();
argument=atan(c_number2/c_number1);
norm=sqrt(pow(c_number1, 2)+pow(c_number2, 2));
result_real=pow(norm, 2)*cos(argument*2.0);
result_imaginary=pow(norm, 2)*sin(argument*2.0);

display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
                                      };

void calculator::equal_complex(){
if(cad==false && csu==false && cmu==false && cdi==false && cpo==true){
display_temp="";
display_text=display_entry.get_text();
stringstream(display_text)>>c_number2;

argument=atan(number1_imaginary/number1_real);
norm=sqrt(pow(number1_real, 2)+pow(number2_imaginary, 2));
result_real=pow(norm, number2)*cos(argument*number2);
result_imaginary=pow(norm, number2)*sin(argument*number2);

display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
return;
                                                                     };

get_complex_parts();
number2_real=c_number1;
number2_imaginary=c_number2;


if(cad==true && csu==false && cmu==false && cdi==false && cpo==false){
result_real=number1_real+number2_real;
result_imaginary=number1_imaginary+number2_imaginary;
                                                                     };

if(cad==false && csu==true && cmu==false && cdi==false && cpo==false){
result_real=number1_real-number2_real;
result_imaginary=number1_imaginary-number2_imaginary;
                                                                     };

if(cad==false && csu==false && cmu==true && cdi==false && cpo==false){
result_real=(number1_real*number2_real)-(number1_imaginary*number2_imaginary);
result_imaginary=(number1_real*number2_imaginary)+(number1_imaginary*number2_real);
                                                                     };

if(cad==false && csu==false && cmu==false && cdi==true && cpo==false){
norm=sqrt(pow(number2_real, 2)+pow(number2_imaginary, 2));

result_real=(number1_real*number2_real)+(number1_imaginary*number2_imaginary);
result_real=result_real/norm;
result_imaginary=(number1_imaginary*number2_real)-(number1_real*number2_imaginary);
result_imaginary=result_imaginary/norm;
                                                                     };

display_temp="";
display_temp+=to_string(result_real);
if(result_imaginary>=0.0)
display_temp+="+";
display_temp+=to_string(result_imaginary);
display_temp+="i";

display_entry.set_text(display_temp);
                                };

//FUNÇÕES EXPONENCIAIS E LOGARÍTMICAS
void calculator::square(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=el_number1*el_number1;
display_entry.set_text(to_string(el_result));
                         };

void calculator::cube(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=el_number1*el_number1;
el_result=el_result*el_number1;
display_entry.set_text(to_string(el_result));
                       };

void calculator::square_root(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=sqrt(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::cubic_root(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=cbrt(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::exponential(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=exp(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::neperian_logarithm(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=log(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::ten_logarithm(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=log10(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::two_logarithm(){
display_text=display_entry.get_text();
stringstream(display_text)>>el_number1;
el_result=log2(el_number1);
display_entry.set_text(to_string(el_result));
                         };

void calculator::general_exponential(){
display_temp=base1_entry.get_text();
stringstream(display_temp)>>el_number1;
display_temp=exponent_entry.get_text();
stringstream(display_temp)>>el_number2;
el_result=pow(el_number1, el_number2);
display_entry.set_text(to_string(el_result));
                         };

void calculator::general_logarithm(){
display_temp=base2_entry.get_text();
stringstream(display_temp)>>el_number1;
display_temp=log_entry.get_text();
stringstream(display_temp)>>el_number2;
el_result=log(el_number2)/log(el_number1);
display_entry.set_text(to_string(el_result));
                         };

//FUNÇÕES DE MUDANÇA DE BASE E OPERAÇÕES COM BITS
void calculator::to_bin(){
/*VARIÁVEL LOCAL*/ const char bin_digits[]="01";
display_temp="0b";
power2=1;
counter=0;

display_text=display_entry.get_text();
stringstream(display_text)>>blli_number1;
value = blli_number1;

if(value==0){
display_entry.set_text("0");
return;
            };
if(value==1){
display_entry.set_text("1");
return;
            };
if(value==2){
display_entry.set_text("10");
return;
            };

while(power2<value){
counter++;
power2=power2*2;
                   };

power2=power2/2;
do{
if(value/power2>0){
display_temp.push_back(bin_digits[1]);
residue=value%power2;
counter--;
value=residue;
power2=power2/2;
continue;
                   };

if(value/power2==0){
display_temp.push_back(bin_digits[0]);
counter--;
power2=power2/2;
continue;
                   };
  }while(counter>0);

display_entry.set_text(display_temp);
                         };

void calculator::to_oct(){
/*VARIÁVEL LOCAL*/ const char oct_digits[]="01234567";
display_temp="0";
power8=1;
counter=0;

//PROCEDIMENTOS
display_text=display_entry.get_text();
stringstream(display_text)>>blli_number1;
value = blli_number1;

if(value==8){
display_entry.set_text("10");
return;
            };

if(value<8){
display_temp.push_back(oct_digits[value]);
display_entry.set_text(display_temp);
return;
            };


while(power8<value){
counter++;
power8=power8*8;
                   };

power8=power8/8;
do{
if(value/power8>0){
display_temp.push_back(oct_digits[value/power8]);
residue=value%power8;
counter--;
value=residue;
power8=power8/8;
continue;
                   };

if(value/power8==0){
display_temp.push_back(oct_digits[0]);
counter--;
power8=power8/8;
continue;
                   };
  }while(counter>0);

display_entry.set_text(display_temp);
                         };

void calculator::to_hex(){
/*VARIÁVEL LOCAL*/ const char hex_digits[]="0123456789abcdef";
display_temp="0x";
power16=1;
counter=0;

display_text=display_entry.get_text();
stringstream(display_text)>>blli_number1;
value = blli_number1;

if(value==16){
display_entry.set_text("10");
return;
            };

if(value<16){
display_temp.push_back(hex_digits[value]);
display_entry.set_text(display_temp);
return;
            };


while(power16<value){
counter++;
power16=power16*16;
                   };

power16=power16/16;
do{
if(value/power16>0){
display_temp.push_back(hex_digits[value/power16]);
residue=value%power16;
counter--;
value=residue;
power16=power16/16;
continue;
                   };

if(value/power16==0){
display_temp.push_back(hex_digits[0]);
counter--;
power16=power16/16;
continue;
                   };
  }while(counter>0);

display_entry.set_text(display_temp);
                         };

void calculator::to_dec(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_digits_array;
display_temp="";

if(b_digits_array[0]=='0' && b_digits_array[1]!='b' && b_digits_array[1]!='x'){
bin=false; oct=true; hex=false;
for(counter=0; counter<=sizeof(b_digits_array); counter++)
display_temp.push_back(b_digits_array[counter]);
                                                                              };
if(b_digits_array[0]=='0' && b_digits_array[1]=='b'){
bin=true; oct=false; hex=false;
for(counter=2; counter<=sizeof(b_digits_array); counter++)
display_temp.push_back(b_digits_array[counter]);
                                                    };
if(b_digits_array[0]=='0' && b_digits_array[1]=='x'){
bin=false; oct=false; hex=true;
for(counter=0; counter<=sizeof(b_digits_array); counter++)
display_temp.push_back(b_digits_array[counter]);
                                                    };

if(bin==true && oct==false && hex==false)
d_result=stoull(display_temp, 0, 2);
if(bin==false && oct==true && hex==false)
d_result=stoull(display_temp, 0, 8);
if(bin==false && oct==false && hex==true)
d_result=stoull(display_temp, 0, 16);

display_entry.set_text(to_string(d_result));
                         };

void calculator::bit_and(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
b_and=true; b_or=false; b_xor=false; b_shl=false; b_shr=false;
display_entry.set_text("");
                          };

void calculator::bit_or(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
b_and=false; b_or=true; b_xor=false; b_shl=false; b_shr=false;
display_entry.set_text("");
                         };

void calculator::bit_xor(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
b_and=false; b_or=false; b_xor=true; b_shl=false; b_shr=false;
display_entry.set_text("");
                          };

void calculator::bit_not(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
display_entry.set_text(to_string((~b_number1)));
                          };

void calculator::shift_left(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
b_and=false; b_or=false; b_xor=false; b_shl=true; b_shr=false;
display_entry.set_text("");
                             };

void calculator::shift_right(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number1;
b_and=false; b_or=false; b_xor=false; b_shl=false; b_shr=true;
display_entry.set_text("");
                              };

void calculator::bit_equal(){
display_text=display_entry.get_text();
stringstream(display_text)>>b_number2;

if(b_and==true && b_or==false && b_xor==false && b_shl==false && b_shr==false)
display_entry.set_text(to_string((b_number1&b_number2)));
if(b_and==false && b_or==true && b_xor==false && b_shl==false && b_shr==false)
display_entry.set_text(to_string((b_number1|b_number2)));
if(b_and==false && b_or==false && b_xor==true && b_shl==false && b_shr==false)
display_entry.set_text(to_string((b_number1^b_number2)));
if(b_and==false && b_or==false && b_xor==false && b_shl==true && b_shr==false)
display_entry.set_text(to_string((b_number1<<b_number2)));
if(b_and==false && b_or==false && b_xor==false && b_shl==false && b_shr==true)
display_entry.set_text(to_string((b_number1>>b_number2)));
                            };

void calculator::put_a(){
const char c='a';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_b(){
const char c='b';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_c(){
const char c='c';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_d(){
const char c='d';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_e(){
const char c='e';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_f(){
const char c='f';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

void calculator::put_x(){
const char c='x';
display_text=display_entry.get_text();
display_text.push_back(c);
display_entry.set_text(display_text);
                        };

//AJUDA
void calculator::help(EntryIconPosition /* icon_pos */, const GdkEventButton* /* event */){
help_window->set_default_size(800, 800);
help_window->show();
help_window->set_title("Calculadora científica - ajuda.");
help_window->show_all_children();
                       };


bool calculator::on_key_press_event(GdkEventKey* key_event){
//Exibindo o menu de ajuda
  if((key_event->keyval == GDK_KEY_H) && (key_event->state &(GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_CONTROL_MASK){
help_window->set_default_size(800, 800);
help_window->show();
help_window->set_title("Calculadora científica - ajuda.");
help_window->show_all_children();
    return true;
  };
 //Encerrando o aplicativo
if((key_event->keyval == GDK_KEY_F4) && (key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_MOD1_MASK){
    hide();
    return true;
  };
  
  //Retornando o método base da classe em caso de falha
  return Gtk::Window::on_key_press_event(key_event);
};
