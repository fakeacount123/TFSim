#include "clock_.hpp"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

clock_::clock_(sc_module_name name, int dl, nana::label &clk):  sc_module(name), delay(dl), clock_count(clk)
{
    SC_THREAD(main);
}

int string_to_int(std::string clock_ns)
{
	int clock_int = std::stoi(clock_ns);
	return clock_int;
}

void clock_::main()
{
    while(true)
    {	
    	int clock_int, instructions_count, IPC;
        sc_pause();
        wait(SC_ZERO_TIME);
        out->write("");
        clock_count.caption(sc_time_stamp().to_string());
        std::cout << "### Clock atual		: " << sc_time_stamp().to_string() << ".\n";
        clock_int = string_to_int(sc_time_stamp().to_string());
        instructions_count = clock_int;
        std::cout << "### Instrucao atual	: " << instructions_count << ".\n";
        if(clock_int != 0){
        	IPC = instructions_count/clock_int;
        	std::cout << "### IPC atual		: " << IPC << " instrucoes por ciclo.\n";
        }
        wait(delay,SC_NS);
    }
}