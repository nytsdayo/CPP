#include <iostream>
#include <string>
#include <cctype>      

int main(int argc, char* argv[]) {
	std::string output_string;

    if (argc > 1) {
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); ++j) {
        		output_string += static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
    		}
		}
    }else{
		output_string = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << output_string << std::endl;
    return 0;
}
