#include <pcg_random.hpp>

#include <iostream>
#include <fstream>
#include <format>

void generate_output_pcg32()
{
	int state = 123;
	int seq = 456;
	int numNumbers = 2048;

	pcg32 rng(state, seq);

	std::ofstream file(std::format("./pcg32_state{}_seq{}_first{}.csv", state, seq, numNumbers));
	for(int i = 0; i < numNumbers; ++i)
	{
		const auto randomNumber = rng();
		file << randomNumber;
		
		if(i < numNumbers - 1)
		{
			file << ',';
		}

		std::cout << randomNumber << '\n';
	}
}

void generate_output_cm_setseq_dxsm_128_64()
{
	int state = 123;
	int seq = 456;
	int numNumbers = 2048;

	pcg_engines::cm_setseq_dxsm_128_64 rng(state, seq);

	std::ofstream file(std::format("./cm_setseq_dxsm_128_64_state{}_seq{}_first{}.csv", state, seq, numNumbers));
	for(int i = 0; i < numNumbers; ++i)
	{
		const auto randomNumber = rng();
		file << randomNumber;
		
		if(i < numNumbers - 1)
		{
			file << ',';
		}

		std::cout << randomNumber << '\n';
	}
}

int main()
{
	generate_output_pcg32();
	generate_output_cm_setseq_dxsm_128_64();
}
