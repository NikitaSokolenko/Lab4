/** @file modAlphaCipher.h
 *  @author Соколенко Н.С.
 *  @version 1.0
 *  @date 18.12.2022
 *  @copyright ИБСТ ПГУ
 *  @brief Класс для шифрования перестановочным шифром  
 */

#pragma once

#include <string>

using namespace std;

class modAlphaCipher
{
private:
	int key; ///< Ключ для шифрования
public:
	modAlphaCipher()=delete; ///< запрет конструктора без параметров
	
	/** 
 @brief Конструктор для установки ключа. Ключ является целым положительным числом.
 @param [in] ключ, std::string.
 @throw cipher_error в случае некорректного ключа. 
 Параметры исключения:
 @code 
 type = invalid_argument, what ="Invalid key"
 @endcode 
*/
	
	modAlphaCipher(string skey);
	
	/** 
 @brief Заширование текста маршрутным перестановочным шифром.
 @details Символы текста перставляются по алгоритму маршрутной перестановки:
 В качестве ключа берётся количество столбцов таблицы. Маршрут записи: по
 горизонтали слева направо, сверху вниз. Маршрут считывания: сверху вниз, справа налево.
 Если строка пустая или ключ больше половины текста для шифрования, возбуждает исключение.
 @param [in] строка с текстом, std::string.
 @return Строка std::string шифротекста.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Key is too long", "Empty message"
 @endcode
*/
	
	string encrypt(string& open_text);
	
	/** 
 @brief Расширование текста маршрутным перестановочным шифром.
 @details Символы текста перставляются по алгоритму маршрутной перестановки:
 В качестве ключа берётся количество столбцов таблицы. Маршрут записи: сверху вниз, справа налево. 
 Маршрут считывания: по горизонтали слева направо, сверху вниз.
 Если строка пустая или ключ больше половины шифротекста, возбуждает исключение.
 @param [in] строка с шифротекстом, std::string.
 @return Строка std::string текста.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Key is too long", "Empty message"
 @endcode
*/
	
	string decrypt(string& cipher_text);
	
	/** 
 @brief Проверка ключа на корректность.
 @details Корректный текст: целое положительное число не больше половины
 длины текста. Если ключ не является целым положительным числом, возбуждает исключение.
 @param [in] строка с ключом, std::string.
 @throw std::cipher_error в случае некорректного ключа.
 @code 
 type = invalid_argument, what ="Invalid key"
 @endcode
*/
	
	void KeyCheck(string& skey);
	
	/** 
 @brief Проверка длины теста.
 @details Корректный текст: строка символов в 2 или более раза длинне ключа.
 Если ключ слишком длинный, возбуждает исключение. 
 @param [in] строка с текстаом, std::string.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Key is too long"
 @endcode
*/
	
	void LengthCheck(int& skey, string& stext);
	
	/** 
 @brief Проверка теста на пустоту.
 @details Если текст пустой, возбуждает исключение. 
 @param [in] строка с текстаом, std::string.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Empty message"
 @endcode
*/

	void TextCheck(string& stext);
};

class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg): ///< ошибка внутри класса
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg): ///< ошибка внутри класса
		std::invalid_argument(what_arg) {}
};
