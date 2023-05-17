/* Fig.: TokenBuilder
 * ======================================================
 * Filename: TokenBuilder.h
 * =====================================================
 * Abstract: Header модуль
 * лаборатоной лексическому анализатору
 * Description: парсит входной файл и выводит файл-таблицу
 * лексем
 * Author: Новиков Илья
 * Platform: Linux
 ==================================================== */
#pragma once

#include <cstddef>
#include <string>

using std::string;
using std::size_t;

class TokenBuilder {
  /**
   * @var Context
   */
 protected:
     TokenType token_type;
     string token_value;
     size_t line_number_;
     size_t column_number_;

 public:
     TokenBuilder();
     ~TokenBuilder();
     void set_type(TokenType);
     void set_position(size_t, size_t);
     void add_value(string);
     Token build();
};
