/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{
	/*
	@@@@@@@@@
	@-------@
	@-@@@@@-@
	@-@---@-@
	@-@@@@@-@
	@-------@
	@@@@@@@@@
	*/

	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));

	/*
	###
	#&#
	#&#
	#&#
	#&#
	#&#
	###
	*/
	CHECK(nospaces(mat(3, 7, '#', '&')) == nospaces("###\n#&#\n#&#\n#&#\n#&#\n#&#\n###"));
	/* @ */
	CHECK(nospaces(mat(1, 1, '@', '!')) == nospaces("@"));
	/*
	+++++
	+---+
	+-+-+
	+---+
	+++++
	*/
	CHECK(nospaces(mat(5, 5, '+', '-')) == nospaces("+++++\n+---+\n+-+-+\n+---+\n+++++"));

	/*
	*************
	*!!!!!!!!!!!*
	*!*********!*
	*!*!!!!!!!*!*
	*!*!*****!*!*
	*!*!*!!!*!*!*
	*!*!*!*!*!*!*
	*!*!*!*!*!*!*
	*!*!*!*!*!*!*
	*!*!*!!!*!*!*
	*!*!*****!*!*
	*!*!!!!!!!*!*
	*!*********!*
	*!!!!!!!!!!!*
	*************
	*/

	CHECK(nospaces(mat(13, 15, '*', '!')) == nospaces("*************\n*!!!!!!!!!!!*\n*!*********!*\n*!*!!!!!!!*!*\n*!*!*****!*!*\n*!*!*!!!*!*!*\n*!*!*!*!*!*!*\n*!*!*!*!*!*!*\n*!*!*!*!*!*!*\n*!*!*!!!*!*!*\n*!*!*****!*!*\n*!*!!!!!!!*!*\n*!*********!*\n*!!!!!!!!!!!*\n*************"));

	/*
	_________
	_-------_
	_-_____-_
	_-------_
	_________
	*/
	CHECK(nospaces(mat(9, 5, '_', '-')) == nospaces("_________\n_-------_\n_-_____-_\n_-------_\n_________"));

	/*
	;;;;;;;;;;;
	;.........;
	;.;;;;;;;.;
	;.;.....;.;
	;.;;;;;;;.;
	;.........;
	;;;;;;;;;;;
	*/
	CHECK(nospaces(mat(11, 7, ';', '.')) == nospaces(";;;;;;;;;;;\n;.........;\n;.;;;;;;;.;\n;.;.....;.;\n;.;;;;;;;.;\n;.........;\n;;;;;;;;;;;"));

	/* <<<<<<< */
	CHECK(nospaces(mat(7, 1, '<', '>')) == nospaces("<<<<<<<"));

	/*
	~~~~~~~~~
	~-------~
	~-~~~~~-~
	~-------~
	~~~~~~~~~
	*/
	CHECK(nospaces(mat(9, 5, '~', '-')) == nospaces("~~~~~~~~~\n~-------~\n~-~~~~~-~\n~-------~\n~~~~~~~~~"));
}

TEST_CASE("Bad input")
{
	// 	/* invalid numbers - negetiv or even numbers */
	CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(4, 4, '#', '&'));
	CHECK_THROWS(mat(5, 6, '*', '!'));
	CHECK_THROWS(mat(0, 7, '-', '^'));
	CHECK_THROWS(mat(0, 0, '%', '&'));
	CHECK_THROWS(mat(-2, 6, '#', '&'));
	CHECK_THROWS(mat(15, 4, '@', '~'));
	CHECK_THROWS(mat(21, 0, '-', '^'));
	CHECK_THROWS(mat(-1, -5, '!', '?'));
	CHECK_THROWS(mat(3, 240, '#', '%'));
	CHECK_THROWS(mat(0, -7, ']', '['));

	/* invalid chars in input - spaces */
	CHECK_THROWS(mat(3, 21, ' ', '%'));
	CHECK_THROWS(mat(19, 17, '#', '\t'));
	CHECK_THROWS(mat(7, 1, '\n', '!'));
	CHECK_THROWS(mat(35, 15, ' ', '\r'));
	CHECK_THROWS(mat(7, 1, '\n', '!'));
	CHECK_THROWS(mat(19, 7, ' ', '^'));
	CHECK_THROWS(mat(1, 1, '\t', '-'));
	CHECK_THROWS(mat(11, 13, ' ', ' '));
}
