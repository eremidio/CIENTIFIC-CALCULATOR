//NESTE ARQUIVO CONSTA ESTRUTURA DA CLASSE DO APP (VARIÁVEIS, WIDGETS E MÉTODOS DA CLASSE)

/*CABEÇALHO*/
#include<gtkmm.h>
#include<array>
#include<string>
#include<memory>
#include"calculadora_cientifica_ajuda.h"
using namespace std;
using namespace Glib;
using namespace Gtk;

//CLASSE DO APP

class calculator:public Window{
public:

//CONSTRUTOR E DESTRUIDOR DA CLASSE
calculator();
virtual ~calculator();

//VARIÁVEIS (BACK-END)
//VARIÁVEIS DO DISPLAY DA TELA
string display_text, display_temp;
//VARIÁVEIS PARA FUNÇÕES DE USO GERAL
long double memory_value;

//VARIÁVEIS DE PARA USO EM OPERADORES ARITMÉTICOS BÁSICOS
long double number1, number2, result;
long long int int_number1, int_number2, int_result;
bool ad, su, mu, di, mo, pe;

//VARIÁVEIS PARA OPERAÇÕES COM FUNÇÕES TRIGONOMÉTRICAS E HIPERBÓLICAS
long double th_result, th_number1, angle;
bool rad, degree, inv;

//VARIÁVEIS PARA OPERAÇÕES COM NÚMEROS COMPLEXOS
char c_digits_array[100];
bool cad, csu, cmu, cdi, cpo;
long double c_number1, c_number2, number1_real, number1_imaginary, number2_real, number2_imaginary, result_real, result_imaginary, argument, norm, c_result;

//VARIAVÉIS DE OPERAÇÕES COM FUNÇÕES EXPONENCIAIS E LOGARÍTMICAS
long double el_number1, el_number2, el_result;

//VARIÁVEIS DE OPERAÇÃO COM BITS DE NÚMEROS INTEIROS E BASES DECIMAIS
long long int value, residue, counter, power2, power8, power16;
long long int blli_number1;
int b_number1, b_number2;
unsigned long long d_result;
char b_digits_array[100];
bool bin, oct, hex;
bool b_and, b_or, b_xor, b_shl, b_shr;

//ELEMENTOS GRÁFICOS (WIDGETS)
//CAIXA DE LAYOUT PRINCIPAL
Box base;

//DISPLAY DA CALCULADORA
Box box1;
Entry display_entry;

//CAIXA PARA ALOCAR DEMAIS ELEMENTOS DA CALCULADORA
Box box2;

//TECLADO NUMÉRICO (FIXO)
Box box21;
Frame numeric_frame;
Grid numeric_grid;
Button one, two, three, four, five, six, seven, eight, nine, zero, point, equal_button; 

//MENU DE USO GERAL (FIXO)
Box box22;
Frame basic_frame;
Grid basic_grid;
Button clear_button, memory_button, memory_cache_button, plus_minus_button;

//MENU DE FUNÇÕES ESPECIAIS
Box box23;
Notebook menu_notebook;

//TECLADO DE OPERAÇÕES ARITMÉTICAS BÁSICAS
Box box231;   
Frame arithmetic_frame;
Grid arithmetic_grid;
Button plus_button, minus_button, multiply_button, divide_button, abs_button, factorial_button, inverse_button, percent_button, mod_button,
round_button, pi_button, euler_button;

//TECLADO DE FUNÇÕES TRIGONOMÉTRICAS E HIPERBÓLICAS
Box box232, box2321, box2322;
Frame trig_hyp_frame;
Grid trig_hyp_grid;
RadioButton empty_button, rad_button, degree_button, inv_button;
Button sin_button, cos_button, tan_button, sinh_button, cosh_button, tanh_button;

//TECLADO DE OPERAÇÕES COM NÚMEROS COMPLEXOS
Box box233;
Frame complex_frame;
Grid complex_grid;
Button complex_plus_button, complex_minus_button, complex_multiply_button, complex_divide_button, imaginary_button, real_button, conjugate_button, argument_button, complex_exp_button, complex_ln_button, norm_button, i_button, sign_plus_button, sign_minus_button, power_int_button, complex_sqrt_button, complex_square_button, complex_equal_button;

//TECLADO DE OPERAÇÕES COM FUNÇÕES EXEPONENCIAIS E LOGARÍTMICAS
Box box234, box2341, box2342, box23421, box23422;
Frame exp_log_frame, base1_frame, exponent_frame, base2_frame, log_frame;
Grid exp_log_grid, exp_grid, log_grid;
Entry base1_entry, exponent_entry, base2_entry, log_entry;
Button square_button, square_root_button, cube_button, cubic_root_button, exp_button, ln_button, log_button, log2_button, get_log_button, get_exp_button;
//TECLADO DE OPERAÇÕES COM BITS
Box box235;
Frame bit_frame;
Grid bit_grid;
Button bin_button, oct_button, hex_button, dec_button, and_button, or_button, xor_button, not_button, shl_button, shr_button, bit_equal_button, a_button, b_button, c_button, d_button, e_button, f_button, x_button;

//JANELA DE AJUDA
HelpWindow* help_window=new HelpWindow;

//MÉTODOS DA CLASSE
//FUNÇÕES DE USO GERAL
void clear();
void memory_register();
void memory_clear();
void change_signal();
//FUNÇÕES DO TECLADO NÚMERICO
void put_point();
void put_0();
void put_1();
void put_2();
void put_3();
void put_4();
void put_5();
void put_6();
void put_7();
void put_8();
void put_9();
//FUNÇÕES DO TECLADO DE OPERAÇÕES ARITMÉTICAS BÁSICAS
void sum();
void subtract();
void multiply();
void divide();
void absolute();
void factorial();
void invert();
void get_percent();
void congruence();
void next_integer();
void show_pi();
void show_euler();
void equal();
//FUNÇÕES DO TECLADO DE FUNÇÕES TRIGONOPMÉTRICAS E HIPERBÓLICAS
//SELEÇÃO DE UNIDADE DE MEDIDA DE ÂNGULO E FUNÇÕES INVERSAS
void null_angle();
void rad_angle();
void degree_angle();
void inverse_function();
//FUNÇÕES TRIGONOMÉTRICAS E HIPERBÓLICAS
void sine();
void cossine();
void tangent();
void hyperbolic_sine();
void hyperbolic_cossine();
void hyperbolic_tangent();
//FUNÇÕES COM NÚMEROS COMPLEXOS
void get_complex_parts();
void complex_sum();
void complex_subtract();
void complex_multiply();
void complex_divide();
void get_real();
void get_imaginary();
void conjugate();
void get_argument();
void complex_exponential();
void complex_logarithm();
void complex_norm();
void put_i();
void put_plus();
void put_minus();
void power_integer();
void complex_square_root();
void complex_square();
void equal_complex();
//FUNÇÕES EXPONENCIAIS E LOGARÍTMICAS
void square();
void square_root();
void cube();
void cubic_root();
void exponential();
void neperian_logarithm();
void ten_logarithm();
void two_logarithm();
void general_logarithm();
void general_exponential();
//FUNÇÕES DE OPERAÇÕES COM BITS E SISTEMAS DE NUMERAÇÃO
void to_bin();
void to_oct();
void to_hex();
void to_dec();
void bit_and();
void bit_or();
void bit_xor();
void bit_not();
void shift_left();
void shift_right();
void bit_equal();
void put_a();
void put_b();
void put_c();
void put_d();
void put_e();
void put_f();
void put_x();
// MOSTRAR AJUDA
void help(Gtk::EntryIconPosition icon_pos, const GdkEventButton* event);
};
