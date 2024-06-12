
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cmath>

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN
};

Type detectType(const std::string &literal) {
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
        return CHAR;
    }
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return FLOAT;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return DOUBLE;
    }
    
    std::istringstream iss(literal);
    int intValue;
    float floatValue;
    double doubleValue;

    // Check for INT
    if (iss >> intValue && iss.eof()) {
        return INT;
    }
    iss.clear();
    iss.str(literal);

    // Check for FLOAT
    if ((iss >> floatValue >> std::ws).eof()) {
        return FLOAT;
    }
    iss.clear();
    iss.str(literal);

    // Check for DOUBLE
    if (iss >> doubleValue && iss.eof()) {
        return DOUBLE;
    }

    return UNKNOWN;
}

void printChar(char c) {
    if (isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void printFloat(float f) {
    if (std::isnan(f)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(f)) {
        std::cout << "float: " << (f < 0 ? "-" : "+") << "inff" << std::endl;
    } else if (f - static_cast<int>(f) == 0) {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void printDouble(double d) {
    if (std::isnan(d)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << "double: " << (d < 0 ? "-" : "+") << "inf" << std::endl;
    } else if (d - static_cast<int>(d) == 0) {
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
}

void convert(const std::string &literal) {
    Type type = detectType(literal);
    std::cout << "Detected type: " << type << std::endl; // Debug message

    try {
        switch (type) {
            case CHAR: {
                char c = literal[0];
                printChar(c);
                printInt(static_cast<int>(c));
                printFloat(static_cast<float>(c));
                printDouble(static_cast<double>(c));
                break;
            }
            case INT: {
                int i = std::stoi(literal);
                if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
                    std::cout << "char: impossible" << std::endl;
                else
                    printChar(static_cast<char>(i));
                printInt(i);
                printFloat(static_cast<float>(i));
                printDouble(static_cast<double>(i));
                break;
            }
            case FLOAT: {
                if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
                    float f = std::stof(literal);
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    printFloat(f);
                    printDouble(static_cast<double>(f));
                } else {
                    float f = std::stof(literal);
                    if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
                        std::cout << "char: impossible" << std::endl;
                    else
                        printChar(static_cast<char>(f));
                    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
                        std::cout << "int: impossible" << std::endl;
                    else
                        printInt(static_cast<int>(f));
                    printFloat(f);
                    printDouble(static_cast<double>(f));
                }
                break;
            }
            case DOUBLE: {
                if (literal == "-inf" || literal == "+inf" || literal == "nan") {
                    double d = std::stod(literal);
                    std::cout << "char: impossible" << std::endl;
                    std::cout << "int: impossible" << std::endl;
                    printFloat(static_cast<float>(d));
                    printDouble(d);
                } else {
                    double d = std::stod(literal);
                    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
                        std::cout << "char: impossible" << std::endl;
                    else
                        printChar(static_cast<char>(d));
                    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
                        std::cout << "int: impossible" << std::endl;
                    else
                        printInt(static_cast<int>(d));
                    printFloat(static_cast<float>(d));
                    printDouble(d);
                }
                break;
            }
            default:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                break;
        }
    } catch (const std::exception &e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal(argv[1]);
    convert(literal);

    return 0;
}


