#include<iostream>




class Token {
    private:
        TokenType type;
        string value;

    public:
        Token(TokenType type, string value) {
            this->type = type;
            this->value = value;
        }

        friend std::ostream& operator<<(std::ostream& ostream, const Token& token) {
            ostream << token.type << '\t' << token.value << std::endl;
            return ostream;
        }

        TokenType get_type() {
            return type;
        }
};

class Interpreter {
    std::string text;
    int current_position;
    char current_char;
    Token current_token;

    public:
        Interpreter(){};
        friend std::ostream& operator<<(std::ostream& ostream, const Interpreter& interpreter);
        int interpret(std::string input);

    private:
        int get_integer();
        Token get_next_token();
};

std::ostream& operator<<(std::ostream& ostream, const Interpreter& interpreter) {
    ostream << interpreter.text;
    return ostream;
}

int Interpreter::get_integer() {
    std::string complete_integer;

    while (std::isdigit(this->current_char)) {
        complete_integer.append(this->current_char);
        this->current_position += 1;
        this->current_char = this->text[this->current_position];
    }

    return std::stoi(complete_integer);
}

Token Interpreter::get_next_token() {
    while (this->current_char) {

        if (std::isdigit(this->current_char)) {
            return Token(this->get_integer());
        } else if (this->current_char.is_whitespace()) {
        } else if (this->current_char == "+") {
        } else if (this->current_char == "-") {
        }
    }
}

int Interpreter::interpret(std::string input) {
    text = input;
    current_position = 0;
    current_char = text[current_position];

    current_token = get_next_token();
    return 0;
}

int main(){
    std::string input;
    Interpreter interpreter = Interpreter();

    while (std::getline(std::cin, input)){
        std::cout << interpreter.interpret(input);
    }

    return 0;
}