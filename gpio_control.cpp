#include <iostream>
#include <fstream>
#include <string>

void export_pin(int pin_number) {
	std::ofstream export_file("/sys/class/gpio/export");
	if(!export_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	export_file << pin_number;
	export_file.close();
}

void get_direction(int pin_number) {
	std::string filename = "/sys/class/gpio/gpio" + std::to_string(pin_number) + "/direction";
	std::ifstream direction_file(filename.c_str());
	if(!direction_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	std::string direction; 
	std::getline(direction_file, direction);
	std::cout << direction;
	direction_file.close();
}

void set_direction(int pin_number, bool value) {
	std::string filename = "/sys/class/gpio/gpio" + std::to_string(pin_number) + "/direction";
	std::ofstream direction_file(filename.c_str());
	if(!direction_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	direction_file << ((value == true) ? "out" : "in");
	direction_file.close();

}

void read_pin(int pin_number) {
	std::string filename = "/sys/class/gpio/gpio" + std::to_string(pin_number) + "/value";
	std::ifstream value_file(filename.c_str());
	if(!value_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	std::string value; 
	std::getline(value_file, value);
	std::cout << value;
	value_file.close();
}

void write_pin(int pin_number, bool value) {
	std::string filename = "/sys/class/gpio/gpio" + std::to_string(pin_number) + "/value";
	std::ofstream value_file(filename.c_str());
	if(!value_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	value_file << ((value == true) ? 1 : 0);
	value_file.close();
}

void unexport_pin(int pin_number) {
	write_pin(pin_number, false);
	set_direction(pin_number, false);
	std::ofstream unexport_file("/sys/class/gpio/unexport");
	if(!unexport_file.is_open())
		throw std::logic_error("Failed to access GPIO directory");
	unexport_file << pin_number;
	unexport_file.close();
}

int main(int argc, char* argv[]) {

	//DIRECTION: (TRUE:OUT) (FALSE:IN)
	//VALUE: (TRUE:HIGH) (FALSE:LOW)
	
	if(argc < 3) {
	       	throw std::logic_error("Wrong user input");
	}
	
	std::string command;
	int pin_number;
	std::string option;
	
	try {
		command = std::string(argv[1]);
		pin_number = std::stoi(std::string(argv[2]));
		if (argc == 4)
			option = std::string(argv[3]);
	}
	catch (...) {
		throw std::logic_error("Wrong user input");
	}

	if (command == "export" && argc == 3)
		export_pin(pin_number);
	
	else if (command == "unexport" && argc == 3)
		unexport_pin(pin_number);
	
	else if (command == "getmode" && argc == 3)
		get_direction(pin_number);
	
	else if (command == "read" && argc == 3)
		read_pin(pin_number);
	
	else if (command == "write" && argc == 4) {
		if (option == "high")
			write_pin(pin_number, true);
		else if (option == "low")
			write_pin(pin_number, false);
		else
			throw std::logic_error("Wrong user input");
	}
	
	else if (command == "setmode" && argc == 4) {
		std::string option = std::string(argv[3]);
		if (option == "out")
			set_direction(pin_number, true);
		else if (option == "in")
			set_direction(pin_number, false);
		else
			throw std::logic_error("Wrong user input");
	}
	
	else
		throw std::logic_error("Wrong user input");

	return 0;

}
