#pragma once
#include <string>
#include <vector>

class Scyt
{

public:
    Scyt(int columns, int per_column) : m_columns(columns), m_per_column(per_column) {}

    // Зашифровать сообщение
    std::string encrypt(const std::string& message) const {
        std::string ciphertext;
        std::vector<std::string> rows(m_columns, std::string(m_per_column, ' '));

        // Записать символы сообщения в таблицу по столбцам
        int row = 0, col = 0;
        for (char c : message) {
            rows[col][row] = c;
            col = (col + 1) % m_columns;
            if (col == 0) {
                row++;
            }
        }

        // Собрать зашифрованное сообщение по строкам
        for (const std::string& row : rows) {
            ciphertext += row;
        }

        return ciphertext;
    }

    // Расшифровать сообщение
    std::string decrypt(const std::string& ciphertext) const {
        std::string message;
        std::vector<std::string> rows(m_columns, std::string(m_per_column, ' '));

        // Записать символы зашифрованного сообщения в таблицу по строкам
        int index = 0;
        for (std::string& row : rows) {
            row = ciphertext.substr(index, m_per_column);
            index += m_per_column;
        }

        // Собрать расшифрованное сообщение по столбцам
        for (int row = 0; row < m_per_column; row++) {
            for (int col = 0; col < m_columns; col++) {
                message += rows[col][row];
            }
        }

        return message;
    }

private:
    int m_columns;    // количество столбцов
    int m_per_column; // количество символов в одной строке
};