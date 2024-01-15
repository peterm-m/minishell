#include <time.h>
#include <stdlib.h>
#include "common.h"
//void syntax(t_dlst *lex)

/*
Casos de prueba:
echo "hola" | cat
*/

void	test_syntax(void)
{
	//tt_and_if
	TEST_CHECK(table_action(0, tt_and_if) + 32== 126);
	TEST_CHECK(table_action(1, tt_and_if) + 32== 126);
	TEST_CHECK(table_action(2, tt_and_if) + 32== 126);
	TEST_CHECK(table_action(3, tt_and_if) + 32== 53);
	TEST_CHECK(table_action(4, tt_and_if) + 32== 90);
	TEST_CHECK(table_action(5, tt_and_if) + 32== 93);
	TEST_CHECK(table_action(6, tt_and_if) + 32== 95);
	TEST_CHECK(table_action(7, tt_and_if) + 32 == 96);
	TEST_CHECK(table_action(8, tt_and_if) + 32 == 104);
	TEST_CHECK(table_action(9, tt_and_if) + 32 == 106);
	TEST_CHECK(table_action(10, tt_and_if) + 32 == 98);
	TEST_CHECK(table_action(11, tt_and_if) + 32 == 99);
	TEST_CHECK(table_action(12, tt_and_if) + 32 == 107);
	TEST_CHECK(table_action(13, tt_and_if) + 32 == 109);
	TEST_CHECK(table_action(14, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(15, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(16, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(17, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(18, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(19, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(20, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(21, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(22, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(23, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(24, tt_and_if) + 32 == 97);
	TEST_CHECK(table_action(25, tt_and_if) + 32 == 115);
	TEST_CHECK(table_action(26, tt_and_if) + 32 == 103);
	TEST_CHECK(table_action(27, tt_and_if) + 32 == 108);
	TEST_CHECK(table_action(28, tt_and_if) + 32 == 110);
	TEST_CHECK(table_action(29, tt_and_if) + 32 == 105);
	TEST_CHECK(table_action(30, tt_and_if) + 32 == 111);
	TEST_CHECK(table_action(31, tt_and_if) + 32 == 113);
	TEST_CHECK(table_action(32, tt_and_if) + 32 == 53);
	TEST_CHECK(table_action(33, tt_and_if) + 32 == 53);
	TEST_CHECK(table_action(34, tt_and_if) + 32 == 117);
	TEST_CHECK(table_action(35, tt_and_if) + 32 == 118);
	TEST_CHECK(table_action(36, tt_and_if) + 32 == 119);
	TEST_CHECK(table_action(37, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(38, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(39, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(40, tt_and_if) + 32 == 126);
	TEST_CHECK(table_action(41, tt_and_if) + 32 == 123);
	TEST_CHECK(table_action(42, tt_and_if) + 32 == 91);
	TEST_CHECK(table_action(43, tt_and_if) + 32 == 92);
	TEST_CHECK(table_action(44, tt_and_if) + 32 == 94);
	TEST_CHECK(table_action(45, tt_and_if) + 32 == 116);
	TEST_CHECK(table_action(46, tt_and_if) + 32 == 102);
	TEST_CHECK(table_action(47, tt_and_if) + 32 == 112);
	TEST_CHECK(table_action(48, tt_and_if) + 32 == 114);
	TEST_CHECK(table_action(49, tt_and_if) + 32 == 100);
	TEST_CHECK(table_action(50, tt_and_if) + 32 == 101);
	TEST_CHECK(table_action(51, tt_and_if) + 32 == 120);
	TEST_CHECK(table_action(52, tt_and_if) + 32 == 121);
	TEST_CHECK(table_action(53, tt_and_if) + 32 == 122);
	TEST_CHECK(table_action(54, tt_and_if) + 32 == 124);

	//tt_or_if

	TEST_CHECK(table_action(0, tt_or_if) + 32== 126);
	TEST_CHECK(table_action(1, tt_or_if) + 32== 126);
	TEST_CHECK(table_action(2, tt_or_if) + 32== 126);
	TEST_CHECK(table_action(3, tt_or_if) + 32== 54);
	TEST_CHECK(table_action(4, tt_or_if) + 32== 90);
	TEST_CHECK(table_action(5, tt_or_if) + 32== 93);
	TEST_CHECK(table_action(6, tt_or_if) + 32== 95);
	TEST_CHECK(table_action(7, tt_or_if) + 32 == 96);
	TEST_CHECK(table_action(8, tt_or_if) + 32 == 104);
	TEST_CHECK(table_action(9, tt_or_if) + 32 == 106);
	TEST_CHECK(table_action(10, tt_or_if) + 32 == 98);
	TEST_CHECK(table_action(11, tt_or_if) + 32 == 99);
	TEST_CHECK(table_action(12, tt_or_if) + 32 == 107);
	TEST_CHECK(table_action(13, tt_or_if) + 32 == 109);
	TEST_CHECK(table_action(14, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(15, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(16, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(17, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(18, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(19, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(20, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(21, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(22, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(23, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(24, tt_or_if) + 32 == 97);
	TEST_CHECK(table_action(25, tt_or_if) + 32 == 115);
	TEST_CHECK(table_action(26, tt_or_if) + 32 == 103);
	TEST_CHECK(table_action(27, tt_or_if) + 32 == 108);
	TEST_CHECK(table_action(28, tt_or_if) + 32 == 110);
	TEST_CHECK(table_action(29, tt_or_if) + 32 == 105);
	TEST_CHECK(table_action(30, tt_or_if) + 32 == 111);
	TEST_CHECK(table_action(31, tt_or_if) + 32 == 113);
	TEST_CHECK(table_action(32, tt_or_if) + 32 == 54);
	TEST_CHECK(table_action(33, tt_or_if) + 32 == 54);
	TEST_CHECK(table_action(34, tt_or_if) + 32 == 117);
	TEST_CHECK(table_action(35, tt_or_if) + 32 == 118);
	TEST_CHECK(table_action(36, tt_or_if) + 32 == 119);
	TEST_CHECK(table_action(37, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(38, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(39, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(40, tt_or_if) + 32 == 126);
	TEST_CHECK(table_action(41, tt_or_if) + 32 == 123);
	TEST_CHECK(table_action(42, tt_or_if) + 32 == 91);
	TEST_CHECK(table_action(43, tt_or_if) + 32 == 92);
	TEST_CHECK(table_action(44, tt_or_if) + 32 == 94);
	TEST_CHECK(table_action(45, tt_or_if) + 32 == 116);
	TEST_CHECK(table_action(46, tt_or_if) + 32 == 102);
	TEST_CHECK(table_action(47, tt_or_if) + 32 == 112);
	TEST_CHECK(table_action(48, tt_or_if) + 32 == 114);
	TEST_CHECK(table_action(49, tt_or_if) + 32 == 100);
	TEST_CHECK(table_action(50, tt_or_if) + 32 == 101);
	TEST_CHECK(table_action(51, tt_or_if) + 32 == 120);
	TEST_CHECK(table_action(52, tt_or_if) + 32 == 121);
	TEST_CHECK(table_action(53, tt_or_if) + 32 == 122);
	TEST_CHECK(table_action(54, tt_or_if) + 32 == 124);	

	//tt_pipe

	TEST_CHECK(table_action(0, tt_pipe) + 32== 126);
	TEST_CHECK(table_action(1, tt_pipe) + 32== 126);
	TEST_CHECK(table_action(2, tt_pipe) + 32== 126);
	TEST_CHECK(table_action(3, tt_pipe) + 32== 126);
	TEST_CHECK(table_action(4, tt_pipe) + 32== 55);
	TEST_CHECK(table_action(5, tt_pipe) + 32== 93);
	TEST_CHECK(table_action(6, tt_pipe) + 32== 95);
	TEST_CHECK(table_action(7, tt_pipe) + 32 == 96);
	TEST_CHECK(table_action(8, tt_pipe) + 32 == 104);
	TEST_CHECK(table_action(9, tt_pipe) + 32 == 106);
	TEST_CHECK(table_action(10, tt_pipe) + 32 == 98);
	TEST_CHECK(table_action(11, tt_pipe) + 32 == 99);
	TEST_CHECK(table_action(12, tt_pipe) + 32 == 107);
	TEST_CHECK(table_action(13, tt_pipe) + 32 == 109);
	TEST_CHECK(table_action(14, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(15, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(16, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(17, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(18, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(19, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(20, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(21, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(22, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(23, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(24, tt_pipe) + 32 == 97);
	TEST_CHECK(table_action(25, tt_pipe) + 32 == 115);
	TEST_CHECK(table_action(26, tt_pipe) + 32 == 103);
	TEST_CHECK(table_action(27, tt_pipe) + 32 == 108);
	TEST_CHECK(table_action(28, tt_pipe) + 32 == 110);
	TEST_CHECK(table_action(29, tt_pipe) + 32 == 105);
	TEST_CHECK(table_action(30, tt_pipe) + 32 == 111);
	TEST_CHECK(table_action(31, tt_pipe) + 32 == 113);
	TEST_CHECK(table_action(32, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(33, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(34, tt_pipe) + 32 == 117);
	TEST_CHECK(table_action(35, tt_pipe) + 32 == 118);
	TEST_CHECK(table_action(36, tt_pipe) + 32 == 119);
	TEST_CHECK(table_action(37, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(38, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(39, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(40, tt_pipe) + 32 == 126);
	TEST_CHECK(table_action(41, tt_pipe) + 32 == 123);
	TEST_CHECK(table_action(42, tt_pipe) + 32 == 55);
	TEST_CHECK(table_action(43, tt_pipe) + 32 == 55);
	TEST_CHECK(table_action(44, tt_pipe) + 32 == 94);
	TEST_CHECK(table_action(45, tt_pipe) + 32 == 116);
	TEST_CHECK(table_action(46, tt_pipe) + 32 == 102);
	TEST_CHECK(table_action(47, tt_pipe) + 32 == 112);
	TEST_CHECK(table_action(48, tt_pipe) + 32 == 114);
	TEST_CHECK(table_action(49, tt_pipe) + 32 == 100);
	TEST_CHECK(table_action(50, tt_pipe) + 32 == 101);
	TEST_CHECK(table_action(51, tt_pipe) + 32 == 120);
	TEST_CHECK(table_action(52, tt_pipe) + 32 == 121);
	TEST_CHECK(table_action(53, tt_pipe) + 32 == 122);
	TEST_CHECK(table_action(54, tt_pipe) + 32 == 124);

	//tt_lbrace

	TEST_CHECK(table_action(0, tt_lbrace) + 32== 46);
	TEST_CHECK(table_action(1, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(2, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(3, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(4, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(5, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(6, tt_lbrace) + 32== 126);
	TEST_CHECK(table_action(7, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(8, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(9, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(10, tt_lbrace) + 32 ==126);
	TEST_CHECK(table_action(11, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(12, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(13, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(14, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(15, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(16, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(17, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(18, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(19, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(20, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(21, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(22, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(23, tt_lbrace) + 32 == 46);
	TEST_CHECK(table_action(24, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(25, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(26, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(27, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(28, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(29, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(30, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(31, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(32, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(33, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(34, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(35, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(36, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(37, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(38, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(39, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(40, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(41, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(42, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(43, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(44, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(45, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(46, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(47, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(48, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(49, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(50, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(51, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(52, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(53, tt_lbrace) + 32 == 126);
	TEST_CHECK(table_action(54, tt_lbrace) + 32 == 126);

	//tt_rbrace

	TEST_CHECK(table_action(0, tt_rbrace) + 32== 126);
	TEST_CHECK(table_action(1, tt_rbrace) + 32== 126);
	TEST_CHECK(table_action(2, tt_rbrace) + 32== 126);
	TEST_CHECK(table_action(3, tt_rbrace) + 32== 126);
	TEST_CHECK(table_action(4, tt_rbrace) + 32== 90);
	TEST_CHECK(table_action(5, tt_rbrace) + 32== 93);
	TEST_CHECK(table_action(6, tt_rbrace) + 32== 95);
	TEST_CHECK(table_action(7, tt_rbrace) + 32 == 96);
	TEST_CHECK(table_action(8, tt_rbrace) + 32 == 104);
	TEST_CHECK(table_action(9, tt_rbrace) + 32 == 106);
	TEST_CHECK(table_action(10, tt_rbrace) + 32 == 98);
	TEST_CHECK(table_action(11, tt_rbrace) + 32 == 99);
	TEST_CHECK(table_action(12, tt_rbrace) + 32 == 107);
	TEST_CHECK(table_action(13, tt_rbrace) + 32 == 109);
	TEST_CHECK(table_action(14, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(15, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(16, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(17, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(18, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(19, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(20, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(21, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(22, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(23, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(24, tt_rbrace) + 32 == 97);
	TEST_CHECK(table_action(25, tt_rbrace) + 32 == 115);
	TEST_CHECK(table_action(26, tt_rbrace) + 32 == 103);
	TEST_CHECK(table_action(27, tt_rbrace) + 32 == 108);
	TEST_CHECK(table_action(28, tt_rbrace) + 32 == 110);
	TEST_CHECK(table_action(29, tt_rbrace) + 32 == 105);
	TEST_CHECK(table_action(30, tt_rbrace) + 32 == 111);
	TEST_CHECK(table_action(31, tt_rbrace) + 32 == 113);
	TEST_CHECK(table_action(32, tt_rbrace) + 32 == 81);
	TEST_CHECK(table_action(33, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(34, tt_rbrace) + 32 == 117);
	TEST_CHECK(table_action(35, tt_rbrace) + 32 == 118);
	TEST_CHECK(table_action(36, tt_rbrace) + 32 == 119);
	TEST_CHECK(table_action(37, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(38, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(39, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(40, tt_rbrace) + 32 == 126);
	TEST_CHECK(table_action(41, tt_rbrace) + 32 == 123);
	TEST_CHECK(table_action(42, tt_rbrace) + 32 == 91);
	TEST_CHECK(table_action(43, tt_rbrace) + 32 == 92);
	TEST_CHECK(table_action(44, tt_rbrace) + 32 == 94);
	TEST_CHECK(table_action(45, tt_rbrace) + 32 == 116);
	TEST_CHECK(table_action(46, tt_rbrace) + 32 == 102);
	TEST_CHECK(table_action(47, tt_rbrace) + 32 == 112);
	TEST_CHECK(table_action(48, tt_rbrace) + 32 == 114);
	TEST_CHECK(table_action(49, tt_rbrace) + 32 == 100);
	TEST_CHECK(table_action(50, tt_rbrace) + 32 == 101);
	TEST_CHECK(table_action(51, tt_rbrace) + 32 == 120);
	TEST_CHECK(table_action(52, tt_rbrace) + 32 == 121);
	TEST_CHECK(table_action(53, tt_rbrace) + 32 == 122);
	TEST_CHECK(table_action(54, tt_rbrace) + 32 == 124);	

	//tt_lbraket

	TEST_CHECK(table_action(0, tt_lbraket) + 32== 47);
	TEST_CHECK(table_action(1, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(2, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(3, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(4, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(5, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(6, tt_lbraket) + 32== 126);
	TEST_CHECK(table_action(7, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(8, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(9, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(10, tt_lbraket) + 32 ==126);
	TEST_CHECK(table_action(11, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(12, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(13, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(14, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(15, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(16, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(17, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(18, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(19, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(20, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(21, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(22, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(23, tt_lbraket) + 32 == 47);
	TEST_CHECK(table_action(24, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(25, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(26, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(27, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(28, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(29, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(30, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(31, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(32, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(33, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(34, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(35, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(36, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(37, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(38, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(39, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(40, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(41, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(42, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(43, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(44, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(45, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(46, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(47, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(48, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(49, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(50, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(51, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(52, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(53, tt_lbraket) + 32 == 126);
	TEST_CHECK(table_action(54, tt_lbraket) + 32 == 126);

	//tt_rbraket

	TEST_CHECK(table_action(0, tt_rbraket) + 32== 126);
	TEST_CHECK(table_action(1, tt_rbraket) + 32== 126);
	TEST_CHECK(table_action(2, tt_rbraket) + 32== 126);
	TEST_CHECK(table_action(3, tt_rbraket) + 32== 126);
	TEST_CHECK(table_action(4, tt_rbraket) + 32== 90);
	TEST_CHECK(table_action(5, tt_rbraket) + 32== 93);
	TEST_CHECK(table_action(6, tt_rbraket) + 32== 95);
	TEST_CHECK(table_action(7, tt_rbraket) + 32 == 96);
	TEST_CHECK(table_action(8, tt_rbraket) + 32 == 104);
	TEST_CHECK(table_action(9, tt_rbraket) + 32 == 106);
	TEST_CHECK(table_action(10, tt_rbraket) + 32 == 98);
	TEST_CHECK(table_action(11, tt_rbraket) + 32 == 99);
	TEST_CHECK(table_action(12, tt_rbraket) + 32 == 107);
	TEST_CHECK(table_action(13, tt_rbraket) + 32 == 109);
	TEST_CHECK(table_action(14, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(15, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(16, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(17, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(18, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(19, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(20, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(21, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(22, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(23, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(24, tt_rbraket) + 32 == 97);
	TEST_CHECK(table_action(25, tt_rbraket) + 32 == 115);
	TEST_CHECK(table_action(26, tt_rbraket) + 32 == 103);
	TEST_CHECK(table_action(27, tt_rbraket) + 32 == 108);
	TEST_CHECK(table_action(28, tt_rbraket) + 32 == 110);
	TEST_CHECK(table_action(29, tt_rbraket) + 32 == 105);
	TEST_CHECK(table_action(30, tt_rbraket) + 32 == 111);
	TEST_CHECK(table_action(31, tt_rbraket) + 32 == 113);
	TEST_CHECK(table_action(32, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(33, tt_rbraket) + 32 == 82);
	TEST_CHECK(table_action(34, tt_rbraket) + 32 == 117);
	TEST_CHECK(table_action(35, tt_rbraket) + 32 == 118);
	TEST_CHECK(table_action(36, tt_rbraket) + 32 == 119);
	TEST_CHECK(table_action(37, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(38, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(39, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(40, tt_rbraket) + 32 == 126);
	TEST_CHECK(table_action(41, tt_rbraket) + 32 == 123);
	TEST_CHECK(table_action(42, tt_rbraket) + 32 == 91);
	TEST_CHECK(table_action(43, tt_rbraket) + 32 == 92);
	TEST_CHECK(table_action(44, tt_rbraket) + 32 == 94);
	TEST_CHECK(table_action(45, tt_rbraket) + 32 == 116);
	TEST_CHECK(table_action(46, tt_rbraket) + 32 == 102);
	TEST_CHECK(table_action(47, tt_rbraket) + 32 == 112);
	TEST_CHECK(table_action(48, tt_rbraket) + 32 == 114);
	TEST_CHECK(table_action(49, tt_rbraket) + 32 == 100);
	TEST_CHECK(table_action(50, tt_rbraket) + 32 == 101);
	TEST_CHECK(table_action(51, tt_rbraket) + 32 == 120);
	TEST_CHECK(table_action(52, tt_rbraket) + 32 == 121);
	TEST_CHECK(table_action(53, tt_rbraket) + 32 == 122);
	TEST_CHECK(table_action(54, tt_rbraket) + 32 == 124);

	//WORD

	TEST_CHECK(table_action(0, tt_word) + 32== 41);
	TEST_CHECK(table_action(1, tt_word) + 32== 126);
	TEST_CHECK(table_action(2, tt_word) + 32== 126);
	TEST_CHECK(table_action(3, tt_word) + 32== 126);
	TEST_CHECK(table_action(4, tt_word) + 32== 126);
	TEST_CHECK(table_action(5, tt_word) + 32== 126);
	TEST_CHECK(table_action(6, tt_word) + 32== 126);
	TEST_CHECK(table_action(7, tt_word) + 32 == 126);
	TEST_CHECK(table_action(8, tt_word) + 32 == 58);
	TEST_CHECK(table_action(9, tt_word) + 32 == 63);
	TEST_CHECK(table_action(10, tt_word) + 32 == 126);
	TEST_CHECK(table_action(11, tt_word) + 32 == 126);
	TEST_CHECK(table_action(12, tt_word) + 32 == 107);
	TEST_CHECK(table_action(13, tt_word) + 32 == 109);
	TEST_CHECK(table_action(14, tt_word) + 32 == 41);
	TEST_CHECK(table_action(15, tt_word) + 32 == 41);
	TEST_CHECK(table_action(16, tt_word) + 32 == 66);
	TEST_CHECK(table_action(17, tt_word) + 32 == 67);
	TEST_CHECK(table_action(18, tt_word) + 32 == 68);
	TEST_CHECK(table_action(19, tt_word) + 32 == 126);
	TEST_CHECK(table_action(20, tt_word) + 32 == 73);
	TEST_CHECK(table_action(21, tt_word) + 32 == 41);
	TEST_CHECK(table_action(22, tt_word) + 32 == 41);
	TEST_CHECK(table_action(23, tt_word) + 32 == 41);
	TEST_CHECK(table_action(24, tt_word) + 32 == 126);
	TEST_CHECK(table_action(25, tt_word) + 32 == 126);
	TEST_CHECK(table_action(26, tt_word) + 32 == 63);
	TEST_CHECK(table_action(27, tt_word) + 32 == 108);
	TEST_CHECK(table_action(28, tt_word) + 32 == 110);
	TEST_CHECK(table_action(29, tt_word) + 32 == 80);
	TEST_CHECK(table_action(30, tt_word) + 32 == 111);
	TEST_CHECK(table_action(31, tt_word) + 32 == 113);
	TEST_CHECK(table_action(32, tt_word) + 32 == 126);
	TEST_CHECK(table_action(33, tt_word) + 32 == 126);
	TEST_CHECK(table_action(34, tt_word) + 32 == 117);
	TEST_CHECK(table_action(35, tt_word) + 32 == 118);
	TEST_CHECK(table_action(36, tt_word) + 32 == 119);
	TEST_CHECK(table_action(37, tt_word) + 32 == 83);
	TEST_CHECK(table_action(38, tt_word) + 32 == 84);
	TEST_CHECK(table_action(39, tt_word) + 32 == 85);
	TEST_CHECK(table_action(40, tt_word) + 32 == 86);
	TEST_CHECK(table_action(41, tt_word) + 32 == 123);
	TEST_CHECK(table_action(42, tt_word) + 32 == 126);
	TEST_CHECK(table_action(43, tt_word) + 32 == 126);
	TEST_CHECK(table_action(44, tt_word) + 32 == 126);
	TEST_CHECK(table_action(45, tt_word) + 32 == 126);
	TEST_CHECK(table_action(46, tt_word) + 32 == 80);
	TEST_CHECK(table_action(47, tt_word) + 32 == 112);
	TEST_CHECK(table_action(48, tt_word) + 32 == 114);
	TEST_CHECK(table_action(49, tt_word) + 32 == 126);
	TEST_CHECK(table_action(50, tt_word) + 32 == 126);
	TEST_CHECK(table_action(51, tt_word) + 32 == 120);
	TEST_CHECK(table_action(52, tt_word) + 32 == 121);
	TEST_CHECK(table_action(53, tt_word) + 32 == 122);
	TEST_CHECK(table_action(54, tt_word) + 32 == 124);

	//ASSIGMENT T_WORD

	TEST_CHECK(table_action(0, tt_assignment_word) + 32== 45);
	TEST_CHECK(table_action(1, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(2, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(3, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(4, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(5, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(6, tt_assignment_word) + 32== 126);
	TEST_CHECK(table_action(7, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(8, tt_assignment_word) + 32 == 60);
	TEST_CHECK(table_action(9, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(10, tt_assignment_word) + 32 ==126);
	TEST_CHECK(table_action(11, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(12, tt_assignment_word) + 32 == 107);
	TEST_CHECK(table_action(13, tt_assignment_word) + 32 == 109);
	TEST_CHECK(table_action(14, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(15, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(16, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(17, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(18, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(19, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(20, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(21, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(22, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(23, tt_assignment_word) + 32 == 45);
	TEST_CHECK(table_action(24, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(25, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(26, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(27, tt_assignment_word) + 32 == 108);
	TEST_CHECK(table_action(28, tt_assignment_word) + 32 == 110);
	TEST_CHECK(table_action(29, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(30, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(31, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(32, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(33, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(34, tt_assignment_word) + 32 == 117);
	TEST_CHECK(table_action(35, tt_assignment_word) + 32 == 118);
	TEST_CHECK(table_action(36, tt_assignment_word) + 32 == 119);
	TEST_CHECK(table_action(37, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(38, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(39, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(40, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(41, tt_assignment_word) + 32 == 123);
	TEST_CHECK(table_action(42, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(43, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(44, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(45, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(46, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(47, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(48, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(49, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(50, tt_assignment_word) + 32 == 126);
	TEST_CHECK(table_action(51, tt_assignment_word) + 32 == 120);
	TEST_CHECK(table_action(52, tt_assignment_word) + 32 == 121);
	TEST_CHECK(table_action(53, tt_assignment_word) + 32 == 122);
	TEST_CHECK(table_action(54, tt_assignment_word) + 32 == 124);

	//tt_less


	//tt_great


	//tt_dgreat


	//tt_io_number


	//tt_dless

	
	//tt_end
}