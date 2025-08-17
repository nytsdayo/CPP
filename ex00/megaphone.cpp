#include <iostream>
#include <string>
#include <cctype>      

int main(int argc, char* argv[]) {
    if (argc > 1) {
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t i = 0; i < str.length(); ++i) {
        		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    		}
	        std::cout << str;
		}
		std::cout << std::endl;
    }else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
    return 0;
}
