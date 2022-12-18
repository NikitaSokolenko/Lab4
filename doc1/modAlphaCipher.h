/** @file modAlphaCipher.h
 *  @author Соколенко Н.С.
 *  @version 1.0
 *  @date 18.12.2022
 *  @copyright ИБСТ ПГУ
 *  @brief Класс для шифрования перестановочным шифром  
 */

#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <cstdlib>
#include <locale>

using namespace std;

/**
 @brief Класс для шифрования и расшифрования табличным перестановочным шифром.
 Пример использования класса для шифрования и расшифрования.
 @code
modAlphaCipher cipher(std::string "КЛЮЧ");
std::string code = cipher.encode(std::string "Сообщение");
std::cout << code << std::endl;
std::string text = cipher.decode(code);
std::cout << text << std::endl;
 @endcode*/

class modAlphaCipher
{
private:
	std::string numAlpha = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< алфавит шифра.
	wstring wnumAlpha; ///< алфавит шифра типа wstring.
	std::map <wchar_t,int> alphaNum; ///< ассоциативный массив "номер по символу".
	std::vector <int> key; ///< вектор для ключа в виде чисел.
	
	/** 
 @brief Преобразование строки в целочисленный вектор.
 @details Преобразует строку в целочисленный вектор по ассоциативному массиву.
 @param [in] строка теста, std::wstring.
 @return Вектор std::vector<int>
*/
	std::vector<int> convert(const std::wstring& s); 
	
	/** 
 @brief Преобразование целочисленного вектора в строку.
 @details Преобразует целочисленный вектор в строку по ассоциативному массиву.
 @param [in] вектор std::vector<int>
 @return строка теста, std::wstring
*/
	
	std::wstring convert(const std::vector<int>& v);
	
	/** 
 @brief Проверка ключа на корректность
 @details Корректный ключ: строка букв в верхнем регистре, если регистр нижний, возвращает строку.
 в верхнем регистре. Если присутсвуют символы кроме букв, возбуждает исключение.
 @param [in] строка с ключом, std::wstring.
 @return Строка std::wstring с исправленным ключом.
 @throw std::cipher_error в случае некорректного ключа.
 @code 
 type = invalid_argument, what ="Invalid key"
 @endcode
*/
	
	std::wstring getValidKey(const std::wstring& s);
	
	/** 
 @brief Проверка текста для шифрования на корректность.
 @details Корректный текст: строка букв в верхнем регистре, если регистр нижний, возвращает строку.
 в верхнем регистре. Если присутсвуют символы кроме букв, возвращает строку без этих символов.
 Если строка пустая или в ней отсутстуют буквы, возбуждает исключение.
 @param [in] строка с текстом, std::wstring.
 @return Строка std::wstring с исправленным ключом.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Invalid open text"
 @endcode
*/
	
	std::wstring getValidOpenText(const std::wstring& s);
	
	/** 
 @brief Проверка шифротекста на корректность.
 @details Корректный текст: строка букв в верхнем регистре. Если регистр нижний,
 присутсвуют символы кроме букв или строка пустая, возбуждает исключение.
 @param [in] строка с шифротекстом, std::wstring.
 @return Строка std::wstring с шифротекстом без изменений.
 @throw std::cipher_error в случае некорректного шифротекста.
 @code 
 type = invalid_argument, what ="Invalid cipher text"
 @endcode
*/
	
	std::wstring getValidCipherText(const std::wstring & s);
public:
	modAlphaCipher()=delete; ///< запрет конструктора без параметров
	
	/** 
 @brief Конструктор для установки ключа.
 @param [in] ключ, std::wstring.
 @throw cipher_error в случае некорректного ключа. 
 Параметры исключения:
 @code 
 type = invalid_argument, what ="Invalid key"
 @endcode 
*/
	
	modAlphaCipher(const std::wstring& skey);
	
	/** 
 @brief Заширование текста табличным перестановочным шифром.
 @details Символы текста заменяются на символы из словаря
 по ключу, символы ключа явлются величиной смещения символа по алфавиту.
 Если строка пустая или в ней отсутстуют буквы, возбуждает исключение.
 @param [in] строка с текстом, std::wstring.
 @return Строка std::wstring шифротекста.
 @throw std::cipher_error в случае некорректного текста.
 @code 
 type = invalid_argument, what ="Invalid open text"
 @endcode
*/
	
	std::wstring encrypt(const std::wstring& open_text);
	
	/** 
 @brief Расширование текста табличным перестановочным шифром.
 @details Символы текста заменяются на символы из словаря.
 по ключу, символы ключа явлются величиной смещения символа по алфавиту.
 Если строка пустая или в ней присутсвуют символы кро прописных букв, возбуждает исключение.
 @param [in] строка с шифротекстом, std::wstring.
 @return Строка std::wstring расшифрованный текст.
 @throw std::cipher_error в случае некорректного шифротекста.
 @code 
 type = invalid_argument, what ="Invalid cipher text"
 @endcode
*/
	 
	std::wstring decrypt(const std::wstring& cipher_text);
};

class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg): ///< ошибка внутри класса
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg): ///< ошибка внутри класса
		std::invalid_argument(what_arg) {}
};
