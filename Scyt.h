#pragma once
#include <string>
#include <vector>

class Scyt
{

public:
    Scyt(int columns, int per_column) : m_columns(columns), m_per_column(per_column) {}

    // ����������� ���������
    std::string encrypt(const std::string& message) const {
        std::string ciphertext;
        std::vector<std::string> rows(m_columns, std::string(m_per_column, ' '));

        // �������� ������� ��������� � ������� �� ��������
        int row = 0, col = 0;
        for (char c : message) {
            rows[col][row] = c;
            col = (col + 1) % m_columns;
            if (col == 0) {
                row++;
            }
        }

        // ������� ������������� ��������� �� �������
        for (const std::string& row : rows) {
            ciphertext += row;
        }

        return ciphertext;
    }

    // ������������ ���������
    std::string decrypt(const std::string& ciphertext) const {
        std::string message;
        std::vector<std::string> rows(m_columns, std::string(m_per_column, ' '));

        // �������� ������� �������������� ��������� � ������� �� �������
        int index = 0;
        for (std::string& row : rows) {
            row = ciphertext.substr(index, m_per_column);
            index += m_per_column;
        }

        // ������� �������������� ��������� �� ��������
        for (int row = 0; row < m_per_column; row++) {
            for (int col = 0; col < m_columns; col++) {
                message += rows[col][row];
            }
        }

        return message;
    }

private:
    int m_columns;    // ���������� ��������
    int m_per_column; // ���������� �������� � ����� ������
};