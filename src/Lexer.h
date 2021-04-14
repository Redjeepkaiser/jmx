#ifndef JMX_LEXER_H
#define JMX_LEXER_H


class Lexer {
private:
    std::string text;
    int current_position;
    char current_char;
    Token current_token;

    int get_integer();

    Token get_next_token();
};


public:

Interpreter() {};

friend std::ostream &
operator<<(std::ostream &ostream, const Interpreter &interpreter);

int interpret(std::string input);

};


#endif //JMX_LEXER_H
